/*
 * tx_eth_udp.c
 *
 * Purpose: Build and transmit a valid Ethernet -> IPv4 -> UDP frame
 * Platform: S32K344 + TJA1103 (RMII)
 * Author: Gettobyte
 * Date: 11-Oct-2025
 */

#include "Mcal.h"
#include "Clock_Ip.h"
#include "Siul2_Port_Ip_Cfg.h"
#include "Siul2_Port_Ip.h"
#include "Gmac_Ip.h"
#include "string.h"
#include "stdint.h"
#include "stdbool.h"

/* ===== app control ===== */
volatile int exit_code = 0;

/* ===== GMAC/PHY globals ===== */
#define INST_GMAC_0     (0U)
Gmac_Ip_StatusType Status = 0;

/* Replace with your actual MACs for both boards */
static uint8 MacAddr_Src[6U]  = { 0x10, 0x11, 0x22, 0x77, 0x77, 0x77 }; /* this board */
static uint8 MacAddr_Dest[6U] = { 0x10, 0x11, 0x22, 0x77, 0x77, 0x78 }; /* peer board */

/* ===== PHY discovery scratch ===== */
static uint16 phy_addr;             /* discovered PHY address (0..31) */
static uint16 register_value_0;
static uint16 register_value_1;

/* ===== Ethernet frame sizes ===== */
#define ETH_MIN_NO_FCS       (60U)
#define ETH_HDR_LEN          (14U)
#define ETHERTYPE_IPV4       (0x0800U)

/* ===== IPv4 / UDP sizes ===== */
#define IPV4_IHL_NOOPT       (5U)
#define IPV4_HDR_LEN         (IPV4_IHL_NOOPT * 4U)
#define UDP_HDR_LEN          (8U)

/* ===== TX structures ===== */
static Gmac_Ip_BufferType   TxBuffer = {0};
static Gmac_Ip_TxInfoType   TxInfo   = {0};
static Gmac_Ip_TxOptionsType TxOptions =
{
    TRUE,                         /* add CRC/FCS and pad in hardware */
    GMAC_CRC_AND_PAD_INSERTION,
    GMAC_CHECKSUM_INSERTION_DISABLE /* we compute checksums in software */
};

/* ====== Simple busy-wait delay (approx) ====== */
/* Adjust for your clock; this is just to pace packets for Wireshark */
static void delay_cycles(volatile uint32_t cycles)
{
    while (cycles--) { __asm("nop"); }
}

/* ====== Byte-order helpers ====== */
static inline uint16_t htons(uint16_t x)
{
    return (uint16_t)((x << 8) | (x >> 8));
}
static inline uint32_t htonl(uint32_t x)
{
    return ((x & 0x000000FFUL) << 24) |
           ((x & 0x0000FF00UL) <<  8) |
           ((x & 0x00FF0000UL) >>  8) |
           ((x & 0xFF000000UL) >> 24);
}

/* ====== RFC 1071 checksum over arbitrary buffer ====== */
static uint16_t rfc1071_checksum(const uint8_t *data, uint16_t len)
{
    uint32_t sum = 0U;
    for (uint16_t i = 0U; i + 1U < len; i += 2U) {
        uint16_t w = ((uint16_t)data[i] << 8) | data[i+1U];
        sum += w;
    }
    if (len & 1U) { sum += ((uint16_t)data[len-1U] << 8); }
    while (sum >> 16) { sum = (sum & 0xFFFFU) + (sum >> 16); }
    return (uint16_t)(~sum);
}

/* ====== UDP pseudo-header for checksum ====== */
typedef struct {
    uint8_t  src[4];
    uint8_t  dst[4];
    uint8_t  zero;
    uint8_t  proto;   /* 17 for UDP */
    uint16_t udp_len; /* network order */
} __attribute__((packed)) ipv4_pseudo_t;

static uint16_t udp_checksum_ipv4(const uint8_t srcIP[4], const uint8_t dstIP[4],
                                  const uint8_t *udp, uint16_t udpLen)
{
    ipv4_pseudo_t ph;
    memcpy(ph.src, srcIP, 4);
    memcpy(ph.dst, dstIP, 4);
    ph.zero  = 0;
    ph.proto = 17U; /* UDP */
    ph.udp_len = htons(udpLen);

    uint32_t sum = 0U;

    /* pseudo header */
    const uint8_t *p = (const uint8_t *)&ph;
    for (uint16_t i=0; i<sizeof(ph); i+=2) {
        uint16_t w = ((uint16_t)p[i] << 8) | p[i+1U];
        sum += w;
    }
    /* UDP header + payload */
    for (uint16_t i=0; i+1<udpLen; i+=2) {
        uint16_t w = ((uint16_t)udp[i] << 8) | udp[i+1U];
        sum += w;
    }
    if (udpLen & 1U) { sum += ((uint16_t)udp[udpLen-1U] << 8); }

    while (sum >> 16) { sum = (sum & 0xFFFFU) + (sum >> 16); }
    uint16_t res = (uint16_t)(~sum);
    if (res == 0x0000U) res = 0xFFFFU; /* UDP checksum cannot be 0 */
    return res;
}

/* ====== Ethernet -> IPv4 -> UDP builder ====== */
/* srcIP_host/dstIP_host are host-order (e.g. 0xC0A8010A for 192.168.1.10) */
static void BuildEthernetIPv4UDP(Gmac_Ip_BufferType *txBuf,
                                 const uint8_t srcMac[6], const uint8_t dstMac[6],
                                 uint32_t srcIP_host, uint32_t dstIP_host,
                                 uint16_t srcPort, uint16_t dstPort,
                                 const uint8_t *payload, uint16_t payloadLen)
{
    uint8_t *f = txBuf->Data;

    /* --- Ethernet header (14B) --- */
    memcpy(f + 0, dstMac, 6U);
    memcpy(f + 6, srcMac, 6U);
    f[12] = (uint8_t)((ETHERTYPE_IPV4 >> 8) & 0xFF);
    f[13] = (uint8_t)(ETHERTYPE_IPV4 & 0xFF);

    /* --- IPv4 header (no options) --- */
    uint8_t *ip = f + ETH_HDR_LEN;
    const uint8_t ver_ihl = (4U << 4) | IPV4_IHL_NOOPT;
    const uint16_t totalLen = (uint16_t)(IPV4_HDR_LEN + UDP_HDR_LEN + payloadLen);

    ip[0]  = ver_ihl;
    ip[1]  = 0x00;                          /* DSCP/ECN */
    ip[2]  = (uint8_t)((totalLen >> 8) & 0xFF);
    ip[3]  = (uint8_t)(totalLen & 0xFF);
    ip[4]  = 0x00; ip[5] = 0x01;            /* Identification */
    ip[6]  = 0x40; ip[7] = 0x00;            /* Flags/Fragment */
    ip[8]  = 64U;                           /* TTL */
    ip[9]  = 17U;                           /* UDP */
    ip[10] = 0; ip[11] = 0;                 /* checksum placeholder */

    const uint32_t srcIP = htonl(srcIP_host);
    const uint32_t dstIP = htonl(dstIP_host);

    ip[12] = (uint8_t)((srcIP >> 24) & 0xFF);
    ip[13] = (uint8_t)((srcIP >> 16) & 0xFF);
    ip[14] = (uint8_t)((srcIP >> 8)  & 0xFF);
    ip[15] = (uint8_t)(srcIP & 0xFF);

    ip[16] = (uint8_t)((dstIP >> 24) & 0xFF);
    ip[17] = (uint8_t)((dstIP >> 16) & 0xFF);
    ip[18] = (uint8_t)((dstIP >> 8)  & 0xFF);
    ip[19] = (uint8_t)(dstIP & 0xFF);

    /* IP header checksum */
    uint16_t ipChk = rfc1071_checksum(ip, IPV4_HDR_LEN);
    ip[10] = (uint8_t)((ipChk >> 8) & 0xFF);
    ip[11] = (uint8_t)(ipChk & 0xFF);

    /* --- UDP header + payload --- */
    uint8_t *udp = ip + IPV4_HDR_LEN;
    udp[0] = (uint8_t)((srcPort >> 8) & 0xFF);
    udp[1] = (uint8_t)(srcPort & 0xFF);
    udp[2] = (uint8_t)((dstPort >> 8) & 0xFF);
    udp[3] = (uint8_t)(dstPort & 0xFF);

    const uint16_t udpLen = (uint16_t)(UDP_HDR_LEN + payloadLen);
    udp[4] = (uint8_t)((udpLen >> 8) & 0xFF);
    udp[5] = (uint8_t)(udpLen & 0xFF);

    udp[6] = 0; udp[7] = 0;                 /* checksum placeholder */

    if (payloadLen && payload) {
        memcpy(udp + UDP_HDR_LEN, payload, payloadLen);
    }

    /* UDP checksum (pseudo-header) */
    uint8_t srcIpBytes[4] = { ip[12], ip[13], ip[14], ip[15] };
    uint8_t dstIpBytes[4] = { ip[16], ip[17], ip[18], ip[19] };
    uint16_t udpChk = udp_checksum_ipv4(srcIpBytes, dstIpBytes, udp, udpLen);
    udp[6] = (uint8_t)((udpChk >> 8) & 0xFF);
    udp[7] = (uint8_t)(udpChk & 0xFF);

    /* Frame length without FCS; pad to 60 so MAC will append FCS */
    uint32_t frameLen = ETH_HDR_LEN + totalLen;
    if (frameLen < ETH_MIN_NO_FCS) {
        memset(f + frameLen, 0x00, ETH_MIN_NO_FCS - frameLen);
        frameLen = ETH_MIN_NO_FCS;
    }

    txBuf->Length = frameLen;
}

/* ====== Simple app payload: magic + seq + text ====== */
typedef struct {
    uint32_t magic;    /* 'GTBY' = 0x47544259 */
    uint32_t seq;      /* host-order counter */
    uint8_t  text[32]; /* ASCII payload */
} __attribute__((packed)) app_msg_t;

static uint32_t g_seq = 1U;

/* ====== PHY init (TJA110x via MDIO) ====== */
static void Eth_Phy_Init(void)
{
    /* Enable MDIO (Management Data I/O) for PHY communication */
    Gmac_Ip_EnableMDIO(INST_GMAC_0, FALSE, 48000000U);

    /* --- Discover PHY address by reading PHY ID1/ID2 --- */
    for (phy_addr = 0U; phy_addr < 32U; ++phy_addr) {
        (void)Gmac_Ip_MDIORead(INST_GMAC_0, phy_addr, 2U, &register_value_0, 1U);
        (void)Gmac_Ip_MDIORead(INST_GMAC_0, phy_addr, 3U, &register_value_1, 1U);

        /* TJA110x ID: 0x001B / 0xB013 (adjust if your silicon differs) */
        if ((register_value_0 == 0x001B) && (register_value_1 == 0xB013)) {
            break;
        }
    }

    /* Reset PHY */
    (void)Gmac_Ip_MDIOWrite(INST_GMAC_0, phy_addr, 0U, 0x8000U, 1U);
    /* Wait for reset done (bit15 clears) */
    do {
        (void)Gmac_Ip_MDIORead(INST_GMAC_0, phy_addr, 0U, &register_value_0, 1U);
    } while (register_value_0 & 0x8000U);

    /* Basic sanity checks (optional but good while bringing up) */
    /* ePHY enable check */
    (void)Gmac_Ip_MDIOReadMMD(INST_GMAC_0, phy_addr, 1, 0x8048U, &register_value_0, 1U);
    /* master/slave */
    (void)Gmac_Ip_MDIOReadMMD(INST_GMAC_0, phy_addr, 1, 0x0834U, &register_value_0, 1U);
    /* xMII config (Rev-RMII) */
    (void)Gmac_Ip_MDIOReadMMD(INST_GMAC_0, phy_addr, 30, 0xAFC6U, &register_value_0, 1U);

    /* Link status poll (bit2 of 0x8102) */
    do {
        (void)Gmac_Ip_MDIOReadMMD(INST_GMAC_0, phy_addr, 30, 0x8102U, &register_value_0, 1U);
    } while (((register_value_0 & (1U << 2)) == 0U));
}

/* ====== Send one UDP test frame ====== */
static void Send_UDP_Test(uint32_t srcIP_host, uint32_t dstIP_host,
                          uint16_t srcPort, uint16_t dstPort,
                          const char *text)
{
    /* Grab a TX buffer from GMAC */
    Status = Gmac_Ip_GetTxBuff(INST_GMAC_0, 0U, &TxBuffer, NULL_PTR);
    DevAssert(Status == GMAC_STATUS_SUCCESS);

    /* Build app payload */
    app_msg_t msg;
    msg.magic = 0x47544259UL; /* 'GTBY' */
    msg.seq   = g_seq++;
    memset(msg.text, 0, sizeof(msg.text));
    if (text != NULL) {
        size_t n = strlen(text);
        if (n > sizeof(msg.text)) n = sizeof(msg.text);
        memcpy(msg.text, text, n);
    }

    /* Build the frame */
    BuildEthernetIPv4UDP(&TxBuffer,
                         MacAddr_Src,
                         MacAddr_Dest,
                         srcIP_host, dstIP_host,
                         srcPort, dstPort,
                         (const uint8_t *)&msg, (uint16_t)sizeof(msg));

    /* Transmit */
    Status = Gmac_Ip_SendFrame(INST_GMAC_0, 0U, &TxBuffer, &TxOptions);
    DevAssert(Status == GMAC_STATUS_SUCCESS);

    /* Wait for completion */
    do {
        Status = Gmac_Ip_GetTransmitStatus(INST_GMAC_0, 0U, &TxBuffer, &TxInfo);
    } while (Status == GMAC_STATUS_BUSY);

    DevAssert((GMAC_STATUS_SUCCESS == Status) || (0U != TxInfo.ErrMask));
}

/* ====== Main ====== */
int main(void)
{
    /* Put MAC into RMII mode through DCM (per your original code) */
    IP_DCM_GPR->DCMRWF1 =
        (IP_DCM_GPR->DCMRWF1 & ~DCM_GPR_DCMRWF1_MAC_CONF_SEL_MASK)
        | DCM_GPR_DCMRWF1_MAC_CONF_SEL(2U);

    /* Clocks / Pins / GMAC driver (generated by RTD config tool) */
    Clock_Ip_Init(&Clock_Ip_aClockConfig[0]);
    Siul2_Port_Ip_Init(
        NUM_OF_CONFIGURED_PINS_PortContainer_0_BOARD_InitPeripherals,
        g_pin_mux_InitConfigArr_PortContainer_0_BOARD_InitPeripherals);

    Status = Gmac_Ip_Init(INST_GMAC_0, &Gmac_0_ConfigPB);
    DevAssert(Status == GMAC_STATUS_SUCCESS);

    /* Bring up PHY and wait for link */
    Eth_Phy_Init();

    /* ==== Addressing for the two boards (adjust to your setup) ==== */
    /* Board A: 192.168.1.10:50000 -> Board B: 192.168.1.20:50001 */
    const uint32_t srcIP_host = 0xC0A8010AUL; /* 192.168.1.10 */
    const uint32_t dstIP_host = 0xC0A80114UL; /* 192.168.1.20 */
    const uint16_t srcPort    = 50000U;
    const uint16_t dstPort    = 50001U;

    /* ==== Send once per second so Wireshark is easy to read ==== */
    for (;;)
    {
        Send_UDP_Test(srcIP_host, dstIP_host, srcPort, dstPort,
                      "Hello from Gettobyte");

        /* ~1 second delay (tune for your clock: this is a rough software wait) */
        delay_cycles(10000000U);

        if (exit_code != 0) { break; }
    }

    return exit_code;
}
