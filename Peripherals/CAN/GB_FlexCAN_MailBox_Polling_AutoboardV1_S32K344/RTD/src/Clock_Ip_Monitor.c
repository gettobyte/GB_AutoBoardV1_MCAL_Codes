/*==================================================================================================
*   Project              : RTD AUTOSAR 4.4
*   Platform             : CORTEXM
*   Peripheral           : 
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
*   @file       Clock_Ip_Monitor.c
*   @version    2.0.0
*
*   @brief   CLOCK driver implementations.
*   @details CLOCK driver implementations.
*
*   @addtogroup CLOCK_DRIVER Clock Ip Driver
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

#include "Clock_Ip_Private.h"
#include "SchM_Mcu.h"

/*==================================================================================================
                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define CLOCK_IP_MONITOR_VENDOR_ID_C                      43
#define CLOCK_IP_MONITOR_AR_RELEASE_MAJOR_VERSION_C       4
#define CLOCK_IP_MONITOR_AR_RELEASE_MINOR_VERSION_C       4
#define CLOCK_IP_MONITOR_AR_RELEASE_REVISION_VERSION_C    0
#define CLOCK_IP_MONITOR_SW_MAJOR_VERSION_C               2
#define CLOCK_IP_MONITOR_SW_MINOR_VERSION_C               0
#define CLOCK_IP_MONITOR_SW_PATCH_VERSION_C               0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if Clock_Ip_Monitor.c file and Clock_Ip_Private.h file are of the same vendor */
#if (CLOCK_IP_MONITOR_VENDOR_ID_C != CLOCK_IP_PRIVATE_VENDOR_ID)
    #error "Clock_Ip_Monitor.c and Clock_Ip_Private.h have different vendor ids"
#endif

/* Check if Clock_Ip_Monitor.c file and Clock_Ip_Private.h file are of the same Autosar version */
#if ((CLOCK_IP_MONITOR_AR_RELEASE_MAJOR_VERSION_C != CLOCK_IP_PRIVATE_AR_RELEASE_MAJOR_VERSION) || \
     (CLOCK_IP_MONITOR_AR_RELEASE_MINOR_VERSION_C != CLOCK_IP_PRIVATE_AR_RELEASE_MINOR_VERSION) || \
     (CLOCK_IP_MONITOR_AR_RELEASE_REVISION_VERSION_C != CLOCK_IP_PRIVATE_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Clock_Ip_Monitor.c and Clock_Ip_Private.h are different"
#endif

/* Check if Clock_Ip_Monitor.c file and Clock_Ip_Private.h file are of the same Software version */
#if ((CLOCK_IP_MONITOR_SW_MAJOR_VERSION_C != CLOCK_IP_PRIVATE_SW_MAJOR_VERSION) || \
     (CLOCK_IP_MONITOR_SW_MINOR_VERSION_C != CLOCK_IP_PRIVATE_SW_MINOR_VERSION) || \
     (CLOCK_IP_MONITOR_SW_PATCH_VERSION_C != CLOCK_IP_PRIVATE_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Clock_Ip_Monitor.c and Clock_Ip_Private.h are different"
#endif
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
/* Check if Clock_Ip_Monitor.c file and SchM_Mcu.h file are of the same Autosar version */
#if ((CLOCK_IP_MONITOR_AR_RELEASE_MAJOR_VERSION_C != SCHM_MCU_AR_RELEASE_MAJOR_VERSION) || \
     (CLOCK_IP_MONITOR_AR_RELEASE_MINOR_VERSION_C != SCHM_MCU_AR_RELEASE_MINOR_VERSION))
    #error "AutoSar Version Numbers of Clock_Ip_Monitor.c and SchM_Mcu.h are different"
#endif
#endif

/*==================================================================================================
*                           LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
*                                          LOCAL MACROS
==================================================================================================*/
#ifdef CLOCK_IP_CMU_FC_FCE_REF_CNT_LFREF_HFREF
#define CLOCK_IP_CMU_REFERENCE_COUNTER_MINIMUM_VALUE_MULTIPLIER 10U
#define CLOCK_IP_CMU_FC_VAR                                     3U
#define CLOCK_IP_CMU_REFERENCE_CLOCK_VARIATION                  33U
#define CLOCK_IP_CMU_MONITORED_CLOCK_VARIATION                  11U
#define CLOCK_IP_DIVIDE_BY_1000                                 1000U

#if defined(CLOCK_IP_FEATURE_OFFSET_REFERENCE_COUNT_FORMULA1)
    #define CLOCK_IP_OFFSET_REFERENCE_COUNT_FORMULA1 CLOCK_IP_FEATURE_OFFSET_REFERENCE_COUNT_FORMULA1
#else
    #define CLOCK_IP_OFFSET_REFERENCE_COUNT_FORMULA1 1U
#endif

#if defined(CLOCK_IP_FEATURE_MULTIPLIER_REFERENCE_COUNT_FORMULA1)
    #define CLOCK_IP_MULTIPLIER_REFERENCE_COUNT_FORMULA1 CLOCK_IP_FEATURE_MULTIPLIER_REFERENCE_COUNT_FORMULA1
#else
    #define CLOCK_IP_MULTIPLIER_REFERENCE_COUNT_FORMULA1 3U
#endif

#if defined(CLOCK_IP_OFFSET_REFERENCE_COUNT_FORMULA2)
    #define CLOCK_IP_OFFSET_REFERENCE_COUNT_FORMULA2 CLOCK_IP_OFFSET_REFERENCE_COUNT_FORMULA2
#else
    #define CLOCK_IP_OFFSET_REFERENCE_COUNT_FORMULA2 9U
#endif

#if defined(CLOCK_IP_FEATURE_MULTIPLIER_REFERENCE_COUNT_FORMULA2)
    #define CLOCK_IP_MULTIPLIER_REFERENCE_COUNT_FORMULA2 CLOCK_IP_FEATURE_MULTIPLIER_REFERENCE_COUNT_FORMULA2
#else
    #define CLOCK_IP_MULTIPLIER_REFERENCE_COUNT_FORMULA2 5U
#endif

#endif

/*==================================================================================================
*                                         LOCAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                         LOCAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                        GLOBAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                    LOCAL FUNCTION PROTOTYPES
==================================================================================================*/
/* Clock start section code */
#define MCU_START_SEC_CODE

#include "Mcu_MemMap.h"

/*  TODO ARTD-738  Implement CMU in Clock_Ip driver    */

static void Clock_Ip_ClockMonitorEmpty(Clock_Ip_CmuConfigType const* Config);
static void Clock_Ip_ClockMonitorEmpty_Set(Clock_Ip_CmuConfigType const* Config, uint32 Index);
static void Clock_Ip_ClockMonitorEmpty_Disable(Clock_Ip_NameType Name);
static void Clock_Ip_ClockMonitorEmpty_ClearStatus(Clock_Ip_NameType Name);
static Clock_Ip_CmuStatusType Clock_Ip_ClockMonitorEmpty_GetStatus(Clock_Ip_NameType Name);

#ifdef CLOCK_IP_CMU_FC_FCE_REF_CNT_LFREF_HFREF
static void Clock_Ip_ResetCmuFcFceRefCntLfrefHfref(Clock_Ip_CmuConfigType const* Config);
#if !(defined(CLOCK_IP_REGISTER_VALUES_OPTIMIZATION) && (CLOCK_IP_REGISTER_VALUES_OPTIMIZATION == STD_ON))
static void Clock_Ip_SetCmuFcFceRefCntLfrefHfref(Clock_Ip_CmuConfigType const* Config, uint32 Index);
#endif
static void Clock_Ip_DisableCmuFcFceRefCntLfrefHfref(Clock_Ip_NameType Name);
static void Clock_Ip_ClearStatusCmuFcFceRefCntLfrefHfref(Clock_Ip_NameType Name);
static Clock_Ip_CmuStatusType Clock_Ip_GetStatusCmuFcFceRefCntLfrefHfref(Clock_Ip_NameType Name);
static void Clock_Ip_EnableCmuFcFceRefCntLfrefHfref(Clock_Ip_CmuConfigType const* Config);
#endif


/* Clock stop section code */
#define MCU_STOP_SEC_CODE

#include "Mcu_MemMap.h"

/*==================================================================================================
*                                         LOCAL FUNCTIONS
==================================================================================================*/

/* Clock start section code */
#define MCU_START_SEC_CODE

#include "Mcu_MemMap.h"

static void Clock_Ip_ClockMonitorEmpty(Clock_Ip_CmuConfigType const* Config)
{
    (void)Config;
    /* No implementation */
}

static void Clock_Ip_ClockMonitorEmpty_Set(Clock_Ip_CmuConfigType const* Config, uint32 Index)
{
    (void)Config;
    (void)Index;
    /* No implementation */
}

static void Clock_Ip_ClockMonitorEmpty_Disable(Clock_Ip_NameType Name)
{
    (void)Name;
    /* No implementation */
}

static void Clock_Ip_ClockMonitorEmpty_ClearStatus(Clock_Ip_NameType Name)
{
    (void)Name;
    /* No implementation */
}

static Clock_Ip_CmuStatusType Clock_Ip_ClockMonitorEmpty_GetStatus(Clock_Ip_NameType Name)
{
    (void)Name;
    /* No implementation */
    return CLOCK_IP_CMU_STATUS_UNDEFINED;
}
#if (defined(CLOCK_IP_REGISTER_VALUES_OPTIMIZATION) && (CLOCK_IP_REGISTER_VALUES_OPTIMIZATION == STD_ON))
static void Clock_Ip_SetClockMonitorRegisterValues(Clock_Ip_CmuConfigType const* Config, uint32 Index)
{
    (void)Index;
    Clock_Ip_WriteRegisterValues(&Config->Indexes);
}
#endif

#ifdef CLOCK_IP_CMU_FC_FCE_REF_CNT_LFREF_HFREF
static void Clock_Ip_DisableCmuFcFceRefCntLfrefHfref(Clock_Ip_NameType Name)
{
    const Clock_Ip_CmuInfoType * CmuInformation = &Clock_Ip_axCmuInfo[Clock_Ip_au8ClockFeatures[Name][CLOCK_IP_CMU_INDEX]];
    Clock_Ip_ClockMonitorType* const CmuFc    = CmuInformation->CmuInstance;

    boolean TimeoutOccurred = FALSE;
    uint32 StartTime;
    uint32 ElapsedTime;
    uint32 TimeoutTicks;
    uint32 FrequencyCheckStatus;

#if (defined (CLOCK_IP_S32K118) || defined(CLOCK_IP_S32K116))
    if(0U == ((IP_PCC->PCCn[62] & PCC_PCCn_CGC_MASK) >> PCC_PCCn_CGC_SHIFT))
    {
        #if defined(CLOCK_IP_HAS_FIRC_MON1_CLK)
            #ifdef CLOCK_IP_ENABLE_USER_MODE_SUPPORT
                #if (STD_ON == CLOCK_IP_ENABLE_USER_MODE_SUPPORT)
                    OsIf_Trusted_Call(Clock_Ip_EnableCmu0Gate_TrustedCall);
                #else
                    Clock_Ip_EnableCmu0Gate_TrustedCall();
                #endif
            #endif /* CLOCK_IP_ENABLE_USER_MODE_SUPPORT */
        #endif
        /* Enable clock gate for CMU0 device */
        IP_PCC->PCCn[62] |= PCC_PCCn_CGC_MASK;
    }

    if(0U == ((IP_PCC->PCCn[63] & PCC_PCCn_CGC_MASK) >> PCC_PCCn_CGC_SHIFT))
    {
        #if defined(CLOCK_IP_HAS_FIRC_MON2_CLK)
            #ifdef CLOCK_IP_ENABLE_USER_MODE_SUPPORT
                #if (STD_ON == CLOCK_IP_ENABLE_USER_MODE_SUPPORT)
                    OsIf_Trusted_Call(Clock_Ip_EnableCmu1Gate_TrustedCall);
                #else
                    Clock_Ip_EnableCmu1Gate_TrustedCall();
                #endif
            #endif /* CLOCK_IP_ENABLE_USER_MODE_SUPPORT */
        #endif
        /* Enable clock gate for CMU1 device */
        IP_PCC->PCCn[63] |= PCC_PCCn_CGC_MASK;
    }
#endif

    /* Enter critical region*/
    SchM_Enter_Mcu_MCU_EXCLUSIVE_AREA_01();
    /* Only disable frequency check if it is enabled */
    if (CLOCK_IP_CMU_FREQUENCY_CHECK_ENABLED == (CmuFc->GCR & CMU_FC_GCR_FCE_MASK))
    {
        Clock_Ip_StartTimeout(&StartTime, &ElapsedTime, &TimeoutTicks, CLOCK_IP_TIMEOUT_VALUE_US);
        /* Wait for frequency check to be running. */
        do
        {
            FrequencyCheckStatus = (CmuFc->SR & CMU_FC_SR_RS_MASK);
            TimeoutOccurred = Clock_Ip_TimeoutExpired(&StartTime, &ElapsedTime, TimeoutTicks);
        }
        while((CLOCK_IP_CMU_FREQUENCY_CHECK_STOPPED == FrequencyCheckStatus) && (!TimeoutOccurred));

        /* timeout notification */
        if (TimeoutOccurred)
        {
            /* Report timeout error */
            Clock_Ip_ReportClockErrors(CLOCK_IP_REPORT_TIMEOUT_ERROR, Name);
        }
        else
        {
            /* Disable frequency check */
            CmuFc->GCR &= ~CMU_FC_GCR_FCE_MASK;

            /* Disable interupts */
            CmuFc->IER &= ~(CMU_FC_IER_FLLIE_MASK | CMU_FC_IER_FHHIE_MASK | CMU_FC_IER_FLLAIE_MASK | CMU_FC_IER_FHHAIE_MASK);

            /* Clear flags */
            CmuFc->SR |= (CMU_FC_SR_FLL_MASK | CMU_FC_SR_FHH_MASK);
        }
    }
    else
    {
        /* Disable interupts */
        CmuFc->IER &= ~(CMU_FC_IER_FLLIE_MASK | CMU_FC_IER_FHHIE_MASK | CMU_FC_IER_FLLAIE_MASK | CMU_FC_IER_FHHAIE_MASK);

        /* Clear flags */
        CmuFc->SR |= (CMU_FC_SR_FLL_MASK | CMU_FC_SR_FHH_MASK);
    }

    /* Exit critical region. */
    SchM_Exit_Mcu_MCU_EXCLUSIVE_AREA_01();
}

/* Reset CMU register */
static void Clock_Ip_ResetCmuFcFceRefCntLfrefHfref(Clock_Ip_CmuConfigType const* Config)
{
    Clock_Ip_DisableCmuFcFceRefCntLfrefHfref(Config->Name);
}

#if !(defined(CLOCK_IP_REGISTER_VALUES_OPTIMIZATION) && (CLOCK_IP_REGISTER_VALUES_OPTIMIZATION == STD_ON))
static void Clock_Ip_SetCmuFcFceRefCntLfrefHfref(Clock_Ip_CmuConfigType const* Config, uint32 Index)
{
    const Clock_Ip_CmuInfoType * CmuInformation = &Clock_Ip_axCmuInfo[Clock_Ip_au8ClockFeatures[Config->Name][CLOCK_IP_CMU_INDEX]];
    Clock_Ip_ClockMonitorType* const CmuFc    = CmuInformation->CmuInstance;
    static uint32 Hash[CLOCK_IP_CMUS_NO];

    uint32 ReferenceClk = 0U;
    uint32 MonitoredClk = 0U;
    uint32 BusClk = 0U;
    uint32 RefCount = 0U;
    uint32 HfRef = 0U;
    uint32 LfRef = 0U;
    uint32 Cmp1;
    uint32 Cmp2;
    uint32 DivideBy;
    uint32 DividerResult;
    uint32 ModuloValue;

    /* Do not calculate cmu values if these values are already calculated and written in hw registers */
    if (Hash[Index] != ((((uint32)Config->Enable) ^ ((uint32)Config->Interrupt) ^ ((uint32)Config->MonitoredClockFrequency)  ^ ((uint32)Config->Name))))
    {
        Hash[Index] = ((((uint32)Config->Enable) ^ ((uint32)Config->Interrupt) ^ ((uint32)Config->MonitoredClockFrequency)  ^ ((uint32)Config->Name)));

        ReferenceClk = Clock_Ip_pxConfig->ConfiguredFrequencies[Clock_Ip_FreqIds[CmuInformation->Reference]].ConfiguredFrequencyValue / CLOCK_IP_DIVIDE_BY_1000;
        BusClk       = Clock_Ip_pxConfig->ConfiguredFrequencies[Clock_Ip_FreqIds[CmuInformation->Bus]].ConfiguredFrequencyValue / CLOCK_IP_DIVIDE_BY_1000;
        MonitoredClk = Config->MonitoredClockFrequency / CLOCK_IP_DIVIDE_BY_1000;

#if (defined(CLOCK_IP_DEV_ERROR_DETECT) && (CLOCK_IP_DEV_ERROR_DETECT == STD_ON))
        CLOCK_IP_DEV_ASSERT(ReferenceClk != 0U);
        CLOCK_IP_DEV_ASSERT(BusClk != 0U);
        CLOCK_IP_DEV_ASSERT(MonitoredClk != 0U);
#endif
        /* Avoid divide by zero */
        if ((ReferenceClk != 0U) && (BusClk != 0U) && (MonitoredClk != 0U))
        {
            /* Cmp1 = ceiling of (3 * fRef/ fBus) */
            Cmp1 = CLOCK_IP_OFFSET_REFERENCE_COUNT_FORMULA1 + (uint32)((CLOCK_IP_MULTIPLIER_REFERENCE_COUNT_FORMULA1 * ReferenceClk) / BusClk);
            /* Cmp2 = ceiling of (8 + (5 * fRef / fMonitor)) */
            Cmp2 = CLOCK_IP_OFFSET_REFERENCE_COUNT_FORMULA2 + (uint32)((CLOCK_IP_MULTIPLIER_REFERENCE_COUNT_FORMULA2 * ReferenceClk) / MonitoredClk);

            /* REF count = Max(cmp1,cmp2) */
            RefCount = (Cmp1 > Cmp2) ? Cmp1 : Cmp2;


            /* (fMonitoredClk mul_by (1000U plus CLOCK_IP_CMU_MONITORED_CLOCK_VARIATION)) divide_by (fReferenceClk mul_by (1000U minus CLOCK_IP_CMU_REFERENCE_CLOCK_VARIATION)) plus CLOCK_IP_CMU_FC_VAR plus 1U */
            HfRef = MonitoredClk * (1000U + CLOCK_IP_CMU_MONITORED_CLOCK_VARIATION) * RefCount;
            DivideBy = ReferenceClk * (1000U - CLOCK_IP_CMU_REFERENCE_CLOCK_VARIATION);
            DividerResult = (uint32) HfRef / DivideBy;
            ModuloValue = HfRef - (DivideBy * DividerResult);
            HfRef = (DividerResult * CLOCK_IP_CMU_REFERENCE_COUNTER_MINIMUM_VALUE_MULTIPLIER) + ((uint32)((ModuloValue * CLOCK_IP_CMU_REFERENCE_COUNTER_MINIMUM_VALUE_MULTIPLIER) / DivideBy)) + (CLOCK_IP_CMU_FC_VAR + 1U);

            /* (fMonitoredClk mul_by (1000U minus CLOCK_IP_CMU_MONITORED_CLOCK_VARIATION)) divide_by (fReferenceClk mul_by (1000U plus CLOCK_IP_CMU_REFERENCE_CLOCK_VARIATION)) minus CLOCK_IP_CMU_FC_VAR */
            LfRef = MonitoredClk * (1000U - CLOCK_IP_CMU_MONITORED_CLOCK_VARIATION) * RefCount;
            DivideBy = ReferenceClk * (1000U + CLOCK_IP_CMU_REFERENCE_CLOCK_VARIATION);
            DividerResult = (uint32) LfRef / DivideBy;
            ModuloValue = LfRef - (DivideBy * DividerResult);
            LfRef = (DividerResult * CLOCK_IP_CMU_REFERENCE_COUNTER_MINIMUM_VALUE_MULTIPLIER) + ((uint32)((ModuloValue * CLOCK_IP_CMU_REFERENCE_COUNTER_MINIMUM_VALUE_MULTIPLIER) / DivideBy)) - CLOCK_IP_CMU_FC_VAR;


            /* Set reference counter */
            CmuFc->RCCR = RefCount * CLOCK_IP_CMU_REFERENCE_COUNTER_MINIMUM_VALUE_MULTIPLIER;

            /* Set high limit */
            CmuFc->HTCR = HfRef;

            /* Set low limit */
            CmuFc->LTCR = LfRef;
        }
    }

    /* Enable/disable interrupts */
    CmuFc->IER = Config->Interrupt;
}
#endif

static void Clock_Ip_ClearStatusCmuFcFceRefCntLfrefHfref(Clock_Ip_NameType Name)
{
    const Clock_Ip_CmuInfoType * CmuInformation = &Clock_Ip_axCmuInfo[Clock_Ip_au8ClockFeatures[Name][CLOCK_IP_CMU_INDEX]];
    Clock_Ip_ClockMonitorType* const CmuFc    = CmuInformation->CmuInstance;

    uint32 CmuIsrValue;

    /* Read flags */
    CmuIsrValue = CmuFc->SR & CLOCK_IP_CMU_ISR_MASK;

    /* Clear flags */
    CmuFc->SR = CmuIsrValue;
}

static Clock_Ip_CmuStatusType Clock_Ip_GetStatusCmuFcFceRefCntLfrefHfref(Clock_Ip_NameType Name)
{
    const Clock_Ip_CmuInfoType * CmuInformation = &Clock_Ip_axCmuInfo[Clock_Ip_au8ClockFeatures[Name][CLOCK_IP_CMU_INDEX]];
    const Clock_Ip_ClockMonitorType* CmuFc    = CmuInformation->CmuInstance;

    Clock_Ip_CmuStatusType Status   = CLOCK_IP_CMU_STATUS_UNDEFINED;
    uint32 CmuIerValue;
    uint32 CmuIsrValue;


    /* Read flags */
    CmuIsrValue = CmuFc->SR & CLOCK_IP_CMU_ISR_MASK;

    /* Read interrupt enable */
    CmuIerValue = CmuFc->IER & CLOCK_IP_CMU_ISR_MASK;

    CmuIsrValue = CmuIsrValue & CmuIerValue;


    /* Gheck flash if frequency check is enabled */
    if (CLOCK_IP_CMU_FREQUENCY_CHECK_ENABLED == (CmuFc->GCR & CMU_FC_GCR_FCE_MASK))
    {
        if ( ( CMU_FC_SR_FHH_MASK == (CmuIsrValue & CMU_FC_SR_FHH_MASK) ) )
        {
            Status = CLOCK_IP_CMU_HIGH_FREQ;
        }
        else if ( CMU_FC_SR_FLL_MASK == (CmuIsrValue & CMU_FC_SR_FLL_MASK) )
        {
            Status = CLOCK_IP_CMU_LOW_FREQ;
        }
        else
        {
            Status = CLOCK_IP_CMU_IN_RANGE;
        }
    }

    return Status;

}
static void Clock_Ip_EnableCmuFcFceRefCntLfrefHfref(Clock_Ip_CmuConfigType const* Config)
{
    const Clock_Ip_CmuInfoType *CmuInformation  = &Clock_Ip_axCmuInfo[Clock_Ip_au8ClockFeatures[Config->Name][CLOCK_IP_CMU_INDEX]];
    Clock_Ip_ClockMonitorType* const CmuFc    = CmuInformation->CmuInstance;

    /* Enable cmu */
    if (Config->Enable != 0U)
    {
        CmuFc->GCR |= CMU_FC_GCR_FCE_MASK;
    }
    else
    {
        CmuFc->GCR &= ~CMU_FC_GCR_FCE_MASK;
    }
}

#endif

/*==================================================================================================
*                                        GLOBAL FUNCTIONS
==================================================================================================*/
#if CLOCK_IP_CMU_INSTANCES_ARRAY_SIZE > 0U

uint32 Clock_Ip_CMU_GetInterruptStatus(uint8 IndexCmu)
{
    uint32 CmuIsrValue;

    /* Read flags */
    CmuIsrValue = Clock_Ip_apxCmu[IndexCmu]->SR & CLOCK_IP_CMU_ISR_MASK;
    return CmuIsrValue;
}

/**
* @brief        This function clear the CMU interrupt flag from CMU module.
* @details      Called by RGM ISR routine when a user notification for CMU FCCU events is configured
*
* @return       void
*
* @implements Clock_Ip_CMU_ClockFailInt_Activity
*
*/
void Clock_Ip_CMU_ClockFailInt(void)
{
    uint32 CmuIerValue;
    uint32 CmuIsrValue;
    uint32 IndexCmu;

    for (IndexCmu = 0U; IndexCmu < CLOCK_IP_CMU_INSTANCES_ARRAY_SIZE; IndexCmu++)
    {
        /* Read flags */
        CmuIsrValue = Clock_Ip_apxCmu[IndexCmu]->SR & CLOCK_IP_CMU_ISR_MASK;

        /* Clear status flag */
        Clock_Ip_apxCmu[IndexCmu]->SR = CmuIsrValue;

        /* Check whether driver is initialized */
        if(NULL_PTR != Clock_Ip_pxConfig)
        {
            /* Read interrupt enable */
            CmuIerValue = Clock_Ip_apxCmu[IndexCmu]->IER & CLOCK_IP_CMU_ISR_MASK;

            /* Filter all interrupts that are not enabled from cmuIsrValue */
            CmuIsrValue = CmuIsrValue & CmuIerValue;

            /* If at least one interrupt has been triggered */
            if (CmuIsrValue != 0U)
            {
#ifdef CLOCK_IP_CMU_FCCU_NOTIFICATION
                CLOCK_IP_CMU_FCCU_NOTIFICATION(Clock_Ip_aeCmuNames[IndexCmu]);
#else
                Clock_Ip_ReportClockErrors(CLOCK_IP_CMU_ERROR, Clock_Ip_aeCmuNames[IndexCmu]);
#endif
            }
        }
    }

}
#endif



/* Clock stop section code */
#define MCU_STOP_SEC_CODE

#include "Mcu_MemMap.h"

/*==================================================================================================
*                                        GLOBAL CONSTANTS
==================================================================================================*/

/* Clock start constant section data */
#define MCU_START_SEC_CONST_UNSPECIFIED

#include "Mcu_MemMap.h"

const Clock_Ip_ClockMonitorCallbackType Clock_Ip_axCmuCallbacks[CLOCK_IP_CMU_CALLBACKS_COUNT] =
{
    {
        Clock_Ip_ClockMonitorEmpty,                /* Reset */
        Clock_Ip_ClockMonitorEmpty_Set,            /* Set */
        Clock_Ip_ClockMonitorEmpty_Disable,        /* Disable */
        Clock_Ip_ClockMonitorEmpty_ClearStatus,    /* Clear */
        Clock_Ip_ClockMonitorEmpty_GetStatus,      /* Get status */
        Clock_Ip_ClockMonitorEmpty,                /* Enable */
    },
#ifdef CLOCK_IP_CMU_FC_FCE_REF_CNT_LFREF_HFREF
    {
        Clock_Ip_ResetCmuFcFceRefCntLfrefHfref,          /* Reset */
#if (defined(CLOCK_IP_REGISTER_VALUES_OPTIMIZATION) && (CLOCK_IP_REGISTER_VALUES_OPTIMIZATION == STD_ON))
        Clock_Ip_SetClockMonitorRegisterValues,          /* Set */
#else
        Clock_Ip_SetCmuFcFceRefCntLfrefHfref,            /* Set */
#endif    
        Clock_Ip_DisableCmuFcFceRefCntLfrefHfref,        /* Disable */
        Clock_Ip_ClearStatusCmuFcFceRefCntLfrefHfref,    /* Clear */
        Clock_Ip_GetStatusCmuFcFceRefCntLfrefHfref,      /* Get status */
        Clock_Ip_EnableCmuFcFceRefCntLfrefHfref,         /* Enable */
    },
#endif


};

/* Clock stop constant section data */
#define MCU_STOP_SEC_CONST_UNSPECIFIED

#include "Mcu_MemMap.h"


#ifdef __cplusplus
}
#endif

/** @} */

