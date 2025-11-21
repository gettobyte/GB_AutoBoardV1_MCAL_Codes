/*==================================================================================================
 * Project : RTD AUTOSAR 4.7
 * Platform : CORTEXM
 * Peripheral : S32K3XX
 * Dependencies : none
 *
 * Autosar Version : 4.7.0
 * Autosar Revision : ASR_REL_4_7_REV_0000
 * Autosar Conf.Variant :
 * SW Version : 4.0.0
 * Build Version : S32K3_RTD_4_0_0_P24_D2405_ASR_REL_4_7_REV_0000_20240515
 *
 * Copyright 2020 - 2024 NXP
 *
 * NXP Confidential. This software is owned or controlled by NXP and may only be
 * used strictly in accordance with the applicable license terms. By expressly
 * accepting such terms or by downloading, installing, activating and/or otherwise
 * using the software, you are agreeing that you have read, and that you agree to
 * comply with and are bound by, such license terms. If you do not agree to be
 * bound by the applicable license terms, then you may not retain, install,
 * activate or otherwise use the software.
 ==================================================================================================*/

/**
 *   @file main.c
 *
 *   @addtogroup main_module main module documentation
 *   @{
 */

/* Including necessary configuration files. */
#include "Mcal.h"
#include "Clock_Ip.h"
#include "Siul2_Port_Ip.h"
#include "Lpspi_Ip.h"
#include "Siul2_Dio_Ip.h"
#include "ST7789_low_level.h"
#include "fonts.h"

volatile int exit_code = 0;
/* User includes */

void TestDelay(uint32 delay) {
	static volatile uint32 DelayTimer = 0;
	while (DelayTimer < delay) {
		DelayTimer++;
	}
	DelayTimer = 0;
}

/*!
 \brief The main function for the project.
 \details The startup initialization sequence is the following:
 * - startup asm routine
 * - main()
 */
int main(void) {
	Clock_Ip_StatusType clockStatus;
	Siul2_Port_Ip_PortStatusType portStatus;
	Lpspi_Ip_StatusType lpspiStatus;

	clockStatus = Clock_Ip_Init(&Clock_Ip_aClockConfig[0]);
	while (clockStatus != CLOCK_IP_SUCCESS) {
		clockStatus = Clock_Ip_Init(&Clock_Ip_aClockConfig[0]);
	}
#if defined (CLOCK_IP_HAS_PLL_CLK)
	/* Busy wait until the System PLL is locked */
	while (CLOCK_IP_PLL_LOCKED != Clock_Ip_GetPllStatus())
		;
	Clock_Ip_DistributePll();
#endif

	portStatus = Siul2_Port_Ip_Init(
	NUM_OF_CONFIGURED_PINS_PortContainer_0_BOARD_InitPeripherals,
			g_pin_mux_InitConfigArr_PortContainer_0_BOARD_InitPeripherals);

	lpspiStatus = Lpspi_Ip_Init(&Lpspi_Ip_PhyUnitConfig_SpiPhyUnit_0_Instance_4);

	GB_ST7789_Init();

	ST7789_SetAddressWindow(ST7789_XStart,ST7789_YStart, ST7789_XEnd, ST7789_YEnd);

	for (;;) {
		ST7789_Fill_Color(ST77XX_CYAN);

		ST7789_Fill_Color(ST77XX_NEON_GREEN);

		ST7789_Fill_Color(ST77XX_ORANGE);

		ST7789_Fill_Color(ST77XX_YELLOW);

		ST7789_Fill_Color(ST77XX_MAGENTA);

		ST7789_Fill_Color(ST77XX_BLUE);

		ST7789_Fill_Color(ST77XX_GREEN);

		ST7789_Fill_Color(ST77XX_RED);
		if (exit_code != 0) {
			break;
		}
	}
	return exit_code;
}

/** @} */
