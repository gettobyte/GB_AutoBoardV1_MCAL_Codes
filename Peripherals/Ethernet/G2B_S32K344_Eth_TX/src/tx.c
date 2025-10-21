/**
 *   @file main.c
 *
 *   @addtogroup main_module main module documentation
 *   @{
 */

/* Including necessary configuration files. */
#include "Mcal.h"
#include "S32K344.h"
#include "IntCtrl_Ip.h"
#include "Clock_Ip.h"
#include "Gmac_Ip.h"
#include "Gmac_Ip_Irq.h"
#include "Siul2_Port_Ip.h"
#include "string.h"

volatile int exit_code = 0;
/* User includes */

#define PAYLOAD_SIZE 50U

/* ===== PHY discovery scratch ===== */
static uint16 phy_addr; /* discovered PHY address (0..31) */
static uint16 register_value_0;
static uint16 register_value_1;

Gmac_Ip_TxOptionsType TxOptions = { FALSE, GMAC_CRC_AND_PAD_INSERTION,
		GMAC_CHECKSUM_INSERTION_IP};
Gmac_Ip_BufferType TxBuffer = { 0 };
Gmac_Ip_TxInfoType TxInfo = { 0 };
Gmac_Ip_StatusType Status;
uint8 MacAddr_Src[6U] = { 0x10, 0x11, 0x22, 0x77, 0x77, 0x77 };
uint8 MacAddr_Dest[6U] = { 0x10, 0x11, 0x22, 0x77, 0x77, 0x78 };

void RX_Callback(void) {

}

void TX_Callback(void) {

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
	uint8 payload[PAYLOAD_SIZE]; /* A buffer for the payload data. */
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

/* ====== Simple busy-wait delay (approx) ====== */
/* Adjust for your clock; this is just to pace packets for Wireshark */
static void delay_cycles(volatile uint32_t cycles) {
	while (cycles--) {
		__asm("nop");
	}
}

int main(void) {

	/* Put MAC into RMII mode through DCM (per your original code) */
	IP_DCM_GPR->DCMRWF1 = (IP_DCM_GPR->DCMRWF1
			& ~DCM_GPR_DCMRWF1_MAC_CONF_SEL_MASK)
			| DCM_GPR_DCMRWF1_MAC_CONF_SEL(2U);

	Siul2_Port_Ip_Init(
	NUM_OF_CONFIGURED_PINS_PortContainer_0_BOARD_InitPeripherals,
			g_pin_mux_InitConfigArr_PortContainer_0_BOARD_InitPeripherals);

	/* Clocks / Pins / GMAC driver (generated by RTD config tool) */
	Clock_Ip_Init(&Clock_Ip_aClockConfig[0]);

	DevAssert(IntCtrl_Ip_Init(&IntCtrlConfig_0) == INTCTRL_IP_STATUS_SUCCESS);

	Status = Gmac_Ip_Init(INST_GMAC_0, &Gmac_0_ConfigPB);
	DevAssert(Status == GMAC_STATUS_SUCCESS);

	/* Bring up PHY and wait for link */
	Eth_Phy_Init();

	/* Declare a local variable to hold the Ethernet frame data. */
	EthFrame_t txFrame;

	/* --- Assemble the Ethernet Frame --- */
	/* Copy the retrieved hardware MAC as the source address. */
	memcpy(txFrame.srcMac, MacAddr_Src, 6U);
	/* Copy the predefined destination MAC address. */
	memcpy(txFrame.dstMac, MacAddr_Dest, 6U);
	/* Set a custom EtherType (e.g., for a proprietary protocol). 0xBB80 = 48000 */
	txFrame.etherType = 0x0800U;
	/* Set the payload length. Ethernet requires a minimum frame size, so payloads < 46 bytes get padded. */
	txFrame.payloadLen = PAYLOAD_SIZE;

	/* Fill the payload with dummy data (a simple ascending sequence of numbers). */
	for (uint16 i = 0; i < txFrame.payloadLen; i++) {
		txFrame.payload[i] = i;
	}

	/* --- Prepare for Transmission --- */
	/* Request a free transmit buffer from the GMAC driver's internal queue. */
	Status = Gmac_Ip_GetTxBuff(INST_GMAC_0, 0U, &TxBuffer, NULL_PTR);
	DevAssert(Status == GMAC_STATUS_SUCCESS); // Halt if no buffer is available.

	/* Call the helper function to copy the assembled frame into the hardware buffer. */
	BuildEthernetFrame(&TxBuffer, &txFrame);

	/* ==== Send once per second so Wireshark is easy to read ==== */
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

		/* ~1 second delay (tune for your clock: this is a rough software wait) */
		delay_cycles(10000000U);

		if (exit_code != 0) {
			break;
		}
	}

	return exit_code;
}
/** @} */
