/*
 * Copyright 2020-2022 NXP
 * All rights reserved.
 *
 * THIS SOFTWARE IS PROVIDED BY NXP "AS IS" AND ANY EXPRESSED OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
 * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
 * IN NO EVENT SHALL NXP OR ITS CONTRIBUTORS BE LIABLE FOR ANY DIRECT,
 * INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
 * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING
 * IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF
 * THE POSSIBILITY OF SUCH DAMAGE.
 */

/**
 * @page misra_violations MISRA-C:2012 violations
 *
 */

#include "S32K344.h"
#include "Pit_Ip.h"
#include "IntCtrl_Ip.h"
#include "device.h"
#include "Mcal.h"
#include "Clock_Ip.h"
#include "Siul2_Port_Ip.h"
#include "Gmac_Ip.h"
#include "Gmac_Ip_Irq.h"
#include "OsIf.h"

#ifdef SJA1105_CONFIG
#include "Spi.h"
#include "switch_init.h"
#endif /* SJA1105_CONFIG */

/* PIT instance used */
#define PIT_INST 0U
/* PIT Channel used - 0 */
#define CH_0 0U

#define CFG_PHY_CTRL_IDX        (0U)
#define ENABLE_PHY_LOOPBACK     (0U)   /* Set to 1 to enable PHY loopback*/
#define TJA1100_PHY_ID0         (0x0180U)
#define TJA1103_PHY_ID0         (0x01BU)
#define TJA1100_PHY_ID1         (0xDC41U)
#define TJA1101_PHY_ID1         (0xDD01U)
#define TJA1103_PHY_ID1         (0xB013U)

#define DP83848_PHY_ID0         (0x2000U)
#define DP83848_PHY_ID1         (0x5C90U)
#define TLK110_PHY_ID1          (0xA210U)

#define PHY_ID1                 DP83848_PHY_ID0
#define PHY_ID2                 DP83848_PHY_ID1

#define PHY_LED_ON              (1U)

extern ISR(PIT_0_ISR);

static void Eth_T_InitPhys(void)
{
    uint16 rmii_sel = 0;
    uint16 phy_reg_val0, phy_reg_val1;
    uint16 phy_addr;

    Gmac_Ip_EnableMDIO(CFG_PHY_CTRL_IDX, FALSE, 48000000U);

    /* Search for the PHY address */
    for (phy_addr = 0U; phy_addr < 32U; ++phy_addr)
    {
        Gmac_Ip_MDIORead(CFG_PHY_CTRL_IDX, phy_addr, 2U, &phy_reg_val0, 1U);
        Gmac_Ip_MDIORead(CFG_PHY_CTRL_IDX, phy_addr, 3U, &phy_reg_val1, 1U);

        /* check for PHY ID */
        if ((((phy_reg_val0 == TJA1100_PHY_ID0) || (phy_reg_val0 == TJA1103_PHY_ID0)) && ((phy_reg_val1 == TJA1100_PHY_ID1) || (phy_reg_val1 == TJA1101_PHY_ID1 || phy_reg_val1 == TJA1103_PHY_ID1))) ||
            ((phy_reg_val0 == DP83848_PHY_ID0) && ((phy_reg_val1 & 0xFFF0U) == DP83848_PHY_ID1 || (phy_reg_val1 & 0xFFF0U) == TLK110_PHY_ID1)))
        {
            break; /* found the PHY ID*/
        }
    }

    /* Reset the PHY */
    Gmac_Ip_MDIOWrite(CFG_PHY_CTRL_IDX, phy_addr, 0U, 0x8000U, 1U);

    /* Wait until the PHY is out of reset */
    while (Gmac_Ip_MDIORead(CFG_PHY_CTRL_IDX, phy_addr, 0U, &phy_reg_val0, 1U) & 0x8000U)
    { /* Busy Wait */
    }

    phy_reg_val0 |= (ENABLE_PHY_LOOPBACK << 14U);  /* Enable Loopback */
    phy_reg_val0 &= ~(1U << 12U); /* Disable AN */

    phy_reg_val0 |= (1U << 13U);  /* Speed_Select Lsb = 1 100Mbs */

    rmii_sel = 1;

    phy_reg_val0 |= (1U << 8U); /* Full-Duplex mode */

    /* Configure the PHY */
    if ((phy_reg_val1 & 0xFFF0U) == DP83848_PHY_ID1 || (phy_reg_val1 & 0xFFF0U) == TLK110_PHY_ID1)
    {
        phy_reg_val0 &= ~(1U << 12U); /* Enable auto-negotiation */
        phy_reg_val0 &= ~(1U << 9U); /* Enable auto-negotiation restart */
        Gmac_Ip_MDIOWrite(CFG_PHY_CTRL_IDX, phy_addr, 0U, phy_reg_val0, 1U);
        Gmac_Ip_MDIORead(CFG_PHY_CTRL_IDX, phy_addr, 0U, &phy_reg_val0, 1U);

        Gmac_Ip_MDIORead(CFG_PHY_CTRL_IDX, phy_addr, 0x17U, &phy_reg_val0, 1U);
        phy_reg_val0 |= rmii_sel << 5; // RMII Enable
        Gmac_Ip_MDIOWrite(CFG_PHY_CTRL_IDX, phy_addr, 0x17U, phy_reg_val0, 1U);
    }
    else
    {
        phy_reg_val0 &= ~(1U << 6U);  /* Speed_Select Msb = 0 100Mbs */
        Gmac_Ip_MDIOWrite(CFG_PHY_CTRL_IDX, phy_addr, 0U, phy_reg_val0, 1U);

        Gmac_Ip_MDIORead(CFG_PHY_CTRL_IDX, phy_addr, 0x11U, &phy_reg_val0, 1U);
        phy_reg_val0 = (phy_reg_val0 | 0x4); // PHY configuration register access enable
        Gmac_Ip_MDIOWrite(CFG_PHY_CTRL_IDX, phy_addr, 0x11U, phy_reg_val0, 1U);

        Gmac_Ip_MDIORead(CFG_PHY_CTRL_IDX, phy_addr, 0x12U, &phy_reg_val0, 1U);
        phy_reg_val0 = phy_reg_val0 & 0xFCF7;          // Mask to set MII_MODE bits 9:8 to 0 and set LED_EN bit 3
        phy_reg_val0 = phy_reg_val0 | (rmii_sel << 9) | (PHY_LED_ON << 3); // If RMII mode: [MII_MODE]-> 10b (RMII mode enabled, 50 MHz output on REF_CLK)
        Gmac_Ip_MDIOWrite(CFG_PHY_CTRL_IDX, phy_addr, 0x12U, phy_reg_val0, 1U);
    }
    /* Wait to establish link */
    do
    {
        if (phy_reg_val1 == TJA1103_PHY_ID1)
        {
            Gmac_Ip_MDIOReadMMD(CFG_PHY_CTRL_IDX, phy_addr, 30, 0x8102U, &phy_reg_val0, 1U);
        }
        else
        {
            Gmac_Ip_MDIORead(CFG_PHY_CTRL_IDX, phy_addr, 1U, &phy_reg_val0, 1U);
        }
    } while ((0U == (phy_reg_val0 & (1U << 2U))));
}


static void Eth_T_EnableIRQs(void)
{
    uint32 instance;
#if (defined(FEATURE_ETH_RX_IRQS) || defined(FEATURE_ETH_TX_IRQS))
    uint32 channel;
#endif /* FEATURE_ETH_RX_IRQS || FEATURE_ETH_TX_IRQS */

#ifdef FEATURE_ETH_COMMON_IRQS
    /*! @brief ETH common IRQ number for each instance. */
    const IRQn_Type ethCommonIrqId[FEATURE_ETH_NUM_INSTANCES] = FEATURE_ETH_COMMON_IRQS;
    /*! @brief ETH common IRQ handler for each instance. */
    void (*ethCommonIrqHandler[FEATURE_ETH_NUM_INSTANCES])(void) = FEATURE_GMAC_COMMON_IRQ_HDLRS;
#endif /* FEATURE_ETH_COMMON_IRQS */

#ifdef FEATURE_ETH_SAFETY_IRQS
    /*! @brief ETH safety IRQ number for each instance. */
    const IRQn_Type ethSafetyIrqId[FEATURE_ETH_NUM_INSTANCES] = FEATURE_ETH_SAFETY_IRQS;
    /*! @brief ETH safety IRQ handler for each instance. */
    void (*ethSafetyIrqHandler[FEATURE_ETH_NUM_INSTANCES])(void) = FEATURE_GMAC_SAFETY_IRQ_HDLRS;
#endif /* FEATURE_ETH_COMMON_IRQS */

#ifdef FEATURE_ETH_TX_IRQS
    /*! @brief ETH transmit IRQ number for each channel and each instance. */
    const IRQn_Type ethTxIrqId[FEATURE_ETH_NUM_INSTANCES][FEATURE_ETH_NUM_CHANNELS] = FEATURE_ETH_TX_IRQS;
    /*! @brief ETH transmit IRQ handler for each channel and each instance. */
    void (*ethTxIrqHandler[FEATURE_ETH_NUM_INSTANCES][FEATURE_ETH_NUM_CHANNELS])(void) = FEATURE_ETH_TX_IRQ_HDLRS;
#endif /* FEATURE_ETH_TX_IRQS */

#ifdef FEATURE_ETH_RX_IRQS
    /*! @brief ETH receive IRQ number for each channel and each instance. */
    const IRQn_Type ethRxIrqId[FEATURE_ETH_NUM_INSTANCES][FEATURE_ETH_NUM_CHANNELS] = FEATURE_ETH_RX_IRQS;
    /*! @brief ETH receive IRQ handler for each channel and each instance. */
    void (*ethRxIrqHandler[FEATURE_ETH_NUM_INSTANCES][FEATURE_ETH_NUM_CHANNELS])(void) = FEATURE_ETH_RX_IRQ_HLDRS;
#endif /* FEATURE_GMAC_RX_IRQS */

    /* Enable IRQs in a platform-specific way */
    for (instance = 0U; instance < FEATURE_GMAC_NUM_INSTANCES; ++instance)
    {
    #ifdef FEATURE_ETH_COMMON_IRQS
        ((volatile uint32*)S32_SCB->VTOR)[ethCommonIrqId[instance] + 16] = (uint32)ethCommonIrqHandler[instance];
        S32_NVIC->ISER[(uint32)(ethCommonIrqId[instance]) >> 5U] = (uint32)(1UL << ((uint32)(ethCommonIrqId[instance]) & (uint32)0x1FU));
    #endif /* FEATURE_ETH_COMMON_IRQS */

    #ifdef FEATURE_ETH_SAFETY_IRQS
        ((volatile uint32*)S32_SCB->VTOR)[ethSafetyIrqId[instance] + 16] = (uint32)ethSafetyIrqHandler[instance];
        S32_NVIC->ISER[(uint32)(ethSafetyIrqId[instance]) >> 5U] = (uint32)(1UL << ((uint32)(ethSafetyIrqId[instance]) & (uint32)0x1FU));
    #endif /* FEATURE_ETH_COMMON_IRQS */

    #ifdef FEATURE_ETH_RX_IRQS
        for (channel = 0U; channel < FEATURE_ETH_NUM_CHANNELS; ++channel)
        {
            ((volatile uint32*)S32_SCB->VTOR)[ethRxIrqId[instance][channel] + 16] = (uint32)ethRxIrqHandler[instance][channel];
            S32_NVIC->ISER[(uint32)(ethRxIrqId[instance][channel]) >> 5U] = (uint32)(1UL << ((uint32)(ethRxIrqId[instance][channel]) & (uint32)0x1FU));
        }
    #endif /* FEATURE_ETH_RX_IRQS */

    #ifdef FEATURE_ETH_TX_IRQS
        for (channel = 0U; channel < FEATURE_ETH_NUM_CHANNELS; ++channel)
        {
            ((volatile uint32*)S32_SCB->VTOR)[ethTxIrqId[instance][channel] + 16] = (uint32)ethTxIrqHandler[instance][channel];
            S32_NVIC->ISER[(uint32)(ethTxIrqId[instance][channel]) >> 5U] = (uint32)(1UL << ((uint32)(ethTxIrqId[instance][channel]) & (uint32)0x1FU));
        }
    #endif /* FEATURE_ETH_TX_IRQS */
    }
}

void device_init(void)
{
    uint16 PitPeriod;
    /* Set RMII configuration for EMAC in DCM module */
    IP_DCM_GPR->DCMRWF1 = (IP_DCM_GPR->DCMRWF1 & ~DCM_GPR_DCMRWF1_MAC_CONF_SEL_MASK) | DCM_GPR_DCMRWF1_MAC_CONF_SEL(2U);

    /* Initialize all pins using the Port driver */
    Siul2_Port_Ip_Init(NUM_OF_CONFIGURED_PINS_PortContainer_0_VS_0, g_pin_mux_InitConfigArr_PortContainer_0_VS_0);

    /* Initialize Clocks */
    Clock_Ip_Init(&Clock_Ip_aClockConfig[0U]);

    /* Install interrupt handlers for PIT and EMAC */
    IntCtrl_Ip_InstallHandler(PIT0_IRQn, PIT_0_ISR, NULL_PTR);
    IntCtrl_Ip_SetPriority(PIT0_IRQn, 5);
    IntCtrl_Ip_EnableIrq(PIT0_IRQn);

    IntCtrl_Ip_InstallHandler(EMAC_1_IRQn, GMAC0_CH_TX_IRQHandler, NULL_PTR);
    IntCtrl_Ip_SetPriority(EMAC_1_IRQn, 8);
    IntCtrl_Ip_EnableIrq(EMAC_1_IRQn);

    IntCtrl_Ip_InstallHandler(EMAC_2_IRQn, GMAC0_CH_RX_IRQHandler, NULL_PTR);
    IntCtrl_Ip_SetPriority(EMAC_2_IRQn, 7);
    IntCtrl_Ip_EnableIrq(EMAC_2_IRQn);

    IntCtrl_Ip_InstallHandler(EMAC_0_IRQn, GMAC0_Common_IRQHandler, NULL_PTR);
    IntCtrl_Ip_SetPriority(EMAC_0_IRQn, 6);
    IntCtrl_Ip_EnableIrq(EMAC_0_IRQn);

    Eth_T_EnableIRQs();

    /* Initialize Os Interface */
    OsIf_Init(NULL_PTR);

    /* Initialize PIT driver and start the timer */
    Pit_Ip_Init(PIT_INST, &PIT_0_InitConfig_PB);
    Pit_Ip_InitChannel(PIT_INST, PIT_0_CH_0);
    Pit_Ip_EnableChannelInterrupt(PIT_INST, CH_0);

    PitPeriod = Clock_Ip_GetClockFrequency(PIT0_CLK) / 1000;
    Pit_Ip_StartChannel(PIT_INST, CH_0, PitPeriod);

#ifndef USING_OS_FREERTOS
    OsIf_SetTimerFrequency(160000000U,  OSIF_USE_SYSTEM_TIMER);
#endif /* USING_OS_FREERTOS */

    /* Initialize and enable the GMAC module */
    Gmac_Ip_Init(INST_GMAC_0, &Gmac_0_ConfigPB);

    /* Initialize Ethernet Phy */
    Eth_T_InitPhys();

#ifdef SJA1105_CONFIG
    Spi_Init()
    Switch_Init();
#endif /* SJA1105_CONFIG */
}
