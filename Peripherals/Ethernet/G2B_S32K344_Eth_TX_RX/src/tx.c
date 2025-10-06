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

/*
 * Ethernet Frame Format (IEEE 802.3 / Ethernet II)
 *
 * +------------+------------+-----------+------------------+-----------+
 * | Destination|   Source   | EtherType |      Payload     |    FCS    |
 * |   MAC (6B) |   MAC (6B) |   (2B)    |    (46–1500 B)   |   (4B)    |
 * +------------+------------+-----------+------------------+-----------+
 *
 * Field Details:
 * - Destination MAC (6 bytes): Who the frame is sent to
 * - Source MAC      (6 bytes): Who is sending the frame
 * - EtherType/Length(2 bytes): Protocol indicator
 * e.g. 0x0800 = IPv4, 0x0806 = ARP, custom = 0x88B5 etc.
 * - Payload         (46–1500 bytes): Actual data being sent
 * - FCS             (4 bytes): CRC checksum (auto-inserted by GMAC HW)
 *
 * In our code:
 * [0..5]   -> txFrame.dstMac
 * [6..11]  -> txFrame.srcMac
 * [12..13] -> txFrame.etherType
 * [14..N]  -> txFrame.payload
 * [N+1..]  -> FCS (handled automatically by hardware)
 */

/* A structure to represent an Ethernet frame in a user-friendly way. */
typedef struct {
	uint8 dstMac[6];
	uint8 srcMac[6];
	uint16 etherType;
	uint8 payload[64]; /* A buffer for the payload data. */
	uint16 payloadLen; /* The actual length of the payload. */
} EthFrame_t;

/**
 * @brief Constructs a raw Ethernet frame into a GMAC hardware buffer.
 * @param txBuf A pointer to the GMAC transmit buffer where the frame will be built.
 * @param frame A pointer to the user-friendly frame structure containing the data.
 */
static void BuildEthernetFrame(Gmac_Ip_BufferType *txBuf,
		const EthFrame_t *frame) {
	/* Get a pointer to the beginning of the hardware buffer's data area. */
	uint8 *ptr = txBuf->Data;

	/* Copy the 6-byte destination MAC address into the buffer. */
	memcpy(ptr, frame->dstMac, 6U);
	ptr += 6U; // Move the pointer forward by 6 bytes.

	/* Copy the 6-byte source MAC address. */
	memcpy(ptr, frame->srcMac, 6U);
	ptr += 6U; // Move the pointer forward.

	/* Copy the 2-byte EtherType, handling big-endian byte order manually. */
	*ptr++ = (uint8) ((frame->etherType >> 8) & 0xFFU); // Most Significant Byte (MSB)
	*ptr++ = (uint8) (frame->etherType & 0xFFU); // Least Significant Byte (LSB)

	/* Copy the payload data into the buffer. */
	memcpy(ptr, frame->payload, frame->payloadLen);
	ptr += frame->payloadLen; // Move the pointer past the payload.

	/* Set the total length of the buffer. The FCS (CRC) will be added by the hardware. */
	txBuf->Length = (uint32) (ptr - txBuf->Data);
}

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

	/* Declare a local variable to hold the Ethernet frame data. */
	EthFrame_t txFrame;

	/* Initialize the GMAC (Ethernet) peripheral with its configuration. */
	Status = Gmac_Ip_Init(INST_GMAC_0, &Gmac_0_ConfigPB);
	DevAssert(Status == GMAC_STATUS_SUCCESS); // Halt if initialization fails.

	Eth_Phy_Init();

	/* Retrieve the unique MAC address from the GMAC hardware and store it. */
//	Gmac_Ip_GetMacAddr(INST_GMAC_0, MacAddr_Src);

	/* --- Assemble the Ethernet Frame --- */
	/* Copy the retrieved hardware MAC as the source address. */
	memcpy(txFrame.srcMac, MacAddr_Src, 6U);
	/* Copy the predefined destination MAC address. */
	memcpy(txFrame.dstMac, MacAddr_Dest, 6U);
	/* Set a custom EtherType (e.g., for a proprietary protocol). 0xBB80 = 48000 */
	txFrame.etherType = 0xBB80U;
	/* Set the payload length. Ethernet requires a minimum frame size, so payloads < 46 bytes get padded. */
	txFrame.payloadLen = 46U;

	/* Fill the payload with dummy data (a simple ascending sequence of numbers). */
	for (uint16 i = 0; i < txFrame.payloadLen; i++) {
		txFrame.payload[i] = (uint8) i;
	}

	/* --- Prepare for Transmission --- */
	/* Request a free transmit buffer from the GMAC driver's internal queue. */
	Status = Gmac_Ip_GetTxBuff(INST_GMAC_0, 0U, &TxBuffer, NULL_PTR);
	DevAssert(Status == GMAC_STATUS_SUCCESS); // Halt if no buffer is available.

	/* Call the helper function to copy the assembled frame into the hardware buffer. */
	BuildEthernetFrame(&TxBuffer, &txFrame);

	/* Infinite loop to keep the program running, typical for embedded applications. */
	for (;;) {

		/* --- Send the Frame --- */
		/* Instruct the GMAC hardware to send the contents of the buffer. */
		Status = Gmac_Ip_SendFrame(INST_GMAC_0, 0U, &TxBuffer, &TxOptions);
		DevAssert(Status == GMAC_STATUS_SUCCESS); // Halt if sending fails.

		/* Wait for the frame to be transmitted */
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
