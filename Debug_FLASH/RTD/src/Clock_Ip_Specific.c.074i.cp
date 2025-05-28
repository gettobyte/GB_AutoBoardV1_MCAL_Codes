
IPA constant propagation start:
Determining dynamic type for call: _2 (&SircConfig);
  Starting walk at: _2 (&SircConfig);
  instance pointer: &SircConfig  Outer instance pointer: SircConfig offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: _2 (&FircConfig);
  Starting walk at: _2 (&FircConfig);
  instance pointer: &FircConfig  Outer instance pointer: FircConfig offset: 0 (bits) vtbl reference: 

IPA structures before propagation:

Jump functions:
  Jump functions of caller  Clock_Ip_PRAMCSetRamIWS.part.0/26:
  Jump functions of caller  Clock_Ip_ReportClockErrors/23:
  Jump functions of caller  Clock_Ip_TimeoutExpired/22:
  Jump functions of caller  Clock_Ip_StartTimeout/21:
  Jump functions of caller  Clock_Ip_PRAMCSetRamIWS/17:
    callsite  Clock_Ip_PRAMCSetRamIWS/17 -> Clock_Ip_PRAMCSetRamIWS.part.0/26 : 
  Jump functions of caller  Clock_Ip_FLASH_SetFlashIWS/16:
    indirect simple callsite, calling param -1, offset 0, for stmt Clock_Ip_SetFlashWaitStatesCallback.9_1 ();
  Jump functions of caller  Clock_Ip_Command/15:
    callsite  Clock_Ip_Command/15 -> Clock_Ip_PowerClockIpModules/3 : 
    callsite  Clock_Ip_Command/15 -> Clock_Ip_ClockInitializeObjects/13 : 
  Jump functions of caller  Clock_Ip_ClockPowerModeChangeNotification/14:
  Jump functions of caller  Clock_Ip_ClockInitializeObjects/13:
  Jump functions of caller  EnableSircInStandbyMode/12:
    indirect simple callsite, calling param -1, offset 0, for stmt _2 (&SircConfig);
       param 0: UNKNOWN
         Aggregate passed by reference:
           offset: 32, type: uint16, CONST: 1
         value: 0x0, mask: 0xfffffffc
         VR  [1, -1]
  Jump functions of caller  DisableSircInStandbyMode/11:
    indirect simple callsite, calling param -1, offset 0, for stmt _2 (3);
       param 0: CONST: 3
         value: 0x3, mask: 0x0
         Unknown VR
  Jump functions of caller  EnableFircInStandbyMode/10:
    indirect simple callsite, calling param -1, offset 0, for stmt _2 (&FircConfig);
       param 0: UNKNOWN
         Aggregate passed by reference:
           offset: 32, type: uint16, CONST: 1
         value: 0x0, mask: 0xfffffffc
         VR  [1, -1]
  Jump functions of caller  DisableFircInStandbyMode/9:
    indirect simple callsite, calling param -1, offset 0, for stmt _2 (1);
       param 0: CONST: 1
         value: 0x1, mask: 0x0
         Unknown VR
  Jump functions of caller  Clock_Ip_McMeEnterKey/7:
  Jump functions of caller  Clock_Ip_SetFlashWaitStates/6:
    callsite  Clock_Ip_SetFlashWaitStates/6 -> Clock_Ip_FLASH_SetFlashIWS/16 : 
  Jump functions of caller  Clock_Ip_SetRamWaitStates/5:
    callsite  Clock_Ip_SetRamWaitStates/5 -> Clock_Ip_PRAMCSetRamIWS/17 : 
  Jump functions of caller  Clock_Ip_CodeInRamSetFlashWaitStates/4:
  Jump functions of caller  Clock_Ip_PowerClockIpModules/3:
    callsite  Clock_Ip_PowerClockIpModules/3 -> Clock_Ip_ReportClockErrors/23 : 
       no arg info
    callsite  Clock_Ip_PowerClockIpModules/3 -> Clock_Ip_TimeoutExpired/22 : 
       no arg info
    callsite  Clock_Ip_PowerClockIpModules/3 -> Clock_Ip_StartTimeout/21 : 
       no arg info
    callsite  Clock_Ip_PowerClockIpModules/3 -> Clock_Ip_McMeEnterKey/7 : 
    callsite  Clock_Ip_PowerClockIpModules/3 -> Clock_Ip_ReportClockErrors/23 : 
       no arg info
    callsite  Clock_Ip_PowerClockIpModules/3 -> Clock_Ip_TimeoutExpired/22 : 
       no arg info
    callsite  Clock_Ip_PowerClockIpModules/3 -> Clock_Ip_StartTimeout/21 : 
       no arg info
    callsite  Clock_Ip_PowerClockIpModules/3 -> Clock_Ip_McMeEnterKey/7 : 
    callsite  Clock_Ip_PowerClockIpModules/3 -> Clock_Ip_ReportClockErrors/23 : 
       no arg info
    callsite  Clock_Ip_PowerClockIpModules/3 -> Clock_Ip_TimeoutExpired/22 : 
       no arg info
    callsite  Clock_Ip_PowerClockIpModules/3 -> Clock_Ip_StartTimeout/21 : 
       no arg info
    callsite  Clock_Ip_PowerClockIpModules/3 -> Clock_Ip_McMeEnterKey/7 : 
    callsite  Clock_Ip_PowerClockIpModules/3 -> Clock_Ip_ReportClockErrors/23 : 
       no arg info
    callsite  Clock_Ip_PowerClockIpModules/3 -> Clock_Ip_TimeoutExpired/22 : 
       no arg info
    callsite  Clock_Ip_PowerClockIpModules/3 -> Clock_Ip_StartTimeout/21 : 
       no arg info
    callsite  Clock_Ip_PowerClockIpModules/3 -> Clock_Ip_McMeEnterKey/7 : 

 Propagating constants:

Not considering Clock_Ip_Command/15 for cloning; -fipa-cp-clone disabled.
Not considering Clock_Ip_ClockPowerModeChangeNotification/14 for cloning; -fipa-cp-clone disabled.

overall_size: 289
 - context independent values, size: 11, time_benefit: 1.000000
 - context independent values, size: 3, time_benefit: 2.000000

IPA lattices after all propagation:

Lattices:
  Node: Clock_Ip_PRAMCSetRamIWS.part.0/26:
  Node: Clock_Ip_PRAMCSetRamIWS/17:
  Node: Clock_Ip_FLASH_SetFlashIWS/16:
  Node: Clock_Ip_Command/15:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         int VARYING
        AGGS BOTTOM
    param [1]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         int VARYING
        AGGS BOTTOM
  Node: Clock_Ip_ClockPowerModeChangeNotification/14:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         int VARYING
        AGGS BOTTOM
    param [1]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         int VARYING
        AGGS BOTTOM
  Node: Clock_Ip_ClockInitializeObjects/13:
  Node: EnableSircInStandbyMode/12:
  Node: DisableSircInStandbyMode/11:
  Node: EnableFircInStandbyMode/10:
  Node: DisableFircInStandbyMode/9:
  Node: Clock_Ip_McMeEnterKey/7:
  Node: Clock_Ip_SetFlashWaitStates/6:
  Node: Clock_Ip_SetRamWaitStates/5:
  Node: Clock_Ip_CodeInRamSetFlashWaitStates/4:
  Node: Clock_Ip_PowerClockIpModules/3:

IPA decision stage:


IPA constant propagation end

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

;; Function Clock_Ip_CodeInRamSetFlashWaitStates (Clock_Ip_CodeInRamSetFlashWaitStates, funcdef_no=1, decl_uid=6578, cgraph_uid=2, symbol_order=4)

Modification phase of node Clock_Ip_CodeInRamSetFlashWaitStates/4
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



;; Function Clock_Ip_McMeEnterKey (Clock_Ip_McMeEnterKey, funcdef_no=4, decl_uid=6383, cgraph_uid=5, symbol_order=7)

Modification phase of node Clock_Ip_McMeEnterKey/7
Clock_Ip_McMeEnterKey ()
{
  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  MEM[(struct MC_ME_Type *)1076740096B].CTL_KEY ={v} 23280;
  # DEBUG BEGIN_STMT
  MEM[(struct MC_ME_Type *)1076740096B].CTL_KEY ={v} 42255;
  return;

}



;; Function DisableFircInStandbyMode (DisableFircInStandbyMode, funcdef_no=6, decl_uid=6375, cgraph_uid=7, symbol_order=9)

Modification phase of node DisableFircInStandbyMode/9
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



;; Function EnableFircInStandbyMode (EnableFircInStandbyMode, funcdef_no=7, decl_uid=6377, cgraph_uid=8, symbol_order=10)

Modification phase of node EnableFircInStandbyMode/10
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



;; Function DisableSircInStandbyMode (DisableSircInStandbyMode, funcdef_no=8, decl_uid=6379, cgraph_uid=9, symbol_order=11)

Modification phase of node DisableSircInStandbyMode/11
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



;; Function EnableSircInStandbyMode (EnableSircInStandbyMode, funcdef_no=9, decl_uid=6381, cgraph_uid=10, symbol_order=12)

Modification phase of node EnableSircInStandbyMode/12
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



;; Function Clock_Ip_ClockPowerModeChangeNotification (Clock_Ip_ClockPowerModeChangeNotification, funcdef_no=11, decl_uid=6548, cgraph_uid=12, symbol_order=14)

Modification phase of node Clock_Ip_ClockPowerModeChangeNotification/14
Clock_Ip_ClockPowerModeChangeNotification (Clock_Ip_PowerModesType PowerMode, Clock_Ip_PowerNotificationType Notification)
{
  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  return;

}



;; Function Clock_Ip_Command (Clock_Ip_Command, funcdef_no=12, decl_uid=6565, cgraph_uid=13, symbol_order=15)

Modification phase of node Clock_Ip_Command/15
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



;; Function Clock_Ip_FLASH_SetFlashIWS (Clock_Ip_FLASH_SetFlashIWS, funcdef_no=13, decl_uid=6610, cgraph_uid=14, symbol_order=16)

Modification phase of node Clock_Ip_FLASH_SetFlashIWS/16
Clock_Ip_FLASH_SetFlashIWS ()
{
  void (*<T73d>) (void) Clock_Ip_SetFlashWaitStatesCallback.9_1;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  Clock_Ip_SetFlashWaitStatesCallback.9_1 = Clock_Ip_SetFlashWaitStatesCallback;
  Clock_Ip_SetFlashWaitStatesCallback.9_1 ();
  return;

}



;; Function Clock_Ip_SetFlashWaitStates (Clock_Ip_SetFlashWaitStates, funcdef_no=3, decl_uid=6562, cgraph_uid=4, symbol_order=6)

Modification phase of node Clock_Ip_SetFlashWaitStates/6
Clock_Ip_SetFlashWaitStates ()
{
  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  Clock_Ip_FLASH_SetFlashIWS ();
  return;

}



;; Function Clock_Ip_PRAMCSetRamIWS (Clock_Ip_PRAMCSetRamIWS, funcdef_no=14, decl_uid=6585, cgraph_uid=15, symbol_order=17)

Modification phase of node Clock_Ip_PRAMCSetRamIWS/17
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



;; Function Clock_Ip_SetRamWaitStates (Clock_Ip_SetRamWaitStates, funcdef_no=2, decl_uid=6560, cgraph_uid=3, symbol_order=5)

Modification phase of node Clock_Ip_SetRamWaitStates/5
Clock_Ip_SetRamWaitStates ()
{
  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  Clock_Ip_PRAMCSetRamIWS ();
  return;

}


