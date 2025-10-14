/*
 * rx_eth.c
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
#include "IntCtrl_Ip.h"
#include "Gmac_Ip_Irq.h"

/* A volatile integer used for gracefully exiting the main loop, typically changed by a debugger. */
volatile int exit_code = 0;

uint16_t phy_addr;             // Discovered PHY address
uint16_t register_value_0;     // Temporary register value storage
uint16_t register_value_1;

boolean correct_frame = false;

/* Defines the instance number for the GMAC peripheral to be used. Here, it's GMAC instance 0. */
#define INST_GMAC_0     (0U)

/* A global variable to hold the status returned by GMAC driver functions. */
Gmac_Ip_StatusType Status = 0;

/* A buffer structure for receiving data. */
Gmac_Ip_BufferType RxBuffer = { 0 };

/* Structures to hold metadata about the reception. */
Gmac_Ip_RxInfoType RxInfo = { 0 };

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

	Status = Gmac_Ip_MDIOWriteMMD(INST_GMAC_0, phy_addr, 30, 0x8108U, 0x1, 1U);
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

/* A structure to represent an Ethernet frame in a user-friendly way. */
typedef struct {
	uint8 dstMac[6];
	uint8 srcMac[6];
	uint16 etherType;
	uint8 payload[64]; /* A buffer for the payload data. */
	uint16 payloadLen; /* The actual length of the payload. */
} EthFrame_t;

EthFrame_t rxFrame;

void Rx_Callback(void) {
	/* Wait for the frame to be received */
	do {
		Status = Gmac_Ip_ReadFrame(INST_GMAC_0, 0U, &RxBuffer, &RxInfo);
	} while (Status == GMAC_STATUS_RX_QUEUE_EMPTY);

	if (Status == GMAC_STATUS_SUCCESS && RxInfo.ErrMask == 0U) {

		uint8 *ptr = RxBuffer.Data;

		/* Extract directly into rxFrame structure */
		memcpy(rxFrame.dstMac, ptr, 6U);
		ptr += 6U;

		memcpy(rxFrame.srcMac, ptr, 6U);
		ptr += 6U;

		rxFrame.etherType = (uint16) ((ptr[0] << 8) | ptr[1]);
		ptr += 2U;

		rxFrame.payloadLen = (uint16) (RxBuffer.Length - 14U);

		memcpy(rxFrame.payload, ptr, rxFrame.payloadLen);

		/* Simple check */
		if (rxFrame.etherType == 0xBB80U) {
			correct_frame = true;
		}

		Gmac_Ip_ProvideRxBuff(INST_GMAC_0, 0U, &RxBuffer);

	}
}

/*
 * Ethernet Frame Format (IEEE 802.3 / Ethernet II)
 *
 * +------------+------------+-----------+------------------+-----------+
 * | Destination|   Source   | EtherType |      Payload     |    FCS    |
 * |   MAC (6B) |   MAC (6B) |   (2B)    |    (46�1500 B)   |   (4B)    |
 * +------------+------------+-----------+------------------+-----------+
 *
 * Field Details:
 * - Destination MAC (6 bytes): Who the frame is sent to
 * - Source MAC      (6 bytes): Who is sending the frame
 * - EtherType/Length(2 bytes): Protocol indicator
 * e.g. 0x0800 = IPv4, 0x0806 = ARP, custom = 0x88B5 etc.
 * - Payload         (46�1500 bytes): Actual data being sent
 * - FCS             (4 bytes): CRC checksum (auto-inserted by GMAC HW)
 *
 * In our code:
 * [0..5]   -> txFrame.dstMac
 * [6..11]  -> txFrame.srcMac
 * [12..13] -> txFrame.etherType
 * [14..N]  -> txFrame.payload
 * [N+1..]  -> FCS (handled automatically by hardware)
 */

int main(void) {

	/* Configure RMII mode for Ethernet MAC in DCM module */
	IP_DCM_GPR->DCMRWF1 = (IP_DCM_GPR->DCMRWF1
			& ~DCM_GPR_DCMRWF1_MAC_CONF_SEL_MASK)
			| DCM_GPR_DCMRWF1_MAC_CONF_SEL(2U);

	/* Initialize and configure the MCU's pins for peripherals (like Ethernet). */
	Siul2_Port_Ip_Init(
	NUM_OF_CONFIGURED_PINS_PortContainer_0_BOARD_InitPeripherals,
			g_pin_mux_InitConfigArr_PortContainer_0_BOARD_InitPeripherals);

	/* Initialize the microcontroller's clock system based on the provided configuration. */
	Clock_Ip_Init(&Clock_Ip_aClockConfig[0]);

	IntCtrl_Ip_InstallHandler(EMAC_2_IRQn, GMAC0_CH_RX_IRQHandler, NULL_PTR);
	IntCtrl_Ip_EnableIrq(EMAC_2_IRQn);

	IntCtrl_Ip_InstallHandler(EMAC_0_IRQn, GMAC0_Common_IRQHandler, NULL_PTR);
	IntCtrl_Ip_EnableIrq(EMAC_0_IRQn);

	/* Initialize the GMAC (Ethernet) peripheral with its configuration. */
	Status = Gmac_Ip_Init(INST_GMAC_0, &Gmac_0_ConfigPB);
	DevAssert(Status == GMAC_STATUS_SUCCESS); // Halt if initialization fails.

	Eth_Phy_Init();

	while (1) {

	}

	return 0;
}
