/*
 * tx_eth.c
 *
 * Created on: 24-Sep-2025
 * Author: RohanS002 Gettbyte
 */

/* Including necessary configuration files for the microcontroller and peripherals. */
#include "Mcal.h"           // Microcontroller Abstraction Layer definitions.
#include "Clock_Ip.h"       // Clock initialization and configuration driver.
#include "Siul2_Port_Ip_Cfg.h" // SIUL2 (System Integration Unit Lite 2) Port configuration.
#include "Siul2_Port_Ip.h"  // SIUL2 Port driver for pin muxing.
#include "Gmac_Ip.h"        // Gigabit MAC (Ethernet Controller) driver.
#include "string.h"         // Standard C library for memory operations.

/* A volatile integer used for gracefully exiting the main loop, typically changed by a debugger. */
volatile int exit_code = 0;

uint16_t phy_addr;             // Discovered PHY address
uint16_t register_value_0;     // Temporary register value storage
uint16_t register_value_1;

/* Defines the instance number for the GMAC peripheral to be used. Here, it's GMAC instance 0. */
#define INST_GMAC_0     (0U)

/* A global variable to hold the status returned by GMAC driver functions. */
Gmac_Ip_StatusType Status = 0;

/* A 6-byte array to store the source MAC address, which will be retrieved from the hardware. */
uint8 MacAddr_Src[6U] = { 66, 55, 44, 33, 22, 11 };

/* A 6-byte array defining the destination MAC address for the Ethernet frame. */
uint8 MacAddr_Dest[6U] = { 66, 55, 44, 33, 22, 12 };

/* Configuration options for the transmission, enabling automatic CRC and padding insertion. */
Gmac_Ip_TxOptionsType TxOptions = { TRUE, GMAC_CRC_AND_PAD_INSERTION,
		GMAC_CHECKSUM_INSERTION_DISABLE };

/* A buffer structure provided by the GMAC driver to hold the data to be transmitted. */
Gmac_Ip_BufferType TxBuffer = { 0 };

/* Structures to hold metadata about the transmission. */
Gmac_Ip_TxInfoType TxInfo = { 0 };

static void Eth_Phy_Init(void) {

	/* Enable MDIO (Management Data I/O) for PHY communication */
	Gmac_Ip_EnableMDIO(INST_GMAC_0, FALSE, 48000000U);

	/* ======================== PHY Discovery ========================== */
	for (phy_addr = 0U; phy_addr < 32U; ++phy_addr) {
		/* Read PHY ID registers 2 and 3 */
		Status = Gmac_Ip_MDIORead(INST_GMAC_0, phy_addr, 2U, &register_value_0,
				1U);
		Status = Gmac_Ip_MDIORead(INST_GMAC_0, phy_addr, 3U, &register_value_1,
				1U);

		/* Check for TJA110X PHY ID */
		if ((register_value_0 == 0x001B) && (register_value_1 == 0xB013)) {
			break;  // Found TJA110X PHY
		}
	}

	/* ======================== PHY Reset ============================== */
	Status = Gmac_Ip_MDIOWrite(INST_GMAC_0, phy_addr, 0U, 0x8000U, 1U); // Reset PHY

	/* Wait until reset completes (bit 15 clears) */
	do {
		Status = Gmac_Ip_MDIORead(INST_GMAC_0, phy_addr, 0U, &register_value_0,
				1U);
	} while (register_value_0 & 0x8000U);

	/* ======================== PHY Configuration ====================== */

	/* ePHY Enable Check (bit 2 should be 1) */
	Status = Gmac_Ip_MDIOReadMMD(INST_GMAC_0, phy_addr, 1, 0x8048U,
			&register_value_0, 1U);
	if (((register_value_0 >> 2) & 0x1U) != 1U) {
		while (1)
			; /* Halt if ePHY not enabled */
	}

	/* Unlock Config access if not already enabled */
	Status = Gmac_Ip_MDIOReadMMD(INST_GMAC_0, phy_addr, 30, 0x8100U,
			&register_value_0, 1U);
	if ((register_value_0 & 0x4000U) == 0U) {

		Status = Gmac_Ip_MDIOWriteMMD(INST_GMAC_0, phy_addr, 30, 0x8100U,
				0x4000U, 1U);

		/* Verify Config-Enable flag */
		Status = Gmac_Ip_MDIOReadMMD(INST_GMAC_0, phy_addr, 30, 0x8100U,
				&register_value_0, 1U);

		if ((register_value_0 & 0x4000U) == 0U) {
			while (1)
				; /* Halt if Config not enabled */
		}
	}

	/* Master/Slave mode check (Reg 0x834, Device 1)
	 * - 32768 = Slave mode
	 * - 49152 = Master mode
	 */
	Status = Gmac_Ip_MDIOReadMMD(INST_GMAC_0, phy_addr, 1, 0x0834U,
			&register_value_0, 1U);
	if ((register_value_0 != 32768U) && (register_value_0 != 49152U)) {
		while (1)
			; /* Halt if not valid Master/Slave mode */
	}

	/* xMII Basic Config (0xAFC6 should return 21 -> Rev-RMII) */
	Status = Gmac_Ip_MDIOReadMMD(INST_GMAC_0, phy_addr, 30, 0xAFC6U,
			&register_value_0, 1U);
	if (register_value_0 != 21U) {
		while (1)
			; /* Halt if not Rev-RMII */
	}

	/* Auto-polarity correction:
	 * - Bit0 = auto (should be set by default)
	 * - Bit1 = test mode (should be 0)
	 * - Bit2 = polarity_correct_disable (should be 0 in slave, ignored in master)
	 */
	Status = Gmac_Ip_MDIOReadMMD(INST_GMAC_0, phy_addr, 30, 0x8108U,
			&register_value_0, 1U);
	if (((register_value_0 & 0x1U) == 0U) || /* Bit0 must be 1 */
	((register_value_0 & 0x2U) != 0U)) { /* Bit1 must be 0 */
		while (1)
			; /* Halt if auto-polarity config invalid */
	}

	/* Force polarity correction config (set bit0 only) */
	Status = Gmac_Ip_MDIOWriteMMD(INST_GMAC_0, phy_addr, 30, 0x8108U, 0x0001U,
			1U);

	/* Verify polarity correction settings */
	Status = Gmac_Ip_MDIOReadMMD(INST_GMAC_0, phy_addr, 30, 0x8108U,
			&register_value_0, 1U);
	if (register_value_0 != 0x0001U) {
		while (1)
			; /* Halt if polarity correction not set */
	}

	/* ======================== PHY Status ============================= */

	/* Start operation check (Reg 0x40) -> if bit0=1, PHY is busy */
	Status = Gmac_Ip_MDIOReadMMD(INST_GMAC_0, phy_addr, 30, 0x0040U,
			&register_value_0, 1U);
	if ((register_value_0 & 0x1U) != 0U) {
		while (1)
			; /* Halt if PHY still busy */
	}

	/* Basic State Check (Reg 0x810C) -> Bits[3:0] should be 1101b */
	Status = Gmac_Ip_MDIOReadMMD(INST_GMAC_0, phy_addr, 30, 0x810CU,
			&register_value_0, 1U);
	if ((register_value_0 & 0xFU) != 0xDU) {
		while (1)
			; /* Halt if state mismatch */
	}

	/* Link Status (Reg 0x8102)
	 * - Bit2 = link established
	 * - Bit7 = polarity detection (if set, physical connections need inversion)
	 */
	Status = Gmac_Ip_MDIOReadMMD(INST_GMAC_0, phy_addr, 30, 0x8102U,
			&register_value_0, 1U);
	if (((register_value_0 & (1U << 2)) == 0U) /* Bit2 must be 1 */) {
		while (1)
			; /* Halt if link not OK */
	}
}

/* ============================================================
 * New Frame Builder: Ethernet + IPv4 + ICMP (Custom Payload)
 * ============================================================ */

static uint16 CalcChecksum(const uint8 *data, uint16 len)
{
    uint32 sum = 0;
    for (uint16 i = 0; i < len - 1; i += 2) {
        uint16 word = ((uint16)data[i] << 8) | data[i + 1];
        sum += word;
    }
    if (len & 1) { // odd length
        sum += ((uint16)data[len - 1] << 8);
    }
    while (sum >> 16)
        sum = (sum & 0xFFFFU) + (sum >> 16);
    return (uint16)(~sum);
}

static void BuildEthernetIPv4ICMPFrame(Gmac_Ip_BufferType *txBuf,
                                       const uint8 srcMac[6],
                                       const uint8 dstMac[6],
                                       uint32 srcIP,
                                       uint32 dstIP,
                                       const uint8 *icmpPayload,
                                       uint16 payloadLen)
{
    uint8 *ptr = txBuf->Data;

    /* ========== Ethernet Header ========== */
    memcpy(ptr, dstMac, 6U);
    ptr += 6U;
    memcpy(ptr, srcMac, 6U);
    ptr += 6U;
    *ptr++ = 0x08U; // EtherType = IPv4 (0x0800)
    *ptr++ = 0x00U;

    /* ========== IPv4 Header ========== */
    uint8 *ipHeader = ptr;
    uint16 ipHeaderLen = 20U;
    uint16 totalLen = ipHeaderLen + 8U + payloadLen; // IP + ICMP

    ipHeader[0] = 0x45;          // Version 4, IHL = 5
    ipHeader[1] = 0x00;          // DSCP/ECN
    ipHeader[2] = (totalLen >> 8) & 0xFF;
    ipHeader[3] = totalLen & 0xFF;
    ipHeader[4] = 0x00; ipHeader[5] = 0x01; // ID
    ipHeader[6] = 0x40; ipHeader[7] = 0x00; // Flags/Offset
    ipHeader[8] = 64;              // TTL
    ipHeader[9] = 1;               // Protocol = ICMP
    ipHeader[10] = 0; ipHeader[11] = 0; // Checksum placeholder
    ipHeader[12] = (srcIP >> 24) & 0xFF;
    ipHeader[13] = (srcIP >> 16) & 0xFF;
    ipHeader[14] = (srcIP >> 8) & 0xFF;
    ipHeader[15] = srcIP & 0xFF;
    ipHeader[16] = (dstIP >> 24) & 0xFF;
    ipHeader[17] = (dstIP >> 16) & 0xFF;
    ipHeader[18] = (dstIP >> 8) & 0xFF;
    ipHeader[19] = dstIP & 0xFF;

    uint16 ipChecksum = CalcChecksum(ipHeader, ipHeaderLen);
    ipHeader[10] = (ipChecksum >> 8) & 0xFF;
    ipHeader[11] = ipChecksum & 0xFF;
    ptr += ipHeaderLen;

    /* ========== ICMP Header + Payload ========== */
    uint8 *icmp = ptr;
    icmp[0] = 8;   // Type = Echo Request
    icmp[1] = 0;   // Code = 0
    icmp[2] = 0; icmp[3] = 0; // Checksum placeholder
    icmp[4] = 0x12; icmp[5] = 0x34; // Identifier
    icmp[6] = 0x00; icmp[7] = 0x01; // Sequence

    memcpy(&icmp[8], icmpPayload, payloadLen);

    uint16 icmpLen = 8U + payloadLen;
    uint16 icmpChecksum = CalcChecksum(icmp, icmpLen);
    icmp[2] = (icmpChecksum >> 8) & 0xFF;
    icmp[3] = icmpChecksum & 0xFF;
    ptr += icmpLen;

    /* ========== Finalize ========== */
    txBuf->Length = (uint32)(ptr - txBuf->Data);
}

/* ============================================================
 * Main Function
 * ============================================================ */

int main(void) {

	/* Configure RMII mode for Ethernet MAC in DCM module */
	IP_DCM_GPR->DCMRWF1 = (IP_DCM_GPR->DCMRWF1
			& ~DCM_GPR_DCMRWF1_MAC_CONF_SEL_MASK)
			| DCM_GPR_DCMRWF1_MAC_CONF_SEL(2U);

	/* Initialize the microcontroller's clock system based on the provided configuration. */
	Clock_Ip_Init(&Clock_Ip_aClockConfig[0]);

	/* Initialize and configure the MCU's pins for peripherals (like Ethernet). */
	Siul2_Port_Ip_Init(
	NUM_OF_CONFIGURED_PINS_PortContainer_0_BOARD_InitPeripherals,
			g_pin_mux_InitConfigArr_PortContainer_0_BOARD_InitPeripherals);

	/* Initialize the GMAC (Ethernet) peripheral with its configuration. */
	Status = Gmac_Ip_Init(INST_GMAC_0, &Gmac_0_ConfigPB);
	DevAssert(Status == GMAC_STATUS_SUCCESS);

	Eth_Phy_Init();

	/* ========== Create Custom ICMP Frame ========== */
	uint8 icmpMsg[] = "Welcome to Gettobyte";

	Status = Gmac_Ip_GetTxBuff(INST_GMAC_0, 0U, &TxBuffer, NULL_PTR);
	DevAssert(Status == GMAC_STATUS_SUCCESS);

	/* Example IPs: 192.168.1.10 -> 192.168.1.20 */
	BuildEthernetIPv4ICMPFrame(&TxBuffer,
							   MacAddr_Src,
							   MacAddr_Dest,
							   0xC0A8010A, // 192.168.1.10
							   0xC0A80114, // 192.168.1.20
							   icmpMsg,
							   sizeof(icmpMsg) - 1);

	/* ========== Send Loop ========== */
	for (;;) {

		Status = Gmac_Ip_SendFrame(INST_GMAC_0, 0U, &TxBuffer, &TxOptions);
		DevAssert(Status == GMAC_STATUS_SUCCESS);

		do {
			Status = Gmac_Ip_GetTransmitStatus(INST_GMAC_0, 0U, &TxBuffer,
					&TxInfo);
		} while (Status == GMAC_STATUS_BUSY);

		DevAssert((GMAC_STATUS_SUCCESS == Status) || (0U != TxInfo.ErrMask));

		if (exit_code != 0) {
			break;
		}
	}
	return exit_code;
}
