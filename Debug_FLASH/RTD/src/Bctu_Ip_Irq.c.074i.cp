
IPA constant propagation start:

IPA structures before propagation:

Jump functions:
  Jump functions of caller  Bctu_Ip_IRQHandler/1:
  Jump functions of caller  Bctu_0_Isr/0:
    callsite  Bctu_0_Isr/0 -> Bctu_Ip_IRQHandler/1 : 
       no arg info

 Propagating constants:


overall_size: 5

IPA lattices after all propagation:

Lattices:
  Node: Bctu_0_Isr/0:

IPA decision stage:


IPA constant propagation end

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

;; Function Bctu_0_Isr (Bctu_0_Isr, funcdef_no=0, decl_uid=5823, cgraph_uid=1, symbol_order=0)

Modification phase of node Bctu_0_Isr/0
Bctu_0_Isr ()
{
  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  Bctu_Ip_IRQHandler (0);
  return;

}


