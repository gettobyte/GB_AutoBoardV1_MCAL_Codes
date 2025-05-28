Creating summary for Clock_Ip_PRAMCSetRamIWS.part.0/26:


Creating summary for Clock_Ip_PRAMCSetRamIWS/17:


Creating summary for Clock_Ip_FLASH_SetFlashIWS/16:


Creating summary for Clock_Ip_Command/15:
  Descriptor for parameter 0 ConfigD.6642
    unused with 0 call_uses
    by_ref with 0 pass throughs
  Descriptor for parameter 1 CommandD.6643
    not a candidate
----------------------------------------
  Descriptor for parameter 0 ConfigD.6642
    (locally) unused
    param_size_limit: 4, size_reached: 0, by_ref
  Descriptor for parameter 1 CommandD.6643
    not a candidate for splitting


Creating summary for Clock_Ip_ClockPowerModeChangeNotification/14:
  Descriptor for parameter 0 PowerModeD.6638
    (locally) unused
    not a candidate for splitting
  Descriptor for parameter 1 NotificationD.6639
    (locally) unused
    not a candidate for splitting


Creating summary for Clock_Ip_ClockInitializeObjects/13:


Creating summary for EnableSircInStandbyMode/12:


Creating summary for DisableSircInStandbyMode/11:


Creating summary for EnableFircInStandbyMode/10:


Creating summary for DisableFircInStandbyMode/9:


Creating summary for Clock_Ip_McMeEnterKey/7:


Creating summary for Clock_Ip_SetFlashWaitStates/6:


Creating summary for Clock_Ip_SetRamWaitStates/5:


Creating summary for Clock_Ip_CodeInRamSetFlashWaitStates/4:


Creating summary for Clock_Ip_PowerClockIpModules/3:



========== IPA-SRA IPA stage ==========

Summary for node Clock_Ip_PRAMCSetRamIWS.part.0/26:
  No parameter information. 


Summary for node Clock_Ip_PRAMCSetRamIWS/17:
  No parameter information. 

  Summary for edge Clock_Ip_PRAMCSetRamIWS/17->Clock_Ip_PRAMCSetRamIWS.part.0/26:
    return value ignored

Summary for node Clock_Ip_FLASH_SetFlashIWS/16:
  No parameter information. 


Summary for node Clock_Ip_Command/15:
  Descriptor for parameter 0:
    (locally) unused
    param_size_limit: 4, size_reached: 0, by_ref
  Descriptor for parameter 1:
    not a candidate for splitting

  Summary for edge Clock_Ip_Command/15->Clock_Ip_PowerClockIpModules/3:
    return value ignored
  Summary for edge Clock_Ip_Command/15->Clock_Ip_ClockInitializeObjects/13:
    return value ignored

Summary for node Clock_Ip_ClockPowerModeChangeNotification/14:
  Descriptor for parameter 0:
    (locally) unused
    not a candidate for splitting
  Descriptor for parameter 1:
    (locally) unused
    not a candidate for splitting


Summary for node Clock_Ip_ClockInitializeObjects/13:
  No parameter information. 


Summary for node EnableSircInStandbyMode/12:
  No parameter information. 


Summary for node DisableSircInStandbyMode/11:
  No parameter information. 


Summary for node EnableFircInStandbyMode/10:
  No parameter information. 


Summary for node DisableFircInStandbyMode/9:
  No parameter information. 


Summary for node Clock_Ip_McMeEnterKey/7:
  No parameter information. 


Summary for node Clock_Ip_SetFlashWaitStates/6:
  No parameter information. 

  Summary for edge Clock_Ip_SetFlashWaitStates/6->Clock_Ip_FLASH_SetFlashIWS/16:
    return value ignored

Summary for node Clock_Ip_SetRamWaitStates/5:
  No parameter information. 

  Summary for edge Clock_Ip_SetRamWaitStates/5->Clock_Ip_PRAMCSetRamIWS/17:
    return value ignored

Summary for node Clock_Ip_CodeInRamSetFlashWaitStates/4:
  No parameter information. 


Summary for node Clock_Ip_PowerClockIpModules/3:
  No parameter information. 

  Summary for edge Clock_Ip_PowerClockIpModules/3->Clock_Ip_ReportClockErrors/23:
    return value ignored
  Summary for edge Clock_Ip_PowerClockIpModules/3->Clock_Ip_TimeoutExpired/22:
  Summary for edge Clock_Ip_PowerClockIpModules/3->Clock_Ip_StartTimeout/21:
    return value ignored
  Summary for edge Clock_Ip_PowerClockIpModules/3->Clock_Ip_McMeEnterKey/7:
    return value ignored
  Summary for edge Clock_Ip_PowerClockIpModules/3->Clock_Ip_ReportClockErrors/23:
    return value ignored
  Summary for edge Clock_Ip_PowerClockIpModules/3->Clock_Ip_TimeoutExpired/22:
  Summary for edge Clock_Ip_PowerClockIpModules/3->Clock_Ip_StartTimeout/21:
    return value ignored
  Summary for edge Clock_Ip_PowerClockIpModules/3->Clock_Ip_McMeEnterKey/7:
    return value ignored
  Summary for edge Clock_Ip_PowerClockIpModules/3->Clock_Ip_ReportClockErrors/23:
    return value ignored
  Summary for edge Clock_Ip_PowerClockIpModules/3->Clock_Ip_TimeoutExpired/22:
  Summary for edge Clock_Ip_PowerClockIpModules/3->Clock_Ip_StartTimeout/21:
    return value ignored
  Summary for edge Clock_Ip_PowerClockIpModules/3->Clock_Ip_McMeEnterKey/7:
    return value ignored
  Summary for edge Clock_Ip_PowerClockIpModules/3->Clock_Ip_ReportClockErrors/23:
    return value ignored
  Summary for edge Clock_Ip_PowerClockIpModules/3->Clock_Ip_TimeoutExpired/22:
  Summary for edge Clock_Ip_PowerClockIpModules/3->Clock_Ip_StartTimeout/21:
    return value ignored
  Summary for edge Clock_Ip_PowerClockIpModules/3->Clock_Ip_McMeEnterKey/7:
    return value ignored


Function Clock_Ip_McMeEnterKey/7 disqualified because it cannot be made local.
Function Clock_Ip_CodeInRamSetFlashWaitStates/4 disqualified because it cannot be made local.
Function Clock_Ip_PRAMCSetRamIWS/17 disqualified because it cannot be made local.
Function Clock_Ip_SetRamWaitStates/5 disqualified because it cannot be made local.
Function Clock_Ip_FLASH_SetFlashIWS/16 disqualified because it cannot be made local.
Function Clock_Ip_SetFlashWaitStates/6 disqualified because it cannot be made local.
Function DisableFircInStandbyMode/9 disqualified because it cannot be made local.
Function EnableFircInStandbyMode/10 disqualified because it cannot be made local.
Function DisableSircInStandbyMode/11 disqualified because it cannot be made local.
Function EnableSircInStandbyMode/12 disqualified because it cannot be made local.
Function Clock_Ip_ClockPowerModeChangeNotification/14 disqualified because it cannot be made local.
Function Clock_Ip_Command/15 disqualified because it cannot be made local.

========== IPA-SRA decisions ==========

========== IPA SRA IPA analysis done ==========


Reclaiming functions:
Reclaiming variables:
Clearing address taken flags:
Symbol table:

Clock_Ip_PRAMCSetRamIWS.part.0/26 (Clock_Ip_PRAMCSetRamIWS.part.0) @064620e0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly artificial
  References: 
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) body local split_part optimize_size
  Called by: Clock_Ip_PRAMCSetRamIWS/17 (354334801 (estimated locally),0.33 per call) 
  Calls: 
Clock_Ip_FreqIds/25 (Clock_Ip_FreqIds) @063274c8
  Type: variable
  Body removed by symtab_remove_unreachable_nodes
  Visibility: external public
  References: 
  Referring: Clock_Ip_CodeInRamSetFlashWaitStates/4 (read) Clock_Ip_PRAMCSetRamIWS/17 (read) Clock_Ip_PRAMCSetRamIWS/17 (read) 
  Availability: not_available
  Varpool flags:
Clock_Ip_pxConfig/24 (Clock_Ip_pxConfig) @06327480
  Type: variable
  Body removed by symtab_remove_unreachable_nodes
  Visibility: external public
  References: 
  Referring: Clock_Ip_CodeInRamSetFlashWaitStates/4 (read) Clock_Ip_PRAMCSetRamIWS/17 (read) 
  Availability: not_available
  Varpool flags:
Clock_Ip_ReportClockErrors/23 (Clock_Ip_ReportClockErrors) @062e4ee0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Clock_Ip_PowerClockIpModules/3 (37904965 (estimated locally),0.11 per call) Clock_Ip_PowerClockIpModules/3 (37904965 (estimated locally),0.11 per call) Clock_Ip_PowerClockIpModules/3 (37904965 (estimated locally),0.11 per call) Clock_Ip_PowerClockIpModules/3 (37904965 (estimated locally),0.11 per call) 
  Calls: 
Clock_Ip_TimeoutExpired/22 (Clock_Ip_TimeoutExpired) @062e4e00
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Clock_Ip_PowerClockIpModules/3 (1073741824 (estimated locally),3.08 per call) Clock_Ip_PowerClockIpModules/3 (1073741821 (estimated locally),3.08 per call) Clock_Ip_PowerClockIpModules/3 (1073741817 (estimated locally),3.08 per call) Clock_Ip_PowerClockIpModules/3 (1073741813 (estimated locally),3.08 per call) 
  Calls: 
Clock_Ip_StartTimeout/21 (Clock_Ip_StartTimeout) @062e4d20
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Clock_Ip_PowerClockIpModules/3 (114863530 (estimated locally),0.33 per call) Clock_Ip_PowerClockIpModules/3 (114863530 (estimated locally),0.33 per call) Clock_Ip_PowerClockIpModules/3 (114863529 (estimated locally),0.33 per call) Clock_Ip_PowerClockIpModules/3 (114863529 (estimated locally),0.33 per call) 
  Calls: 
Clock_Ip_axIntOscCallbacks/20 (Clock_Ip_axIntOscCallbacks) @062e8c60
  Type: variable
  Body removed by symtab_remove_unreachable_nodes
  Visibility: external public
  References: 
  Referring: Clock_Ip_ClockInitializeObjects/13 (addr) Clock_Ip_ClockInitializeObjects/13 (addr) 
  Availability: not_available
  Varpool flags: read-only
Clock_Ip_au8IrcoscCallbackIndex/19 (Clock_Ip_au8IrcoscCallbackIndex) @062e8c18
  Type: variable
  Body removed by symtab_remove_unreachable_nodes
  Visibility: external public
  References: 
  Referring: Clock_Ip_ClockInitializeObjects/13 (read) Clock_Ip_ClockInitializeObjects/13 (read) 
  Availability: not_available
  Varpool flags: read-only
Clock_Ip_bObjectsAreInitialized.0/18 (Clock_Ip_bObjectsAreInitialized) @062e8bd0
  Type: variable definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: Clock_Ip_ClockInitializeObjects/13 (read) Clock_Ip_ClockInitializeObjects/13 (write) 
  Availability: available
  Varpool flags: initialized
Clock_Ip_PRAMCSetRamIWS/17 (Clock_Ip_PRAMCSetRamIWS) @062dd620
  Type: function definition analyzed
  Visibility: externally_visible public
  References: Clock_Ip_pxConfig/24 (read) Clock_Ip_FreqIds/25 (read) Clock_Ip_FreqIds/25 (read) 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: Clock_Ip_SetRamWaitStates/5 (1073741824 (estimated locally),1.00 per call) 
  Calls: Clock_Ip_PRAMCSetRamIWS.part.0/26 (354334801 (estimated locally),0.33 per call) 
Clock_Ip_FLASH_SetFlashIWS/16 (Clock_Ip_FLASH_SetFlashIWS) @062dd0e0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: Clock_Ip_SetFlashWaitStatesCallback/2 (read) 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: Clock_Ip_SetFlashWaitStates/6 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
   Indirect call(1073741824 (estimated locally),1.00 per call)  Num speculative call targets: 0
Clock_Ip_Command/15 (Clock_Ip_Command) @062ddd20
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741817 (estimated locally) body optimize_size
  Called by: 
  Calls: Clock_Ip_PowerClockIpModules/3 (357913942 (estimated locally),0.33 per call) Clock_Ip_ClockInitializeObjects/13 (357913942 (estimated locally),0.33 per call) 
Clock_Ip_ClockPowerModeChangeNotification/14 (Clock_Ip_ClockPowerModeChangeNotification) @062dda80
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
Clock_Ip_ClockInitializeObjects/13 (Clock_Ip_ClockInitializeObjects) @062dd7e0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: Clock_Ip_bObjectsAreInitialized.0/18 (read) Clock_Ip_bObjectsAreInitialized.0/18 (write) Clock_Ip_au8IrcoscCallbackIndex/19 (read) Clock_Ip_axIntOscCallbacks/20 (addr) Clock_Ip_pxSircStdbyClock/0 (write) Clock_Ip_au8IrcoscCallbackIndex/19 (read) Clock_Ip_axIntOscCallbacks/20 (addr) Clock_Ip_pxFircStdbyClock/1 (write) 
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) body local optimize_size
  Called by: Clock_Ip_Command/15 (357913942 (estimated locally),0.33 per call) 
  Calls: 
EnableSircInStandbyMode/12 (EnableSircInStandbyMode) @062dd540
  Type: function definition analyzed
  Visibility: externally_visible public
  References: Clock_Ip_pxSircStdbyClock/0 (read) 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
   Indirect call(1073741824 (estimated locally),1.00 per call)  Num speculative call targets: 0
DisableSircInStandbyMode/11 (DisableSircInStandbyMode) @062dd2a0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: Clock_Ip_pxSircStdbyClock/0 (read) 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
   Indirect call(1073741824 (estimated locally),1.00 per call)  Num speculative call targets: 0
EnableFircInStandbyMode/10 (EnableFircInStandbyMode) @062dd000
  Type: function definition analyzed
  Visibility: externally_visible public
  References: Clock_Ip_pxFircStdbyClock/1 (read) 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
   Indirect call(1073741824 (estimated locally),1.00 per call)  Num speculative call targets: 0
DisableFircInStandbyMode/9 (DisableFircInStandbyMode) @062d78c0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: Clock_Ip_pxFircStdbyClock/1 (read) 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
   Indirect call(1073741824 (estimated locally),1.00 per call)  Num speculative call targets: 0
Clock_Ip_McMeEnterKey/7 (Clock_Ip_McMeEnterKey) @062d7d20
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: Clock_Ip_PowerClockIpModules/3 (114863530 (estimated locally),0.33 per call) Clock_Ip_PowerClockIpModules/3 (114863530 (estimated locally),0.33 per call) Clock_Ip_PowerClockIpModules/3 (114863529 (estimated locally),0.33 per call) Clock_Ip_PowerClockIpModules/3 (114863529 (estimated locally),0.33 per call) 
  Calls: 
Clock_Ip_SetFlashWaitStates/6 (Clock_Ip_SetFlashWaitStates) @062d7a80
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: Clock_Ip_FLASH_SetFlashIWS/16 (1073741824 (estimated locally),1.00 per call) 
Clock_Ip_SetRamWaitStates/5 (Clock_Ip_SetRamWaitStates) @062d7700
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: Clock_Ip_PRAMCSetRamIWS/17 (1073741824 (estimated locally),1.00 per call) 
Clock_Ip_CodeInRamSetFlashWaitStates/4 (Clock_Ip_CodeInRamSetFlashWaitStates) @062d7460
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  Address is taken.
  References: Clock_Ip_pxConfig/24 (read) Clock_Ip_FreqIds/25 (read) 
  Referring: Clock_Ip_SetFlashWaitStatesCallback/2 (addr) 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
Clock_Ip_PowerClockIpModules/3 (Clock_Ip_PowerClockIpModules) @062d70e0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: local
  Function flags: count:348071301 (estimated locally) body local optimize_size
  Called by: Clock_Ip_Command/15 (357913942 (estimated locally),0.33 per call) 
  Calls: Clock_Ip_ReportClockErrors/23 (37904965 (estimated locally),0.11 per call) Clock_Ip_TimeoutExpired/22 (1073741824 (estimated locally),3.08 per call) Clock_Ip_StartTimeout/21 (114863530 (estimated locally),0.33 per call) Clock_Ip_McMeEnterKey/7 (114863530 (estimated locally),0.33 per call) Clock_Ip_ReportClockErrors/23 (37904965 (estimated locally),0.11 per call) Clock_Ip_TimeoutExpired/22 (1073741821 (estimated locally),3.08 per call) Clock_Ip_StartTimeout/21 (114863530 (estimated locally),0.33 per call) Clock_Ip_McMeEnterKey/7 (114863530 (estimated locally),0.33 per call) Clock_Ip_ReportClockErrors/23 (37904965 (estimated locally),0.11 per call) Clock_Ip_TimeoutExpired/22 (1073741817 (estimated locally),3.08 per call) Clock_Ip_StartTimeout/21 (114863529 (estimated locally),0.33 per call) Clock_Ip_McMeEnterKey/7 (114863529 (estimated locally),0.33 per call) Clock_Ip_ReportClockErrors/23 (37904965 (estimated locally),0.11 per call) Clock_Ip_TimeoutExpired/22 (1073741813 (estimated locally),3.08 per call) Clock_Ip_StartTimeout/21 (114863529 (estimated locally),0.33 per call) Clock_Ip_McMeEnterKey/7 (114863529 (estimated locally),0.33 per call) 
Clock_Ip_SetFlashWaitStatesCallback/2 (Clock_Ip_SetFlashWaitStatesCallback) @061ad288
  Type: variable definition analyzed
  Visibility: prevailing_def_ironly
  References: Clock_Ip_CodeInRamSetFlashWaitStates/4 (addr) 
  Referring: Clock_Ip_FLASH_SetFlashIWS/16 (read) 
  Availability: available
  Varpool flags: initialized read-only const-value-known
Clock_Ip_pxFircStdbyClock/1 (Clock_Ip_pxFircStdbyClock) @061ad1f8
  Type: variable definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: DisableFircInStandbyMode/9 (read) Clock_Ip_ClockInitializeObjects/13 (write) EnableFircInStandbyMode/10 (read) 
  Availability: available
  Varpool flags:
Clock_Ip_pxSircStdbyClock/0 (Clock_Ip_pxSircStdbyClock) @061ad168
  Type: variable definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: DisableSircInStandbyMode/11 (read) Clock_Ip_ClockInitializeObjects/13 (write) EnableSircInStandbyMode/12 (read) 
  Availability: available
  Varpool flags:
Clock_Ip_PRAMCSetRamIWS.part.0 ()
{
  uint32 ConfiguredCoreClock;
  uint32 ConfiguredAipsPlatClock;
  long unsigned int _1;
  long unsigned int _2;
  long unsigned int _3;
  long unsigned int _4;

  <bb 4> [local count: 1073741824]:

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  _1 ={v} MEM[(struct PRAMC_Type *)1076248576B].PRCR1;
  _2 = _1 & 4294967294;
  MEM[(struct PRAMC_Type *)1076248576B].PRCR1 ={v} _2;
  # DEBUG BEGIN_STMT
  _3 ={v} MEM[(struct PRAMC_Type *)1078345728B].PRCR1;
  _4 = _3 & 4294967294;
  MEM[(struct PRAMC_Type *)1078345728B].PRCR1 ={v} _4;

  <bb 3> [local count: 1073741824]:
  return;

}


Clock_Ip_PRAMCSetRamIWS ()
{
  uint32 ConfiguredAipsPlatClock;
  uint32 ConfiguredCoreClock;
  const struct Clock_Ip_ClockConfigType * Clock_Ip_pxConfig.11_1;
  unsigned char _2;
  int _3;
  unsigned char _5;
  int _6;
  long unsigned int _7;
  long unsigned int _8;
  long unsigned int _9;
  long unsigned int _10;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG ConfiguredCoreClock => 0
  # DEBUG BEGIN_STMT
  # DEBUG ConfiguredAipsPlatClock => 0
  # DEBUG BEGIN_STMT
  Clock_Ip_pxConfig.11_1 = Clock_Ip_pxConfig;
  _2 = Clock_Ip_FreqIds[15];
  _3 = (int) _2;
  ConfiguredCoreClock_13 = Clock_Ip_pxConfig.11_1->ConfiguredFrequencies[_3].ConfiguredFrequencyValue;
  # DEBUG ConfiguredCoreClock => ConfiguredCoreClock_13
  # DEBUG BEGIN_STMT
  _5 = Clock_Ip_FreqIds[16];
  _6 = (int) _5;
  ConfiguredAipsPlatClock_14 = Clock_Ip_pxConfig.11_1->ConfiguredFrequencies[_6].ConfiguredFrequencyValue;
  # DEBUG ConfiguredAipsPlatClock => ConfiguredAipsPlatClock_14
  # DEBUG BEGIN_STMT
  if (ConfiguredCoreClock_13 > 80000000)
    goto <bb 4>; [50.00%]
  else
    goto <bb 3>; [50.00%]

  <bb 3> [local count: 536870913]:
  if (ConfiguredCoreClock_13 == ConfiguredAipsPlatClock_14)
    goto <bb 4>; [34.00%]
  else
    goto <bb 5>; [66.00%]

  <bb 4> [local count: 719407025]:
  # DEBUG BEGIN_STMT
  _7 ={v} MEM[(struct PRAMC_Type *)1076248576B].PRCR1;
  _8 = _7 | 1;
  MEM[(struct PRAMC_Type *)1076248576B].PRCR1 ={v} _8;
  # DEBUG BEGIN_STMT
  _9 ={v} MEM[(struct PRAMC_Type *)1078345728B].PRCR1;
  _10 = _9 | 1;
  MEM[(struct PRAMC_Type *)1078345728B].PRCR1 ={v} _10;
  goto <bb 6>; [100.00%]

  <bb 5> [local count: 354334801]:
  Clock_Ip_PRAMCSetRamIWS.part.0 ();

  <bb 6> [local count: 1073741824]:
  return;

}


Clock_Ip_FLASH_SetFlashIWS ()
{
  void (*<T73d>) (void) Clock_Ip_SetFlashWaitStatesCallback.9_1;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  Clock_Ip_SetFlashWaitStatesCallback.9_1 = Clock_Ip_SetFlashWaitStatesCallback;
  Clock_Ip_SetFlashWaitStatesCallback.9_1 ();
  return;

}


Clock_Ip_Command (const struct Clock_Ip_ClockConfigType * Config, Clock_Ip_CommandType Command)
{
  <bb 2> [local count: 1073741817]:
  # DEBUG BEGIN_STMT
  switch (Command_2(D)) <default: <L4> [33.33%], case 1: <L5> [33.33%], case 2: <L0> [33.33%]>

  <bb 3> [local count: 357913942]:
<L0>:
  # DEBUG BEGIN_STMT
  Clock_Ip_ClockInitializeObjects ();
  # DEBUG BEGIN_STMT
  goto <bb 5>; [100.00%]

  <bb 4> [local count: 357913942]:
<L5>:
  # DEBUG BEGIN_STMT
  # DEBUG Config => Config_5(D)
  # DEBUG INLINE_ENTRY Clock_Ip_SpecificPlatformInitClock
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  Clock_Ip_PowerClockIpModules ();

  <bb 5> [local count: 1073741824]:
<L4>:
  # DEBUG Config => NULL
  return;

}


Clock_Ip_ClockPowerModeChangeNotification (Clock_Ip_PowerModesType PowerMode, Clock_Ip_PowerNotificationType Notification)
{
  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  return;

}


Clock_Ip_ClockInitializeObjects ()
{
  static boolean Clock_Ip_bObjectsAreInitialized = 0;
  _Bool Clock_Ip_bObjectsAreInitialized.4_1;
  unsigned char _2;
  int _3;
  const struct Clock_Ip_IntOscCallbackType * _4;
  unsigned char _5;
  int _6;
  const struct Clock_Ip_IntOscCallbackType * _7;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  Clock_Ip_bObjectsAreInitialized.4_1 = Clock_Ip_bObjectsAreInitialized;
  if (Clock_Ip_bObjectsAreInitialized.4_1 != 0)
    goto <bb 4>; [50.00%]
  else
    goto <bb 3>; [50.00%]

  <bb 3> [local count: 536870913]:
  # DEBUG BEGIN_STMT
  Clock_Ip_bObjectsAreInitialized = 1;
  # DEBUG BEGIN_STMT
  _2 = Clock_Ip_au8IrcoscCallbackIndex[2];
  _3 = (int) _2;
  _4 = &Clock_Ip_axIntOscCallbacks[_3];
  Clock_Ip_pxSircStdbyClock = _4;
  # DEBUG BEGIN_STMT
  _5 = Clock_Ip_au8IrcoscCallbackIndex[1];
  _6 = (int) _5;
  _7 = &Clock_Ip_axIntOscCallbacks[_6];
  Clock_Ip_pxFircStdbyClock = _7;

  <bb 4> [local count: 1073741824]:
  return;

}


EnableSircInStandbyMode ()
{
  struct Clock_Ip_IrcoscConfigType SircConfig;
  const struct Clock_Ip_IntOscCallbackType * Clock_Ip_pxSircStdbyClock.3_1;
  void (*<T651>) (const struct Clock_Ip_IrcoscConfigType *) _2;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  SircConfig.Enable = 1;
  # DEBUG BEGIN_STMT
  Clock_Ip_pxSircStdbyClock.3_1 = Clock_Ip_pxSircStdbyClock;
  _2 = Clock_Ip_pxSircStdbyClock.3_1->Enable;
  _2 (&SircConfig);
  SircConfig ={v} {CLOBBER};
  return;

}


DisableSircInStandbyMode ()
{
  const struct Clock_Ip_IntOscCallbackType * Clock_Ip_pxSircStdbyClock.2_1;
  void (*<T654>) (Clock_Ip_NameType) _2;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  Clock_Ip_pxSircStdbyClock.2_1 = Clock_Ip_pxSircStdbyClock;
  _2 = Clock_Ip_pxSircStdbyClock.2_1->Disable;
  _2 (3);
  return;

}


EnableFircInStandbyMode ()
{
  struct Clock_Ip_IrcoscConfigType FircConfig;
  const struct Clock_Ip_IntOscCallbackType * Clock_Ip_pxFircStdbyClock.1_1;
  void (*<T651>) (const struct Clock_Ip_IrcoscConfigType *) _2;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  FircConfig.Enable = 1;
  # DEBUG BEGIN_STMT
  Clock_Ip_pxFircStdbyClock.1_1 = Clock_Ip_pxFircStdbyClock;
  _2 = Clock_Ip_pxFircStdbyClock.1_1->Enable;
  _2 (&FircConfig);
  FircConfig ={v} {CLOBBER};
  return;

}


DisableFircInStandbyMode ()
{
  const struct Clock_Ip_IntOscCallbackType * Clock_Ip_pxFircStdbyClock.0_1;
  void (*<T654>) (Clock_Ip_NameType) _2;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  Clock_Ip_pxFircStdbyClock.0_1 = Clock_Ip_pxFircStdbyClock;
  _2 = Clock_Ip_pxFircStdbyClock.0_1->Disable;
  _2 (1);
  return;

}


Clock_Ip_McMeEnterKey ()
{
  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  MEM[(struct MC_ME_Type *)1076740096B].CTL_KEY ={v} 23280;
  # DEBUG BEGIN_STMT
  MEM[(struct MC_ME_Type *)1076740096B].CTL_KEY ={v} 42255;
  return;

}


Clock_Ip_SetFlashWaitStates ()
{
  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  Clock_Ip_FLASH_SetFlashIWS ();
  return;

}


Clock_Ip_SetRamWaitStates ()
{
  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  Clock_Ip_PRAMCSetRamIWS ();
  return;

}


Clock_Ip_CodeInRamSetFlashWaitStates ()
{
  uint32 ConfiguredCoreClock;
  uint32 RwscSetting;
  const struct Clock_Ip_ClockConfigType * Clock_Ip_pxConfig.10_1;
  unsigned char _2;
  int _3;
  long unsigned int _4;
  long unsigned int _5;
  long unsigned int _6;
  long unsigned int _7;
  long unsigned int _8;
  long unsigned int _9;
  long unsigned int _10;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG RwscSetting => 0
  # DEBUG BEGIN_STMT
  # DEBUG ConfiguredCoreClock => 0
  # DEBUG BEGIN_STMT
  Clock_Ip_pxConfig.10_1 = Clock_Ip_pxConfig;
  _2 = Clock_Ip_FreqIds[15];
  _3 = (int) _2;
  ConfiguredCoreClock_13 = Clock_Ip_pxConfig.10_1->ConfiguredFrequencies[_3].ConfiguredFrequencyValue;
  # DEBUG ConfiguredCoreClock => ConfiguredCoreClock_13
  # DEBUG BEGIN_STMT
  if (ConfiguredCoreClock_13 <= 167000000)
    goto <bb 3>; [50.00%]
  else
    goto <bb 7>; [50.00%]

  <bb 3> [local count: 536870913]:
  # DEBUG BEGIN_STMT
  if (ConfiguredCoreClock_13 <= 66000000)
    goto <bb 10>; [50.00%]
  else
    goto <bb 4>; [50.00%]

  <bb 4> [local count: 268435456]:
  # DEBUG BEGIN_STMT
  if (ConfiguredCoreClock_13 <= 100000000)
    goto <bb 10>; [50.00%]
  else
    goto <bb 5>; [50.00%]

  <bb 5> [local count: 134217728]:
  # DEBUG BEGIN_STMT
  if (ConfiguredCoreClock_13 <= 133000000)
    goto <bb 10>; [50.00%]
  else
    goto <bb 6>; [50.00%]

  <bb 6> [local count: 67108864]:
  # DEBUG BEGIN_STMT
  # DEBUG RwscSetting => 4
  goto <bb 10>; [100.00%]

  <bb 7> [local count: 536870913]:
  # DEBUG BEGIN_STMT
  if (ConfiguredCoreClock_13 <= 200000000)
    goto <bb 10>; [50.00%]
  else
    goto <bb 8>; [50.00%]

  <bb 8> [local count: 268435456]:
  # DEBUG BEGIN_STMT
  if (ConfiguredCoreClock_13 <= 233000000)
    goto <bb 10>; [50.00%]
  else
    goto <bb 9>; [50.00%]

  <bb 9> [local count: 134217728]:
  # DEBUG BEGIN_STMT

  <bb 10> [local count: 1073741824]:
  # RwscSetting_11 = PHI <2(4), 5(7), 6(8), 7(9), 3(5), 1(3), 4(6)>
  # DEBUG RwscSetting => RwscSetting_11
  # DEBUG BEGIN_STMT
  _4 ={v} MEM[(struct FLASH_Type *)1076805632B].CTL;
  _5 = _4 & 4294934527;
  MEM[(struct FLASH_Type *)1076805632B].CTL ={v} _5;
  # DEBUG BEGIN_STMT
  _6 ={v} MEM[(struct FLASH_Type *)1076805632B].CTL;
  _7 = _6 & 4294959359;
  MEM[(struct FLASH_Type *)1076805632B].CTL ={v} _7;
  # DEBUG BEGIN_STMT
  _8 ={v} MEM[(struct FLASH_Type *)1076805632B].CTL;
  _9 = RwscSetting_11 << 8;
  _10 = _8 | _9;
  MEM[(struct FLASH_Type *)1076805632B].CTL ={v} _10;
  return;

}


Clock_Ip_PowerClockIpModules ()
{
  boolean TimeoutOccurred;
  uint32 TimeoutTicks;
  uint32 ElapsedTime;
  uint32 StartTime;
  long unsigned int _2;
  long unsigned int _3;
  long unsigned int _5;
  long unsigned int _7;
  long unsigned int _8;
  long unsigned int _9;
  long unsigned int _10;
  long unsigned int _11;
  long unsigned int TimeoutTicks.5_12;
  long unsigned int _13;
  long unsigned int _14;
  long unsigned int _15;
  long unsigned int _16;
  long unsigned int _17;
  long unsigned int _18;
  long unsigned int _19;
  long unsigned int _20;
  long unsigned int _21;
  long unsigned int _22;
  long unsigned int TimeoutTicks.6_23;
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
  long unsigned int TimeoutTicks.7_34;
  long unsigned int _35;
  long unsigned int _36;
  long unsigned int _37;
  long unsigned int _38;
  long unsigned int _39;
  long unsigned int _40;
  long unsigned int _41;
  long unsigned int _42;
  long unsigned int _43;
  long unsigned int _44;
  long unsigned int TimeoutTicks.8_45;
  long unsigned int _46;
  long unsigned int _47;

  <bb 2> [local count: 348071301]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG TimeoutOccurred => 0
  # DEBUG BEGIN_STMT
  _2 ={v} MEM[(struct MC_ME_Type *)1076740096B].PRTN1_COFB1_STAT;
  _3 = _2 & 16777216;
  if (_3 == 0)
    goto <bb 3>; [33.00%]
  else
    goto <bb 8>; [67.00%]

  <bb 3> [local count: 114863529]:
  # DEBUG BEGIN_STMT
  _5 ={v} MEM[(struct MC_ME_Type *)1076740096B].PRTN1_COFB1_CLKEN;
  _7 = _5 | 16777216;
  MEM[(struct MC_ME_Type *)1076740096B].PRTN1_COFB1_CLKEN ={v} _7;
  # DEBUG BEGIN_STMT
  _8 ={v} MEM[(struct MC_ME_Type *)1076740096B].PRTN1_PCONF;
  _9 = _8 | 1;
  MEM[(struct MC_ME_Type *)1076740096B].PRTN1_PCONF ={v} _9;
  # DEBUG BEGIN_STMT
  _10 ={v} MEM[(struct MC_ME_Type *)1076740096B].PRTN1_PUPD;
  _11 = _10 | 1;
  MEM[(struct MC_ME_Type *)1076740096B].PRTN1_PUPD ={v} _11;
  # DEBUG BEGIN_STMT
  Clock_Ip_McMeEnterKey ();
  # DEBUG BEGIN_STMT
  Clock_Ip_StartTimeout (&StartTime, &ElapsedTime, &TimeoutTicks, 50000);

  <bb 4> [local count: 1073741813]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  TimeoutTicks.5_12 = TimeoutTicks;
  TimeoutOccurred_64 = Clock_Ip_TimeoutExpired (&StartTime, &ElapsedTime, TimeoutTicks.5_12);
  # DEBUG TimeoutOccurred => TimeoutOccurred_64
  # DEBUG BEGIN_STMT
  _13 ={v} MEM[(struct MC_ME_Type *)1076740096B].PRTN1_COFB1_STAT;
  _14 = _13 & 16777216;
  if (_14 == 0)
    goto <bb 5>; [94.50%]
  else
    goto <bb 6>; [5.50%]

  <bb 5> [local count: 1014686014]:
  if (TimeoutOccurred_64 != 0)
    goto <bb 6>; [5.50%]
  else
    goto <bb 30>; [94.50%]

  <bb 30> [local count: 958878283]:
  goto <bb 4>; [100.00%]

  <bb 6> [local count: 114863530]:
  # TimeoutOccurred_56 = PHI <TimeoutOccurred_64(4), TimeoutOccurred_64(5)>
  # DEBUG BEGIN_STMT
  if (TimeoutOccurred_56 != 0)
    goto <bb 7>; [33.00%]
  else
    goto <bb 8>; [67.00%]

  <bb 7> [local count: 37904965]:
  # DEBUG BEGIN_STMT
  Clock_Ip_ReportClockErrors (1, 7);

  <bb 8> [local count: 348071303]:
  # DEBUG BEGIN_STMT
  _15 ={v} MEM[(struct MC_ME_Type *)1076740096B].PRTN1_COFB1_STAT;
  _16 = _15 & 2097152;
  if (_16 == 0)
    goto <bb 9>; [33.00%]
  else
    goto <bb 14>; [67.00%]

  <bb 9> [local count: 114863529]:
  # DEBUG BEGIN_STMT
  _17 ={v} MEM[(struct MC_ME_Type *)1076740096B].PRTN1_COFB1_CLKEN;
  _18 = _17 | 2097152;
  MEM[(struct MC_ME_Type *)1076740096B].PRTN1_COFB1_CLKEN ={v} _18;
  # DEBUG BEGIN_STMT
  _19 ={v} MEM[(struct MC_ME_Type *)1076740096B].PRTN1_PCONF;
  _20 = _19 | 1;
  MEM[(struct MC_ME_Type *)1076740096B].PRTN1_PCONF ={v} _20;
  # DEBUG BEGIN_STMT
  _21 ={v} MEM[(struct MC_ME_Type *)1076740096B].PRTN1_PUPD;
  _22 = _21 | 1;
  MEM[(struct MC_ME_Type *)1076740096B].PRTN1_PUPD ={v} _22;
  # DEBUG BEGIN_STMT
  Clock_Ip_McMeEnterKey ();
  # DEBUG BEGIN_STMT
  Clock_Ip_StartTimeout (&StartTime, &ElapsedTime, &TimeoutTicks, 50000);

  <bb 10> [local count: 1073741817]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  TimeoutTicks.6_23 = TimeoutTicks;
  TimeoutOccurred_72 = Clock_Ip_TimeoutExpired (&StartTime, &ElapsedTime, TimeoutTicks.6_23);
  # DEBUG TimeoutOccurred => TimeoutOccurred_72
  # DEBUG BEGIN_STMT
  _24 ={v} MEM[(struct MC_ME_Type *)1076740096B].PRTN1_COFB1_STAT;
  _25 = _24 & 2097152;
  if (_25 == 0)
    goto <bb 11>; [94.50%]
  else
    goto <bb 12>; [5.50%]

  <bb 11> [local count: 1014686018]:
  if (TimeoutOccurred_72 != 0)
    goto <bb 12>; [5.50%]
  else
    goto <bb 29>; [94.50%]

  <bb 29> [local count: 958878287]:
  goto <bb 10>; [100.00%]

  <bb 12> [local count: 114863530]:
  # TimeoutOccurred_1 = PHI <TimeoutOccurred_72(10), TimeoutOccurred_72(11)>
  # DEBUG BEGIN_STMT
  if (TimeoutOccurred_1 != 0)
    goto <bb 13>; [33.00%]
  else
    goto <bb 14>; [67.00%]

  <bb 13> [local count: 37904965]:
  # DEBUG BEGIN_STMT
  Clock_Ip_ReportClockErrors (1, 5);

  <bb 14> [local count: 348071304]:
  # DEBUG BEGIN_STMT
  _26 ={v} MEM[(struct MC_ME_Type *)1076740096B].PRTN1_COFB1_STAT;
  _27 = _26 & 524288;
  if (_27 == 0)
    goto <bb 15>; [33.00%]
  else
    goto <bb 20>; [67.00%]

  <bb 15> [local count: 114863530]:
  # DEBUG BEGIN_STMT
  _28 ={v} MEM[(struct MC_ME_Type *)1076740096B].PRTN1_COFB1_CLKEN;
  _29 = _28 | 524288;
  MEM[(struct MC_ME_Type *)1076740096B].PRTN1_COFB1_CLKEN ={v} _29;
  # DEBUG BEGIN_STMT
  _30 ={v} MEM[(struct MC_ME_Type *)1076740096B].PRTN1_PCONF;
  _31 = _30 | 1;
  MEM[(struct MC_ME_Type *)1076740096B].PRTN1_PCONF ={v} _31;
  # DEBUG BEGIN_STMT
  _32 ={v} MEM[(struct MC_ME_Type *)1076740096B].PRTN1_PUPD;
  _33 = _32 | 1;
  MEM[(struct MC_ME_Type *)1076740096B].PRTN1_PUPD ={v} _33;
  # DEBUG BEGIN_STMT
  Clock_Ip_McMeEnterKey ();
  # DEBUG BEGIN_STMT
  Clock_Ip_StartTimeout (&StartTime, &ElapsedTime, &TimeoutTicks, 50000);

  <bb 16> [local count: 1073741821]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  TimeoutTicks.7_34 = TimeoutTicks;
  TimeoutOccurred_80 = Clock_Ip_TimeoutExpired (&StartTime, &ElapsedTime, TimeoutTicks.7_34);
  # DEBUG TimeoutOccurred => TimeoutOccurred_80
  # DEBUG BEGIN_STMT
  _35 ={v} MEM[(struct MC_ME_Type *)1076740096B].PRTN1_COFB1_STAT;
  _36 = _35 & 524288;
  if (_36 == 0)
    goto <bb 17>; [94.50%]
  else
    goto <bb 18>; [5.50%]

  <bb 17> [local count: 1014686021]:
  if (TimeoutOccurred_80 != 0)
    goto <bb 18>; [5.50%]
  else
    goto <bb 28>; [94.50%]

  <bb 28> [local count: 958878290]:
  goto <bb 16>; [100.00%]

  <bb 18> [local count: 114863531]:
  # TimeoutOccurred_4 = PHI <TimeoutOccurred_80(16), TimeoutOccurred_80(17)>
  # DEBUG BEGIN_STMT
  if (TimeoutOccurred_4 != 0)
    goto <bb 19>; [33.00%]
  else
    goto <bb 20>; [67.00%]

  <bb 19> [local count: 37904965]:
  # DEBUG BEGIN_STMT
  Clock_Ip_ReportClockErrors (1, 6);

  <bb 20> [local count: 348071305]:
  # DEBUG BEGIN_STMT
  _37 ={v} MEM[(struct MC_ME_Type *)1076740096B].PRTN1_COFB1_STAT;
  _38 = _37 & 32768;
  if (_38 == 0)
    goto <bb 21>; [33.00%]
  else
    goto <bb 26>; [67.00%]

  <bb 21> [local count: 114863530]:
  # DEBUG BEGIN_STMT
  _39 ={v} MEM[(struct MC_ME_Type *)1076740096B].PRTN1_COFB1_CLKEN;
  _40 = _39 | 32768;
  MEM[(struct MC_ME_Type *)1076740096B].PRTN1_COFB1_CLKEN ={v} _40;
  # DEBUG BEGIN_STMT
  _41 ={v} MEM[(struct MC_ME_Type *)1076740096B].PRTN1_PCONF;
  _42 = _41 | 1;
  MEM[(struct MC_ME_Type *)1076740096B].PRTN1_PCONF ={v} _42;
  # DEBUG BEGIN_STMT
  _43 ={v} MEM[(struct MC_ME_Type *)1076740096B].PRTN1_PUPD;
  _44 = _43 | 1;
  MEM[(struct MC_ME_Type *)1076740096B].PRTN1_PUPD ={v} _44;
  # DEBUG BEGIN_STMT
  Clock_Ip_McMeEnterKey ();
  # DEBUG BEGIN_STMT
  Clock_Ip_StartTimeout (&StartTime, &ElapsedTime, &TimeoutTicks, 50000);

  <bb 22> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  TimeoutTicks.8_45 = TimeoutTicks;
  TimeoutOccurred_88 = Clock_Ip_TimeoutExpired (&StartTime, &ElapsedTime, TimeoutTicks.8_45);
  # DEBUG TimeoutOccurred => TimeoutOccurred_88
  # DEBUG BEGIN_STMT
  _46 ={v} MEM[(struct MC_ME_Type *)1076740096B].PRTN1_COFB1_STAT;
  _47 = _46 & 32768;
  if (_47 == 0)
    goto <bb 23>; [94.50%]
  else
    goto <bb 24>; [5.50%]

  <bb 23> [local count: 1014686025]:
  if (TimeoutOccurred_88 != 0)
    goto <bb 24>; [5.50%]
  else
    goto <bb 27>; [94.50%]

  <bb 27> [local count: 958878294]:
  goto <bb 22>; [100.00%]

  <bb 24> [local count: 114863531]:
  # TimeoutOccurred_6 = PHI <TimeoutOccurred_88(22), TimeoutOccurred_88(23)>
  # DEBUG BEGIN_STMT
  if (TimeoutOccurred_6 != 0)
    goto <bb 25>; [33.00%]
  else
    goto <bb 26>; [67.00%]

  <bb 25> [local count: 37904965]:
  # DEBUG BEGIN_STMT
  Clock_Ip_ReportClockErrors (1, 143);

  <bb 26> [local count: 348071306]:
  StartTime ={v} {CLOBBER};
  ElapsedTime ={v} {CLOBBER};
  TimeoutTicks ={v} {CLOBBER};
  return;

}


