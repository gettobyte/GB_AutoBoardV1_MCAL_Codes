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

#ifndef SIUL2_PORT_IP_TYPES_H
#define SIUL2_PORT_IP_TYPES_H

/**
*   @file    Siul2_Port_Ip_Types.h
*
*   @addtogroup Port_IPL
*   @{
*/

#if defined(__cplusplus)
extern "C" {
#endif

/*==================================================================================================
*                                          INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "StandardTypes.h"
#include "Siul2_Port_Ip_Defines.h"

/*==================================================================================================
*                                 SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/*
 * @brief Parameters that shall be published within the driver header file and also in the
 *        module's description file
 */
#define SIUL2_PORT_IP_TYPES_VENDOR_ID_H                     43
#define SIUL2_PORT_IP_TYPES_AR_RELEASE_MAJOR_VERSION_H      4
#define SIUL2_PORT_IP_TYPES_AR_RELEASE_MINOR_VERSION_H      4
#define SIUL2_PORT_IP_TYPES_AR_RELEASE_REVISION_VERSION_H   0
#define SIUL2_PORT_IP_TYPES_SW_MAJOR_VERSION_H              2
#define SIUL2_PORT_IP_TYPES_SW_MINOR_VERSION_H              0
#define SIUL2_PORT_IP_TYPES_SW_PATCH_VERSION_H              0

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if the files Siul2_Port_Ip_Types.h and StandardTypes.h are of the same version */
    #if ((SIUL2_PORT_IP_TYPES_AR_RELEASE_MAJOR_VERSION_H != STD_AR_RELEASE_MAJOR_VERSION) || \
         (SIUL2_PORT_IP_TYPES_AR_RELEASE_MINOR_VERSION_H != STD_AR_RELEASE_MINOR_VERSION)    \
        )
        #error "AutoSar Version Numbers of Siul2_Port_Ip_Types.h and StandardTypes.h are different"
    #endif
#endif

/* Check if the files Siul2_Port_Ip_Types.h and Siul2_Port_Ip_Defines.h are of the same version */
#if (SIUL2_PORT_IP_TYPES_VENDOR_ID_H != SIUL2_PORT_IP_DEFINES_VENDOR_ID_H)
    #error "Siul2_Port_Ip_Types.h and Siul2_Port_Ip_Defines.h have different vendor ids"
#endif

/* Check if Siul2_Port_Ip_Types.h and Siul2_Port_Ip_Defines.h are of the same Autosar version */
#if ((SIUL2_PORT_IP_TYPES_AR_RELEASE_MAJOR_VERSION_H    != SIUL2_PORT_IP_DEFINES_AR_RELEASE_MAJOR_VERSION_H) || \
     (SIUL2_PORT_IP_TYPES_AR_RELEASE_MINOR_VERSION_H    != SIUL2_PORT_IP_DEFINES_AR_RELEASE_MINOR_VERSION_H) || \
     (SIUL2_PORT_IP_TYPES_AR_RELEASE_REVISION_VERSION_H != SIUL2_PORT_IP_DEFINES_AR_RELEASE_REVISION_VERSION_H) \
    )
    #error "AutoSar Version Numbers of Siul2_Port_Ip_Types.h and Siul2_Port_Ip_Defines.h are different"
#endif

/* Check if Siul2_Port_Ip_Types.h and Siul2_Port_Ip_Defines.h are of the same Software version */
#if ((SIUL2_PORT_IP_TYPES_SW_MAJOR_VERSION_H != SIUL2_PORT_IP_DEFINES_SW_MAJOR_VERSION_H) || \
     (SIUL2_PORT_IP_TYPES_SW_MINOR_VERSION_H != SIUL2_PORT_IP_DEFINES_SW_MINOR_VERSION_H) || \
     (SIUL2_PORT_IP_TYPES_SW_PATCH_VERSION_H != SIUL2_PORT_IP_DEFINES_SW_PATCH_VERSION_H)    \
    )
    #error "Software Version Numbers of Siul2_Port_Ip_Types.h and Siul2_Port_Ip_Defines.h are different"
#endif
/*==================================================================================================
*                                            CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/
/*! @brief SIUL2 module maximum number of input signal on a pin */
#define FEATURE_SIUL2_MAX_NUMBER_OF_INPUT        (8U)

#ifdef SIUL2_PORT_IP_HAS_ADC_INTERLEAVE
/*! @brief SIUL2 module maximum number of input signal on a pin */
#define FEATURE_ADC_INTERLEAVE_MAX_MUX_MODE      (2U)
#endif
/*==================================================================================================
*                                              ENUMS
==================================================================================================*/

/*==================================================================================================
*                                  STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/
/*!
 * @brief Type of a port levels representation.
 * Implements : Siul2_Port_Ip_PortPinsLevelType
 */
typedef uint8 Siul2_Port_Ip_PortPinsLevelType;

/*!
 * @brief Internal resistor pull feature selection
 * Implements : Siul2_Port_Ip_PortPullConfig
 */
typedef enum
{
    PORT_INTERNAL_PULL_DOWN_ENABLED      = 0U,  /*!< internal pull-down resistor is enabled.     */
    PORT_INTERNAL_PULL_UP_ENABLED        = 1U,  /*!< internal pull-up resistor is enabled.       */
    PORT_INTERNAL_PULL_NOT_ENABLED       = 2U   /*!< internal pull-down/up resistor is disabled. */
} Siul2_Port_Ip_PortPullConfig;

/*!
 * @brief Configures the Pin output muxing selection
 * Implements : Siul2_Port_Ip_PortMux
 */
typedef enum
{
    PORT_MUX_AS_GPIO            = 0U,   /*!< corresponding pin is configured as GPIO */
    PORT_MUX_ALT1               = 1U,   /*!< chip-specific                           */
    PORT_MUX_ALT2               = 2U,   /*!< chip-specific                           */
    PORT_MUX_ALT3               = 3U,   /*!< chip-specific                           */
    PORT_MUX_ALT4               = 4U,   /*!< chip-specific                           */
    PORT_MUX_ALT5               = 5U,   /*!< chip-specific                           */
    PORT_MUX_ALT6               = 6U,   /*!< chip-specific                           */
    PORT_MUX_ALT7               = 7U    /*!< chip-specific                           */
} Siul2_Port_Ip_PortMux;


#ifdef FEATURE_SIUL2_PORT_IP_HAS_INPUT_FILTER
/*!
 * @brief Configures the Pin filter enable
 * Implements : Siul2_Port_Ip_PortInputFilter
 */
typedef enum
{
    PORT_INPUT_FILTER_DISABLED     = 0U, /*!< IFE OFF*/
    PORT_INPUT_FILTER_ENABLED      = 1U  /*!< IFE ON*/
} Siul2_Port_Ip_PortInputFilter;
#endif /* FEATURE_SIUL2_PORT_IP_HAS_INPUT_FILTER */

#ifdef FEATURE_SIUL2_PORT_IP_HAS_PULL_KEEPER
/*!
 * @brief Configures the Pad keep enable
 * Implements : Siul2_Port_Ip_PortPullKeep
 */
typedef enum
{
    PORT_PULL_KEEP_DISABLED     = 0U, /*!< PKE OFF*/
    PORT_PULL_KEEP_ENABLED      = 1U  /*!< PKE ON*/
} Siul2_Port_Ip_PortPullKeep;
#endif /* FEATURE_SIUL2_PORT_IP_HAS_PULL_KEEPER */

#ifdef FEATURE_SIUL2_PORT_IP_HAS_INVERT_DATA
/*!
 * @brief Configures signal invert for the pin
 * Implements : Siul2_Port_Ip_PortInvert
 */
typedef enum
{
    PORT_INVERT_DISABLED     = 0U, /*!< INV OFF*/
    PORT_INVERT_ENABLED      = 1U  /*!< INV ON*/
} Siul2_Port_Ip_PortInvert;
#endif /* FEATURE_SIUL2_PORT_IP_HAS_INVERT_DATA */

/*!
 * @brief Configures the output buffer enable
 * Implements : Siul2_Port_Ip_PortOutputBuffer
 */
typedef enum
{
    PORT_OUTPUT_BUFFER_DISABLED  = 0U, /*!< Output buffer disabled */
    PORT_OUTPUT_BUFFER_ENABLED   = 1U  /*!< Output buffer enabled  */
} Siul2_Port_Ip_PortOutputBuffer;

/*!
 * @brief Configures the Input Buffer Enable field.
 * Implements : Siul2_Port_Ip_PortInputBuffer
 */
typedef enum
{
    PORT_INPUT_BUFFER_DISABLED   = 0U, /*!< Input buffer disabled */
    PORT_INPUT_BUFFER_ENABLED    = 1U  /*!< Input buffer enabled  */
} Siul2_Port_Ip_PortInputBuffer;

#ifdef FEATURE_SIUL2_HAS_INPUT_HYSTERESYS
/*!
 * @brief Configures the Hysteresis Enable field.
 * Implements : Siul2_Port_Ip_PortHysteresis
 */
typedef enum
{
    PORT_HYSTERESYS_DISABLED     = 0U, /*!< Input Hysteresis disabled */
    PORT_HYSTERESYS_ENABLED      = 1U  /*!< Input Hysteresis enabled  */
} Siul2_Port_Ip_PortHysteresis;
#endif /* FEATURE_SIUL2_HAS_INPUT_HYSTERESYS */

#ifdef FEATURE_SIUL2_HAS_AE_INSTANCE
/*!
 * @brief Configures the Analog Pad Control.
 * Implements : Siul2_Port_Ip_PortAnalogPad
 */
typedef enum
{
    PORT_ANALOG_PAD_CONTROL_DISABLED = 0U, /*!< Disable (the switch is off)                                 */
    PORT_ANALOG_PAD_CONTROL_ENABLED  = 1U  /*!< Enable (another module can control the state of the switch) */
} Siul2_Port_Ip_PortAnalogPad;
#endif /* FEATURE_SIUL2_HAS_AE_INSTANCE */

/*!
 * @brief Configures the Pin input muxing selection
 * Implements : Siul2_Port_Ip_PortInputMux
 */
typedef enum
{
    PORT_INPUT_MUX_ALT0      = 0U,   /*!< Chip-specific     */
    PORT_INPUT_MUX_ALT1      = 1U,   /*!< Chip-specific     */
    PORT_INPUT_MUX_ALT2      = 2U,   /*!< Chip-specific     */
    PORT_INPUT_MUX_ALT3      = 3U,   /*!< Chip-specific     */
    PORT_INPUT_MUX_ALT4      = 4U,   /*!< Chip-specific     */
    PORT_INPUT_MUX_ALT5      = 5U,   /*!< Chip-specific     */
    PORT_INPUT_MUX_ALT6      = 6U,   /*!< Chip-specific     */
    PORT_INPUT_MUX_ALT7      = 7U,   /*!< Chip-specific     */
    PORT_INPUT_MUX_ALT8      = 8U,   /*!< Chip-specific     */
    PORT_INPUT_MUX_ALT9      = 9U,   /*!< Chip-specific     */
    PORT_INPUT_MUX_ALT10      = 10U,   /*!< Chip-specific     */
    PORT_INPUT_MUX_ALT11      = 11U,   /*!< Chip-specific     */
    PORT_INPUT_MUX_ALT12      = 12U,   /*!< Chip-specific     */
    PORT_INPUT_MUX_ALT13      = 13U,   /*!< Chip-specific     */
    PORT_INPUT_MUX_ALT14      = 14U,   /*!< Chip-specific     */
    PORT_INPUT_MUX_ALT15      = 15U,   /*!< Chip-specific     */
    PORT_INPUT_MUX_NO_INIT   = 16U    /*!< No initialization */
} Siul2_Port_Ip_PortInputMux;

/*!
 * @brief Configures the Safe Mode Control.
 * Implements : Siul2_Port_Ip_PortSafeMode
 */
typedef enum
{
    PORT_SAFE_MODE_DISABLED     = 0U, /*!< To drive pad in hi-z state using OBE = 0, when FCCU in fault state.
                                       *   The OBE will be driven by IP/SIUL when FCCU leaves the fault state. */
    PORT_SAFE_MODE_ENABLED      = 1U  /*!< No effect on IP/SIUL driven OBE value */
} Siul2_Port_Ip_PortSafeMode;

/*!
 * @brief Configures the slew rate control.
 * Implements : Siul2_Port_Ip_PortSlewRateControl
 */
#ifdef SIUL2_PORT_IP_HAS_ONEBIT_SLEWRATE
typedef enum
{
    PORT_SLEW_RATE_FASTEST                = 0U, /*!< Fmax=133 MHz(at 1.8V), 100 MHz (at 3.3V), apply for SIUL2_0/1  */
    PORT_SLEW_RATE_SLOWEST                = 1U  /*!< Fmax=83 MHz (at 1.8V), 63 MHz (at 3.3V), apply for SIUL2_0/1   */
} Siul2_Port_Ip_PortSlewRateControl;

#else
typedef enum
{
    PORT_SLEW_RATE_CONTROL0                = 0U, /*!< Fmax=208 MHz (at 1.8V), 166 MHz (at 3.3V), apply for SIUL2_0/1 */
    PORT_SLEW_RATE_CONTROL4                = 4U, /*!< Fmax=166 MHz (at 1.8V), 150 MHz (at 3.3V, apply for SIUL2_0/1  */
    PORT_SLEW_RATE_CONTROL5                = 5U, /*!< Fmax=150 MHz (at 1.8V), 133 MHz (at 3.3V), apply for SIUL2_0/1 */
    PORT_SLEW_RATE_CONTROL6                = 6U, /*!< Fmax=133 MHz(at 1.8V), 100 MHz (at 3.3V), apply for SIUL2_0/1  */
    PORT_SLEW_RATE_CONTROL7                = 7U  /*!< Fmax=83 MHz (at 1.8V), 63 MHz (at 3.3V), apply for SIUL2_0/1   */
} Siul2_Port_Ip_PortSlewRateControl;
#endif

#ifdef FEATURE_SIUL2_PORT_IP_HAS_DRIVE_STRENGTH
/*!
 * @brief Configures the drive strength.
 * Implements : Siul2_Port_Ip_PortDriveStrength
 */
typedef enum
{
    PORT_DRIVE_STRENTGTH_DISABLED = 0U, /*!< Enables DSE. */
    PORT_DRIVE_STRENTGTH_ENABLED      = 1U  /*!< Enables DSE.*/
} Siul2_Port_Ip_PortDriveStrength;
#endif /* FEATURE_SIUL2_PORT_IP_HAS_DRIVE_STRENGTH */

#ifdef FEATURE_SIUL2_PORT_IP_HAS_RECEIVER_SELECT
/*!
 * @brief Configures the Receiver Select.
 * Implements : Siul2_Port_Ip_PortReceiverSelect
 */
typedef enum
{
    PORT_RECEIVER_ENABLE_DIFFERENTIAL_VREF = 0U, /*!< Enables the differential vref based receiver. */
    PORT_RECEIVER_ENABLE_SINGLE_ENDED      = 1U  /*!< Enables the single ended receiver.            */
} Siul2_Port_Ip_PortReceiverSelect;
#endif /* FEATURE_SIUL2_PORT_IP_HAS_RECEIVER_SELECT */

#ifdef FEATURE_SIUL2_PORT_IP_HAS_OPEN_DRAIN
/*!
 * @brief Configures the Open Drain Enable field.
 * Implements : Siul2_Port_Ip_PortOpenDrain
 */
typedef enum
{
    PORT_OPEN_DRAIN_DISABLED     = 0U, /*!< Output is CMOS       */
    PORT_OPEN_DRAIN_ENABLED      = 1U  /*!< Output is open drain */
} Siul2_Port_Ip_PortOpenDrain;
#endif /* FEATURE_SIUL2_PORT_IP_HAS_OPEN_DRAIN */

typedef enum
{
   SIUL2_PORT_SUCCESS = E_OK,
   SIUL2_PORT_ERROR = E_NOT_OK
}Siul2_Port_Ip_PortStatusType;

/** PORT - Register Layout Typedef */
typedef struct {
  __IO  uint32 MSCR[16];
} Siul2_Port_Ip_PortType;

/*!
 * @brief Configures port direction.
 */
typedef enum
{
    SIUL2_PORT_IN = 0U,         /**< @brief Sets port pin as input. */
    SIUL2_PORT_OUT = 1U,        /**< @brief Sets port pin as output. */
    SIUL2_PORT_IN_OUT = 2U,     /**< @brief Sets port pin as bidirectional. */
    SIUL2_PORT_HI_Z = 3U        /**< @brief Sets port pin as high_z. */
} Siul2_Port_Ip_PortDirectionType;

#ifdef SIUL2_PORT_IP_HAS_ADC_INTERLEAVE
/*!
 * @brief Configures adc interleave mux mode.
 */
typedef enum
{
    MUX_MODE_NOT_AVAILABLE      = 0x0000U,
    MUX_MODE_EN_ADC1_S14_1      = 0x0008U,
    MUX_MODE_EN_ADC1_S15_1      = 0x0010U,
    MUX_MODE_EN_ADC0_S8_1       = 0x0002U,
    MUX_MODE_EN_ADC2_S8_1       = 0x0200U,
    MUX_MODE_EN_ADC0_S9_1       = 0x0004U,
    MUX_MODE_EN_ADC2_S9_1       = 0x0400U,
    MUX_MODE_EN_ADC1_S22_1      = 0x0020U,
    MUX_MODE_EN_ADC1_S23_1      = 0x0040U,
    MUX_MODE_EN_ADC1_S14_0      = 0xFFF7U,
    MUX_MODE_EN_ADC1_S15_0      = 0xFFEFU,
    MUX_MODE_EN_ADC0_S8_0       = 0xFFFDU,
    MUX_MODE_EN_ADC2_S8_0       = 0xFDFFU,
    MUX_MODE_EN_ADC0_S9_0       = 0xFFFBU,
    MUX_MODE_EN_ADC2_S9_0       = 0xFBFFU,
    MUX_MODE_EN_ADC1_S22_0      = 0xFFDFU,
    MUX_MODE_EN_ADC1_S23_0      = 0xFFBFU,
} Siul2_Port_Ip_AdcInterleaves;
#endif

/*!
 * @brief Defines the converter configuration
 *
 * This structure is used to configure the pins
 * Implements : Siul2_Port_Ip_PinSettingsConfig
 */
typedef struct
{
    SIUL2_Type                           *base;             /*!< The main SIUL2 base pointer.                               */
    uint32                               pinPortIdx;        /*!< Port pin number.                                           */
    Siul2_Port_Ip_PortPullConfig         pullConfig;        /*!< Internal resistor pull feature selection.                  */
    Siul2_Port_Ip_PortMux                mux;               /*!< Pin output muxing selection.                               */
    Siul2_Port_Ip_PortSafeMode           safeMode;          /*!< Configures the Safe Mode Control, apply for SIUL2_0/1      */
    Siul2_Port_Ip_PortSlewRateControl    slewRateCtrlSel;   /*!< Configures the Slew Rate Control field.                    */
#ifdef FEATURE_SIUL2_PORT_IP_HAS_DRIVE_STRENGTH
    Siul2_Port_Ip_PortDriveStrength      driveStrength;     /*!< Configures DSE                                             */
#endif /* FEATURE_SIUL2_PORT_IP_HAS_DRIVE_STRENGTH */
#ifdef FEATURE_SIUL2_PORT_IP_HAS_INPUT_FILTER
    Siul2_Port_Ip_PortInputFilter        inputFilter;       /*!< Configures IFE                                             */
#endif /* FEATURE_SIUL2_PORT_IP_HAS_INPUT_FILTER */
#ifdef FEATURE_SIUL2_PORT_IP_HAS_RECEIVER_SELECT
    Siul2_Port_Ip_PortReceiverSelect     receiverSel;       /*!< Configures the Receiver Select, apply for SIUL2_0/1        */
#endif /* FEATURE_SIUL2_PORT_IP_HAS_RECEIVER_SELECT */
#ifdef FEATURE_SIUL2_PORT_IP_HAS_PULL_KEEPER
    Siul2_Port_Ip_PortPullKeep           pullKeep;          /*!< Configures PKE                                             */
#endif /* FEATURE_SIUL2_PORT_IP_HAS_PULL_KEEPER */
#ifdef FEATURE_SIUL2_PORT_IP_HAS_INVERT_DATA
    Siul2_Port_Ip_PortInvert             invert;            /*!< Configures IFE                                             */
#endif /* FEATURE_SIUL2_PORT_IP_HAS_INVERT_DATA */
#ifdef FEATURE_SIUL2_PORT_IP_HAS_OPEN_DRAIN
    Siul2_Port_Ip_PortOpenDrain          openDrain;         /*!< Configures open drain, apply for SIUL2_0/1                 */
#endif /* FEATURE_SIUL2_PORT_IP_HAS_OPEN_DRAIN */
    Siul2_Port_Ip_PortOutputBuffer       outputBuffer;      /*!< Configures the Output Buffer Enable.                       */
    Siul2_Port_Ip_PortInputBuffer        inputBuffer;       /*!< Configures the Input Buffer Enable.                        */
#ifdef SIUL2_PORT_IP_HAS_ADC_INTERLEAVE
    Siul2_Port_Ip_AdcInterleaves         adcInterleaves[FEATURE_ADC_INTERLEAVE_MAX_MUX_MODE];  /*!< Configures the adc interleave mux modes. */
#endif /* SIUL2_PORT_IP_HAS_ADC_INTERLEAVE */
    Siul2_Port_Ip_PortInputMux           inputMux[FEATURE_SIUL2_MAX_NUMBER_OF_INPUT];   /*!< Configures the input muxing */
    uint32                               inputMuxReg[FEATURE_SIUL2_MAX_NUMBER_OF_INPUT];
                                /*!< Configures the input muxing register. For the pins controlled by both SIUL2_0
                                 * and SIUL2_1 instances, refer the note for PINS_DRV_SetInputBuffer function      */
    Siul2_Port_Ip_PortPinsLevelType      initValue;         /*!< Initial value                                              */
#if (STD_ON == PORT_VIRTWRAPPER_SUPPORT)
    uint8                                mscrPdacSlot;      /*!< Configures MSCR PDAC Slot for VirtWrapper                       */
    uint8                                imcrPdacSlot;      /*!< Configures IMCR PDAC Slot for VirtWrapper                       */
#endif
} Siul2_Port_Ip_PinSettingsConfig;

/*==================================================================================================
*                                  GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                       FUNCTION PROTOTYPES
==================================================================================================*/

#if defined(__cplusplus)
}
#endif

/** @} */

#endif /* SIUL2_PORT_IP_Types_H */
