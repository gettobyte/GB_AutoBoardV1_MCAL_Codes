/*
 * register_test.c
 *
 *  Created on: 29-Sep-2025
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

uint16_t phy_addr, register_value_0, register_value_1;

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
	DevAssert(Status == GMAC_STATUS_SUCCESS); // Halt if initialization fails.

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

//	Setting Config-Enable flag of Phy-Control Register otherwise access is resticted
	Status = Gmac_Ip_MDIOReadMMD(INST_GMAC_0, phy_addr, 30, 0x8100U,
			&register_value_0, 1U);

	Status = Gmac_Ip_MDIOWriteMMD(INST_GMAC_0, phy_addr, 30, 0x8100U, 0x4000U,
			1U);

	Status = Gmac_Ip_MDIOReadMMD(INST_GMAC_0, phy_addr, 30, 0x8100U,
			&register_value_0, 1U);


//	If returned value is 32768 then board is in Slave mode or
//	if returned value is 49152 then board is in Master mode
	Status = Gmac_Ip_MDIOReadMMD(INST_GMAC_0, phy_addr, 1, 0x834U,
			&register_value_0, 1U);


//	Auto-polarity correction to be enabled only for slave
//	configuration where pin strapping is disabling the polarity correction
	Status = Gmac_Ip_MDIOReadMMD(INST_GMAC_0, phy_addr, 30, 0x8108U,
			&register_value_0, 1U);

	Status = Gmac_Ip_MDIOWriteMMD(INST_GMAC_0, phy_addr, 30, 0x8108U, 0x1U,
			1U);

	Status = Gmac_Ip_MDIOReadMMD(INST_GMAC_0, phy_addr, 30, 0x8108U,
			&register_value_0, 1U);


//	Start operation check(bit 0)
	Status = Gmac_Ip_MDIOReadMMD(INST_GMAC_0, phy_addr, 30, 0x40U,
			&register_value_0, 1U);


//	ePHY enable or not check(bit 2)
	Status = Gmac_Ip_MDIOReadMMD(INST_GMAC_0, phy_addr, 1, 0x8048U,
			&register_value_0, 1U);


//	xMII Basic Config if value is 21 which means rev-RMII
	Status = Gmac_Ip_MDIOReadMMD(INST_GMAC_0, phy_addr, 30, 0xAFC6U,
			&register_value_0, 1U);


//	Phy_Linking Register
	Status = Gmac_Ip_MDIOReadMMD(INST_GMAC_0, phy_addr, 30, 0x8102U,
			&register_value_0, 1U);


//	Phy-state Basic State
	Status = Gmac_Ip_MDIOReadMMD(INST_GMAC_0, phy_addr, 30, 0x810CU,
			&register_value_0, 1U);

//	Linking Timer
	Status = Gmac_Ip_MDIOReadMMD(INST_GMAC_0, phy_addr, 30, 0x8340U,
			&register_value_0, 1U);

	for (;;) {

	}

	return 0;
}
