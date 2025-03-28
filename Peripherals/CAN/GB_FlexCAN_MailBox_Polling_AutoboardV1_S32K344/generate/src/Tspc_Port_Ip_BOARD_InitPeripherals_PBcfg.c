/*==================================================================================================
*   Project              : RTD AUTOSAR 4.4
*   Platform             : CORTEXM
*   Peripheral           : SIUL2
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
*   @file    Tspc_Port_Ip_BOARD_InitPeripherals_PBcfg.c
*
*   @addtogroup Port_CFG
*   @{
*/

#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
*                                          INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Tspc_Port_Ip.h"

/*==================================================================================================
*                                 SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define TSPC_PORT_IP_VENDOR_ID_BOARD_InitPeripherals_PBCFG_C                       43
#define TSPC_PORT_IP_AR_RELEASE_MAJOR_VERSION_BOARD_InitPeripherals_PBCFG_C        4
#define TSPC_PORT_IP_AR_RELEASE_MINOR_VERSION_BOARD_InitPeripherals_PBCFG_C        4
#define TSPC_PORT_IP_AR_RELEASE_REVISION_VERSION_BOARD_InitPeripherals_PBCFG_C     0
#define TSPC_PORT_IP_SW_MAJOR_VERSION_BOARD_InitPeripherals_PBCFG_C                2
#define TSPC_PORT_IP_SW_MINOR_VERSION_BOARD_InitPeripherals_PBCFG_C                0
#define TSPC_PORT_IP_SW_PATCH_VERSION_BOARD_InitPeripherals_PBCFG_C                0

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/
/* Check if Tspc_Port_Ip_BOARD_InitPeripherals_PBcfg.c and Tspc_Port_Ip.h are of the same vendor */
#if (TSPC_PORT_IP_VENDOR_ID_BOARD_InitPeripherals_PBCFG_C != TSPC_PORT_IP_VENDOR_ID_H)
    #error "Tspc_Port_Ip_BOARD_InitPeripherals_PBcfg.c and Tspc_Port_Ip.h have different vendor ids"
#endif
/* Check if Tspc_Port_Ip_BOARD_InitPeripherals_PBcfg.c and Tspc_Port_Ip.h are of the same Autosar version */
#if ((TSPC_PORT_IP_AR_RELEASE_MAJOR_VERSION_BOARD_InitPeripherals_PBCFG_C    != TSPC_PORT_IP_AR_RELEASE_MAJOR_VERSION_H) || \
     (TSPC_PORT_IP_AR_RELEASE_MINOR_VERSION_BOARD_InitPeripherals_PBCFG_C    != TSPC_PORT_IP_AR_RELEASE_MINOR_VERSION_H) || \
     (TSPC_PORT_IP_AR_RELEASE_REVISION_VERSION_BOARD_InitPeripherals_PBCFG_C != TSPC_PORT_IP_AR_RELEASE_REVISION_VERSION_H) \
    )
    #error "AutoSar Version Numbers of Tspc_Port_Ip_BOARD_InitPeripherals_PBcfg.c and Tspc_Port_Ip.h are different"
#endif

/* Check if Tspc_Port_Ip_BOARD_InitPeripherals_PBcfg.c and Tspc_Port_Ip.h are of the same software version */
#if ((TSPC_PORT_IP_SW_MAJOR_VERSION_BOARD_InitPeripherals_PBCFG_C != TSPC_PORT_IP_SW_MAJOR_VERSION_H) || \
     (TSPC_PORT_IP_SW_MINOR_VERSION_BOARD_InitPeripherals_PBCFG_C != TSPC_PORT_IP_SW_MINOR_VERSION_H) || \
     (TSPC_PORT_IP_SW_PATCH_VERSION_BOARD_InitPeripherals_PBCFG_C != TSPC_PORT_IP_SW_PATCH_VERSION_H)    \
    )
    #error "Software Version Numbers of Tspc_Port_Ip_BOARD_InitPeripherals_PBcfg.c and Tspc_Port_Ip.h are different"
#endif

/*==================================================================================================
*                           LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/


/*==================================================================================================
*                                          LOCAL MACROS
==================================================================================================*/


/*==================================================================================================
*                                         LOCAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                         LOCAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                        GLOBAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                        GLOBAL VARIABLES
==================================================================================================*/
#define PORT_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Port_MemMap.h"

const Tspc_Port_Ip_ObeGroupConfig aTspc_InitConfigArr_BOARD_InitPeripherals[NUM_OF_OBE_GROUP_CONFIG] = 
{
    {
        .obeGroupSelect = 0,
        .obeGroupIndex  = 65535
    },
    {
        .obeGroupSelect = 0,
        .obeGroupIndex  = 65535
    },
    {
        .obeGroupSelect = 0,
        .obeGroupIndex  = 65535
    },
    {
        .obeGroupSelect = 0,
        .obeGroupIndex  = 65535
    }
};
#define PORT_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Port_MemMap.h"

/*==================================================================================================
*                                        GLOBAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                        GLOBAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                    LOCAL FUNCTION PROTOTYPES
==================================================================================================*/

/*==================================================================================================
*                                         LOCAL FUNCTIONS
==================================================================================================*/

/*==================================================================================================
*                                        GLOBAL FUNCTIONS
==================================================================================================*/

#ifdef __cplusplus
}
#endif

/** @} */

