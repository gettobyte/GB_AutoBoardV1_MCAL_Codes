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
#include "string.h"

volatile int exit_code = 0;

/* ===== PHY discovery scratch ===== */
static uint16 phy_addr; /* discovered PHY address (0..31) */
static uint16 register_value_0;
static uint16 register_value_1;

Gmac_Ip_BufferType RxBuffer = { 0 };
Gmac_Ip_RxInfoType RxInfo = { 0 };
Gmac_Ip_StatusType Status;

/* User includes */

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
	uint16 payload[1536]; /* A buffer for the payload data. */
	uint16 payloadLen; /* The actual length of the payload. */
} EthFrame_t;

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

	DevAssert(IntCtrl_Ip_Init(&IntCtrlConfig_0) == INTCTRL_IP_STATUS_SUCCESS);

	DevAssert(
			Gmac_Ip_Init(INST_GMAC_0, &Gmac_0_ConfigPB) == GMAC_STATUS_SUCCESS);

	/* PHY up */
	Eth_Phy_Init();

	for (;;) {
		if (exit_code != 0) {
			break;
		}
	}
	return exit_code;
}

void TX_Callback(void) {

}

void RX_Callback(void) {

	do {
		Status = Gmac_Ip_ReadFrame(INST_GMAC_0, 0U, &RxBuffer, &RxInfo);
	} while (Status == GMAC_STATUS_RX_QUEUE_EMPTY);

	EthFrame_t rxFrame;

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
//		if (rxFrame.etherType == 0xBB80U) {
//			correct_frame = true;
//		}

		Gmac_Ip_ProvideRxBuff(INST_GMAC_0, 0U, &RxBuffer);

	}

}

/** @} */
