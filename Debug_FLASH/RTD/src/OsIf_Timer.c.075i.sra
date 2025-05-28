Creating summary for OsIf_MicrosToTicks/9:
  Descriptor for parameter 0 MicrosD.5765
    not a candidate for splitting
  Descriptor for parameter 1 SelectedCounterD.5766
    not a candidate for splitting


Creating summary for OsIf_SetTimerFrequency/8:
  Descriptor for parameter 0 FreqD.5758
    (locally) unused
    not a candidate for splitting
  Descriptor for parameter 1 SelectedCounterD.5759
    (locally) unused
    not a candidate for splitting


Creating summary for OsIf_GetElapsed/7:
  Descriptor for parameter 0 CurrentRefD.5750
    unused with 0 call_uses
    by_ref with 0 pass throughs
  Descriptor for parameter 1 SelectedCounterD.5751
    not a candidate
----------------------------------------
  Descriptor for parameter 0 CurrentRefD.5750
    (locally) unused
    param_size_limit: 4, size_reached: 0, by_ref
  Descriptor for parameter 1 SelectedCounterD.5751
    not a candidate for splitting


Creating summary for OsIf_GetCounter/6:
  Descriptor for parameter 0 SelectedCounterD.5743
    (locally) unused
    not a candidate for splitting


Creating summary for OsIf_Init/5:
  Descriptor for parameter 0 ConfigD.5740
    not a candidate for splitting



========== IPA-SRA IPA stage ==========

Summary for node OsIf_MicrosToTicks/9:
  Returns value
  Descriptor for parameter 0:
    not a candidate for splitting
  Descriptor for parameter 1:
    not a candidate for splitting


Summary for node OsIf_SetTimerFrequency/8:
  Descriptor for parameter 0:
    (locally) unused
    not a candidate for splitting
  Descriptor for parameter 1:
    (locally) unused
    not a candidate for splitting


Summary for node OsIf_GetElapsed/7:
  Returns value
  Descriptor for parameter 0:
    (locally) unused
    param_size_limit: 4, size_reached: 0, by_ref
  Descriptor for parameter 1:
    not a candidate for splitting


Summary for node OsIf_GetCounter/6:
  Returns value
  Descriptor for parameter 0:
    (locally) unused
    not a candidate for splitting


Summary for node OsIf_Init/5:
  Descriptor for parameter 0:
    not a candidate for splitting



Function OsIf_Init/5 disqualified because it cannot be made local.
Function OsIf_GetCounter/6 disqualified because it cannot be made local.
Function OsIf_GetElapsed/7 disqualified because it cannot be made local.
Function OsIf_SetTimerFrequency/8 disqualified because it cannot be made local.
Function OsIf_MicrosToTicks/9 disqualified because it cannot be made local.

========== IPA-SRA decisions ==========

========== IPA SRA IPA analysis done ==========


Reclaiming functions:
Reclaiming variables:
Clearing address taken flags:
Symbol table:

OsIf_MicrosToTicks/9 (OsIf_MicrosToTicks) @069c6620
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
OsIf_SetTimerFrequency/8 (OsIf_SetTimerFrequency) @069c60e0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
OsIf_GetElapsed/7 (OsIf_GetElapsed) @069c6d20
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
OsIf_GetCounter/6 (OsIf_GetCounter) @069c6a80
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
OsIf_Init/5 (OsIf_Init) @069c67e0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:30374594 (estimated locally) body optimize_size
  Called by: 
  Calls: 
OsIf_MicrosToTicks (uint32 Micros, OsIf_CounterType SelectedCounter)
{
  uint32 Value;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG Value => 0
  # DEBUG BEGIN_STMT
  if (SelectedCounter_2(D) == 0)
    goto <bb 3>; [50.00%]
  else
    goto <bb 4>; [50.00%]

  <bb 3> [local count: 536870913]:
  # DEBUG BEGIN_STMT
  # DEBUG Micros => Micros_4(D)
  # DEBUG INLINE_ENTRY NULL
  # DEBUG BEGIN_STMT
  # DEBUG Micros => NULL
  # DEBUG Value => Micros_4(D)
  # DEBUG BEGIN_STMT

  <bb 4> [local count: 1073741824]:
  # Value_1 = PHI <Micros_4(D)(3), 0(2)>
  # DEBUG Value => Value_1
  # DEBUG BEGIN_STMT
  return Value_1;

}


OsIf_SetTimerFrequency (uint32 Freq, OsIf_CounterType SelectedCounter)
{
  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG Freq => NULL
  return;

}


OsIf_GetElapsed (uint32 * const CurrentRef, OsIf_CounterType SelectedCounter)
{
  uint32 Value;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG Value => 0
  # DEBUG BEGIN_STMT
  if (SelectedCounter_2(D) == 0)
    goto <bb 3>; [50.00%]
  else
    goto <bb 4>; [50.00%]

  <bb 3> [local count: 536870913]:
  # DEBUG BEGIN_STMT
  # DEBUG CurrentRef => CurrentRef_4(D)
  # DEBUG INLINE_ENTRY NULL
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG CurrentRef => NULL
  # DEBUG Value => 1
  # DEBUG BEGIN_STMT

  <bb 4> [local count: 1073741824]:
  # Value_1 = PHI <1(3), 0(2)>
  # DEBUG Value => Value_1
  # DEBUG BEGIN_STMT
  return Value_1;

}


OsIf_GetCounter (OsIf_CounterType SelectedCounter)
{
  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG Value => 0
  # DEBUG BEGIN_STMT
  # DEBUG Value => 0
  # DEBUG BEGIN_STMT
  return 0;

}


OsIf_Init (const void * Config)
{
  volatile boolean x;
  _Bool x.0_4;

  <bb 2> [local count: 30374594]:
  # DEBUG BEGIN_STMT
  if (Config_2(D) != 0B)
    goto <bb 3>; [70.00%]
  else
    goto <bb 5>; [30.00%]

  <bb 3> [local count: 21262216]:
  # DEBUG BEGIN_STMT
  x ={v} 0;
  # DEBUG x => x
  # DEBUG INLINE_ENTRY DevAssert
  # DEBUG BEGIN_STMT
  x.0_4 ={v} x;
  if (x.0_4 != 0)
    goto <bb 5>; [50.00%]
  else
    goto <bb 6>; [50.00%]

  <bb 6> [local count: 10631108]:

  <bb 4> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  __asm__ __volatile__("BKPT #0");
  # DEBUG BEGIN_STMT

  <bb 7> [local count: 1073741824]:
  goto <bb 4>; [100.00%]

  <bb 5> [local count: 19743486]:
  # DEBUG x => NULL
  return;

}


