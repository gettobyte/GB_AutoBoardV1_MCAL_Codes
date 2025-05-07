/*==================================================================================================
*   Project              : RTD AUTOSAR 4.7
*   Platform             : CORTEXM
*   Peripheral           : ADC_SAR
*   Dependencies         : none
*
*   Autosar Version      : 4.7.0
*   Autosar Revision     : ASR_REL_4_7_REV_0000
*   Autosar Conf.Variant :
*   SW Version           : 4.0.0
*   Build Version        : S32K3_RTD_4_0_0_P20_D2403_ASR_REL_4_7_REV_0000_20240315
*
*   Copyright 2020 - 2024 NXP
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
#define BCTU_IP_AR_RELEASE_MINOR_VERSION_VS_0_PBCFG_C       7
#define BCTU_IP_AR_RELEASE_REVISION_VERSION_VS_0_PBCFG_C    0
#define BCTU_IP_SW_MAJOR_VERSION_VS_0_PBCFG_C               4
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
        BCTU_IP_DATA_DEST_FIFO1, /* DataDest */
        (boolean)FALSE, /* HwTriggersEn */
        BCTU_IP_TRIG_TYPE_SINGLE, /* TrigType */
        1U, /* AdcTargetMask */
        4U /* AdcChanOrListStart - Adc channel ID, because trigger is configured in single mode */
    },
    {
        1U, /* TrigIndex - BCTU_EMIOS_0_1 */
        (boolean)FALSE, /* LoopEn */
        BCTU_IP_DATA_DEST_FIFO1, /* DataDest */
        (boolean)FALSE, /* HwTriggersEn */
        BCTU_IP_TRIG_TYPE_SINGLE, /* TrigType */
        1U, /* AdcTargetMask */
        49U /* AdcChanOrListStart - Adc channel ID, because trigger is configured in single mode */
    }
};

static const Bctu_Ip_FifoConfigType BctuHwUnit_0_aFifoConfigPB_VS_0[1] =
{
    /* Configuration for FIFO_1 */
    {
        0U, /* FifoIndex */
        0U, /* WatermarkValue */
        (boolean)FALSE, /* FifoDmaEnable */
        0U, /* FifoDmaChannel */
        NULL_PTR, /* UserFifoBuffer */
        (boolean)TRUE, /* bEnNotif */
        BctuWatermarkNotif, /* WatermarkNotification */
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
    NULL_PTR, /* TriggerNotification */
    { { NULL_PTR, NULL_PTR, NULL_PTR }, { NULL_PTR, NULL_PTR, NULL_PTR }, { NULL_PTR, NULL_PTR, NULL_PTR } }, /* AdcNotifications */
    2U, /* NumTrigConfigs */
    BctuHwUnit_0_aTrigConfigPB_VS_0, /* TrigConfigs */
    0U, /* NumListItems */
    NULL_PTR, /* ListItemConfigs */
    1U, /* NumFifoConfigs */
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

