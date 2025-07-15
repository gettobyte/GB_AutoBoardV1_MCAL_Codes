/*==================================================================================================
*   Project              : RTD AUTOSAR 4.4
*   Platform             : CORTEXM
*   Peripheral           : ADC_SAR
*   Dependencies         : none
*
*   Autosar Version      : 4.4.0
*   Autosar Revision     : ASR_REL_4_4_REV_0000
*   Autosar Conf.Variant :
*   SW Version           : 2.0.0
*   Build Version        : S32K3_RTD_2_0_0_D2203_ASR_REL_4_4_REV_0000_20220331
*
*   (c) Copyright 2020 - 2022 NXP Semiconductors
*   All Rights Reserved.
*
*   NXP Confidential. This software is owned or controlled by NXP and may only be
*   used strictly in accordance with the applicable license terms. By expressly
*   accepting such terms or by downloading, installing, activating and/or otherwise
*   using the software, you are agreeing that you have read, and that you agree to
*   comply with and are bound by, such license terms. If you do not agree to be
*   bound by the applicable license terms, then you may not retain, install,
*   activate or otherwise use the software.
==================================================================================================*/

/**
*   @file
*
*   @addtogroup bctu_ip_driver_config Bctu IPL Configuration
*   @{
*/

#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Bctu_Ip_VS_0_PBcfg.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/

#define BCTU_IP_VENDOR_ID_VS_0_PBCFG_C                      43
#define BCTU_IP_AR_RELEASE_MAJOR_VERSION_VS_0_PBCFG_C       4
#define BCTU_IP_AR_RELEASE_MINOR_VERSION_VS_0_PBCFG_C       4
#define BCTU_IP_AR_RELEASE_REVISION_VERSION_VS_0_PBCFG_C    0
#define BCTU_IP_SW_MAJOR_VERSION_VS_0_PBCFG_C               2
#define BCTU_IP_SW_MINOR_VERSION_VS_0_PBCFG_C               0
#define BCTU_IP_SW_PATCH_VERSION_VS_0_PBCFG_C               0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if Bctu_Ip_VS_0_PBcfg.c file and Bctu_Ip_VS_0_PBcfg.h file are of the same vendor */
#if (BCTU_IP_VENDOR_ID_VS_0_PBCFG_C != BCTU_IP_VENDOR_ID_VS_0_PBCFG)
    #error "Bctu_Ip_VS_0_PBcfg.c and Bctu_Ip_VS_0_PBcfg.h have different vendor ids"
#endif

/* Check if Bctu_Ip_VS_0_PBcfg.c file and Bctu_Ip_VS_0_PBcfg.h file are of the same Autosar version */
#if ((BCTU_IP_AR_RELEASE_MAJOR_VERSION_VS_0_PBCFG_C != BCTU_IP_AR_RELEASE_MAJOR_VERSION_VS_0_PBCFG) || \
     (BCTU_IP_AR_RELEASE_MINOR_VERSION_VS_0_PBCFG_C != BCTU_IP_AR_RELEASE_MINOR_VERSION_VS_0_PBCFG) || \
     (BCTU_IP_AR_RELEASE_REVISION_VERSION_VS_0_PBCFG_C != BCTU_IP_AR_RELEASE_REVISION_VERSION_VS_0_PBCFG) \
    )
    #error "AutoSar Version Numbers of Bctu_Ip_VS_0_PBcfg.c and Bctu_Ip_VS_0_PBcfg.h are different"
#endif

/* Check if Bctu_Ip_VS_0_PBcfg.c file and Bctu_Ip_VS_0_PBcfg.h file are of the same Software version */
#if ((BCTU_IP_SW_MAJOR_VERSION_VS_0_PBCFG_C != BCTU_IP_SW_MAJOR_VERSION_VS_0_PBCFG) || \
     (BCTU_IP_SW_MINOR_VERSION_VS_0_PBCFG_C != BCTU_IP_SW_MINOR_VERSION_VS_0_PBCFG) || \
     (BCTU_IP_SW_PATCH_VERSION_VS_0_PBCFG_C != BCTU_IP_SW_PATCH_VERSION_VS_0_PBCFG) \
    )
  #error "Software Version Numbers of Bctu_Ip_VS_0_PBcfg.c and Bctu_Ip_VS_0_PBcfg.h are different"
#endif

/*==================================================================================================
*                                 GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/

/*==================================================================================================
*                                      LOCAL CONSTANTS
==================================================================================================*/

#define ADC_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Adc_MemMap.h"

static const Bctu_Ip_TrigConfigType BctuHwUnit_0_aTrigConfigPB_VS_0[2] =
{
    {
        0U, /* TrigIndex - BCTU_EMIOS_0_0 */
        (boolean)FALSE, /* LoopEn */
        BCTU_IP_DATA_DEST_FIFO2, /* DataDest */
        (boolean)TRUE, /* HwTriggersEn */
        BCTU_IP_TRIG_TYPE_LIST, /* TrigType */
        2U, /* AdcTargetMask */
        0U /* AdcChanOrListStart - Start index in BCTU LIST, because trigger is configured in LIST mode */
    },
    {
        8U, /* TrigIndex - BCTU_EMIOS_0_8 */
        (boolean)FALSE, /* LoopEn */
        BCTU_IP_DATA_DEST_FIFO1, /* DataDest */
        (boolean)TRUE, /* HwTriggersEn */
        BCTU_IP_TRIG_TYPE_LIST, /* TrigType */
        4U, /* AdcTargetMask */
        1U /* AdcChanOrListStart - Start index in BCTU LIST, because trigger is configured in LIST mode */
    }
};

static const Bctu_Ip_ListItemConfigType BctuHwUnit_0_aItemConfigPB_VS_0[3] =
{
    { /* Command List Index: 0 - BctuListItems_0 */
        (boolean)FALSE, /* NextChanWaitOnTrig */
        5U, /* AdcChanIndex */
        (boolean)FALSE /* LastChanInList */
    },
    { /* Command List Index: 1 - BctuListItems_1 */
        (boolean)FALSE, /* NextChanWaitOnTrig */
        3U, /* AdcChanIndex */
        (boolean)FALSE /* LastChanInList */
    },
    { /* Command List Index: 2 - BctuListItems_2 */
        (boolean)FALSE, /* NextChanWaitOnTrig */
        37U, /* AdcChanIndex */
        (boolean)TRUE /* LastChanInList */
    }
};

static const Bctu_Ip_FifoConfigType BctuHwUnit_0_aFifoConfigPB_VS_0[2] =
{
    /* Configuration for FIFO_1 */
    {
        0U, /* FifoIndex */
        1U, /* WatermarkValue */
        (boolean)FALSE, /* FifoDmaEnable */
        0U, /* FifoDmaChannel */
        NULL_PTR, /* UserFifoBuffer */
        (boolean)TRUE, /* bEnNotif */
        Fifo1Watermark, /* WatermarkNotification */
        NULL_PTR, /* UnderrunNotification */
        NULL_PTR /* OverrunNotification */
    },
    /* Configuration for FIFO_2 */
    {
        1U, /* FifoIndex */
        0U, /* WatermarkValue */
        (boolean)FALSE, /* FifoDmaEnable */
        0U, /* FifoDmaChannel */
        NULL_PTR, /* UserFifoBuffer */
        (boolean)TRUE, /* bEnNotif */
        Fifo2Watermark, /* WatermarkNotification */
        NULL_PTR, /* UnderrunNotification */
        NULL_PTR /* OverrunNotification */
    }
};

#define ADC_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Adc_MemMap.h"

/*==================================================================================================
*                                      LOCAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                      GLOBAL VARIABLES
==================================================================================================*/

#define ADC_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Adc_MemMap.h"

const Bctu_Ip_ConfigType BctuHwUnit_0_VS_0 =
{
    (boolean)FALSE, /* LowPowerModeEn */
    (boolean)TRUE, /* GlobalHwTriggersEn */
    0U, /* NewDataDmaEnMask */
    Check, /* TriggerNotification */
    { { NULL_PTR, NULL_PTR, NULL_PTR }, { NULL_PTR, NULL_PTR, NULL_PTR }, { NULL_PTR, NULL_PTR, NULL_PTR } }, /* AdcNotifications */
    2U, /* NumTrigConfigs */
    BctuHwUnit_0_aTrigConfigPB_VS_0, /* TrigConfigs */
    3U, /* NumListItems */
    BctuHwUnit_0_aItemConfigPB_VS_0, /* ListItemConfigs */
    2U, /* NumFifoConfigs */
    BctuHwUnit_0_aFifoConfigPB_VS_0 /* FifoConfigs */
};

#define ADC_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Adc_MemMap.h"

/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/

/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/

#ifdef __cplusplus
}
#endif

/** @} */

