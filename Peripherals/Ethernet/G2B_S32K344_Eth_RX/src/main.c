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
 * Build Version : S32K3_RTD_4_0_0_P20_D2403_ASR_REL_4_7_REV_0000_20240315
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
#include "S32K344.h"
#include "IntCtrl_Ip.h"
#include "Clock_Ip.h"
#include "Gmac_Ip.h"
#include "Gmac_Ip_Irq.h"
#include "Siul2_Port_Ip.h"

volatile int exit_code = 0;

/* ===== PHY discovery scratch ===== */
static uint16 phy_addr; /* discovered PHY address (0..31) */
static uint16 register_value_0;
static uint16 register_value_1;

Gmac_Ip_TxOptionsType TxOptions = { FALSE, GMAC_CRC_AND_PAD_INSERTION,
		GMAC_CHECKSUM_INSERTION_DISABLE };
Gmac_Ip_BufferType TxBuffer = {0};
Gmac_Ip_BufferType RxBuffer = {0};
Gmac_Ip_TxInfoType TxInfo  = {0};
Gmac_Ip_RxInfoType RxInfo  = {0};
Gmac_Ip_StatusType Status;
uint8 MacAddr[6U] = { 0x10, 0x11, 0x22, 0x77, 0x77, 0x78 };
uint8 i;
uint8 j = 0U;

/* User includes */

void TX_Callback(void) {

}

void RX_Callback(void) {

	do {
		Status = Gmac_Ip_ReadFrame(INST_GMAC_0, 0U, &RxBuffer, &RxInfo);
	} while (Status == GMAC_STATUS_RX_QUEUE_EMPTY);

	if (Status == GMAC_STATUS_SUCCESS && RxInfo.ErrMask == 0U) {

	}

	}

	/* ====== PHY init (TJA110x via MDIO) ====== */
	static void Eth_Phy_Init(void) {
		/* Enable MDIO (Management Data I/O) for PHY communication */
		Gmac_Ip_EnableMDIO(INST_GMAC_0, FALSE, 48000000U);

		/* --- Discover PHY address by reading PHY ID1/ID2 --- */
		for (phy_addr = 0U; phy_addr < 32U; ++phy_addr) {
			(void) Gmac_Ip_MDIORead(INST_GMAC_0, phy_addr, 2U,
					&register_value_0, 1U);
			(void) Gmac_Ip_MDIORead(INST_GMAC_0, phy_addr, 3U,
					&register_value_1, 1U);

			/* TJA110x ID: 0x001B / 0xB013 (adjust if your silicon differs) */
			if ((register_value_0 == 0x001B) && (register_value_1 == 0xB013)) {
				break;
			}
		}

		/* Reset PHY */
		(void) Gmac_Ip_MDIOWrite(INST_GMAC_0, phy_addr, 0U, 0x8000U, 1U);
		/* Wait for reset done (bit15 clears) */
		do {
			(void) Gmac_Ip_MDIORead(INST_GMAC_0, phy_addr, 0U,
					&register_value_0, 1U);
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

	int main(void) {

		/* Put MAC into RMII mode using your existing DCM write (same as your UDP sample) */
		IP_DCM_GPR->DCMRWF1 = (IP_DCM_GPR->DCMRWF1
				& ~DCM_GPR_DCMRWF1_MAC_CONF_SEL_MASK)
				| DCM_GPR_DCMRWF1_MAC_CONF_SEL(2U);

		Siul2_Port_Ip_Init(
		NUM_OF_CONFIGURED_PINS_PortContainer_0_BOARD_InitPeripherals,
				g_pin_mux_InitConfigArr_PortContainer_0_BOARD_InitPeripherals);

		/* Clocks, Pins, GMAC init via RTD */
		Clock_Ip_Init(&Clock_Ip_aClockConfig[0]);

		DevAssert(
				IntCtrl_Ip_Init(&IntCtrlConfig_0) == INTCTRL_IP_STATUS_SUCCESS);

		DevAssert(
				Gmac_Ip_Init(INST_GMAC_0, &Gmac_0_ConfigPB)
						== GMAC_STATUS_SUCCESS);

		/* PHY up */
		Eth_Phy_Init();

		for (;;) {
			if (exit_code != 0) {
				break;
			}
		}
		return exit_code;
	}

	/** @} */
