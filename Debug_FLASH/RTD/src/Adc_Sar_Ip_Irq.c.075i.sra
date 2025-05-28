Creating summary for Adc_Sar_2_Isr/2:


Creating summary for Adc_Sar_1_Isr/1:


Creating summary for Adc_Sar_0_Isr/0:



========== IPA-SRA IPA stage ==========

Summary for node Adc_Sar_2_Isr/2:
  No parameter information. 

  Summary for edge Adc_Sar_2_Isr/2->Adc_Sar_Ip_IRQHandler/3:
    return value ignored

Summary for node Adc_Sar_1_Isr/1:
  No parameter information. 

  Summary for edge Adc_Sar_1_Isr/1->Adc_Sar_Ip_IRQHandler/3:
    return value ignored

Summary for node Adc_Sar_0_Isr/0:
  No parameter information. 

  Summary for edge Adc_Sar_0_Isr/0->Adc_Sar_Ip_IRQHandler/3:
    return value ignored


Function Adc_Sar_0_Isr/0 disqualified because it cannot be made local.
Function Adc_Sar_1_Isr/1 disqualified because it cannot be made local.
Function Adc_Sar_2_Isr/2 disqualified because it cannot be made local.

========== IPA-SRA decisions ==========

========== IPA SRA IPA analysis done ==========


Reclaiming functions:
Reclaiming variables:
Clearing address taken flags:
Symbol table:

Adc_Sar_Ip_IRQHandler/3 (Adc_Sar_Ip_IRQHandler) @05f8e620
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Adc_Sar_2_Isr/2 (1073741824 (estimated locally),1.00 per call) Adc_Sar_1_Isr/1 (1073741824 (estimated locally),1.00 per call) Adc_Sar_0_Isr/0 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
Adc_Sar_2_Isr/2 (Adc_Sar_2_Isr) @05f8e1c0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: Adc_Sar_Ip_IRQHandler/3 (1073741824 (estimated locally),1.00 per call) 
Adc_Sar_1_Isr/1 (Adc_Sar_1_Isr) @05f84ee0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: Adc_Sar_Ip_IRQHandler/3 (1073741824 (estimated locally),1.00 per call) 
Adc_Sar_0_Isr/0 (Adc_Sar_0_Isr) @05f84e00
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: Adc_Sar_Ip_IRQHandler/3 (1073741824 (estimated locally),1.00 per call) 
Adc_Sar_2_Isr ()
{
  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  Adc_Sar_Ip_IRQHandler (2);
  return;

}


Adc_Sar_1_Isr ()
{
  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  Adc_Sar_Ip_IRQHandler (1);
  return;

}


Adc_Sar_0_Isr ()
{
  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  Adc_Sar_Ip_IRQHandler (0);
  return;

}


