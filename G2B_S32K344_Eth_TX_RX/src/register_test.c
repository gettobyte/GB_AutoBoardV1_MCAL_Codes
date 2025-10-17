/*
 * register_test.c
 *
 *  Created on: 29-Sep-2025
 *      Author: singh
 *
 *  Purpose:
 *  ----------
 *  This code initializes the microcontroller clocks, I/O pins, and the GMAC (Ethernet MAC).
 *  It then searches for a connected TJA110X PHY via MDIO, resets it, and performs basic
 *  configuration and status checks.
 */

/* ============================== Includes ============================== */
#include "Mcal.h"               // Microcontroller Abstraction Layer definitions
#include "Clock_Ip.h"           // Clock initialization and configuration driver
#include "Siul2_Port_Ip_Cfg.h"  // SIUL2 Port configuration
#include "Siul2_Port_Ip.h"      // SIUL2 Port driver for pin multiplexing
#include "Gmac_Ip.h"            // Gigabit MAC (Ethernet Controller) driver
#include "string.h"             // Standard C library for memory operations

/* ============================== Globals =============================== */
volatile int exit_code = 0;   // Used for debugger-controlled exit

#define INST_GMAC_0     (0U)  // GMAC instance to be used (instance 0)

Gmac_Ip_StatusType Status = 0;  // Return status for GMAC driver APIs

uint16_t phy_addr, register_value_0, register_value_1, bist_DA_0, bist_DA_1,
		bist_DA_2, bist_SA_0, bist_SA_1, bist_SA_2;

/* ============================== Main Code ============================= */
int main(void) {
	/* Configure RMII mode for Ethernet MAC in DCM module */
	IP_DCM_GPR->DCMRWF1 = (IP_DCM_GPR->DCMRWF1
			& ~DCM_GPR_DCMRWF1_MAC_CONF_SEL_MASK)
			| DCM_GPR_DCMRWF1_MAC_CONF_SEL(2U);

	/* Initialize MCU clocking */
	Clock_Ip_Init(&Clock_Ip_aClockConfig[0]);

	/* Initialize MCU pins for peripheral functions (Ethernet, etc.) */
	Siul2_Port_Ip_Init(
	NUM_OF_CONFIGURED_PINS_PortContainer_0_BOARD_InitPeripherals,
			g_pin_mux_InitConfigArr_PortContainer_0_BOARD_InitPeripherals);

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
//	/* ePHY Enable Check (bit 2 should be 1) */
//	Status = Gmac_Ip_MDIOReadMMD(INST_GMAC_0, phy_addr, 1, 0x8048U,
//			&register_value_0, 1U);
//	if (((register_value_0 >> 2) & 0x1U) != 1U) {
//		while (1)
//			; /* Halt if ePHY not enabled */
//	}
//
//	/* Unlock Config access if not already enabled */
//	Status = Gmac_Ip_MDIOReadMMD(INST_GMAC_0, phy_addr, 30, 0x8100U,
//			&register_value_0, 1U);
//	if ((register_value_0 & 0x4000U) == 0U) {
//
//		Status = Gmac_Ip_MDIOWriteMMD(INST_GMAC_0, phy_addr, 30, 0x8100U,
//				0x4000U, 1U);
//
//		/* Verify Config-Enable flag */
//		Status = Gmac_Ip_MDIOReadMMD(INST_GMAC_0, phy_addr, 30, 0x8100U,
//				&register_value_0, 1U);
//
//		if ((register_value_0 & 0x4000U) == 0U) {
//			while (1)
//				; /* Halt if Config not enabled */
//		}
//	}
//
//	/* Master/Slave mode check (Reg 0x834, Device 1)
//	 * - 32768 = Slave mode
//	 * - 49152 = Master mode
//	 */
//	Status = Gmac_Ip_MDIOReadMMD(INST_GMAC_0, phy_addr, 1, 0x0834U,
//			&register_value_0, 1U);
//	if ((register_value_0 != 32768U) && (register_value_0 != 49152U)) {
//		while (1)
//			; /* Halt if not valid Master/Slave mode */
//	}
//
//	/* xMII Basic Config (0xAFC6 should return 21 -> Rev-RMII) */
//	Status = Gmac_Ip_MDIOReadMMD(INST_GMAC_0, phy_addr, 30, 0xAFC6U,
//			&register_value_0, 1U);
//	if (register_value_0 != 21U) {
//		while (1)
//			; /* Halt if not Rev-RMII */
//	}
//
//	/* Auto-polarity correction:
//	 * - Bit0 = auto (should be set by default)
//	 * - Bit1 = test mode (should be 0)
//	 * - Bit2 = polarity_correct_disable (should be 0 in slave, ignored in master)
//	 */
//	Status = Gmac_Ip_MDIOReadMMD(INST_GMAC_0, phy_addr, 30, 0x8108U,
//			&register_value_0, 1U);
//	if (((register_value_0 & 0x1U) == 0U) || /* Bit0 must be 1 */
//	((register_value_0 & 0x2U) != 0U)) { /* Bit1 must be 0 */
//		while (1)
//			; /* Halt if auto-polarity config invalid */
//	}
//
//	/* Force polarity correction config (set bit0 only) */
//	Status = Gmac_Ip_MDIOWriteMMD(INST_GMAC_0, phy_addr, 30, 0x8108U, 0x0001U,
//			1U);
//
//	/* Verify polarity correction settings */
//	Status = Gmac_Ip_MDIOReadMMD(INST_GMAC_0, phy_addr, 30, 0x8108U,
//			&register_value_0, 1U);
//	if (register_value_0 != 0x0001U) {
//		while (1)
//			; /* Halt if polarity correction not set */
//	}
//
//	/* ======================== PHY Status ============================= */
//
//	/* Start operation check (Reg 0x40) -> if bit0=1, PHY is busy */
//	Status = Gmac_Ip_MDIOReadMMD(INST_GMAC_0, phy_addr, 30, 0x0040U,
//			&register_value_0, 1U);
//	if ((register_value_0 & 0x1U) != 0U) {
//		while (1)
//			; /* Halt if PHY still busy */
//	}
//
//	/* Basic State Check (Reg 0x810C) -> Bits[3:0] should be 1101b */
//	Status = Gmac_Ip_MDIOReadMMD(INST_GMAC_0, phy_addr, 30, 0x810CU,
//			&register_value_0, 1U);
//	if ((register_value_0 & 0xFU) != 0xDU) {
//		while (1)
//			; /* Halt if state mismatch */
//	}
//
//	/* Link Status (Reg 0x8102)
//	 * - Bit2 = link established
//	 * - Bit7 = polarity detection (if set, physical connections need inversion)
//	 */
//	Status = Gmac_Ip_MDIOReadMMD(INST_GMAC_0, phy_addr, 30, 0x8102U,
//			&register_value_0, 1U);
//	if (((register_value_0 & (1U << 2)) == 0U) /* Bit2 must be 1 */) {
//		while (1)
//			; /* Halt if link not OK */
//	}
	/* ======================== BIST Enable ============================= */
	Gmac_Ip_MDIOReadMMD(INST_GMAC_0, phy_addr, 30U, 0x0040U, &register_value_0,
			1U);

	Gmac_Ip_MDIOWriteMMD(INST_GMAC_0, phy_addr, 30U, 0x0040U, 0x2001, 1U);

	Gmac_Ip_MDIOReadMMD(INST_GMAC_0, phy_addr, 30U, 0xA800U, &register_value_0,
			1U);

	Gmac_Ip_MDIOWriteMMD(INST_GMAC_0, phy_addr, 30U, 0xA800U, 0x4000, 1U);

	Gmac_Ip_MDIOReadMMD(INST_GMAC_0, phy_addr, 30U, 0x8048U, &register_value_0,
			1U);

	Gmac_Ip_MDIOWriteMMD(INST_GMAC_0, phy_addr, 30U, 0x8048U, 0x2805, 1U);

	Gmac_Ip_MDIOReadMMD(INST_GMAC_0, phy_addr, 3U, 0x0000U, &register_value_0,
			1U);

//	Gmac_Ip_MDIOWriteMMD(INST_GMAC_0, phy_addr, 3U, 0x0000U, 0x6000, 1U);

	Gmac_Ip_MDIOReadMMD(INST_GMAC_0, phy_addr, 30U, 0xA807U, &register_value_0,
			1U);

	Gmac_Ip_MDIOWriteMMD(INST_GMAC_0, phy_addr, 30U, 0xA807U, 0x0820, 1U);

	Gmac_Ip_MDIOReadMMD(INST_GMAC_0, phy_addr, 30U, 0xA8C0U, &register_value_0,
			1U);

	Gmac_Ip_MDIOWriteMMD(INST_GMAC_0, phy_addr, 30U, 0xA8C0U, 0x4001, 1U);

	Gmac_Ip_MDIOReadMMD(INST_GMAC_0, phy_addr, 30U, 0xA880U, &register_value_0,
			1U);

	Gmac_Ip_MDIOWriteMMD(INST_GMAC_0, phy_addr, 30U, 0xA880U, 0x6000, 1U);

//	BIST DA {15:0}
	Gmac_Ip_MDIOReadMMD(INST_GMAC_0, phy_addr, 30U, 0xA888U, &bist_DA_0, 1U);
	Gmac_Ip_MDIOWriteMMD(INST_GMAC_0, phy_addr, 30U, 0xA888U, 0x2211, 1U);
//	BIST DA {31:16}
	Gmac_Ip_MDIOReadMMD(INST_GMAC_0, phy_addr, 30U, 0xA889U, &bist_DA_1, 1U);
	Gmac_Ip_MDIOWriteMMD(INST_GMAC_0, phy_addr, 30U, 0xA889U, 0x4433, 1U);
//	BIST DA {47:32}
	Gmac_Ip_MDIOReadMMD(INST_GMAC_0, phy_addr, 30U, 0xA88AU, &bist_DA_2, 1U);
	Gmac_Ip_MDIOWriteMMD(INST_GMAC_0, phy_addr, 30U, 0xA88AU, 0x6655, 1U);

//	BIST SA {15:0}
	Gmac_Ip_MDIOReadMMD(INST_GMAC_0, phy_addr, 30U, 0xA88BU, &bist_SA_0, 1U);
	Gmac_Ip_MDIOWriteMMD(INST_GMAC_0, phy_addr, 30U, 0xA88BU, 0x2212, 1U);
//	BIST SA {31:16}
	Gmac_Ip_MDIOReadMMD(INST_GMAC_0, phy_addr, 30U, 0xA88CU, &bist_SA_1, 1U);
	Gmac_Ip_MDIOWriteMMD(INST_GMAC_0, phy_addr, 30U, 0xA88CU, 0x4433, 1U);
//	BIST SA {47:32}
	Gmac_Ip_MDIOReadMMD(INST_GMAC_0, phy_addr, 30U, 0xA88DU, &bist_SA_2, 1U);
	Gmac_Ip_MDIOWriteMMD(INST_GMAC_0, phy_addr, 30U, 0xA88DU, 0x6655, 1U);

	Gmac_Ip_MDIOReadMMD(INST_GMAC_0, phy_addr, 30U, 0xA890U, &register_value_0,
			1U);

	Gmac_Ip_MDIOWriteMMD(INST_GMAC_0, phy_addr, 30U, 0xA890U, 0x0800, 1U);

	Gmac_Ip_MDIOWriteMMD(INST_GMAC_0, phy_addr, 30U, 0xA880U, 0x1000, 1U);

	/* ======================== Infinite Loop ========================== */
	for (;;) {
		// Application main loop
		Gmac_Ip_MDIOReadMMD(INST_GMAC_0, phy_addr, 30U, 0xA8D0U,
				&register_value_0, 1U);

		Gmac_Ip_MDIOReadMMD(INST_GMAC_0, phy_addr, 30U, 0xA8D2U,
				&register_value_0, 1U);
	}

	return 0;
}
