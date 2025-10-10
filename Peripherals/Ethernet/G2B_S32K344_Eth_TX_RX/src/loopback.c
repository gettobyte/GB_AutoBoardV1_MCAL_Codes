/*
 * loopback.c
 *
 *  Created on: 06-Oct-2025
 *      Author: singh
 */

/* Including necessary configuration files for the microcontroller and peripherals. */
#include "Mcal.h"               // Microcontroller Abstraction Layer definitions.
#include "Clock_Ip.h"           // Clock initialization and configuration driver.
#include "Siul2_Port_Ip_Cfg.h"  // SIUL2 (System Integration Unit Lite 2) Port configuration.
#include "Siul2_Port_Ip.h"      // SIUL2 Port driver for pin muxing.
#include "Gmac_Ip.h"            // Gigabit MAC (Ethernet Controller) driver.
#include "string.h"             // Standard C library for memory operations.

/* A volatile integer used for gracefully exiting the main loop, typically changed by a debugger. */
volatile int exit_code = 0;

/* Defines the instance number for the GMAC peripheral to be used. Here, it's GMAC instance 0. */
#define INST_GMAC_0     (0U)

/* A global variable to hold the status returned by GMAC driver functions. */
Gmac_Ip_StatusType Status = 0;

uint16_t phy_addr, register_value_0, register_value_1, bist_DA_0, bist_DA_1,
		bist_DA_2, bist_SA_0, bist_SA_1, bist_SA_2;

/* A 6-byte array to store the source MAC address, which will be retrieved from the hardware. */
uint8 MacAddr_Src[6U] = { 66, 55, 44, 33, 22, 11 };

/* A 6-byte array defining the destination MAC address for the Ethernet frame. */
uint8 MacAddr_Dest[6U] = { 66, 55, 44, 33, 22, 11 };

/* Configuration options for the transmission, enabling automatic CRC and padding insertion. */
Gmac_Ip_TxOptionsType TxOptions = { TRUE, GMAC_CRC_AND_PAD_INSERTION,
		GMAC_CHECKSUM_INSERTION_DISABLE };

/* A buffer structure provided by the GMAC driver to hold the data to be transmitted. */
Gmac_Ip_BufferType TxBuffer = { 0 };

/* Structures to hold metadata about the transmission. */
Gmac_Ip_TxInfoType TxInfo = { 0 };

Gmac_Ip_BufferType RxBuffer = { 0 };

Gmac_Ip_RxInfoType RxInfo = { 0 };

int main(void) {

	/* Set RMII configuration for EMAC in DCM module */
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

	Gmac_Ip_EnableMDIO(INST_GMAC_0, FALSE, 48000000U);

	/* Search for the TJA110X address */
	for (phy_addr = 0U; phy_addr < 32U; ++phy_addr) {

		Status = Gmac_Ip_MDIORead(INST_GMAC_0, phy_addr, 2U, &register_value_0,
				1U);
		Status = Gmac_Ip_MDIORead(INST_GMAC_0, phy_addr, 3U, &register_value_1,
				1U);

		/* check for TJA110X ID */
		if ((register_value_0 == 0x1B) && (register_value_1 == 0xB013)) {
			break; /* found the TJA110X ID*/
		}
	}

	/* Reset the TJA110X */
	Status = Gmac_Ip_MDIOWrite(INST_GMAC_0, phy_addr, 0U, 0x8000U, 1U);

	/* Wait until the TJA110X is out of reset */
	do {
		/* Read the value from the PHY register. This action is now in the loop's body. */
		Status = Gmac_Ip_MDIORead(INST_GMAC_0, phy_addr, 0U, &register_value_0,
				1U);

	} while (register_value_0 & 0x8000U); /* Check the 15th bit and loop if it's 1 (TJA110X is resetting). */

//	Enable all configuration access
	Gmac_Ip_MDIOReadMMD(INST_GMAC_0, phy_addr, 30U, 0x0040U, &register_value_0,
			1U);

	Gmac_Ip_MDIOWriteMMD(INST_GMAC_0, phy_addr, 30U, 0x0040U, 0x2000, 1U);

//    Enable BIST configuration and functionality
	Gmac_Ip_MDIOReadMMD(INST_GMAC_0, phy_addr, 30U, 0xA800U, &register_value_0,
			1U);

	Gmac_Ip_MDIOWriteMMD(INST_GMAC_0, phy_addr, 30U, 0xA800U, 0x4000, 1U); // Set PORT_BIST_CONTROL.CONFIG_ENABLE = 1

	Gmac_Ip_MDIOReadMMD(INST_GMAC_0, phy_addr, 30U, 0x8048U, &register_value_0,
			1U);

	Gmac_Ip_MDIOWriteMMD(INST_GMAC_0, phy_addr, 30U, 0x8048U, 0x0800, 1U); // Set PORT_FUNC_ENABLES.BIST_ENABLE = 1

//    Configure datapath to send BIST frames to the MDI (ePHY)
	Gmac_Ip_MDIOReadMMD(INST_GMAC_0, phy_addr, 30U, 0xA807U, &register_value_0,
			1U);

	Gmac_Ip_MDIOWriteMMD(INST_GMAC_0, phy_addr, 30U, 0xA807U, 0x0020, 1U);

//    Configure generator for continuous mode
	Gmac_Ip_MDIOReadMMD(INST_GMAC_0, phy_addr, 30U, 0xA880U, &register_value_0,
			1U);

	Gmac_Ip_MDIOWriteMMD(INST_GMAC_0, phy_addr, 30U, 0xA880U, 0x2000, 1U);

//	BIST DA {15:0}
	Gmac_Ip_MDIOReadMMD(INST_GMAC_0, phy_addr, 30U, 0xA888U, &bist_DA_0, 1U);
//	BIST DA {31:16}
	Gmac_Ip_MDIOReadMMD(INST_GMAC_0, phy_addr, 30U, 0xA889U, &bist_DA_1, 1U);
//	BIST DA {47:32}
	Gmac_Ip_MDIOReadMMD(INST_GMAC_0, phy_addr, 30U, 0xA88AU, &bist_DA_2, 1U);

//	BIST SA {15:0}
	Gmac_Ip_MDIOReadMMD(INST_GMAC_0, phy_addr, 30U, 0xA888U, &bist_SA_0, 1U);
//	BIST SA {31:16}
	Gmac_Ip_MDIOReadMMD(INST_GMAC_0, phy_addr, 30U, 0xA889U, &bist_SA_1, 1U);
//	BIST SA {47:32}
	Gmac_Ip_MDIOReadMMD(INST_GMAC_0, phy_addr, 30U, 0xA88AU, &bist_SA_2, 1U);

	do {
		Gmac_Ip_MDIOReadMMD(INST_GMAC_0, phy_addr, 30U, 0x8102U,
				&register_value_0, 1U);
	} while ((0U == (register_value_0 & (1U << 2U))));

//    Start the BIST frame generator
	Gmac_Ip_MDIOReadMMD(INST_GMAC_0, phy_addr, 30U, 0xA880U, &register_value_0,
			1U);

	Gmac_Ip_MDIOWriteMMD(INST_GMAC_0, phy_addr, 30U, 0xA807U, 0x6000, 1U);

//	/* --- Assemble the Ethernet Frame --- */
//	/* Copy the retrieved hardware MAC as the source address. */
//	memcpy(txFrame.srcMac, MacAddr_Src, 6U);
//	/* Copy the predefined destination MAC address. */
//	memcpy(txFrame.dstMac, MacAddr_Dest, 6U);
//	/* Set a custom EtherType (e.g., for a proprietary protocol). 0xBB80 = 48000 */
//	txFrame.etherType = 0xBB80U;
//	/* Set the payload length. Ethernet requires a minimum frame size, so payloads < 46 bytes get padded. */
//	txFrame.payloadLen = 46U;
//
//	/* Fill the payload with dummy data (a simple ascending sequence of numbers). */
//	for (uint16 i = 0; i < txFrame.payloadLen; i++) {
//		txFrame.payload[i] = (uint8) i;
//	}
//
//	/* --- Prepare for Transmission --- */
//	/* Request a free transmit buffer from the GMAC driver's internal queue. */
//	Status = Gmac_Ip_GetTxBuff(INST_GMAC_0, 0U, &TxBuffer, NULL_PTR);
//	DevAssert(Status == GMAC_STATUS_SUCCESS); // Halt if no buffer is available.
//
//	/* Call the helper function to copy the assembled frame into the hardware buffer. */
//	BuildEthernetFrame(&TxBuffer, &txFrame);
//
//	/* Infinite loop to keep the program running, typical for embedded applications. */
//	for (;;) {
//
//		/* --- Send the Frame --- */
//		/* Instruct the GMAC hardware to send the contents of the buffer. */
//		Status = Gmac_Ip_SendFrame(INST_GMAC_0, 0U, &TxBuffer, &TxOptions);
//		DevAssert(Status == GMAC_STATUS_SUCCESS); // Halt if sending fails.
//
//		/* Wait for the frame to be transmitted */
//		do {
//			Status = Gmac_Ip_GetTransmitStatus(INST_GMAC_0, 0U, &TxBuffer,
//					&TxInfo);
//		} while (Status == GMAC_STATUS_BUSY);
//
//		DevAssert((GMAC_STATUS_SUCCESS == Status) || (0U != TxInfo.ErrMask));
//
//		/* Wait for the frame to be received */
//		do {
//			Status = Gmac_Ip_ReadFrame(INST_GMAC_0, 0U, &RxBuffer, &RxInfo);
//		} while (Status == GMAC_STATUS_RX_QUEUE_EMPTY);
//
//		/* Check the frame status */
//		if (Status == GMAC_STATUS_SUCCESS && RxInfo.ErrMask == 0U) {
//
//			uint8 *ptr = RxBuffer.Data;
//
//			/* Extract directly into rxFrame structure */
//			memcpy(rxFrame.dstMac, ptr, 6U);
//			ptr += 6U;
//
//			memcpy(rxFrame.srcMac, ptr, 6U);
//			ptr += 6U;
//
//			rxFrame.etherType = (uint16) ((ptr[0] << 8) | ptr[1]);
//			ptr += 2U;
//
//			rxFrame.payloadLen = (uint16) (RxBuffer.Length - 14U);
//
//			memcpy(rxFrame.payload, ptr, rxFrame.payloadLen);
//
//			/* Simple check */
//			if (rxFrame.etherType == 0xBB80U) {
////				correct_frame = true;
//			}
//
//			Gmac_Ip_ProvideRxBuff(INST_GMAC_0, 0U, &RxBuffer);
//
//		}
//
//	}

	while (1);
	return exit_code;

}
