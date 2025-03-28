/*==================================================================================================
* Project : RTD AUTOSAR 4.4
* Platform : CORTEXM
* Peripheral : SIUL2
* Dependencies : none
*
* Autosar Version : 4.4.0
* Autosar Revision : ASR_REL_4_4_REV_0000
* Autosar Conf.Variant :
* SW Version : 2.0.0
* Build Version : S32K3_RTD_2_0_0_D2203_ASR_REL_4_4_REV_0000_20220331
*
* (c) Copyright 2020 - 2022 NXP Semiconductors
* All Rights Reserved.
*
* NXP Confidential. This software is owned or controlled by NXP and may only be
* used strictly in accordance with the applicable license terms. By expressly
* accepting such terms or by downloading, installing, activating and/or otherwise
* using the software, you are agreeing that you have read, and that you agree to
* comply with and are bound by, such license terms. If you do not agree to be
* bound by the applicable license terms, then you may not retain, install,
* activate or otherwise use the software.
==================================================================================================*/

#ifndef PORT_H
#define PORT_H

/**
* @file Port'.h
*
* @implements Port.h_Artifact
* @brief Autosar Port driver header file
* @details Port driver header file containg exported functions and macros
*
* @defgroup Port_HLD Port HLD
* @{
*/

#ifdef __cplusplus
extern "C" {
#endif

/*=================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
=================================================================================================*/
#include "StandardTypes.h"
#include "Port_Cfg.h"
#include "Port_Ipw.h"
#include "Mcal.h"

/*=================================================================================================
*                              SOURCE FILE VERSION INFORMATION
=================================================================================================*/
/**
* @brief Parameters that shall be published within the Port driver header file and also in the
*        module's description file
*/
#define PORT_VENDOR_ID                    43
#define PORT_MODULE_ID                    124
#define PORT_AR_RELEASE_MAJOR_VERSION     4
#define PORT_AR_RELEASE_MINOR_VERSION     4
#define PORT_AR_RELEASE_REVISION_VERSION  0
#define PORT_SW_MAJOR_VERSION             2
#define PORT_SW_MINOR_VERSION             0
#define PORT_SW_PATCH_VERSION             0

/*=================================================================================================
*                                     FILE VERSION CHECKS
=================================================================================================*/
/* Check if the files Port.h and Port_Cfg.h are of the same vendor */
#if (PORT_VENDOR_ID != PORT_CFG_VENDOR_ID_H)
    #error "Port.h and Port_Cfg.h have different vendor ids"
#endif
/* Check if the files Port.h and Port_Cfg.h are of the same Autosar version */
#if ((PORT_AR_RELEASE_MAJOR_VERSION != PORT_CFG_AR_RELEASE_MAJOR_VERSION_H)     || \
     (PORT_AR_RELEASE_MINOR_VERSION != PORT_CFG_AR_RELEASE_MINOR_VERSION_H)     || \
     (PORT_AR_RELEASE_REVISION_VERSION != PORT_CFG_AR_RELEASE_REVISION_VERSION_H)  \
    )
     #error "AutoSar Version Numbers of Port.h and Port_Cfg.h are different"
#endif
/* Check if the files Port.h and Port_Cfg.h are of the same software version */
#if ((PORT_SW_MAJOR_VERSION != PORT_CFG_SW_MAJOR_VERSION_H) || \
     (PORT_SW_MINOR_VERSION != PORT_CFG_SW_MINOR_VERSION_H) || \
     (PORT_SW_PATCH_VERSION != PORT_CFG_SW_PATCH_VERSION_H)    \
    )
  #error "Software Version Numbers of Port.h and Port_Cfg.h are different"
#endif

/* Check if the files Port.h and Port_Ipw.h are of the same vendor */
#if (PORT_VENDOR_ID != PORT_VENDOR_ID_IPW_H)
    #error "Port.h and Port_Ipw.h have different vendor ids"
#endif
/* Check if the files Port.h and Port_Ipw.h are of the same Autosar version */
#if ((PORT_AR_RELEASE_MAJOR_VERSION    != PORT_AR_RELEASE_MAJOR_VERSION_IPW_H) || \
     (PORT_AR_RELEASE_MINOR_VERSION    != PORT_AR_RELEASE_MINOR_VERSION_IPW_H) || \
     (PORT_AR_RELEASE_REVISION_VERSION != PORT_AR_RELEASE_REVISION_VERSION_IPW_H) \
    )
    #error "AutoSar Version Numbers of Port.h and Port_Ipw.h are different"
#endif
/* Check if the files Port.h and Port_Ipw.h are of the same Software version */
#if ((PORT_SW_MAJOR_VERSION != PORT_SW_MAJOR_VERSION_IPW_H) || \
     (PORT_SW_MINOR_VERSION != PORT_SW_MINOR_VERSION_IPW_H) || \
     (PORT_SW_PATCH_VERSION != PORT_SW_PATCH_VERSION_IPW_H)    \
    )
    #error "Software Version Numbers of Port.h and Port_Ipw.h are different"
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if the files Port.h and StandardTypes.h are of the same version */
   #if ((PORT_AR_RELEASE_MAJOR_VERSION != STD_AR_RELEASE_MAJOR_VERSION) || \
        (PORT_AR_RELEASE_MINOR_VERSION != STD_AR_RELEASE_MINOR_VERSION)    \
       )
       #error "AutoSar Version Numbers of Port.h and StandardTypes.h are different"
   #endif
    /* Check if the files Port.h and Mcal.h are of the same version */
   #if ((PORT_AR_RELEASE_MAJOR_VERSION != MCAL_AR_RELEASE_MAJOR_VERSION) || \
        (PORT_AR_RELEASE_MINOR_VERSION != MCAL_AR_RELEASE_MINOR_VERSION)    \
       )
       #error "AutoSar Version Numbers of Port.h and Mcal.h are different"
   #endif
#endif
/*=================================================================================================
*                                          CONSTANTS
=================================================================================================*/
/**
* @brief          The PORT module is not properly configured
*
* @api
*/
#define PORT_E_PARAM_CONFIG                      ((uint8)0xF0)

/* Instance IDs */
/**
* @brief   Instance ID of port driver.
*
*/
#define PORT_INSTANCE_ID                ((uint8)0x0)

/* Service IDs */
/*
* @brief   Service ID of port driver.
*/

/**
* @brief   API service ID for PORT Init function.
* @details Parameters used when raising an error/exception.
*
* @api
*
*/
#define PORT_INIT_ID                    ((uint8)0x00)

/**
* @brief   API service ID for PORT set pin direction function.
* @details Parameters used when raising an error/exception.
*
* @api
*
*/
#define PORT_SETPINDIRECTION_ID         ((uint8)0x01)
/**
* @brief   API service ID for PORT refresh pin direction function.
* @details Parameters used when raising an error/exception.
*
* @api
*
*/
#define PORT_REFRESHPINDIRECTION_ID     ((uint8)0x02)

/**
* @brief   API service ID for PORT get version info function.
* @details Parameters used when raising an error/exception.
*
* @api
*
*/
#define PORT_GETVERSIONINFO_ID          ((uint8)0x03)

/**
* @brief   API service ID for PORT set pin mode.
* @details Parameters used when raising an error/exception.
*
* @api
*
*/
#define PORT_SETPINMODE_ID              ((uint8)0x04)

/**
* @brief   API service ID for PORT set as unused pin.
* @details Parameters used when raising an error/exception.
*/
#define PORT_SETASUNUSEDPIN_ID              ((uint8)0x05)

/**
* @brief   API service ID for PORT set as used pin.
* @details Parameters used when raising an error/exception.
*/
#define PORT_SETASUSEDPIN_ID                ((uint8)0x06)

/**
* @brief   API service ID for PORT reset pin mode.
* @details Parameters used when raising an error/exception.
*
* @api
*
*/
#define PORT_RESETPINMODE_ID                ((uint8)0x07)

#ifdef PORT_SET_2_PINS_DIRECTION_API
#if (STD_ON == PORT_SET_2_PINS_DIRECTION_API)
/**
* @brief   API service ID for PORT set 2 pins direction function.
* @details Parameters used when raising an error/exception.
*
* @api
*
*/
#define PORT_SET2PINSDIRECTION_ID       ((uint8)0x08)
#endif /* (STD_ON == PORT_SET_2_PINS_DIRECTION_API) */
#endif

/* Errors IDs */
/**
* @brief   Error ID of port driver.
* @details The following errors and exception are detectable by the PORT driver
*          if development error detection is enabled.
*
*/

/**
* @brief   Invalid Port Pin ID requested.
* @details Det Error value, returned by Port_SetPinDirection and Port_PinMode
*          if an wrong PortPin ID is passed.
*
* @implements Port_ErrorCodes_define
*/
 #define PORT_E_PARAM_PIN                ((uint8)0x0A)

/**
* @brief   Port Pin Direction not configured as changeable.
* @details Det Error value, returned by Port_SetPinDirection
*          if the passed PortPin have unchangeable direction.
*
* @implements Port_ErrorCodes_define
*/
#define PORT_E_DIRECTION_UNCHANGEABLE   ((uint8)0x0B)

/**
* @brief   API Port_Init() service called with wrong parameter.
* @details Det Error value, returned by Port_Init function
*          if Port_Init is called with wrong parameter.
*
* @implements Port_ErrorCodes_define
* @implements Port_InitFailed_Object
*/
#define PORT_E_INIT_FAILED              ((uint8)0x0C)

/**
* @brief   API Port_SetPinMode() service called when mode is invalid.
* @details Det Error value, returned by Port_SetPinMode function
*          if the passed PortPinMode is invalid.
*
* @implements Port_ErrorCodes_define
*/
#define PORT_E_PARAM_INVALID_MODE       ((uint8)0x0D)

/**
* @brief   API Port_SetPinMode() service called when mode is unchangeable.
* @details Det Error value, returned by Port_SetPinMode function
*          if the passed PortPin have a unchangeable Mode.
*
* @implements Port_ErrorCodes_define
*/
#define PORT_E_MODE_UNCHANGEABLE        ((uint8)0x0E)

/**
* @brief   API service called without module initialization.
* @details Det Error value, returned by a function if API service called
*          prior to module initialization.
*
* @implements Port_ErrorCodes_define
*/
#define PORT_E_UNINIT                   ((uint8)0x0F)

/**
* @brief   API service called with NULL Pointer Parameter.
* @details Det Error value, returned by Port_GetVersionInfo function
*          if API is called with NULL Pointer Parameter.
*
* @implements Port_ErrorCodes_define
*/
#define PORT_E_PARAM_POINTER            ((uint8)0x10)

/*=================================================================================================
*                                      DEFINES AND MACROS
=================================================================================================*/
#if (STD_ON == PORT_MULTICORE_ENABLED)
    #define Port_GetCoreID()            OsIf_GetCoreID()
#else
    #define Port_GetCoreID()            ((uint32)0UL)
#endif
/*=================================================================================================
*                                              ENUMS
=================================================================================================*/

/*=================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
=================================================================================================*/

/*=================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
=================================================================================================*/

#define PORT_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Port_MemMap.h"

PORT_CONFIG_EXT

#define PORT_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Port_MemMap.h"

/*=================================================================================================
*                                     FUNCTION PROTOTYPES
=================================================================================================*/
/* Allocate defined section for PORT code */
#define PORT_START_SEC_CODE
#include "Port_MemMap.h"

/*!
 * @brief Port driver initialization function
 *
 * @details Function used for initializing the port driver and
 *          for initializing the configured pins.
 *
 *
 * @param[in] Port_ConfigType * ConfigPtr Pointer to configuration (NULL_PTR if only one variant is used)
 *
 * @return void
 *
 * @implements Port_Init_Activity
 **/
void Port_Init
(
    const Port_ConfigType * ConfigPtr
);

#if (STD_ON == PORT_SET_PIN_DIRECTION_API)
/*!
 * @brief Port_SetPinDirection
 *
 * @details Function used for changing the pin direction at runtime
 *
 *
 * @param[in]Pin pin id of the pin that needs to change the direction
 * @param[in]Direction new desired direction IN OUT IN_OUT
 *
 * @return void
 * @implements Port_SetPinDirection_Activity
 **/
void Port_SetPinDirection
(
    Port_PinType Pin,
    Port_PinDirectionType Direction
);
#endif /* (STD_ON == PORT_SET_PIN_DIRECTION_API) */

#ifdef PORT_SET_2_PINS_DIRECTION_API
#if (STD_ON == PORT_SET_2_PINS_DIRECTION_API)
/**
* @brief   Sets the direction of 2 pins.
* @details The function @p Port_Set2PinsDirection() will set the port pins direction
*          during runtime.
* @pre     @p Port_Init() must have been called first. In order to change the
*          pin direction the PortPinDirectionChangeable flag must have been set
*          to @p TRUE for both pins.
*
* @param[in] Pin1          Pin 1 ID number.
* @param[in] Pin2          Pin 2 ID number.
* @param[in] Direction     Port Pin direction.
*
* Port_Set2PinsDirection_Activity
* @api
*/
void Port_Set2PinsDirection
(
    Port_PinType Pin1,
    Port_PinType Pin2,
    Port_PinDirectionType Direction
);

#endif /*(STD_ON == PORT_SET_2_PINS_DIRECTION_API) */
#endif

#if (STD_ON == PORT_SET_PIN_MODE_API)
/*!
 * @brief Port_SetPinMode
 *
 * @details Function used to change the pin mode at runtime.
 *
 * @param[in]Pin pin id of the pin that needs to change the direction
 * @param[in]Mode new mode
 *
 * @return void
 *
 * @implements Port_SetPinMode_Activity
 **/
void Port_SetPinMode
(
    Port_PinType Pin,
    Port_PinModeType Mode
);
#endif /* (STD_ON == PORT_SET_PIN_MODE_API) */

#if (STD_ON == PORT_VERSION_INFO_API)
/*!
 * @brief Port_GetVersionInfo
 *
 * @details Function used to read the driver version information
 *
 *
 * @param[in] versioninfo pointer to structure that will contain the version information
 *
 * @return void
 *
 * @implements Port_GetVersionInfo_Activity
 **/
void Port_GetVersionInfo
(
    Std_VersionInfoType * versioninfo
);
#endif /* (STD_ON == PORT_VERSION_INFO_API) */

/*!
 * @brief Port_RefreshPortDirection
 *
 * @details function used to reset the direction of the pin
 *
 * @return void
 *
 * @implements Port_RefreshPortDirection_Activity
 **/
void Port_RefreshPortDirection(void);

#ifdef PORT_SET_AS_UNUSED_PIN_API
#if (STD_ON == PORT_SET_AS_UNUSED_PIN_API)
/*!
 * @brief Port_SetAsUnusedPin
 *
 * @details configures the referenced pin with all the properties specified in the NotUsedPortPin container.
 *
 * @return void
 *
 * @implements Port_SetAsUnusedPin_Activity
 **/
void Port_SetAsUnusedPin
(
    Port_PinType Pin
);

/*!
 * @brief Port_SetAsUsedPin
 *
 * @details configures the referenced pin with all the properties that where set during the Port_Init operation.
 *
 * @return void
 *
 * @implements Port_SetAsUsedPin_Activity
 **/
void Port_SetAsUsedPin
(
    Port_PinType Pin
);
#endif /* (STD_ON == PORT_SET_AS_UNUSED_PIN_API) */
#endif

#ifdef PORT_RESET_PIN_MODE_API
#if (STD_ON == PORT_RESET_PIN_MODE_API)

/*!
 * @brief Port_ResetPinMode
 *
 * @details reverts the port pin mode of the referenced pin to the value that was set by Port_Init operation.
 *
 * @return void
 *
 * @implements Port_ResetPinMode_Activity
 **/
void Port_ResetPinMode
(
    Port_PinType Pin
);
#endif /* (STD_ON == PORT_RESET_PIN_MODE_API) */
#endif

#define PORT_STOP_SEC_CODE
#include "Port_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */

#endif /* PORT_H */
