/*
 * tx_icmp_echo.c
 *
 * Purpose : Build & transmit Ethernet -> IPv4 -> ICMP Echo Request (Ping)
 * Author  : RohanS002 Gettobyte
 * Date    : 13-Oct-2025
 */

#include "Mcal.h"
#include "Clock_Ip.h"
#include "Siul2_Port_Ip_Cfg.h"
#include "Siul2_Port_Ip.h"
#include "Gmac_Ip.h"
#include "stdint.h"
#include "string.h"
#include "stdbool.h"

/* ===================== user knobs ===================== */

/* MAC addresses */
static uint8_t MAC_SRC[6] = {0x10,0x11,0x22,0x77,0x77,0x77};
static uint8_t MAC_DST[6] = {0x10,0x11,0x22,0x77,0x77,0x78}; /* set peer/gateway MAC (or ARP-resolve first) */

/* IPs (host-order, use your corrected macro order) */
#define IP4(a,b,c,d) ( ((uint32_t)(d)<<24) | ((uint32_t)(c)<<16) | ((uint32_t)(b)<<8) | ((uint32_t)(a)) )
static uint32_t IP_SRC_HOST = IP4(192,168,1,10);
static uint32_t IP_DST_HOST = IP4(192,168,1,10);

/* ICMP identifiers */
static uint16_t ICMP_IDENT = 0x1234;
static uint16_t ICMP_SEQ   = 1;

/* Payload */
static const uint8_t ICMP_PAYLOAD[] = "Gettobyte ICMP ping";
#define ICMP_PAYLOAD_LEN ((uint16_t)sizeof(ICMP_PAYLOAD)-1U)

/* Pace for Wireshark readability (tune for your clock) */
static inline void delay_cycles(volatile uint32_t n){ while(n--){ __asm("nop"); } }

/* If your TX buffers are cacheable, implement this to clean D-cache before DMA reads. */
static inline void tx_cache_clean(void *addr, uint32_t len)
{
    (void)addr; (void)len;
    /* Examples (pick your platform API if needed):
       - Cache_Ip_CleanByAddr((uint32)addr, (int32)len);
       - DCACHE_CleanByAddr((uint32_t)addr, (int32_t)len);
    */
}

/* ===================== constants ===================== */

#define INST_GMAC_0           (0U)
#define ETH_HDR_LEN           (14U)
#define ETHERTYPE_IPV4        (0x0800U)
#define ETH_MIN_NO_FCS        (60U)

#define IPV4_VERSION          (4U)
#define IPV4_IHL_NOOPT        (5U)
#define IPV4_HDR_LEN          (IPV4_IHL_NOOPT * 4U)
#define IPV4_TOS              (0x00U)
#define IPV4_TTL              (64U)
#define IPV4_PROTO_ICMP       (1U)

#define ICMP_TYPE_ECHO_REQ    (8U)
#define ICMP_TYPE_ECHO_REPLY  (0U)

/* ===================== tiny helpers ===================== */

static inline uint16_t htons(uint16_t x){ return (uint16_t)((x<<8)|(x>>8)); }
static inline uint32_t htonl(uint32_t x){
    return ((x & 0x000000FFUL) << 24) |
           ((x & 0x0000FF00UL) <<  8) |
           ((x & 0x00FF0000UL) >>  8) |
           ((x & 0xFF000000UL) >> 24);
}

/* RFC1071 checksum (used for ICMP and SW IP header if needed) */
static uint16_t rfc1071(const uint8_t *p, uint16_t n)
{
    uint32_t s = 0U;
    for (uint16_t i=0; i+1<n; i+=2) { s += (uint16_t)((p[i]<<8) | p[i+1]); }
    if (n & 1U) { s += (uint16_t)(p[n-1] << 8); }
    while (s >> 16) { s = (s & 0xFFFFU) + (s >> 16); }
    return (uint16_t)(~s);
}

/* ===================== PHY init (your version) ===================== */

static uint16_t phy_addr;
static uint16_t register_value_0, register_value_1;

static void Eth_Phy_Init(void) {
    /* Enable MDIO */
    Gmac_Ip_EnableMDIO(INST_GMAC_0, FALSE, 48000000U);

    /* Probe PHY ID */
    for (phy_addr = 0U; phy_addr < 32U; ++phy_addr) {
        (void)Gmac_Ip_MDIORead(INST_GMAC_0, phy_addr, 2U, &register_value_0, 1U);
        (void)Gmac_Ip_MDIORead(INST_GMAC_0, phy_addr, 3U, &register_value_1, 1U);
        /* TJA110x example ID: 0x001B/0xB013 — adjust if needed */
        if ((register_value_0 == 0x001B) && (register_value_1 == 0xB013)) { break; }
    }

    /* Reset */
    (void)Gmac_Ip_MDIOWrite(INST_GMAC_0, phy_addr, 0U, 0x8000U, 1U);
    do { (void)Gmac_Ip_MDIORead(INST_GMAC_0, phy_addr, 0U, &register_value_0, 1U); }
    while (register_value_0 & 0x8000U);

    /* Optional sanity reads */
    (void)Gmac_Ip_MDIOReadMMD(INST_GMAC_0, phy_addr, 1,  0x8048U, &register_value_0, 1U); /* ePHY enable */
    (void)Gmac_Ip_MDIOReadMMD(INST_GMAC_0, phy_addr, 1,  0x0834U, &register_value_0, 1U); /* master/slave */
    (void)Gmac_Ip_MDIOReadMMD(INST_GMAC_0, phy_addr, 30, 0xAFC6U, &register_value_0, 1U); /* Rev-RMII */

    /* Wait link-up (bit2 of 0x8102) */
    do { (void)Gmac_Ip_MDIOReadMMD(INST_GMAC_0, phy_addr, 30, 0x8102U, &register_value_0, 1U); }
    while (((register_value_0 & (1U<<2)) == 0U));
}

/* ===================== ICMP structs ===================== */

typedef struct __attribute__((packed)){
    uint8_t  type;   /* 8=request, 0=reply */
    uint8_t  code;   /* 0 */
    uint16_t csum;   /* header+payload */
    uint16_t ident;
    uint16_t seq;
    /* payload follows */
} icmp_echo_t;

/* ===================== GMAC globals & options ===================== */

static Gmac_Ip_StatusType Status;
static Gmac_Ip_BufferType TxBuffer;
static Gmac_Ip_TxInfoType TxInfo;

/* Prefer HW IPv4 header checksum; fallback to SW if enum not defined */
#if defined(GMAC_CHECKSUM_INSERTION_IPHDR)
  #define USE_HW_IPHDR_CSUM   (1)
  static Gmac_Ip_TxOptionsType TxOptions = {
      TRUE, /* CRC/FCS + pad */
      GMAC_CRC_AND_PAD_INSERTION,
      GMAC_CHECKSUM_INSERTION_IPHDR
  };
#else
  #define USE_HW_IPHDR_CSUM   (0)
  static Gmac_Ip_TxOptionsType TxOptions = {
      TRUE,
      GMAC_CRC_AND_PAD_INSERTION,
      GMAC_CHECKSUM_INSERTION_DISABLE
  };
#endif

/* ===================== Frame builder ===================== */

static void Build_Eth_IPv4_ICMP_Echo(Gmac_Ip_BufferType *tx,
                                     const uint8_t mac_src[6], const uint8_t mac_dst[6],
                                     uint32_t ip_src_host, uint32_t ip_dst_host,
                                     uint16_t ident, uint16_t seq,
                                     const uint8_t *payload, uint16_t payloadLen)
{
    uint8_t *f = tx->Data;

    /* ---- Ethernet ---- */
    memcpy(f+0, mac_dst, 6);
    memcpy(f+6, mac_src, 6);
    f[12] = (uint8_t)((ETHERTYPE_IPV4 >> 8) & 0xFF);
    f[13] = (uint8_t)( ETHERTYPE_IPV4       & 0xFF);

    /* ---- IPv4 ---- */
    uint8_t *ip = f + ETH_HDR_LEN;
    const uint16_t icmpLen  = (uint16_t)(sizeof(icmp_echo_t) + payloadLen);
    const uint16_t totalLen = (uint16_t)(IPV4_HDR_LEN + icmpLen);

    ip[0]  = (uint8_t)((IPV4_VERSION<<4) | IPV4_IHL_NOOPT);
    ip[1]  = IPV4_TOS;
    ip[2]  = (uint8_t)((totalLen >> 8) & 0xFF);
    ip[3]  = (uint8_t)( totalLen       & 0xFF);
    ip[4]  = 0x00; ip[5] = 0x01;                 /* Identification (arbitrary) */
    ip[6]  = 0x40; ip[7] = 0x00;                 /* DF=1 (0x4000) */
    ip[8]  = IPV4_TTL;
    ip[9]  = IPV4_PROTO_ICMP;
    ip[10] = 0x00; ip[11] = 0x00;                /* IP hdr checksum: 0 for HW; SW will fill below if needed */

    const uint32_t s = htonl(ip_src_host);
    const uint32_t d = htonl(ip_dst_host);
    ip[12] = (uint8_t)((s >> 24) & 0xFF);
    ip[13] = (uint8_t)((s >> 16) & 0xFF);
    ip[14] = (uint8_t)((s >>  8) & 0xFF);
    ip[15] = (uint8_t)( s        & 0xFF);
    ip[16] = (uint8_t)((d >> 24) & 0xFF);
    ip[17] = (uint8_t)((d >> 16) & 0xFF);
    ip[18] = (uint8_t)((d >>  8) & 0xFF);
    ip[19] = (uint8_t)( d        & 0xFF);

#if (USE_HW_IPHDR_CSUM == 0)
    /* Fallback: compute IPv4 header checksum in software */
    const uint16_t ipcs = rfc1071(ip, IPV4_HDR_LEN);
    ip[10] = (uint8_t)((ipcs >> 8) & 0xFF);
    ip[11] = (uint8_t)( ipcs       & 0xFF);
#endif

    /* ---- ICMP Echo ---- */
    uint8_t *icmp = ip + IPV4_HDR_LEN;
    icmp_echo_t *hdr = (icmp_echo_t*)icmp;
    hdr->type  = ICMP_TYPE_ECHO_REQ;
    hdr->code  = 0;
    hdr->csum  = 0;
    hdr->ident = htons(ident);
    hdr->seq   = htons(seq);

    if (payloadLen && payload) {
        memcpy(icmp + sizeof(icmp_echo_t), payload, payloadLen);
    }

    /* ICMP checksum (always SW; NICs typically don’t offload ICMP csum) */
    uint16_t ic = rfc1071(icmp, icmpLen);
    if (ic == 0U) { ic = 0xFFFFU; } /* avoid 0 */
    hdr->csum = ic;

    /* ---- pad to 60B (no FCS) ---- */
    uint32_t frameLen = ETH_HDR_LEN + totalLen;
    if (frameLen < ETH_MIN_NO_FCS) {
        memset(f + frameLen, 0x00, ETH_MIN_NO_FCS - frameLen);
        frameLen = ETH_MIN_NO_FCS;
    }
    tx->Length = frameLen;
}

/* ===================== Send one ping ===================== */

static void Send_ICMP_Echo_Once(void)
{
    /* 1) grab TX buffer */
    DevAssert(Gmac_Ip_GetTxBuff(INST_GMAC_0, 0U, &TxBuffer, NULL_PTR) == GMAC_STATUS_SUCCESS);

    /* 2) build frame */
    Build_Eth_IPv4_ICMP_Echo(&TxBuffer,
                             MAC_SRC, MAC_DST,
                             IP_SRC_HOST, IP_DST_HOST,
                             ICMP_IDENT, ICMP_SEQ++,
                             ICMP_PAYLOAD, ICMP_PAYLOAD_LEN);

    /* 3) cache clean (if needed) */
    tx_cache_clean(TxBuffer.Data, TxBuffer.Length);

    /* 4) send */
    DevAssert(Gmac_Ip_SendFrame(INST_GMAC_0, 0U, &TxBuffer, &TxOptions) == GMAC_STATUS_SUCCESS);

    /* 5) wait for completion */
    while (Gmac_Ip_GetTransmitStatus(INST_GMAC_0, 0U, &TxBuffer, &TxInfo) == GMAC_STATUS_BUSY) { }
}

/* ===================== Main ===================== */

int main(void)
{
    /* Put MAC into RMII mode via DCM (same as your other apps) */
    IP_DCM_GPR->DCMRWF1 =
        (IP_DCM_GPR->DCMRWF1 & ~DCM_GPR_DCMRWF1_MAC_CONF_SEL_MASK)
        |  DCM_GPR_DCMRWF1_MAC_CONF_SEL(2U);

    /* Clocks / Pins / GMAC (from RTD) */
    Clock_Ip_Init(&Clock_Ip_aClockConfig[0]);
    Siul2_Port_Ip_Init(NUM_OF_CONFIGURED_PINS_PortContainer_0_BOARD_InitPeripherals,
                       g_pin_mux_InitConfigArr_PortContainer_0_BOARD_InitPeripherals);
    DevAssert(Gmac_Ip_Init(INST_GMAC_0, &Gmac_0_ConfigPB) == GMAC_STATUS_SUCCESS);

    /* PHY link-up */
    Eth_Phy_Init();

    /* NOTE: Ensure MAC_DST is correct (same-subnet peer or gateway).
             If not known, ARP-resolve first (your ARP app). */

    for (;;)
    {
        Send_ICMP_Echo_Once();        /* TX one echo request */
        delay_cycles(10000000U);      /* ~1s */
    }
}
