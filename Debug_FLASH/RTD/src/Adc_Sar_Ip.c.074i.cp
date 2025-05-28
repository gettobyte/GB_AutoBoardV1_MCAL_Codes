
IPA constant propagation start:
Determining dynamic type for call: Adc_Sar_EnableHighSpeed (AdcBasePtr_15, _5);
  Starting walk at: Adc_Sar_EnableHighSpeed (AdcBasePtr_15, _5);
  instance pointer: AdcBasePtr_15  Outer instance pointer: AdcBasePtr_15 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_51 ();
  Function call may change dynamic type:Status_24 = Adc_Sar_Ip_Powerup (u32Instance_14(D));
  Function call may change dynamic type:SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_15 ();
  Function call may change dynamic type:SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_15 ();
  Function call may change dynamic type:Status_19 = Adc_Sar_Ip_Powerdown (u32Instance_14(D));
Determining dynamic type for call: Adc_Sar_Ip_SetSampleTimes (u32Instance_14(D), _10);
  Starting walk at: Adc_Sar_Ip_SetSampleTimes (u32Instance_14(D), _10);
  instance pointer: _10  Outer instance pointer: pConfig_16(D) offset: 40 (bits) vtbl reference: 
  Function call may change dynamic type:Adc_Sar_Ip_SetAveraging (u32Instance_14(D), _6, _7);
  Function call may change dynamic type:SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_51 ();
  Function call may change dynamic type:Adc_Sar_EnableHighSpeed (AdcBasePtr_15, _5);
  Function call may change dynamic type:SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_51 ();
  Function call may change dynamic type:Status_24 = Adc_Sar_Ip_Powerup (u32Instance_14(D));
  Function call may change dynamic type:SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_15 ();
  Function call may change dynamic type:SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_15 ();
  Function call may change dynamic type:Status_19 = Adc_Sar_Ip_Powerdown (u32Instance_14(D));
Determining dynamic type for call: _7 = Adc_Sar_GetConvResults (u32Instance_2(D), pChainType_3(D), 0B, pResults_4(D), u32Length_5(D));
  Starting walk at: _7 = Adc_Sar_GetConvResults (u32Instance_2(D), pChainType_3(D), 0B, pResults_4(D), u32Length_5(D));
  instance pointer: 0B  Outer instance pointer: 0B offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: _7 = Adc_Sar_GetConvResults (u32Instance_2(D), pChainType_3(D), 0B, pResults_4(D), u32Length_5(D));
  Starting walk at: _7 = Adc_Sar_GetConvResults (u32Instance_2(D), pChainType_3(D), 0B, pResults_4(D), u32Length_5(D));
  instance pointer: pResults_4(D)  Outer instance pointer: pResults_4(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: _7 = Adc_Sar_GetConvResults (u32Instance_2(D), pChainType_3(D), pResults_4(D), 0B, u32Length_5(D));
  Starting walk at: _7 = Adc_Sar_GetConvResults (u32Instance_2(D), pChainType_3(D), pResults_4(D), 0B, u32Length_5(D));
  instance pointer: pResults_4(D)  Outer instance pointer: pResults_4(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: _7 = Adc_Sar_GetConvResults (u32Instance_2(D), pChainType_3(D), pResults_4(D), 0B, u32Length_5(D));
  Starting walk at: _7 = Adc_Sar_GetConvResults (u32Instance_2(D), pChainType_3(D), pResults_4(D), 0B, u32Length_5(D));
  instance pointer: 0B  Outer instance pointer: 0B offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: Adc_Sar_SetInjectedChain (u32Instance_7(D), _2);
  Starting walk at: Adc_Sar_SetInjectedChain (u32Instance_7(D), _2);
  instance pointer: _2  Outer instance pointer: pChansIdxMask_6(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: Adc_Sar_SetNormalChain (u32Instance_7(D), _1);
  Starting walk at: Adc_Sar_SetNormalChain (u32Instance_7(D), _1);
  instance pointer: _1  Outer instance pointer: pChansIdxMask_6(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: Status_49 = Adc_Sar_Ip_Init (u32Instance_20(D), &DefaultConfig);
  Starting walk at: Status_49 = Adc_Sar_Ip_Init (u32Instance_20(D), &DefaultConfig);
  instance pointer: &DefaultConfig  Outer instance pointer: DefaultConfig offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: _4 = Adc_Sar_CollectMcrMasks (u32Instance_59(D), pConfig_65(D), _3);
  Starting walk at: _4 = Adc_Sar_CollectMcrMasks (u32Instance_59(D), pConfig_65(D), _3);
  instance pointer: pConfig_65(D)  Outer instance pointer: pConfig_65(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:Status_64 = Adc_Sar_Ip_Powerdown (u32Instance_59(D));
  Function call may change dynamic type:Adc_Sar_Ip_AbortChain (u32Instance_59(D), 1, 0);
Determining dynamic type for call: Adc_Sar_EnableHighSpeed (AdcBasePtr_60, _9);
  Starting walk at: Adc_Sar_EnableHighSpeed (AdcBasePtr_60, _9);
  instance pointer: AdcBasePtr_60  Outer instance pointer: AdcBasePtr_60 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:Status_69 = Adc_Sar_Ip_Powerup (u32Instance_59(D));
  Function call may change dynamic type:Status_64 = Adc_Sar_Ip_Powerdown (u32Instance_59(D));
  Function call may change dynamic type:Adc_Sar_Ip_AbortChain (u32Instance_59(D), 1, 0);
Determining dynamic type for call: Adc_Sar_Ip_SetSampleTimes (u32Instance_59(D), _10);
  Starting walk at: Adc_Sar_Ip_SetSampleTimes (u32Instance_59(D), _10);
  instance pointer: _10  Outer instance pointer: pConfig_65(D) offset: 304 (bits) vtbl reference: 
  Function call may change dynamic type:Adc_Sar_EnableHighSpeed (AdcBasePtr_60, _9);
  Function call may change dynamic type:Status_69 = Adc_Sar_Ip_Powerup (u32Instance_59(D));
  Function call may change dynamic type:Status_64 = Adc_Sar_Ip_Powerdown (u32Instance_59(D));
  Function call may change dynamic type:Adc_Sar_Ip_AbortChain (u32Instance_59(D), 1, 0);
Determining dynamic type for call: Adc_Sar_SetNormalChain (u32Instance_59(D), _17);
  Starting walk at: Adc_Sar_SetNormalChain (u32Instance_59(D), _17);
  instance pointer: _17  Outer instance pointer: pConfig_65(D) offset: 672 (bits) vtbl reference: 
  Function call may change dynamic type:Adc_Sar_Ip_SetSampleTimes (u32Instance_59(D), _10);
  Function call may change dynamic type:Adc_Sar_EnableHighSpeed (AdcBasePtr_60, _9);
  Function call may change dynamic type:Status_69 = Adc_Sar_Ip_Powerup (u32Instance_59(D));
  Function call may change dynamic type:Status_64 = Adc_Sar_Ip_Powerdown (u32Instance_59(D));
  Function call may change dynamic type:Adc_Sar_Ip_AbortChain (u32Instance_59(D), 1, 0);
Determining dynamic type for call: Adc_Sar_SetInjectedChain (u32Instance_59(D), _18);
  Starting walk at: Adc_Sar_SetInjectedChain (u32Instance_59(D), _18);
  instance pointer: _18  Outer instance pointer: pConfig_65(D) offset: 768 (bits) vtbl reference: 
  Function call may change dynamic type:Adc_Sar_SetNormalChain (u32Instance_59(D), _17);
  Function call may change dynamic type:Adc_Sar_Ip_SetSampleTimes (u32Instance_59(D), _10);
  Function call may change dynamic type:Adc_Sar_EnableHighSpeed (AdcBasePtr_60, _9);
  Function call may change dynamic type:Status_69 = Adc_Sar_Ip_Powerup (u32Instance_59(D));
  Function call may change dynamic type:Status_64 = Adc_Sar_Ip_Powerdown (u32Instance_59(D));
  Function call may change dynamic type:Adc_Sar_Ip_AbortChain (u32Instance_59(D), 1, 0);
Determining dynamic type for call: Adc_Sar_ConfigChannels (u32Instance_59(D), _29, _30);
  Starting walk at: Adc_Sar_ConfigChannels (u32Instance_59(D), _29, _30);
  instance pointer: _29  Outer instance pointer: _29 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:Adc_Sar_Ip_SetResolution (u32Instance_59(D), _19);
  Function call may change dynamic type:Adc_Sar_SetInjectedChain (u32Instance_59(D), _18);
  Function call may change dynamic type:Adc_Sar_SetNormalChain (u32Instance_59(D), _17);
  Function call may change dynamic type:Adc_Sar_Ip_SetSampleTimes (u32Instance_59(D), _10);
  Function call may change dynamic type:Adc_Sar_EnableHighSpeed (AdcBasePtr_60, _9);
  Function call may change dynamic type:Status_69 = Adc_Sar_Ip_Powerup (u32Instance_59(D));
  Function call may change dynamic type:Status_64 = Adc_Sar_Ip_Powerdown (u32Instance_59(D));
  Function call may change dynamic type:Adc_Sar_Ip_AbortChain (u32Instance_59(D), 1, 0);
Determining dynamic type for call: Adc_Sar_CheckAndCallNotification (Instance_26(D), _5);
  Starting walk at: Adc_Sar_CheckAndCallNotification (Instance_26(D), _5);
  instance pointer: _5  Outer instance pointer: _5 offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: Adc_Sar_CheckAndCallNotification (Instance_26(D), _10);
  Starting walk at: Adc_Sar_CheckAndCallNotification (Instance_26(D), _10);
  instance pointer: _10  Outer instance pointer: _10 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:Adc_Sar_CheckAndCallNotification (Instance_26(D), _5);
Determining dynamic type for call: Adc_Sar_CheckAndCallNotification (Instance_26(D), _15);
  Starting walk at: Adc_Sar_CheckAndCallNotification (Instance_26(D), _15);
  instance pointer: _15  Outer instance pointer: _15 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:Adc_Sar_CheckAndCallNotification (Instance_26(D), _5);
  Function call may change dynamic type:Adc_Sar_CheckAndCallNotification (Instance_26(D), _10);

IPA structures before propagation:

Jump functions:
  Jump functions of caller  Adc_Sar_Ip_SetPresamplingSource.part.0/147:
    callsite  Adc_Sar_Ip_SetPresamplingSource.part.0/147 -> SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_38/111 : 
       no arg info
    callsite  Adc_Sar_Ip_SetPresamplingSource.part.0/147 -> SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_38/112 : 
       no arg info
  Jump functions of caller  SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_21/138:
  Jump functions of caller  SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_21/137:
  Jump functions of caller  SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_20/136:
  Jump functions of caller  SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_20/135:
  Jump functions of caller  SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_19/134:
  Jump functions of caller  SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_19/133:
  Jump functions of caller  SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_45/132:
  Jump functions of caller  SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_45/131:
  Jump functions of caller  SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_48/130:
  Jump functions of caller  SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_48/129:
  Jump functions of caller  SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_47/128:
  Jump functions of caller  SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_47/127:
  Jump functions of caller  SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_46/126:
  Jump functions of caller  SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_46/125:
  Jump functions of caller  SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_44/124:
  Jump functions of caller  SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_44/123:
  Jump functions of caller  SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_43/122:
  Jump functions of caller  SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_43/121:
  Jump functions of caller  SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_40/120:
  Jump functions of caller  SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_40/119:
  Jump functions of caller  SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_39/118:
  Jump functions of caller  SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_39/117:
  Jump functions of caller  SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_42/116:
  Jump functions of caller  SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_42/115:
  Jump functions of caller  SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_41/114:
  Jump functions of caller  SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_41/113:
  Jump functions of caller  SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_38/112:
  Jump functions of caller  SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_38/111:
  Jump functions of caller  SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_18/110:
  Jump functions of caller  SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_18/109:
  Jump functions of caller  SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_17/108:
  Jump functions of caller  SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_17/107:
  Jump functions of caller  SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_16/106:
  Jump functions of caller  SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_16/105:
  Jump functions of caller  SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_51/104:
  Jump functions of caller  SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_51/103:
  Jump functions of caller  SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_15/102:
  Jump functions of caller  SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_15/101:
  Jump functions of caller  SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_34/100:
  Jump functions of caller  SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_34/99:
  Jump functions of caller  SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_33/98:
  Jump functions of caller  SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_33/97:
  Jump functions of caller  SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_14/96:
  Jump functions of caller  SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_14/95:
  Jump functions of caller  SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_13/94:
  Jump functions of caller  SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_13/93:
  Jump functions of caller  SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_36/92:
  Jump functions of caller  SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_36/91:
  Jump functions of caller  SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_12/90:
  Jump functions of caller  SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_12/89:
  Jump functions of caller  OsIf_GetElapsed/86:
  Jump functions of caller  SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_35/85:
  Jump functions of caller  SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_35/84:
  Jump functions of caller  SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_11/83:
  Jump functions of caller  SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_11/82:
  Jump functions of caller  SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_25/81:
  Jump functions of caller  SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_25/80:
  Jump functions of caller  OsIf_GetCounter/79:
  Jump functions of caller  OsIf_MicrosToTicks/78:
  Jump functions of caller  SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_10/77:
  Jump functions of caller  SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_10/76:
  Jump functions of caller  SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_37/75:
  Jump functions of caller  SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_37/74:
  Jump functions of caller  SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_27/73:
  Jump functions of caller  SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_27/72:
  Jump functions of caller  SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_24/71:
  Jump functions of caller  SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_24/70:
  Jump functions of caller  SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_26/69:
  Jump functions of caller  SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_26/68:
  Jump functions of caller  SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_23/67:
  Jump functions of caller  SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_23/66:
  Jump functions of caller  Adc_Sar_Ip_GetDataAddress/65:
  Jump functions of caller  Adc_Sar_Ip_SetExternalTrigger/64:
    callsite  Adc_Sar_Ip_SetExternalTrigger/64 -> Adc_Sar_ConfigExternalTrigger/22 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: PASS THROUGH: 1, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 2: CONST: 2097152
         value: 0x200000, mask: 0x0
         Unknown VR
       param 3: CONST: 2097152
         value: 0x200000, mask: 0x0
         Unknown VR
       param 4: CONST: 4194304
         value: 0x400000, mask: 0x0
         Unknown VR
    callsite  Adc_Sar_Ip_SetExternalTrigger/64 -> Adc_Sar_ConfigExternalTrigger/22 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: PASS THROUGH: 1, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 2: CONST: 67108864
         value: 0x4000000, mask: 0x0
         Unknown VR
       param 3: CONST: 67108864
         value: 0x4000000, mask: 0x0
         Unknown VR
       param 4: CONST: 167772160
         value: 0xa000000, mask: 0x0
         Unknown VR
    callsite  Adc_Sar_Ip_SetExternalTrigger/64 -> Adc_Sar_ConfigExternalTrigger/22 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: PASS THROUGH: 1, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 2: CONST: 67108864
         value: 0x4000000, mask: 0x0
         Unknown VR
       param 3: CONST: 0
         value: 0x0, mask: 0x0
         Unknown VR
       param 4: CONST: 33554432
         value: 0x2000000, mask: 0x0
         Unknown VR
    callsite  Adc_Sar_Ip_SetExternalTrigger/64 -> Adc_Sar_ConfigExternalTrigger/22 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: PASS THROUGH: 1, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 2: CONST: 67108864
         value: 0x4000000, mask: 0x0
         Unknown VR
       param 3: CONST: 0
         value: 0x0, mask: 0x0
         Unknown VR
       param 4: CONST: 134217728
         value: 0x8000000, mask: 0x0
         Unknown VR
  Jump functions of caller  Adc_Sar_Ip_SetCtuMode/63:
    callsite  Adc_Sar_Ip_SetCtuMode/63 -> Adc_Sar_Ip_Powerup/42 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  Adc_Sar_Ip_SetCtuMode/63 -> SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_20/136 : 
       no arg info
    callsite  Adc_Sar_Ip_SetCtuMode/63 -> SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_20/135 : 
       no arg info
    callsite  Adc_Sar_Ip_SetCtuMode/63 -> Adc_Sar_Ip_Powerdown/43 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  Adc_Sar_Ip_SetCtuMode/63 -> SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_20/136 : 
       no arg info
    callsite  Adc_Sar_Ip_SetCtuMode/63 -> SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_20/135 : 
       no arg info
  Jump functions of caller  Adc_Sar_Ip_SetConversionMode/62:
    callsite  Adc_Sar_Ip_SetConversionMode/62 -> SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_19/134 : 
       no arg info
    callsite  Adc_Sar_Ip_SetConversionMode/62 -> SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_19/133 : 
       no arg info
  Jump functions of caller  Adc_Sar_Ip_SetDmaClearSource/61:
    callsite  Adc_Sar_Ip_SetDmaClearSource/61 -> SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_45/132 : 
       no arg info
    callsite  Adc_Sar_Ip_SetDmaClearSource/61 -> SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_45/131 : 
       no arg info
  Jump functions of caller  Adc_Sar_Ip_DisableChannelDmaAll/60:
    callsite  Adc_Sar_Ip_DisableChannelDmaAll/60 -> SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_48/130 : 
       no arg info
    callsite  Adc_Sar_Ip_DisableChannelDmaAll/60 -> SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_48/129 : 
       no arg info
  Jump functions of caller  Adc_Sar_Ip_DisableChannelDma/59:
    callsite  Adc_Sar_Ip_DisableChannelDma/59 -> SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_47/128 : 
       no arg info
    callsite  Adc_Sar_Ip_DisableChannelDma/59 -> SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_47/127 : 
       no arg info
  Jump functions of caller  Adc_Sar_Ip_EnableChannelDma/58:
    callsite  Adc_Sar_Ip_EnableChannelDma/58 -> SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_46/126 : 
       no arg info
    callsite  Adc_Sar_Ip_EnableChannelDma/58 -> SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_46/125 : 
       no arg info
  Jump functions of caller  Adc_Sar_Ip_DisableDma/57:
    callsite  Adc_Sar_Ip_DisableDma/57 -> SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_44/124 : 
       no arg info
    callsite  Adc_Sar_Ip_DisableDma/57 -> SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_44/123 : 
       no arg info
  Jump functions of caller  Adc_Sar_Ip_EnableDma/56:
    callsite  Adc_Sar_Ip_EnableDma/56 -> SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_43/122 : 
       no arg info
    callsite  Adc_Sar_Ip_EnableDma/56 -> SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_43/121 : 
       no arg info
  Jump functions of caller  Adc_Sar_Ip_DisablePresampleConversion/55:
    callsite  Adc_Sar_Ip_DisablePresampleConversion/55 -> SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_40/120 : 
       no arg info
    callsite  Adc_Sar_Ip_DisablePresampleConversion/55 -> SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_40/119 : 
       no arg info
  Jump functions of caller  Adc_Sar_Ip_EnablePresampleConversion/54:
    callsite  Adc_Sar_Ip_EnablePresampleConversion/54 -> SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_39/118 : 
       no arg info
    callsite  Adc_Sar_Ip_EnablePresampleConversion/54 -> SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_39/117 : 
       no arg info
  Jump functions of caller  Adc_Sar_Ip_DisableChannelPresampling/53:
    callsite  Adc_Sar_Ip_DisableChannelPresampling/53 -> SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_42/116 : 
       no arg info
    callsite  Adc_Sar_Ip_DisableChannelPresampling/53 -> SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_42/115 : 
       no arg info
  Jump functions of caller  Adc_Sar_Ip_EnableChannelPresampling/52:
    callsite  Adc_Sar_Ip_EnableChannelPresampling/52 -> SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_41/114 : 
       no arg info
    callsite  Adc_Sar_Ip_EnableChannelPresampling/52 -> SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_41/113 : 
       no arg info
  Jump functions of caller  Adc_Sar_Ip_SetPresamplingSource/51:
    callsite  Adc_Sar_Ip_SetPresamplingSource/51 -> Adc_Sar_Ip_SetPresamplingSource.part.0/147 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: PASS THROUGH: 1, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 2: PASS THROUGH: 2, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  Adc_Sar_Ip_AbortChain/50:
    callsite  Adc_Sar_Ip_AbortChain/50 -> OsIf_GetElapsed/86 : 
       no arg info
    callsite  Adc_Sar_Ip_AbortChain/50 -> SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_18/110 : 
       no arg info
    callsite  Adc_Sar_Ip_AbortChain/50 -> SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_18/109 : 
       no arg info
    callsite  Adc_Sar_Ip_AbortChain/50 -> OsIf_GetCounter/79 : 
       no arg info
    callsite  Adc_Sar_Ip_AbortChain/50 -> OsIf_MicrosToTicks/78 : 
       no arg info
  Jump functions of caller  Adc_Sar_Ip_AbortConversion/49:
    callsite  Adc_Sar_Ip_AbortConversion/49 -> SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_17/108 : 
       no arg info
    callsite  Adc_Sar_Ip_AbortConversion/49 -> SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_17/107 : 
       no arg info
  Jump functions of caller  Adc_Sar_Ip_SetAveraging/48:
    callsite  Adc_Sar_Ip_SetAveraging/48 -> SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_16/106 : 
       no arg info
    callsite  Adc_Sar_Ip_SetAveraging/48 -> SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_16/105 : 
       no arg info
  Jump functions of caller  Adc_Sar_Ip_SetSampleTimes/47:
  Jump functions of caller  Adc_Sar_Ip_SetClockMode/46:
    callsite  Adc_Sar_Ip_SetClockMode/46 -> Adc_Sar_Ip_SetSampleTimes/47 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xffffffff
         VR  [1, -1]
    callsite  Adc_Sar_Ip_SetClockMode/46 -> Adc_Sar_Ip_SetAveraging/48 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0x1
         Unknown VR
       param 2: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  Adc_Sar_Ip_SetClockMode/46 -> SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_51/104 : 
       no arg info
    callsite  Adc_Sar_Ip_SetClockMode/46 -> Adc_Sar_EnableHighSpeed/2 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0x1
         Unknown VR
    callsite  Adc_Sar_Ip_SetClockMode/46 -> SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_51/103 : 
       no arg info
    callsite  Adc_Sar_Ip_SetClockMode/46 -> Adc_Sar_Ip_Powerup/42 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  Adc_Sar_Ip_SetClockMode/46 -> SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_15/102 : 
       no arg info
    callsite  Adc_Sar_Ip_SetClockMode/46 -> SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_15/101 : 
       no arg info
    callsite  Adc_Sar_Ip_SetClockMode/46 -> Adc_Sar_Ip_Powerdown/43 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  Adc_Sar_Ip_DisableNotifications/45:
    callsite  Adc_Sar_Ip_DisableNotifications/45 -> SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_34/100 : 
       no arg info
    callsite  Adc_Sar_Ip_DisableNotifications/45 -> SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_34/99 : 
       no arg info
  Jump functions of caller  Adc_Sar_Ip_EnableNotifications/44:
    callsite  Adc_Sar_Ip_EnableNotifications/44 -> SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_33/98 : 
       no arg info
    callsite  Adc_Sar_Ip_EnableNotifications/44 -> SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_33/97 : 
       no arg info
  Jump functions of caller  Adc_Sar_Ip_Powerdown/43:
    callsite  Adc_Sar_Ip_Powerdown/43 -> OsIf_GetElapsed/86 : 
       no arg info
    callsite  Adc_Sar_Ip_Powerdown/43 -> SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_14/96 : 
       no arg info
    callsite  Adc_Sar_Ip_Powerdown/43 -> SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_14/95 : 
       no arg info
    callsite  Adc_Sar_Ip_Powerdown/43 -> OsIf_GetCounter/79 : 
       no arg info
    callsite  Adc_Sar_Ip_Powerdown/43 -> OsIf_MicrosToTicks/78 : 
       no arg info
  Jump functions of caller  Adc_Sar_Ip_Powerup/42:
    callsite  Adc_Sar_Ip_Powerup/42 -> OsIf_GetElapsed/86 : 
       no arg info
    callsite  Adc_Sar_Ip_Powerup/42 -> SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_13/94 : 
       no arg info
    callsite  Adc_Sar_Ip_Powerup/42 -> SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_13/93 : 
       no arg info
    callsite  Adc_Sar_Ip_Powerup/42 -> OsIf_GetCounter/79 : 
       no arg info
    callsite  Adc_Sar_Ip_Powerup/42 -> OsIf_MicrosToTicks/78 : 
       no arg info
  Jump functions of caller  Adc_Sar_Ip_DoCalibration/41:
    callsite  Adc_Sar_Ip_DoCalibration/41 -> Adc_Sar_Ip_Powerup/42 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  Adc_Sar_Ip_DoCalibration/41 -> SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_12/90 : 
       no arg info
    callsite  Adc_Sar_Ip_DoCalibration/41 -> SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_12/89 : 
       no arg info
    callsite  Adc_Sar_Ip_DoCalibration/41 -> Adc_Sar_Ip_Powerdown/43 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  Adc_Sar_Ip_DoCalibration/41 -> OsIf_GetElapsed/86 : 
       no arg info
    callsite  Adc_Sar_Ip_DoCalibration/41 -> SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_36/92 : 
       no arg info
    callsite  Adc_Sar_Ip_DoCalibration/41 -> SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_36/91 : 
       no arg info
    callsite  Adc_Sar_Ip_DoCalibration/41 -> Adc_Sar_Ip_Powerup/42 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  Adc_Sar_Ip_DoCalibration/41 -> SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_12/90 : 
       no arg info
    callsite  Adc_Sar_Ip_DoCalibration/41 -> SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_12/89 : 
       no arg info
    callsite  Adc_Sar_Ip_DoCalibration/41 -> Adc_Sar_Ip_Powerdown/43 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  Adc_Sar_Ip_DoCalibration/41 -> OsIf_GetCounter/79 : 
       no arg info
    callsite  Adc_Sar_Ip_DoCalibration/41 -> OsIf_MicrosToTicks/78 : 
       no arg info
  Jump functions of caller  Adc_Sar_Ip_GetConvResult/40:
    callsite  Adc_Sar_Ip_GetConvResult/40 -> Adc_Sar_GetMaskedResult/11 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  Adc_Sar_Ip_GetConvData/39:
    callsite  Adc_Sar_Ip_GetConvData/39 -> Adc_Sar_GetMaskedResult/11 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  Adc_Sar_Ip_GetConvResultsToArray/38:
    callsite  Adc_Sar_Ip_GetConvResultsToArray/38 -> Adc_Sar_GetConvResults/18 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: PASS THROUGH: 1, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 2: CONST: 0B
         value: 0x0, mask: 0xfffffff8
         Unknown VR
       param 3: PASS THROUGH: 3, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 4: PASS THROUGH: 2, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  Adc_Sar_Ip_GetConvDataToArray/37:
    callsite  Adc_Sar_Ip_GetConvDataToArray/37 -> Adc_Sar_GetConvResults/18 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: PASS THROUGH: 1, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 2: PASS THROUGH: 3, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 3: CONST: 0B
         value: 0x0, mask: 0xfffffff8
         Unknown VR
       param 4: PASS THROUGH: 2, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  Adc_Sar_Ip_SelfTest/36:
    callsite  Adc_Sar_Ip_SelfTest/36 -> SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_35/85 : 
       no arg info
    callsite  Adc_Sar_Ip_SelfTest/36 -> SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_35/84 : 
       no arg info
    callsite  Adc_Sar_Ip_SelfTest/36 -> OsIf_GetElapsed/86 : 
       no arg info
    callsite  Adc_Sar_Ip_SelfTest/36 -> SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_11/83 : 
       no arg info
    callsite  Adc_Sar_Ip_SelfTest/36 -> SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_11/82 : 
       no arg info
    callsite  Adc_Sar_Ip_SelfTest/36 -> Adc_Sar_CheckSelfTestProgress/17 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  Adc_Sar_Ip_SelfTest/36 -> SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_11/83 : 
       no arg info
    callsite  Adc_Sar_Ip_SelfTest/36 -> SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_11/82 : 
       no arg info
    callsite  Adc_Sar_Ip_SelfTest/36 -> SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_35/85 : 
       no arg info
    callsite  Adc_Sar_Ip_SelfTest/36 -> SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_35/84 : 
       no arg info
    callsite  Adc_Sar_Ip_SelfTest/36 -> SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_11/83 : 
       no arg info
    callsite  Adc_Sar_Ip_SelfTest/36 -> SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_11/82 : 
       no arg info
    callsite  Adc_Sar_Ip_SelfTest/36 -> SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_25/81 : 
       no arg info
    callsite  Adc_Sar_Ip_SelfTest/36 -> SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_25/80 : 
       no arg info
    callsite  Adc_Sar_Ip_SelfTest/36 -> OsIf_GetCounter/79 : 
       no arg info
    callsite  Adc_Sar_Ip_SelfTest/36 -> OsIf_MicrosToTicks/78 : 
       no arg info
  Jump functions of caller  Adc_Sar_Ip_ClearStatusFlags/35:
  Jump functions of caller  Adc_Sar_Ip_GetStatusFlags/34:
    callsite  Adc_Sar_Ip_GetStatusFlags/34 -> Adc_Sar_GetIsrFlags/13 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  Adc_Sar_Ip_GetStatusFlags/34 -> Adc_Sar_GetMsrFlags/12 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  Adc_Sar_Ip_StartConversion/33:
    callsite  Adc_Sar_Ip_StartConversion/33 -> SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_10/77 : 
       no arg info
    callsite  Adc_Sar_Ip_StartConversion/33 -> SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_10/76 : 
       no arg info
  Jump functions of caller  Adc_Sar_Ip_SetResolution/32:
    callsite  Adc_Sar_Ip_SetResolution/32 -> SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_37/75 : 
       no arg info
    callsite  Adc_Sar_Ip_SetResolution/32 -> SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_37/74 : 
       no arg info
  Jump functions of caller  Adc_Sar_Ip_DisableChannel/31:
    callsite  Adc_Sar_Ip_DisableChannel/31 -> SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_27/73 : 
       no arg info
    callsite  Adc_Sar_Ip_DisableChannel/31 -> SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_27/72 : 
       no arg info
    callsite  Adc_Sar_Ip_DisableChannel/31 -> SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_24/71 : 
       no arg info
    callsite  Adc_Sar_Ip_DisableChannel/31 -> SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_24/70 : 
       no arg info
  Jump functions of caller  Adc_Sar_Ip_EnableChannel/30:
    callsite  Adc_Sar_Ip_EnableChannel/30 -> SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_26/69 : 
       no arg info
    callsite  Adc_Sar_Ip_EnableChannel/30 -> SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_26/68 : 
       no arg info
    callsite  Adc_Sar_Ip_EnableChannel/30 -> SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_23/67 : 
       no arg info
    callsite  Adc_Sar_Ip_EnableChannel/30 -> SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_23/66 : 
       no arg info
  Jump functions of caller  Adc_Sar_Ip_ChainConfig/29:
    callsite  Adc_Sar_Ip_ChainConfig/29 -> Adc_Sar_SetInjectedChain/25 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  Adc_Sar_Ip_ChainConfig/29 -> Adc_Sar_SetNormalChain/24 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  Adc_Sar_Ip_Deinit/28:
    callsite  Adc_Sar_Ip_Deinit/28 -> Adc_Sar_Ip_Powerdown/43 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  Adc_Sar_Ip_Deinit/28 -> Adc_Sar_Ip_SetResolution/32 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: CONST: 1
         value: 0x1, mask: 0x0
         Unknown VR
    callsite  Adc_Sar_Ip_Deinit/28 -> Adc_Sar_Ip_ClearStatusFlags/35 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: CONST: 31
         value: 0x1f, mask: 0x0
         Unknown VR
    callsite  Adc_Sar_Ip_Deinit/28 -> Adc_Sar_ResetWdog/19 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  Adc_Sar_Ip_Deinit/28 -> Adc_Sar_Ip_Init/27 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: UNKNOWN
         Aggregate passed by reference:
           offset: 448, type: boolean, CONST: 0
           offset: 456, type: boolean, CONST: 0
           offset: 480, type: Adc_Sar_Ip_DataAlignedType, CONST: 0
           offset: 512, type: uint16, CONST: 0
           offset: 528, type: uint8, CONST: 0
           offset: 536, type: boolean, CONST: 0
           offset: 544, type: Adc_Sar_Ip_AvgSelectType, CONST: 0
           offset: 576, type: uint8, CONST: 0
           offset: 592, type: uint16, CONST: 0
           offset: 608, type: boolean, CONST: 0
           offset: 640, type: Adc_Sar_Ip_ClearSourceType, CONST: 0
           offset: 864, type: uint8, CONST: 0
           offset: 896, type: const struct Adc_Sar_Ip_ChanConfigType *, CONST: 0B
           offset: 928, type: void (*<T532>) (void), CONST: 0B
           offset: 960, type: void (*<T532>) (void), CONST: 0B
           offset: 992, type: void (*<T532>) (void), CONST: 0B
         value: 0x0, mask: 0xfffffffc
         VR  [1, -1]
  Jump functions of caller  Adc_Sar_Ip_Init/27:
    callsite  Adc_Sar_Ip_Init/27 -> Adc_Sar_Ip_SetPresamplingSource/51 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: CONST: 2
         value: 0x2, mask: 0x0
         Unknown VR
       param 2: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  Adc_Sar_Ip_Init/27 -> Adc_Sar_Ip_SetPresamplingSource/51 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: CONST: 1
         value: 0x1, mask: 0x0
         Unknown VR
       param 2: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  Adc_Sar_Ip_Init/27 -> Adc_Sar_Ip_SetPresamplingSource/51 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: CONST: 0
         value: 0x0, mask: 0x0
         Unknown VR
       param 2: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  Adc_Sar_Ip_Init/27 -> Adc_Sar_ConfigChannels/16 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 2: UNKNOWN
         value: 0x0, mask: 0xff
         Unknown VR
    callsite  Adc_Sar_Ip_Init/27 -> Adc_Sar_Ip_SetResolution/32 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  Adc_Sar_Ip_Init/27 -> Adc_Sar_SetInjectedChain/25 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xffffffff
         VR  [1, -1]
    callsite  Adc_Sar_Ip_Init/27 -> Adc_Sar_SetNormalChain/24 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xffffffff
         VR  [1, -1]
    callsite  Adc_Sar_Ip_Init/27 -> Adc_Sar_Ip_SetSampleTimes/47 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xffffffff
         VR  [1, -1]
    callsite  Adc_Sar_Ip_Init/27 -> Adc_Sar_EnableHighSpeed/2 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0x1
         Unknown VR
    callsite  Adc_Sar_Ip_Init/27 -> Adc_Sar_Ip_Powerup/42 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  Adc_Sar_Ip_Init/27 -> Adc_Sar_CollectMcrMasks/15 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: PASS THROUGH: 1, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 2: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  Adc_Sar_Ip_Init/27 -> Adc_Sar_Ip_Powerdown/43 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  Adc_Sar_Ip_Init/27 -> Adc_Sar_Ip_AbortChain/50 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: CONST: 1
         value: 0x1, mask: 0x0
         Unknown VR
       param 2: CONST: 0
         value: 0x0, mask: 0x0
         Unknown VR
  Jump functions of caller  Adc_Sar_SetInjectedChain/25:
  Jump functions of caller  Adc_Sar_SetNormalChain/24:
  Jump functions of caller  Adc_Sar_Ip_IRQHandler/23:
    callsite  Adc_Sar_Ip_IRQHandler/23 -> Adc_CheckAndCallAllChannelNotification/21 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  Adc_Sar_Ip_IRQHandler/23 -> Adc_Sar_CheckAndCallNotification/20 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  Adc_Sar_Ip_IRQHandler/23 -> Adc_Sar_CheckAndCallNotification/20 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  Adc_Sar_Ip_IRQHandler/23 -> Adc_Sar_CheckAndCallNotification/20 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  Adc_Sar_ConfigExternalTrigger/22:
    callsite  Adc_Sar_ConfigExternalTrigger/22 -> SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_21/138 : 
       no arg info
    callsite  Adc_Sar_ConfigExternalTrigger/22 -> SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_21/137 : 
       no arg info
  Jump functions of caller  Adc_CheckAndCallAllChannelNotification/21:
  Jump functions of caller  Adc_Sar_CheckAndCallNotification/20:
    indirect simple callsite, calling param 1, offset 0, for stmt Callback_3(D) ();
  Jump functions of caller  Adc_Sar_ResetWdog/19:
  Jump functions of caller  Adc_Sar_GetConvResults/18:
    callsite  Adc_Sar_GetConvResults/18 -> Adc_Sar_GetMaskedResult/11 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  Adc_Sar_GetConvResults/18 -> Adc_Sar_GetMaskedResult/11 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  Adc_Sar_CheckSelfTestProgress/17:
    callsite  Adc_Sar_CheckSelfTestProgress/17 -> OsIf_GetElapsed/86 : 
       no arg info
    callsite  Adc_Sar_CheckSelfTestProgress/17 -> OsIf_GetElapsed/86 : 
       no arg info
    callsite  Adc_Sar_CheckSelfTestProgress/17 -> OsIf_GetCounter/79 : 
       no arg info
    callsite  Adc_Sar_CheckSelfTestProgress/17 -> OsIf_MicrosToTicks/78 : 
       no arg info
  Jump functions of caller  Adc_Sar_ConfigChannels/16:
  Jump functions of caller  Adc_Sar_CollectMcrMasks/15:
  Jump functions of caller  Adc_Sar_GetIsrFlags/13:
  Jump functions of caller  Adc_Sar_GetMsrFlags/12:
  Jump functions of caller  Adc_Sar_GetMaskedResult/11:
    callsite  Adc_Sar_GetMaskedResult/11 -> Adc_Sar_GetResolution/10 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  Adc_Sar_GetResolution/10:
  Jump functions of caller  Adc_Sar_EnableHighSpeed/2:

 Propagating constants:

Not considering Adc_Sar_Ip_GetDataAddress/65 for cloning; -fipa-cp-clone disabled.
Not considering Adc_Sar_Ip_SetExternalTrigger/64 for cloning; -fipa-cp-clone disabled.
Not considering Adc_Sar_Ip_SetCtuMode/63 for cloning; -fipa-cp-clone disabled.
Not considering Adc_Sar_Ip_SetConversionMode/62 for cloning; -fipa-cp-clone disabled.
Not considering Adc_Sar_Ip_SetDmaClearSource/61 for cloning; -fipa-cp-clone disabled.
Not considering Adc_Sar_Ip_DisableChannelDmaAll/60 for cloning; -fipa-cp-clone disabled.
Not considering Adc_Sar_Ip_DisableChannelDma/59 for cloning; -fipa-cp-clone disabled.
Not considering Adc_Sar_Ip_EnableChannelDma/58 for cloning; -fipa-cp-clone disabled.
Not considering Adc_Sar_Ip_DisableDma/57 for cloning; -fipa-cp-clone disabled.
Not considering Adc_Sar_Ip_EnableDma/56 for cloning; -fipa-cp-clone disabled.
Not considering Adc_Sar_Ip_DisablePresampleConversion/55 for cloning; -fipa-cp-clone disabled.
Not considering Adc_Sar_Ip_EnablePresampleConversion/54 for cloning; -fipa-cp-clone disabled.
Not considering Adc_Sar_Ip_DisableChannelPresampling/53 for cloning; -fipa-cp-clone disabled.
Not considering Adc_Sar_Ip_EnableChannelPresampling/52 for cloning; -fipa-cp-clone disabled.
Not considering Adc_Sar_Ip_SetPresamplingSource/51 for cloning; -fipa-cp-clone disabled.
Not considering Adc_Sar_Ip_AbortChain/50 for cloning; -fipa-cp-clone disabled.
Not considering Adc_Sar_Ip_AbortConversion/49 for cloning; -fipa-cp-clone disabled.
Not considering Adc_Sar_Ip_SetAveraging/48 for cloning; -fipa-cp-clone disabled.
Not considering Adc_Sar_Ip_SetSampleTimes/47 for cloning; -fipa-cp-clone disabled.
Not considering Adc_Sar_Ip_SetClockMode/46 for cloning; -fipa-cp-clone disabled.
Not considering Adc_Sar_Ip_DisableNotifications/45 for cloning; -fipa-cp-clone disabled.
Not considering Adc_Sar_Ip_EnableNotifications/44 for cloning; -fipa-cp-clone disabled.
Not considering Adc_Sar_Ip_Powerdown/43 for cloning; -fipa-cp-clone disabled.
Not considering Adc_Sar_Ip_Powerup/42 for cloning; -fipa-cp-clone disabled.
Not considering Adc_Sar_Ip_DoCalibration/41 for cloning; -fipa-cp-clone disabled.
Not considering Adc_Sar_Ip_GetConvResult/40 for cloning; -fipa-cp-clone disabled.
Not considering Adc_Sar_Ip_GetConvData/39 for cloning; -fipa-cp-clone disabled.
Not considering Adc_Sar_Ip_GetConvResultsToArray/38 for cloning; -fipa-cp-clone disabled.
Not considering Adc_Sar_Ip_GetConvDataToArray/37 for cloning; -fipa-cp-clone disabled.
Not considering Adc_Sar_Ip_SelfTest/36 for cloning; -fipa-cp-clone disabled.
Not considering Adc_Sar_Ip_ClearStatusFlags/35 for cloning; -fipa-cp-clone disabled.
Not considering Adc_Sar_Ip_GetStatusFlags/34 for cloning; -fipa-cp-clone disabled.
Not considering Adc_Sar_Ip_StartConversion/33 for cloning; -fipa-cp-clone disabled.
Not considering Adc_Sar_Ip_SetResolution/32 for cloning; -fipa-cp-clone disabled.
Not considering Adc_Sar_Ip_DisableChannel/31 for cloning; -fipa-cp-clone disabled.
Not considering Adc_Sar_Ip_EnableChannel/30 for cloning; -fipa-cp-clone disabled.
Not considering Adc_Sar_Ip_ChainConfig/29 for cloning; -fipa-cp-clone disabled.
Not considering Adc_Sar_Ip_Deinit/28 for cloning; -fipa-cp-clone disabled.
Not considering Adc_Sar_Ip_Init/27 for cloning; -fipa-cp-clone disabled.
Not considering Adc_Sar_Ip_IRQHandler/23 for cloning; -fipa-cp-clone disabled.

overall_size: 1627

IPA lattices after all propagation:

Lattices:
  Node: Adc_Sar_Ip_SetPresamplingSource.part.0/147:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         int VARYING
        AGGS VARIABLE
    param [1]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         int VARYING
        AGGS VARIABLE
    param [2]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         int VARYING
        AGGS VARIABLE
  Node: Adc_Sar_Ip_GetDataAddress/65:
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
  Node: Adc_Sar_Ip_SetExternalTrigger/64:
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
    param [2]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         int VARYING
        AGGS BOTTOM
  Node: Adc_Sar_Ip_SetCtuMode/63:
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
  Node: Adc_Sar_Ip_SetConversionMode/62:
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
  Node: Adc_Sar_Ip_SetDmaClearSource/61:
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
  Node: Adc_Sar_Ip_DisableChannelDmaAll/60:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         int VARYING
        AGGS BOTTOM
  Node: Adc_Sar_Ip_DisableChannelDma/59:
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
  Node: Adc_Sar_Ip_EnableChannelDma/58:
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
  Node: Adc_Sar_Ip_DisableDma/57:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         int VARYING
        AGGS BOTTOM
  Node: Adc_Sar_Ip_EnableDma/56:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         int VARYING
        AGGS BOTTOM
  Node: Adc_Sar_Ip_DisablePresampleConversion/55:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         int VARYING
        AGGS BOTTOM
  Node: Adc_Sar_Ip_EnablePresampleConversion/54:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         int VARYING
        AGGS BOTTOM
  Node: Adc_Sar_Ip_DisableChannelPresampling/53:
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
  Node: Adc_Sar_Ip_EnableChannelPresampling/52:
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
  Node: Adc_Sar_Ip_SetPresamplingSource/51:
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
    param [2]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         int VARYING
        AGGS BOTTOM
  Node: Adc_Sar_Ip_AbortChain/50:
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
    param [2]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         int VARYING
        AGGS BOTTOM
  Node: Adc_Sar_Ip_AbortConversion/49:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         int VARYING
        AGGS BOTTOM
  Node: Adc_Sar_Ip_SetAveraging/48:
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
    param [2]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         int VARYING
        AGGS BOTTOM
  Node: Adc_Sar_Ip_SetSampleTimes/47:
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
  Node: Adc_Sar_Ip_SetClockMode/46:
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
  Node: Adc_Sar_Ip_DisableNotifications/45:
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
  Node: Adc_Sar_Ip_EnableNotifications/44:
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
  Node: Adc_Sar_Ip_Powerdown/43:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         int VARYING
        AGGS BOTTOM
  Node: Adc_Sar_Ip_Powerup/42:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         int VARYING
        AGGS BOTTOM
  Node: Adc_Sar_Ip_DoCalibration/41:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         int VARYING
        AGGS BOTTOM
  Node: Adc_Sar_Ip_GetConvResult/40:
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
    param [2]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         int VARYING
        AGGS BOTTOM
    param [3]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         int VARYING
        AGGS BOTTOM
  Node: Adc_Sar_Ip_GetConvData/39:
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
  Node: Adc_Sar_Ip_GetConvResultsToArray/38:
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
    param [2]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         int VARYING
        AGGS BOTTOM
    param [3]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         int VARYING
        AGGS BOTTOM
  Node: Adc_Sar_Ip_GetConvDataToArray/37:
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
    param [2]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         int VARYING
        AGGS BOTTOM
    param [3]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         int VARYING
        AGGS BOTTOM
  Node: Adc_Sar_Ip_SelfTest/36:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         int VARYING
        AGGS BOTTOM
  Node: Adc_Sar_Ip_ClearStatusFlags/35:
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
  Node: Adc_Sar_Ip_GetStatusFlags/34:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         int VARYING
        AGGS BOTTOM
  Node: Adc_Sar_Ip_StartConversion/33:
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
  Node: Adc_Sar_Ip_SetResolution/32:
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
  Node: Adc_Sar_Ip_DisableChannel/31:
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
    param [2]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         int VARYING
        AGGS BOTTOM
  Node: Adc_Sar_Ip_EnableChannel/30:
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
    param [2]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         int VARYING
        AGGS BOTTOM
  Node: Adc_Sar_Ip_ChainConfig/29:
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
    param [2]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         int VARYING
        AGGS BOTTOM
  Node: Adc_Sar_Ip_Deinit/28:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         int VARYING
        AGGS BOTTOM
  Node: Adc_Sar_Ip_Init/27:
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
  Node: Adc_Sar_SetInjectedChain/25:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         int VARYING
        AGGS VARIABLE
    param [1]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         int VARYING
        AGGS VARIABLE
  Node: Adc_Sar_SetNormalChain/24:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         int VARYING
        AGGS VARIABLE
    param [1]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         int VARYING
        AGGS VARIABLE
  Node: Adc_Sar_Ip_IRQHandler/23:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         int VARYING
        AGGS BOTTOM
  Node: Adc_Sar_ConfigExternalTrigger/22:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         int VARYING
        AGGS VARIABLE
    param [1]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         int VARYING
        AGGS VARIABLE
    param [2]: 2097152 [loc_time: 1, loc_size: 30, prop_time: 0, prop_size: 0]
               67108864 [loc_time: 1, loc_size: 30, prop_time: 0, prop_size: 0]
         ctxs: VARIABLE
         Bits: value = 0x200000, mask = 0x4200000
         const uint32 [2097152, 67108864]
        AGGS VARIABLE
    param [3]: 2097152 [loc_time: 1, loc_size: 31, prop_time: 0, prop_size: 0]
               67108864 [loc_time: 1, loc_size: 31, prop_time: 0, prop_size: 0]
               0 [loc_time: 1, loc_size: 31, prop_time: 0, prop_size: 0]
         ctxs: VARIABLE
         Bits: value = 0x200000, mask = 0x4200000
         const uint32 [0, 67108864]
        AGGS VARIABLE
    param [4]: 4194304 [loc_time: 1, loc_size: 31, prop_time: 0, prop_size: 0]
               167772160 [loc_time: 1, loc_size: 31, prop_time: 0, prop_size: 0]
               33554432 [loc_time: 1, loc_size: 31, prop_time: 0, prop_size: 0]
               134217728 [loc_time: 1, loc_size: 31, prop_time: 0, prop_size: 0]
         ctxs: VARIABLE
         Bits: value = 0x400000, mask = 0xa400000
         const uint32 [4194304, 167772160]
        AGGS VARIABLE
  Node: Adc_CheckAndCallAllChannelNotification/21:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         int VARYING
        AGGS VARIABLE
  Node: Adc_Sar_CheckAndCallNotification/20:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         int VARYING
        AGGS VARIABLE
    param [1]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         int VARYING
        AGGS VARIABLE
  Node: Adc_Sar_ResetWdog/19:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         int VARYING
        AGGS VARIABLE
  Node: Adc_Sar_GetConvResults/18:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         int VARYING
        AGGS VARIABLE
    param [1]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         int VARYING
        AGGS VARIABLE
    param [2]: VARIABLE
               0B [loc_time: 57, loc_size: 67, prop_time: 0, prop_size: 0]
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         int VARYING
        AGGS VARIABLE
    param [3]: VARIABLE
               0B [loc_time: 57, loc_size: 62, prop_time: 0, prop_size: 0]
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         int VARYING
        AGGS VARIABLE
    param [4]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         int VARYING
        AGGS VARIABLE
  Node: Adc_Sar_CheckSelfTestProgress/17:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         int VARYING
        AGGS VARIABLE
  Node: Adc_Sar_ConfigChannels/16:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         int VARYING
        AGGS VARIABLE
    param [1]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         int VARYING
        AGGS VARIABLE
    param [2]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         int VARYING
        AGGS VARIABLE
  Node: Adc_Sar_CollectMcrMasks/15:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         int VARYING
        AGGS VARIABLE
    param [1]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         int VARYING
        AGGS VARIABLE
    param [2]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         int VARYING
        AGGS VARIABLE
  Node: Adc_Sar_GetIsrFlags/13:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         int VARYING
        AGGS VARIABLE
  Node: Adc_Sar_GetMsrFlags/12:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         int VARYING
        AGGS VARIABLE
  Node: Adc_Sar_GetMaskedResult/11:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         int VARYING
        AGGS VARIABLE
    param [1]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         int VARYING
        AGGS VARIABLE
  Node: Adc_Sar_GetResolution/10:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         int VARYING
        AGGS VARIABLE
  Node: Adc_Sar_EnableHighSpeed/2:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         int VARYING
        AGGS VARIABLE
    param [1]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         int VARYING
        AGGS VARIABLE

IPA decision stage:

Propagated bits info for function Adc_Sar_ConfigExternalTrigger/22:
 param 2: value = 0x200000, mask = 0x4200000
 param 3: value = 0x200000, mask = 0x4200000
 param 4: value = 0x400000, mask = 0xa400000

IPA constant propagation end

Reclaiming functions:
Reclaiming variables:
Clearing address taken flags:
Symbol table:

Adc_Sar_Ip_SetPresamplingSource.part.0/147 (Adc_Sar_Ip_SetPresamplingSource.part.0) @062db700
  Type: function definition analyzed
  Visibility: prevailing_def_ironly artificial
  References: Adc_Sar_Ip_apxAdcBase/5 (read) 
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) body local split_part optimize_size
  Called by: Adc_Sar_Ip_SetPresamplingSource/51 (354334800 (estimated locally),0.33 per call) 
  Calls: SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_38/111 (1073741824 (estimated locally),1.00 per call) SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_38/112 (1073741824 (estimated locally),1.00 per call) 
SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_21/138 (SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_21) @06344000
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Adc_Sar_ConfigExternalTrigger/22 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_21/137 (SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_21) @06338ee0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Adc_Sar_ConfigExternalTrigger/22 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_20/136 (SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_20) @06338c40
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Adc_Sar_Ip_SetCtuMode/63 (177167400 (estimated locally),0.16 per call) Adc_Sar_Ip_SetCtuMode/63 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_20/135 (SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_20) @06338b60
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Adc_Sar_Ip_SetCtuMode/63 (177167400 (estimated locally),0.16 per call) Adc_Sar_Ip_SetCtuMode/63 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_19/134 (SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_19) @063389a0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Adc_Sar_Ip_SetConversionMode/62 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_19/133 (SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_19) @063388c0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Adc_Sar_Ip_SetConversionMode/62 (1073741817 (estimated locally),1.00 per call) 
  Calls: 
SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_45/132 (SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_45) @06338700
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Adc_Sar_Ip_SetDmaClearSource/61 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_45/131 (SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_45) @06338620
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Adc_Sar_Ip_SetDmaClearSource/61 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_48/130 (SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_48) @06338460
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Adc_Sar_Ip_DisableChannelDmaAll/60 (955630225 (estimated locally),8.09 per call) 
  Calls: 
SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_48/129 (SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_48) @06338380
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Adc_Sar_Ip_DisableChannelDmaAll/60 (955630225 (estimated locally),8.09 per call) 
  Calls: 
SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_47/128 (SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_47) @063381c0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Adc_Sar_Ip_DisableChannelDma/59 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_47/127 (SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_47) @063380e0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Adc_Sar_Ip_DisableChannelDma/59 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_46/126 (SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_46) @06332ee0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Adc_Sar_Ip_EnableChannelDma/58 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_46/125 (SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_46) @06332e00
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Adc_Sar_Ip_EnableChannelDma/58 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_44/124 (SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_44) @06332c40
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Adc_Sar_Ip_DisableDma/57 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_44/123 (SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_44) @06332b60
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Adc_Sar_Ip_DisableDma/57 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_43/122 (SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_43) @063329a0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Adc_Sar_Ip_EnableDma/56 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_43/121 (SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_43) @063328c0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Adc_Sar_Ip_EnableDma/56 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_40/120 (SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_40) @06332700
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Adc_Sar_Ip_DisablePresampleConversion/55 (354334800 (estimated locally),0.33 per call) 
  Calls: 
SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_40/119 (SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_40) @06332620
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Adc_Sar_Ip_DisablePresampleConversion/55 (354334800 (estimated locally),0.33 per call) 
  Calls: 
SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_39/118 (SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_39) @06332460
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Adc_Sar_Ip_EnablePresampleConversion/54 (354334800 (estimated locally),0.33 per call) 
  Calls: 
SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_39/117 (SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_39) @06332380
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Adc_Sar_Ip_EnablePresampleConversion/54 (354334800 (estimated locally),0.33 per call) 
  Calls: 
SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_42/116 (SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_42) @063321c0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Adc_Sar_Ip_DisableChannelPresampling/53 (354334800 (estimated locally),0.33 per call) 
  Calls: 
SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_42/115 (SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_42) @063320e0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Adc_Sar_Ip_DisableChannelPresampling/53 (354334800 (estimated locally),0.33 per call) 
  Calls: 
SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_41/114 (SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_41) @06326ee0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Adc_Sar_Ip_EnableChannelPresampling/52 (354334800 (estimated locally),0.33 per call) 
  Calls: 
SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_41/113 (SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_41) @06326e00
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Adc_Sar_Ip_EnableChannelPresampling/52 (354334800 (estimated locally),0.33 per call) 
  Calls: 
SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_38/112 (SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_38) @06326c40
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Adc_Sar_Ip_SetPresamplingSource.part.0/147 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_38/111 (SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_38) @06326b60
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Adc_Sar_Ip_SetPresamplingSource.part.0/147 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_18/110 (SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_18) @063269a0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Adc_Sar_Ip_AbortChain/50 (229727060 (estimated locally),1.00 per call) 
  Calls: 
SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_18/109 (SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_18) @063268c0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Adc_Sar_Ip_AbortChain/50 (229727060 (estimated locally),1.00 per call) 
  Calls: 
SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_17/108 (SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_17) @06326700
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Adc_Sar_Ip_AbortConversion/49 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_17/107 (SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_17) @06326620
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Adc_Sar_Ip_AbortConversion/49 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_16/106 (SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_16) @06326460
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Adc_Sar_Ip_SetAveraging/48 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_16/105 (SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_16) @06326380
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Adc_Sar_Ip_SetAveraging/48 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_51/104 (SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_51) @063260e0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Adc_Sar_Ip_SetClockMode/46 (116930483 (estimated locally),0.11 per call) 
  Calls: 
SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_51/103 (SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_51) @06326000
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Adc_Sar_Ip_SetClockMode/46 (116930483 (estimated locally),0.11 per call) 
  Calls: 
SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_15/102 (SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_15) @0631cee0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Adc_Sar_Ip_SetClockMode/46 (354334800 (estimated locally),0.33 per call) 
  Calls: 
SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_15/101 (SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_15) @0631ce00
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Adc_Sar_Ip_SetClockMode/46 (354334800 (estimated locally),0.33 per call) 
  Calls: 
SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_34/100 (SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_34) @0631cc40
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Adc_Sar_Ip_DisableNotifications/45 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_34/99 (SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_34) @0631cb60
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Adc_Sar_Ip_DisableNotifications/45 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_33/98 (SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_33) @0631c9a0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Adc_Sar_Ip_EnableNotifications/44 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_33/97 (SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_33) @0631c8c0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Adc_Sar_Ip_EnableNotifications/44 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_14/96 (SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_14) @0631c620
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Adc_Sar_Ip_Powerdown/43 (114863530 (estimated locally),1.00 per call) 
  Calls: 
SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_14/95 (SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_14) @0631c540
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Adc_Sar_Ip_Powerdown/43 (114863530 (estimated locally),1.00 per call) 
  Calls: 
SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_13/94 (SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_13) @0631c2a0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Adc_Sar_Ip_Powerup/42 (114863530 (estimated locally),1.00 per call) 
  Calls: 
SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_13/93 (SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_13) @0631c1c0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Adc_Sar_Ip_Powerup/42 (114863530 (estimated locally),1.00 per call) 
  Calls: 
SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_36/92 (SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_36) @0631c000
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Adc_Sar_Ip_DoCalibration/41 (114863530 (estimated locally),0.11 per call) 
  Calls: 
SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_36/91 (SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_36) @06306ee0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Adc_Sar_Ip_DoCalibration/41 (114863530 (estimated locally),0.11 per call) 
  Calls: 
SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_12/90 (SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_12) @06306e00
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Adc_Sar_Ip_DoCalibration/41 (348071307 (estimated locally),0.33 per call) Adc_Sar_Ip_DoCalibration/41 (348071305 (estimated locally),0.33 per call) 
  Calls: 
SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_12/89 (SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_12) @06306d20
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Adc_Sar_Ip_DoCalibration/41 (348071307 (estimated locally),0.33 per call) Adc_Sar_Ip_DoCalibration/41 (348071305 (estimated locally),0.33 per call) 
  Calls: 
ResolutionArray.0/88 (ResolutionArray) @0630bc18
  Type: variable definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: Adc_Sar_GetResolution/10 (read) 
  Availability: available
  Varpool flags: initialized read-only const-value-known
*.LC0/87 (*.LC0) @0630b0d8
  Type: variable definition analyzed
  Visibility: prevailing_def_ironly artificial
  References: 
  Referring: Adc_Sar_GetConvResults/18 (read) 
  Availability: available
  Varpool flags: initialized read-only const-value-known
OsIf_GetElapsed/86 (OsIf_GetElapsed) @06306380
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Adc_Sar_Ip_AbortChain/50 (958878296 (estimated locally),4.17 per call) Adc_Sar_Ip_DoCalibration/41 (958878295 (estimated locally),0.91 per call) Adc_Sar_Ip_Powerdown/43 (958878296 (estimated locally),8.35 per call) Adc_Sar_Ip_Powerup/42 (958878296 (estimated locally),8.35 per call) Adc_Sar_Ip_SelfTest/36 (958878296 (estimated locally),4.17 per call) Adc_Sar_CheckSelfTestProgress/17 (129448572 (estimated locally),2.08 per call) Adc_Sar_CheckSelfTestProgress/17 (958878294 (estimated locally),15.42 per call) 
  Calls: 
SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_35/85 (SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_35) @063062a0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Adc_Sar_Ip_SelfTest/36 (229727061 (estimated locally),1.00 per call) Adc_Sar_Ip_SelfTest/36 (229727060 (estimated locally),1.00 per call) 
  Calls: 
SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_35/84 (SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_35) @063061c0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Adc_Sar_Ip_SelfTest/36 (229727061 (estimated locally),1.00 per call) Adc_Sar_Ip_SelfTest/36 (229727060 (estimated locally),1.00 per call) 
  Calls: 
SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_11/83 (SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_11) @063060e0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Adc_Sar_Ip_SelfTest/36 (229727060 (estimated locally),1.00 per call) Adc_Sar_Ip_SelfTest/36 (229727060 (estimated locally),1.00 per call) Adc_Sar_Ip_SelfTest/36 (229727060 (estimated locally),1.00 per call) 
  Calls: 
SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_11/82 (SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_11) @06306000
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Adc_Sar_Ip_SelfTest/36 (229727060 (estimated locally),1.00 per call) Adc_Sar_Ip_SelfTest/36 (229727060 (estimated locally),1.00 per call) Adc_Sar_Ip_SelfTest/36 (229727060 (estimated locally),1.00 per call) 
  Calls: 
SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_25/81 (SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_25) @062f5ee0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Adc_Sar_Ip_SelfTest/36 (229727060 (estimated locally),1.00 per call) 
  Calls: 
SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_25/80 (SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_25) @062f5e00
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Adc_Sar_Ip_SelfTest/36 (229727060 (estimated locally),1.00 per call) 
  Calls: 
OsIf_GetCounter/79 (OsIf_GetCounter) @062f5d20
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Adc_Sar_Ip_AbortChain/50 (229727060 (estimated locally),1.00 per call) Adc_Sar_Ip_DoCalibration/41 (1054761537 (estimated locally),1.00 per call) Adc_Sar_Ip_Powerdown/43 (114863530 (estimated locally),1.00 per call) Adc_Sar_Ip_Powerup/42 (114863530 (estimated locally),1.00 per call) Adc_Sar_Ip_SelfTest/36 (229727060 (estimated locally),1.00 per call) Adc_Sar_CheckSelfTestProgress/17 (62173924 (estimated locally),1.00 per call) 
  Calls: 
OsIf_MicrosToTicks/78 (OsIf_MicrosToTicks) @062f5c40
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Adc_Sar_Ip_AbortChain/50 (229727060 (estimated locally),1.00 per call) Adc_Sar_Ip_DoCalibration/41 (1054761537 (estimated locally),1.00 per call) Adc_Sar_Ip_Powerdown/43 (114863530 (estimated locally),1.00 per call) Adc_Sar_Ip_Powerup/42 (114863530 (estimated locally),1.00 per call) Adc_Sar_Ip_SelfTest/36 (229727060 (estimated locally),1.00 per call) Adc_Sar_CheckSelfTestProgress/17 (62173924 (estimated locally),1.00 per call) 
  Calls: 
SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_10/77 (SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_10) @062f5700
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Adc_Sar_Ip_StartConversion/33 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_10/76 (SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_10) @062f5620
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Adc_Sar_Ip_StartConversion/33 (1073741817 (estimated locally),1.00 per call) 
  Calls: 
SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_37/75 (SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_37) @062f5460
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Adc_Sar_Ip_SetResolution/32 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_37/74 (SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_37) @062f5380
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Adc_Sar_Ip_SetResolution/32 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_27/73 (SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_27) @062f51c0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Adc_Sar_Ip_DisableChannel/31 (357913942 (estimated locally),0.33 per call) 
  Calls: 
SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_27/72 (SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_27) @062f50e0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Adc_Sar_Ip_DisableChannel/31 (357913942 (estimated locally),0.33 per call) 
  Calls: 
SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_24/71 (SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_24) @062f5000
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Adc_Sar_Ip_DisableChannel/31 (357913942 (estimated locally),0.33 per call) 
  Calls: 
SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_24/70 (SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_24) @05ae3ee0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Adc_Sar_Ip_DisableChannel/31 (357913942 (estimated locally),0.33 per call) 
  Calls: 
SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_26/69 (SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_26) @05ae3d20
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Adc_Sar_Ip_EnableChannel/30 (357913942 (estimated locally),0.33 per call) 
  Calls: 
SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_26/68 (SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_26) @05ae3c40
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Adc_Sar_Ip_EnableChannel/30 (357913942 (estimated locally),0.33 per call) 
  Calls: 
SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_23/67 (SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_23) @05ae3b60
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Adc_Sar_Ip_EnableChannel/30 (357913942 (estimated locally),0.33 per call) 
  Calls: 
SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_23/66 (SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_23) @05ae3a80
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Adc_Sar_Ip_EnableChannel/30 (357913942 (estimated locally),0.33 per call) 
  Calls: 
Adc_Sar_Ip_GetDataAddress/65 (Adc_Sar_Ip_GetDataAddress) @062db9a0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: Adc_Sar_Ip_apxAdcBase/5 (read) 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
Adc_Sar_Ip_SetExternalTrigger/64 (Adc_Sar_Ip_SetExternalTrigger) @062db620
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741809 (estimated locally) body optimize_size
  Called by: 
  Calls: Adc_Sar_ConfigExternalTrigger/22 (214748365 (estimated locally),0.20 per call) Adc_Sar_ConfigExternalTrigger/22 (214748365 (estimated locally),0.20 per call) Adc_Sar_ConfigExternalTrigger/22 (214748365 (estimated locally),0.20 per call) Adc_Sar_ConfigExternalTrigger/22 (214748365 (estimated locally),0.20 per call) 
Adc_Sar_Ip_SetCtuMode/63 (Adc_Sar_Ip_SetCtuMode) @062db380
  Type: function definition analyzed
  Visibility: externally_visible public
  References: Adc_Sar_Ip_apxAdcBase/5 (read) Adc_Sar_Ip_au32AdcFeatureBitmap/9 (read) 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: Adc_Sar_Ip_Powerup/42 (536870913 (estimated locally),0.50 per call) SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_20/136 (177167400 (estimated locally),0.16 per call) SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_20/135 (177167400 (estimated locally),0.16 per call) Adc_Sar_Ip_Powerdown/43 (1073741824 (estimated locally),1.00 per call) SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_20/136 (1073741824 (estimated locally),1.00 per call) SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_20/135 (1073741824 (estimated locally),1.00 per call) 
Adc_Sar_Ip_SetConversionMode/62 (Adc_Sar_Ip_SetConversionMode) @062830e0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: Adc_Sar_Ip_apxAdcBase/5 (read) 
  Referring: 
  Availability: available
  Function flags: count:1073741817 (estimated locally) body optimize_size
  Called by: 
  Calls: SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_19/134 (1073741824 (estimated locally),1.00 per call) SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_19/133 (1073741817 (estimated locally),1.00 per call) 
Adc_Sar_Ip_SetDmaClearSource/61 (Adc_Sar_Ip_SetDmaClearSource) @06283b60
  Type: function definition analyzed
  Visibility: externally_visible public
  References: Adc_Sar_Ip_apxAdcBase/5 (read) 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_45/132 (1073741824 (estimated locally),1.00 per call) SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_45/131 (1073741824 (estimated locally),1.00 per call) 
Adc_Sar_Ip_DisableChannelDmaAll/60 (Adc_Sar_Ip_DisableChannelDmaAll) @062837e0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: Adc_Sar_Ip_apxAdcBase/5 (read) Adc_Sar_Ip_au32AdcChanBitmap/8 (read) Adc_Sar_Ip_au8AdcGroupCount/7 (read) 
  Referring: 
  Availability: available
  Function flags: count:118111600 (estimated locally) body optimize_size
  Called by: 
  Calls: SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_48/130 (955630225 (estimated locally),8.09 per call) SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_48/129 (955630225 (estimated locally),8.09 per call) 
Adc_Sar_Ip_DisableChannelDma/59 (Adc_Sar_Ip_DisableChannelDma) @06283540
  Type: function definition analyzed
  Visibility: externally_visible public
  References: Adc_Sar_Ip_apxAdcBase/5 (read) 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_47/128 (1073741824 (estimated locally),1.00 per call) SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_47/127 (1073741824 (estimated locally),1.00 per call) 
Adc_Sar_Ip_EnableChannelDma/58 (Adc_Sar_Ip_EnableChannelDma) @062832a0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: Adc_Sar_Ip_apxAdcBase/5 (read) 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_46/126 (1073741824 (estimated locally),1.00 per call) SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_46/125 (1073741824 (estimated locally),1.00 per call) 
Adc_Sar_Ip_DisableDma/57 (Adc_Sar_Ip_DisableDma) @06283000
  Type: function definition analyzed
  Visibility: externally_visible public
  References: Adc_Sar_Ip_apxAdcBase/5 (read) 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_44/124 (1073741824 (estimated locally),1.00 per call) SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_44/123 (1073741824 (estimated locally),1.00 per call) 
Adc_Sar_Ip_EnableDma/56 (Adc_Sar_Ip_EnableDma) @0627e540
  Type: function definition analyzed
  Visibility: externally_visible public
  References: Adc_Sar_Ip_apxAdcBase/5 (read) 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_43/122 (1073741824 (estimated locally),1.00 per call) SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_43/121 (1073741824 (estimated locally),1.00 per call) 
Adc_Sar_Ip_DisablePresampleConversion/55 (Adc_Sar_Ip_DisablePresampleConversion) @0627ed20
  Type: function definition analyzed
  Visibility: externally_visible public
  References: Adc_Sar_Ip_au32AdcFeatureBitmap/9 (read) Adc_Sar_Ip_apxAdcBase/5 (read) 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_40/120 (354334800 (estimated locally),0.33 per call) SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_40/119 (354334800 (estimated locally),0.33 per call) 
Adc_Sar_Ip_EnablePresampleConversion/54 (Adc_Sar_Ip_EnablePresampleConversion) @0627e8c0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: Adc_Sar_Ip_au32AdcFeatureBitmap/9 (read) Adc_Sar_Ip_apxAdcBase/5 (read) 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_39/118 (354334800 (estimated locally),0.33 per call) SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_39/117 (354334800 (estimated locally),0.33 per call) 
Adc_Sar_Ip_DisableChannelPresampling/53 (Adc_Sar_Ip_DisableChannelPresampling) @0627e460
  Type: function definition analyzed
  Visibility: externally_visible public
  References: Adc_Sar_Ip_au32AdcFeatureBitmap/9 (read) Adc_Sar_Ip_apxAdcBase/5 (read) 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_42/116 (354334800 (estimated locally),0.33 per call) SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_42/115 (354334800 (estimated locally),0.33 per call) 
Adc_Sar_Ip_EnableChannelPresampling/52 (Adc_Sar_Ip_EnableChannelPresampling) @0627e0e0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: Adc_Sar_Ip_au32AdcFeatureBitmap/9 (read) Adc_Sar_Ip_apxAdcBase/5 (read) 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_41/114 (354334800 (estimated locally),0.33 per call) SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_41/113 (354334800 (estimated locally),0.33 per call) 
Adc_Sar_Ip_SetPresamplingSource/51 (Adc_Sar_Ip_SetPresamplingSource) @062777e0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: Adc_Sar_Ip_au32AdcFeatureBitmap/9 (read) 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: Adc_Sar_Ip_Init/27 (177167400 (estimated locally),0.16 per call) Adc_Sar_Ip_Init/27 (177167400 (estimated locally),0.16 per call) Adc_Sar_Ip_Init/27 (177167400 (estimated locally),0.16 per call) 
  Calls: Adc_Sar_Ip_SetPresamplingSource.part.0/147 (354334800 (estimated locally),0.33 per call) 
Adc_Sar_Ip_AbortChain/50 (Adc_Sar_Ip_AbortChain) @06277b60
  Type: function definition analyzed
  Visibility: externally_visible public
  References: Adc_Sar_Ip_apxAdcBase/5 (read) 
  Referring: 
  Availability: available
  Function flags: count:229727060 (estimated locally) body optimize_size
  Called by: Adc_Sar_Ip_Init/27 (1073741824 (estimated locally),1.00 per call) 
  Calls: OsIf_GetElapsed/86 (958878296 (estimated locally),4.17 per call) SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_18/110 (229727060 (estimated locally),1.00 per call) SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_18/109 (229727060 (estimated locally),1.00 per call) OsIf_GetCounter/79 (229727060 (estimated locally),1.00 per call) OsIf_MicrosToTicks/78 (229727060 (estimated locally),1.00 per call) 
Adc_Sar_Ip_AbortConversion/49 (Adc_Sar_Ip_AbortConversion) @06277700
  Type: function definition analyzed
  Visibility: externally_visible public
  References: Adc_Sar_Ip_apxAdcBase/5 (read) 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_17/108 (1073741824 (estimated locally),1.00 per call) SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_17/107 (1073741824 (estimated locally),1.00 per call) 
Adc_Sar_Ip_SetAveraging/48 (Adc_Sar_Ip_SetAveraging) @06277380
  Type: function definition analyzed
  Visibility: externally_visible public
  References: Adc_Sar_Ip_apxAdcBase/5 (read) 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: Adc_Sar_Ip_SetClockMode/46 (116930483 (estimated locally),0.11 per call) 
  Calls: SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_16/106 (1073741824 (estimated locally),1.00 per call) SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_16/105 (1073741824 (estimated locally),1.00 per call) 
Adc_Sar_Ip_SetSampleTimes/47 (Adc_Sar_Ip_SetSampleTimes) @06271c40
  Type: function definition analyzed
  Visibility: externally_visible public
  References: Adc_Sar_Ip_apxAdcBase/5 (read) Adc_Sar_Ip_au8AdcGroupCount/7 (read) 
  Referring: 
  Availability: available
  Function flags: count:118111600 (estimated locally) body optimize_size
  Called by: Adc_Sar_Ip_Init/27 (177167400 (estimated locally),0.16 per call) Adc_Sar_Ip_SetClockMode/46 (116930483 (estimated locally),0.11 per call) 
  Calls: 
Adc_Sar_Ip_SetClockMode/46 (Adc_Sar_Ip_SetClockMode) @06271ee0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: Adc_Sar_Ip_apxAdcBase/5 (read) 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: Adc_Sar_Ip_SetSampleTimes/47 (116930483 (estimated locally),0.11 per call) Adc_Sar_Ip_SetAveraging/48 (116930483 (estimated locally),0.11 per call) SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_51/104 (116930483 (estimated locally),0.11 per call) Adc_Sar_EnableHighSpeed/2 (116930483 (estimated locally),0.11 per call) SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_51/103 (116930483 (estimated locally),0.11 per call) Adc_Sar_Ip_Powerup/42 (354334800 (estimated locally),0.33 per call) SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_15/102 (354334800 (estimated locally),0.33 per call) SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_15/101 (354334800 (estimated locally),0.33 per call) Adc_Sar_Ip_Powerdown/43 (1073741824 (estimated locally),1.00 per call) 
Adc_Sar_Ip_DisableNotifications/45 (Adc_Sar_Ip_DisableNotifications) @06271b60
  Type: function definition analyzed
  Visibility: externally_visible public
  References: Adc_Sar_Ip_apxAdcBase/5 (read) Adc_Sar_Ip_au32AdcFeatureBitmap/9 (read) 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_34/100 (1073741824 (estimated locally),1.00 per call) SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_34/99 (1073741824 (estimated locally),1.00 per call) 
Adc_Sar_Ip_EnableNotifications/44 (Adc_Sar_Ip_EnableNotifications) @06271540
  Type: function definition analyzed
  Visibility: externally_visible public
  References: Adc_Sar_Ip_apxAdcBase/5 (read) Adc_Sar_Ip_au32AdcFeatureBitmap/9 (read) 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_33/98 (1073741824 (estimated locally),1.00 per call) SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_33/97 (1073741824 (estimated locally),1.00 per call) 
Adc_Sar_Ip_Powerdown/43 (Adc_Sar_Ip_Powerdown) @06263d20
  Type: function definition analyzed
  Visibility: externally_visible public
  References: Adc_Sar_Ip_apxAdcBase/5 (read) 
  Referring: 
  Availability: available
  Function flags: count:114863530 (estimated locally) body optimize_size
  Called by: Adc_Sar_Ip_SetCtuMode/63 (1073741824 (estimated locally),1.00 per call) Adc_Sar_Ip_Deinit/28 (134217728 (estimated locally),0.50 per call) Adc_Sar_Ip_Init/27 (1073741824 (estimated locally),1.00 per call) Adc_Sar_Ip_SetClockMode/46 (1073741824 (estimated locally),1.00 per call) Adc_Sar_Ip_DoCalibration/41 (114863531 (estimated locally),0.11 per call) Adc_Sar_Ip_DoCalibration/41 (1054761537 (estimated locally),1.00 per call) 
  Calls: OsIf_GetElapsed/86 (958878296 (estimated locally),8.35 per call) SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_14/96 (114863530 (estimated locally),1.00 per call) SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_14/95 (114863530 (estimated locally),1.00 per call) OsIf_GetCounter/79 (114863530 (estimated locally),1.00 per call) OsIf_MicrosToTicks/78 (114863530 (estimated locally),1.00 per call) 
Adc_Sar_Ip_Powerup/42 (Adc_Sar_Ip_Powerup) @06263000
  Type: function definition analyzed
  Visibility: externally_visible public
  References: Adc_Sar_Ip_apxAdcBase/5 (read) 
  Referring: 
  Availability: available
  Function flags: count:114863530 (estimated locally) body optimize_size
  Called by: Adc_Sar_Ip_SetCtuMode/63 (536870913 (estimated locally),0.50 per call) Adc_Sar_Ip_Init/27 (354334800 (estimated locally),0.33 per call) Adc_Sar_Ip_SetClockMode/46 (354334800 (estimated locally),0.33 per call) Adc_Sar_Ip_DoCalibration/41 (114863531 (estimated locally),0.11 per call) Adc_Sar_Ip_DoCalibration/41 (348071305 (estimated locally),0.33 per call) 
  Calls: OsIf_GetElapsed/86 (958878296 (estimated locally),8.35 per call) SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_13/94 (114863530 (estimated locally),1.00 per call) SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_13/93 (114863530 (estimated locally),1.00 per call) OsIf_GetCounter/79 (114863530 (estimated locally),1.00 per call) OsIf_MicrosToTicks/78 (114863530 (estimated locally),1.00 per call) 
Adc_Sar_Ip_DoCalibration/41 (Adc_Sar_Ip_DoCalibration) @06263c40
  Type: function definition analyzed
  Visibility: externally_visible public
  References: Adc_Sar_Ip_apxAdcBase/5 (read) Adc_Sar_Ip_axAdcSarState/6 (read) 
  Referring: 
  Availability: available
  Function flags: count:1054761537 (estimated locally) body optimize_size
  Called by: 
  Calls: Adc_Sar_Ip_Powerup/42 (114863531 (estimated locally),0.11 per call) SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_12/90 (348071307 (estimated locally),0.33 per call) SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_12/89 (348071307 (estimated locally),0.33 per call) Adc_Sar_Ip_Powerdown/43 (114863531 (estimated locally),0.11 per call) OsIf_GetElapsed/86 (958878295 (estimated locally),0.91 per call) SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_36/92 (114863530 (estimated locally),0.11 per call) SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_36/91 (114863530 (estimated locally),0.11 per call) Adc_Sar_Ip_Powerup/42 (348071305 (estimated locally),0.33 per call) SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_12/90 (348071305 (estimated locally),0.33 per call) SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_12/89 (348071305 (estimated locally),0.33 per call) Adc_Sar_Ip_Powerdown/43 (1054761537 (estimated locally),1.00 per call) OsIf_GetCounter/79 (1054761537 (estimated locally),1.00 per call) OsIf_MicrosToTicks/78 (1054761537 (estimated locally),1.00 per call) 
Adc_Sar_Ip_GetConvResult/40 (Adc_Sar_Ip_GetConvResult) @06263700
  Type: function definition analyzed
  Visibility: externally_visible public
  References: Adc_Sar_Ip_apxAdcBase/5 (read) 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: Adc_Sar_GetMaskedResult/11 (354334800 (estimated locally),0.33 per call) 
Adc_Sar_Ip_GetConvData/39 (Adc_Sar_Ip_GetConvData) @062632a0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: Adc_Sar_Ip_apxAdcBase/5 (read) 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: Adc_Sar_GetMaskedResult/11 (354334800 (estimated locally),0.33 per call) 
Adc_Sar_Ip_GetConvResultsToArray/38 (Adc_Sar_Ip_GetConvResultsToArray) @0625ed20
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: Adc_Sar_GetConvResults/18 (1073741824 (estimated locally),1.00 per call) 
Adc_Sar_Ip_GetConvDataToArray/37 (Adc_Sar_Ip_GetConvDataToArray) @0625eee0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: Adc_Sar_GetConvResults/18 (1073741824 (estimated locally),1.00 per call) 
Adc_Sar_Ip_SelfTest/36 (Adc_Sar_Ip_SelfTest) @0625ec40
  Type: function definition analyzed
  Visibility: externally_visible public
  References: Adc_Sar_Ip_apxAdcBase/5 (read) 
  Referring: 
  Availability: available
  Function flags: count:229727060 (estimated locally) body optimize_size
  Called by: 
  Calls: SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_35/85 (229727061 (estimated locally),1.00 per call) SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_35/84 (229727061 (estimated locally),1.00 per call) OsIf_GetElapsed/86 (958878296 (estimated locally),4.17 per call) SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_11/83 (229727060 (estimated locally),1.00 per call) SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_11/82 (229727060 (estimated locally),1.00 per call) Adc_Sar_CheckSelfTestProgress/17 (229727060 (estimated locally),1.00 per call) SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_11/83 (229727060 (estimated locally),1.00 per call) SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_11/82 (229727060 (estimated locally),1.00 per call) SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_35/85 (229727060 (estimated locally),1.00 per call) SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_35/84 (229727060 (estimated locally),1.00 per call) SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_11/83 (229727060 (estimated locally),1.00 per call) SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_11/82 (229727060 (estimated locally),1.00 per call) SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_25/81 (229727060 (estimated locally),1.00 per call) SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_25/80 (229727060 (estimated locally),1.00 per call) OsIf_GetCounter/79 (229727060 (estimated locally),1.00 per call) OsIf_MicrosToTicks/78 (229727060 (estimated locally),1.00 per call) 
Adc_Sar_Ip_ClearStatusFlags/35 (Adc_Sar_Ip_ClearStatusFlags) @0625e0e0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: Adc_Sar_Ip_apxAdcBase/5 (read) Adc_Sar_Ip_au32AdcFeatureBitmap/9 (read) 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: Adc_Sar_Ip_Deinit/28 (134217728 (estimated locally),0.50 per call) 
  Calls: 
Adc_Sar_Ip_GetStatusFlags/34 (Adc_Sar_Ip_GetStatusFlags) @06255d20
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: Adc_Sar_GetIsrFlags/13 (1073741824 (estimated locally),1.00 per call) Adc_Sar_GetMsrFlags/12 (1073741824 (estimated locally),1.00 per call) 
Adc_Sar_Ip_StartConversion/33 (Adc_Sar_Ip_StartConversion) @06255a80
  Type: function definition analyzed
  Visibility: externally_visible public
  References: Adc_Sar_Ip_apxAdcBase/5 (read) 
  Referring: 
  Availability: available
  Function flags: count:1073741817 (estimated locally) body optimize_size
  Called by: 
  Calls: SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_10/77 (1073741824 (estimated locally),1.00 per call) SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_10/76 (1073741817 (estimated locally),1.00 per call) 
Adc_Sar_Ip_SetResolution/32 (Adc_Sar_Ip_SetResolution) @06255620
  Type: function definition analyzed
  Visibility: externally_visible public
  References: Adc_Sar_Ip_apxAdcBase/5 (read) 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: Adc_Sar_Ip_Deinit/28 (134217728 (estimated locally),0.50 per call) Adc_Sar_Ip_Init/27 (177167400 (estimated locally),0.16 per call) 
  Calls: SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_37/75 (1073741824 (estimated locally),1.00 per call) SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_37/74 (1073741824 (estimated locally),1.00 per call) 
Adc_Sar_Ip_DisableChannel/31 (Adc_Sar_Ip_DisableChannel) @062552a0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: Adc_Sar_Ip_apxAdcBase/5 (read) 
  Referring: 
  Availability: available
  Function flags: count:1073741817 (estimated locally) body optimize_size
  Called by: 
  Calls: SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_27/73 (357913942 (estimated locally),0.33 per call) SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_27/72 (357913942 (estimated locally),0.33 per call) SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_24/71 (357913942 (estimated locally),0.33 per call) SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_24/70 (357913942 (estimated locally),0.33 per call) 
Adc_Sar_Ip_EnableChannel/30 (Adc_Sar_Ip_EnableChannel) @06255000
  Type: function definition analyzed
  Visibility: externally_visible public
  References: Adc_Sar_Ip_apxAdcBase/5 (read) 
  Referring: 
  Availability: available
  Function flags: count:1073741817 (estimated locally) body optimize_size
  Called by: 
  Calls: SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_26/69 (357913942 (estimated locally),0.33 per call) SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_26/68 (357913942 (estimated locally),0.33 per call) SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_23/67 (357913942 (estimated locally),0.33 per call) SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_23/66 (357913942 (estimated locally),0.33 per call) 
Adc_Sar_Ip_ChainConfig/29 (Adc_Sar_Ip_ChainConfig) @061fc380
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741817 (estimated locally) body optimize_size
  Called by: 
  Calls: Adc_Sar_SetInjectedChain/25 (357913942 (estimated locally),0.33 per call) Adc_Sar_SetNormalChain/24 (357913942 (estimated locally),0.33 per call) 
Adc_Sar_Ip_Deinit/28 (Adc_Sar_Ip_Deinit) @061fcee0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: Adc_Sar_Ip_apxAdcBase/5 (read) Adc_Sar_Ip_au8AdcGroupCount/7 (read) Adc_Sar_Ip_axAdcSarState/6 (write) 
  Referring: 
  Availability: available
  Function flags: count:268435456 (estimated locally) body optimize_size
  Called by: 
  Calls: Adc_Sar_Ip_Powerdown/43 (134217728 (estimated locally),0.50 per call) Adc_Sar_Ip_SetResolution/32 (134217728 (estimated locally),0.50 per call) Adc_Sar_Ip_ClearStatusFlags/35 (134217728 (estimated locally),0.50 per call) Adc_Sar_ResetWdog/19 (134217728 (estimated locally),0.50 per call) Adc_Sar_Ip_Init/27 (268435456 (estimated locally),1.00 per call) 
Adc_Sar_Ip_Init/27 (Adc_Sar_Ip_Init) @061fcc40
  Type: function definition analyzed
  Visibility: externally_visible public
  References: Adc_Sar_Ip_apxAdcBase/5 (read) Adc_Sar_Ip_axAdcSarState/6 (write) Adc_Sar_Ip_au32AdcFeatureBitmap/9 (read) Adc_Sar_Ip_axAdcSarState/6 (write) Adc_Sar_Ip_axAdcSarState/6 (write) Adc_Sar_Ip_axAdcSarState/6 (write) Adc_Sar_Ip_axAdcSarState/6 (write) Adc_Sar_Ip_axAdcSarState/6 (write) Adc_Sar_Ip_axAdcSarState/6 (write) 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: Adc_Sar_Ip_Deinit/28 (268435456 (estimated locally),1.00 per call) 
  Calls: Adc_Sar_Ip_SetPresamplingSource/51 (177167400 (estimated locally),0.16 per call) Adc_Sar_Ip_SetPresamplingSource/51 (177167400 (estimated locally),0.16 per call) Adc_Sar_Ip_SetPresamplingSource/51 (177167400 (estimated locally),0.16 per call) Adc_Sar_ConfigChannels/16 (40925669 (estimated locally),0.04 per call) Adc_Sar_Ip_SetResolution/32 (177167400 (estimated locally),0.16 per call) Adc_Sar_SetInjectedChain/25 (177167400 (estimated locally),0.16 per call) Adc_Sar_SetNormalChain/24 (177167400 (estimated locally),0.16 per call) Adc_Sar_Ip_SetSampleTimes/47 (177167400 (estimated locally),0.16 per call) Adc_Sar_EnableHighSpeed/2 (177167400 (estimated locally),0.16 per call) Adc_Sar_Ip_Powerup/42 (354334800 (estimated locally),0.33 per call) Adc_Sar_CollectMcrMasks/15 (354334800 (estimated locally),0.33 per call) Adc_Sar_Ip_Powerdown/43 (1073741824 (estimated locally),1.00 per call) Adc_Sar_Ip_AbortChain/50 (1073741824 (estimated locally),1.00 per call) 
Adc_Sar_SetInjectedChain/25 (Adc_Sar_SetInjectedChain) @061fc000
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: Adc_Sar_Ip_apxAdcBase/5 (read) Adc_Sar_Ip_au8AdcGroupCount/7 (read) 
  Referring: 
  Availability: local
  Function flags: count:118111600 (estimated locally) body local optimize_size
  Called by: Adc_Sar_Ip_Init/27 (177167400 (estimated locally),0.16 per call) Adc_Sar_Ip_ChainConfig/29 (357913942 (estimated locally),0.33 per call) 
  Calls: 
Adc_Sar_SetNormalChain/24 (Adc_Sar_SetNormalChain) @061eba80
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: Adc_Sar_Ip_apxAdcBase/5 (read) Adc_Sar_Ip_au8AdcGroupCount/7 (read) 
  Referring: 
  Availability: local
  Function flags: count:118111600 (estimated locally) body local optimize_size
  Called by: Adc_Sar_Ip_Init/27 (177167400 (estimated locally),0.16 per call) Adc_Sar_Ip_ChainConfig/29 (357913942 (estimated locally),0.33 per call) 
  Calls: 
Adc_Sar_Ip_IRQHandler/23 (Adc_Sar_Ip_IRQHandler) @061eb540
  Type: function definition analyzed
  Visibility: externally_visible public
  References: Adc_Sar_Ip_apxAdcBase/5 (read) Adc_Sar_Ip_axAdcSarState/6 (read) Adc_Sar_Ip_axAdcSarState/6 (read) Adc_Sar_Ip_axAdcSarState/6 (read) 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: Adc_CheckAndCallAllChannelNotification/21 (1073741824 (estimated locally),1.00 per call) Adc_Sar_CheckAndCallNotification/20 (177167400 (estimated locally),0.16 per call) Adc_Sar_CheckAndCallNotification/20 (177167400 (estimated locally),0.16 per call) Adc_Sar_CheckAndCallNotification/20 (177167400 (estimated locally),0.16 per call) 
Adc_Sar_ConfigExternalTrigger/22 (Adc_Sar_ConfigExternalTrigger) @061ebee0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: Adc_Sar_Ip_apxAdcBase/5 (read) 
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) body local optimize_size
  Called by: Adc_Sar_Ip_SetExternalTrigger/64 (214748365 (estimated locally),0.20 per call) Adc_Sar_Ip_SetExternalTrigger/64 (214748365 (estimated locally),0.20 per call) Adc_Sar_Ip_SetExternalTrigger/64 (214748365 (estimated locally),0.20 per call) Adc_Sar_Ip_SetExternalTrigger/64 (214748365 (estimated locally),0.20 per call) 
  Calls: SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_21/138 (1073741824 (estimated locally),1.00 per call) SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_21/137 (1073741824 (estimated locally),1.00 per call) 
Adc_CheckAndCallAllChannelNotification/21 (Adc_CheckAndCallAllChannelNotification) @061ebc40
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: Adc_Sar_Ip_apxAdcBase/5 (read) Adc_Sar_Ip_au8AdcGroupCount/7 (read) 
  Referring: 
  Availability: local
  Function flags: count:118111600 (estimated locally) body local optimize_size
  Called by: Adc_Sar_Ip_IRQHandler/23 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
Adc_Sar_CheckAndCallNotification/20 (Adc_Sar_CheckAndCallNotification) @061eb9a0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: Adc_Sar_Ip_axAdcSarState/6 (read) 
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) body local optimize_size
  Called by: Adc_Sar_Ip_IRQHandler/23 (177167400 (estimated locally),0.16 per call) Adc_Sar_Ip_IRQHandler/23 (177167400 (estimated locally),0.16 per call) Adc_Sar_Ip_IRQHandler/23 (177167400 (estimated locally),0.16 per call) 
  Calls: 
   Indirect call(375809640 (estimated locally),0.35 per call)  of param:1 (vptr maybe changed) Num speculative call targets: 0
Adc_Sar_ResetWdog/19 (Adc_Sar_ResetWdog) @061eb700
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: Adc_Sar_Ip_apxAdcBase/5 (read) Adc_Sar_Ip_au8AdcGroupCount/7 (read) Adc_Sar_Ip_au32AdcChanBitmap/8 (read) 
  Referring: 
  Availability: local
  Function flags: count:118111600 (estimated locally) body local optimize_size
  Called by: Adc_Sar_Ip_Deinit/28 (134217728 (estimated locally),0.50 per call) 
  Calls: 
Adc_Sar_GetConvResults/18 (Adc_Sar_GetConvResults) @061eb460
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: Adc_Sar_Ip_apxAdcBase/5 (read) *.LC0/87 (read) Adc_Sar_Ip_au32AdcChanBitmap/8 (read) Adc_Sar_Ip_au8AdcGroupCount/7 (read) 
  Referring: 
  Availability: local
  Function flags: count:8124303 (estimated locally) body local optimize_size
  Called by: Adc_Sar_Ip_GetConvResultsToArray/38 (1073741824 (estimated locally),1.00 per call) Adc_Sar_Ip_GetConvDataToArray/37 (1073741824 (estimated locally),1.00 per call) 
  Calls: Adc_Sar_GetMaskedResult/11 (123593488 (estimated locally),15.21 per call) Adc_Sar_GetMaskedResult/11 (123593488 (estimated locally),15.21 per call) 
Adc_Sar_CheckSelfTestProgress/17 (Adc_Sar_CheckSelfTestProgress) @061dde00
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: Adc_Sar_Ip_apxAdcBase/5 (read) 
  Referring: 
  Availability: local
  Function flags: count:62173924 (estimated locally) body local optimize_size
  Called by: Adc_Sar_Ip_SelfTest/36 (229727060 (estimated locally),1.00 per call) 
  Calls: OsIf_GetElapsed/86 (129448572 (estimated locally),2.08 per call) OsIf_GetElapsed/86 (958878294 (estimated locally),15.42 per call) OsIf_GetCounter/79 (62173924 (estimated locally),1.00 per call) OsIf_MicrosToTicks/78 (62173924 (estimated locally),1.00 per call) 
Adc_Sar_ConfigChannels/16 (Adc_Sar_ConfigChannels) @061dd0e0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: Adc_Sar_Ip_apxAdcBase/5 (read) Adc_Sar_Ip_au8AdcGroupCount/7 (read) 
  Referring: 
  Availability: local
  Function flags: count:118111600 (estimated locally) body local optimize_size
  Called by: Adc_Sar_Ip_Init/27 (40925669 (estimated locally),0.04 per call) 
  Calls: 
Adc_Sar_CollectMcrMasks/15 (Adc_Sar_CollectMcrMasks) @061ddd20
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: Adc_Sar_Ip_au32AdcFeatureBitmap/9 (read) 
  Referring: 
  Availability: local
  Function flags: count:1073741811 (estimated locally) body local optimize_size
  Called by: Adc_Sar_Ip_Init/27 (354334800 (estimated locally),0.33 per call) 
  Calls: 
Adc_Sar_GetIsrFlags/13 (Adc_Sar_GetIsrFlags) @061dd000
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: Adc_Sar_Ip_apxAdcBase/5 (read) Adc_Sar_Ip_au32AdcFeatureBitmap/9 (read) 
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) body local optimize_size
  Called by: Adc_Sar_Ip_GetStatusFlags/34 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
Adc_Sar_GetMsrFlags/12 (Adc_Sar_GetMsrFlags) @061d37e0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: Adc_Sar_Ip_apxAdcBase/5 (read) Adc_Sar_Ip_au32AdcFeatureBitmap/9 (read) 
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) body local optimize_size
  Called by: Adc_Sar_Ip_GetStatusFlags/34 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
Adc_Sar_GetMaskedResult/11 (Adc_Sar_GetMaskedResult) @061d3c40
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: Adc_Sar_Ip_axAdcSarState/6 (read) Adc_Sar_Ip_axAdcSarState/6 (read) 
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) body local optimize_size
  Called by: Adc_Sar_Ip_GetConvResult/40 (354334800 (estimated locally),0.33 per call) Adc_Sar_Ip_GetConvData/39 (354334800 (estimated locally),0.33 per call) Adc_Sar_GetConvResults/18 (123593488 (estimated locally),15.21 per call) Adc_Sar_GetConvResults/18 (123593488 (estimated locally),15.21 per call) 
  Calls: Adc_Sar_GetResolution/10 (354334800 (estimated locally),0.33 per call) 
Adc_Sar_GetResolution/10 (Adc_Sar_GetResolution) @061d39a0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: Adc_Sar_Ip_apxAdcBase/5 (read) ResolutionArray.0/88 (read) 
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) body local optimize_size
  Called by: Adc_Sar_GetMaskedResult/11 (354334800 (estimated locally),0.33 per call) 
  Calls: 
Adc_Sar_Ip_au32AdcFeatureBitmap/9 (Adc_Sar_Ip_au32AdcFeatureBitmap) @0615c240
  Type: variable definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: Adc_Sar_Ip_DisableNotifications/45 (read) Adc_Sar_GetMsrFlags/12 (read) Adc_Sar_Ip_EnablePresampleConversion/54 (read) Adc_Sar_Ip_DisablePresampleConversion/55 (read) Adc_Sar_GetIsrFlags/13 (read) Adc_Sar_CollectMcrMasks/15 (read) Adc_Sar_Ip_ClearStatusFlags/35 (read) Adc_Sar_Ip_EnableNotifications/44 (read) Adc_Sar_Ip_SetPresamplingSource/51 (read) Adc_Sar_Ip_Init/27 (read) Adc_Sar_Ip_EnableChannelPresampling/52 (read) Adc_Sar_Ip_DisableChannelPresampling/53 (read) Adc_Sar_Ip_SetCtuMode/63 (read) 
  Availability: available
  Varpool flags: initialized read-only const-value-known
Adc_Sar_Ip_au32AdcChanBitmap/8 (Adc_Sar_Ip_au32AdcChanBitmap) @0615c1f8
  Type: variable definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: Adc_Sar_ResetWdog/19 (read) Adc_Sar_GetConvResults/18 (read) Adc_Sar_Ip_DisableChannelDmaAll/60 (read) 
  Availability: available
  Varpool flags: initialized read-only const-value-known
Adc_Sar_Ip_au8AdcGroupCount/7 (Adc_Sar_Ip_au8AdcGroupCount) @0615c1b0
  Type: variable definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: Adc_Sar_GetConvResults/18 (read) Adc_Sar_ResetWdog/19 (read) Adc_CheckAndCallAllChannelNotification/21 (read) Adc_Sar_SetInjectedChain/25 (read) Adc_Sar_SetNormalChain/24 (read) Adc_Sar_Ip_SetSampleTimes/47 (read) Adc_Sar_ConfigChannels/16 (read) Adc_Sar_Ip_Deinit/28 (read) Adc_Sar_Ip_DisableChannelDmaAll/60 (read) 
  Availability: available
  Varpool flags: initialized read-only const-value-known
Adc_Sar_Ip_axAdcSarState/6 (Adc_Sar_Ip_axAdcSarState) @0615c120
  Type: variable definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: Adc_Sar_CheckAndCallNotification/20 (read) Adc_Sar_Ip_IRQHandler/23 (read) Adc_Sar_GetMaskedResult/11 (read) Adc_Sar_Ip_Init/27 (write) Adc_Sar_Ip_IRQHandler/23 (read) Adc_Sar_GetMaskedResult/11 (read) Adc_Sar_Ip_IRQHandler/23 (read) Adc_Sar_Ip_DoCalibration/41 (read) Adc_Sar_Ip_Init/27 (write) Adc_Sar_Ip_Init/27 (write) Adc_Sar_Ip_Init/27 (write) Adc_Sar_Ip_Init/27 (write) Adc_Sar_Ip_Init/27 (write) Adc_Sar_Ip_Init/27 (write) Adc_Sar_Ip_Deinit/28 (write) 
  Availability: available
  Varpool flags:
Adc_Sar_Ip_apxAdcBase/5 (Adc_Sar_Ip_apxAdcBase) @0615c048
  Type: variable definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: Adc_Sar_CheckSelfTestProgress/17 (read) Adc_Sar_GetConvResults/18 (read) Adc_Sar_Ip_AbortChain/50 (read) Adc_Sar_ResetWdog/19 (read) Adc_CheckAndCallAllChannelNotification/21 (read) Adc_Sar_SetNormalChain/24 (read) Adc_Sar_Ip_SetPresamplingSource.part.0/147 (read) Adc_Sar_GetIsrFlags/13 (read) Adc_Sar_ConfigExternalTrigger/22 (read) Adc_Sar_Ip_IRQHandler/23 (read) Adc_Sar_Ip_EnableChannel/30 (read) Adc_Sar_Ip_DisableChannel/31 (read) Adc_Sar_Ip_SetCtuMode/63 (read) Adc_Sar_GetResolution/10 (read) Adc_Sar_Ip_SetResolution/32 (read) Adc_Sar_Ip_StartConversion/33 (read) Adc_Sar_SetInjectedChain/25 (read) Adc_Sar_GetMsrFlags/12 (read) Adc_Sar_Ip_SetConversionMode/62 (read) Adc_Sar_Ip_ClearStatusFlags/35 (read) Adc_Sar_Ip_SelfTest/36 (read) Adc_Sar_Ip_Powerup/42 (read) Adc_Sar_Ip_GetConvData/39 (read) Adc_Sar_Ip_GetConvResult/40 (read) Adc_Sar_Ip_Powerdown/43 (read) Adc_Sar_Ip_DoCalibration/41 (read) Adc_Sar_Ip_SetSampleTimes/47 (read) Adc_Sar_Ip_EnableNotifications/44 (read) Adc_Sar_Ip_DisableNotifications/45 (read) Adc_Sar_Ip_SetAveraging/48 (read) Adc_Sar_Ip_SetClockMode/46 (read) Adc_Sar_Ip_AbortConversion/49 (read) Adc_Sar_Ip_Init/27 (read) Adc_Sar_Ip_Deinit/28 (read) Adc_Sar_Ip_EnableChannelPresampling/52 (read) Adc_Sar_Ip_DisableChannelPresampling/53 (read) Adc_Sar_Ip_EnablePresampleConversion/54 (read) Adc_Sar_Ip_DisablePresampleConversion/55 (read) Adc_Sar_Ip_EnableDma/56 (read) Adc_Sar_Ip_DisableDma/57 (read) Adc_Sar_Ip_EnableChannelDma/58 (read) Adc_Sar_Ip_DisableChannelDma/59 (read) Adc_Sar_Ip_DisableChannelDmaAll/60 (read) Adc_Sar_Ip_SetDmaClearSource/61 (read) Adc_Sar_ConfigChannels/16 (read) Adc_Sar_Ip_GetDataAddress/65 (read) 
  Availability: available
  Varpool flags: initialized read-only const-value-known
Adc_Sar_EnableHighSpeed/2 (Adc_Sar_EnableHighSpeed) @0602db60
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) body local optimize_size
  Called by: Adc_Sar_Ip_Init/27 (177167400 (estimated locally),0.16 per call) Adc_Sar_Ip_SetClockMode/46 (116930483 (estimated locally),0.11 per call) 
  Calls: 

;; Function Adc_Sar_GetMaskedResult (Adc_Sar_GetMaskedResult, funcdef_no=6, decl_uid=6375, cgraph_uid=7, symbol_order=11)

Modification phase of node Adc_Sar_GetMaskedResult/11
Adc_Sar_GetMaskedResult (const uint32 Instance, const uint32 Cdr)
{
  uint8 Resolution;
  uint16 Result;
  uint32 CdrMask;
  _Bool _1;
  <unnamed type> _2;
  unsigned int _3;
  unsigned int _4;
  short unsigned int _5;
  short unsigned int _6;
  unsigned int _7;
  unsigned int _8;
  long unsigned int _9;
  short unsigned int _10;
  short unsigned int _11;
  short unsigned int _12;
  int _13;
  int _14;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG CdrMask => 65535
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = Adc_Sar_Ip_axAdcSarState[Instance_19(D)].BypassResolution;
  if (_1 != 0)
    goto <bb 4>; [67.00%]
  else
    goto <bb 3>; [33.00%]

  <bb 3> [local count: 354334800]:
  # DEBUG BEGIN_STMT
  Resolution_21 = Adc_Sar_GetResolution (Instance_19(D));
  # DEBUG Resolution => Resolution_21

  <bb 4> [local count: 1073741824]:
  # Resolution_16 = PHI <Resolution_21(3), 15(2)>
  # DEBUG Resolution => Resolution_16
  # DEBUG BEGIN_STMT
  _2 = Adc_Sar_Ip_axAdcSarState[Instance_19(D)].DataAlign;
  if (_2 == 1)
    goto <bb 5>; [34.00%]
  else
    goto <bb 6>; [66.00%]

  <bb 5> [local count: 365072224]:
  # DEBUG BEGIN_STMT
  _3 = (unsigned int) Resolution_16;
  _4 = 16 - _3;
  CdrMask_25 = 65535 << _4;
  # DEBUG CdrMask => CdrMask_25
  # DEBUG BEGIN_STMT
  _5 = (short unsigned int) Cdr_23(D);
  _6 = (short unsigned int) CdrMask_25;
  Result_26 = _5 & _6;
  # DEBUG Result => Result_26
  goto <bb 7>; [100.00%]

  <bb 6> [local count: 708669601]:
  # DEBUG BEGIN_STMT
  _7 = (unsigned int) Resolution_16;
  _8 = 15 - _7;
  _9 = 65535 << _8;
  CdrMask_22 = _9 & 32767;
  # DEBUG CdrMask => CdrMask_22
  # DEBUG BEGIN_STMT
  _10 = (short unsigned int) Cdr_23(D);
  _11 = (short unsigned int) CdrMask_22;
  _12 = _10 & _11;
  _13 = (int) _12;
  _14 = _13 >> _8;
  Result_24 = (uint16) _14;
  # DEBUG Result => Result_24

  <bb 7> [local count: 1073741824]:
  # Result_15 = PHI <Result_26(5), Result_24(6)>
  # DEBUG Result => Result_15
  # DEBUG BEGIN_STMT
  return Result_15;

}



;; Function Adc_Sar_GetConvResults (Adc_Sar_GetConvResults, funcdef_no=13, decl_uid=6397, cgraph_uid=14, symbol_order=18)

Modification phase of node Adc_Sar_GetConvResults/18
Adc_Sar_GetConvResults (const uint32 Instance, const Adc_Sar_Ip_ConvChainType ChainType, uint16 * const ResultsRaw, struct Adc_Sar_Ip_ChanResultType * const ResultsStruct, const uint32 Length)
{
  const uint16 AdcChanCount[3][3];
  uint32 Cdr;
  uint8 ChnIdx;
  uint32 VectBit;
  uint32 VectAdr;
  struct ADC_Type * const AdcBasePtr;
  boolean LengthExceeded;
  uint32 Index;
  unsigned char _1;
  unsigned char _2;
  unsigned char _3;
  unsigned char _4;
  unsigned int _5;
  long unsigned int _6;
  unsigned int _7;
  unsigned int _8;
  long unsigned int _9;
  long unsigned int _10;
  const uint32_t * _11;
  unsigned int _12;
  const uint32_t * _13;
  long unsigned int _14;
  long unsigned int _15;
  long unsigned int _16;
  long unsigned int _17;
  long unsigned int _18;
  uint16 * _19;
  short unsigned int _20;
  long unsigned int _21;
  struct Adc_Sar_Ip_ChanResultType * _22;
  short unsigned int _23;
  long unsigned int _24;
  _Bool _25;
  long unsigned int _26;
  _Bool _27;
  volatile uint32_t * _28;
  long unsigned int _29;
  volatile uint32_t * _30;
  long unsigned int _31;
  short unsigned int _32;
  long unsigned int _33;
  unsigned char _34;
  long unsigned int _35;
  unsigned char _52;

  <bb 2> [local count: 8124303]:
  # DEBUG BEGIN_STMT
  # DEBUG Index => 0
  # DEBUG BEGIN_STMT
  # DEBUG LengthExceeded => 0
  # DEBUG BEGIN_STMT
  AdcBasePtr_55 = Adc_Sar_Ip_apxAdcBase[Instance_54(D)];
  # DEBUG AdcBasePtr => AdcBasePtr_55
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  AdcChanCount = *.LC0;
  # DEBUG BEGIN_STMT
  # DEBUG VectAdr => 0
  goto <bb 15>; [100.00%]

  <bb 3> [local count: 1014686025]:
  # DEBUG BEGIN_STMT
  _1 = (unsigned char) VectAdr_43;
  _2 = _1 * 32;
  _3 = (unsigned char) VectBit_44;
  ChnIdx_57 = _2 + _3;
  # DEBUG ChnIdx => ChnIdx_57
  # DEBUG BEGIN_STMT
  _4 = ChnIdx_57 >> 5;
  _5 = (unsigned int) _4;
  _6 = Adc_Sar_Ip_au32AdcChanBitmap[Instance_54(D)][_5];
  _7 = (unsigned int) ChnIdx_57;
  _52 = ChnIdx_57 & 31;
  _8 = (unsigned int) _52;
  _9 = _6 >> _8;
  _10 = _9 & 1;
  if (_10 == 0)
    goto <bb 4>; [33.00%]
  else
    goto <bb 5>; [67.00%]

  <bb 4> [local count: 334846386]:
  # DEBUG BEGIN_STMT
  // predicted unlikely by continue predictor.
  goto <bb 11>; [100.00%]

  <bb 5> [local count: 679839639]:
  # DEBUG BEGIN_STMT
  _11 = &AdcBasePtr_55->PCDR[0];
  _12 = _7 * 4;
  _13 = _11 + _12;
  Cdr_58 ={v} MEM[(const uint32 *)_13];
  # DEBUG Cdr => Cdr_58
  # DEBUG BEGIN_STMT
  _14 = ChainType_59(D) << 16;
  _15 = _14 & 196608;
  _16 = _15 | 524288;
  _17 = Cdr_58 & 720896;
  if (_16 == _17)
    goto <bb 6>; [34.00%]
  else
    goto <bb 11>; [66.00%]

  <bb 6> [local count: 231145479]:
  # DEBUG BEGIN_STMT
  if (ResultsRaw_60(D) != 0B)
    goto <bb 7>; [53.47%]
  else
    goto <bb 8>; [46.53%]

  <bb 7> [local count: 123593488]:
  # DEBUG BEGIN_STMT
  _18 = Index_37 * 2;
  _19 = ResultsRaw_60(D) + _18;
  _20 = Adc_Sar_GetMaskedResult (Instance_54(D), Cdr_58);
  *_19 = _20;

  <bb 8> [local count: 231145479]:
  # DEBUG BEGIN_STMT
  if (ResultsStruct_63(D) != 0B)
    goto <bb 9>; [53.47%]
  else
    goto <bb 10>; [46.53%]

  <bb 9> [local count: 123593488]:
  # DEBUG BEGIN_STMT
  _21 = Index_37 * 6;
  _22 = ResultsStruct_63(D) + _21;
  _23 = Adc_Sar_GetMaskedResult (Instance_54(D), Cdr_58);
  _22->ConvData = _23;
  # DEBUG BEGIN_STMT
  _22->AdcChnIdx = ChnIdx_57;
  # DEBUG BEGIN_STMT
  _24 = Cdr_58 >> 19;
  _25 = (_Bool) _24;
  _22->ValidFlag = _25;
  # DEBUG BEGIN_STMT
  _26 = Cdr_58 >> 18;
  _27 = (_Bool) _26;
  _22->OverWrittenFlag = _27;

  <bb 10> [local count: 231145479]:
  # DEBUG BEGIN_STMT
  _28 = &AdcBasePtr_55->CEOCFR0;
  _29 = VectAdr_43 * 4;
  _30 = _28 + _29;
  _31 = 1 << VectBit_44;
  MEM[(volatile uint32 *)_30] ={v} _31;
  # DEBUG BEGIN_STMT
  Index_70 = Index_37 + 1;
  # DEBUG Index => Index_70
  # DEBUG BEGIN_STMT
  if (Index_70 >= Length_71(D))
    goto <bb 13>; [5.50%]
  else
    goto <bb 11>; [94.50%]

  <bb 11> [local count: 1001973024]:
  # Index_36 = PHI <Index_37(4), Index_37(5), Index_70(10)>
  # DEBUG Index => Index_36
  # DEBUG BEGIN_STMT
  VectBit_72 = VectBit_44 + 1;
  # DEBUG VectBit => VectBit_72

  <bb 12> [local count: 1073741824]:
  # Index_37 = PHI <Index_36(11), Index_39(17)>
  # VectBit_44 = PHI <VectBit_72(11), 0(17)>
  # DEBUG VectBit => VectBit_44
  # DEBUG Index => Index_37
  # DEBUG BEGIN_STMT
  _32 = AdcChanCount[Instance_54(D)][VectAdr_43];
  _33 = (long unsigned int) _32;
  if (_33 > VectBit_44)
    goto <bb 3>; [94.50%]
  else
    goto <bb 13>; [5.50%]

  <bb 13> [local count: 71768801]:
  # Index_38 = PHI <Index_70(10), Index_37(12)>
  # LengthExceeded_41 = PHI <1(10), LengthExceeded_42(12)>
  # DEBUG LengthExceeded => LengthExceeded_41
  # DEBUG Index => Index_38
  # DEBUG BEGIN_STMT
  if (LengthExceeded_41 != 0)
    goto <bb 16>; [5.50%]
  else
    goto <bb 14>; [94.50%]

  <bb 14> [local count: 67821517]:
  # DEBUG BEGIN_STMT
  VectAdr_73 = VectAdr_43 + 1;
  # DEBUG VectAdr => VectAdr_73

  <bb 15> [local count: 75945820]:
  # Index_39 = PHI <0(2), Index_38(14)>
  # LengthExceeded_42 = PHI <0(2), 0(14)>
  # VectAdr_43 = PHI <0(2), VectAdr_73(14)>
  # DEBUG VectAdr => VectAdr_43
  # DEBUG LengthExceeded => LengthExceeded_42
  # DEBUG Index => Index_39
  # DEBUG BEGIN_STMT
  _34 = Adc_Sar_Ip_au8AdcGroupCount[Instance_54(D)];
  _35 = (long unsigned int) _34;
  if (_35 > VectAdr_43)
    goto <bb 17>; [94.50%]
  else
    goto <bb 16>; [5.50%]

  <bb 17> [local count: 71768800]:
  goto <bb 12>; [100.00%]

  <bb 16> [local count: 8124304]:
  # Index_40 = PHI <Index_38(13), Index_39(15)>
  # DEBUG Index => Index_40
  # DEBUG BEGIN_STMT
  AdcChanCount ={v} {CLOBBER};
  return Index_40;

}



;; Function Adc_Sar_CheckAndCallNotification (Adc_Sar_CheckAndCallNotification, funcdef_no=15, decl_uid=6403, cgraph_uid=16, symbol_order=20)

Modification phase of node Adc_Sar_CheckAndCallNotification/20
Adc_Sar_CheckAndCallNotification (const uint32 Instance, void (*<T532>) (void) Callback)
{
  _Bool _1;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  if (Callback_3(D) != 0B)
    goto <bb 3>; [70.00%]
  else
    goto <bb 5>; [30.00%]

  <bb 3> [local count: 751619281]:
  _1 = Adc_Sar_Ip_axAdcSarState[Instance_5(D)].InitStatus;
  if (_1 != 0)
    goto <bb 4>; [50.00%]
  else
    goto <bb 5>; [50.00%]

  <bb 4> [local count: 375809640]:
  # DEBUG BEGIN_STMT
  Callback_3(D) ();

  <bb 5> [local count: 1073741824]:
  return;

}



;; Function Adc_Sar_SetNormalChain (Adc_Sar_SetNormalChain, funcdef_no=19, decl_uid=6414, cgraph_uid=20, symbol_order=24)

Modification phase of node Adc_Sar_SetNormalChain/24
Adc_Sar_SetNormalChain (const uint32 Instance, const uint32 * const Mask)
{
  uint8 Index;
  struct ADC_Type * const AdcBasePtr;
  unsigned int _1;
  unsigned int _2;
  const uint32 * _3;
  volatile uint32_t * _4;
  volatile uint32_t * _5;
  long unsigned int _6;
  unsigned char _7;

  <bb 2> [local count: 118111600]:
  # DEBUG BEGIN_STMT
  AdcBasePtr_12 = Adc_Sar_Ip_apxAdcBase[Instance_11(D)];
  # DEBUG AdcBasePtr => AdcBasePtr_12
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG Index => 0
  goto <bb 4>; [100.00%]

  <bb 3> [local count: 955630225]:
  # DEBUG BEGIN_STMT
  _1 = (unsigned int) Index_8;
  _2 = _1 * 4;
  _3 = Mask_13(D) + _2;
  _4 = &AdcBasePtr_12->NCMR0;
  _5 = _4 + _2;
  _6 = *_3;
  MEM[(volatile uint32 *)_5] ={v} _6;
  # DEBUG BEGIN_STMT
  Index_15 = Index_8 + 1;
  # DEBUG Index => Index_15

  <bb 4> [local count: 1073741824]:
  # Index_8 = PHI <0(2), Index_15(3)>
  # DEBUG Index => Index_8
  # DEBUG BEGIN_STMT
  _7 = Adc_Sar_Ip_au8AdcGroupCount[Instance_11(D)];
  if (_7 > Index_8)
    goto <bb 3>; [89.00%]
  else
    goto <bb 5>; [11.00%]

  <bb 5> [local count: 118111600]:
  return;

}



;; Function Adc_Sar_SetInjectedChain (Adc_Sar_SetInjectedChain, funcdef_no=20, decl_uid=6417, cgraph_uid=21, symbol_order=25)

Modification phase of node Adc_Sar_SetInjectedChain/25
Adc_Sar_SetInjectedChain (const uint32 Instance, const uint32 * const Mask)
{
  uint8 Index;
  struct ADC_Type * const AdcBasePtr;
  unsigned int _1;
  unsigned int _2;
  const uint32 * _3;
  volatile uint32_t * _4;
  volatile uint32_t * _5;
  long unsigned int _6;
  unsigned char _7;

  <bb 2> [local count: 118111600]:
  # DEBUG BEGIN_STMT
  AdcBasePtr_12 = Adc_Sar_Ip_apxAdcBase[Instance_11(D)];
  # DEBUG AdcBasePtr => AdcBasePtr_12
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG Index => 0
  goto <bb 4>; [100.00%]

  <bb 3> [local count: 955630225]:
  # DEBUG BEGIN_STMT
  _1 = (unsigned int) Index_8;
  _2 = _1 * 4;
  _3 = Mask_13(D) + _2;
  _4 = &AdcBasePtr_12->JCMR0;
  _5 = _4 + _2;
  _6 = *_3;
  MEM[(volatile uint32 *)_5] ={v} _6;
  # DEBUG BEGIN_STMT
  Index_15 = Index_8 + 1;
  # DEBUG Index => Index_15

  <bb 4> [local count: 1073741824]:
  # Index_8 = PHI <0(2), Index_15(3)>
  # DEBUG Index => Index_8
  # DEBUG BEGIN_STMT
  _7 = Adc_Sar_Ip_au8AdcGroupCount[Instance_11(D)];
  if (_7 > Index_8)
    goto <bb 3>; [89.00%]
  else
    goto <bb 5>; [11.00%]

  <bb 5> [local count: 118111600]:
  return;

}



;; Function Adc_Sar_ConfigExternalTrigger (Adc_Sar_ConfigExternalTrigger, funcdef_no=17, decl_uid=6411, cgraph_uid=18, symbol_order=22)

Modification phase of node Adc_Sar_ConfigExternalTrigger/22
Adjusting mask for param 2 to 0x4200000
Adjusting mask for param 3 to 0x4200000
Adjusting mask for param 4 to 0xa400000
Setting value range of param 2 (now 2) [2097152, 67108864]
Setting value range of param 3 (now 3) [0, 67108864]
Setting value range of param 4 (now 4) [4194304, 167772160]
Adc_Sar_ConfigExternalTrigger (const uint32 Instance, const Adc_Sar_Ip_ExtTriggerEdgeType TriggerEdge, const uint32 TrgEdgeSetMask, const uint32 TrgEdgeClrMask, const uint32 TrigSrcMask)
{
  struct ADC_Type * const AdcBasePtr;
  long unsigned int _1;
  long unsigned int _2;
  long unsigned int _3;
  long unsigned int _4;
  long unsigned int _5;
  long unsigned int _6;
  long unsigned int _7;
  long unsigned int _8;
  long unsigned int _9;
  long unsigned int _10;
  long unsigned int _11;
  long unsigned int _12;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  AdcBasePtr_16 = Adc_Sar_Ip_apxAdcBase[Instance_15(D)];
  # DEBUG AdcBasePtr => AdcBasePtr_16
  # DEBUG BEGIN_STMT
  SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_21 ();
  # DEBUG BEGIN_STMT
  switch (TriggerEdge_18(D)) <default: <L5> [25.00%], case 0: <L2> [25.00%], case 1: <L0> [25.00%], case 2: <L1> [25.00%]>

  <bb 3> [local count: 268435456]:
<L0>:
  # DEBUG BEGIN_STMT
  _1 ={v} AdcBasePtr_16->MCR;
  _2 = ~TrgEdgeSetMask_19(D);
  _3 = _1 & _2;
  AdcBasePtr_16->MCR ={v} _3;
  # DEBUG BEGIN_STMT
  _4 ={v} AdcBasePtr_16->MCR;
  _5 = _4 | TrigSrcMask_20(D);
  AdcBasePtr_16->MCR ={v} _5;
  # DEBUG BEGIN_STMT
  goto <bb 6>; [100.00%]

  <bb 4> [local count: 268435456]:
<L1>:
  # DEBUG BEGIN_STMT
  _6 ={v} AdcBasePtr_16->MCR;
  _7 = TrgEdgeSetMask_19(D) | TrigSrcMask_20(D);
  _8 = _6 | _7;
  AdcBasePtr_16->MCR ={v} _8;
  # DEBUG BEGIN_STMT
  goto <bb 6>; [100.00%]

  <bb 5> [local count: 268435456]:
<L2>:
  # DEBUG BEGIN_STMT
  _9 ={v} AdcBasePtr_16->MCR;
  _10 = TrigSrcMask_20(D) | TrgEdgeClrMask_24(D);
  _11 = ~_10;
  _12 = _9 & _11;
  AdcBasePtr_16->MCR ={v} _12;
  # DEBUG BEGIN_STMT

  <bb 6> [local count: 1073741824]:
<L5>:
  # DEBUG BEGIN_STMT
  SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_21 ();
  return;

}



;; Function Adc_Sar_Ip_IRQHandler (Adc_Sar_Ip_IRQHandler, funcdef_no=18, decl_uid=6067, cgraph_uid=19, symbol_order=23)

Modification phase of node Adc_Sar_Ip_IRQHandler/23
Adc_Sar_Ip_IRQHandler (const uint32 Instance)
{
  struct ADC_Type * const AdcBasePtr;
  long unsigned int _1;
  long unsigned int _2;
  long unsigned int _3;
  long unsigned int _4;
  void (*<T532>) (void) _5;
  long unsigned int _6;
  long unsigned int _7;
  long unsigned int _8;
  long unsigned int _9;
  void (*<T532>) (void) _10;
  long unsigned int _11;
  long unsigned int _12;
  long unsigned int _13;
  long unsigned int _14;
  void (*<T532>) (void) _15;
  long unsigned int _16;
  long unsigned int _17;
  long unsigned int _18;
  long unsigned int _19;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  AdcBasePtr_27 = Adc_Sar_Ip_apxAdcBase[Instance_26(D)];
  # DEBUG AdcBasePtr => AdcBasePtr_27
  # DEBUG BEGIN_STMT
  _1 ={v} AdcBasePtr_27->ISR;
  _2 = _1 & 16;
  if (_2 != 0)
    goto <bb 3>; [50.00%]
  else
    goto <bb 5>; [50.00%]

  <bb 3> [local count: 536870913]:
  # DEBUG BEGIN_STMT
  AdcBasePtr_27->ISR ={v} 16;
  # DEBUG BEGIN_STMT
  _3 ={v} AdcBasePtr_27->IMR;
  _4 = _3 & 16;
  if (_4 != 0)
    goto <bb 4>; [33.00%]
  else
    goto <bb 5>; [67.00%]

  <bb 4> [local count: 177167400]:
  # DEBUG BEGIN_STMT
  _5 = Adc_Sar_Ip_axAdcSarState[Instance_26(D)].EndOfCtuConversionNotification;
  Adc_Sar_CheckAndCallNotification (Instance_26(D), _5);

  <bb 5> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  _6 ={v} AdcBasePtr_27->ISR;
  _7 = _6 & 1;
  if (_7 != 0)
    goto <bb 6>; [50.00%]
  else
    goto <bb 8>; [50.00%]

  <bb 6> [local count: 536870913]:
  # DEBUG BEGIN_STMT
  AdcBasePtr_27->ISR ={v} 1;
  # DEBUG BEGIN_STMT
  _8 ={v} AdcBasePtr_27->IMR;
  _9 = _8 & 1;
  if (_9 != 0)
    goto <bb 7>; [33.00%]
  else
    goto <bb 8>; [67.00%]

  <bb 7> [local count: 177167400]:
  # DEBUG BEGIN_STMT
  _10 = Adc_Sar_Ip_axAdcSarState[Instance_26(D)].EndOfNormalChainNotification;
  Adc_Sar_CheckAndCallNotification (Instance_26(D), _10);

  <bb 8> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  _11 ={v} AdcBasePtr_27->ISR;
  _12 = _11 & 4;
  if (_12 != 0)
    goto <bb 9>; [50.00%]
  else
    goto <bb 11>; [50.00%]

  <bb 9> [local count: 536870913]:
  # DEBUG BEGIN_STMT
  AdcBasePtr_27->ISR ={v} 4;
  # DEBUG BEGIN_STMT
  _13 ={v} AdcBasePtr_27->IMR;
  _14 = _13 & 4;
  if (_14 != 0)
    goto <bb 10>; [33.00%]
  else
    goto <bb 11>; [67.00%]

  <bb 10> [local count: 177167400]:
  # DEBUG BEGIN_STMT
  _15 = Adc_Sar_Ip_axAdcSarState[Instance_26(D)].EndOfInjectedChainNotification;
  Adc_Sar_CheckAndCallNotification (Instance_26(D), _15);

  <bb 11> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  _16 ={v} AdcBasePtr_27->ISR;
  _17 = _16 & 2;
  if (_17 != 0)
    goto <bb 12>; [50.00%]
  else
    goto <bb 13>; [50.00%]

  <bb 12> [local count: 536870913]:
  # DEBUG BEGIN_STMT
  AdcBasePtr_27->ISR ={v} 2;

  <bb 13> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  _18 ={v} AdcBasePtr_27->ISR;
  _19 = _18 & 8;
  if (_19 != 0)
    goto <bb 14>; [50.00%]
  else
    goto <bb 15>; [50.00%]

  <bb 14> [local count: 536870913]:
  # DEBUG BEGIN_STMT
  AdcBasePtr_27->ISR ={v} 8;

  <bb 15> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  Adc_CheckAndCallAllChannelNotification (Instance_26(D));
  # DEBUG BEGIN_STMT
  AdcBasePtr_27->WTISR ={v} 4294967295;
  return;

}



;; Function Adc_Sar_Ip_ChainConfig (Adc_Sar_Ip_ChainConfig, funcdef_no=24, decl_uid=5953, cgraph_uid=25, symbol_order=29)

Modification phase of node Adc_Sar_Ip_ChainConfig/29
Adc_Sar_Ip_ChainConfig (const uint32 u32Instance, const struct Adc_Sar_Ip_ChansIdxMaskType * const pChansIdxMask, const Adc_Sar_Ip_ConvChainType pChainType)
{
  const uint32[3] * _1;
  const uint32[3] * _2;

  <bb 2> [local count: 1073741817]:
  # DEBUG BEGIN_STMT
  switch (pChainType_4(D)) <default: <L4> [33.33%], case 0: <L0> [33.33%], case 1: <L1> [33.33%]>

  <bb 3> [local count: 357913942]:
<L0>:
  # DEBUG BEGIN_STMT
  _1 = &pChansIdxMask_6(D)->ChanMaskArr;
  Adc_Sar_SetNormalChain (u32Instance_7(D), _1);
  # DEBUG BEGIN_STMT
  goto <bb 5>; [100.00%]

  <bb 4> [local count: 357913942]:
<L1>:
  # DEBUG BEGIN_STMT
  _2 = &pChansIdxMask_6(D)->ChanMaskArr;
  Adc_Sar_SetInjectedChain (u32Instance_7(D), _2);
  # DEBUG BEGIN_STMT

  <bb 5> [local count: 1073741824]:
<L4>:
  return;

}



;; Function Adc_Sar_Ip_EnableChannel (Adc_Sar_Ip_EnableChannel, funcdef_no=25, decl_uid=5957, cgraph_uid=26, symbol_order=30)

Modification phase of node Adc_Sar_Ip_EnableChannel/30
Adc_Sar_Ip_EnableChannel (const uint32 u32Instance, const Adc_Sar_Ip_ConvChainType pChainType, const uint32 u32ChnIdx)
{
  struct ADC_Type * const AdcBasePtr;
  uint32 VectBit;
  uint32 VectAdr;
  volatile uint32_t * _1;
  long unsigned int _2;
  volatile uint32_t * _3;
  long unsigned int _4;
  long unsigned int _5;
  long unsigned int _6;
  volatile uint32_t * _7;
  long unsigned int _8;
  volatile uint32_t * _9;
  long unsigned int _10;
  long unsigned int _11;
  long unsigned int _12;

  <bb 2> [local count: 1073741817]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  AdcBasePtr_16 = Adc_Sar_Ip_apxAdcBase[u32Instance_15(D)];
  # DEBUG AdcBasePtr => AdcBasePtr_16
  # DEBUG BEGIN_STMT
  VectAdr_18 = u32ChnIdx_17(D) >> 5;
  # DEBUG VectAdr => VectAdr_18
  # DEBUG BEGIN_STMT
  VectBit_19 = u32ChnIdx_17(D) & 31;
  # DEBUG VectBit => VectBit_19
  # DEBUG BEGIN_STMT
  switch (pChainType_20(D)) <default: <L4> [33.33%], case 0: <L0> [33.33%], case 1: <L1> [33.33%]>

  <bb 3> [local count: 357913942]:
<L0>:
  # DEBUG BEGIN_STMT
  SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_23 ();
  # DEBUG BEGIN_STMT
  _1 = &AdcBasePtr_16->NCMR0;
  _2 = VectAdr_18 * 4;
  _3 = _1 + _2;
  _4 ={v} MEM[(volatile uint32 *)_3];
  _5 = 1 << VectBit_19;
  _6 = _4 | _5;
  MEM[(volatile uint32 *)_3] ={v} _6;
  # DEBUG BEGIN_STMT
  SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_23 ();
  # DEBUG BEGIN_STMT
  goto <bb 5>; [100.00%]

  <bb 4> [local count: 357913942]:
<L1>:
  # DEBUG BEGIN_STMT
  SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_26 ();
  # DEBUG BEGIN_STMT
  _7 = &AdcBasePtr_16->JCMR0;
  _8 = VectAdr_18 * 4;
  _9 = _7 + _8;
  _10 ={v} MEM[(volatile uint32 *)_9];
  _11 = 1 << VectBit_19;
  _12 = _10 | _11;
  MEM[(volatile uint32 *)_9] ={v} _12;
  # DEBUG BEGIN_STMT
  SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_26 ();
  # DEBUG BEGIN_STMT

  <bb 5> [local count: 1073741824]:
<L4>:
  return;

}



;; Function Adc_Sar_Ip_DisableChannel (Adc_Sar_Ip_DisableChannel, funcdef_no=26, decl_uid=5961, cgraph_uid=27, symbol_order=31)

Modification phase of node Adc_Sar_Ip_DisableChannel/31
Adc_Sar_Ip_DisableChannel (const uint32 u32Instance, const Adc_Sar_Ip_ConvChainType pChainType, const uint32 u32ChnIdx)
{
  struct ADC_Type * const AdcBasePtr;
  uint32 VectBit;
  uint32 VectAdr;
  volatile uint32_t * _1;
  long unsigned int _2;
  volatile uint32_t * _3;
  long unsigned int _4;
  long unsigned int _5;
  long unsigned int _6;
  long unsigned int _7;
  volatile uint32_t * _8;
  long unsigned int _9;
  volatile uint32_t * _10;
  long unsigned int _11;
  long unsigned int _12;
  long unsigned int _13;
  long unsigned int _14;

  <bb 2> [local count: 1073741817]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  AdcBasePtr_18 = Adc_Sar_Ip_apxAdcBase[u32Instance_17(D)];
  # DEBUG AdcBasePtr => AdcBasePtr_18
  # DEBUG BEGIN_STMT
  VectAdr_20 = u32ChnIdx_19(D) >> 5;
  # DEBUG VectAdr => VectAdr_20
  # DEBUG BEGIN_STMT
  VectBit_21 = u32ChnIdx_19(D) & 31;
  # DEBUG VectBit => VectBit_21
  # DEBUG BEGIN_STMT
  switch (pChainType_22(D)) <default: <L4> [33.33%], case 0: <L0> [33.33%], case 1: <L1> [33.33%]>

  <bb 3> [local count: 357913942]:
<L0>:
  # DEBUG BEGIN_STMT
  SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_24 ();
  # DEBUG BEGIN_STMT
  _1 = &AdcBasePtr_18->NCMR0;
  _2 = VectAdr_20 * 4;
  _3 = _1 + _2;
  _4 ={v} MEM[(volatile uint32 *)_3];
  _5 = 1 << VectBit_21;
  _6 = ~_5;
  _7 = _4 & _6;
  MEM[(volatile uint32 *)_3] ={v} _7;
  # DEBUG BEGIN_STMT
  SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_24 ();
  # DEBUG BEGIN_STMT
  goto <bb 5>; [100.00%]

  <bb 4> [local count: 357913942]:
<L1>:
  # DEBUG BEGIN_STMT
  SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_27 ();
  # DEBUG BEGIN_STMT
  _8 = &AdcBasePtr_18->JCMR0;
  _9 = VectAdr_20 * 4;
  _10 = _8 + _9;
  _11 ={v} MEM[(volatile uint32 *)_10];
  _12 = 1 << VectBit_21;
  _13 = ~_12;
  _14 = _11 & _13;
  MEM[(volatile uint32 *)_10] ={v} _14;
  # DEBUG BEGIN_STMT
  SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_27 ();
  # DEBUG BEGIN_STMT

  <bb 5> [local count: 1073741824]:
<L4>:
  return;

}



;; Function Adc_Sar_Ip_SetResolution (Adc_Sar_Ip_SetResolution, funcdef_no=27, decl_uid=5964, cgraph_uid=28, symbol_order=32)

Modification phase of node Adc_Sar_Ip_SetResolution/32
Adc_Sar_Ip_SetResolution (const uint32 u32Instance, const Adc_Sar_Ip_Resolution eResolution)
{
  uint32 Calbistreg;
  struct ADC_Type * const AdcBasePtr;
  long unsigned int _1;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  AdcBasePtr_4 = Adc_Sar_Ip_apxAdcBase[u32Instance_3(D)];
  # DEBUG AdcBasePtr => AdcBasePtr_4
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_37 ();
  # DEBUG BEGIN_STMT
  Calbistreg_6 ={v} AdcBasePtr_4->CALBISTREG;
  # DEBUG Calbistreg => Calbistreg_6
  # DEBUG BEGIN_STMT
  Calbistreg_7 = Calbistreg_6 & 536870911;
  # DEBUG Calbistreg => Calbistreg_7
  # DEBUG BEGIN_STMT
  _1 = eResolution_8(D) << 29;
  Calbistreg_9 = _1 | Calbistreg_7;
  # DEBUG Calbistreg => Calbistreg_9
  # DEBUG BEGIN_STMT
  AdcBasePtr_4->CALBISTREG ={v} Calbistreg_9;
  # DEBUG BEGIN_STMT
  SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_37 ();
  return;

}



;; Function Adc_Sar_Ip_StartConversion (Adc_Sar_Ip_StartConversion, funcdef_no=28, decl_uid=5967, cgraph_uid=29, symbol_order=33)

Modification phase of node Adc_Sar_Ip_StartConversion/33
Adc_Sar_Ip_StartConversion (const uint32 u32Instance, const Adc_Sar_Ip_ConvChainType pChainType)
{
  struct ADC_Type * const AdcBasePtr;
  long unsigned int _1;
  long unsigned int _2;
  long unsigned int _3;
  long unsigned int _4;

  <bb 2> [local count: 1073741817]:
  # DEBUG BEGIN_STMT
  AdcBasePtr_8 = Adc_Sar_Ip_apxAdcBase[u32Instance_7(D)];
  # DEBUG AdcBasePtr => AdcBasePtr_8
  # DEBUG BEGIN_STMT
  SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_10 ();
  # DEBUG BEGIN_STMT
  switch (pChainType_10(D)) <default: <L4> [33.33%], case 0: <L0> [33.33%], case 1: <L1> [33.33%]>

  <bb 3> [local count: 357913942]:
<L0>:
  # DEBUG BEGIN_STMT
  _1 ={v} AdcBasePtr_8->MCR;
  _2 = _1 | 16777216;
  AdcBasePtr_8->MCR ={v} _2;
  # DEBUG BEGIN_STMT
  goto <bb 5>; [100.00%]

  <bb 4> [local count: 357913942]:
<L1>:
  # DEBUG BEGIN_STMT
  _3 ={v} AdcBasePtr_8->MCR;
  _4 = _3 | 1048576;
  AdcBasePtr_8->MCR ={v} _4;
  # DEBUG BEGIN_STMT

  <bb 5> [local count: 1073741824]:
<L4>:
  # DEBUG BEGIN_STMT
  SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_10 ();
  return;

}



;; Function Adc_Sar_Ip_GetStatusFlags (Adc_Sar_Ip_GetStatusFlags, funcdef_no=29, decl_uid=5969, cgraph_uid=30, symbol_order=34)

Modification phase of node Adc_Sar_Ip_GetStatusFlags/34
Adc_Sar_Ip_GetStatusFlags (const uint32 u32Instance)
{
  uint32 Flags;
  long unsigned int _4;
  long unsigned int _6;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG Flags => 0
  # DEBUG BEGIN_STMT
  _4 = Adc_Sar_GetMsrFlags (u32Instance_2(D));
  # DEBUG Flags => _4
  # DEBUG BEGIN_STMT
  _6 = Adc_Sar_GetIsrFlags (u32Instance_2(D));
  Flags_7 = _4 | _6;
  # DEBUG Flags => Flags_7
  # DEBUG BEGIN_STMT
  return Flags_7;

}



;; Function Adc_Sar_Ip_ClearStatusFlags (Adc_Sar_Ip_ClearStatusFlags, funcdef_no=30, decl_uid=5972, cgraph_uid=31, symbol_order=35)

Modification phase of node Adc_Sar_Ip_ClearStatusFlags/35
Adc_Sar_Ip_ClearStatusFlags (const uint32 u32Instance, const uint32 u32Mask)
{
  struct ADC_Type * const AdcBasePtr;
  uint32 IsrFlags;
  long unsigned int _1;
  long unsigned int _2;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG IsrFlags => 0
  # DEBUG BEGIN_STMT
  AdcBasePtr_6 = Adc_Sar_Ip_apxAdcBase[u32Instance_5(D)];
  # DEBUG AdcBasePtr => AdcBasePtr_6
  # DEBUG BEGIN_STMT
  # DEBUG IsrFlags => u32Mask_7(D) & 2
  # DEBUG BEGIN_STMT
  # DEBUG IsrFlags => u32Mask_7(D) & 3
  # DEBUG BEGIN_STMT
  # DEBUG IsrFlags => u32Mask_7(D) & 11
  # DEBUG BEGIN_STMT
  IsrFlags_8 = u32Mask_7(D) & 15;
  # DEBUG IsrFlags => IsrFlags_8
  # DEBUG BEGIN_STMT
  _1 = Adc_Sar_Ip_au32AdcFeatureBitmap[u32Instance_5(D)];
  _2 = _1 & 4;
  if (_2 != 0)
    goto <bb 3>; [50.00%]
  else
    goto <bb 4>; [50.00%]

  <bb 3> [local count: 536870913]:
  # DEBUG BEGIN_STMT
  IsrFlags_9 = u32Mask_7(D) & 31;
  # DEBUG IsrFlags => IsrFlags_9

  <bb 4> [local count: 1073741824]:
  # IsrFlags_3 = PHI <IsrFlags_8(2), IsrFlags_9(3)>
  # DEBUG IsrFlags => IsrFlags_3
  # DEBUG BEGIN_STMT
  AdcBasePtr_6->ISR ={v} IsrFlags_3;
  return;

}



;; Function Adc_Sar_Ip_SelfTest (Adc_Sar_Ip_SelfTest, funcdef_no=31, decl_uid=5974, cgraph_uid=32, symbol_order=36)

Modification phase of node Adc_Sar_Ip_SelfTest/36
Adc_Sar_Ip_SelfTest (const uint32 u32Instance)
{
  struct ADC_Type * const AdcBasePtr;
  uint32 ElapsedTicks;
  uint32 CurrentTicks;
  uint32 TimeoutTicks;
  uint32 MsrStatus;
  Adc_Sar_Ip_StatusType Status;
  long unsigned int _1;
  long unsigned int _2;
  long unsigned int _3;
  long unsigned int _4;
  long unsigned int _5;
  long unsigned int _6;
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
  long unsigned int _17;
  long unsigned int _18;
  long unsigned int _19;
  long unsigned int _56;

  <bb 2> [local count: 229727060]:
  # DEBUG BEGIN_STMT
  # DEBUG Status => 0
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  TimeoutTicks_28 = OsIf_MicrosToTicks (3000, 0);
  # DEBUG TimeoutTicks => TimeoutTicks_28
  # DEBUG BEGIN_STMT
  _1 = OsIf_GetCounter (0);
  CurrentTicks = _1;
  # DEBUG BEGIN_STMT
  # DEBUG ElapsedTicks => 0
  # DEBUG BEGIN_STMT
  AdcBasePtr_32 = Adc_Sar_Ip_apxAdcBase[u32Instance_31(D)];
  # DEBUG AdcBasePtr => AdcBasePtr_32
  # DEBUG BEGIN_STMT
  SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_25 ();
  # DEBUG BEGIN_STMT
  _2 ={v} MEM[(volatile uint32 *)AdcBasePtr_32 + 164B];
  _3 = _2 | 1;
  MEM[(volatile uint32 *)AdcBasePtr_32 + 164B] ={v} _3;
  # DEBUG BEGIN_STMT
  SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_25 ();
  # DEBUG BEGIN_STMT
  SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_11 ();
  # DEBUG BEGIN_STMT
  _4 ={v} AdcBasePtr_32->MCR;
  _5 = _4 & 4294836223;
  AdcBasePtr_32->MCR ={v} _5;
  # DEBUG BEGIN_STMT
  _6 ={v} AdcBasePtr_32->MCR;
  _7 = _6 | 536870912;
  AdcBasePtr_32->MCR ={v} _7;
  # DEBUG BEGIN_STMT
  SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_11 ();
  # DEBUG BEGIN_STMT
  # DEBUG Reg => 0
  # DEBUG BEGIN_STMT
  # DEBUG Reg => 268439552
  # DEBUG BEGIN_STMT
  AdcBasePtr_32->STCR1 ={v} 268439552;
  # DEBUG BEGIN_STMT
  SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_35 ();
  # DEBUG BEGIN_STMT
  _8 ={v} AdcBasePtr_32->STCR3;
  _9 = _8 | 768;
  AdcBasePtr_32->STCR3 ={v} _9;
  # DEBUG BEGIN_STMT
  _10 ={v} AdcBasePtr_32->STCR2;
  _11 = _10 | 128;
  AdcBasePtr_32->STCR2 ={v} _11;
  # DEBUG BEGIN_STMT
  SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_35 ();
  # DEBUG BEGIN_STMT
  SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_11 ();
  # DEBUG BEGIN_STMT
  _12 ={v} AdcBasePtr_32->MCR;
  _13 = _12 | 16777216;
  AdcBasePtr_32->MCR ={v} _13;
  # DEBUG BEGIN_STMT
  SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_11 ();
  # DEBUG BEGIN_STMT
  Status_49 = Adc_Sar_CheckSelfTestProgress (u32Instance_31(D));
  # DEBUG Status => Status_49
  # DEBUG BEGIN_STMT
  SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_11 ();
  # DEBUG BEGIN_STMT
  _14 ={v} AdcBasePtr_32->MCR;
  _15 = _14 & 4278190079;
  AdcBasePtr_32->MCR ={v} _15;
  # DEBUG BEGIN_STMT
  SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_11 ();
  # DEBUG BEGIN_STMT
  if (Status_49 == 0)
    goto <bb 3>; [50.00%]
  else
    goto <bb 7>; [50.00%]

  <bb 3> [local count: 114863530]:
  # DEBUG BEGIN_STMT
  _16 ={v} AdcBasePtr_32->MSR;
  MsrStatus_53 = _16 & 7;
  # DEBUG MsrStatus => MsrStatus_53
  # DEBUG BEGIN_STMT
  # DEBUG ElapsedTicks => 0
  # DEBUG BEGIN_STMT
  goto <bb 5>; [100.00%]

  <bb 4> [local count: 958878296]:
  # DEBUG BEGIN_STMT
  _17 ={v} AdcBasePtr_32->MSR;
  MsrStatus_54 = _17 & 7;
  # DEBUG MsrStatus => MsrStatus_54
  # DEBUG BEGIN_STMT
  _56 = OsIf_GetElapsed (&CurrentTicks, 0);
  ElapsedTicks_57 = ElapsedTicks_22 + _56;
  # DEBUG ElapsedTicks => ElapsedTicks_57

  <bb 5> [local count: 1073741824]:
  # MsrStatus_21 = PHI <MsrStatus_53(3), MsrStatus_54(4)>
  # ElapsedTicks_22 = PHI <0(3), ElapsedTicks_57(4)>
  # DEBUG ElapsedTicks => ElapsedTicks_22
  # DEBUG MsrStatus => MsrStatus_21
  # DEBUG BEGIN_STMT
  if (MsrStatus_21 != 0)
    goto <bb 6>; [94.50%]
  else
    goto <bb 7>; [5.50%]

  <bb 6> [local count: 1014686026]:
  if (ElapsedTicks_22 < TimeoutTicks_28)
    goto <bb 4>; [94.50%]
  else
    goto <bb 7>; [5.50%]

  <bb 7> [local count: 229727061]:
  # ElapsedTicks_23 = PHI <0(2), ElapsedTicks_22(5), ElapsedTicks_22(6)>
  # DEBUG ElapsedTicks => ElapsedTicks_23
  # DEBUG BEGIN_STMT
  SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_35 ();
  # DEBUG BEGIN_STMT
  _18 ={v} AdcBasePtr_32->STCR2;
  _19 = _18 & 4294967167;
  AdcBasePtr_32->STCR2 ={v} _19;
  # DEBUG BEGIN_STMT
  SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_35 ();
  # DEBUG BEGIN_STMT
  if (ElapsedTicks_23 >= TimeoutTicks_28)
    goto <bb 8>; [35.00%]
  else
    goto <bb 9>; [65.00%]

  <bb 8> [local count: 80404472]:
  # DEBUG BEGIN_STMT
  # DEBUG Status => 2

  <bb 9> [local count: 229727061]:
  # Status_20 = PHI <Status_49(7), 2(8)>
  # DEBUG Status => Status_20
  # DEBUG BEGIN_STMT
  CurrentTicks ={v} {CLOBBER};
  return Status_20;

}



;; Function Adc_Sar_Ip_GetConvDataToArray (Adc_Sar_Ip_GetConvDataToArray, funcdef_no=32, decl_uid=5979, cgraph_uid=33, symbol_order=37)

Modification phase of node Adc_Sar_Ip_GetConvDataToArray/37
Adc_Sar_Ip_GetConvDataToArray (const uint32 u32Instance, const Adc_Sar_Ip_ConvChainType pChainType, const uint32 u32Length, uint16 * const pResults)
{
  uint32 _7;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  _7 = Adc_Sar_GetConvResults (u32Instance_2(D), pChainType_3(D), pResults_4(D), 0B, u32Length_5(D));
  return _7;

}



;; Function Adc_Sar_Ip_GetConvResultsToArray (Adc_Sar_Ip_GetConvResultsToArray, funcdef_no=33, decl_uid=5984, cgraph_uid=34, symbol_order=38)

Modification phase of node Adc_Sar_Ip_GetConvResultsToArray/38
Adc_Sar_Ip_GetConvResultsToArray (const uint32 u32Instance, const Adc_Sar_Ip_ConvChainType pChainType, const uint32 u32Length, struct Adc_Sar_Ip_ChanResultType * const pResults)
{
  uint32 _7;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  _7 = Adc_Sar_GetConvResults (u32Instance_2(D), pChainType_3(D), 0B, pResults_4(D), u32Length_5(D));
  return _7;

}



;; Function Adc_Sar_Ip_GetConvData (Adc_Sar_Ip_GetConvData, funcdef_no=34, decl_uid=5987, cgraph_uid=35, symbol_order=39)

Modification phase of node Adc_Sar_Ip_GetConvData/39
Adc_Sar_Ip_GetConvData (const uint32 u32Instance, const uint32 u32ChnIdx)
{
  struct ADC_Type * const AdcBasePtr;
  uint32 Cdr;
  uint32 VectBit;
  uint32 VectAdr;
  uint16 Result;
  const uint32_t * _1;
  long unsigned int _2;
  const uint32_t * _3;
  long unsigned int _4;
  volatile uint32_t * _5;
  long unsigned int _6;
  volatile uint32_t * _7;
  long unsigned int _8;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG Result => 0
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  AdcBasePtr_13 = Adc_Sar_Ip_apxAdcBase[u32Instance_12(D)];
  # DEBUG AdcBasePtr => AdcBasePtr_13
  # DEBUG BEGIN_STMT
  VectAdr_15 = u32ChnIdx_14(D) >> 5;
  # DEBUG VectAdr => VectAdr_15
  # DEBUG BEGIN_STMT
  VectBit_16 = u32ChnIdx_14(D) & 31;
  # DEBUG VectBit => VectBit_16
  # DEBUG BEGIN_STMT
  _1 = &AdcBasePtr_13->PCDR[0];
  _2 = u32ChnIdx_14(D) * 4;
  _3 = _1 + _2;
  Cdr_17 ={v} MEM[(const uint32 *)_3];
  # DEBUG Cdr => Cdr_17
  # DEBUG BEGIN_STMT
  _4 = Cdr_17 & 524288;
  if (_4 != 0)
    goto <bb 3>; [33.00%]
  else
    goto <bb 4>; [67.00%]

  <bb 3> [local count: 354334800]:
  # DEBUG BEGIN_STMT
  Result_19 = Adc_Sar_GetMaskedResult (u32Instance_12(D), Cdr_17);
  # DEBUG Result => Result_19
  # DEBUG BEGIN_STMT
  _5 = &AdcBasePtr_13->CEOCFR0;
  _6 = VectAdr_15 * 4;
  _7 = _5 + _6;
  _8 = 1 << VectBit_16;
  MEM[(volatile uint32 *)_7] ={v} _8;

  <bb 4> [local count: 1073741824]:
  # Result_9 = PHI <0(2), Result_19(3)>
  # DEBUG Result => Result_9
  # DEBUG BEGIN_STMT
  return Result_9;

}



;; Function Adc_Sar_Ip_GetConvResult (Adc_Sar_Ip_GetConvResult, funcdef_no=35, decl_uid=5992, cgraph_uid=36, symbol_order=40)

Modification phase of node Adc_Sar_Ip_GetConvResult/40
Adc_Sar_Ip_GetConvResult (const uint32 u32Instance, const uint32 u32ChnIdx, const Adc_Sar_Ip_ConvChainType pChainType, struct Adc_Sar_Ip_ChanResultType * const pResult)
{
  struct ADC_Type * const AdcBasePtr;
  uint32 Cdr;
  uint32 VectBit;
  uint32 VectAdr;
  unsigned char _1;
  const uint32_t * _2;
  long unsigned int _3;
  const uint32_t * _4;
  long unsigned int _5;
  long unsigned int _6;
  long unsigned int _7;
  long unsigned int _8;
  _Bool _9;
  long unsigned int _10;
  _Bool _11;
  short unsigned int _12;
  volatile uint32_t * _13;
  long unsigned int _14;
  volatile uint32_t * _15;
  long unsigned int _16;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  AdcBasePtr_20 = Adc_Sar_Ip_apxAdcBase[u32Instance_19(D)];
  # DEBUG AdcBasePtr => AdcBasePtr_20
  # DEBUG BEGIN_STMT
  VectAdr_22 = u32ChnIdx_21(D) >> 5;
  # DEBUG VectAdr => VectAdr_22
  # DEBUG BEGIN_STMT
  VectBit_23 = u32ChnIdx_21(D) & 31;
  # DEBUG VectBit => VectBit_23
  # DEBUG BEGIN_STMT
  pResult_24(D)->ConvData = 0;
  # DEBUG BEGIN_STMT
  _1 = (unsigned char) u32ChnIdx_21(D);
  pResult_24(D)->AdcChnIdx = _1;
  # DEBUG BEGIN_STMT
  pResult_24(D)->ValidFlag = 0;
  # DEBUG BEGIN_STMT
  pResult_24(D)->OverWrittenFlag = 0;
  # DEBUG BEGIN_STMT
  _2 = &AdcBasePtr_20->PCDR[0];
  _3 = u32ChnIdx_21(D) * 4;
  _4 = _2 + _3;
  Cdr_29 ={v} MEM[(const uint32 *)_4];
  # DEBUG Cdr => Cdr_29
  # DEBUG BEGIN_STMT
  _5 = pChainType_30(D) << 16;
  _6 = _5 ^ Cdr_29;
  _7 = _6 & 196608;
  if (_7 == 0)
    goto <bb 3>; [33.00%]
  else
    goto <bb 4>; [67.00%]

  <bb 3> [local count: 354334800]:
  # DEBUG BEGIN_STMT
  _8 = Cdr_29 >> 19;
  _9 = (_Bool) _8;
  pResult_24(D)->ValidFlag = _9;
  # DEBUG BEGIN_STMT
  _10 = Cdr_29 & 262144;
  _11 = _10 != 0;
  pResult_24(D)->OverWrittenFlag = _11;
  # DEBUG BEGIN_STMT
  _12 = Adc_Sar_GetMaskedResult (u32Instance_19(D), Cdr_29);
  pResult_24(D)->ConvData = _12;

  <bb 4> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  _13 = &AdcBasePtr_20->CEOCFR0;
  _14 = VectAdr_22 * 4;
  _15 = _13 + _14;
  _16 = 1 << VectBit_23;
  MEM[(volatile uint32 *)_15] ={v} _16;
  return;

}



;; Function Adc_Sar_Ip_Powerup (Adc_Sar_Ip_Powerup, funcdef_no=37, decl_uid=5996, cgraph_uid=38, symbol_order=42)

Modification phase of node Adc_Sar_Ip_Powerup/42
Adc_Sar_Ip_Powerup (const uint32 u32Instance)
{
  struct ADC_Type * const AdcBasePtr;
  uint32 ElapsedTicks;
  uint32 CurrentTicks;
  uint32 TimeoutTicks;
  uint32 MsrStatus;
  Adc_Sar_Ip_StatusType ReturnStatus;
  long unsigned int _1;
  long unsigned int _2;
  long unsigned int _3;
  long unsigned int _20;
  long unsigned int _24;
  long unsigned int _25;

  <bb 2> [local count: 114863530]:
  # DEBUG BEGIN_STMT
  # DEBUG ReturnStatus => 0
  # DEBUG BEGIN_STMT
  # DEBUG ExpectedStatus => 0
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  TimeoutTicks_10 = OsIf_MicrosToTicks (3000, 0);
  # DEBUG TimeoutTicks => TimeoutTicks_10
  # DEBUG BEGIN_STMT
  _1 = OsIf_GetCounter (0);
  CurrentTicks = _1;
  # DEBUG BEGIN_STMT
  # DEBUG ElapsedTicks => 0
  # DEBUG BEGIN_STMT
  AdcBasePtr_14 = Adc_Sar_Ip_apxAdcBase[u32Instance_13(D)];
  # DEBUG AdcBasePtr => AdcBasePtr_14
  # DEBUG BEGIN_STMT
  _2 ={v} AdcBasePtr_14->MSR;
  MsrStatus_15 = _2 & 7;
  # DEBUG MsrStatus => MsrStatus_15
  # DEBUG BEGIN_STMT
  SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_13 ();
  # DEBUG BEGIN_STMT
  # DEBUG Base => AdcBasePtr_14
  # DEBUG INLINE_ENTRY Adc_Sar_Powerup
  # DEBUG BEGIN_STMT
  _24 ={v} AdcBasePtr_14->MCR;
  _25 = _24 & 4294967294;
  AdcBasePtr_14->MCR ={v} _25;
  # DEBUG Base => NULL
  # DEBUG BEGIN_STMT
  SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_13 ();
  # DEBUG BEGIN_STMT
  goto <bb 4>; [100.00%]

  <bb 3> [local count: 958878296]:
  # DEBUG BEGIN_STMT
  _3 ={v} AdcBasePtr_14->MSR;
  MsrStatus_18 = _3 & 7;
  # DEBUG MsrStatus => MsrStatus_18
  # DEBUG BEGIN_STMT
  _20 = OsIf_GetElapsed (&CurrentTicks, 0);
  ElapsedTicks_21 = ElapsedTicks_6 + _20;
  # DEBUG ElapsedTicks => ElapsedTicks_21

  <bb 4> [local count: 1073741824]:
  # MsrStatus_5 = PHI <MsrStatus_15(2), MsrStatus_18(3)>
  # ElapsedTicks_6 = PHI <0(2), ElapsedTicks_21(3)>
  # DEBUG ElapsedTicks => ElapsedTicks_6
  # DEBUG MsrStatus => MsrStatus_5
  # DEBUG BEGIN_STMT
  if (MsrStatus_5 != 0)
    goto <bb 5>; [94.50%]
  else
    goto <bb 6>; [5.50%]

  <bb 5> [local count: 1014686026]:
  if (ElapsedTicks_6 < TimeoutTicks_10)
    goto <bb 3>; [94.50%]
  else
    goto <bb 6>; [5.50%]

  <bb 6> [local count: 114863531]:
  # ElapsedTicks_22 = PHI <ElapsedTicks_6(4), ElapsedTicks_6(5)>
  # DEBUG BEGIN_STMT
  if (TimeoutTicks_10 <= ElapsedTicks_22)
    goto <bb 7>; [35.00%]
  else
    goto <bb 8>; [65.00%]

  <bb 7> [local count: 40202236]:
  # DEBUG BEGIN_STMT
  # DEBUG ReturnStatus => 2

  <bb 8> [local count: 114863531]:
  # ReturnStatus_4 = PHI <0(6), 2(7)>
  # DEBUG ReturnStatus => ReturnStatus_4
  # DEBUG BEGIN_STMT
  CurrentTicks ={v} {CLOBBER};
  return ReturnStatus_4;

}



;; Function Adc_Sar_Ip_Powerdown (Adc_Sar_Ip_Powerdown, funcdef_no=38, decl_uid=5998, cgraph_uid=39, symbol_order=43)

Modification phase of node Adc_Sar_Ip_Powerdown/43
Adc_Sar_Ip_Powerdown (const uint32 u32Instance)
{
  struct ADC_Type * const AdcBasePtr;
  uint32 ElapsedTicks;
  uint32 CurrentTicks;
  uint32 TimeoutTicks;
  uint32 MsrStatus;
  Adc_Sar_Ip_StatusType ReturnStatus;
  long unsigned int _1;
  long unsigned int _2;
  long unsigned int _3;
  long unsigned int _20;
  long unsigned int _24;
  long unsigned int _25;

  <bb 2> [local count: 114863530]:
  # DEBUG BEGIN_STMT
  # DEBUG ReturnStatus => 0
  # DEBUG BEGIN_STMT
  # DEBUG ExpectedStatus => 1
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  TimeoutTicks_10 = OsIf_MicrosToTicks (3000, 0);
  # DEBUG TimeoutTicks => TimeoutTicks_10
  # DEBUG BEGIN_STMT
  _1 = OsIf_GetCounter (0);
  CurrentTicks = _1;
  # DEBUG BEGIN_STMT
  # DEBUG ElapsedTicks => 0
  # DEBUG BEGIN_STMT
  AdcBasePtr_14 = Adc_Sar_Ip_apxAdcBase[u32Instance_13(D)];
  # DEBUG AdcBasePtr => AdcBasePtr_14
  # DEBUG BEGIN_STMT
  _2 ={v} AdcBasePtr_14->MSR;
  MsrStatus_15 = _2 & 7;
  # DEBUG MsrStatus => MsrStatus_15
  # DEBUG BEGIN_STMT
  SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_14 ();
  # DEBUG BEGIN_STMT
  # DEBUG Base => AdcBasePtr_14
  # DEBUG INLINE_ENTRY Adc_Sar_Powerdown
  # DEBUG BEGIN_STMT
  _24 ={v} AdcBasePtr_14->MCR;
  _25 = _24 | 1;
  AdcBasePtr_14->MCR ={v} _25;
  # DEBUG Base => NULL
  # DEBUG BEGIN_STMT
  SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_14 ();
  # DEBUG BEGIN_STMT
  goto <bb 4>; [100.00%]

  <bb 3> [local count: 958878296]:
  # DEBUG BEGIN_STMT
  _3 ={v} AdcBasePtr_14->MSR;
  MsrStatus_18 = _3 & 7;
  # DEBUG MsrStatus => MsrStatus_18
  # DEBUG BEGIN_STMT
  _20 = OsIf_GetElapsed (&CurrentTicks, 0);
  ElapsedTicks_21 = ElapsedTicks_6 + _20;
  # DEBUG ElapsedTicks => ElapsedTicks_21

  <bb 4> [local count: 1073741824]:
  # MsrStatus_5 = PHI <MsrStatus_15(2), MsrStatus_18(3)>
  # ElapsedTicks_6 = PHI <0(2), ElapsedTicks_21(3)>
  # DEBUG ElapsedTicks => ElapsedTicks_6
  # DEBUG MsrStatus => MsrStatus_5
  # DEBUG BEGIN_STMT
  if (MsrStatus_5 != 1)
    goto <bb 5>; [94.50%]
  else
    goto <bb 6>; [5.50%]

  <bb 5> [local count: 1014686026]:
  if (ElapsedTicks_6 < TimeoutTicks_10)
    goto <bb 3>; [94.50%]
  else
    goto <bb 6>; [5.50%]

  <bb 6> [local count: 114863531]:
  # ElapsedTicks_22 = PHI <ElapsedTicks_6(4), ElapsedTicks_6(5)>
  # DEBUG BEGIN_STMT
  if (TimeoutTicks_10 <= ElapsedTicks_22)
    goto <bb 7>; [35.00%]
  else
    goto <bb 8>; [65.00%]

  <bb 7> [local count: 40202236]:
  # DEBUG BEGIN_STMT
  # DEBUG ReturnStatus => 2

  <bb 8> [local count: 114863531]:
  # ReturnStatus_4 = PHI <0(6), 2(7)>
  # DEBUG ReturnStatus => ReturnStatus_4
  # DEBUG BEGIN_STMT
  CurrentTicks ={v} {CLOBBER};
  return ReturnStatus_4;

}



;; Function Adc_Sar_Ip_DoCalibration (Adc_Sar_Ip_DoCalibration, funcdef_no=36, decl_uid=5994, cgraph_uid=37, symbol_order=41)

Modification phase of node Adc_Sar_Ip_DoCalibration/41
Adc_Sar_Ip_DoCalibration (const uint32 u32Instance)
{
  struct ADC_Type * const AdcBasePtr;
  uint32 Calbistreg;
  uint32 Mcr;
  uint32 AdcClkSel;
  uint32 ElapsedTicks;
  uint32 CurrentTicks;
  uint32 TimeoutTicks;
  Adc_Sar_Ip_StatusType CalStatus;
  Adc_Sar_Ip_StatusType Status;
  long unsigned int _1;
  <unnamed type> _2;
  long unsigned int _3;
  long unsigned int _4;
  long unsigned int _5;
  long unsigned int _6;
  long unsigned int _7;
  long unsigned int _8;
  long unsigned int _9;
  long unsigned int _10;
  long unsigned int _32;
  long unsigned int _47;
  long unsigned int _60;

  <bb 2> [local count: 1054761537]:
  # DEBUG BEGIN_STMT
  # DEBUG Status => 0
  # DEBUG BEGIN_STMT
  # DEBUG CalStatus => 0
  # DEBUG BEGIN_STMT
  TimeoutTicks_21 = OsIf_MicrosToTicks (3000, 0);
  # DEBUG TimeoutTicks => TimeoutTicks_21
  # DEBUG BEGIN_STMT
  _1 = OsIf_GetCounter (0);
  CurrentTicks = _1;
  # DEBUG BEGIN_STMT
  # DEBUG ElapsedTicks => 0
  # DEBUG BEGIN_STMT
  # DEBUG AdcClkSel => 0
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  AdcBasePtr_25 = Adc_Sar_Ip_apxAdcBase[u32Instance_24(D)];
  # DEBUG AdcBasePtr => AdcBasePtr_25
  # DEBUG BEGIN_STMT
  Status_27 = Adc_Sar_Ip_Powerdown (u32Instance_24(D));
  # DEBUG Status => Status_27
  # DEBUG BEGIN_STMT
  if (Status_27 == 0)
    goto <bb 3>; [33.00%]
  else
    goto <bb 15>; [67.00%]

  <bb 3> [local count: 348071305]:
  # DEBUG BEGIN_STMT
  SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_12 ();
  # DEBUG BEGIN_STMT
  Mcr_29 ={v} AdcBasePtr_25->MCR;
  # DEBUG Mcr => Mcr_29
  # DEBUG BEGIN_STMT
  AdcClkSel_30 = Mcr_29 & 6;
  # DEBUG AdcClkSel => AdcClkSel_30
  # DEBUG BEGIN_STMT
  Mcr_31 = Mcr_29 & 4294967289;
  # DEBUG Mcr => Mcr_31
  # DEBUG BEGIN_STMT
  _2 = Adc_Sar_Ip_axAdcSarState[u32Instance_24(D)].CalibrationClkSelect;
  # DEBUG ClockSel => _2
  # DEBUG INLINE_ENTRY Adc_Sar_GetADCLKSELValue
  # DEBUG BEGIN_STMT
  _32 = _2 << 1;
  _60 = _32 & 6;
  # DEBUG ClockSel => NULL
  Mcr_33 = Mcr_31 | _60;
  # DEBUG Mcr => Mcr_33
  # DEBUG BEGIN_STMT
  AdcBasePtr_25->MCR ={v} Mcr_33;
  # DEBUG BEGIN_STMT
  SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_12 ();
  # DEBUG BEGIN_STMT
  Status_37 = Adc_Sar_Ip_Powerup (u32Instance_24(D));
  # DEBUG Status => Status_37
  # DEBUG BEGIN_STMT
  if (Status_37 == 0)
    goto <bb 4>; [33.00%]
  else
    goto <bb 12>; [67.00%]

  <bb 4> [local count: 114863530]:
  # DEBUG BEGIN_STMT
  SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_36 ();
  # DEBUG BEGIN_STMT
  Calbistreg_39 ={v} AdcBasePtr_25->CALBISTREG;
  # DEBUG Calbistreg => Calbistreg_39
  # DEBUG BEGIN_STMT
  Calbistreg_40 = Calbistreg_39 & 3892313998;
  # DEBUG Calbistreg => Calbistreg_40
  # DEBUG BEGIN_STMT
  Calbistreg_41 = Calbistreg_40 | 112;
  # DEBUG Calbistreg => Calbistreg_41
  # DEBUG BEGIN_STMT
  AdcBasePtr_25->CALBISTREG ={v} Calbistreg_41;
  # DEBUG BEGIN_STMT
  _3 ={v} AdcBasePtr_25->CALBISTREG;
  _4 = _3 | 8;
  AdcBasePtr_25->CALBISTREG ={v} _4;
  # DEBUG BEGIN_STMT
  _5 ={v} AdcBasePtr_25->CALBISTREG;
  _6 = _5 | 1;
  AdcBasePtr_25->CALBISTREG ={v} _6;
  # DEBUG BEGIN_STMT
  SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_36 ();
  # DEBUG BEGIN_STMT
  # DEBUG ElapsedTicks => 0
  # DEBUG BEGIN_STMT
  goto <bb 6>; [100.00%]

  <bb 5> [local count: 958878295]:
  # DEBUG BEGIN_STMT
  _47 = OsIf_GetElapsed (&CurrentTicks, 0);
  ElapsedTicks_48 = ElapsedTicks_15 + _47;
  # DEBUG ElapsedTicks => ElapsedTicks_48

  <bb 6> [local count: 1073741824]:
  # ElapsedTicks_15 = PHI <0(4), ElapsedTicks_48(5)>
  # DEBUG ElapsedTicks => ElapsedTicks_15
  # DEBUG BEGIN_STMT
  _7 ={v} AdcBasePtr_25->CALBISTREG;
  _8 = _7 & 32768;
  if (_8 != 0)
    goto <bb 7>; [94.50%]
  else
    goto <bb 8>; [5.50%]

  <bb 7> [local count: 1014686025]:
  if (ElapsedTicks_15 < TimeoutTicks_21)
    goto <bb 5>; [94.50%]
  else
    goto <bb 8>; [5.50%]

  <bb 8> [local count: 114863531]:
  # ElapsedTicks_61 = PHI <ElapsedTicks_15(6), ElapsedTicks_15(7)>
  # DEBUG BEGIN_STMT
  if (TimeoutTicks_21 <= ElapsedTicks_61)
    goto <bb 11>; [50.00%]
  else
    goto <bb 9>; [50.00%]

  <bb 9> [local count: 57431766]:
  # DEBUG BEGIN_STMT
  _9 ={v} AdcBasePtr_25->CALBISTREG;
  _10 = _9 & 8;
  if (_10 != 0)
    goto <bb 10>; [50.00%]
  else
    goto <bb 11>; [50.00%]

  <bb 10> [local count: 28715883]:
  # DEBUG BEGIN_STMT
  # DEBUG CalStatus => 1

  <bb 11> [local count: 114863531]:
  # CalStatus_13 = PHI <2(8), 0(9), 1(10)>
  # DEBUG CalStatus => CalStatus_13
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  Status_50 = Adc_Sar_Ip_Powerdown (u32Instance_24(D));
  # DEBUG Status => Status_50

  <bb 12> [local count: 348071307]:
  # Status_11 = PHI <Status_37(3), Status_50(11)>
  # CalStatus_14 = PHI <0(3), CalStatus_13(11)>
  # DEBUG CalStatus => CalStatus_14
  # DEBUG Status => Status_11
  # DEBUG BEGIN_STMT
  SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_12 ();
  # DEBUG BEGIN_STMT
  Mcr_52 ={v} AdcBasePtr_25->MCR;
  # DEBUG Mcr => Mcr_52
  # DEBUG BEGIN_STMT
  Mcr_53 = Mcr_52 & 4294967289;
  # DEBUG Mcr => Mcr_53
  # DEBUG BEGIN_STMT
  Mcr_54 = AdcClkSel_30 | Mcr_53;
  # DEBUG Mcr => Mcr_54
  # DEBUG BEGIN_STMT
  AdcBasePtr_25->MCR ={v} Mcr_54;
  # DEBUG BEGIN_STMT
  SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_12 ();
  # DEBUG BEGIN_STMT
  if (Status_11 == 0)
    goto <bb 13>; [33.00%]
  else
    goto <bb 15>; [67.00%]

  <bb 13> [local count: 114863531]:
  # DEBUG BEGIN_STMT
  Status_58 = Adc_Sar_Ip_Powerup (u32Instance_24(D));
  # DEBUG Status => Status_58
  # DEBUG BEGIN_STMT
  if (CalStatus_14 != 0)
    goto <bb 14>; [50.00%]
  else
    goto <bb 15>; [50.00%]

  <bb 14> [local count: 57431765]:
  # DEBUG BEGIN_STMT
  # DEBUG Status => CalStatus_14

  <bb 15> [local count: 1054761539]:
  # Status_12 = PHI <Status_27(2), Status_11(12), Status_58(13), CalStatus_14(14)>
  # DEBUG Status => Status_12
  # DEBUG BEGIN_STMT
  CurrentTicks ={v} {CLOBBER};
  return Status_12;

}



;; Function Adc_Sar_Ip_EnableNotifications (Adc_Sar_Ip_EnableNotifications, funcdef_no=39, decl_uid=6001, cgraph_uid=40, symbol_order=44)

Modification phase of node Adc_Sar_Ip_EnableNotifications/44
Adc_Sar_Ip_EnableNotifications (const uint32 u32Instance, const uint32 u32NotificationMask)
{
  struct ADC_Type * const AdcBasePtr;
  uint32 ImrFlags;
  long unsigned int _1;
  long unsigned int _2;
  long unsigned int _3;
  long unsigned int _4;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG ImrFlags => 0
  # DEBUG BEGIN_STMT
  AdcBasePtr_8 = Adc_Sar_Ip_apxAdcBase[u32Instance_7(D)];
  # DEBUG AdcBasePtr => AdcBasePtr_8
  # DEBUG BEGIN_STMT
  # DEBUG ImrFlags => u32NotificationMask_9(D) & 1
  # DEBUG BEGIN_STMT
  ImrFlags_10 = u32NotificationMask_9(D) & 5;
  # DEBUG ImrFlags => ImrFlags_10
  # DEBUG BEGIN_STMT
  _1 = Adc_Sar_Ip_au32AdcFeatureBitmap[u32Instance_7(D)];
  _2 = _1 & 4;
  if (_2 != 0)
    goto <bb 3>; [50.00%]
  else
    goto <bb 4>; [50.00%]

  <bb 3> [local count: 536870913]:
  # DEBUG BEGIN_STMT
  ImrFlags_11 = u32NotificationMask_9(D) & 21;
  # DEBUG ImrFlags => ImrFlags_11

  <bb 4> [local count: 1073741824]:
  # ImrFlags_5 = PHI <ImrFlags_10(2), ImrFlags_11(3)>
  # DEBUG ImrFlags => ImrFlags_5
  # DEBUG BEGIN_STMT
  SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_33 ();
  # DEBUG BEGIN_STMT
  _3 ={v} AdcBasePtr_8->IMR;
  _4 = _3 | ImrFlags_5;
  AdcBasePtr_8->IMR ={v} _4;
  # DEBUG BEGIN_STMT
  SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_33 ();
  return;

}



;; Function Adc_Sar_Ip_DisableNotifications (Adc_Sar_Ip_DisableNotifications, funcdef_no=40, decl_uid=6004, cgraph_uid=41, symbol_order=45)

Modification phase of node Adc_Sar_Ip_DisableNotifications/45
Adc_Sar_Ip_DisableNotifications (const uint32 u32Instance, const uint32 u32NotificationMask)
{
  struct ADC_Type * const AdcBasePtr;
  uint32 ImrFlags;
  long unsigned int _1;
  long unsigned int _2;
  long unsigned int _3;
  long unsigned int _4;
  long unsigned int _5;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG ImrFlags => 0
  # DEBUG BEGIN_STMT
  AdcBasePtr_9 = Adc_Sar_Ip_apxAdcBase[u32Instance_8(D)];
  # DEBUG AdcBasePtr => AdcBasePtr_9
  # DEBUG BEGIN_STMT
  # DEBUG ImrFlags => u32NotificationMask_10(D) & 1
  # DEBUG BEGIN_STMT
  ImrFlags_11 = u32NotificationMask_10(D) & 5;
  # DEBUG ImrFlags => ImrFlags_11
  # DEBUG BEGIN_STMT
  _1 = Adc_Sar_Ip_au32AdcFeatureBitmap[u32Instance_8(D)];
  _2 = _1 & 4;
  if (_2 != 0)
    goto <bb 3>; [50.00%]
  else
    goto <bb 4>; [50.00%]

  <bb 3> [local count: 536870913]:
  # DEBUG BEGIN_STMT
  ImrFlags_12 = u32NotificationMask_10(D) & 21;
  # DEBUG ImrFlags => ImrFlags_12

  <bb 4> [local count: 1073741824]:
  # ImrFlags_6 = PHI <ImrFlags_11(2), ImrFlags_12(3)>
  # DEBUG ImrFlags => ImrFlags_6
  # DEBUG BEGIN_STMT
  SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_34 ();
  # DEBUG BEGIN_STMT
  _3 ={v} AdcBasePtr_9->IMR;
  _4 = ~ImrFlags_6;
  _5 = _3 & _4;
  AdcBasePtr_9->IMR ={v} _5;
  # DEBUG BEGIN_STMT
  SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_34 ();
  return;

}



;; Function Adc_Sar_Ip_SetSampleTimes (Adc_Sar_Ip_SetSampleTimes, funcdef_no=42, decl_uid=6010, cgraph_uid=43, symbol_order=47)

Modification phase of node Adc_Sar_Ip_SetSampleTimes/47
Adc_Sar_Ip_SetSampleTimes (const uint32 u32Instance, const uint8 * const aSampleTimes)
{
  uint8 Index;
  struct ADC_Type * const AdcBasePtr;
  sizetype _1;
  const uint8 * _2;
  unsigned char _3;
  volatile uint32_t * _4;
  unsigned int _5;
  volatile uint32_t * _6;
  long unsigned int _7;
  unsigned char _8;

  <bb 2> [local count: 118111600]:
  # DEBUG BEGIN_STMT
  AdcBasePtr_13 = Adc_Sar_Ip_apxAdcBase[u32Instance_12(D)];
  # DEBUG AdcBasePtr => AdcBasePtr_13
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG Index => 0
  goto <bb 4>; [100.00%]

  <bb 3> [local count: 955630225]:
  # DEBUG BEGIN_STMT
  _1 = (sizetype) Index_9;
  _2 = aSampleTimes_14(D) + _1;
  _3 = *_2;
  _4 = &AdcBasePtr_13->CTR0;
  _5 = _1 * 4;
  _6 = _4 + _5;
  _7 = (long unsigned int) _3;
  MEM[(volatile uint32 *)_6] ={v} _7;
  # DEBUG BEGIN_STMT
  Index_16 = Index_9 + 1;
  # DEBUG Index => Index_16

  <bb 4> [local count: 1073741824]:
  # Index_9 = PHI <0(2), Index_16(3)>
  # DEBUG Index => Index_9
  # DEBUG BEGIN_STMT
  _8 = Adc_Sar_Ip_au8AdcGroupCount[u32Instance_12(D)];
  if (_8 > Index_9)
    goto <bb 3>; [89.00%]
  else
    goto <bb 5>; [11.00%]

  <bb 5> [local count: 118111600]:
  return;

}



;; Function Adc_Sar_Ip_SetAveraging (Adc_Sar_Ip_SetAveraging, funcdef_no=43, decl_uid=6014, cgraph_uid=44, symbol_order=48)

Modification phase of node Adc_Sar_Ip_SetAveraging/48
Adc_Sar_Ip_SetAveraging (const uint32 u32Instance, const boolean bAvgEn, const Adc_Sar_Ip_AvgSelectType eAvgSel)
{
  struct ADC_Type * const AdcBasePtr;
  long unsigned int _1;
  long unsigned int _2;
  long unsigned int _3;
  long unsigned int _4;
  long unsigned int _5;
  long unsigned int _6;
  long unsigned int _7;
  long unsigned int iftmp.16_8;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  AdcBasePtr_11 = Adc_Sar_Ip_apxAdcBase[u32Instance_10(D)];
  # DEBUG AdcBasePtr => AdcBasePtr_11
  # DEBUG BEGIN_STMT
  SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_16 ();
  # DEBUG BEGIN_STMT
  _1 ={v} AdcBasePtr_11->MCR;
  _2 = _1 & 4294963711;
  AdcBasePtr_11->MCR ={v} _2;
  # DEBUG BEGIN_STMT
  _3 ={v} AdcBasePtr_11->MCR;
  if (bAvgEn_14(D) != 0)
    goto <bb 4>; [50.00%]
  else
    goto <bb 3>; [50.00%]

  <bb 3> [local count: 536870913]:

  <bb 4> [local count: 1073741824]:
  # iftmp.16_8 = PHI <2048(2), 0(3)>
  _4 = eAvgSel_15(D) << 9;
  _5 = _4 & 1536;
  _6 = _5 | iftmp.16_8;
  _7 = _3 | _6;
  AdcBasePtr_11->MCR ={v} _7;
  # DEBUG BEGIN_STMT
  SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_16 ();
  return;

}



;; Function Adc_Sar_Ip_SetClockMode (Adc_Sar_Ip_SetClockMode, funcdef_no=41, decl_uid=6007, cgraph_uid=42, symbol_order=46)

Modification phase of node Adc_Sar_Ip_SetClockMode/46
Adc_Sar_Ip_SetClockMode (const uint32 u32Instance, const struct Adc_Sar_Ip_ClockConfigType * const pConfig)
{
  struct ADC_Type * const AdcBasePtr;
  Adc_Sar_Ip_StatusType Status;
  <unnamed type> _1;
  long unsigned int _2;
  long unsigned int _3;
  long unsigned int _4;
  _Bool _5;
  _Bool _6;
  <unnamed type> _7;
  unsigned char _8;
  long unsigned int _9;
  const uint8[3] * _10;
  long unsigned int _17;
  long unsigned int _31;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG Status => 0
  # DEBUG BEGIN_STMT
  # DEBUG Mcr => 0
  # DEBUG BEGIN_STMT
  AdcBasePtr_15 = Adc_Sar_Ip_apxAdcBase[u32Instance_14(D)];
  # DEBUG AdcBasePtr => AdcBasePtr_15
  # DEBUG BEGIN_STMT
  _1 = pConfig_16(D)->ClkSelect;
  # DEBUG ClockSel => _1
  # DEBUG INLINE_ENTRY Adc_Sar_GetADCLKSELValue
  # DEBUG BEGIN_STMT
  _17 = _1 << 1;
  _31 = _17 & 6;
  # DEBUG ClockSel => NULL
  # DEBUG Mcr => _31
  # DEBUG BEGIN_STMT
  Status_19 = Adc_Sar_Ip_Powerdown (u32Instance_14(D));
  # DEBUG Status => Status_19
  # DEBUG BEGIN_STMT
  if (Status_19 == 0)
    goto <bb 3>; [33.00%]
  else
    goto <bb 5>; [67.00%]

  <bb 3> [local count: 354334800]:
  # DEBUG BEGIN_STMT
  SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_15 ();
  # DEBUG BEGIN_STMT
  _2 ={v} AdcBasePtr_15->MCR;
  _3 = _2 & 4294967289;
  _4 = _3 | _31;
  AdcBasePtr_15->MCR ={v} _4;
  # DEBUG BEGIN_STMT
  SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_15 ();
  # DEBUG BEGIN_STMT
  Status_24 = Adc_Sar_Ip_Powerup (u32Instance_14(D));
  # DEBUG Status => Status_24
  # DEBUG BEGIN_STMT
  if (Status_24 == 0)
    goto <bb 4>; [33.00%]
  else
    goto <bb 5>; [67.00%]

  <bb 4> [local count: 116930483]:
  # DEBUG BEGIN_STMT
  SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_51 ();
  # DEBUG BEGIN_STMT
  _5 = pConfig_16(D)->HighSpeedConvEn;
  Adc_Sar_EnableHighSpeed (AdcBasePtr_15, _5);
  # DEBUG BEGIN_STMT
  SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_51 ();
  # DEBUG BEGIN_STMT
  _6 = pConfig_16(D)->AvgEn;
  _7 = pConfig_16(D)->AvgSel;
  Adc_Sar_Ip_SetAveraging (u32Instance_14(D), _6, _7);
  # DEBUG BEGIN_STMT
  _8 = pConfig_16(D)->PowerDownDelay;
  _9 = (long unsigned int) _8;
  AdcBasePtr_15->PDEDR ={v} _9;
  # DEBUG BEGIN_STMT
  _10 = &pConfig_16(D)->SampleTimeArr;
  Adc_Sar_Ip_SetSampleTimes (u32Instance_14(D), _10);

  <bb 5> [local count: 1073741824]:
  # Status_11 = PHI <Status_19(2), Status_24(3), 0(4)>
  # DEBUG Status => Status_11
  # DEBUG BEGIN_STMT
  return Status_11;

}



;; Function Adc_Sar_Ip_AbortConversion (Adc_Sar_Ip_AbortConversion, funcdef_no=44, decl_uid=6016, cgraph_uid=45, symbol_order=49)

Modification phase of node Adc_Sar_Ip_AbortConversion/49
Adc_Sar_Ip_AbortConversion (const uint32 u32Instance)
{
  struct ADC_Type * const AdcBasePtr;
  long unsigned int _1;
  long unsigned int _2;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  AdcBasePtr_5 = Adc_Sar_Ip_apxAdcBase[u32Instance_4(D)];
  # DEBUG AdcBasePtr => AdcBasePtr_5
  # DEBUG BEGIN_STMT
  SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_17 ();
  # DEBUG BEGIN_STMT
  _1 ={v} AdcBasePtr_5->MCR;
  _2 = _1 | 64;
  AdcBasePtr_5->MCR ={v} _2;
  # DEBUG BEGIN_STMT
  SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_17 ();
  return;

}



;; Function Adc_Sar_Ip_AbortChain (Adc_Sar_Ip_AbortChain, funcdef_no=45, decl_uid=6020, cgraph_uid=46, symbol_order=50)

Modification phase of node Adc_Sar_Ip_AbortChain/50
Adc_Sar_Ip_AbortChain (const uint32 u32Instance, const boolean bBlocking, const boolean bAllowRestart)
{
  struct ADC_Type * const AdcBasePtr;
  Adc_Sar_Ip_StatusType ReturnStatus;
  uint32 ElapsedTicks;
  uint32 CurrentTicks;
  uint32 TimeoutTicks;
  uint32 MsrStatus;
  long unsigned int _1;
  long unsigned int _2;
  long unsigned int _3;
  long unsigned int _4;
  long unsigned int _5;
  long unsigned int _6;
  long unsigned int _7;
  long unsigned int _30;

  <bb 2> [local count: 229727060]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  TimeoutTicks_16 = OsIf_MicrosToTicks (3000, 0);
  # DEBUG TimeoutTicks => TimeoutTicks_16
  # DEBUG BEGIN_STMT
  _1 = OsIf_GetCounter (0);
  CurrentTicks = _1;
  # DEBUG BEGIN_STMT
  # DEBUG ElapsedTicks => 0
  # DEBUG BEGIN_STMT
  # DEBUG ReturnStatus => 0
  # DEBUG BEGIN_STMT
  AdcBasePtr_20 = Adc_Sar_Ip_apxAdcBase[u32Instance_19(D)];
  # DEBUG AdcBasePtr => AdcBasePtr_20
  # DEBUG BEGIN_STMT
  SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_18 ();
  # DEBUG BEGIN_STMT
  if (bAllowRestart_22(D) != 0)
    goto <bb 4>; [50.00%]
  else
    goto <bb 3>; [50.00%]

  <bb 3> [local count: 114863530]:
  # DEBUG BEGIN_STMT
  _2 ={v} AdcBasePtr_20->MCR;
  _3 = _2 & 4278190079;
  AdcBasePtr_20->MCR ={v} _3;

  <bb 4> [local count: 229727060]:
  # DEBUG BEGIN_STMT
  _4 ={v} AdcBasePtr_20->MCR;
  _5 = _4 | 128;
  AdcBasePtr_20->MCR ={v} _5;
  # DEBUG BEGIN_STMT
  SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_18 ();
  # DEBUG BEGIN_STMT
  if (bBlocking_26(D) != 0)
    goto <bb 5>; [50.00%]
  else
    goto <bb 11>; [50.00%]

  <bb 5> [local count: 114863530]:
  # DEBUG BEGIN_STMT
  _6 ={v} AdcBasePtr_20->MSR;
  MsrStatus_27 = _6 & 16777216;
  # DEBUG MsrStatus => MsrStatus_27
  # DEBUG BEGIN_STMT
  goto <bb 7>; [100.00%]

  <bb 6> [local count: 958878296]:
  # DEBUG BEGIN_STMT
  _7 ={v} AdcBasePtr_20->MSR;
  MsrStatus_28 = _7 & 16777216;
  # DEBUG MsrStatus => MsrStatus_28
  # DEBUG BEGIN_STMT
  _30 = OsIf_GetElapsed (&CurrentTicks, 0);
  ElapsedTicks_31 = ElapsedTicks_9 + _30;
  # DEBUG ElapsedTicks => ElapsedTicks_31

  <bb 7> [local count: 1073741824]:
  # MsrStatus_8 = PHI <MsrStatus_27(5), MsrStatus_28(6)>
  # ElapsedTicks_9 = PHI <0(5), ElapsedTicks_31(6)>
  # DEBUG ElapsedTicks => ElapsedTicks_9
  # DEBUG MsrStatus => MsrStatus_8
  # DEBUG BEGIN_STMT
  if (MsrStatus_8 == 16777216)
    goto <bb 8>; [94.50%]
  else
    goto <bb 9>; [5.50%]

  <bb 8> [local count: 1014686026]:
  if (ElapsedTicks_9 < TimeoutTicks_16)
    goto <bb 6>; [94.50%]
  else
    goto <bb 9>; [5.50%]

  <bb 9> [local count: 114863531]:
  # ElapsedTicks_32 = PHI <ElapsedTicks_9(7), ElapsedTicks_9(8)>
  # DEBUG BEGIN_STMT
  if (TimeoutTicks_16 <= ElapsedTicks_32)
    goto <bb 10>; [35.00%]
  else
    goto <bb 11>; [65.00%]

  <bb 10> [local count: 40202236]:
  # DEBUG BEGIN_STMT
  # DEBUG ReturnStatus => 2

  <bb 11> [local count: 229727061]:
  # ReturnStatus_10 = PHI <0(4), 0(9), 2(10)>
  # DEBUG ReturnStatus => ReturnStatus_10
  # DEBUG BEGIN_STMT
  CurrentTicks ={v} {CLOBBER};
  return ReturnStatus_10;

}



;; Function Adc_Sar_Ip_SetPresamplingSource (Adc_Sar_Ip_SetPresamplingSource, funcdef_no=46, decl_uid=6024, cgraph_uid=47, symbol_order=51)

Modification phase of node Adc_Sar_Ip_SetPresamplingSource/51
Adc_Sar_Ip_SetPresamplingSource (const uint32 u32Instance, const Adc_Sar_Ip_ChanGroupType pChanGroup, const Adc_Sar_Ip_PresamplingSourceType pPresampleSource)
{
  long unsigned int _1;
  long unsigned int _2;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = Adc_Sar_Ip_au32AdcFeatureBitmap[u32Instance_4(D)];
  _2 = _1 & 2;
  if (_2 != 0)
    goto <bb 3>; [33.00%]
  else
    goto <bb 4>; [67.00%]

  <bb 3> [local count: 354334800]:
  Adc_Sar_Ip_SetPresamplingSource.part.0 (u32Instance_4(D), pChanGroup_5(D), pPresampleSource_6(D));

  <bb 4> [local count: 1073741824]:
  return;

}



;; Function Adc_Sar_Ip_Init (Adc_Sar_Ip_Init, funcdef_no=22, decl_uid=5947, cgraph_uid=23, symbol_order=27)

Modification phase of node Adc_Sar_Ip_Init/27
Adc_Sar_Ip_Init (const uint32 u32Instance, const struct Adc_Sar_Ip_ConfigType * const pConfig)
{
  struct ADC_Type * const AdcBasePtr;
  Adc_Sar_Ip_StatusType Status;
  long unsigned int _1;
  long unsigned int _2;
  long unsigned int _3;
  long unsigned int _4;
  <unnamed type> _5;
  <unnamed type> _6;
  long unsigned int _7;
  long unsigned int _8;
  _Bool _9;
  const uint8[3] * _10;
  unsigned char _11;
  long unsigned int _12;
  long unsigned int _13;
  long unsigned int _14;
  short unsigned int _15;
  long unsigned int _16;
  const uint32[3] * _17;
  const uint32[3] * _18;
  <unnamed type> _19;
  long unsigned int _20;
  long unsigned int _21;
  _Bool _22;
  long unsigned int _23;
  <unnamed type> _24;
  long unsigned int _25;
  long unsigned int _26;
  long unsigned int _27;
  long unsigned int _28;
  const struct Adc_Sar_Ip_ChanConfigType * _29;
  unsigned char _30;
  long unsigned int _31;
  long unsigned int _32;
  long unsigned int _33;
  _Bool _34;
  long unsigned int _35;
  <unnamed type> _36;
  <unnamed type> _37;
  <unnamed type> _38;
  void (*<T532>) (void) _39;
  void (*<T532>) (void) _40;
  void (*<T532>) (void) _41;
  _Bool _42;
  <unnamed type> _43;
  unsigned char _44;
  long unsigned int _45;
  short unsigned int _46;
  long unsigned int _47;
  long unsigned int _48;
  long unsigned int _49;
  long unsigned int _50;
  long unsigned int iftmp.1_52;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG Status => 0
  # DEBUG BEGIN_STMT
  AdcBasePtr_60 = Adc_Sar_Ip_apxAdcBase[u32Instance_59(D)];
  # DEBUG AdcBasePtr => AdcBasePtr_60
  # DEBUG BEGIN_STMT
  Adc_Sar_Ip_AbortChain (u32Instance_59(D), 1, 0);
  # DEBUG BEGIN_STMT
  _1 ={v} AdcBasePtr_60->MCR;
  _2 = _1 & 4294836223;
  AdcBasePtr_60->MCR ={v} _2;
  # DEBUG BEGIN_STMT
  Status_64 = Adc_Sar_Ip_Powerdown (u32Instance_59(D));
  # DEBUG Status => Status_64
  # DEBUG BEGIN_STMT
  if (Status_64 == 0)
    goto <bb 3>; [33.00%]
  else
    goto <bb 16>; [67.00%]

  <bb 3> [local count: 354334800]:
  # DEBUG BEGIN_STMT
  _3 ={v} AdcBasePtr_60->MCR;
  _4 = Adc_Sar_CollectMcrMasks (u32Instance_59(D), pConfig_65(D), _3);
  AdcBasePtr_60->MCR ={v} _4;
  # DEBUG BEGIN_STMT
  _5 = pConfig_65(D)->DataAlign;
  Adc_Sar_Ip_axAdcSarState[u32Instance_59(D)].DataAlign = _5;
  # DEBUG BEGIN_STMT
  Status_69 = Adc_Sar_Ip_Powerup (u32Instance_59(D));
  # DEBUG Status => Status_69
  # DEBUG BEGIN_STMT
  if (Status_69 == 0)
    goto <bb 4>; [50.00%]
  else
    goto <bb 16>; [50.00%]

  <bb 4> [local count: 177167400]:
  # DEBUG BEGIN_STMT
  _6 = pConfig_65(D)->CtuMode;
  if (_6 == 2)
    goto <bb 5>; [34.00%]
  else
    goto <bb 6>; [66.00%]

  <bb 5> [local count: 60236917]:
  # DEBUG BEGIN_STMT
  _7 ={v} AdcBasePtr_60->MCR;
  _8 = _7 | 65536;
  AdcBasePtr_60->MCR ={v} _8;

  <bb 6> [local count: 177167400]:
  # DEBUG BEGIN_STMT
  _9 = pConfig_65(D)->HighSpeedConvEn;
  Adc_Sar_EnableHighSpeed (AdcBasePtr_60, _9);
  # DEBUG BEGIN_STMT
  _10 = &pConfig_65(D)->SampleTimeArr;
  Adc_Sar_Ip_SetSampleTimes (u32Instance_59(D), _10);
  # DEBUG BEGIN_STMT
  _11 = pConfig_65(D)->PowerDownDelay;
  _12 = (long unsigned int) _11;
  AdcBasePtr_60->PDEDR ={v} _12;
  # DEBUG BEGIN_STMT
  _13 = Adc_Sar_Ip_au32AdcFeatureBitmap[u32Instance_59(D)];
  _14 = _13 & 1;
  if (_14 != 0)
    goto <bb 7>; [50.00%]
  else
    goto <bb 8>; [50.00%]

  <bb 7> [local count: 88583700]:
  # DEBUG BEGIN_STMT
  _15 = pConfig_65(D)->DecodeDelay;
  _16 = (long unsigned int) _15;
  AdcBasePtr_60->DSDR ={v} _16;

  <bb 8> [local count: 177167400]:
  # DEBUG BEGIN_STMT
  _17 = &pConfig_65(D)->ChanMaskNormal;
  Adc_Sar_SetNormalChain (u32Instance_59(D), _17);
  # DEBUG BEGIN_STMT
  _18 = &pConfig_65(D)->ChanMaskInjected;
  Adc_Sar_SetInjectedChain (u32Instance_59(D), _18);
  # DEBUG BEGIN_STMT
  _19 = pConfig_65(D)->AdcResolution;
  Adc_Sar_Ip_SetResolution (u32Instance_59(D), _19);
  # DEBUG BEGIN_STMT
  _20 ={v} AdcBasePtr_60->DMAE;
  _21 = _20 & 4294967292;
  AdcBasePtr_60->DMAE ={v} _21;
  # DEBUG BEGIN_STMT
  _22 = pConfig_65(D)->DmaEnable;
  if (_22 != 0)
    goto <bb 9>; [50.00%]
  else
    goto <bb 10>; [50.00%]

  <bb 9> [local count: 88583700]:
  # DEBUG BEGIN_STMT
  _23 ={v} AdcBasePtr_60->DMAE;
  _24 = pConfig_65(D)->DmaClearSource;
  _25 = _24 << 1;
  _26 = _25 & 2;
  _27 = _23 | _26;
  _28 = _27 | 1;
  AdcBasePtr_60->DMAE ={v} _28;

  <bb 10> [local count: 177167400]:
  # DEBUG BEGIN_STMT
  _29 = pConfig_65(D)->ChannelConfigsPtr;
  if (_29 != 0B)
    goto <bb 11>; [70.00%]
  else
    goto <bb 13>; [30.00%]

  <bb 11> [local count: 124017181]:
  _30 = pConfig_65(D)->NumChannels;
  if (_30 != 0)
    goto <bb 12>; [33.00%]
  else
    goto <bb 13>; [67.00%]

  <bb 12> [local count: 40925669]:
  # DEBUG BEGIN_STMT
  Adc_Sar_ConfigChannels (u32Instance_59(D), _29, _30);

  <bb 13> [local count: 177167400]:
  # DEBUG BEGIN_STMT
  _31 ={v} AdcBasePtr_60->PSCR;
  _32 = _31 & 4294967294;
  AdcBasePtr_60->PSCR ={v} _32;
  # DEBUG BEGIN_STMT
  _33 ={v} AdcBasePtr_60->PSCR;
  _34 = pConfig_65(D)->BypassSampling;
  if (_34 != 0)
    goto <bb 15>; [50.00%]
  else
    goto <bb 14>; [50.00%]

  <bb 14> [local count: 88583700]:

  <bb 15> [local count: 177167400]:
  # iftmp.1_52 = PHI <1(13), 0(14)>
  _35 = _33 | iftmp.1_52;
  AdcBasePtr_60->PSCR ={v} _35;
  # DEBUG BEGIN_STMT
  _36 = pConfig_65(D)->PresamplingSourceArr[0];
  Adc_Sar_Ip_SetPresamplingSource (u32Instance_59(D), 0, _36);
  # DEBUG BEGIN_STMT
  _37 = pConfig_65(D)->PresamplingSourceArr[1];
  Adc_Sar_Ip_SetPresamplingSource (u32Instance_59(D), 1, _37);
  # DEBUG BEGIN_STMT
  _38 = pConfig_65(D)->PresamplingSourceArr[2];
  Adc_Sar_Ip_SetPresamplingSource (u32Instance_59(D), 2, _38);
  # DEBUG BEGIN_STMT
  _39 = pConfig_65(D)->EndOfNormalChainNotification;
  Adc_Sar_Ip_axAdcSarState[u32Instance_59(D)].EndOfNormalChainNotification = _39;
  # DEBUG BEGIN_STMT
  _40 = pConfig_65(D)->EndOfInjectedChainNotification;
  Adc_Sar_Ip_axAdcSarState[u32Instance_59(D)].EndOfInjectedChainNotification = _40;
  # DEBUG BEGIN_STMT
  _41 = pConfig_65(D)->EndOfCtuConversionNotification;
  Adc_Sar_Ip_axAdcSarState[u32Instance_59(D)].EndOfCtuConversionNotification = _41;
  # DEBUG BEGIN_STMT
  _42 = pConfig_65(D)->BypassResolution;
  Adc_Sar_Ip_axAdcSarState[u32Instance_59(D)].BypassResolution = _42;
  # DEBUG BEGIN_STMT
  _43 = pConfig_65(D)->CalibrationClkSelect;
  Adc_Sar_Ip_axAdcSarState[u32Instance_59(D)].CalibrationClkSelect = _43;
  # DEBUG BEGIN_STMT
  _44 = pConfig_65(D)->UsrOffset;
  _45 = (long unsigned int) _44;
  _46 = pConfig_65(D)->UsrGain;
  _47 = (long unsigned int) _46;
  _48 = _47 << 16;
  _49 = _48 & 67043328;
  _50 = _45 | _49;
  AdcBasePtr_60->OFSGNUSR ={v} _50;
  # DEBUG BEGIN_STMT
  Adc_Sar_Ip_axAdcSarState[u32Instance_59(D)].InitStatus = 1;

  <bb 16> [local count: 1073741824]:
  # Status_51 = PHI <Status_64(2), Status_69(3), 0(15)>
  # DEBUG Status => Status_51
  # DEBUG BEGIN_STMT
  return Status_51;

}



;; Function Adc_Sar_Ip_Deinit (Adc_Sar_Ip_Deinit, funcdef_no=23, decl_uid=5949, cgraph_uid=24, symbol_order=28)

Modification phase of node Adc_Sar_Ip_Deinit/28
Adc_Sar_Ip_Deinit (const uint32 u32Instance)
{
  struct ADC_Type * const AdcBasePtr;
  Adc_Sar_Ip_StatusType Status;
  struct Adc_Sar_Ip_ConfigType DefaultConfig;
  uint32 Index;
  unsigned char _1;
  long unsigned int _2;
  volatile uint32_t * _3;
  long unsigned int _4;
  volatile uint32_t * _5;
  volatile uint32_t * _6;
  volatile uint32_t * _7;
  volatile uint32_t * _8;
  volatile uint32_t * _9;
  volatile uint32_t * _10;
  volatile uint32_t * _11;
  long unsigned int _12;

  <bb 2> [local count: 268435456]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  AdcBasePtr_21 = Adc_Sar_Ip_apxAdcBase[u32Instance_20(D)];
  # DEBUG AdcBasePtr => AdcBasePtr_21
  # DEBUG BEGIN_STMT
  DefaultConfig.ConvMode = 0;
  # DEBUG BEGIN_STMT
  DefaultConfig.ClkSelect = 0;
  # DEBUG BEGIN_STMT
  DefaultConfig.CalibrationClkSelect = 1;
  # DEBUG BEGIN_STMT
  DefaultConfig.HighSpeedConvEn = 0;
  # DEBUG BEGIN_STMT
  DefaultConfig.CtuMode = 0;
  # DEBUG BEGIN_STMT
  DefaultConfig.InjectedEdge = 0;
  # DEBUG BEGIN_STMT
  DefaultConfig.ExtTrigger = 0;
  # DEBUG BEGIN_STMT
  DefaultConfig.NormalExtTrgEn = 0;
  # DEBUG BEGIN_STMT
  DefaultConfig.NormalAuxExtTrgEn = 0;
  # DEBUG BEGIN_STMT
  # DEBUG Index => 0
  goto <bb 4>; [100.00%]

  <bb 3> [local count: 805306369]:
  # DEBUG BEGIN_STMT
  DefaultConfig.SampleTimeArr[Index_13] = 22;
  # DEBUG BEGIN_STMT
  DefaultConfig.PresamplingSourceArr[Index_13] = 0;
  # DEBUG BEGIN_STMT
  Index_65 = Index_13 + 1;
  # DEBUG Index => Index_65

  <bb 4> [local count: 1073741824]:
  # Index_13 = PHI <0(2), Index_65(3)>
  # DEBUG Index => Index_13
  # DEBUG BEGIN_STMT
  _1 = Adc_Sar_Ip_au8AdcGroupCount[u32Instance_20(D)];
  _2 = (long unsigned int) _1;
  if (_2 > Index_13)
    goto <bb 3>; [75.00%]
  else
    goto <bb 5>; [25.00%]

  <bb 5> [local count: 268435456]:
  # _12 = PHI <_2(4)>
  # DEBUG BEGIN_STMT
  DefaultConfig.BypassSampling = 0;
  # DEBUG BEGIN_STMT
  DefaultConfig.AutoClockOff = 0;
  # DEBUG BEGIN_STMT
  DefaultConfig.OverwriteEnable = 0;
  # DEBUG BEGIN_STMT
  DefaultConfig.DataAlign = 0;
  # DEBUG BEGIN_STMT
  DefaultConfig.DecodeDelay = 0;
  # DEBUG BEGIN_STMT
  DefaultConfig.PowerDownDelay = 0;
  # DEBUG BEGIN_STMT
  DefaultConfig.AvgEn = 0;
  # DEBUG BEGIN_STMT
  DefaultConfig.AvgSel = 0;
  # DEBUG BEGIN_STMT
  DefaultConfig.UsrOffset = 0;
  # DEBUG BEGIN_STMT
  DefaultConfig.UsrGain = 0;
  # DEBUG BEGIN_STMT
  DefaultConfig.DmaEnable = 0;
  # DEBUG BEGIN_STMT
  DefaultConfig.DmaClearSource = 0;
  # DEBUG BEGIN_STMT
  DefaultConfig.NumChannels = 0;
  # DEBUG BEGIN_STMT
  DefaultConfig.ChannelConfigsPtr = 0B;
  # DEBUG BEGIN_STMT
  DefaultConfig.EndOfNormalChainNotification = 0B;
  # DEBUG BEGIN_STMT
  DefaultConfig.EndOfInjectedChainNotification = 0B;
  # DEBUG BEGIN_STMT
  DefaultConfig.EndOfCtuConversionNotification = 0B;
  # DEBUG BEGIN_STMT
  Status_49 = Adc_Sar_Ip_Init (u32Instance_20(D), &DefaultConfig);
  # DEBUG Status => Status_49
  # DEBUG BEGIN_STMT
  if (Status_49 == 0)
    goto <bb 10>; [50.00%]
  else
    goto <bb 9>; [50.00%]

  <bb 10> [local count: 134217728]:
  goto <bb 7>; [100.00%]

  <bb 6> [local count: 402653184]:
  # DEBUG BEGIN_STMT
  _3 = &AdcBasePtr_21->CIMR0;
  _4 = Index_14 * 4;
  _5 = _3 + _4;
  MEM[(volatile uint32 *)_5] ={v} 0;
  # DEBUG BEGIN_STMT
  _6 = &AdcBasePtr_21->CEOCFR0;
  _7 = _6 + _4;
  MEM[(volatile uint32 *)_7] ={v} 4294967295;
  # DEBUG BEGIN_STMT
  _8 = &AdcBasePtr_21->DMAR0;
  _9 = _8 + _4;
  MEM[(volatile uint32 *)_9] ={v} 0;
  # DEBUG BEGIN_STMT
  _10 = &AdcBasePtr_21->PSR0;
  _11 = _10 + _4;
  MEM[(volatile uint32 *)_11] ={v} 0;
  # DEBUG BEGIN_STMT
  Index_61 = Index_14 + 1;
  # DEBUG Index => Index_61

  <bb 7> [local count: 536870913]:
  # Index_14 = PHI <Index_61(6), 0(10)>
  # DEBUG Index => Index_14
  # DEBUG BEGIN_STMT
  if (_12 > Index_14)
    goto <bb 6>; [75.00%]
  else
    goto <bb 8>; [25.00%]

  <bb 8> [local count: 134217728]:
  # DEBUG BEGIN_STMT
  Adc_Sar_ResetWdog (u32Instance_20(D));
  # DEBUG BEGIN_STMT
  AdcBasePtr_21->WTIMR ={v} 0;
  # DEBUG BEGIN_STMT
  Adc_Sar_Ip_ClearStatusFlags (u32Instance_20(D), 31);
  # DEBUG BEGIN_STMT
  Adc_Sar_Ip_SetResolution (u32Instance_20(D), 1);
  # DEBUG BEGIN_STMT
  Adc_Sar_Ip_axAdcSarState[u32Instance_20(D)].InitStatus = 0;
  # DEBUG BEGIN_STMT
  Status_56 = Adc_Sar_Ip_Powerdown (u32Instance_20(D));
  # DEBUG Status => Status_56

  <bb 9> [local count: 268435456]:
  # Status_15 = PHI <Status_49(5), Status_56(8)>
  # DEBUG Status => Status_15
  # DEBUG BEGIN_STMT
  DefaultConfig ={v} {CLOBBER};
  return Status_15;

}



;; Function Adc_Sar_Ip_EnableChannelPresampling (Adc_Sar_Ip_EnableChannelPresampling, funcdef_no=47, decl_uid=6027, cgraph_uid=48, symbol_order=52)

Modification phase of node Adc_Sar_Ip_EnableChannelPresampling/52
Adc_Sar_Ip_EnableChannelPresampling (const uint32 u32Instance, const uint32 u32ChnIdx)
{
  struct ADC_Type * const AdcBasePtr;
  uint32 VectBit;
  uint32 VectAdr;
  long unsigned int _1;
  long unsigned int _2;
  volatile uint32_t * _3;
  long unsigned int _4;
  volatile uint32_t * _5;
  long unsigned int _6;
  long unsigned int _7;
  long unsigned int _8;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = Adc_Sar_Ip_au32AdcFeatureBitmap[u32Instance_11(D)];
  _2 = _1 & 2;
  if (_2 != 0)
    goto <bb 3>; [33.00%]
  else
    goto <bb 4>; [67.00%]

  <bb 3> [local count: 354334800]:
  # DEBUG BEGIN_STMT
  AdcBasePtr_12 = Adc_Sar_Ip_apxAdcBase[u32Instance_11(D)];
  # DEBUG AdcBasePtr => AdcBasePtr_12
  # DEBUG BEGIN_STMT
  VectAdr_14 = u32ChnIdx_13(D) >> 5;
  # DEBUG VectAdr => VectAdr_14
  # DEBUG BEGIN_STMT
  VectBit_15 = u32ChnIdx_13(D) & 31;
  # DEBUG VectBit => VectBit_15
  # DEBUG BEGIN_STMT
  SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_41 ();
  # DEBUG BEGIN_STMT
  _3 = &AdcBasePtr_12->PSR0;
  _4 = VectAdr_14 * 4;
  _5 = _3 + _4;
  _6 ={v} MEM[(volatile uint32 *)_5];
  _7 = 1 << VectBit_15;
  _8 = _6 | _7;
  MEM[(volatile uint32 *)_5] ={v} _8;
  # DEBUG BEGIN_STMT
  SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_41 ();

  <bb 4> [local count: 1073741824]:
  return;

}



;; Function Adc_Sar_Ip_DisableChannelPresampling (Adc_Sar_Ip_DisableChannelPresampling, funcdef_no=48, decl_uid=6030, cgraph_uid=49, symbol_order=53)

Modification phase of node Adc_Sar_Ip_DisableChannelPresampling/53
Adc_Sar_Ip_DisableChannelPresampling (const uint32 u32Instance, const uint32 u32ChnIdx)
{
  struct ADC_Type * const AdcBasePtr;
  uint32 VectBit;
  uint32 VectAdr;
  long unsigned int _1;
  long unsigned int _2;
  volatile uint32_t * _3;
  long unsigned int _4;
  volatile uint32_t * _5;
  long unsigned int _6;
  long unsigned int _7;
  long unsigned int _8;
  long unsigned int _9;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = Adc_Sar_Ip_au32AdcFeatureBitmap[u32Instance_12(D)];
  _2 = _1 & 2;
  if (_2 != 0)
    goto <bb 3>; [33.00%]
  else
    goto <bb 4>; [67.00%]

  <bb 3> [local count: 354334800]:
  # DEBUG BEGIN_STMT
  AdcBasePtr_13 = Adc_Sar_Ip_apxAdcBase[u32Instance_12(D)];
  # DEBUG AdcBasePtr => AdcBasePtr_13
  # DEBUG BEGIN_STMT
  VectAdr_15 = u32ChnIdx_14(D) >> 5;
  # DEBUG VectAdr => VectAdr_15
  # DEBUG BEGIN_STMT
  VectBit_16 = u32ChnIdx_14(D) & 31;
  # DEBUG VectBit => VectBit_16
  # DEBUG BEGIN_STMT
  SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_42 ();
  # DEBUG BEGIN_STMT
  _3 = &AdcBasePtr_13->PSR0;
  _4 = VectAdr_15 * 4;
  _5 = _3 + _4;
  _6 ={v} MEM[(volatile uint32 *)_5];
  _7 = 1 << VectBit_16;
  _8 = ~_7;
  _9 = _6 & _8;
  MEM[(volatile uint32 *)_5] ={v} _9;
  # DEBUG BEGIN_STMT
  SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_42 ();

  <bb 4> [local count: 1073741824]:
  return;

}



;; Function Adc_Sar_Ip_EnablePresampleConversion (Adc_Sar_Ip_EnablePresampleConversion, funcdef_no=49, decl_uid=6032, cgraph_uid=50, symbol_order=54)

Modification phase of node Adc_Sar_Ip_EnablePresampleConversion/54
Adc_Sar_Ip_EnablePresampleConversion (const uint32 u32Instance)
{
  struct ADC_Type * const AdcBasePtr;
  long unsigned int _1;
  long unsigned int _2;
  long unsigned int _3;
  long unsigned int _4;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  _1 = Adc_Sar_Ip_au32AdcFeatureBitmap[u32Instance_7(D)];
  _2 = _1 & 2;
  if (_2 != 0)
    goto <bb 3>; [33.00%]
  else
    goto <bb 4>; [67.00%]

  <bb 3> [local count: 354334800]:
  # DEBUG BEGIN_STMT
  AdcBasePtr_8 = Adc_Sar_Ip_apxAdcBase[u32Instance_7(D)];
  # DEBUG AdcBasePtr => AdcBasePtr_8
  # DEBUG BEGIN_STMT
  SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_39 ();
  # DEBUG BEGIN_STMT
  _3 ={v} AdcBasePtr_8->PSCR;
  _4 = _3 | 1;
  AdcBasePtr_8->PSCR ={v} _4;
  # DEBUG BEGIN_STMT
  SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_39 ();

  <bb 4> [local count: 1073741824]:
  return;

}



;; Function Adc_Sar_Ip_DisablePresampleConversion (Adc_Sar_Ip_DisablePresampleConversion, funcdef_no=50, decl_uid=6034, cgraph_uid=51, symbol_order=55)

Modification phase of node Adc_Sar_Ip_DisablePresampleConversion/55
Adc_Sar_Ip_DisablePresampleConversion (const uint32 u32Instance)
{
  struct ADC_Type * const AdcBasePtr;
  long unsigned int _1;
  long unsigned int _2;
  long unsigned int _3;
  long unsigned int _4;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  _1 = Adc_Sar_Ip_au32AdcFeatureBitmap[u32Instance_7(D)];
  _2 = _1 & 2;
  if (_2 != 0)
    goto <bb 3>; [33.00%]
  else
    goto <bb 4>; [67.00%]

  <bb 3> [local count: 354334800]:
  # DEBUG BEGIN_STMT
  AdcBasePtr_8 = Adc_Sar_Ip_apxAdcBase[u32Instance_7(D)];
  # DEBUG AdcBasePtr => AdcBasePtr_8
  # DEBUG BEGIN_STMT
  SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_40 ();
  # DEBUG BEGIN_STMT
  _3 ={v} AdcBasePtr_8->PSCR;
  _4 = _3 & 4294967294;
  AdcBasePtr_8->PSCR ={v} _4;
  # DEBUG BEGIN_STMT
  SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_40 ();

  <bb 4> [local count: 1073741824]:
  return;

}



;; Function Adc_Sar_Ip_EnableDma (Adc_Sar_Ip_EnableDma, funcdef_no=51, decl_uid=6036, cgraph_uid=52, symbol_order=56)

Modification phase of node Adc_Sar_Ip_EnableDma/56
Adc_Sar_Ip_EnableDma (const uint32 u32Instance)
{
  struct ADC_Type * const AdcBasePtr;
  long unsigned int _1;
  long unsigned int _2;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  AdcBasePtr_5 = Adc_Sar_Ip_apxAdcBase[u32Instance_4(D)];
  # DEBUG AdcBasePtr => AdcBasePtr_5
  # DEBUG BEGIN_STMT
  SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_43 ();
  # DEBUG BEGIN_STMT
  _1 ={v} AdcBasePtr_5->DMAE;
  _2 = _1 | 1;
  AdcBasePtr_5->DMAE ={v} _2;
  # DEBUG BEGIN_STMT
  SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_43 ();
  return;

}



;; Function Adc_Sar_Ip_DisableDma (Adc_Sar_Ip_DisableDma, funcdef_no=52, decl_uid=6038, cgraph_uid=53, symbol_order=57)

Modification phase of node Adc_Sar_Ip_DisableDma/57
Adc_Sar_Ip_DisableDma (const uint32 u32Instance)
{
  struct ADC_Type * const AdcBasePtr;
  long unsigned int _1;
  long unsigned int _2;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  AdcBasePtr_5 = Adc_Sar_Ip_apxAdcBase[u32Instance_4(D)];
  # DEBUG AdcBasePtr => AdcBasePtr_5
  # DEBUG BEGIN_STMT
  SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_44 ();
  # DEBUG BEGIN_STMT
  _1 ={v} AdcBasePtr_5->DMAE;
  _2 = _1 & 4294967294;
  AdcBasePtr_5->DMAE ={v} _2;
  # DEBUG BEGIN_STMT
  SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_44 ();
  return;

}



;; Function Adc_Sar_Ip_EnableChannelDma (Adc_Sar_Ip_EnableChannelDma, funcdef_no=53, decl_uid=6041, cgraph_uid=54, symbol_order=58)

Modification phase of node Adc_Sar_Ip_EnableChannelDma/58
Adc_Sar_Ip_EnableChannelDma (const uint32 u32Instance, const uint32 u32ChnIdx)
{
  struct ADC_Type * const AdcBasePtr;
  uint32 VectBit;
  uint32 VectAdr;
  volatile uint32_t * _1;
  long unsigned int _2;
  volatile uint32_t * _3;
  long unsigned int _4;
  long unsigned int _5;
  long unsigned int _6;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  AdcBasePtr_9 = Adc_Sar_Ip_apxAdcBase[u32Instance_8(D)];
  # DEBUG AdcBasePtr => AdcBasePtr_9
  # DEBUG BEGIN_STMT
  VectAdr_11 = u32ChnIdx_10(D) >> 5;
  # DEBUG VectAdr => VectAdr_11
  # DEBUG BEGIN_STMT
  VectBit_12 = u32ChnIdx_10(D) & 31;
  # DEBUG VectBit => VectBit_12
  # DEBUG BEGIN_STMT
  SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_46 ();
  # DEBUG BEGIN_STMT
  _1 = &AdcBasePtr_9->DMAR0;
  _2 = VectAdr_11 * 4;
  _3 = _1 + _2;
  _4 ={v} MEM[(volatile uint32 *)_3];
  _5 = 1 << VectBit_12;
  _6 = _4 | _5;
  MEM[(volatile uint32 *)_3] ={v} _6;
  # DEBUG BEGIN_STMT
  SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_46 ();
  return;

}



;; Function Adc_Sar_Ip_DisableChannelDma (Adc_Sar_Ip_DisableChannelDma, funcdef_no=54, decl_uid=6044, cgraph_uid=55, symbol_order=59)

Modification phase of node Adc_Sar_Ip_DisableChannelDma/59
Adc_Sar_Ip_DisableChannelDma (const uint32 u32Instance, const uint32 u32ChnIdx)
{
  struct ADC_Type * const AdcBasePtr;
  uint32 VectBit;
  uint32 VectAdr;
  volatile uint32_t * _1;
  long unsigned int _2;
  volatile uint32_t * _3;
  long unsigned int _4;
  long unsigned int _5;
  long unsigned int _6;
  long unsigned int _7;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  AdcBasePtr_10 = Adc_Sar_Ip_apxAdcBase[u32Instance_9(D)];
  # DEBUG AdcBasePtr => AdcBasePtr_10
  # DEBUG BEGIN_STMT
  VectAdr_12 = u32ChnIdx_11(D) >> 5;
  # DEBUG VectAdr => VectAdr_12
  # DEBUG BEGIN_STMT
  VectBit_13 = u32ChnIdx_11(D) & 31;
  # DEBUG VectBit => VectBit_13
  # DEBUG BEGIN_STMT
  SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_47 ();
  # DEBUG BEGIN_STMT
  _1 = &AdcBasePtr_10->DMAR0;
  _2 = VectAdr_12 * 4;
  _3 = _1 + _2;
  _4 ={v} MEM[(volatile uint32 *)_3];
  _5 = 1 << VectBit_13;
  _6 = ~_5;
  _7 = _4 & _6;
  MEM[(volatile uint32 *)_3] ={v} _7;
  # DEBUG BEGIN_STMT
  SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_47 ();
  return;

}



;; Function Adc_Sar_Ip_DisableChannelDmaAll (Adc_Sar_Ip_DisableChannelDmaAll, funcdef_no=55, decl_uid=6046, cgraph_uid=56, symbol_order=60)

Modification phase of node Adc_Sar_Ip_DisableChannelDmaAll/60
Adc_Sar_Ip_DisableChannelDmaAll (const uint32 u32Instance)
{
  struct ADC_Type * const AdcBasePtr;
  uint8 Index;
  volatile uint32_t * _1;
  unsigned int _2;
  unsigned int _3;
  volatile uint32_t * _4;
  long unsigned int _5;
  int _6;
  long unsigned int _7;
  long unsigned int _8;
  long unsigned int _9;
  unsigned char _10;

  <bb 2> [local count: 118111600]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  AdcBasePtr_15 = Adc_Sar_Ip_apxAdcBase[u32Instance_14(D)];
  # DEBUG AdcBasePtr => AdcBasePtr_15
  # DEBUG BEGIN_STMT
  # DEBUG Index => 0
  goto <bb 4>; [100.00%]

  <bb 3> [local count: 955630225]:
  # DEBUG BEGIN_STMT
  SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_48 ();
  # DEBUG BEGIN_STMT
  _1 = &AdcBasePtr_15->DMAR0;
  _2 = (unsigned int) Index_11;
  _3 = _2 * 4;
  _4 = _1 + _3;
  _5 ={v} MEM[(volatile uint32 *)_4];
  _6 = (int) Index_11;
  _7 = Adc_Sar_Ip_au32AdcChanBitmap[u32Instance_14(D)][_6];
  _8 = ~_7;
  _9 = _5 & _8;
  MEM[(volatile uint32 *)_4] ={v} _9;
  # DEBUG BEGIN_STMT
  SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_48 ();
  # DEBUG BEGIN_STMT
  Index_19 = Index_11 + 1;
  # DEBUG Index => Index_19

  <bb 4> [local count: 1073741824]:
  # Index_11 = PHI <0(2), Index_19(3)>
  # DEBUG Index => Index_11
  # DEBUG BEGIN_STMT
  _10 = Adc_Sar_Ip_au8AdcGroupCount[u32Instance_14(D)];
  if (_10 > Index_11)
    goto <bb 3>; [89.00%]
  else
    goto <bb 5>; [11.00%]

  <bb 5> [local count: 118111600]:
  return;

}



;; Function Adc_Sar_Ip_SetDmaClearSource (Adc_Sar_Ip_SetDmaClearSource, funcdef_no=56, decl_uid=6049, cgraph_uid=57, symbol_order=61)

Modification phase of node Adc_Sar_Ip_SetDmaClearSource/61
Adc_Sar_Ip_SetDmaClearSource (const uint32 u32Instance, const Adc_Sar_Ip_ClearSourceType pDmaClear)
{
  struct ADC_Type * const AdcBasePtr;
  long unsigned int _1;
  long unsigned int _2;
  long unsigned int _3;
  long unsigned int _4;
  long unsigned int _5;
  long unsigned int _6;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  AdcBasePtr_9 = Adc_Sar_Ip_apxAdcBase[u32Instance_8(D)];
  # DEBUG AdcBasePtr => AdcBasePtr_9
  # DEBUG BEGIN_STMT
  SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_45 ();
  # DEBUG BEGIN_STMT
  _1 ={v} AdcBasePtr_9->DMAE;
  _2 = _1 & 4294967293;
  AdcBasePtr_9->DMAE ={v} _2;
  # DEBUG BEGIN_STMT
  _3 ={v} AdcBasePtr_9->DMAE;
  _4 = pDmaClear_12(D) << 1;
  _5 = _4 & 2;
  _6 = _3 | _5;
  AdcBasePtr_9->DMAE ={v} _6;
  # DEBUG BEGIN_STMT
  SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_45 ();
  return;

}



;; Function Adc_Sar_Ip_SetConversionMode (Adc_Sar_Ip_SetConversionMode, funcdef_no=57, decl_uid=6052, cgraph_uid=58, symbol_order=62)

Modification phase of node Adc_Sar_Ip_SetConversionMode/62
Adc_Sar_Ip_SetConversionMode (const uint32 u32Instance, const Adc_Sar_Ip_ConvModeType eConvMode)
{
  struct ADC_Type * const AdcBasePtr;
  long unsigned int _1;
  long unsigned int _2;
  long unsigned int _3;
  long unsigned int _4;

  <bb 2> [local count: 1073741817]:
  # DEBUG BEGIN_STMT
  AdcBasePtr_8 = Adc_Sar_Ip_apxAdcBase[u32Instance_7(D)];
  # DEBUG AdcBasePtr => AdcBasePtr_8
  # DEBUG BEGIN_STMT
  SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_19 ();
  # DEBUG BEGIN_STMT
  switch (eConvMode_10(D)) <default: <L4> [33.33%], case 0: <L0> [33.33%], case 1: <L1> [33.33%]>

  <bb 3> [local count: 357913942]:
<L0>:
  # DEBUG BEGIN_STMT
  _1 ={v} AdcBasePtr_8->MCR;
  _2 = _1 & 3758096383;
  AdcBasePtr_8->MCR ={v} _2;
  # DEBUG BEGIN_STMT
  goto <bb 5>; [100.00%]

  <bb 4> [local count: 357913942]:
<L1>:
  # DEBUG BEGIN_STMT
  _3 ={v} AdcBasePtr_8->MCR;
  _4 = _3 | 536870912;
  AdcBasePtr_8->MCR ={v} _4;
  # DEBUG BEGIN_STMT

  <bb 5> [local count: 1073741824]:
<L4>:
  # DEBUG BEGIN_STMT
  SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_19 ();
  return;

}



;; Function Adc_Sar_Ip_SetCtuMode (Adc_Sar_Ip_SetCtuMode, funcdef_no=58, decl_uid=6055, cgraph_uid=59, symbol_order=63)

Modification phase of node Adc_Sar_Ip_SetCtuMode/63
Adc_Sar_Ip_SetCtuMode (const uint32 u32Instance, const Adc_Sar_Ip_CtuModeType eCtuMode)
{
  struct ADC_Type * const AdcBasePtr;
  Adc_Sar_Ip_StatusType Status;
  long unsigned int _1;
  long unsigned int _2;
  long unsigned int _3;
  long unsigned int _4;
  long unsigned int _5;
  long unsigned int _6;
  long unsigned int _7;
  long unsigned int _8;
  long unsigned int _9;
  long unsigned int _10;
  long unsigned int _11;
  long unsigned int _12;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG Status => 0
  # DEBUG BEGIN_STMT
  AdcBasePtr_19 = Adc_Sar_Ip_apxAdcBase[u32Instance_18(D)];
  # DEBUG AdcBasePtr => AdcBasePtr_19
  # DEBUG BEGIN_STMT
  SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_20 ();
  # DEBUG BEGIN_STMT
  _1 ={v} AdcBasePtr_19->MCR;
  _2 = _1 & 4294836223;
  AdcBasePtr_19->MCR ={v} _2;
  # DEBUG BEGIN_STMT
  SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_20 ();
  # DEBUG BEGIN_STMT
  Status_24 = Adc_Sar_Ip_Powerdown (u32Instance_18(D));
  # DEBUG Status => Status_24
  # DEBUG BEGIN_STMT
  if (Status_24 == 0)
    goto <bb 3>; [50.00%]
  else
    goto <bb 10>; [50.00%]

  <bb 3> [local count: 536870913]:
  # DEBUG BEGIN_STMT
  _3 = Adc_Sar_Ip_au32AdcFeatureBitmap[u32Instance_18(D)];
  _4 = _3 & 4;
  if (_4 != 0)
    goto <bb 4>; [33.00%]
  else
    goto <bb 9>; [67.00%]

  <bb 4> [local count: 177167400]:
  # DEBUG BEGIN_STMT
  SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_20 ();
  # DEBUG BEGIN_STMT
  switch (eCtuMode_26(D)) <default: <L10> [25.00%], case 0: <L4> [25.00%], case 1: <L2> [25.00%], case 2: <L3> [25.00%]>

  <bb 5> [local count: 44291850]:
<L2>:
  # DEBUG BEGIN_STMT
  _5 ={v} AdcBasePtr_19->MCR;
  _6 = _5 & 4294901759;
  AdcBasePtr_19->MCR ={v} _6;
  # DEBUG BEGIN_STMT
  _7 ={v} AdcBasePtr_19->MCR;
  _8 = _7 | 131072;
  AdcBasePtr_19->MCR ={v} _8;
  # DEBUG BEGIN_STMT
  goto <bb 8>; [100.00%]

  <bb 6> [local count: 44291850]:
<L3>:
  # DEBUG BEGIN_STMT
  _9 ={v} AdcBasePtr_19->MCR;
  _10 = _9 | 196608;
  AdcBasePtr_19->MCR ={v} _10;
  # DEBUG BEGIN_STMT
  goto <bb 8>; [100.00%]

  <bb 7> [local count: 44291850]:
<L4>:
  # DEBUG BEGIN_STMT
  _11 ={v} AdcBasePtr_19->MCR;
  _12 = _11 & 4294770687;
  AdcBasePtr_19->MCR ={v} _12;
  # DEBUG BEGIN_STMT

  <bb 8> [local count: 177167400]:
<L10>:
  # DEBUG BEGIN_STMT
  SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_20 ();

  <bb 9> [local count: 536870913]:
  # DEBUG BEGIN_STMT
  Status_33 = Adc_Sar_Ip_Powerup (u32Instance_18(D));
  # DEBUG Status => Status_33

  <bb 10> [local count: 1073741824]:
  # Status_13 = PHI <Status_24(2), Status_33(9)>
  # DEBUG Status => Status_13
  # DEBUG BEGIN_STMT
  return Status_13;

}



;; Function Adc_Sar_Ip_SetExternalTrigger (Adc_Sar_Ip_SetExternalTrigger, funcdef_no=59, decl_uid=6059, cgraph_uid=60, symbol_order=64)

Modification phase of node Adc_Sar_Ip_SetExternalTrigger/64
Adc_Sar_Ip_SetExternalTrigger (const uint32 u32Instance, const Adc_Sar_Ip_ExtTriggerEdgeType eTriggerEdge, const Adc_Sar_Ip_ExtTriggerSourceType eTrggerSrc)
{
  <bb 2> [local count: 1073741809]:
  # DEBUG BEGIN_STMT
  switch (eTrggerSrc_2(D)) <default: <L6> [20.00%], case 0: <L0> [20.00%], case 1: <L1> [20.00%], case 2: <L2> [20.00%], case 3: <L3> [20.00%]>

  <bb 3> [local count: 214748365]:
<L0>:
  # DEBUG BEGIN_STMT
  Adc_Sar_ConfigExternalTrigger (u32Instance_4(D), eTriggerEdge_5(D), 67108864, 0, 134217728);
  # DEBUG BEGIN_STMT
  goto <bb 7>; [100.00%]

  <bb 4> [local count: 214748365]:
<L1>:
  # DEBUG BEGIN_STMT
  Adc_Sar_ConfigExternalTrigger (u32Instance_4(D), eTriggerEdge_5(D), 67108864, 0, 33554432);
  # DEBUG BEGIN_STMT
  goto <bb 7>; [100.00%]

  <bb 5> [local count: 214748365]:
<L2>:
  # DEBUG BEGIN_STMT
  Adc_Sar_ConfigExternalTrigger (u32Instance_4(D), eTriggerEdge_5(D), 67108864, 67108864, 167772160);
  # DEBUG BEGIN_STMT
  goto <bb 7>; [100.00%]

  <bb 6> [local count: 214748365]:
<L3>:
  # DEBUG BEGIN_STMT
  Adc_Sar_ConfigExternalTrigger (u32Instance_4(D), eTriggerEdge_5(D), 2097152, 2097152, 4194304);
  # DEBUG BEGIN_STMT

  <bb 7> [local count: 1073741824]:
<L6>:
  return;

}



;; Function Adc_Sar_Ip_GetDataAddress (Adc_Sar_Ip_GetDataAddress, funcdef_no=60, decl_uid=5944, cgraph_uid=61, symbol_order=65)

Modification phase of node Adc_Sar_Ip_GetDataAddress/65
Adc_Sar_Ip_GetDataAddress (uint32 u32Instance, uint32 u32ChannelIndex)
{
  struct ADC_Type * _1;
  const uint32_t * _2;
  long unsigned int _3;
  const uint32_t * _4;
  uint32 _8;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  _1 = Adc_Sar_Ip_apxAdcBase[u32Instance_6(D)];
  _2 = &_1->PCDR[0];
  _3 = u32ChannelIndex_7(D) * 4;
  _4 = _2 + _3;
  _8 = (uint32) _4;
  return _8;

}


