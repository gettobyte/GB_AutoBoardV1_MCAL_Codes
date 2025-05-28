
IPA constant propagation start:

IPA structures before propagation:

Jump functions:
  Jump functions of caller  BctuWatermarkNotif/3:

 Propagating constants:


overall_size: 0

IPA lattices after all propagation:

Lattices:

IPA decision stage:


IPA constant propagation end

Reclaiming functions:
Reclaiming variables:
Clearing address taken flags:
Symbol table:

BctuWatermarkNotif/3 (BctuWatermarkNotif) @06c5a7e0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: BctuHwUnit_0_aFifoConfigPB_VS_0/1 (addr) 
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
BctuHwUnit_0_VS_0/2 (BctuHwUnit_0_VS_0) @06c57ea0
  Type: variable definition analyzed
  Visibility: externally_visible public
  References: BctuHwUnit_0_aTrigConfigPB_VS_0/0 (addr) BctuHwUnit_0_aFifoConfigPB_VS_0/1 (addr) 
  Referring: 
  Availability: available
  Varpool flags: initialized read-only const-value-known
BctuHwUnit_0_aFifoConfigPB_VS_0/1 (BctuHwUnit_0_aFifoConfigPB_VS_0) @06c57dc8
  Type: variable definition analyzed
  Visibility: prevailing_def_ironly
  References: BctuWatermarkNotif/3 (addr) 
  Referring: BctuHwUnit_0_VS_0/2 (addr) 
  Availability: available
  Varpool flags: initialized read-only const-value-known
BctuHwUnit_0_aTrigConfigPB_VS_0/0 (BctuHwUnit_0_aTrigConfigPB_VS_0) @06c57cf0
  Type: variable definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: BctuHwUnit_0_VS_0/2 (addr) 
  Availability: available
  Varpool flags: initialized read-only const-value-known
