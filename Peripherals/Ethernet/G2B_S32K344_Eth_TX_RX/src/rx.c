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

/* A volatile integer used for gracefully exiting the main loop, typically changed by a debugger. */
volatile int exit_code = 0;

boolean correct_frame = false;

/* Defines the instance number for the GMAC peripheral to be used. Here, it's GMAC instance 0. */
#define INST_GMAC_0     (0U)

/* A global variable to hold the status returned by GMAC driver functions. */
Gmac_Ip_StatusType Status = 0;

/* A buffer structure for receiving data (though not used in this transmit-only example). */
Gmac_Ip_BufferType RxBuffer = { 0 };

/* Structures to hold metadata about the reception. */
Gmac_Ip_RxInfoType RxInfo = { 0 };

/* A structure to represent an Ethernet frame in a user-friendly way. */
typedef struct {
	uint8 dstMac[6];
	uint8 srcMac[6];
	uint16 etherType;
	uint8 payload[64]; /* A buffer for the payload data. */
	uint16 payloadLen; /* The actual length of the payload. */
} EthFrame_t;

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

int main(void) {

	/* Initialize the microcontroller's clock system based on the provided configuration. */
	Clock_Ip_Init(&Clock_Ip_aClockConfig[0]);

	/* Initialize and configure the MCU's pins for peripherals (like Ethernet). */
	Siul2_Port_Ip_Init(
	NUM_OF_CONFIGURED_PINS_PortContainer_0_BOARD_InitPeripherals,
			g_pin_mux_InitConfigArr_PortContainer_0_BOARD_InitPeripherals);

	/* Initialize the GMAC (Ethernet) peripheral with its configuration. */
	Status = Gmac_Ip_Init(INST_GMAC_0, &Gmac_0_ConfigPB);
	DevAssert(Status == GMAC_STATUS_SUCCESS); // Halt if initialization fails.

	EthFrame_t rxFrame;

	while (1) {

		Status = Gmac_Ip_ReadFrame(INST_GMAC_0, 0U, &RxBuffer, &RxInfo);
		DevAssert(Status == GMAC_STATUS_SUCCESS);

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

	return 0;
}

