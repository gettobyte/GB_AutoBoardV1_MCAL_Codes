/*==================================================================================================
*   Project              : RTD AUTOSAR 4.7
*   Platform             : CORTEXM
*   Peripheral           : 
*   Dependencies         : none
*
*   Autosar Version      : 4.7.0
*   Autosar Revision     : ASR_REL_4_7_REV_0000
*   Autosar Conf.Variant :
*   SW Version           : 4.0.0
*   Build Version        : S32K3_RTD_4_0_0_D2311_ASR_REL_4_7_REV_0000_20231128
*
*   Copyright 2020 - 2023 NXP
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
*   @addtogroup IntCtrl_Ip
*   @{
*/

/*==================================================================================================
*                                        INCLUDE FILES
==================================================================================================*/

#include "IntCtrl_Ip.h"
#include "Mcal.h"
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define CDD_PLATFORM_INTCTRL_IP_VENDOR_ID_C                          43
#define CDD_PLATFORM_INTCTRL_IP_AR_RELEASE_MAJOR_VERSION_C           4
#define CDD_PLATFORM_INTCTRL_IP_AR_RELEASE_MINOR_VERSION_C           7
#define CDD_PLATFORM_INTCTRL_IP_AR_RELEASE_REVISION_VERSION_C        0
#define CDD_PLATFORM_INTCTRL_IP_SW_MAJOR_VERSION_C                   4
#define CDD_PLATFORM_INTCTRL_IP_SW_MINOR_VERSION_C                   0
#define CDD_PLATFORM_INTCTRL_IP_SW_PATCH_VERSION_C                   0
/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and IntCtrl_Ip header file are of the same vendor */
#if (CDD_PLATFORM_INTCTRL_IP_VENDOR_ID_C != CDD_PLATFORM_INTCTRL_IP_VENDOR_ID)
    #error "IntCtrl_Ip.c and IntCtrl_Ip.h have different vendor ids"
#endif
/* Check if current file and Fls header file are of the same Software version */
#if ((CDD_PLATFORM_INTCTRL_IP_AR_RELEASE_MAJOR_VERSION_C != CDD_PLATFORM_INTCTRL_IP_AR_RELEASE_MAJOR_VERSION) || \
     (CDD_PLATFORM_INTCTRL_IP_AR_RELEASE_MINOR_VERSION_C != CDD_PLATFORM_INTCTRL_IP_AR_RELEASE_MINOR_VERSION) || \
     (CDD_PLATFORM_INTCTRL_IP_AR_RELEASE_REVISION_VERSION_C != CDD_PLATFORM_INTCTRL_IP_AR_RELEASE_REVISION_VERSION) \
    )
    #error "Software Version Numbers of IntCtrl_Ip.c and IntCtrl_Ip.h are different"
#endif
/* Check if current file and Fls header file are of the same Software version */
#if ((CDD_PLATFORM_INTCTRL_IP_SW_MAJOR_VERSION_C != CDD_PLATFORM_INTCTRL_IP_SW_MAJOR_VERSION) || \
     (CDD_PLATFORM_INTCTRL_IP_SW_MINOR_VERSION_C != CDD_PLATFORM_INTCTRL_IP_SW_MINOR_VERSION) || \
     (CDD_PLATFORM_INTCTRL_IP_SW_PATCH_VERSION_C != CDD_PLATFORM_INTCTRL_IP_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of IntCtrl_Ip.c and IntCtrl_Ip.h are different"
#endif

/*==================================================================================================
*                                       GLOBAL VARIABLES
==================================================================================================*/

#if defined(S32K3XX) || defined(SAF85) || defined(S32R41) || defined(S32NZ5X)
extern uint32 __RAM_INTERRUPT_START[1U];
#else
extern uint32 __INT_SRAM_START[1U];
#endif


/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/
#if ((STD_ON == INTCTRL_PLATFORM_ENABLE_USER_MODE_SUPPORT) && (defined (MCAL_ENABLE_USER_MODE_SUPPORT)))
    #define Call_IntCtrl_Ip_InstallHandlerPrivileged(eIrqNumber,pfNewHandler,pfOldHandler)  \
                OsIf_Trusted_Call3params(IntCtrl_Ip_InstallHandlerPrivileged,(eIrqNumber),(pfNewHandler),(pfOldHandler))
    #define Call_IntCtrl_Ip_EnableIrqPrivileged(eIrqNumber)  \
                OsIf_Trusted_Call1param(IntCtrl_Ip_EnableIrqPrivileged,(eIrqNumber))
    #define Call_IntCtrl_Ip_DisableIrqPrivileged(eIrqNumber)  \
                OsIf_Trusted_Call1param(IntCtrl_Ip_DisableIrqPrivileged,(eIrqNumber))
    #define Call_IntCtrl_Ip_SetPriorityPrivileged(eIrqNumber,u8Priority)  \
                OsIf_Trusted_Call2params(IntCtrl_Ip_SetPriorityPrivileged,(eIrqNumber),(u8Priority))
    #define Call_IntCtrl_Ip_GetPriorityPrivileged(eIrqNumber)  \
                OsIf_Trusted_Call_Return1param(IntCtrl_Ip_GetPriorityPrivileged,(eIrqNumber))
    #define Call_IntCtrl_Ip_ClearPendingPrivileged(eIrqNumber)  \
                OsIf_Trusted_Call1param(IntCtrl_Ip_ClearPendingPrivileged,(eIrqNumber))
#if (INT_CTRL_IP_STANDALONE_APIS == STD_ON)
    #define Call_IntCtrl_Ip_SetPendingPrivileged(eIrqNumber)  \
                OsIf_Trusted_Call1param(IntCtrl_Ip_SetPendingPrivileged,(eIrqNumber))
    #define Call_IntCtrl_Ip_GetPendingPrivileged(eIrqNumber)  \
                OsIf_Trusted_Call_Return1param(IntCtrl_Ip_GetPendingPrivileged,(eIrqNumber))
#if ((INT_CTRL_IP_CORTEXM == STD_ON) && (INT_CTRL_IP_CORTEXM0PLUS == STD_OFF))
    #define Call_IntCtrl_Ip_GetActivePrivileged(eIrqNumber)  \
                OsIf_Trusted_Call_Return1param(IntCtrl_Ip_GetActivePrivileged,(eIrqNumber))
#endif
#endif
#if (INT_CTRL_IP_MSI_AVAILABLE == STD_ON)
    #define Call_IntCtrl_Ip_GenerateDirectedCpuInterruptPrivileged(eIrqNumber,eCpuTarget)  \
                OsIf_Trusted_Call2params(IntCtrl_Ip_GenerateDirectedCpuInterruptPrivileged,(eIrqNumber),(eCpuTarget))
    #define Call_IntCtrl_Ip_ClearDirectedCpuInterruptPrivileged(eIrqNumber)  \
                OsIf_Trusted_Call1param(IntCtrl_Ip_ClearDirectedCpuInterruptPrivileged,(eIrqNumber))
    #define Call_IntCtrl_Ip_GetDirectedCpuInterruptPrivileged(eIrqNumber)  \
                OsIf_Trusted_Call_Return1param(IntCtrl_Ip_GetDirectedCpuInterruptPrivileged,(eIrqNumber))
#endif
#else /*STD_ON == INTCTRL_PLATFORM_ENABLE_USER_MODE_SUPPORT*/
    #define Call_IntCtrl_Ip_InstallHandlerPrivileged(eIrqNumber,pfNewHandler,pfOldHandler)  \
                IntCtrl_Ip_InstallHandlerPrivileged((eIrqNumber),(pfNewHandler),(pfOldHandler))
    #define Call_IntCtrl_Ip_EnableIrqPrivileged(eIrqNumber)  \
                IntCtrl_Ip_EnableIrqPrivileged((eIrqNumber))
    #define Call_IntCtrl_Ip_DisableIrqPrivileged(eIrqNumber)  \
                IntCtrl_Ip_DisableIrqPrivileged((eIrqNumber))
    #define Call_IntCtrl_Ip_SetPriorityPrivileged(eIrqNumber,u8Priority)  \
                IntCtrl_Ip_SetPriorityPrivileged((eIrqNumber),(u8Priority))
    #define Call_IntCtrl_Ip_GetPriorityPrivileged(eIrqNumber)  \
                IntCtrl_Ip_GetPriorityPrivileged((eIrqNumber))
    #define Call_IntCtrl_Ip_ClearPendingPrivileged(eIrqNumber)  \
                IntCtrl_Ip_ClearPendingPrivileged((eIrqNumber))

#if (INT_CTRL_IP_STANDALONE_APIS == STD_ON)
    #define Call_IntCtrl_Ip_SetPendingPrivileged(eIrqNumber)  \
                IntCtrl_Ip_SetPendingPrivileged((eIrqNumber))
    #define Call_IntCtrl_Ip_GetPendingPrivileged(eIrqNumber)  \
                IntCtrl_Ip_GetPendingPrivileged((eIrqNumber))
#if ((INT_CTRL_IP_CORTEXM == STD_ON) && (INT_CTRL_IP_CORTEXM0PLUS == STD_OFF))
    #define Call_IntCtrl_Ip_GetActivePrivileged(eIrqNumber)  \
                IntCtrl_Ip_GetActivePrivileged((eIrqNumber))
#endif
#endif
#if (INT_CTRL_IP_MSI_AVAILABLE == STD_ON)
    #define Call_IntCtrl_Ip_GenerateDirectedCpuInterruptPrivileged(eIrqNumber,eCpuTarget)  \
                IntCtrl_Ip_GenerateDirectedCpuInterruptPrivileged((eIrqNumber),(eCpuTarget))
    #define Call_IntCtrl_Ip_ClearDirectedCpuInterruptPrivileged(eIrqNumber)  \
                IntCtrl_Ip_ClearDirectedCpuInterruptPrivileged(eIrqNumber)
    #define Call_IntCtrl_Ip_GetDirectedCpuInterruptPrivileged(eIrqNumber)  \
                IntCtrl_Ip_GetDirectedCpuInterruptPrivileged(eIrqNumber)
#endif
#endif /*STD_ON == INTCTRL_PLATFORM_ENABLE_USER_MODE_SUPPORT*/

#define PLATFORM_START_SEC_CODE
#include "Platform_MemMap.h"
void IntCtrl_Ip_InstallHandlerPrivileged(IRQn_Type eIrqNumber,
                               const IntCtrl_Ip_IrqHandlerType pfNewHandler,
                               IntCtrl_Ip_IrqHandlerType* const pfOldHandler);
void IntCtrl_Ip_EnableIrqPrivileged(IRQn_Type eIrqNumber);
void IntCtrl_Ip_DisableIrqPrivileged(IRQn_Type eIrqNumber);
void IntCtrl_Ip_SetPriorityPrivileged(IRQn_Type eIrqNumber, uint8 u8Priority);
uint8 IntCtrl_Ip_GetPriorityPrivileged(IRQn_Type eIrqNumber);
void IntCtrl_Ip_ClearPendingPrivileged(IRQn_Type eIrqNumber);


#if (INT_CTRL_IP_STANDALONE_APIS == STD_ON)
void IntCtrl_Ip_SetPendingPrivileged(IRQn_Type eIrqNumber);
uint32 IntCtrl_Ip_GetPendingPrivileged(IRQn_Type eIrqNumber);
#if ((INT_CTRL_IP_CORTEXM == STD_ON) && (INT_CTRL_IP_CORTEXM0PLUS == STD_OFF))
uint32 IntCtrl_Ip_GetActivePrivileged(IRQn_Type eIrqNumber);
#endif
#endif
#if (INT_CTRL_IP_MSI_AVAILABLE == STD_ON)
void IntCtrl_Ip_GenerateDirectedCpuInterruptPrivileged(IRQn_Type eIrqNumber, IntCtrl_Ip_IrqTargetType eCpuTarget);
void IntCtrl_Ip_ClearDirectedCpuInterruptPrivileged(IRQn_Type eIrqNumber);
uint32 IntCtrl_Ip_GetDirectedCpuInterruptPrivileged(IRQn_Type eIrqNumber);
#endif

void IntCtrl_Ip_InstallHandlerPrivileged(IRQn_Type eIrqNumber,
                               const IntCtrl_Ip_IrqHandlerType pfNewHandler,
                               IntCtrl_Ip_IrqHandlerType* const pfOldHandler)
{
#if (INT_CTRL_IP_DEV_ERROR_DETECT == STD_ON)
    /* Check IRQ number - dev_irqNumber is used to avoid compiler warning */
    sint32 dev_irqNumber = (sint32)eIrqNumber;
    DevAssert((sint32)INT_CTRL_IP_IRQ_MIN <= dev_irqNumber);
    DevAssert(dev_irqNumber <= (sint32)INT_CTRL_IP_IRQ_MAX);
#if (MCAL_PLATFORM_ARM == MCAL_ARM_MARCH)
#if defined(S32K3XX) || defined(SAF85) || defined(S32R41) || defined(S32NZ5X)
    DevAssert(S32_SCB->VTOR >= (uint32)__RAM_INTERRUPT_START);
#else
    DevAssert(S32_SCB->VTOR >= (uint32)__INT_SRAM_START);
#endif
#endif /* (MCAL_PLATFORM_ARM == MCAL_ARM_MARCH) */
#endif /*(INT_CTRL_IP_DEV_ERROR_DETECT == STD_ON) */

#if ((INT_CTRL_IP_CORTEXR == STD_ON) || (INT_CTRL_IP_CORTEXA == STD_ON))
    
    OsIf_SuspendAllInterrupts();
    extern uint32 VTABLE[INT_CTRL_IP_IRQ_MAX + 1U];
#if (defined(INT_CTRL_CORE_SPECIFIC_VTABLE) && (INT_CTRL_CORE_SPECIFIC_VTABLE == STD_ON))
    IntCtrl_Ip_IrqHandlerType *pVectorRam = (IntCtrl_Ip_IrqHandlerType *)VTABLE[OsIf_GetCoreID()];
#else
    IntCtrl_Ip_IrqHandlerType *pVectorRam = (IntCtrl_Ip_IrqHandlerType *)VTABLE;
#endif
        /* Save the former handler pointer */
    if (pfOldHandler != NULL_PTR)
    {
        *pfOldHandler = (IntCtrl_Ip_IrqHandlerType)pVectorRam[((uint32)eIrqNumber)];
    }

    /* Set handler into vector table */
    pVectorRam[((sint32)eIrqNumber)] = pfNewHandler;
    OsIf_ResumeAllInterrupts();
#else
    IntCtrl_Ip_IrqHandlerType *pVectorRam = (IntCtrl_Ip_IrqHandlerType *)S32_SCB->VTOR;

    /* Save the former handler pointer */
    if (pfOldHandler != NULL_PTR)
    {
        *pfOldHandler = (IntCtrl_Ip_IrqHandlerType)pVectorRam[((sint32)eIrqNumber) + 16];
    }

    /* Set handler into vector table */
    pVectorRam[((sint32)eIrqNumber) + 16] = pfNewHandler;
#if (INT_CTRL_IP_INVALIDATE_CACHE == STD_ON)
    /* Invalidate ICache */
    S32_SCB->ICIALLU = 0UL;
#endif
    
#endif /* (INT_CTRL_IP_CORTEXR == STD_ON) || (INT_CTRL_IP_CORTEXA == STD_ON) */
/*LDRA_NOANALYSIS*/
    MCAL_INSTRUCTION_SYNC_BARRIER();
    MCAL_DATA_SYNC_BARRIER();
/*LDRA_ANALYSIS*/    
}

void IntCtrl_Ip_EnableIrqPrivileged(IRQn_Type eIrqNumber)
{

#if (INT_CTRL_IP_DEV_ERROR_DETECT == STD_ON)
    /* Check IRQ number - dev_irqNumber is used to avoid compiler warning */
    DevAssert(0 <= (sint32)eIrqNumber);
    DevAssert((sint32)eIrqNumber <= (sint32)INT_CTRL_IP_IRQ_MAX);
#endif /*(INT_CTRL_IP_DEV_ERROR_DETECT == STD_ON) */
    /* Enable interrupt */
#if ((INT_CTRL_IP_CORTEXR == STD_ON) || (INT_CTRL_IP_CORTEXA == STD_ON))
#if (MCAL_PLATFORM_ARM == MCAL_ARM_AARCH64)
    S32_GICD->GICD_ISENABLER[((uint32)(eIrqNumber) >> 5U)] = (uint32)(1UL << ((uint32)(eIrqNumber) & (uint32)0x1FU));
#else
    uint32 cpuId;
    if ((uint32)(eIrqNumber) < GIC500_MIN_SPI_ID)
    {
        cpuId = IntCtrl_Ip_gic500_convertAffinityToLinearId(IntCtrl_Ip_read_MPIDR());
#if (INT_CTRL_IP_DEV_ERROR_DETECT == STD_ON)
        DevAssert(GIC500_CPU_COUNT > cpuId);
#endif /*(INT_CTRL_IP_DEV_ERROR_DETECT == STD_ON) */
        IP_GIC500->CPU[cpuId].GICR_SGII.ISENABLER0 = (uint32)(1UL << ((uint32)(eIrqNumber) & (uint32)0x1FU));
    }
    else
    {
        S32_GICD->GICD_ISENABLER[((uint32)(eIrqNumber) >> 5U) - 1U] = (uint32)(1UL << ((uint32)(eIrqNumber) & (uint32)0x1FU));
    }
#endif
#else
    S32_NVIC->ISER[(uint32)(eIrqNumber) >> 5U] = (uint32)(1UL << ((uint32)(eIrqNumber) & (uint32)0x1FU));
#endif
}

void IntCtrl_Ip_DisableIrqPrivileged(IRQn_Type eIrqNumber)
{
#if (INT_CTRL_IP_DEV_ERROR_DETECT == STD_ON)
    /* Check IRQ number - dev_irqNumber is used to avoid compiler warning */
    DevAssert(0 <= (sint32)eIrqNumber);
    DevAssert((sint32)eIrqNumber <= (sint32)INT_CTRL_IP_IRQ_MAX);
#endif /*(INT_CTRL_IP_DEV_ERROR_DETECT == STD_ON) */
    /* Disable interrupt */
#if ((INT_CTRL_IP_CORTEXR == STD_ON) || (INT_CTRL_IP_CORTEXA == STD_ON))
#if (MCAL_PLATFORM_ARM == MCAL_ARM_AARCH64)
    /* Disable interrupt */
    S32_GICD->GICD_ICENABLER[((uint32)(eIrqNumber) >> 5U)] = (uint32)(1UL << ((uint32)(eIrqNumber) & (uint32)0x1FU));
#else
    uint32 cpuId;
    /* Disable interrupt */
    if ((uint32)(eIrqNumber) < GIC500_MIN_SPI_ID)
    {
        cpuId = IntCtrl_Ip_gic500_convertAffinityToLinearId(IntCtrl_Ip_read_MPIDR());
#if (INT_CTRL_IP_DEV_ERROR_DETECT == STD_ON)
        DevAssert(GIC500_CPU_COUNT > cpuId);
#endif /*(INT_CTRL_IP_DEV_ERROR_DETECT == STD_ON) */
        IP_GIC500->CPU[cpuId].GICR_SGII.ICENABLER0 = (uint32)(1UL << ((uint32)(eIrqNumber) & (uint32)0x1FU));
    }
    else
    {
        S32_GICD->GICD_ICENABLER[((uint32)(eIrqNumber) >> 5U) - 1U] = (uint32)(1UL << ((uint32)(eIrqNumber) & (uint32)0x1FU));
    }
#endif
#else
    S32_NVIC->ICER[(uint32)(eIrqNumber) >> 5U] = (uint32)(1UL << ((uint32)(eIrqNumber) & (uint32)0x1FU));
#endif
}

void IntCtrl_Ip_SetPriorityPrivileged(IRQn_Type eIrqNumber, uint8 u8Priority)
{

#if (INT_CTRL_IP_DEV_ERROR_DETECT == STD_ON)

    /* Check IRQ number and priority - dev_irqNumber is used to avoid compiler warning */
    DevAssert((sint32)INT_CTRL_IP_IRQ_MIN <= (sint32)eIrqNumber);
    DevAssert((sint32)eIrqNumber <= (sint32)INT_CTRL_IP_IRQ_MAX);
#if (INT_CTRL_IP_CORTEXM == STD_ON)
    DevAssert(u8Priority < (uint8)(1U << INT_CTRL_IP_NVIC_PRIO_BITS));
#else
    DevAssert(u8Priority < (uint8)(1U << INT_CTRL_IP_GIC_PRIO_BITS));
#endif

#endif /* (INT_CTRL_IP_DEV_ERROR_DETECT == STD_ON) */

#if (INT_CTRL_IP_CORTEXM == STD_ON)
    uint8 shift = (uint8) (8U - INT_CTRL_IP_NVIC_PRIO_BITS);
    #if (INT_CTRL_IP_CORTEXM0PLUS == STD_OFF)
        /* Set Priority for device specific Interrupts */
        S32_NVIC->IP[(uint32)(eIrqNumber)] = (uint8)((((uint32)u8Priority) << shift) & 0xFFUL);
    #else
        uint32 iprVectorId = (uint32)(eIrqNumber) >> 2U;
        uint8 priByteShift = (uint8)((((uint8)eIrqNumber) & 0x3U) << 3U);

        /* Clear the old value from the register */
        S32_NVIC->IP[iprVectorId] &= ~(0xFFUL << priByteShift);

        S32_NVIC->IP[iprVectorId] |= ((uint32)(((((uint32)u8Priority) << shift)) & 0xFFUL)) << priByteShift;
    #endif
#elif ((INT_CTRL_IP_CORTEXR == STD_ON) || (INT_CTRL_IP_CORTEXA == STD_ON))
    uint8 shift_gic = (uint8) (8U - INT_CTRL_IP_GIC_PRIO_BITS);
    #if (MCAL_PLATFORM_ARM == MCAL_ARM_AARCH64)
        uint32 iprVectorId = ((uint32)(eIrqNumber) >> 2U);
        uint8 priByteShift = (uint8)((((uint8)eIrqNumber) & 0x3U) << 3U);
        /* Clear the old value from the register */
        S32_GICD->GICD_IPRIORITYR[iprVectorId] &= ~(0xFFUL << priByteShift);
        S32_GICD->GICD_IPRIORITYR[iprVectorId] |= ((uint32)(((((uint32)u8Priority) << shift_gic)) & 0xFFUL)) << priByteShift;
    #else
        uint32 cpuId;
        if ((uint32)(eIrqNumber) < GIC500_MIN_SPI_ID)
        {
            uint32 iprVectorId = ((uint32)(eIrqNumber) >> 2U);
            uint8 priByteShift = (uint8)((((uint8)eIrqNumber) & 0x3U) << 3U);
            cpuId = IntCtrl_Ip_gic500_convertAffinityToLinearId(IntCtrl_Ip_read_MPIDR());
#if (INT_CTRL_IP_DEV_ERROR_DETECT == STD_ON)
            DevAssert(GIC500_CPU_COUNT > cpuId);
#endif /*(INT_CTRL_IP_DEV_ERROR_DETECT == STD_ON) */
            IP_GIC500->CPU[cpuId].GICR_SGII.IPRIORITYR[iprVectorId] &= ~(0xFFUL << priByteShift);
            IP_GIC500->CPU[cpuId].GICR_SGII.IPRIORITYR[iprVectorId] |= ((uint32)(((((uint32)u8Priority) << shift_gic)) & 0xFFUL)) << priByteShift;
        }
        else
        {
            uint32 iprVectorId = ((uint32)(eIrqNumber) >> 2U);
            uint8 priByteShift = (uint8)((((uint8)eIrqNumber) & 0x3U) << 3U);
            /* Clear the old value from the register */
            IP_GIC500->GICD.IPRIORITYR[iprVectorId] &= ~(0xFFUL << priByteShift);
            IP_GIC500->GICD.IPRIORITYR[iprVectorId] |= ((uint32)(((((uint32)u8Priority) << shift_gic)) & 0xFFUL)) << priByteShift;
        }
    #endif
#endif
}

uint8 IntCtrl_Ip_GetPriorityPrivileged(IRQn_Type eIrqNumber)
{
#if (INT_CTRL_IP_DEV_ERROR_DETECT == STD_ON)

    /* Check IRQ number */
    DevAssert(INT_CTRL_IP_IRQ_MIN <= eIrqNumber);
    DevAssert((sint32)eIrqNumber <= (sint32)INT_CTRL_IP_IRQ_MAX);

#endif /*(INT_CTRL_IP_DEV_ERROR_DETECT == STD_ON) */

    uint8 priority=0;


#if (INT_CTRL_IP_CORTEXM == STD_ON)
    uint8 shift = (uint8)(8U - INT_CTRL_IP_NVIC_PRIO_BITS);
    #if (INT_CTRL_IP_CORTEXM0PLUS == STD_OFF)
        /* Get Priority for device specific Interrupts  */
        priority = (uint8)(S32_NVIC->IP[(uint32)(eIrqNumber)] >> shift);
    #else
        uint32 iprVectorId = (uint32)(eIrqNumber) >> 2U;
        uint8 priByteShift = (uint8)((((uint8)(eIrqNumber)) & 0x3U) << 3U);
        priority = ((uint8)(S32_NVIC->IP[iprVectorId] >> priByteShift)) >> shift;
    #endif
#elif ((INT_CTRL_IP_CORTEXR == STD_ON) || (INT_CTRL_IP_CORTEXA == STD_ON))
    uint8 shift_gic = (uint8) (8U - INT_CTRL_IP_GIC_PRIO_BITS);
    #if (MCAL_PLATFORM_ARM == MCAL_ARM_AARCH64)
        uint32 iprVectorId = ((uint32)(eIrqNumber) >> 2U);
        uint8 priByteShift = (uint8)((((uint8)(eIrqNumber)) & 0x3U) << 3U);
        priority = ((uint8)(S32_GICD->GICD_IPRIORITYR[iprVectorId] >> priByteShift)) >> shift_gic;
    #else
        uint32 cpuId;
        if ((uint32)(eIrqNumber) < GIC500_MIN_SPI_ID)
        {
            uint32 iprVectorId = ((uint32)(eIrqNumber) >> 2U);
            uint8 priByteShift = (uint8)((((uint8)(eIrqNumber)) & 0x3U) << 3U);
            cpuId = IntCtrl_Ip_gic500_convertAffinityToLinearId(IntCtrl_Ip_read_MPIDR());
#if (INT_CTRL_IP_DEV_ERROR_DETECT == STD_ON)
            DevAssert(GIC500_CPU_COUNT > cpuId);
#endif /*(INT_CTRL_IP_DEV_ERROR_DETECT == STD_ON) */
            priority = ((uint8)(IP_GIC500->CPU[cpuId].GICR_SGII.IPRIORITYR[iprVectorId] >> priByteShift)) >> shift_gic;
        }
        else
        {
            uint32 iprVectorId = ((uint32)(eIrqNumber) >> 2U);
            uint8 priByteShift = (uint8)((((uint8)(eIrqNumber)) & 0x3U) << 3U);
            priority = ((uint8)(IP_GIC500->GICD.IPRIORITYR[iprVectorId] >> priByteShift)) >> shift_gic;
        }
    #endif
#endif
    return priority;
}

void IntCtrl_Ip_ClearPendingPrivileged(IRQn_Type eIrqNumber)
{

#if (INT_CTRL_IP_DEV_ERROR_DETECT == STD_ON)
    /* Check IRQ number */
    DevAssert(0 <= (sint32)eIrqNumber);
    DevAssert((sint32)eIrqNumber <= (sint32)INT_CTRL_IP_IRQ_MAX);
#endif /* (INT_CTRL_IP_DEV_ERROR_DETECT == STD_ON) */
#if ((INT_CTRL_IP_CORTEXR == STD_ON) || (INT_CTRL_IP_CORTEXA == STD_ON))
#if (MCAL_PLATFORM_ARM == MCAL_ARM_AARCH64)
    /* Clear Pending Interrupt */
    S32_GICD->GICD_ICPENDR[((uint32)(eIrqNumber) >> 5U)] = (uint32)(1UL << ((uint32)(eIrqNumber) & (uint32)0x1FU));
#else
    uint32 cpuId;
    /* Clear Pending Interrupt */
    if ((uint32)(eIrqNumber) < GIC500_MIN_SPI_ID)
    {
        cpuId = IntCtrl_Ip_gic500_convertAffinityToLinearId(IntCtrl_Ip_read_MPIDR());
#if (INT_CTRL_IP_DEV_ERROR_DETECT == STD_ON)
        DevAssert(GIC500_CPU_COUNT > cpuId);
#endif /*(INT_CTRL_IP_DEV_ERROR_DETECT == STD_ON) */
        IP_GIC500->CPU[cpuId].GICR_SGII.ICPENDR0 = (uint32)(1UL << ((uint32)(eIrqNumber) & (uint32)0x1FU));

    }
    else
    {
        S32_GICD->GICD_ICPENDR[((uint32)(eIrqNumber) >> 5U) - 1U] = (uint32)(1UL << ((uint32)(eIrqNumber) & (uint32)0x1FU));
    }
#endif

#else
    /* Clear Pending Interrupt */
    S32_NVIC->ICPR[(uint32)(eIrqNumber) >> 5U] = (uint32)(1UL << ((uint32)(eIrqNumber) & (uint32)0x1FU));
#endif

}


#if (INT_CTRL_IP_STANDALONE_APIS == STD_ON)
void IntCtrl_Ip_SetPendingPrivileged(IRQn_Type eIrqNumber)
{
#if (INT_CTRL_IP_DEV_ERROR_DETECT == STD_ON)
    /* Check IRQ number - dev_irqNumber is used to avoid compiler warning */
    DevAssert(0 <= (sint32)eIrqNumber);
    DevAssert(((sint32)eIrqNumber) <= (sint32)INT_CTRL_IP_IRQ_MAX);
#endif /*(INT_CTRL_IP_DEV_ERROR_DETECT == STD_ON) */
#if ((INT_CTRL_IP_CORTEXR == STD_ON) || (INT_CTRL_IP_CORTEXA == STD_ON))
#if (MCAL_PLATFORM_ARM == MCAL_ARM_AARCH64)
    /* Set Pending Interrupt */
    S32_GICD->GICD_ISPENDR[((uint32)(eIrqNumber) >> 5U)] = (uint32)(1UL << ((uint32)(eIrqNumber) & (uint32)0x1FU));
#else
    uint32 cpuId;
    /* Set Pending Interrupt */
    if ((uint32)(eIrqNumber) < GIC500_MIN_SPI_ID)
    {
        cpuId = IntCtrl_Ip_gic500_convertAffinityToLinearId(IntCtrl_Ip_read_MPIDR());
#if (INT_CTRL_IP_DEV_ERROR_DETECT == STD_ON)
        DevAssert(GIC500_CPU_COUNT > cpuId);
#endif /*(INT_CTRL_IP_DEV_ERROR_DETECT == STD_ON) */
        IP_GIC500->CPU[cpuId].GICR_SGII.ISPENDR0 = (uint32)(1UL << ((uint32)(eIrqNumber) & (uint32)0x1FU));
    }
    else
    {
        S32_GICD->GICD_ISPENDR[((uint32)(eIrqNumber) >> 5U) - 1U] = (uint32)(1UL << ((uint32)(eIrqNumber) & (uint32)0x1FU));
    }
#endif

#else
    /* Set Pending Interrupt */
    S32_NVIC->ISPR[(uint32)(eIrqNumber) >> 5U] = (uint32)(1UL << ((uint32)(eIrqNumber) & (uint32)0x1FU));
#endif

}

uint32 IntCtrl_Ip_GetPendingPrivileged(IRQn_Type eIrqNumber)
{
#if (INT_CTRL_IP_DEV_ERROR_DETECT == STD_ON)
    /* Check IRQ number */
    DevAssert(0 <= (sint32)eIrqNumber);
    DevAssert(((sint32)eIrqNumber) <= (sint32)INT_CTRL_IP_IRQ_MAX);
#endif /*(INT_CTRL_IP_DEV_ERROR_DETECT == STD_ON) */
    
#if ((INT_CTRL_IP_CORTEXR == STD_ON) || (INT_CTRL_IP_CORTEXA == STD_ON))
#if (MCAL_PLATFORM_ARM == MCAL_ARM_AARCH64)
/* Get Pending Interrupt */
    return ((((S32_GICD->GICD_ICPENDR[(((uint32)eIrqNumber) >> 5UL)] & (1UL << (((uint32)eIrqNumber) & 0x1FUL))) != 0UL) ? TRUE : FALSE));
#else
    uint32 cpuId;
    volatile uint32 result = 0;
/* Get Pending Interrupt */
    if ((uint32)(eIrqNumber) < GIC500_MIN_SPI_ID)
    {
        /* Convert internal linear ID in RTU */
        cpuId = IntCtrl_Ip_gic500_convertAffinityToLinearId(IntCtrl_Ip_read_MPIDR());
#if (INT_CTRL_IP_DEV_ERROR_DETECT == STD_ON)
        DevAssert(GIC500_CPU_COUNT > cpuId);
#endif /*(INT_CTRL_IP_DEV_ERROR_DETECT == STD_ON) */
        /* Get Pending Interrupt */
        result = (((IP_GIC500->CPU[cpuId].GICR_SGII.ISPENDR0 & (1UL << (((uint32)eIrqNumber) & 0x1FUL))) != 0UL) ? TRUE : FALSE);
    }
    else
    {
        /* Get Pending Interrupt */
        result =  ((((S32_GICD->GICD_ICPENDR[(((uint32)eIrqNumber) >> 5UL) - 1UL] & (1UL << (((uint32)eIrqNumber) & 0x1FUL))) != 0UL) ? TRUE : FALSE));
    }
    
    return result;
#endif

#else
    /* Get Pending Interrupt */
    return ((((S32_NVIC->ISPR[(((uint32)eIrqNumber) >> 5UL)] & (1UL << (((uint32)eIrqNumber) & 0x1FUL))) != 0UL) ? TRUE : FALSE));
#endif
}
#if ((INT_CTRL_IP_CORTEXM == STD_ON) && (INT_CTRL_IP_CORTEXM0PLUS == STD_OFF))
uint32 IntCtrl_Ip_GetActivePrivileged(IRQn_Type eIrqNumber)
{
#if (INT_CTRL_IP_DEV_ERROR_DETECT == STD_ON)
    /* Check IRQ number */
    DevAssert(0 <= (sint32)eIrqNumber);
    DevAssert(((sint32)eIrqNumber) <= (sint32)INT_CTRL_IP_IRQ_MAX);
#endif /*(INT_CTRL_IP_DEV_ERROR_DETECT == STD_ON) */
    /* Get Active Interrupt */
    return ((((S32_NVIC->IABR[(((uint32)eIrqNumber) >> 5UL)] & (1UL << (((uint32)eIrqNumber) & 0x1FUL))) != 0UL) ? TRUE : FALSE));
}
#endif
#endif /*#if (INT_CTRL_IP_STANDALONE_APIS == STD_ON)*/

#if (INT_CTRL_IP_MSI_AVAILABLE == STD_ON)

void IntCtrl_Ip_ClearDirectedCpuInterruptPrivileged(IRQn_Type eIrqNumber)
{
#if (INT_CTRL_IP_DEV_ERROR_DETECT == STD_ON)
    /* Check IRQ number */
    DevAssert(INT_CTRL_IP_DIRECTED_CPU_INT_MIN <= eIrqNumber);
    DevAssert(eIrqNumber <= INT_CTRL_IP_DIRECTED_CPU_INT_MAX);
#endif /* (INT_CTRL_IP_DEV_ERROR_DETECT == STD_ON) */

    uint32 currentCpu;
    uint32 irqId;

    currentCpu = MSCM_CPXNUM_CPN_MASK & (IP_MSCM->CPXNUM);
    irqId = (uint32)eIrqNumber - (uint32)INT_CTRL_IP_DIRECTED_CPU_INT_MIN;
    /* Clear Directed CPU Pending Interrupt */
    MSCM_IRCPnIRx->IRCPnIRx[currentCpu][irqId].IntStatusR = 0x7FU;

}

uint32 IntCtrl_Ip_GetDirectedCpuInterruptPrivileged(IRQn_Type eIrqNumber)
{
#if (INT_CTRL_IP_DEV_ERROR_DETECT == STD_ON)
    /* Check IRQ number */
    DevAssert(INT_CTRL_IP_DIRECTED_CPU_INT_MIN <= eIrqNumber);
    DevAssert(eIrqNumber <= INT_CTRL_IP_DIRECTED_CPU_INT_MAX);
#endif /*(INT_CTRL_IP_DEV_ERROR_DETECT == STD_ON) */


    uint32 currentCpu;
    uint32 irqId;

    currentCpu = MSCM_CPXNUM_CPN_MASK & (IP_MSCM->CPXNUM);
    irqId = (uint32)eIrqNumber - (uint32)INT_CTRL_IP_DIRECTED_CPU_INT_MIN;

    return ((MSCM_IRCPnIRx->IRCPnIRx[currentCpu][irqId].IntStatusR != 0U) ? TRUE : FALSE);
}


void IntCtrl_Ip_GenerateDirectedCpuInterruptPrivileged(IRQn_Type eIrqNumber, IntCtrl_Ip_IrqTargetType eCpuTarget)
{
#if (INT_CTRL_IP_DEV_ERROR_DETECT == STD_ON)
    /* Check IRQ number */
    DevAssert(INT_CTRL_IP_DIRECTED_CPU_INT_MIN <= eIrqNumber);
    DevAssert(eIrqNumber <= INT_CTRL_IP_DIRECTED_CPU_INT_MAX);
#endif

    uint32 irqId = (uint32)eIrqNumber - (uint32)INT_CTRL_IP_DIRECTED_CPU_INT_MIN;
    uint32 core;
    uint32 target;

    if (eCpuTarget == INTCTRL_IP_TARGET_OTHERS)
    {
        /* Add Fault Injection point for processor number */
        MCAL_FAULT_INJECTION_POINT(PLATFORM_CPN_ERROR_CPUINTERRUPT);
        for (core = 0U; core < INT_CTRL_IP_MSI_CORE_CNT; core++)
        {
            /* Generate a Directed CPU Interrupt to every other core */
            if (core != (MSCM_CPXNUM_CPN_MASK & (IP_MSCM->CPXNUM)))
            {
                MSCM_IRCPnIRx->IRCPnIRx[core][irqId].IGR = 0x1U;
            }
        }
    }
    else
    {
        if (eCpuTarget == INTCTRL_IP_TARGET_SELF)
        {
            target = MSCM_CPXNUM_CPN_MASK & (IP_MSCM->CPXNUM);
        }
        else
        {
            target = (uint32)eCpuTarget;
        }

        /* Generate Directed CPU Interrupt to target core */
        MSCM_IRCPnIRx->IRCPnIRx[target][irqId].IGR = 0x1U;
    }
}
#endif /* INT_CTRL_IP_MSI_AVAILABLE == STD_ON */
/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/





/**
 * @internal
 * @brief         Initializes the configured interrupts at interrupt controller level.
 * @implements    IntCtrl_Ip_Init_Activity
 */
IntCtrl_Ip_StatusType IntCtrl_Ip_Init(const IntCtrl_Ip_CtrlConfigType *pIntCtrlCtrlConfig)
{

#if (INT_CTRL_IP_ENABLE_VTOR_CONFIG == STD_ON)
    S32_SCB->VTOR = pIntCtrlCtrlConfig->u32VectorTableAddress;
#endif

#if (INT_CTRL_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(pIntCtrlCtrlConfig != NULL_PTR);
    DevAssert(pIntCtrlCtrlConfig->u32ConfigIrqCount <= INT_CTRL_IP_IRQ_COUNT);
#endif
    uint32 irqIdx;
    for (irqIdx = 0; irqIdx < pIntCtrlCtrlConfig->u32ConfigIrqCount; irqIdx++)
    {
        IntCtrl_Ip_ClearPending(pIntCtrlCtrlConfig->aIrqConfig[irqIdx].eIrqNumber);
        IntCtrl_Ip_SetPriority(pIntCtrlCtrlConfig->aIrqConfig[irqIdx].eIrqNumber,
                               pIntCtrlCtrlConfig->aIrqConfig[irqIdx].u8IrqPriority);

        /* Install the configured handler */
        IntCtrl_Ip_InstallHandler(pIntCtrlCtrlConfig->aIrqConfig[irqIdx].eIrqNumber,
                                  pIntCtrlCtrlConfig->aIrqConfig[irqIdx].pfHandler,
                                  NULL_PTR);

        if (pIntCtrlCtrlConfig->aIrqConfig[irqIdx].bIrqEnabled)
        {
            IntCtrl_Ip_EnableIrq(pIntCtrlCtrlConfig->aIrqConfig[irqIdx].eIrqNumber);
        }
        else
        {
            IntCtrl_Ip_DisableIrq(pIntCtrlCtrlConfig->aIrqConfig[irqIdx].eIrqNumber);
        }
    }

    return INTCTRL_IP_STATUS_SUCCESS;
}

/**
 * @internal
 * @brief         Installs a handler for an IRQ.
 * @implements    IntCtrl_Ip_InstallHandler_Activity
 */
void IntCtrl_Ip_InstallHandler(IRQn_Type eIrqNumber,
                               const IntCtrl_Ip_IrqHandlerType pfNewHandler,
                               IntCtrl_Ip_IrqHandlerType* const pfOldHandler)
{
    Call_IntCtrl_Ip_InstallHandlerPrivileged(eIrqNumber,pfNewHandler,pfOldHandler);
}

/**
 * @internal
 * @brief         Enables an interrupt request.
 * @implements    IntCtrl_Ip_EnableIrq_Activity
 */
void IntCtrl_Ip_EnableIrq(IRQn_Type eIrqNumber)
{
    Call_IntCtrl_Ip_EnableIrqPrivileged(eIrqNumber);
}

/**
 * @internal
 * @brief         Disables an interrupt request.
 * @implements    IntCtrl_Ip_DisableIrq_Activity
 */
void IntCtrl_Ip_DisableIrq(IRQn_Type eIrqNumber)
{
    Call_IntCtrl_Ip_DisableIrqPrivileged(eIrqNumber);
}

/**
 * @internal
 * @brief         Sets the priority for an interrupt request.
 * @implements    IntCtrl_Ip_SetPriority_Activity
 */
void IntCtrl_Ip_SetPriority(IRQn_Type eIrqNumber, uint8 u8Priority)
{
    Call_IntCtrl_Ip_SetPriorityPrivileged(eIrqNumber,u8Priority);
}

/**
 * @internal
 * @brief         Gets the priority for an interrupt request.
 * @implements    IntCtrl_Ip_GetPriority_Activity
 */
uint8 IntCtrl_Ip_GetPriority(IRQn_Type eIrqNumber)
{
    return (uint8)Call_IntCtrl_Ip_GetPriorityPrivileged(eIrqNumber);
}

/**
 * @internal
 * @brief         Clears the pending flag for an interrupt request.
 * @implements    IntCtrl_Ip_ClearPending_Activity
 */
void IntCtrl_Ip_ClearPending(IRQn_Type eIrqNumber)
{
    Call_IntCtrl_Ip_ClearPendingPrivileged(eIrqNumber);
}


#if (INT_CTRL_IP_STANDALONE_APIS == STD_ON)
/**
 * @internal
 * @brief         Sets the pending flag for an interrupt request.
 * @implements    IntCtrl_Ip_SetPending_Activity
 */
void IntCtrl_Ip_SetPending(IRQn_Type eIrqNumber)
{
    Call_IntCtrl_Ip_SetPendingPrivileged(eIrqNumber);
}

/**
 * @internal
 * @brief         Gets the pending flag for an interrupt request.
 * @implements    IntCtrl_Ip_GetPending_Activity
 */
boolean IntCtrl_Ip_GetPending(IRQn_Type eIrqNumber)
{
    /* Get Pending Interrupt */
    return (Call_IntCtrl_Ip_GetPendingPrivileged(eIrqNumber) > 0U)? TRUE : FALSE;
}


#if ((INT_CTRL_IP_CORTEXM == STD_ON) && (INT_CTRL_IP_CORTEXM0PLUS == STD_OFF))
/**
 * @internal
 * @brief         Gets the active flag for an interrupt request.
 * @implements    IntCtrl_Ip_GetActive_Activity
 */    
boolean IntCtrl_Ip_GetActive(IRQn_Type eIrqNumber)
{
    /*Gets the active flag for an interrupt request */
    return (Call_IntCtrl_Ip_GetActivePrivileged(eIrqNumber) > 0U)? TRUE : FALSE;
}
#endif
#endif /* INT_CTRL_IP_STANDALONE_APIS*/



#if (INT_CTRL_IP_MSI_AVAILABLE == STD_ON)
/**
 * @internal
 * @brief         Clear directed cpu Interrupt interrupt flag.
 * @implements    IntCtrl_Ip_ClearDirectedCpuInterruptPrivileged_Activity
 */
void IntCtrl_Ip_ClearDirectedCpuInterrupt(IRQn_Type eIrqNumber)
{
    Call_IntCtrl_Ip_ClearDirectedCpuInterruptPrivileged(eIrqNumber);
}
/**
 * @internal
 * @brief         Get directed cpu Interrupt interrupt flag.
 * @implements    IntCtrl_Ip_GetDirectedCpuInterrupt_Activity
 */
boolean IntCtrl_Ip_GetDirectedCpuInterrupt(IRQn_Type eIrqNumber)
{
    return (Call_IntCtrl_Ip_GetDirectedCpuInterruptPrivileged(eIrqNumber) > 0U)? TRUE : FALSE;
}
/**
 * @internal
 * @brief         Generates an interrupt request to a CPU target.
 * @implements    IntCtrl_Ip_GenerateDirectedCpuInterrupt_Activity
 */
void IntCtrl_Ip_GenerateDirectedCpuInterrupt(IRQn_Type eIrqNumber, IntCtrl_Ip_IrqTargetType eCpuTarget)
{
    Call_IntCtrl_Ip_GenerateDirectedCpuInterruptPrivileged(eIrqNumber,eCpuTarget);
}
#endif /* INT_CTRL_IP_MSI_AVAILABLE == STD_ON */
#define PLATFORM_STOP_SEC_CODE
#include "Platform_MemMap.h"

/** @} */
