/*
 * tx_eth_arp.c
 *
 * Purpose: Build and transmit Ethernet ARP frames
 * Author: RohanS002 Gettobyte
 * Date: 13-Oct-2025
 */

#include "Mcal.h"
#include "Clock_Ip.h"
#include "Siul2_Port_Ip_Cfg.h"
#include "Siul2_Port_Ip.h"
#include "Gmac_Ip.h"
#include "stdint.h"
#include "string.h"
#include "stdbool.h"

/* ===== app control ===== */
volatile int exit_code = 0;

/* ===== PHY discovery scratch ===== */
static uint16 phy_addr;             /* discovered PHY address (0..31) */
static uint16 register_value_0;
static uint16 register_value_1;

/* ===== GMAC/PHY ===== */
#define INST_GMAC_0      (0U)
static Gmac_Ip_StatusType Status = 0;

/* ===== ARP knobs you’ll likely tweak ===== */
typedef enum {
	ARP_REQUEST = 1, ARP_REPLY = 2
} arp_opcode_t;

/* MAC addresses */
static uint8_t MAC_SRC[6] = { 0x10, 0x11, 0x22, 0x77, 0x77, 0x77 }; /* our MAC */
static uint8_t MAC_PEER[6] = { 0x10, 0x11, 0x22, 0x77, 0x77, 0x78 }; /* peer MAC (for replies) */
static const uint8_t MAC_BCAST[6] = { 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF };

/* IPs (host-order for readability) */
#define IP4(a,b,c,d)  ( ((uint32_t)(d) << 24) | ((uint32_t)(c) << 16) | ((uint32_t)(b) << 8) | ((uint32_t)(a)) )
static uint32_t IP_SENDER_HOST = IP4(192, 168, 1, 10); /* who’s asking / who replies */
static uint32_t IP_TARGET_HOST = IP4(192, 168, 1, 10); /* who we want the MAC of (for request) */

/* ARP mode: request (broadcast) or reply (unicast to MAC_PEER) */
static arp_opcode_t g_arp_mode = ARP_REQUEST;

/* ===== Ethernet / ARP constants ===== */
#define ETH_HDR_LEN           (14U)
#define ETHERTYPE_ARP         (0x0806U)
#define ETH_MIN_NO_FCS        (60U)   /* MAC appends 4B FCS; we build to >= 60B without FCS */

#define ARP_HTYPE_ETH         (0x0001U)
#define ARP_PTYPE_IPV4        (0x0800U)
#define ARP_HLEN_ETH          (6U)
#define ARP_PLEN_IPV4         (4U)

/* ===== TX structures ===== */
static Gmac_Ip_BufferType TxBuffer = { 0 };
static Gmac_Ip_TxInfoType TxInfo = { 0 };
static Gmac_Ip_TxOptionsType TxOptions = {
TRUE, /* let MAC add CRC/FCS and pad */
GMAC_CRC_AND_PAD_INSERTION, GMAC_CHECKSUM_INSERTION_PROTO_PSEUDOH };

/* ===== tiny endian helpers ===== */
static inline uint16_t htons(uint16_t x) {
	return (uint16_t) ((x << 8) | (x >> 8));
}
static inline uint32_t htonl(uint32_t x) {
	return ((x & 0x000000FFUL) << 24) | ((x & 0x0000FF00UL) << 8)
			| ((x & 0x00FF0000UL) >> 8) | ((x & 0xFF000000UL) >> 24);
}

/* ====== Simple delay to pace packets ====== */
static void delay_cycles(volatile uint32_t cycles) {
	while (cycles--) {
		__asm("nop");
	}
}

/* ====== ARP header (Ethernet/IPv4) ======
 Wire format (28 bytes after Eth header):
 htype(2) ptype(2) hlen(1) plen(1) oper(2)
 sha(6) spa(4) tha(6) tpa(4)
 */
typedef struct __attribute__((packed)) {
	uint16_t htype;
	uint16_t ptype;
	uint8_t hlen;
	uint8_t plen;
	uint16_t oper;
	uint8_t sha[6];
	uint8_t spa[4];
	uint8_t tha[6];
	uint8_t tpa[4];
} arp_ipv4_t;

/* ===== Build a raw Ethernet+ARP frame in one go (no hidden helpers) ===== */
static void BuildEthernetARP(Gmac_Ip_BufferType *tx, const uint8_t mac_src[6],
		const uint8_t mac_dst[6], arp_ipv4_t *arp, /* filled below */
		uint32_t *out_len_no_fcs) {
	uint8_t *f = tx->Data;

	/* --- Ethernet header --- */
	memcpy(f + 0, mac_dst, 6);
	memcpy(f + 6, mac_src, 6);
	f[12] = (uint8_t) ((ETHERTYPE_ARP >> 8) & 0xFF);
	f[13] = (uint8_t) (ETHERTYPE_ARP & 0xFF);

	/* --- ARP payload (28B) --- */
	uint8_t *p = f + ETH_HDR_LEN;
	memcpy(p, arp, sizeof(*arp));

	/* --- pad to 60B so MAC can append FCS --- */
	uint32_t frameLen = ETH_HDR_LEN + sizeof(*arp);
	if (frameLen < ETH_MIN_NO_FCS) {
		memset(f + frameLen, 0x00, ETH_MIN_NO_FCS - frameLen);
		frameLen = ETH_MIN_NO_FCS;
	}

	tx->Length = frameLen;
	if (out_len_no_fcs)
		*out_len_no_fcs = frameLen;
}

/* ===== Compose the ARP payload for request or reply ===== */
static void MakeArpPayload(arp_ipv4_t *a, arp_opcode_t op, const uint8_t sha[6],
		uint32_t spa_host, const uint8_t tha[6], uint32_t tpa_host) {
	a->htype = htons(ARP_HTYPE_ETH);
	a->ptype = htons(ARP_PTYPE_IPV4);
	a->hlen = ARP_HLEN_ETH;
	a->plen = ARP_PLEN_IPV4;
	a->oper = htons((uint16_t) op);

	memcpy(a->sha, sha, 6);
	/* sender IP */
	uint32_t spa = htonl(spa_host);
	a->spa[0] = (uint8_t) ((spa >> 24) & 0xFF);
	a->spa[1] = (uint8_t) ((spa >> 16) & 0xFF);
	a->spa[2] = (uint8_t) ((spa >> 8) & 0xFF);
	a->spa[3] = (uint8_t) (spa & 0xFF);

	memcpy(a->tha, tha, 6);
	/* target IP */
	uint32_t tpa = htonl(tpa_host);
	a->tpa[0] = (uint8_t) ((tpa >> 24) & 0xFF);
	a->tpa[1] = (uint8_t) ((tpa >> 16) & 0xFF);
	a->tpa[2] = (uint8_t) ((tpa >> 8) & 0xFF);
	a->tpa[3] = (uint8_t) (tpa & 0xFF);
}

/* ====== PHY init (TJA110x via MDIO) ====== */
static void Eth_Phy_Init(void) {
	/* Enable MDIO (Management Data I/O) for PHY communication */
	Gmac_Ip_EnableMDIO(INST_GMAC_0, FALSE, 48000000U);

	/* --- Discover PHY address by reading PHY ID1/ID2 --- */
	for (phy_addr = 0U; phy_addr < 32U; ++phy_addr) {
		(void) Gmac_Ip_MDIORead(INST_GMAC_0, phy_addr, 2U, &register_value_0,
				1U);
		(void) Gmac_Ip_MDIORead(INST_GMAC_0, phy_addr, 3U, &register_value_1,
				1U);

		/* TJA110x ID: 0x001B / 0xB013 (adjust if your silicon differs) */
		if ((register_value_0 == 0x001B) && (register_value_1 == 0xB013)) {
			break;
		}
	}

	/* Reset PHY */
	(void) Gmac_Ip_MDIOWrite(INST_GMAC_0, phy_addr, 0U, 0x8000U, 1U);
	/* Wait for reset done (bit15 clears) */
	do {
		(void) Gmac_Ip_MDIORead(INST_GMAC_0, phy_addr, 0U, &register_value_0,
				1U);
	} while (register_value_0 & 0x8000U);

	/* Basic sanity checks (optional but good while bringing up) */
	/* ePHY enable check */
	(void) Gmac_Ip_MDIOReadMMD(INST_GMAC_0, phy_addr, 1, 0x8048U,
			&register_value_0, 1U);
	/* master/slave */
	(void) Gmac_Ip_MDIOReadMMD(INST_GMAC_0, phy_addr, 1, 0x0834U,
			&register_value_0, 1U);
	/* xMII config (Rev-RMII) */
	(void) Gmac_Ip_MDIOReadMMD(INST_GMAC_0, phy_addr, 30, 0xAFC6U,
			&register_value_0, 1U);

	/* Link status poll (bit2 of 0x8102) */
	do {
		(void) Gmac_Ip_MDIOReadMMD(INST_GMAC_0, phy_addr, 30, 0x8102U,
				&register_value_0, 1U);
	} while (((register_value_0 & (1U << 2)) == 0U));
}

/* ===== Send one ARP (request or reply) ===== */
static void Send_ARP(arp_opcode_t mode, const uint8_t mac_src[6],
		uint32_t ip_sender_host, const uint8_t mac_target_for_reply[6],
		uint32_t ip_target_host) {
	/* 1) get TX buffer */
	DevAssert(
			Gmac_Ip_GetTxBuff(INST_GMAC_0, 0U, &TxBuffer, NULL_PTR)
					== GMAC_STATUS_SUCCESS);

	/* 2) craft ARP payload */
	arp_ipv4_t arp = { 0 };
	if (mode == ARP_REQUEST) {
		/* request: who-has TPA? tell SPA; tha must be 00:00:00:00:00:00, eth DA=broadcast */
		static const uint8_t ZERO6[6] = { 0 };
		MakeArpPayload(&arp, ARP_REQUEST, mac_src, ip_sender_host, ZERO6,
				ip_target_host);
		BuildEthernetARP(&TxBuffer, mac_src, MAC_BCAST, &arp, NULL);
	} else {
		/* reply: TPA = the asker’s IP; tha = the asker’s MAC; eth DA = asker’s MAC */
		MakeArpPayload(&arp, ARP_REPLY, mac_src, ip_sender_host,
				mac_target_for_reply, ip_target_host);
		BuildEthernetARP(&TxBuffer, mac_src, mac_target_for_reply, &arp, NULL);
	}

	/* 3) send */
	DevAssert(
			Gmac_Ip_SendFrame(INST_GMAC_0, 0U, &TxBuffer, &TxOptions)
					== GMAC_STATUS_SUCCESS);

	/* 4) wait for TX done */
	while (Gmac_Ip_GetTransmitStatus(INST_GMAC_0, 0U, &TxBuffer, &TxInfo)
			== GMAC_STATUS_BUSY) {
	}
}

/* ===== Main ===== */
int main(void) {
	/* Put MAC into RMII mode using your existing DCM write (same as your UDP sample) */
	IP_DCM_GPR->DCMRWF1 = (IP_DCM_GPR->DCMRWF1
			& ~DCM_GPR_DCMRWF1_MAC_CONF_SEL_MASK)
			| DCM_GPR_DCMRWF1_MAC_CONF_SEL(2U);

	Siul2_Port_Ip_Init(
	NUM_OF_CONFIGURED_PINS_PortContainer_0_BOARD_InitPeripherals,
			g_pin_mux_InitConfigArr_PortContainer_0_BOARD_InitPeripherals);

	/* Clocks, Pins, GMAC init via RTD */
	Clock_Ip_Init(&Clock_Ip_aClockConfig[0]);

	DevAssert(
			Gmac_Ip_Init(INST_GMAC_0, &Gmac_0_ConfigPB) == GMAC_STATUS_SUCCESS);

	/* PHY up */
	Eth_Phy_Init();



	/* Loop: send an ARP every ~1s so Wireshark is clean */
	for (;;) {
		if (g_arp_mode == ARP_REQUEST) {
			/* who has IP_TARGET_HOST? tell IP_SENDER_HOST */
			Send_ARP(ARP_REQUEST, MAC_SRC, IP_SENDER_HOST, MAC_PEER,
					IP_TARGET_HOST);
		} else {
			/* reply to peer: “IP_SENDER_HOST is at MAC_SRC” (useful for quick testing) */
			Send_ARP(ARP_REPLY, MAC_SRC, IP_SENDER_HOST, MAC_PEER,
					IP_TARGET_HOST);
		}

		/* crude delay: tune for your core clock */
		delay_cycles(10000000U);

		if (exit_code)
			break;

	}

	return exit_code;
}
