Creating summary for Bctu_0_Isr/0:



========== IPA-SRA IPA stage ==========

Summary for node Bctu_0_Isr/0:
  No parameter information. 

  Summary for edge Bctu_0_Isr/0->Bctu_Ip_IRQHandler/1:
    return value ignored


Function Bctu_0_Isr/0 disqualified because it cannot be made local.

========== IPA-SRA decisions ==========

========== IPA SRA IPA analysis done ==========


Reclaiming functions:
Reclaiming variables:
Clearing address taken flags:
Symbol table:

Bctu_Ip_IRQHandler/1 (Bctu_Ip_IRQHandler) @0608bc40
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Bctu_0_Isr/0 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
Bctu_0_Isr/0 (Bctu_0_Isr) @0608b7e0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: Bctu_Ip_IRQHandler/1 (1073741824 (estimated locally),1.00 per call) 
Bctu_0_Isr ()
{
  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  Bctu_Ip_IRQHandler (0);
  return;

}


