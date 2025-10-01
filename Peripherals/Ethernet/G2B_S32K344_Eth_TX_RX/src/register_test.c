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

uint16_t phy_addr;             // Discovered PHY address
uint16_t register_value_0;     // Temporary register value storage
uint16_t register_value_1;

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

	/* Initialize GMAC peripheral */
	Status = Gmac_Ip_Init(INST_GMAC_0, &Gmac_0_ConfigPB);
	DevAssert(Status == GMAC_STATUS_SUCCESS);  // Stop if initialization fails

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

	/* Unlock Config access if not already enabled */
	Status = Gmac_Ip_MDIOReadMMD(INST_GMAC_0, phy_addr, 30, 0x8100U,
			&register_value_0, 1U);
	if ((register_value_0 & 0x4000U) == 0U) {
		Status = Gmac_Ip_MDIOWriteMMD(INST_GMAC_0, phy_addr, 30, 0x8100U,
				0x4000U, 1U);
		/* Verify Config-Enable flag */
		Status = Gmac_Ip_MDIOReadMMD(INST_GMAC_0, phy_addr, 30, 0x8100U,
				&register_value_0, 1U);
	}

	/* Master/Slave mode check (Reg 0x834, Device 1)
	 * - 32768 = Slave mode
	 * - 49152 = Master mode
	 */
	Status = Gmac_Ip_MDIOReadMMD(INST_GMAC_0, phy_addr, 1, 0x0834U,
			&register_value_0, 1U);

	/* xMII Basic Config (0xAFC6 should return 21 -> Rev-RMII) */
	Status = Gmac_Ip_MDIOReadMMD(INST_GMAC_0, phy_addr, 30, 0xAFC6U,
			&register_value_0, 1U);

	/* Auto-polarity correction:
	 * - Bit0 = auto (should be set by default)
	 * - Bit1 = test mode (should be 0)
	 * - Bit2 = polarity_correct_disable (should be 0 in slave, ignored in master)
	 */
	Status = Gmac_Ip_MDIOReadMMD(INST_GMAC_0, phy_addr, 30, 0x8108U,
			&register_value_0, 1U);

	/* Force polarity correction config (set bit0 only) */
	Status = Gmac_Ip_MDIOWriteMMD(INST_GMAC_0, phy_addr, 30, 0x8108U, 0x0001U,
			1U);

	/* Verify polarity correction settings */
	Status = Gmac_Ip_MDIOReadMMD(INST_GMAC_0, phy_addr, 30, 0x8108U,
			&register_value_0, 1U);

	/* ======================== PHY Status ============================= */

	/* Start operation check (Reg 0x40) -> if bit0=1, PHY is busy */
	Status = Gmac_Ip_MDIOReadMMD(INST_GMAC_0, phy_addr, 30, 0x0040U,
			&register_value_0, 1U);

	/* Basic State Check (Reg 0x810C) -> Bits[3:0] should be 1101b */
	Status = Gmac_Ip_MDIOReadMMD(INST_GMAC_0, phy_addr, 30, 0x810CU,
			&register_value_0, 1U);

	/* Link Status (Reg 0x8102)
	 * - Bit2 = link established
	 * - Bit7 = polarity detection (if set, physical connections need inversion)
	 */
	Status = Gmac_Ip_MDIOReadMMD(INST_GMAC_0, phy_addr, 30, 0x8102U,
			&register_value_0, 1U);

	/* ======================== Infinite Loop ========================== */
	for (;;) {
		// Application main loop
	}

	return 0;
}
