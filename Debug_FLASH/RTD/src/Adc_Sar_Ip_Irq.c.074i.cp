
IPA constant propagation start:

IPA structures before propagation:

Jump functions:
  Jump functions of caller  Adc_Sar_Ip_IRQHandler/3:
  Jump functions of caller  Adc_Sar_2_Isr/2:
    callsite  Adc_Sar_2_Isr/2 -> Adc_Sar_Ip_IRQHandler/3 : 
       no arg info
  Jump functions of caller  Adc_Sar_1_Isr/1:
    callsite  Adc_Sar_1_Isr/1 -> Adc_Sar_Ip_IRQHandler/3 : 
       no arg info
  Jump functions of caller  Adc_Sar_0_Isr/0:
    callsite  Adc_Sar_0_Isr/0 -> Adc_Sar_Ip_IRQHandler/3 : 
       no arg info

 Propagating constants:


overall_size: 15

IPA lattices after all propagation:

Lattices:
  Node: Adc_Sar_2_Isr/2:
  Node: Adc_Sar_1_Isr/1:
  Node: Adc_Sar_0_Isr/0:

IPA decision stage:


IPA constant propagation end

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

;; Function Adc_Sar_0_Isr (Adc_Sar_0_Isr, funcdef_no=0, decl_uid=5804, cgraph_uid=1, symbol_order=0)

Modification phase of node Adc_Sar_0_Isr/0
Adc_Sar_0_Isr ()
{
  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  Adc_Sar_Ip_IRQHandler (0);
  return;

}



;; Function Adc_Sar_1_Isr (Adc_Sar_1_Isr, funcdef_no=1, decl_uid=5806, cgraph_uid=2, symbol_order=1)

Modification phase of node Adc_Sar_1_Isr/1
Adc_Sar_1_Isr ()
{
  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  Adc_Sar_Ip_IRQHandler (1);
  return;

}



;; Function Adc_Sar_2_Isr (Adc_Sar_2_Isr, funcdef_no=2, decl_uid=5808, cgraph_uid=3, symbol_order=2)

Modification phase of node Adc_Sar_2_Isr/2
Adc_Sar_2_Isr ()
{
  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  Adc_Sar_Ip_IRQHandler (2);
  return;

}


