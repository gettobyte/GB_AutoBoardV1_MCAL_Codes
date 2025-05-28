Creating summary for IntCtrl_Ip_SetTargetCores/22:
  Descriptor for parameter 0 eIrqNumberD.6000
    (locally) unused
    not a candidate for splitting
  Descriptor for parameter 1 u8TargetCoresD.6001
    (locally) unused
    not a candidate for splitting


Creating summary for IntCtrl_Ip_GetActive/21:
  Descriptor for parameter 0 eIrqNumberD.5997
    (locally) unused
    not a candidate for splitting


Creating summary for IntCtrl_Ip_GetPending/20:
  Descriptor for parameter 0 eIrqNumberD.5994
    (locally) unused
    not a candidate for splitting


Creating summary for IntCtrl_Ip_SetPending/19:
  Descriptor for parameter 0 eIrqNumberD.5991
    (locally) unused
    not a candidate for splitting


Creating summary for IntCtrl_Ip_ClearPending/18:
  Descriptor for parameter 0 eIrqNumberD.5988
    (locally) unused
    not a candidate for splitting


Creating summary for IntCtrl_Ip_GetPriority/17:
  Descriptor for parameter 0 eIrqNumberD.5985
    (locally) unused
    not a candidate for splitting


Creating summary for IntCtrl_Ip_SetPriority/16:
  Descriptor for parameter 0 eIrqNumberD.5981
    (locally) unused
    not a candidate for splitting
  Descriptor for parameter 1 u8PriorityD.5982
    (locally) unused
    not a candidate for splitting


Creating summary for IntCtrl_Ip_DisableIrq/15:
  Descriptor for parameter 0 eIrqNumberD.5978
    (locally) unused
    not a candidate for splitting


Creating summary for IntCtrl_Ip_EnableIrq/14:
  Descriptor for parameter 0 eIrqNumberD.5975
    (locally) unused
    not a candidate for splitting


Creating summary for IntCtrl_Ip_InstallHandler/13:
  Descriptor for parameter 0 eIrqNumberD.5970
    unused with 1 call_uses
    not a candidate
  Descriptor for parameter 1 pfNewHandlerD.5971
    unused with 1 call_uses
    not a candidate
  Descriptor for parameter 2 pfOldHandlerD.5972
    unused with 1 call_uses
    by_ref with 1 pass throughs
----------------------------------------
  Descriptor for parameter 0 eIrqNumberD.5970
    (locally) unused
    not a candidate for splitting
  Descriptor for parameter 1 pfNewHandlerD.5971
    (locally) unused
    not a candidate for splitting
  Descriptor for parameter 2 pfOldHandlerD.5972
    (locally) unused
    param_size_limit: 4, size_reached: 0, by_ref


Creating summary for IntCtrl_Ip_ConfigIrqRouting/12:
  Descriptor for parameter 0 routeConfigD.5963
    not a candidate for splitting


Creating summary for IntCtrl_Ip_Init/11:
  Descriptor for parameter 0 pIntCtrlCtrlConfigD.5956
    not a candidate for splitting


Creating summary for IntCtrl_Ip_SetTargetCoresPrivileged/10:
  Descriptor for parameter 0 eIrqNumberD.5952
    not a candidate for splitting
  Descriptor for parameter 1 u8TargetCoresD.5953
    not a candidate for splitting


Creating summary for IntCtrl_Ip_GetActivePrivileged/9:
  Descriptor for parameter 0 eIrqNumberD.5949
    not a candidate for splitting


Creating summary for IntCtrl_Ip_GetPendingPrivileged/8:
  Descriptor for parameter 0 eIrqNumberD.5946
    not a candidate for splitting


Creating summary for IntCtrl_Ip_SetPendingPrivileged/7:
  Descriptor for parameter 0 eIrqNumberD.5943
    not a candidate for splitting


Creating summary for IntCtrl_Ip_ClearPendingPrivileged/6:
  Descriptor for parameter 0 eIrqNumberD.5940
    not a candidate for splitting


Creating summary for IntCtrl_Ip_GetPriorityPrivileged/5:
  Descriptor for parameter 0 eIrqNumberD.5935
    not a candidate for splitting


Creating summary for IntCtrl_Ip_SetPriorityPrivileged/4:
  Descriptor for parameter 0 eIrqNumberD.5930
    not a candidate for splitting
  Descriptor for parameter 1 u8PriorityD.5931
    not a candidate for splitting


Creating summary for IntCtrl_Ip_DisableIrqPrivileged/3:
  Descriptor for parameter 0 eIrqNumberD.5927
    not a candidate for splitting


Creating summary for IntCtrl_Ip_EnableIrqPrivileged/2:
  Descriptor for parameter 0 eIrqNumberD.5924
    not a candidate for splitting


Creating summary for IntCtrl_Ip_InstallHandlerPrivileged/1:
  Descriptor for parameter 0 eIrqNumberD.5917
    not a candidate for splitting
  Descriptor for parameter 1 pfNewHandlerD.5918
    not a candidate for splitting
  Descriptor for parameter 2 pfOldHandlerD.5919
    not a candidate for splitting


Creating summary for DevAssert/0:
  Descriptor for parameter 0 xD.5860
    not a candidate for splitting



========== IPA-SRA IPA stage ==========

Summary for node IntCtrl_Ip_SetTargetCores/22:
  Descriptor for parameter 0:
    (locally) unused
    not a candidate for splitting
  Descriptor for parameter 1:
    (locally) unused
    not a candidate for splitting

  Summary for edge IntCtrl_Ip_SetTargetCores/22->IntCtrl_Ip_SetTargetCoresPrivileged/10:
    return value ignored
    Parameter 0:
      Scalar param sources: 0
    Parameter 1:
      Scalar param sources: 1

Summary for node IntCtrl_Ip_GetActive/21:
  Returns value
  Descriptor for parameter 0:
    (locally) unused
    not a candidate for splitting

  Summary for edge IntCtrl_Ip_GetActive/21->IntCtrl_Ip_GetActivePrivileged/9:
    return value used only to compute caller return value
    Parameter 0:
      Scalar param sources: 0

Summary for node IntCtrl_Ip_GetPending/20:
  Returns value
  Descriptor for parameter 0:
    (locally) unused
    not a candidate for splitting

  Summary for edge IntCtrl_Ip_GetPending/20->IntCtrl_Ip_GetPendingPrivileged/8:
    return value used only to compute caller return value
    Parameter 0:
      Scalar param sources: 0

Summary for node IntCtrl_Ip_SetPending/19:
  Descriptor for parameter 0:
    (locally) unused
    not a candidate for splitting

  Summary for edge IntCtrl_Ip_SetPending/19->IntCtrl_Ip_SetPendingPrivileged/7:
    return value ignored
    Parameter 0:
      Scalar param sources: 0

Summary for node IntCtrl_Ip_ClearPending/18:
  Descriptor for parameter 0:
    (locally) unused
    not a candidate for splitting

  Summary for edge IntCtrl_Ip_ClearPending/18->IntCtrl_Ip_ClearPendingPrivileged/6:
    return value ignored
    Parameter 0:
      Scalar param sources: 0

Summary for node IntCtrl_Ip_GetPriority/17:
  Returns value
  Descriptor for parameter 0:
    (locally) unused
    not a candidate for splitting

  Summary for edge IntCtrl_Ip_GetPriority/17->IntCtrl_Ip_GetPriorityPrivileged/5:
    return value used only to compute caller return value
    Parameter 0:
      Scalar param sources: 0

Summary for node IntCtrl_Ip_SetPriority/16:
  Descriptor for parameter 0:
    (locally) unused
    not a candidate for splitting
  Descriptor for parameter 1:
    (locally) unused
    not a candidate for splitting

  Summary for edge IntCtrl_Ip_SetPriority/16->IntCtrl_Ip_SetPriorityPrivileged/4:
    return value ignored
    Parameter 0:
      Scalar param sources: 0
    Parameter 1:
      Scalar param sources: 1

Summary for node IntCtrl_Ip_DisableIrq/15:
  Descriptor for parameter 0:
    (locally) unused
    not a candidate for splitting

  Summary for edge IntCtrl_Ip_DisableIrq/15->IntCtrl_Ip_DisableIrqPrivileged/3:
    return value ignored
    Parameter 0:
      Scalar param sources: 0

Summary for node IntCtrl_Ip_EnableIrq/14:
  Descriptor for parameter 0:
    (locally) unused
    not a candidate for splitting

  Summary for edge IntCtrl_Ip_EnableIrq/14->IntCtrl_Ip_EnableIrqPrivileged/2:
    return value ignored
    Parameter 0:
      Scalar param sources: 0

Summary for node IntCtrl_Ip_InstallHandler/13:
  Descriptor for parameter 0:
    (locally) unused
    not a candidate for splitting
  Descriptor for parameter 1:
    (locally) unused
    not a candidate for splitting
  Descriptor for parameter 2:
    (locally) unused
    param_size_limit: 4, size_reached: 0, by_ref

  Summary for edge IntCtrl_Ip_InstallHandler/13->IntCtrl_Ip_InstallHandlerPrivileged/1:
    return value ignored
    Parameter 0:
      Scalar param sources: 0
    Parameter 1:
      Scalar param sources: 1
    Parameter 2:
      Scalar param sources: 2
      Pointer pass through from the param given above, safe_to_import_accesses: 1

Summary for node IntCtrl_Ip_ConfigIrqRouting/12:
  Returns value
  Descriptor for parameter 0:
    not a candidate for splitting

  Summary for edge IntCtrl_Ip_ConfigIrqRouting/12->IntCtrl_Ip_InstallHandlerPrivileged/1:
    return value ignored
    Parameter 0:
      Scalar param sources: 0
    Parameter 1:
      Scalar param sources: 0
    Parameter 2:
  Summary for edge IntCtrl_Ip_ConfigIrqRouting/12->IntCtrl_Ip_SetTargetCoresPrivileged/10:
    return value ignored
    Parameter 0:
      Scalar param sources: 0
    Parameter 1:
      Scalar param sources: 0
  Summary for edge IntCtrl_Ip_ConfigIrqRouting/12->DevAssert/0:
    return value ignored
  Summary for edge IntCtrl_Ip_ConfigIrqRouting/12->DevAssert/0:
    return value ignored

Summary for node IntCtrl_Ip_Init/11:
  Returns value
  Descriptor for parameter 0:
    not a candidate for splitting

  Summary for edge IntCtrl_Ip_Init/11->IntCtrl_Ip_DisableIrqPrivileged/3:
    return value ignored
    Parameter 0:
      Scalar param sources: 0
  Summary for edge IntCtrl_Ip_Init/11->IntCtrl_Ip_EnableIrqPrivileged/2:
    return value ignored
    Parameter 0:
      Scalar param sources: 0
  Summary for edge IntCtrl_Ip_Init/11->IntCtrl_Ip_SetPriorityPrivileged/4:
    return value ignored
  Summary for edge IntCtrl_Ip_Init/11->IntCtrl_Ip_ClearPendingPrivileged/6:
    return value ignored
  Summary for edge IntCtrl_Ip_Init/11->DevAssert/0:
    return value ignored
  Summary for edge IntCtrl_Ip_Init/11->DevAssert/0:
    return value ignored

Summary for node IntCtrl_Ip_SetTargetCoresPrivileged/10:
  Descriptor for parameter 0:
    not a candidate for splitting
  Descriptor for parameter 1:
    not a candidate for splitting

  Summary for edge IntCtrl_Ip_SetTargetCoresPrivileged/10->DevAssert/0:
    return value ignored
  Summary for edge IntCtrl_Ip_SetTargetCoresPrivileged/10->DevAssert/0:
    return value ignored
  Summary for edge IntCtrl_Ip_SetTargetCoresPrivileged/10->DevAssert/0:
    return value ignored
  Summary for edge IntCtrl_Ip_SetTargetCoresPrivileged/10->DevAssert/0:
    return value ignored

Summary for node IntCtrl_Ip_GetActivePrivileged/9:
  Returns value
  Descriptor for parameter 0:
    not a candidate for splitting

  Summary for edge IntCtrl_Ip_GetActivePrivileged/9->DevAssert/0:
    return value ignored
  Summary for edge IntCtrl_Ip_GetActivePrivileged/9->DevAssert/0:
    return value ignored

Summary for node IntCtrl_Ip_GetPendingPrivileged/8:
  Returns value
  Descriptor for parameter 0:
    not a candidate for splitting

  Summary for edge IntCtrl_Ip_GetPendingPrivileged/8->DevAssert/0:
    return value ignored
  Summary for edge IntCtrl_Ip_GetPendingPrivileged/8->DevAssert/0:
    return value ignored

Summary for node IntCtrl_Ip_SetPendingPrivileged/7:
  Descriptor for parameter 0:
    not a candidate for splitting

  Summary for edge IntCtrl_Ip_SetPendingPrivileged/7->DevAssert/0:
    return value ignored
  Summary for edge IntCtrl_Ip_SetPendingPrivileged/7->DevAssert/0:
    return value ignored

Summary for node IntCtrl_Ip_ClearPendingPrivileged/6:
  Descriptor for parameter 0:
    not a candidate for splitting

  Summary for edge IntCtrl_Ip_ClearPendingPrivileged/6->DevAssert/0:
    return value ignored
  Summary for edge IntCtrl_Ip_ClearPendingPrivileged/6->DevAssert/0:
    return value ignored

Summary for node IntCtrl_Ip_GetPriorityPrivileged/5:
  Returns value
  Descriptor for parameter 0:
    not a candidate for splitting

  Summary for edge IntCtrl_Ip_GetPriorityPrivileged/5->DevAssert/0:
    return value ignored
  Summary for edge IntCtrl_Ip_GetPriorityPrivileged/5->DevAssert/0:
    return value ignored

Summary for node IntCtrl_Ip_SetPriorityPrivileged/4:
  Descriptor for parameter 0:
    not a candidate for splitting
  Descriptor for parameter 1:
    not a candidate for splitting

  Summary for edge IntCtrl_Ip_SetPriorityPrivileged/4->DevAssert/0:
    return value ignored
  Summary for edge IntCtrl_Ip_SetPriorityPrivileged/4->DevAssert/0:
    return value ignored
  Summary for edge IntCtrl_Ip_SetPriorityPrivileged/4->DevAssert/0:
    return value ignored

Summary for node IntCtrl_Ip_DisableIrqPrivileged/3:
  Descriptor for parameter 0:
    not a candidate for splitting

  Summary for edge IntCtrl_Ip_DisableIrqPrivileged/3->DevAssert/0:
    return value ignored
  Summary for edge IntCtrl_Ip_DisableIrqPrivileged/3->DevAssert/0:
    return value ignored

Summary for node IntCtrl_Ip_EnableIrqPrivileged/2:
  Descriptor for parameter 0:
    not a candidate for splitting

  Summary for edge IntCtrl_Ip_EnableIrqPrivileged/2->DevAssert/0:
    return value ignored
  Summary for edge IntCtrl_Ip_EnableIrqPrivileged/2->DevAssert/0:
    return value ignored

Summary for node IntCtrl_Ip_InstallHandlerPrivileged/1:
  Descriptor for parameter 0:
    not a candidate for splitting
  Descriptor for parameter 1:
    not a candidate for splitting
  Descriptor for parameter 2:
    not a candidate for splitting

  Summary for edge IntCtrl_Ip_InstallHandlerPrivileged/1->DevAssert/0:
    return value ignored
  Summary for edge IntCtrl_Ip_InstallHandlerPrivileged/1->DevAssert/0:
    return value ignored
    Parameter 0:
      Scalar param sources: 0
  Summary for edge IntCtrl_Ip_InstallHandlerPrivileged/1->DevAssert/0:
    return value ignored
    Parameter 0:
      Scalar param sources: 0

Summary for node DevAssert/0:
  Descriptor for parameter 0:
    not a candidate for splitting



Function IntCtrl_Ip_InstallHandlerPrivileged/1 disqualified because it cannot be made local.
Function IntCtrl_Ip_EnableIrqPrivileged/2 disqualified because it cannot be made local.
Function IntCtrl_Ip_DisableIrqPrivileged/3 disqualified because it cannot be made local.
Function IntCtrl_Ip_SetPriorityPrivileged/4 disqualified because it cannot be made local.
Function IntCtrl_Ip_GetPriorityPrivileged/5 disqualified because it cannot be made local.
Function IntCtrl_Ip_ClearPendingPrivileged/6 disqualified because it cannot be made local.
Function IntCtrl_Ip_SetPendingPrivileged/7 disqualified because it cannot be made local.
Function IntCtrl_Ip_GetPendingPrivileged/8 disqualified because it cannot be made local.
Function IntCtrl_Ip_GetActivePrivileged/9 disqualified because it cannot be made local.
Function IntCtrl_Ip_SetTargetCoresPrivileged/10 disqualified because it cannot be made local.
Function IntCtrl_Ip_Init/11 disqualified because it cannot be made local.
Function IntCtrl_Ip_ConfigIrqRouting/12 disqualified because it cannot be made local.
Function IntCtrl_Ip_InstallHandler/13 disqualified because it cannot be made local.
Function IntCtrl_Ip_EnableIrq/14 disqualified because it cannot be made local.
Function IntCtrl_Ip_DisableIrq/15 disqualified because it cannot be made local.
Function IntCtrl_Ip_SetPriority/16 disqualified because it cannot be made local.
Function IntCtrl_Ip_GetPriority/17 disqualified because it cannot be made local.
Function IntCtrl_Ip_ClearPending/18 disqualified because it cannot be made local.
Function IntCtrl_Ip_SetPending/19 disqualified because it cannot be made local.
Function IntCtrl_Ip_GetPending/20 disqualified because it cannot be made local.
Function IntCtrl_Ip_GetActive/21 disqualified because it cannot be made local.
Function IntCtrl_Ip_SetTargetCores/22 disqualified because it cannot be made local.

========== IPA-SRA decisions ==========

========== IPA SRA IPA analysis done ==========


Reclaiming functions:
Reclaiming variables:
Clearing address taken flags:
Symbol table:

__INT_SRAM_START/23 (__INT_SRAM_START) @060c8708
  Type: variable
  Body removed by symtab_remove_unreachable_nodes
  Visibility: external public
  References: 
  Referring: IntCtrl_Ip_InstallHandlerPrivileged/1 (addr) 
  Availability: not_available
  Varpool flags:
IntCtrl_Ip_SetTargetCores/22 (IntCtrl_Ip_SetTargetCores) @060cb2a0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: IntCtrl_Ip_SetTargetCoresPrivileged/10 (1073741824 (estimated locally),1.00 per call) 
IntCtrl_Ip_GetActive/21 (IntCtrl_Ip_GetActive) @060cb000
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: IntCtrl_Ip_GetActivePrivileged/9 (1073741824 (estimated locally),1.00 per call) 
IntCtrl_Ip_GetPending/20 (IntCtrl_Ip_GetPending) @060c6b60
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: IntCtrl_Ip_GetPendingPrivileged/8 (1073741824 (estimated locally),1.00 per call) 
IntCtrl_Ip_SetPending/19 (IntCtrl_Ip_SetPending) @060c6620
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: IntCtrl_Ip_SetPendingPrivileged/7 (1073741824 (estimated locally),1.00 per call) 
IntCtrl_Ip_ClearPending/18 (IntCtrl_Ip_ClearPending) @060c6000
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: IntCtrl_Ip_ClearPendingPrivileged/6 (1073741824 (estimated locally),1.00 per call) 
IntCtrl_Ip_GetPriority/17 (IntCtrl_Ip_GetPriority) @060c6d20
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: IntCtrl_Ip_GetPriorityPrivileged/5 (1073741824 (estimated locally),1.00 per call) 
IntCtrl_Ip_SetPriority/16 (IntCtrl_Ip_SetPriority) @060c6a80
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: IntCtrl_Ip_SetPriorityPrivileged/4 (1073741824 (estimated locally),1.00 per call) 
IntCtrl_Ip_DisableIrq/15 (IntCtrl_Ip_DisableIrq) @060c67e0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: IntCtrl_Ip_DisableIrqPrivileged/3 (1073741824 (estimated locally),1.00 per call) 
IntCtrl_Ip_EnableIrq/14 (IntCtrl_Ip_EnableIrq) @060c6540
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: IntCtrl_Ip_EnableIrqPrivileged/2 (1073741824 (estimated locally),1.00 per call) 
IntCtrl_Ip_InstallHandler/13 (IntCtrl_Ip_InstallHandler) @060c62a0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: IntCtrl_Ip_InstallHandlerPrivileged/1 (1073741824 (estimated locally),1.00 per call) 
IntCtrl_Ip_ConfigIrqRouting/12 (IntCtrl_Ip_ConfigIrqRouting) @05feee00
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:118111600 (estimated locally) body optimize_size
  Called by: 
  Calls: IntCtrl_Ip_InstallHandlerPrivileged/1 (955630225 (estimated locally),8.09 per call) IntCtrl_Ip_SetTargetCoresPrivileged/10 (955630225 (estimated locally),8.09 per call) DevAssert/0 (118111600 (estimated locally),1.00 per call) DevAssert/0 (118111600 (estimated locally),1.00 per call) 
IntCtrl_Ip_Init/11 (IntCtrl_Ip_Init) @05fee8c0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:118111600 (estimated locally) body optimize_size
  Called by: 
  Calls: IntCtrl_Ip_DisableIrqPrivileged/3 (477815112 (estimated locally),4.05 per call) IntCtrl_Ip_EnableIrqPrivileged/2 (477815112 (estimated locally),4.05 per call) IntCtrl_Ip_SetPriorityPrivileged/4 (955630225 (estimated locally),8.09 per call) IntCtrl_Ip_ClearPendingPrivileged/6 (955630225 (estimated locally),8.09 per call) DevAssert/0 (118111600 (estimated locally),1.00 per call) DevAssert/0 (118111600 (estimated locally),1.00 per call) 
IntCtrl_Ip_SetTargetCoresPrivileged/10 (IntCtrl_Ip_SetTargetCoresPrivileged) @05fee380
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: IntCtrl_Ip_ConfigIrqRouting/12 (955630225 (estimated locally),8.09 per call) IntCtrl_Ip_SetTargetCores/22 (1073741824 (estimated locally),1.00 per call) 
  Calls: DevAssert/0 (1073741824 (estimated locally),1.00 per call) DevAssert/0 (1073741824 (estimated locally),1.00 per call) DevAssert/0 (1073741824 (estimated locally),1.00 per call) DevAssert/0 (1073741824 (estimated locally),1.00 per call) 
IntCtrl_Ip_GetActivePrivileged/9 (IntCtrl_Ip_GetActivePrivileged) @05feed20
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: IntCtrl_Ip_GetActive/21 (1073741824 (estimated locally),1.00 per call) 
  Calls: DevAssert/0 (1073741824 (estimated locally),1.00 per call) DevAssert/0 (1073741824 (estimated locally),1.00 per call) 
IntCtrl_Ip_GetPendingPrivileged/8 (IntCtrl_Ip_GetPendingPrivileged) @05feea80
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: IntCtrl_Ip_GetPending/20 (1073741824 (estimated locally),1.00 per call) 
  Calls: DevAssert/0 (1073741824 (estimated locally),1.00 per call) DevAssert/0 (1073741824 (estimated locally),1.00 per call) 
IntCtrl_Ip_SetPendingPrivileged/7 (IntCtrl_Ip_SetPendingPrivileged) @05fee7e0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: IntCtrl_Ip_SetPending/19 (1073741824 (estimated locally),1.00 per call) 
  Calls: DevAssert/0 (1073741824 (estimated locally),1.00 per call) DevAssert/0 (1073741824 (estimated locally),1.00 per call) 
IntCtrl_Ip_ClearPendingPrivileged/6 (IntCtrl_Ip_ClearPendingPrivileged) @05fee540
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: IntCtrl_Ip_Init/11 (955630225 (estimated locally),8.09 per call) IntCtrl_Ip_ClearPending/18 (1073741824 (estimated locally),1.00 per call) 
  Calls: DevAssert/0 (1073741824 (estimated locally),1.00 per call) DevAssert/0 (1073741824 (estimated locally),1.00 per call) 
IntCtrl_Ip_GetPriorityPrivileged/5 (IntCtrl_Ip_GetPriorityPrivileged) @05fee2a0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: IntCtrl_Ip_GetPriority/17 (1073741824 (estimated locally),1.00 per call) 
  Calls: DevAssert/0 (1073741824 (estimated locally),1.00 per call) DevAssert/0 (1073741824 (estimated locally),1.00 per call) 
IntCtrl_Ip_SetPriorityPrivileged/4 (IntCtrl_Ip_SetPriorityPrivileged) @05fee000
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: IntCtrl_Ip_Init/11 (955630225 (estimated locally),8.09 per call) IntCtrl_Ip_SetPriority/16 (1073741824 (estimated locally),1.00 per call) 
  Calls: DevAssert/0 (1073741824 (estimated locally),1.00 per call) DevAssert/0 (1073741824 (estimated locally),1.00 per call) DevAssert/0 (1073741824 (estimated locally),1.00 per call) 
IntCtrl_Ip_DisableIrqPrivileged/3 (IntCtrl_Ip_DisableIrqPrivileged) @05fe6c40
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: IntCtrl_Ip_Init/11 (477815112 (estimated locally),4.05 per call) IntCtrl_Ip_DisableIrq/15 (1073741824 (estimated locally),1.00 per call) 
  Calls: DevAssert/0 (1073741824 (estimated locally),1.00 per call) DevAssert/0 (1073741824 (estimated locally),1.00 per call) 
IntCtrl_Ip_EnableIrqPrivileged/2 (IntCtrl_Ip_EnableIrqPrivileged) @05fe6e00
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: IntCtrl_Ip_Init/11 (477815112 (estimated locally),4.05 per call) IntCtrl_Ip_EnableIrq/14 (1073741824 (estimated locally),1.00 per call) 
  Calls: DevAssert/0 (1073741824 (estimated locally),1.00 per call) DevAssert/0 (1073741824 (estimated locally),1.00 per call) 
IntCtrl_Ip_InstallHandlerPrivileged/1 (IntCtrl_Ip_InstallHandlerPrivileged) @05fe6b60
  Type: function definition analyzed
  Visibility: externally_visible public
  References: __INT_SRAM_START/23 (addr) 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: IntCtrl_Ip_ConfigIrqRouting/12 (955630225 (estimated locally),8.09 per call) IntCtrl_Ip_InstallHandler/13 (1073741824 (estimated locally),1.00 per call) 
  Calls: DevAssert/0 (1073741824 (estimated locally),1.00 per call) DevAssert/0 (1073741824 (estimated locally),1.00 per call) DevAssert/0 (1073741824 (estimated locally),1.00 per call) 
DevAssert/0 (DevAssert) @05f61d20
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: local
  Function flags: count:21262216 (estimated locally) body local optimize_size
  Called by: IntCtrl_Ip_ConfigIrqRouting/12 (118111600 (estimated locally),1.00 per call) IntCtrl_Ip_ConfigIrqRouting/12 (118111600 (estimated locally),1.00 per call) IntCtrl_Ip_Init/11 (118111600 (estimated locally),1.00 per call) IntCtrl_Ip_Init/11 (118111600 (estimated locally),1.00 per call) IntCtrl_Ip_SetTargetCoresPrivileged/10 (1073741824 (estimated locally),1.00 per call) IntCtrl_Ip_SetTargetCoresPrivileged/10 (1073741824 (estimated locally),1.00 per call) IntCtrl_Ip_SetTargetCoresPrivileged/10 (1073741824 (estimated locally),1.00 per call) IntCtrl_Ip_SetTargetCoresPrivileged/10 (1073741824 (estimated locally),1.00 per call) IntCtrl_Ip_GetActivePrivileged/9 (1073741824 (estimated locally),1.00 per call) IntCtrl_Ip_GetActivePrivileged/9 (1073741824 (estimated locally),1.00 per call) IntCtrl_Ip_GetPendingPrivileged/8 (1073741824 (estimated locally),1.00 per call) IntCtrl_Ip_GetPendingPrivileged/8 (1073741824 (estimated locally),1.00 per call) IntCtrl_Ip_SetPendingPrivileged/7 (1073741824 (estimated locally),1.00 per call) IntCtrl_Ip_SetPendingPrivileged/7 (1073741824 (estimated locally),1.00 per call) IntCtrl_Ip_ClearPendingPrivileged/6 (1073741824 (estimated locally),1.00 per call) IntCtrl_Ip_ClearPendingPrivileged/6 (1073741824 (estimated locally),1.00 per call) IntCtrl_Ip_GetPriorityPrivileged/5 (1073741824 (estimated locally),1.00 per call) IntCtrl_Ip_GetPriorityPrivileged/5 (1073741824 (estimated locally),1.00 per call) IntCtrl_Ip_SetPriorityPrivileged/4 (1073741824 (estimated locally),1.00 per call) IntCtrl_Ip_SetPriorityPrivileged/4 (1073741824 (estimated locally),1.00 per call) IntCtrl_Ip_SetPriorityPrivileged/4 (1073741824 (estimated locally),1.00 per call) IntCtrl_Ip_DisableIrqPrivileged/3 (1073741824 (estimated locally),1.00 per call) IntCtrl_Ip_DisableIrqPrivileged/3 (1073741824 (estimated locally),1.00 per call) IntCtrl_Ip_EnableIrqPrivileged/2 (1073741824 (estimated locally),1.00 per call) IntCtrl_Ip_EnableIrqPrivileged/2 (1073741824 (estimated locally),1.00 per call) IntCtrl_Ip_InstallHandlerPrivileged/1 (1073741824 (estimated locally),1.00 per call) IntCtrl_Ip_InstallHandlerPrivileged/1 (1073741824 (estimated locally),1.00 per call) IntCtrl_Ip_InstallHandlerPrivileged/1 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
IntCtrl_Ip_SetTargetCores (IRQn_Type eIrqNumber, uint8 u8TargetCores)
{
  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  IntCtrl_Ip_SetTargetCoresPrivileged (eIrqNumber_2(D), u8TargetCores_3(D));
  return;

}


IntCtrl_Ip_GetActive (IRQn_Type eIrqNumber)
{
  long unsigned int _1;
  boolean _5;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  _1 = IntCtrl_Ip_GetActivePrivileged (eIrqNumber_3(D));
  _5 = _1 != 0;
  return _5;

}


IntCtrl_Ip_GetPending (IRQn_Type eIrqNumber)
{
  long unsigned int _1;
  boolean _5;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  _1 = IntCtrl_Ip_GetPendingPrivileged (eIrqNumber_3(D));
  _5 = _1 != 0;
  return _5;

}


IntCtrl_Ip_SetPending (IRQn_Type eIrqNumber)
{
  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  IntCtrl_Ip_SetPendingPrivileged (eIrqNumber_2(D));
  return;

}


IntCtrl_Ip_ClearPending (IRQn_Type eIrqNumber)
{
  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  IntCtrl_Ip_ClearPendingPrivileged (eIrqNumber_2(D));
  return;

}


IntCtrl_Ip_GetPriority (IRQn_Type eIrqNumber)
{
  uint8 _4;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  _4 = IntCtrl_Ip_GetPriorityPrivileged (eIrqNumber_2(D));
  return _4;

}


IntCtrl_Ip_SetPriority (IRQn_Type eIrqNumber, uint8 u8Priority)
{
  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  IntCtrl_Ip_SetPriorityPrivileged (eIrqNumber_2(D), u8Priority_3(D));
  return;

}


IntCtrl_Ip_DisableIrq (IRQn_Type eIrqNumber)
{
  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  IntCtrl_Ip_DisableIrqPrivileged (eIrqNumber_2(D));
  return;

}


IntCtrl_Ip_EnableIrq (IRQn_Type eIrqNumber)
{
  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  IntCtrl_Ip_EnableIrqPrivileged (eIrqNumber_2(D));
  return;

}


IntCtrl_Ip_InstallHandler (IRQn_Type eIrqNumber, void (*IntCtrl_Ip_IrqHandlerType) (void) pfNewHandler, void (*IntCtrl_Ip_IrqHandlerType) (void) * const pfOldHandler)
{
  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  IntCtrl_Ip_InstallHandlerPrivileged (eIrqNumber_2(D), pfNewHandler_3(D), pfOldHandler_4(D));
  return;

}


IntCtrl_Ip_ConfigIrqRouting (const struct IntCtrl_Ip_GlobalRouteConfigType * routeConfig)
{
  uint32 irqIdx;
  _Bool _1;
  long unsigned int _2;
  _Bool _3;
  const struct IntCtrl_Ip_IrqRouteConfigType * _4;
  long unsigned int _5;
  const struct IntCtrl_Ip_IrqRouteConfigType * _6;
  <unnamed type> _7;
  unsigned char _8;
  const struct IntCtrl_Ip_IrqRouteConfigType * _9;
  const struct IntCtrl_Ip_IrqRouteConfigType * _10;
  <unnamed type> _11;
  void (*<T514>) (void) _12;
  long unsigned int _13;

  <bb 2> [local count: 118111600]:
  # DEBUG BEGIN_STMT
  _1 = routeConfig_16(D) != 0B;
  DevAssert (_1);
  # DEBUG BEGIN_STMT
  _2 = routeConfig_16(D)->u32ConfigIrqCount;
  _3 = _2 <= 146;
  DevAssert (_3);
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG irqIdx => 0
  goto <bb 4>; [100.00%]

  <bb 3> [local count: 955630225]:
  # DEBUG BEGIN_STMT
  _4 = routeConfig_16(D)->aIrqConfig;
  _5 = irqIdx_14 * 12;
  _6 = _4 + _5;
  _7 = _6->eIrqNumber;
  _8 = _6->u8TargetCores;
  # DEBUG eIrqNumber => _7
  # DEBUG u8TargetCores => _8
  # DEBUG INLINE_ENTRY IntCtrl_Ip_SetTargetCores
  # DEBUG BEGIN_STMT
  IntCtrl_Ip_SetTargetCoresPrivileged (_7, _8);
  # DEBUG eIrqNumber => NULL
  # DEBUG u8TargetCores => NULL
  # DEBUG BEGIN_STMT
  _9 = routeConfig_16(D)->aIrqConfig;
  _10 = _9 + _5;
  _11 = _10->eIrqNumber;
  _12 = _10->pfHandler;
  # DEBUG eIrqNumber => _11
  # DEBUG pfNewHandler => _12
  # DEBUG pfOldHandler => 0B
  # DEBUG INLINE_ENTRY IntCtrl_Ip_InstallHandler
  # DEBUG BEGIN_STMT
  IntCtrl_Ip_InstallHandlerPrivileged (_11, _12, 0B);
  # DEBUG eIrqNumber => NULL
  # DEBUG pfNewHandler => NULL
  # DEBUG pfOldHandler => NULL
  # DEBUG BEGIN_STMT
  irqIdx_20 = irqIdx_14 + 1;
  # DEBUG irqIdx => irqIdx_20

  <bb 4> [local count: 1073741824]:
  # irqIdx_14 = PHI <0(2), irqIdx_20(3)>
  # DEBUG irqIdx => irqIdx_14
  # DEBUG BEGIN_STMT
  _13 = routeConfig_16(D)->u32ConfigIrqCount;
  if (_13 > irqIdx_14)
    goto <bb 3>; [89.00%]
  else
    goto <bb 5>; [11.00%]

  <bb 5> [local count: 118111600]:
  # DEBUG BEGIN_STMT
  return 0;

}


IntCtrl_Ip_Init (const struct IntCtrl_Ip_CtrlConfigType * pIntCtrlCtrlConfig)
{
  uint32 irqIdx;
  _Bool _1;
  long unsigned int _2;
  _Bool _3;
  const struct IntCtrl_Ip_IrqConfigType * _4;
  long unsigned int _5;
  const struct IntCtrl_Ip_IrqConfigType * _6;
  <unnamed type> _7;
  const struct IntCtrl_Ip_IrqConfigType * _8;
  const struct IntCtrl_Ip_IrqConfigType * _9;
  <unnamed type> _10;
  unsigned char _11;
  const struct IntCtrl_Ip_IrqConfigType * _12;
  const struct IntCtrl_Ip_IrqConfigType * _13;
  _Bool _14;
  <unnamed type> _15;
  <unnamed type> _16;
  long unsigned int _17;

  <bb 2> [local count: 118111600]:
  # DEBUG BEGIN_STMT
  _1 = pIntCtrlCtrlConfig_21(D) != 0B;
  DevAssert (_1);
  # DEBUG BEGIN_STMT
  _2 = pIntCtrlCtrlConfig_21(D)->u32ConfigIrqCount;
  _3 = _2 <= 146;
  DevAssert (_3);
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG irqIdx => 0
  goto <bb 7>; [100.00%]

  <bb 3> [local count: 955630225]:
  # DEBUG BEGIN_STMT
  _4 = pIntCtrlCtrlConfig_21(D)->aIrqConfig;
  _5 = irqIdx_18 * 8;
  _6 = _4 + _5;
  _7 = _6->eIrqNumber;
  # DEBUG eIrqNumber => _7
  # DEBUG INLINE_ENTRY IntCtrl_Ip_ClearPending
  # DEBUG BEGIN_STMT
  IntCtrl_Ip_ClearPendingPrivileged (_7);
  # DEBUG eIrqNumber => NULL
  # DEBUG BEGIN_STMT
  _8 = pIntCtrlCtrlConfig_21(D)->aIrqConfig;
  _9 = _8 + _5;
  _10 = _9->eIrqNumber;
  _11 = _9->u8IrqPriority;
  # DEBUG eIrqNumber => _10
  # DEBUG u8Priority => _11
  # DEBUG INLINE_ENTRY IntCtrl_Ip_SetPriority
  # DEBUG BEGIN_STMT
  IntCtrl_Ip_SetPriorityPrivileged (_10, _11);
  # DEBUG eIrqNumber => NULL
  # DEBUG u8Priority => NULL
  # DEBUG BEGIN_STMT
  _12 = pIntCtrlCtrlConfig_21(D)->aIrqConfig;
  _13 = _12 + _5;
  _14 = _13->bIrqEnabled;
  if (_14 != 0)
    goto <bb 4>; [50.00%]
  else
    goto <bb 5>; [50.00%]

  <bb 4> [local count: 477815112]:
  # DEBUG BEGIN_STMT
  _15 = _13->eIrqNumber;
  # DEBUG eIrqNumber => _15
  # DEBUG INLINE_ENTRY IntCtrl_Ip_EnableIrq
  # DEBUG BEGIN_STMT
  IntCtrl_Ip_EnableIrqPrivileged (_15);
  goto <bb 6>; [100.00%]

  <bb 5> [local count: 477815112]:
  # DEBUG BEGIN_STMT
  _16 = _13->eIrqNumber;
  # DEBUG eIrqNumber => _16
  # DEBUG INLINE_ENTRY IntCtrl_Ip_DisableIrq
  # DEBUG BEGIN_STMT
  IntCtrl_Ip_DisableIrqPrivileged (_16);

  <bb 6> [local count: 955630225]:
  # DEBUG eIrqNumber => NULL
  # DEBUG eIrqNumber => NULL
  # DEBUG BEGIN_STMT
  irqIdx_25 = irqIdx_18 + 1;
  # DEBUG irqIdx => irqIdx_25

  <bb 7> [local count: 1073741824]:
  # irqIdx_18 = PHI <0(2), irqIdx_25(6)>
  # DEBUG irqIdx => irqIdx_18
  # DEBUG BEGIN_STMT
  _17 = pIntCtrlCtrlConfig_21(D)->u32ConfigIrqCount;
  if (_17 > irqIdx_18)
    goto <bb 3>; [89.00%]
  else
    goto <bb 8>; [11.00%]

  <bb 8> [local count: 118111600]:
  # DEBUG BEGIN_STMT
  return 0;

}


IntCtrl_Ip_SetTargetCoresPrivileged (IRQn_Type eIrqNumber, uint8 u8TargetCores)
{
  _Bool _1;
  _Bool _2;
  unsigned char _3;
  short unsigned int _4;
  signed short _5;
  _Bool _6;
  _Bool _7;
  short unsigned int _8;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  _1 = eIrqNumber_9(D) >= 0;
  DevAssert (_1);
  # DEBUG BEGIN_STMT
  _2 = eIrqNumber_9(D) <= 212;
  DevAssert (_2);
  # DEBUG BEGIN_STMT
  _4 ={v} MEM[(struct MSCM_Type *)1076232192B].IRSPRC[eIrqNumber_9(D)];
  _5 = (signed short) _4;
  _6 = _5 >= 0;
  DevAssert (_6);
  # DEBUG BEGIN_STMT
  _7 = u8TargetCores_14(D) <= 1;
  DevAssert (_7);
  # DEBUG BEGIN_STMT
  _3 = u8TargetCores_14(D) & 1;
  _8 = (short unsigned int) _3;
  MEM[(struct MSCM_Type *)1076232192B].IRSPRC[eIrqNumber_9(D)] ={v} _8;
  return;

}


IntCtrl_Ip_GetActivePrivileged (IRQn_Type eIrqNumber)
{
  _Bool _1;
  _Bool _2;
  long unsigned int eIrqNumber.16_3;
  long unsigned int _4;
  long unsigned int _5;
  long unsigned int _6;
  long unsigned int _7;
  long unsigned int _8;
  uint32 _13;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  _1 = eIrqNumber_9(D) >= 0;
  DevAssert (_1);
  # DEBUG BEGIN_STMT
  _2 = eIrqNumber_9(D) <= 212;
  DevAssert (_2);
  # DEBUG BEGIN_STMT
  eIrqNumber.16_3 = (long unsigned int) eIrqNumber_9(D);
  _4 = eIrqNumber.16_3 >> 5;
  _5 ={v} MEM[(struct S32_NVIC_Type *)3758153728B].IABR[_4];
  _7 = eIrqNumber.16_3 & 31;
  _8 = _5 >> _7;
  _6 = _8 & 1;
  _13 = _6;
  return _13;

}


IntCtrl_Ip_GetPendingPrivileged (IRQn_Type eIrqNumber)
{
  _Bool _1;
  _Bool _2;
  long unsigned int eIrqNumber.14_3;
  long unsigned int _4;
  long unsigned int _5;
  long unsigned int _6;
  long unsigned int _7;
  long unsigned int _8;
  uint32 _13;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  _1 = eIrqNumber_9(D) >= 0;
  DevAssert (_1);
  # DEBUG BEGIN_STMT
  _2 = eIrqNumber_9(D) <= 212;
  DevAssert (_2);
  # DEBUG BEGIN_STMT
  eIrqNumber.14_3 = (long unsigned int) eIrqNumber_9(D);
  _4 = eIrqNumber.14_3 >> 5;
  _5 ={v} MEM[(struct S32_NVIC_Type *)3758153728B].ISPR[_4];
  _7 = eIrqNumber.14_3 & 31;
  _8 = _5 >> _7;
  _6 = _8 & 1;
  _13 = _6;
  return _13;

}


IntCtrl_Ip_SetPendingPrivileged (IRQn_Type eIrqNumber)
{
  _Bool _1;
  _Bool _2;
  long unsigned int eIrqNumber.12_3;
  long unsigned int _4;
  long unsigned int _5;
  long unsigned int _6;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  _1 = eIrqNumber_7(D) >= 0;
  DevAssert (_1);
  # DEBUG BEGIN_STMT
  _2 = eIrqNumber_7(D) <= 212;
  DevAssert (_2);
  # DEBUG BEGIN_STMT
  eIrqNumber.12_3 = (long unsigned int) eIrqNumber_7(D);
  _4 = eIrqNumber.12_3 & 31;
  _5 = eIrqNumber.12_3 >> 5;
  _6 = 1 << _4;
  MEM[(struct S32_NVIC_Type *)3758153728B].ISPR[_5] ={v} _6;
  return;

}


IntCtrl_Ip_ClearPendingPrivileged (IRQn_Type eIrqNumber)
{
  _Bool _1;
  _Bool _2;
  long unsigned int eIrqNumber.10_3;
  long unsigned int _4;
  long unsigned int _5;
  long unsigned int _6;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  _1 = eIrqNumber_7(D) >= 0;
  DevAssert (_1);
  # DEBUG BEGIN_STMT
  _2 = eIrqNumber_7(D) <= 212;
  DevAssert (_2);
  # DEBUG BEGIN_STMT
  eIrqNumber.10_3 = (long unsigned int) eIrqNumber_7(D);
  _4 = eIrqNumber.10_3 & 31;
  _5 = eIrqNumber.10_3 >> 5;
  _6 = 1 << _4;
  MEM[(struct S32_NVIC_Type *)3758153728B].ICPR[_5] ={v} _6;
  return;

}


IntCtrl_Ip_GetPriorityPrivileged (IRQn_Type eIrqNumber)
{
  uint8 priority;
  _Bool _1;
  _Bool _2;
  long unsigned int eIrqNumber.9_3;
  unsigned char _4;
  int _5;
  int _6;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  _1 = eIrqNumber_7(D) >= 0;
  DevAssert (_1);
  # DEBUG BEGIN_STMT
  _2 = eIrqNumber_7(D) <= 212;
  DevAssert (_2);
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG shift => 4
  # DEBUG BEGIN_STMT
  eIrqNumber.9_3 = (long unsigned int) eIrqNumber_7(D);
  _4 ={v} MEM[(struct S32_NVIC_Type *)3758153728B].IP[eIrqNumber.9_3];
  _5 = (int) _4;
  _6 = _5 >> 4;
  priority_11 = (uint8) _6;
  # DEBUG priority => priority_11
  # DEBUG BEGIN_STMT
  return priority_11;

}


IntCtrl_Ip_SetPriorityPrivileged (IRQn_Type eIrqNumber, uint8 u8Priority)
{
  _Bool _1;
  _Bool _2;
  _Bool _3;
  long unsigned int _4;
  long unsigned int _5;
  long unsigned int eIrqNumber.8_6;
  unsigned char _7;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  _1 = eIrqNumber_8(D) >= 0;
  DevAssert (_1);
  # DEBUG BEGIN_STMT
  _2 = eIrqNumber_8(D) <= 212;
  DevAssert (_2);
  # DEBUG BEGIN_STMT
  _3 = u8Priority_12(D) <= 15;
  DevAssert (_3);
  # DEBUG BEGIN_STMT
  # DEBUG shift => 4
  # DEBUG BEGIN_STMT
  _4 = (long unsigned int) u8Priority_12(D);
  _5 = _4 << 4;
  eIrqNumber.8_6 = (long unsigned int) eIrqNumber_8(D);
  _7 = (unsigned char) _5;
  MEM[(struct S32_NVIC_Type *)3758153728B].IP[eIrqNumber.8_6] ={v} _7;
  return;

}


IntCtrl_Ip_DisableIrqPrivileged (IRQn_Type eIrqNumber)
{
  _Bool _1;
  _Bool _2;
  long unsigned int eIrqNumber.6_3;
  long unsigned int _4;
  long unsigned int _5;
  long unsigned int _6;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  _1 = eIrqNumber_7(D) >= 0;
  DevAssert (_1);
  # DEBUG BEGIN_STMT
  _2 = eIrqNumber_7(D) <= 212;
  DevAssert (_2);
  # DEBUG BEGIN_STMT
  eIrqNumber.6_3 = (long unsigned int) eIrqNumber_7(D);
  _4 = eIrqNumber.6_3 & 31;
  _5 = eIrqNumber.6_3 >> 5;
  _6 = 1 << _4;
  MEM[(struct S32_NVIC_Type *)3758153728B].ICER[_5] ={v} _6;
  return;

}


IntCtrl_Ip_EnableIrqPrivileged (IRQn_Type eIrqNumber)
{
  _Bool _1;
  _Bool _2;
  long unsigned int eIrqNumber.4_3;
  long unsigned int _4;
  long unsigned int _5;
  long unsigned int _6;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  _1 = eIrqNumber_7(D) >= 0;
  DevAssert (_1);
  # DEBUG BEGIN_STMT
  _2 = eIrqNumber_7(D) <= 212;
  DevAssert (_2);
  # DEBUG BEGIN_STMT
  eIrqNumber.4_3 = (long unsigned int) eIrqNumber_7(D);
  _4 = eIrqNumber.4_3 & 31;
  _5 = eIrqNumber.4_3 >> 5;
  _6 = 1 << _4;
  MEM[(struct S32_NVIC_Type *)3758153728B].ISER[_5] ={v} _6;
  return;

}


IntCtrl_Ip_InstallHandlerPrivileged (IRQn_Type eIrqNumber, void (*IntCtrl_Ip_IrqHandlerType) (void) pfNewHandler, void (*IntCtrl_Ip_IrqHandlerType) (void) * const pfOldHandler)
{
  void (*IntCtrl_Ip_IrqHandlerType) (void) * pVectorRam;
  _Bool _1;
  _Bool _2;
  long unsigned int _3;
  long unsigned int __INT_SRAM_START.0_4;
  _Bool _5;
  long unsigned int _6;
  sizetype eIrqNumber.1_7;
  sizetype _8;
  sizetype _9;
  void (*IntCtrl_Ip_IrqHandlerType) (void) * _10;
  void (*<T514>) (void) _11;
  sizetype eIrqNumber.2_12;
  sizetype _13;
  sizetype _14;
  void (*IntCtrl_Ip_IrqHandlerType) (void) * _15;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG dev_irqNumber => eIrqNumber_17(D)
  # DEBUG BEGIN_STMT
  _1 = eIrqNumber_17(D) >= 0;
  DevAssert (_1);
  # DEBUG BEGIN_STMT
  _2 = eIrqNumber_17(D) <= 212;
  DevAssert (_2);
  # DEBUG BEGIN_STMT
  _3 ={v} MEM[(struct S32_SCB_Type *)3758153728B].VTOR;
  __INT_SRAM_START.0_4 = (long unsigned int) &__INT_SRAM_START;
  _5 = _3 >= __INT_SRAM_START.0_4;
  DevAssert (_5);
  # DEBUG BEGIN_STMT
  _6 ={v} MEM[(struct S32_SCB_Type *)3758153728B].VTOR;
  pVectorRam_22 = (void (*IntCtrl_Ip_IrqHandlerType) (void) *) _6;
  # DEBUG pVectorRam => pVectorRam_22
  # DEBUG BEGIN_STMT
  if (pfOldHandler_23(D) != 0B)
    goto <bb 3>; [70.00%]
  else
    goto <bb 4>; [30.00%]

  <bb 3> [local count: 751619281]:
  # DEBUG BEGIN_STMT
  eIrqNumber.1_7 = (sizetype) eIrqNumber_17(D);
  _8 = eIrqNumber.1_7 + 16;
  _9 = _8 * 4;
  _10 = pVectorRam_22 + _9;
  _11 = *_10;
  *pfOldHandler_23(D) = _11;

  <bb 4> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  eIrqNumber.2_12 = (sizetype) eIrqNumber_17(D);
  _13 = eIrqNumber.2_12 + 16;
  _14 = _13 * 4;
  _15 = pVectorRam_22 + _14;
  *_15 = pfNewHandler_25(D);
  # DEBUG BEGIN_STMT
  __asm__ __volatile__(" ISB");
  # DEBUG BEGIN_STMT
  __asm__ __volatile__(" DSB");
  return;

}


DevAssert (volatile boolean x)
{
  _Bool x.3_1;

  <bb 2> [local count: 21262216]:
  # DEBUG BEGIN_STMT
  x.3_1 ={v} x;
  if (x.3_1 != 0)
    goto <bb 4>; [50.00%]
  else
    goto <bb 5>; [50.00%]

  <bb 5> [local count: 10631108]:

  <bb 3> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  __asm__ __volatile__("BKPT #0");
  # DEBUG BEGIN_STMT

  <bb 6> [local count: 1073741824]:
  goto <bb 3>; [100.00%]

  <bb 4> [local count: 10631108]:
  # DEBUG BEGIN_STMT
  return;

}


