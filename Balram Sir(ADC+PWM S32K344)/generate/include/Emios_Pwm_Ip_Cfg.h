/*==================================================================================================
*   Project              : RTD AUTOSAR 4.4
*   Platform             : CORTEXM
*   Peripheral           : Emios Flexio
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

#ifndef EMIOS_PWM_IP_CFG_H
#define EMIOS_PWM_IP_CFG_H

/**
*   @file       Emios_Pwm_Ip_Cfg.h
*
*   @addtogroup emios_pwm_ip Emios Pwm IPL
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
/* Standard Types */
#include "StandardTypes.h"

/* DevAssert implementation */
#include "Devassert.h"

/* Register definitions */
#include "S32K344_EMIOS.h"

/* Include all variants header files. */
#include "Emios_Pwm_Ip_VS_0_PBcfg.h"

/*==================================================================================================
*                                 SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define EMIOS_PWM_IP_CFG_VENDOR_ID                    43
#define EMIOS_PWM_IP_CFG_MODULE_ID                    121
#define EMIOS_PWM_IP_CFG_AR_RELEASE_MAJOR_VERSION     4
#define EMIOS_PWM_IP_CFG_AR_RELEASE_MINOR_VERSION     4
#define EMIOS_PWM_IP_CFG_AR_RELEASE_REVISION_VERSION  0
#define EMIOS_PWM_IP_CFG_SW_MAJOR_VERSION             2
#define EMIOS_PWM_IP_CFG_SW_MINOR_VERSION             0
#define EMIOS_PWM_IP_CFG_SW_PATCH_VERSION             0

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if header file and StandardTypes.h are of the same AUTOSAR version */
    #if ((EMIOS_PWM_IP_CFG_AR_RELEASE_MAJOR_VERSION != STD_AR_RELEASE_MAJOR_VERSION) || \
         (EMIOS_PWM_IP_CFG_AR_RELEASE_MINOR_VERSION != STD_AR_RELEASE_MINOR_VERSION))
        #error "AUTOSAR Version Numbers of Emios_Pwm_Ip_Cfg.h and StandardTypes.h are different"
    #endif

    /* Check if header file and Devassert.h are of the same AUTOSAR version */
    #if ((EMIOS_PWM_IP_CFG_AR_RELEASE_MAJOR_VERSION != DEVASSERT_AR_RELEASE_MAJOR_VERSION) || \
         (EMIOS_PWM_IP_CFG_AR_RELEASE_MINOR_VERSION != DEVASSERT_AR_RELEASE_MINOR_VERSION))
        #error "AUTOSAR Version Numbers of Emios_Pwm_Ip_Cfg.h and Devassert.h are different"
    #endif
#endif


/*==================================================================================================
*                                            CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/
/** @brief      Switch to enable the development error detection. */
#define EMIOS_PWM_IP_DEV_ERROR_DETECT           (STD_OFF)

/** @brief      The number of Emios instances available on platform */
#define EMIOS_PWM_IP_INSTANCE_COUNT                (eMIOS_INSTANCE_COUNT)
/** @brief      The number of channels available on each Emios instance */
#define EMIOS_PWM_IP_CHANNEL_COUNT                 (eMIOS_CH_UC_UC_COUNT)

/** @brief      The number of PWM modes implemented in hardware */
#define EMIOS_PWM_IP_MODES                         (4U)
/** @brief      Mapping between available channels and the PWM mode supported by each of them */
#define EMIOS_PWM_IP_CHANNEL_MODES                 {\
                                                    {0x00C101FFUL, 0x000000FEUL, 0x00FFFFFFUL, 0x00FFFFFFUL},\
                                                    {0x00C10101UL, 0x00000000UL, 0x00FFFFFFUL, 0x00FFFFFFUL},\
                                                    {0x00C10101UL, 0x00000000UL, 0x00FFFFFFUL, 0x00FFFFFFUL},\
                                                }
/** @brief Min counter value for PWM modes */
#define EMIOS_PWM_IP_MIN_CNT_VAL                   (0x0001UL)
/** @brief Max counter value for PWM modes */
#define EMIOS_PWM_IP_MAX_CNT_VAL                   (0xFFFFUL)

/** @brief      Counter bus channel number */
#define EMIOS_PWM_IP_COUNTER_BUS_A                 (23U)
#define EMIOS_PWM_IP_COUNTER_BUS_BCDE              (248U)
#define EMIOS_PWM_IP_COUNTER_BUS_F                 (22U)

#define EMIOS_PWM_IP_INITIAL_MODES        \
{\
    {\
        EMIOS_PWM_IP_MODE_NODEFINE,\
        EMIOS_PWM_IP_MODE_NODEFINE,\
        EMIOS_PWM_IP_MODE_NODEFINE,\
        EMIOS_PWM_IP_MODE_NODEFINE,\
        EMIOS_PWM_IP_MODE_NODEFINE,\
        EMIOS_PWM_IP_MODE_NODEFINE,\
        EMIOS_PWM_IP_MODE_NODEFINE,\
        EMIOS_PWM_IP_MODE_NODEFINE,\
        EMIOS_PWM_IP_MODE_NODEFINE,\
        EMIOS_PWM_IP_MODE_NODEFINE,\
        EMIOS_PWM_IP_MODE_NODEFINE,\
        EMIOS_PWM_IP_MODE_NODEFINE,\
        EMIOS_PWM_IP_MODE_NODEFINE,\
        EMIOS_PWM_IP_MODE_NODEFINE,\
        EMIOS_PWM_IP_MODE_NODEFINE,\
        EMIOS_PWM_IP_MODE_NODEFINE,\
        EMIOS_PWM_IP_MODE_NODEFINE,\
        EMIOS_PWM_IP_MODE_NODEFINE,\
        EMIOS_PWM_IP_MODE_NODEFINE,\
        EMIOS_PWM_IP_MODE_NODEFINE,\
        EMIOS_PWM_IP_MODE_NODEFINE,\
        EMIOS_PWM_IP_MODE_NODEFINE,\
        EMIOS_PWM_IP_MODE_NODEFINE,\
        EMIOS_PWM_IP_MODE_NODEFINE\
    },\
    {\
        EMIOS_PWM_IP_MODE_NODEFINE,\
        EMIOS_PWM_IP_MODE_NODEFINE,\
        EMIOS_PWM_IP_MODE_NODEFINE,\
        EMIOS_PWM_IP_MODE_NODEFINE,\
        EMIOS_PWM_IP_MODE_NODEFINE,\
        EMIOS_PWM_IP_MODE_NODEFINE,\
        EMIOS_PWM_IP_MODE_NODEFINE,\
        EMIOS_PWM_IP_MODE_NODEFINE,\
        EMIOS_PWM_IP_MODE_NODEFINE,\
        EMIOS_PWM_IP_MODE_NODEFINE,\
        EMIOS_PWM_IP_MODE_NODEFINE,\
        EMIOS_PWM_IP_MODE_NODEFINE,\
        EMIOS_PWM_IP_MODE_NODEFINE,\
        EMIOS_PWM_IP_MODE_NODEFINE,\
        EMIOS_PWM_IP_MODE_NODEFINE,\
        EMIOS_PWM_IP_MODE_NODEFINE,\
        EMIOS_PWM_IP_MODE_NODEFINE,\
        EMIOS_PWM_IP_MODE_NODEFINE,\
        EMIOS_PWM_IP_MODE_NODEFINE,\
        EMIOS_PWM_IP_MODE_NODEFINE,\
        EMIOS_PWM_IP_MODE_NODEFINE,\
        EMIOS_PWM_IP_MODE_NODEFINE,\
        EMIOS_PWM_IP_MODE_NODEFINE,\
        EMIOS_PWM_IP_MODE_NODEFINE\
    },\
    {\
        EMIOS_PWM_IP_MODE_NODEFINE,\
        EMIOS_PWM_IP_MODE_NODEFINE,\
        EMIOS_PWM_IP_MODE_NODEFINE,\
        EMIOS_PWM_IP_MODE_NODEFINE,\
        EMIOS_PWM_IP_MODE_NODEFINE,\
        EMIOS_PWM_IP_MODE_NODEFINE,\
        EMIOS_PWM_IP_MODE_NODEFINE,\
        EMIOS_PWM_IP_MODE_NODEFINE,\
        EMIOS_PWM_IP_MODE_NODEFINE,\
        EMIOS_PWM_IP_MODE_NODEFINE,\
        EMIOS_PWM_IP_MODE_NODEFINE,\
        EMIOS_PWM_IP_MODE_NODEFINE,\
        EMIOS_PWM_IP_MODE_NODEFINE,\
        EMIOS_PWM_IP_MODE_NODEFINE,\
        EMIOS_PWM_IP_MODE_NODEFINE,\
        EMIOS_PWM_IP_MODE_NODEFINE,\
        EMIOS_PWM_IP_MODE_NODEFINE,\
        EMIOS_PWM_IP_MODE_NODEFINE,\
        EMIOS_PWM_IP_MODE_NODEFINE,\
        EMIOS_PWM_IP_MODE_NODEFINE,\
        EMIOS_PWM_IP_MODE_NODEFINE,\
        EMIOS_PWM_IP_MODE_NODEFINE,\
        EMIOS_PWM_IP_MODE_NODEFINE,\
        EMIOS_PWM_IP_MODE_NODEFINE\
    }\
}
/*==================================================================================================
*                                              ENUMS
==================================================================================================*/

/*==================================================================================================
*                                  STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/
/* Redefine eMIOS_Type from header file to comply with coding guidelines */
typedef eMIOS_Type Emios_Pwm_Ip_HwAddrType;

/*==================================================================================================
*                                  GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                       FUNCTION PROTOTYPES
==================================================================================================*/


#ifdef __cplusplus
}
#endif

/** @} */

#endif /* EMIOS_PWM_IP_CFG_H */

