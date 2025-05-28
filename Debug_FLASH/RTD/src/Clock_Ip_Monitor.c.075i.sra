Creating summary for Clock_Ip_CMU_ClockFailInt/12:


Creating summary for Clock_Ip_CMU_GetInterruptStatus/11:
  Descriptor for parameter 0 IndexCmuD.6679
    not a candidate for splitting


Creating summary for Clock_Ip_EnableCmuFcFceRefCntLfrefHfref/10:
  Descriptor for parameter 0 ConfigD.6674
    by_ref with 0 pass throughs
        * Access to offset: 0, size: 32, type: const Clock_Ip_NameType, alias_ptr_type: <unnamed type> *, nonarg: 1, reverse: 0
        * Access to offset: 32, size: 8, type: const uint8, alias_ptr_type: unsigned char *, nonarg: 1, reverse: 0
----------------------------------------
  Descriptor for parameter 0 ConfigD.6674
    not a candidate for splitting


Creating summary for Clock_Ip_GetStatusCmuFcFceRefCntLfrefHfref/9:
  Descriptor for parameter 0 NameD.6666
    not a candidate for splitting


Creating summary for Clock_Ip_ClearStatusCmuFcFceRefCntLfrefHfref/8:
  Descriptor for parameter 0 NameD.6660
    not a candidate for splitting


Creating summary for Clock_Ip_SetCmuFcFceRefCntLfrefHfref/7:
  Descriptor for parameter 0 ConfigD.6642
    by_ref with 0 pass throughs
        * Access to offset: 0, size: 32, type: const Clock_Ip_NameType, alias_ptr_type: <unnamed type> *, nonarg: 1, reverse: 0
        * Access to offset: 32, size: 8, type: const uint8, alias_ptr_type: unsigned char *, nonarg: 1, reverse: 0
        * Access to offset: 64, size: 32, type: const uint32, alias_ptr_type: long unsigned int *, nonarg: 1, reverse: 0
        * Access to offset: 96, size: 32, type: const uint32, alias_ptr_type: long unsigned int *, nonarg: 1, reverse: 0
  Descriptor for parameter 1 IndexD.6643
    not a candidate
----------------------------------------
  Descriptor for parameter 0 ConfigD.6642
    not a candidate for splitting
  Descriptor for parameter 1 IndexD.6643
    not a candidate for splitting


Creating summary for Clock_Ip_ResetCmuFcFceRefCntLfrefHfref/6:
  Descriptor for parameter 0 ConfigD.6639
    unused with 1 call_uses
    by_ref with 0 pass throughs
        * Access to offset: 0, size: 32, type: const Clock_Ip_NameType, alias_ptr_type: <unnamed type> *, nonarg: 1, reverse: 0
----------------------------------------
  Descriptor for parameter 0 ConfigD.6639
    (locally) unused
    param_size_limit: 4, size_reached: 4, by_ref
    * Access to unit offset: 0, unit size: 4, type: const Clock_Ip_NameType, alias_ptr_type: <unnamed type> *, certain


Creating summary for Clock_Ip_DisableCmuFcFceRefCntLfrefHfref/5:
  Descriptor for parameter 0 NameD.6627
    not a candidate for splitting


Creating summary for Clock_Ip_ClockMonitorEmpty_GetStatus/4:
  Descriptor for parameter 0 NameD.6624
    (locally) unused
    not a candidate for splitting


Creating summary for Clock_Ip_ClockMonitorEmpty_ClearStatus/3:
  Descriptor for parameter 0 NameD.6621
    (locally) unused
    not a candidate for splitting


Creating summary for Clock_Ip_ClockMonitorEmpty_Disable/2:
  Descriptor for parameter 0 NameD.6618
    (locally) unused
    not a candidate for splitting


Creating summary for Clock_Ip_ClockMonitorEmpty_Set/1:
  Descriptor for parameter 0 ConfigD.6614
    unused with 0 call_uses
    by_ref with 0 pass throughs
  Descriptor for parameter 1 IndexD.6615
    unused with 0 call_uses
    not a candidate
----------------------------------------
  Descriptor for parameter 0 ConfigD.6614
    (locally) unused
    param_size_limit: 4, size_reached: 0, by_ref
  Descriptor for parameter 1 IndexD.6615
    (locally) unused
    not a candidate for splitting


Creating summary for Clock_Ip_ClockMonitorEmpty/0:
  Descriptor for parameter 0 ConfigD.6611
    unused with 0 call_uses
    by_ref with 0 pass throughs
----------------------------------------
  Descriptor for parameter 0 ConfigD.6611
    (locally) unused
    param_size_limit: 4, size_reached: 0, by_ref



========== IPA-SRA IPA stage ==========

Summary for node Clock_Ip_CMU_ClockFailInt/12:
  No parameter information. 

  Summary for edge Clock_Ip_CMU_ClockFailInt/12->Clock_Ip_ReportClockErrors/17:
    return value ignored

Summary for node Clock_Ip_CMU_GetInterruptStatus/11:
  Returns value
  Descriptor for parameter 0:
    not a candidate for splitting


Summary for node Clock_Ip_EnableCmuFcFceRefCntLfrefHfref/10:
  Descriptor for parameter 0:
    not a candidate for splitting


Summary for node Clock_Ip_GetStatusCmuFcFceRefCntLfrefHfref/9:
  Returns value
  Descriptor for parameter 0:
    not a candidate for splitting


Summary for node Clock_Ip_ClearStatusCmuFcFceRefCntLfrefHfref/8:
  Descriptor for parameter 0:
    not a candidate for splitting


Summary for node Clock_Ip_SetCmuFcFceRefCntLfrefHfref/7:
  Descriptor for parameter 0:
    not a candidate for splitting
  Descriptor for parameter 1:
    not a candidate for splitting


Summary for node Clock_Ip_ResetCmuFcFceRefCntLfrefHfref/6:
  Descriptor for parameter 0:
    (locally) unused
    param_size_limit: 4, size_reached: 4, by_ref
    * Access to unit offset: 0, unit size: 4, type: const Clock_Ip_NameType, alias_ptr_type: <unnamed type> *, certain

  Summary for edge Clock_Ip_ResetCmuFcFceRefCntLfrefHfref/6->Clock_Ip_DisableCmuFcFceRefCntLfrefHfref/5:
    return value ignored
    Parameter 0:
      Scalar param sources: 0

Summary for node Clock_Ip_DisableCmuFcFceRefCntLfrefHfref/5:
  Descriptor for parameter 0:
    not a candidate for splitting

  Summary for edge Clock_Ip_DisableCmuFcFceRefCntLfrefHfref/5->SchM_Exit_Mcu_MCU_EXCLUSIVE_AREA_01/23:
    return value ignored
  Summary for edge Clock_Ip_DisableCmuFcFceRefCntLfrefHfref/5->Clock_Ip_ReportClockErrors/17:
    return value ignored
    Parameter 0:
    Parameter 1:
      Scalar param sources: 0
  Summary for edge Clock_Ip_DisableCmuFcFceRefCntLfrefHfref/5->Clock_Ip_TimeoutExpired/22:
  Summary for edge Clock_Ip_DisableCmuFcFceRefCntLfrefHfref/5->Clock_Ip_StartTimeout/21:
    return value ignored
  Summary for edge Clock_Ip_DisableCmuFcFceRefCntLfrefHfref/5->SchM_Enter_Mcu_MCU_EXCLUSIVE_AREA_01/20:
    return value ignored

Summary for node Clock_Ip_ClockMonitorEmpty_GetStatus/4:
  Returns value
  Descriptor for parameter 0:
    (locally) unused
    not a candidate for splitting


Summary for node Clock_Ip_ClockMonitorEmpty_ClearStatus/3:
  Not a candidate function

Summary for node Clock_Ip_ClockMonitorEmpty_Disable/2:
  Descriptor for parameter 0:
    (locally) unused
    not a candidate for splitting


Summary for node Clock_Ip_ClockMonitorEmpty_Set/1:
  Descriptor for parameter 0:
    (locally) unused
    param_size_limit: 4, size_reached: 0, by_ref
  Descriptor for parameter 1:
    (locally) unused
    not a candidate for splitting


Summary for node Clock_Ip_ClockMonitorEmpty/0:
  Descriptor for parameter 0:
    (locally) unused
    param_size_limit: 4, size_reached: 0, by_ref



Function Clock_Ip_ClockMonitorEmpty/0 disqualified because it cannot be made local.
Function Clock_Ip_ClockMonitorEmpty_Set/1 disqualified because it cannot be made local.
Function Clock_Ip_ClockMonitorEmpty_Disable/2 disqualified because it cannot be made local.
Function Clock_Ip_ClockMonitorEmpty_GetStatus/4 disqualified because it cannot be made local.
Function Clock_Ip_DisableCmuFcFceRefCntLfrefHfref/5 disqualified because it cannot be made local.
Function Clock_Ip_ResetCmuFcFceRefCntLfrefHfref/6 disqualified because it cannot be made local.
Function Clock_Ip_SetCmuFcFceRefCntLfrefHfref/7 disqualified because it cannot be made local.
Function Clock_Ip_ClearStatusCmuFcFceRefCntLfrefHfref/8 disqualified because it cannot be made local.
Function Clock_Ip_GetStatusCmuFcFceRefCntLfrefHfref/9 disqualified because it cannot be made local.
Function Clock_Ip_EnableCmuFcFceRefCntLfrefHfref/10 disqualified because it cannot be made local.
Function Clock_Ip_CMU_GetInterruptStatus/11 disqualified because it cannot be made local.
Function Clock_Ip_CMU_ClockFailInt/12 disqualified because it cannot be made local.

========== IPA-SRA decisions ==========

========== IPA SRA IPA analysis done ==========


Reclaiming functions:
Reclaiming variables:
Clearing address taken flags:
Symbol table:

Clock_Ip_FreqIds/25 (Clock_Ip_FreqIds) @062bf2d0
  Type: variable
  Body removed by symtab_remove_unreachable_nodes
  Visibility: external public
  References: 
  Referring: Clock_Ip_SetCmuFcFceRefCntLfrefHfref/7 (read) Clock_Ip_SetCmuFcFceRefCntLfrefHfref/7 (read) 
  Availability: not_available
  Varpool flags:
Hash.0/24 (Hash) @062bf288
  Type: variable definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: Clock_Ip_SetCmuFcFceRefCntLfrefHfref/7 (read) Clock_Ip_SetCmuFcFceRefCntLfrefHfref/7 (write) 
  Availability: available
  Varpool flags:
SchM_Exit_Mcu_MCU_EXCLUSIVE_AREA_01/23 (SchM_Exit_Mcu_MCU_EXCLUSIVE_AREA_01) @06295700
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Clock_Ip_DisableCmuFcFceRefCntLfrefHfref/5 (348071307 (estimated locally),1.00 per call) 
  Calls: 
Clock_Ip_TimeoutExpired/22 (Clock_Ip_TimeoutExpired) @06295620
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Clock_Ip_DisableCmuFcFceRefCntLfrefHfref/5 (1073741824 (estimated locally),3.08 per call) 
  Calls: 
Clock_Ip_StartTimeout/21 (Clock_Ip_StartTimeout) @06295540
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Clock_Ip_DisableCmuFcFceRefCntLfrefHfref/5 (114863530 (estimated locally),0.33 per call) 
  Calls: 
SchM_Enter_Mcu_MCU_EXCLUSIVE_AREA_01/20 (SchM_Enter_Mcu_MCU_EXCLUSIVE_AREA_01) @06295460
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Clock_Ip_DisableCmuFcFceRefCntLfrefHfref/5 (348071305 (estimated locally),1.00 per call) 
  Calls: 
Clock_Ip_axCmuInfo/19 (Clock_Ip_axCmuInfo) @062935a0
  Type: variable
  Body removed by symtab_remove_unreachable_nodes
  Visibility: external public
  References: 
  Referring: Clock_Ip_ClearStatusCmuFcFceRefCntLfrefHfref/8 (read) Clock_Ip_SetCmuFcFceRefCntLfrefHfref/7 (read) Clock_Ip_EnableCmuFcFceRefCntLfrefHfref/10 (read) Clock_Ip_GetStatusCmuFcFceRefCntLfrefHfref/9 (read) Clock_Ip_SetCmuFcFceRefCntLfrefHfref/7 (read) Clock_Ip_SetCmuFcFceRefCntLfrefHfref/7 (read) Clock_Ip_DisableCmuFcFceRefCntLfrefHfref/5 (read) 
  Availability: not_available
  Varpool flags: read-only
Clock_Ip_au8ClockFeatures/18 (Clock_Ip_au8ClockFeatures) @06293558
  Type: variable
  Body removed by symtab_remove_unreachable_nodes
  Visibility: external public
  References: 
  Referring: Clock_Ip_ClearStatusCmuFcFceRefCntLfrefHfref/8 (read) Clock_Ip_SetCmuFcFceRefCntLfrefHfref/7 (read) Clock_Ip_EnableCmuFcFceRefCntLfrefHfref/10 (read) Clock_Ip_GetStatusCmuFcFceRefCntLfrefHfref/9 (read) Clock_Ip_DisableCmuFcFceRefCntLfrefHfref/5 (read) 
  Availability: not_available
  Varpool flags: read-only
Clock_Ip_ReportClockErrors/17 (Clock_Ip_ReportClockErrors) @06236a80
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Clock_Ip_CMU_ClockFailInt/12 (198427488 (estimated locally),0.92 per call) Clock_Ip_DisableCmuFcFceRefCntLfrefHfref/5 (37904965 (estimated locally),0.11 per call) 
  Calls: 
Clock_Ip_aeCmuNames/16 (Clock_Ip_aeCmuNames) @06293318
  Type: variable
  Body removed by symtab_remove_unreachable_nodes
  Visibility: external public
  References: 
  Referring: Clock_Ip_CMU_ClockFailInt/12 (read) 
  Availability: not_available
  Varpool flags: read-only
Clock_Ip_pxConfig/15 (Clock_Ip_pxConfig) @062932d0
  Type: variable
  Body removed by symtab_remove_unreachable_nodes
  Visibility: external public
  References: 
  Referring: Clock_Ip_SetCmuFcFceRefCntLfrefHfref/7 (read) Clock_Ip_CMU_ClockFailInt/12 (read) 
  Availability: not_available
  Varpool flags:
Clock_Ip_apxCmu/14 (Clock_Ip_apxCmu) @0622ef78
  Type: variable
  Body removed by symtab_remove_unreachable_nodes
  Visibility: external public
  References: 
  Referring: Clock_Ip_CMU_GetInterruptStatus/11 (read) Clock_Ip_CMU_ClockFailInt/12 (read) 
  Availability: not_available
  Varpool flags: read-only
Clock_Ip_axCmuCallbacks/13 (Clock_Ip_axCmuCallbacks) @0622ec60
  Type: variable definition analyzed
  Visibility: externally_visible public
  References: Clock_Ip_ClockMonitorEmpty/0 (addr) Clock_Ip_ClockMonitorEmpty_Set/1 (addr) Clock_Ip_ClockMonitorEmpty_Disable/2 (addr) Clock_Ip_ClockMonitorEmpty_ClearStatus/3 (addr) Clock_Ip_ClockMonitorEmpty_GetStatus/4 (addr) Clock_Ip_ClockMonitorEmpty/0 (addr) Clock_Ip_ResetCmuFcFceRefCntLfrefHfref/6 (addr) Clock_Ip_SetCmuFcFceRefCntLfrefHfref/7 (addr) Clock_Ip_DisableCmuFcFceRefCntLfrefHfref/5 (addr) Clock_Ip_ClearStatusCmuFcFceRefCntLfrefHfref/8 (addr) Clock_Ip_GetStatusCmuFcFceRefCntLfrefHfref/9 (addr) Clock_Ip_EnableCmuFcFceRefCntLfrefHfref/10 (addr) 
  Referring: 
  Availability: available
  Varpool flags: initialized read-only const-value-known
Clock_Ip_CMU_ClockFailInt/12 (Clock_Ip_CMU_ClockFailInt) @06236c40
  Type: function definition analyzed
  Visibility: externally_visible public
  References: Clock_Ip_apxCmu/14 (read) Clock_Ip_pxConfig/15 (read) Clock_Ip_aeCmuNames/16 (read) 
  Referring: 
  Availability: available
  Function flags: count:214748366 (estimated locally) body optimize_size
  Called by: 
  Calls: Clock_Ip_ReportClockErrors/17 (198427488 (estimated locally),0.92 per call) 
Clock_Ip_CMU_GetInterruptStatus/11 (Clock_Ip_CMU_GetInterruptStatus) @062369a0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: Clock_Ip_apxCmu/14 (read) 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
Clock_Ip_EnableCmuFcFceRefCntLfrefHfref/10 (Clock_Ip_EnableCmuFcFceRefCntLfrefHfref) @06236700
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  Address is taken.
  References: Clock_Ip_au8ClockFeatures/18 (read) Clock_Ip_axCmuInfo/19 (read) 
  Referring: Clock_Ip_axCmuCallbacks/13 (addr) 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
Clock_Ip_GetStatusCmuFcFceRefCntLfrefHfref/9 (Clock_Ip_GetStatusCmuFcFceRefCntLfrefHfref) @06236460
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  Address is taken.
  References: Clock_Ip_au8ClockFeatures/18 (read) Clock_Ip_axCmuInfo/19 (read) 
  Referring: Clock_Ip_axCmuCallbacks/13 (addr) 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
Clock_Ip_ClearStatusCmuFcFceRefCntLfrefHfref/8 (Clock_Ip_ClearStatusCmuFcFceRefCntLfrefHfref) @062361c0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  Address is taken.
  References: Clock_Ip_au8ClockFeatures/18 (read) Clock_Ip_axCmuInfo/19 (read) 
  Referring: Clock_Ip_axCmuCallbacks/13 (addr) 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
Clock_Ip_SetCmuFcFceRefCntLfrefHfref/7 (Clock_Ip_SetCmuFcFceRefCntLfrefHfref) @0622aee0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  Address is taken.
  References: Clock_Ip_au8ClockFeatures/18 (read) Clock_Ip_axCmuInfo/19 (read) Hash.0/24 (read) Hash.0/24 (write) Clock_Ip_pxConfig/15 (read) Clock_Ip_axCmuInfo/19 (read) Clock_Ip_FreqIds/25 (read) Clock_Ip_axCmuInfo/19 (read) Clock_Ip_FreqIds/25 (read) 
  Referring: Clock_Ip_axCmuCallbacks/13 (addr) 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
Clock_Ip_ResetCmuFcFceRefCntLfrefHfref/6 (Clock_Ip_ResetCmuFcFceRefCntLfrefHfref) @0622a9a0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  Address is taken.
  References: 
  Referring: Clock_Ip_axCmuCallbacks/13 (addr) 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: Clock_Ip_DisableCmuFcFceRefCntLfrefHfref/5 (1073741824 (estimated locally),1.00 per call) 
Clock_Ip_DisableCmuFcFceRefCntLfrefHfref/5 (Clock_Ip_DisableCmuFcFceRefCntLfrefHfref) @0622a460
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  Address is taken.
  References: Clock_Ip_au8ClockFeatures/18 (read) Clock_Ip_axCmuInfo/19 (read) 
  Referring: Clock_Ip_axCmuCallbacks/13 (addr) 
  Availability: available
  Function flags: count:348071305 (estimated locally) body optimize_size
  Called by: Clock_Ip_ResetCmuFcFceRefCntLfrefHfref/6 (1073741824 (estimated locally),1.00 per call) 
  Calls: SchM_Exit_Mcu_MCU_EXCLUSIVE_AREA_01/23 (348071307 (estimated locally),1.00 per call) Clock_Ip_ReportClockErrors/17 (37904965 (estimated locally),0.11 per call) Clock_Ip_TimeoutExpired/22 (1073741824 (estimated locally),3.08 per call) Clock_Ip_StartTimeout/21 (114863530 (estimated locally),0.33 per call) SchM_Enter_Mcu_MCU_EXCLUSIVE_AREA_01/20 (348071305 (estimated locally),1.00 per call) 
Clock_Ip_ClockMonitorEmpty_GetStatus/4 (Clock_Ip_ClockMonitorEmpty_GetStatus) @0622ae00
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  Address is taken.
  References: 
  Referring: Clock_Ip_axCmuCallbacks/13 (addr) 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
Clock_Ip_ClockMonitorEmpty_ClearStatus/3 (Clock_Ip_ClockMonitorEmpty_ClearStatus) @0622ab60
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  Address is taken.
  References: 
  Referring: Clock_Ip_axCmuCallbacks/13 (addr) 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body icf_merged optimize_size
  Called by: 
  Calls: Clock_Ip_ClockMonitorEmpty_Disable/2 (1073741824 (estimated locally),1.00 per call) 
Clock_Ip_ClockMonitorEmpty_Disable/2 (Clock_Ip_ClockMonitorEmpty_Disable) @0622a8c0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  Address is taken.
  References: 
  Referring: Clock_Ip_axCmuCallbacks/13 (addr) 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body icf_merged optimize_size
  Called by: Clock_Ip_ClockMonitorEmpty_ClearStatus/3 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
Clock_Ip_ClockMonitorEmpty_Set/1 (Clock_Ip_ClockMonitorEmpty_Set) @0622a620
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  Address is taken.
  References: 
  Referring: Clock_Ip_axCmuCallbacks/13 (addr) 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
Clock_Ip_ClockMonitorEmpty/0 (Clock_Ip_ClockMonitorEmpty) @0622a380
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  Address is taken.
  References: 
  Referring: Clock_Ip_axCmuCallbacks/13 (addr) Clock_Ip_axCmuCallbacks/13 (addr) 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
Clock_Ip_CMU_ClockFailInt ()
{
  uint32 IndexCmu;
  uint32 CmuIsrValue;
  struct Clock_Ip_ClockMonitorType * _1;
  long unsigned int _2;
  const struct Clock_Ip_ClockConfigType * Clock_Ip_pxConfig.0_3;
  long unsigned int _4;
  <unnamed type> _5;

  <bb 2> [local count: 214748366]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG IndexCmu => 0
  goto <bb 7>; [100.00%]

  <bb 3> [local count: 858993457]:
  # DEBUG BEGIN_STMT
  _1 = Clock_Ip_apxCmu[IndexCmu_6];
  _2 ={v} _1->SR;
  CmuIsrValue_10 = _2 & 3;
  # DEBUG CmuIsrValue => CmuIsrValue_10
  # DEBUG BEGIN_STMT
  _1->SR ={v} CmuIsrValue_10;
  # DEBUG BEGIN_STMT
  Clock_Ip_pxConfig.0_3 = Clock_Ip_pxConfig;
  if (Clock_Ip_pxConfig.0_3 != 0B)
    goto <bb 4>; [70.00%]
  else
    goto <bb 6>; [30.00%]

  <bb 4> [local count: 601295423]:
  # DEBUG BEGIN_STMT
  _4 = _1->IER;
  # DEBUG CmuIerValue => _4 & 3
  # DEBUG BEGIN_STMT
  CmuIsrValue_12 = _4 & CmuIsrValue_10;
  # DEBUG CmuIsrValue => CmuIsrValue_12
  # DEBUG BEGIN_STMT
  if (CmuIsrValue_12 != 0)
    goto <bb 5>; [33.00%]
  else
    goto <bb 6>; [67.00%]

  <bb 5> [local count: 198427488]:
  # DEBUG BEGIN_STMT
  _5 = Clock_Ip_aeCmuNames[IndexCmu_6];
  Clock_Ip_ReportClockErrors (0, _5);

  <bb 6> [local count: 858993458]:
  # DEBUG BEGIN_STMT
  IndexCmu_14 = IndexCmu_6 + 1;
  # DEBUG IndexCmu => IndexCmu_14

  <bb 7> [local count: 1073741824]:
  # IndexCmu_6 = PHI <0(2), IndexCmu_14(6)>
  # DEBUG IndexCmu => IndexCmu_6
  # DEBUG BEGIN_STMT
  if (IndexCmu_6 != 4)
    goto <bb 3>; [80.00%]
  else
    goto <bb 8>; [20.00%]

  <bb 8> [local count: 214748368]:
  return;

}


Clock_Ip_CMU_GetInterruptStatus (uint8 IndexCmu)
{
  uint32 CmuIsrValue;
  int _1;
  struct Clock_Ip_ClockMonitorType * _2;
  long unsigned int _3;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = (int) IndexCmu_4(D);
  _2 = Clock_Ip_apxCmu[_1];
  _3 ={v} _2->SR;
  CmuIsrValue_6 = _3 & 3;
  # DEBUG CmuIsrValue => CmuIsrValue_6
  # DEBUG BEGIN_STMT
  return CmuIsrValue_6;

}


Clock_Ip_EnableCmuFcFceRefCntLfrefHfref (const struct Clock_Ip_CmuConfigType * Config)
{
  struct Clock_Ip_ClockMonitorType * const CmuFc;
  <unnamed type> _1;
  unsigned char _2;
  int _3;
  unsigned char _4;
  long unsigned int _5;
  long unsigned int _6;
  long unsigned int _7;
  long unsigned int _8;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  _1 = Config_11(D)->Name;
  _2 = Clock_Ip_au8ClockFeatures[_1][8];
  _3 = (int) _2;
  # DEBUG D#4 => &Clock_Ip_axCmuInfo[_3]
  # DEBUG CmuInformation => D#4
  # DEBUG BEGIN_STMT
  CmuFc_12 = MEM <const struct Clock_Ip_CmuInfoType[6]> [(const struct Clock_Ip_CmuInfoType *)&Clock_Ip_axCmuInfo][_3].CmuInstance;
  # DEBUG CmuFc => CmuFc_12
  # DEBUG BEGIN_STMT
  _4 = Config_11(D)->Enable;
  if (_4 != 0)
    goto <bb 3>; [50.00%]
  else
    goto <bb 4>; [50.00%]

  <bb 3> [local count: 536870913]:
  # DEBUG BEGIN_STMT
  _5 = CmuFc_12->GCR;
  _6 = _5 | 1;
  CmuFc_12->GCR = _6;
  goto <bb 5>; [100.00%]

  <bb 4> [local count: 536870913]:
  # DEBUG BEGIN_STMT
  _7 = CmuFc_12->GCR;
  _8 = _7 & 4294967294;
  CmuFc_12->GCR = _8;

  <bb 5> [local count: 1073741824]:
  return;

}


Clock_Ip_GetStatusCmuFcFceRefCntLfrefHfref (Clock_Ip_NameType Name)
{
  uint32 CmuIsrValue;
  Clock_Ip_CmuStatusType Status;
  const struct Clock_Ip_ClockMonitorType * CmuFc;
  unsigned char _1;
  int _2;
  long unsigned int _3;
  long unsigned int _4;
  long unsigned int _5;
  long unsigned int _6;
  long unsigned int _7;
  long unsigned int _8;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  _1 = Clock_Ip_au8ClockFeatures[Name_11(D)][8];
  _2 = (int) _1;
  # DEBUG D#3 => &Clock_Ip_axCmuInfo[_2]
  # DEBUG CmuInformation => D#3
  # DEBUG BEGIN_STMT
  CmuFc_12 = MEM <const struct Clock_Ip_CmuInfoType[6]> [(const struct Clock_Ip_CmuInfoType *)&Clock_Ip_axCmuInfo][_2].CmuInstance;
  # DEBUG CmuFc => CmuFc_12
  # DEBUG BEGIN_STMT
  # DEBUG Status => 3
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _3 ={v} CmuFc_12->SR;
  CmuIsrValue_13 = _3 & 3;
  # DEBUG CmuIsrValue => CmuIsrValue_13
  # DEBUG BEGIN_STMT
  _4 = CmuFc_12->IER;
  # DEBUG CmuIerValue => _4 & 3
  # DEBUG BEGIN_STMT
  CmuIsrValue_14 = _4 & CmuIsrValue_13;
  # DEBUG CmuIsrValue => CmuIsrValue_14
  # DEBUG BEGIN_STMT
  _5 = CmuFc_12->GCR;
  _6 = _5 & 1;
  if (_6 != 0)
    goto <bb 3>; [65.00%]
  else
    goto <bb 6>; [35.00%]

  <bb 3> [local count: 697932185]:
  # DEBUG BEGIN_STMT
  _7 = CmuIsrValue_14 & 2;
  if (_7 != 0)
    goto <bb 6>; [50.00%]
  else
    goto <bb 4>; [50.00%]

  <bb 4> [local count: 348966092]:
  # DEBUG BEGIN_STMT
  _8 = CmuIsrValue_14 & 1;
  if (_8 != 0)
    goto <bb 6>; [35.00%]
  else
    goto <bb 5>; [65.00%]

  <bb 5> [local count: 226827959]:
  # DEBUG BEGIN_STMT
  # DEBUG Status => 0

  <bb 6> [local count: 1073741824]:
  # Status_9 = PHI <3(2), 1(3), 2(4), 0(5)>
  # DEBUG Status => Status_9
  # DEBUG BEGIN_STMT
  return Status_9;

}


Clock_Ip_ClearStatusCmuFcFceRefCntLfrefHfref (Clock_Ip_NameType Name)
{
  uint32 CmuIsrValue;
  struct Clock_Ip_ClockMonitorType * const CmuFc;
  unsigned char _1;
  int _2;
  long unsigned int _3;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  _1 = Clock_Ip_au8ClockFeatures[Name_5(D)][8];
  _2 = (int) _1;
  # DEBUG D#2 => &Clock_Ip_axCmuInfo[_2]
  # DEBUG CmuInformation => D#2
  # DEBUG BEGIN_STMT
  CmuFc_6 = MEM <const struct Clock_Ip_CmuInfoType[6]> [(const struct Clock_Ip_CmuInfoType *)&Clock_Ip_axCmuInfo][_2].CmuInstance;
  # DEBUG CmuFc => CmuFc_6
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _3 ={v} CmuFc_6->SR;
  CmuIsrValue_7 = _3 & 3;
  # DEBUG CmuIsrValue => CmuIsrValue_7
  # DEBUG BEGIN_STMT
  CmuFc_6->SR ={v} CmuIsrValue_7;
  return;

}


Clock_Ip_SetCmuFcFceRefCntLfrefHfref (const struct Clock_Ip_CmuConfigType * Config, uint32 Index)
{
  uint32 DividerResult;
  uint32 DivideBy;
  uint32 Cmp2;
  uint32 Cmp1;
  uint32 LfRef;
  uint32 HfRef;
  uint32 RefCount;
  uint32 BusClk;
  uint32 MonitoredClk;
  uint32 ReferenceClk;
  static uint32 Hash[4];
  struct Clock_Ip_ClockMonitorType * const CmuFc;
  <unnamed type> _1;
  unsigned char _2;
  int _3;
  long unsigned int _4;
  unsigned char _5;
  long unsigned int _6;
  long unsigned int _7;
  long unsigned int _8;
  long unsigned int _9;
  long unsigned int _10;
  long unsigned int _11;
  const struct Clock_Ip_ClockConfigType * Clock_Ip_pxConfig.2_12;
  <unnamed type> _13;
  unsigned char _14;
  int _15;
  long unsigned int _16;
  <unnamed type> _17;
  unsigned char _18;
  int _19;
  long unsigned int _20;
  long unsigned int _21;
  long unsigned int _22;
  long unsigned int _23;
  long unsigned int _24;
  long unsigned int _25;
  long unsigned int _26;
  long unsigned int _27;
  long unsigned int _28;
  long unsigned int _29;
  long unsigned int _30;
  long unsigned int _31;
  long unsigned int _32;
  long unsigned int _33;
  long unsigned int _34;
  long unsigned int _39;
  long unsigned int _40;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  _1 = Config_37(D)->Name;
  _2 = Clock_Ip_au8ClockFeatures[_1][8];
  _3 = (int) _2;
  # DEBUG D#1 => &Clock_Ip_axCmuInfo[_3]
  # DEBUG CmuInformation => D#1
  # DEBUG BEGIN_STMT
  CmuFc_38 = MEM <const struct Clock_Ip_CmuInfoType[6]> [(const struct Clock_Ip_CmuInfoType *)&Clock_Ip_axCmuInfo][_3].CmuInstance;
  # DEBUG CmuFc => CmuFc_38
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG ReferenceClk => 0
  # DEBUG BEGIN_STMT
  # DEBUG MonitoredClk => 0
  # DEBUG BEGIN_STMT
  # DEBUG BusClk => 0
  # DEBUG BEGIN_STMT
  # DEBUG RefCount => 0
  # DEBUG BEGIN_STMT
  # DEBUG HfRef => 0
  # DEBUG BEGIN_STMT
  # DEBUG LfRef => 0
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _4 = Hash[Index_41(D)];
  _5 = Config_37(D)->Enable;
  _6 = (long unsigned int) _5;
  _7 = Config_37(D)->Interrupt;
  _8 = _6 ^ _7;
  _9 = Config_37(D)->MonitoredClockFrequency;
  _10 = _8 ^ _9;
  _11 = _1 ^ _10;
  if (_4 != _11)
    goto <bb 3>; [66.00%]
  else
    goto <bb 7>; [34.00%]

  <bb 3> [local count: 708669601]:
  # DEBUG BEGIN_STMT
  Hash[Index_41(D)] = _11;
  # DEBUG BEGIN_STMT
  Clock_Ip_pxConfig.2_12 = Clock_Ip_pxConfig;
  _13 = MEM <const struct Clock_Ip_CmuInfoType[6]> [(const struct Clock_Ip_CmuInfoType *)&Clock_Ip_axCmuInfo][_3].Reference;
  _14 = Clock_Ip_FreqIds[_13];
  _15 = (int) _14;
  _16 = Clock_Ip_pxConfig.2_12->ConfiguredFrequencies[_15].ConfiguredFrequencyValue;
  ReferenceClk_43 = _16 / 1000;
  # DEBUG ReferenceClk => ReferenceClk_43
  # DEBUG BEGIN_STMT
  _17 = MEM <const struct Clock_Ip_CmuInfoType[6]> [(const struct Clock_Ip_CmuInfoType *)&Clock_Ip_axCmuInfo][_3].Bus;
  _18 = Clock_Ip_FreqIds[_17];
  _19 = (int) _18;
  _20 = Clock_Ip_pxConfig.2_12->ConfiguredFrequencies[_19].ConfiguredFrequencyValue;
  BusClk_44 = _20 / 1000;
  # DEBUG BusClk => BusClk_44
  # DEBUG BEGIN_STMT
  MonitoredClk_45 = _9 / 1000;
  # DEBUG MonitoredClk => MonitoredClk_45
  # DEBUG BEGIN_STMT
  if (_16 > 999)
    goto <bb 4>; [50.00%]
  else
    goto <bb 7>; [50.00%]

  <bb 4> [local count: 354334800]:
  if (_20 > 999)
    goto <bb 5>; [50.00%]
  else
    goto <bb 7>; [50.00%]

  <bb 5> [local count: 177167400]:
  if (_9 > 999)
    goto <bb 6>; [50.00%]
  else
    goto <bb 7>; [50.00%]

  <bb 6> [local count: 88583700]:
  # DEBUG BEGIN_STMT
  _21 = ReferenceClk_43 * 3;
  _22 = _21 / BusClk_44;
  Cmp1_46 = _22 + 1;
  # DEBUG Cmp1 => Cmp1_46
  # DEBUG BEGIN_STMT
  _23 = ReferenceClk_43 * 5;
  _24 = _23 / MonitoredClk_45;
  Cmp2_47 = _24 + 9;
  # DEBUG Cmp2 => Cmp2_47
  # DEBUG BEGIN_STMT
  RefCount_48 = MAX_EXPR <Cmp1_46, Cmp2_47>;
  # DEBUG RefCount => RefCount_48
  # DEBUG BEGIN_STMT
  _25 = MonitoredClk_45 * RefCount_48;
  HfRef_49 = _25 * 1011;
  # DEBUG HfRef => HfRef_49
  # DEBUG BEGIN_STMT
  DivideBy_50 = ReferenceClk_43 * 967;
  # DEBUG DivideBy => DivideBy_50
  # DEBUG BEGIN_STMT
  DividerResult_51 = HfRef_49 / DivideBy_50;
  # DEBUG DividerResult => DividerResult_51
  # DEBUG BEGIN_STMT
  _39 = HfRef_49 % DivideBy_50;
  # DEBUG ModuloValue => _39
  # DEBUG BEGIN_STMT
  _26 = DividerResult_51 * 10;
  _27 = _39 * 10;
  _28 = _27 / DivideBy_50;
  _29 = _26 + _28;
  HfRef_52 = _29 + 4;
  # DEBUG HfRef => HfRef_52
  # DEBUG BEGIN_STMT
  LfRef_53 = _25 * 989;
  # DEBUG LfRef => LfRef_53
  # DEBUG BEGIN_STMT
  DivideBy_54 = ReferenceClk_43 * 1033;
  # DEBUG DivideBy => DivideBy_54
  # DEBUG BEGIN_STMT
  DividerResult_55 = LfRef_53 / DivideBy_54;
  # DEBUG DividerResult => DividerResult_55
  # DEBUG BEGIN_STMT
  _40 = LfRef_53 % DivideBy_54;
  # DEBUG ModuloValue => _40
  # DEBUG BEGIN_STMT
  _30 = DividerResult_55 * 10;
  _31 = _40 * 10;
  _32 = _31 / DivideBy_54;
  _33 = _30 + _32;
  LfRef_56 = _33 + 4294967293;
  # DEBUG LfRef => LfRef_56
  # DEBUG BEGIN_STMT
  _34 = RefCount_48 * 10;
  CmuFc_38->RCCR = _34;
  # DEBUG BEGIN_STMT
  CmuFc_38->HTCR = HfRef_52;
  # DEBUG BEGIN_STMT
  CmuFc_38->LTCR = LfRef_56;

  <bb 7> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  CmuFc_38->IER = _7;
  return;

}


Clock_Ip_ResetCmuFcFceRefCntLfrefHfref (const struct Clock_Ip_CmuConfigType * Config)
{
  <unnamed type> _1;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  _1 = Config_3(D)->Name;
  Clock_Ip_DisableCmuFcFceRefCntLfrefHfref (_1);
  return;

}


Clock_Ip_DisableCmuFcFceRefCntLfrefHfref (Clock_Ip_NameType Name)
{
  uint32 FrequencyCheckStatus;
  uint32 TimeoutTicks;
  uint32 ElapsedTime;
  uint32 StartTime;
  boolean TimeoutOccurred;
  struct Clock_Ip_ClockMonitorType * const CmuFc;
  unsigned char _1;
  int _2;
  long unsigned int _3;
  long unsigned int _4;
  long unsigned int _5;
  long unsigned int TimeoutTicks.1_6;
  long unsigned int _7;
  long unsigned int _8;
  long unsigned int _9;
  long unsigned int _10;
  long unsigned int _11;
  long unsigned int _12;
  long unsigned int _13;
  long unsigned int _14;
  long unsigned int _15;
  long unsigned int _16;

  <bb 2> [local count: 348071305]:
  # DEBUG BEGIN_STMT
  _1 = Clock_Ip_au8ClockFeatures[Name_20(D)][8];
  _2 = (int) _1;
  # DEBUG D#5 => &Clock_Ip_axCmuInfo[_2]
  # DEBUG CmuInformation => D#5
  # DEBUG BEGIN_STMT
  CmuFc_22 = MEM <const struct Clock_Ip_CmuInfoType[6]> [(const struct Clock_Ip_CmuInfoType *)&Clock_Ip_axCmuInfo][_2].CmuInstance;
  # DEBUG CmuFc => CmuFc_22
  # DEBUG BEGIN_STMT
  # DEBUG TimeoutOccurred => 0
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  SchM_Enter_Mcu_MCU_EXCLUSIVE_AREA_01 ();
  # DEBUG BEGIN_STMT
  _3 = CmuFc_22->GCR;
  _4 = _3 & 1;
  if (_4 != 0)
    goto <bb 3>; [33.00%]
  else
    goto <bb 9>; [67.00%]

  <bb 3> [local count: 114863530]:
  # DEBUG BEGIN_STMT
  Clock_Ip_StartTimeout (&StartTime, &ElapsedTime, &TimeoutTicks, 50000);

  <bb 4> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _5 ={v} CmuFc_22->SR;
  FrequencyCheckStatus_27 = _5 & 16;
  # DEBUG FrequencyCheckStatus => FrequencyCheckStatus_27
  # DEBUG BEGIN_STMT
  TimeoutTicks.1_6 = TimeoutTicks;
  TimeoutOccurred_29 = Clock_Ip_TimeoutExpired (&StartTime, &ElapsedTime, TimeoutTicks.1_6);
  # DEBUG TimeoutOccurred => TimeoutOccurred_29
  # DEBUG BEGIN_STMT
  if (FrequencyCheckStatus_27 == 0)
    goto <bb 5>; [94.50%]
  else
    goto <bb 6>; [5.50%]

  <bb 5> [local count: 1014686026]:
  if (TimeoutOccurred_29 != 0)
    goto <bb 6>; [5.50%]
  else
    goto <bb 11>; [94.50%]

  <bb 11> [local count: 958878294]:
  goto <bb 4>; [100.00%]

  <bb 6> [local count: 114863531]:
  # TimeoutOccurred_21 = PHI <TimeoutOccurred_29(4), TimeoutOccurred_29(5)>
  # DEBUG BEGIN_STMT
  if (TimeoutOccurred_21 != 0)
    goto <bb 7>; [33.00%]
  else
    goto <bb 8>; [67.00%]

  <bb 7> [local count: 37904965]:
  # DEBUG BEGIN_STMT
  Clock_Ip_ReportClockErrors (1, Name_20(D));
  goto <bb 10>; [100.00%]

  <bb 8> [local count: 76958566]:
  # DEBUG BEGIN_STMT
  _7 = CmuFc_22->GCR;
  _8 = _7 & 4294967294;
  CmuFc_22->GCR = _8;
  # DEBUG BEGIN_STMT
  _9 = CmuFc_22->IER;
  _10 = _9 & 4294967280;
  CmuFc_22->IER = _10;
  # DEBUG BEGIN_STMT
  _11 ={v} CmuFc_22->SR;
  _12 = _11 | 3;
  CmuFc_22->SR ={v} _12;
  goto <bb 10>; [100.00%]

  <bb 9> [local count: 233207775]:
  # DEBUG BEGIN_STMT
  _13 = CmuFc_22->IER;
  _14 = _13 & 4294967280;
  CmuFc_22->IER = _14;
  # DEBUG BEGIN_STMT
  _15 ={v} CmuFc_22->SR;
  _16 = _15 | 3;
  CmuFc_22->SR ={v} _16;

  <bb 10> [local count: 348071307]:
  # DEBUG BEGIN_STMT
  SchM_Exit_Mcu_MCU_EXCLUSIVE_AREA_01 ();
  StartTime ={v} {CLOBBER};
  ElapsedTime ={v} {CLOBBER};
  TimeoutTicks ={v} {CLOBBER};
  return;

}


Clock_Ip_ClockMonitorEmpty_GetStatus (Clock_Ip_NameType Name)
{
  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  return 3;

}


Clock_Ip_ClockMonitorEmpty_ClearStatus (Clock_Ip_NameType Name)
{
  <bb 2> [local count: 1073741824]:
  Clock_Ip_ClockMonitorEmpty_Disable (Name_1(D)); [tail call]
  return;

}


Clock_Ip_ClockMonitorEmpty_Disable (Clock_Ip_NameType Name)
{
  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  return;

}


Clock_Ip_ClockMonitorEmpty_Set (const struct Clock_Ip_CmuConfigType * Config, uint32 Index)
{
  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  return;

}


Clock_Ip_ClockMonitorEmpty (const struct Clock_Ip_CmuConfigType * Config)
{
  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  return;

}


