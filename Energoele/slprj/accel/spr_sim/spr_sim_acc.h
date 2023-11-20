#ifndef RTW_HEADER_spr_sim_acc_h_
#define RTW_HEADER_spr_sim_acc_h_
#ifndef spr_sim_acc_COMMON_INCLUDES_
#define spr_sim_acc_COMMON_INCLUDES_
#include <stdlib.h>
#define S_FUNCTION_NAME simulink_only_sfcn
#define S_FUNCTION_LEVEL 2
#ifndef RTW_GENERATED_S_FUNCTION
#define RTW_GENERATED_S_FUNCTION
#endif
#include "sl_AsyncioQueue/AsyncioQueueCAPI.h"
#include "rtwtypes.h"
#include "simstruc.h"
#include "fixedpoint.h"
#endif
#include "spr_sim_acc_types.h"
#include <stddef.h>
#include "rt_nonfinite.h"
#include <string.h>
#include "rtGetInf.h"
#include "rt_defines.h"
#include "simstruc_types.h"
typedef struct { real_T B_2_250_1784 ; real_T B_2_251_1792 ; }
B_Subsystempi2delay_spr_sim_T ; typedef struct { int32_T
Subsystempi2delay_sysIdxToRun ; int8_T Subsystempi2delay_SubsysRanBC ;
boolean_T Subsystempi2delay_MODE ; char_T pad_Subsystempi2delay_MODE [ 2 ] ;
} DW_Subsystempi2delay_spr_sim_T ; typedef struct { real_T B_3_248_1768 ;
real_T B_3_249_1776 ; } B_Subsystem1_spr_sim_T ; typedef struct { int32_T
Subsystem1_sysIdxToRun ; int8_T Subsystem1_SubsysRanBC ; boolean_T
Subsystem1_MODE ; char_T pad_Subsystem1_MODE [ 2 ] ; }
DW_Subsystem1_spr_sim_T ; typedef struct { creal_T B_4_0_0 ; real_T B_15_1_16
; real_T B_15_2_24 [ 3 ] ; real_T B_15_5_48 [ 17 ] ; real_T B_15_22_184 [ 6 ]
; real_T B_15_28_232 ; real_T B_15_29_240 ; real_T B_15_30_248 ; real_T
B_15_31_256 [ 6 ] ; real_T B_15_37_304 ; real_T B_15_38_312 [ 6 ] ; real_T
B_15_44_360 [ 6 ] ; real_T B_15_50_408 [ 6 ] ; real_T B_15_56_456 ; real_T
B_15_57_464 [ 6 ] ; real_T B_15_63_512 ; real_T B_15_64_520 [ 6 ] ; real_T
B_15_70_568 [ 3 ] ; real_T B_15_73_592 ; real_T B_15_74_600 ; real_T
B_15_75_608 ; real_T B_15_76_616 ; real_T B_15_77_624 ; real_T B_15_78_632 ;
real_T B_15_79_640 ; real_T B_15_80_648 ; real_T B_15_81_656 ; real_T
B_15_82_664 ; real_T B_15_83_672 ; real_T B_15_84_680 ; real_T B_15_85_688 ;
real_T B_15_86_696 ; real_T B_15_87_704 ; real_T B_15_88_712 ; real_T
B_15_89_720 ; real_T B_15_90_728 ; real_T B_15_91_736 ; real_T B_15_92_744 ;
real_T B_15_93_752 ; real_T B_15_94_760 ; real_T B_15_95_768 ; real_T
B_15_96_776 ; real_T B_15_97_784 ; real_T B_15_98_792 ; real_T B_15_99_800 ;
real_T B_15_100_808 ; real_T B_15_101_816 ; real_T B_15_102_824 ; real_T
B_15_103_832 [ 3 ] ; real_T B_15_106_856 [ 3 ] ; real_T B_15_109_880 [ 2 ] ;
real_T B_15_111_896 ; real_T B_15_112_904 ; real_T B_15_113_912 [ 6 ] ;
real_T B_15_119_960 ; real_T B_15_120_968 ; real_T B_15_121_976 ; real_T
B_15_122_984 ; real_T B_15_123_992 ; real_T B_15_124_1000 ; real_T
B_15_125_1008 ; real_T B_15_126_1016 ; real_T B_15_127_1024 ; real_T
B_15_128_1032 ; real_T B_15_129_1040 ; real_T B_15_130_1048 ; real_T
B_15_131_1056 ; real_T B_15_132_1064 [ 3 ] ; real_T B_15_135_1088 ; real_T
B_15_136_1096 ; real_T B_14_137_1104 ; real_T B_14_138_1112 ; real_T
B_14_139_1120 ; real_T B_14_140_1128 ; real_T B_14_141_1136 ; real_T
B_14_142_1144 ; real_T B_14_143_1152 ; real_T B_14_144_1160 ; real_T
B_14_145_1168 ; real_T B_14_146_1176 ; real_T B_14_147_1184 ; real_T
B_14_148_1192 ; real_T B_14_149_1200 ; real_T B_14_150_1208 ; real_T
B_14_151_1216 ; real_T B_14_152_1224 ; real_T B_14_153_1232 ; real_T
B_14_154_1240 ; real_T B_14_155_1248 ; real_T B_14_156_1256 ; real_T
B_9_157_1264 [ 3 ] ; real_T B_9_160_1288 [ 3 ] ; real_T B_9_163_1312 ; real_T
B_9_164_1320 [ 3 ] ; real_T B_9_167_1344 ; real_T B_9_168_1352 ; real_T
B_9_169_1360 [ 3 ] ; real_T B_9_172_1384 ; real_T B_5_173_1392 ; real_T
B_5_174_1400 ; real_T B_4_175_1408 ; real_T B_4_176_1416 ; real_T
B_4_177_1424 ; real_T B_4_178_1432 ; real_T B_4_179_1440 ; real_T
B_4_180_1448 ; real_T B_4_181_1456 ; real_T B_4_182_1464 ; real_T
B_4_183_1472 ; real_T B_4_184_1480 ; real_T B_4_185_1488 ; real_T
B_4_186_1496 ; real_T B_4_187_1504 ; real_T B_4_188_1512 ; real_T
B_4_189_1520 ; real_T B_4_190_1528 [ 3 ] ; real_T B_4_193_1552 [ 3 ] ; real_T
B_4_196_1576 [ 2 ] ; real_T B_4_198_1592 ; real_T B_4_199_1600 ; real_T
B_4_200_1608 ; real_T B_4_201_1616 ; real_T B_1_202_1624 ; real_T
B_1_203_1632 ; real_T B_0_204_1640 ; real_T B_0_205_1648 ; real_T
B_15_206_1656 [ 3 ] ; real_T B_15_209_1680 [ 3 ] ; uint8_T B_15_212_1704 ;
uint8_T B_15_213_1705 ; uint8_T B_4_214_1706 ; uint8_T B_4_215_1707 ;
boolean_T B_15_216_1708 ; boolean_T B_15_217_1709 [ 6 ] ; boolean_T
B_15_223_1715 [ 6 ] ; boolean_T B_15_229_1721 [ 6 ] ; boolean_T B_15_235_1727
; boolean_T B_14_236_1728 ; boolean_T B_14_237_1729 ; boolean_T B_14_238_1730
; boolean_T B_14_239_1731 ; boolean_T B_14_240_1732 ; boolean_T B_14_241_1733
; boolean_T B_4_242_1734 ; boolean_T B_4_243_1735 ; B_Subsystem1_spr_sim_T
Subsystem1 ; B_Subsystempi2delay_spr_sim_T Subsystempi2delay ;
B_Subsystem1_spr_sim_T Subsystem1_p ; B_Subsystempi2delay_spr_sim_T
Subsystempi2delay_h ; } B_spr_sim_T ; typedef struct { real_T
StateSpace_DSTATE [ 9 ] ; real_T DiscreteTimeIntegrator_DSTATE ; real_T
DiscreteTimeIntegrator1_DSTATE ; real_T UnitDelay_DSTATE ; real_T
Initial_FirstOutputTime ; real_T ICic_PreviousInput [ 6 ] ; real_T
Memory_PreviousInput ; real_T PrevY ; real_T LastMajorTime ; struct { real_T
modelTStart ; } VariableTransportDelay_RWORK ; struct { real_T modelTStart ;
} VariableTransportDelay_RWORK_e ; struct { real_T modelTStart ; }
VariableTransportDelay_RWORK_a ; struct { void * AS ; void * BS ; void * CS ;
void * DS ; void * DX_COL ; void * BD_COL ; void * TMP1 ; void * TMP2 ; void
* XTMP ; void * SWITCH_STATUS ; void * SWITCH_STATUS_INIT ; void * SW_CHG ;
void * G_STATE ; void * USWLAST ; void * XKM12 ; void * XKP12 ; void * XLAST
; void * ULAST ; void * IDX_SW_CHG ; void * Y_SWITCH ; void * SWITCH_TYPES ;
void * IDX_OUT_SW ; void * SWITCH_TOPO_SAVED_IDX ; void * SWITCH_MAP ; }
StateSpace_PWORK ; void * Scope_PWORK [ 6 ] ; void * Scope1_PWORK [ 2 ] ;
struct { void * AQHandles ; } _asyncqueue_inserted_for_ToWorkspace_PWORK ;
struct { void * TUbufferPtrs [ 3 ] ; } VariableTransportDelay_PWORK ; void *
Scope2_PWORK [ 2 ] ; struct { void * AQHandles ; }
_asyncqueue_inserted_for_ToWorkspace1_PWORK ; struct { void * TUbufferPtrs [
3 ] ; } VariableTransportDelay_PWORK_a ; struct { void * TUbufferPtrs [ 3 ] ;
} VariableTransportDelay_PWORK_g ; int32_T Signalgenerator_sysIdxToRun ;
int32_T TmpAtomicSubsysAtSwitch2Inport1_sysIdxToRun ; int32_T
TmpAtomicSubsysAtMultiportSwitch1Inport4_sysIdxToRun ; int32_T
TmpAtomicSubsysAtMultiportSwitch1Inport2_sysIdxToRun ; int32_T
TmpAtomicSubsysAtSwitch3Inport1_sysIdxToRun ; int32_T
HarmonicGenerator_sysIdxToRun ; int32_T
TmpAtomicSubsysAtDPYInport1_sysIdxToRun ; int32_T
TmpAtomicSubsysAtSwitchInport1_sysIdxToRun ; int32_T
AutomaticGainControl_sysIdxToRun ; int32_T
TmpAtomicSubsysAtSwitchInport1_sysIdxToRun_b ; int32_T
TmpAtomicSubsysAtSwitchInport1_sysIdxToRun_g ; int_T StateSpace_IWORK [ 11 ]
; int_T Integrator_IWORK ; struct { int_T Tail ; int_T Head ; int_T Last ;
int_T CircularBufSize ; int_T MaxNewBufSize ; } VariableTransportDelay_IWORK
; struct { int_T Tail ; int_T Head ; int_T Last ; int_T CircularBufSize ;
int_T MaxNewBufSize ; } VariableTransportDelay_IWORK_m ; struct { int_T Tail
; int_T Head ; int_T Last ; int_T CircularBufSize ; int_T MaxNewBufSize ; }
VariableTransportDelay_IWORK_p ; int_T Integrator_MODE ; int_T
Integrator_MODE_c ; int_T Saturation2_MODE ; int_T Saturation_MODE ; int8_T
Signalgenerator_SubsysRanBC ; int8_T HarmonicGenerator_SubsysRanBC ; int8_T
AutomaticGainControl_SubsysRanBC ; uint8_T DiscreteTimeIntegrator_NumInitCond
; uint8_T DiscreteTimeIntegrator1_NumInitCond ; boolean_T
RelationalOperator_Mode ; boolean_T RelationalOperator2_Mode [ 6 ] ;
boolean_T RelationalOperator4_Mode [ 6 ] ; boolean_T
RelationalOperator_Mode_f ; boolean_T PrevLimited ; boolean_T
RelationalOperator_Mode_j ; boolean_T RelationalOperator_Mode_k ; boolean_T
Signalgenerator_MODE ; boolean_T HarmonicGenerator_MODE ; boolean_T
AutomaticGainControl_MODE ; char_T pad_AutomaticGainControl_MODE [ 7 ] ;
DW_Subsystem1_spr_sim_T Subsystem1 ; DW_Subsystempi2delay_spr_sim_T
Subsystempi2delay ; DW_Subsystem1_spr_sim_T Subsystem1_p ;
DW_Subsystempi2delay_spr_sim_T Subsystempi2delay_h ; } DW_spr_sim_T ; typedef
struct { real_T Integrator_CSTATE ; real_T Integrator_CSTATE_c ; real_T
VariableTransportDelay_CSTATE ; real_T integrator_CSTATE ; real_T
TransferFcn_CSTATE ; real_T Integrator_x1_CSTATE ; real_T
Integrator_x2_CSTATE ; real_T VariableTransportDelay_CSTATE_f ; real_T
integrator_CSTATE_c ; real_T VariableTransportDelay_CSTATE_e ; real_T
integrator_CSTATE_cy ; } X_spr_sim_T ; typedef struct { real_T
Integrator_CSTATE ; real_T Integrator_CSTATE_c ; real_T
VariableTransportDelay_CSTATE ; real_T integrator_CSTATE ; real_T
TransferFcn_CSTATE ; real_T Integrator_x1_CSTATE ; real_T
Integrator_x2_CSTATE ; real_T VariableTransportDelay_CSTATE_f ; real_T
integrator_CSTATE_c ; real_T VariableTransportDelay_CSTATE_e ; real_T
integrator_CSTATE_cy ; } XDot_spr_sim_T ; typedef struct { boolean_T
Integrator_CSTATE ; boolean_T Integrator_CSTATE_c ; boolean_T
VariableTransportDelay_CSTATE ; boolean_T integrator_CSTATE ; boolean_T
TransferFcn_CSTATE ; boolean_T Integrator_x1_CSTATE ; boolean_T
Integrator_x2_CSTATE ; boolean_T VariableTransportDelay_CSTATE_f ; boolean_T
integrator_CSTATE_c ; boolean_T VariableTransportDelay_CSTATE_e ; boolean_T
integrator_CSTATE_cy ; } XDis_spr_sim_T ; typedef struct { real_T
Integrator_CSTATE ; real_T Integrator_CSTATE_c ; real_T
VariableTransportDelay_CSTATE ; real_T integrator_CSTATE ; real_T
TransferFcn_CSTATE ; real_T Integrator_x1_CSTATE ; real_T
Integrator_x2_CSTATE ; real_T VariableTransportDelay_CSTATE_f ; real_T
integrator_CSTATE_c ; real_T VariableTransportDelay_CSTATE_e ; real_T
integrator_CSTATE_cy ; } CStateAbsTol_spr_sim_T ; typedef struct { real_T
Integrator_CSTATE ; real_T Integrator_CSTATE_c ; real_T
VariableTransportDelay_CSTATE ; real_T integrator_CSTATE ; real_T
TransferFcn_CSTATE ; real_T Integrator_x1_CSTATE ; real_T
Integrator_x2_CSTATE ; real_T VariableTransportDelay_CSTATE_f ; real_T
integrator_CSTATE_c ; real_T VariableTransportDelay_CSTATE_e ; real_T
integrator_CSTATE_cy ; } CXPtMin_spr_sim_T ; typedef struct { real_T
Integrator_CSTATE ; real_T Integrator_CSTATE_c ; real_T
VariableTransportDelay_CSTATE ; real_T integrator_CSTATE ; real_T
TransferFcn_CSTATE ; real_T Integrator_x1_CSTATE ; real_T
Integrator_x2_CSTATE ; real_T VariableTransportDelay_CSTATE_f ; real_T
integrator_CSTATE_c ; real_T VariableTransportDelay_CSTATE_e ; real_T
integrator_CSTATE_cy ; } CXPtMax_spr_sim_T ; typedef struct { real_T
RelationalOperator_RelopInput_ZC ; real_T Integrator_Reset_ZC ; real_T
Integrator_IntgUpLimit_ZC ; real_T Integrator_IntgLoLimit_ZC ; real_T
Integrator_LeaveSaturate_ZC ; real_T RelationalOperator2_RelopInput_ZC [ 6 ]
; real_T RelationalOperator4_RelopInput_ZC [ 6 ] ; real_T
HitCrossing_HitNoOutput_ZC ; real_T Integrator_IntgUpLimit_ZC_k ; real_T
Integrator_IntgLoLimit_ZC_a ; real_T Integrator_LeaveSaturate_ZC_h ; real_T
RelationalOperator_RelopInput_ZC_p ; real_T Saturation2_UprLim_ZC ; real_T
Saturation2_LwrLim_ZC ; real_T RelationalOperator_RelopInput_ZC_e ; real_T
RelationalOperator_RelopInput_ZC_d ; real_T Saturation_UprLim_ZC ; real_T
Saturation_LwrLim_ZC ; } ZCV_spr_sim_T ; typedef struct { ZCSigState
RelationalOperator_RelopInput_ZCE ; ZCSigState Integrator_Reset_ZCE ;
ZCSigState Integrator_IntgUpLimit_ZCE ; ZCSigState Integrator_IntgLoLimit_ZCE
; ZCSigState Integrator_LeaveSaturate_ZCE ; ZCSigState
RelationalOperator2_RelopInput_ZCE [ 6 ] ; ZCSigState
RelationalOperator4_RelopInput_ZCE [ 6 ] ; ZCSigState
HitCrossing_HitNoOutput_ZCE ; ZCSigState Integrator_IntgUpLimit_ZCE_k ;
ZCSigState Integrator_IntgLoLimit_ZCE_k ; ZCSigState
Integrator_LeaveSaturate_ZCE_b ; ZCSigState
RelationalOperator_RelopInput_ZCE_l ; ZCSigState Saturation2_UprLim_ZCE ;
ZCSigState Saturation2_LwrLim_ZCE ; ZCSigState
RelationalOperator_RelopInput_ZCE_e ; ZCSigState
RelationalOperator_RelopInput_ZCE_g ; ZCSigState Saturation_UprLim_ZCE ;
ZCSigState Saturation_LwrLim_ZCE ; } PrevZCX_spr_sim_T ; struct
P_Subsystempi2delay_spr_sim_T_ { real_T P_0 [ 2 ] ; } ; struct
P_Subsystem1_spr_sim_T_ { real_T P_0 [ 2 ] ; } ; struct P_spr_sim_T_ { real_T
P_0 ; real_T P_1 ; real_T P_2 ; real_T P_3 ; real_T P_4 ; real_T P_5 ; real_T
P_6 ; real_T P_7 ; real_T P_8 ; real_T P_9 ; real_T P_10 ; real_T P_11 ;
real_T P_12 ; real_T P_13 [ 9 ] ; real_T P_14 ; real_T P_15 ; real_T P_16 ;
real_T P_17 ; real_T P_18 ; real_T P_19 ; real_T P_20 ; real_T P_21 ; real_T
P_22 ; real_T P_23 ; real_T P_24 ; real_T P_25 ; real_T P_26 ; real_T P_27 ;
real_T P_28 ; real_T P_29 ; real_T P_30 ; real_T P_31 ; real_T P_32 ; real_T
P_33 ; real_T P_34 ; real_T P_35 ; real_T P_36 [ 3 ] ; real_T P_37 [ 3 ] ;
real_T P_38 [ 3 ] ; real_T P_39 ; real_T P_40 ; real_T P_41 ; real_T P_42 ;
real_T P_43 ; real_T P_44 [ 3 ] ; real_T P_45 [ 3 ] ; real_T P_46 [ 3 ] ;
real_T P_47 ; real_T P_48 ; real_T P_49 ; real_T P_50 ; real_T P_51 ; real_T
P_52 ; real_T P_53 [ 8 ] ; real_T P_54 [ 8 ] ; real_T P_55 ; real_T P_56 ;
real_T P_57 ; real_T P_58 ; real_T P_59 ; real_T P_60 ; real_T P_61 ; real_T
P_62 ; real_T P_63 ; real_T P_64 ; real_T P_65 ; real_T P_66 ; real_T P_67 ;
real_T P_68 ; real_T P_69 ; real_T P_70 ; real_T P_71 ; real_T P_72 ; real_T
P_73 ; real_T P_74 ; real_T P_75 ; real_T P_76 ; real_T P_77 ; real_T P_78 ;
real_T P_79 ; real_T P_80 ; real_T P_81 ; real_T P_82 ; real_T P_83 ; real_T
P_84 ; real_T P_85 ; real_T P_86 ; real_T P_87 ; real_T P_88 ; real_T P_89 ;
real_T P_90 ; real_T P_91 ; real_T P_92 [ 2 ] ; real_T P_93 [ 81 ] ; real_T
P_94 [ 2 ] ; real_T P_95 [ 135 ] ; real_T P_96 [ 2 ] ; real_T P_97 [ 153 ] ;
real_T P_98 [ 2 ] ; real_T P_99 [ 255 ] ; real_T P_100 [ 2 ] ; real_T P_101 [
9 ] ; real_T P_102 ; real_T P_103 ; real_T P_104 ; real_T P_105 [ 6 ] ;
real_T P_106 ; real_T P_107 ; real_T P_108 ; real_T P_109 ; real_T P_110 ;
real_T P_111 ; real_T P_112 ; real_T P_113 ; real_T P_114 ; real_T P_115 ;
real_T P_116 ; real_T P_117 ; real_T P_118 ; real_T P_119 ; real_T P_120 ;
real_T P_121 ; real_T P_122 ; real_T P_123 ; real_T P_124 ; real_T P_125 ;
real_T P_126 ; real_T P_127 ; real_T P_128 ; real_T P_129 ; real_T P_130 ;
real_T P_131 ; real_T P_132 ; real_T P_133 ; real_T P_134 ; real_T P_135 ;
real_T P_136 ; real_T P_137 ; real_T P_138 ; real_T P_139 ; real_T P_140 ;
real_T P_141 ; real_T P_142 ; real_T P_143 ; real_T P_144 ; real_T P_145 ;
real_T P_146 ; real_T P_147 ; real_T P_148 ; real_T P_149 ; real_T P_150 ;
real_T P_151 ; real_T P_152 ; real_T P_153 ; real_T P_154 ; real_T P_155 ;
real_T P_156 [ 9 ] ; real_T P_157 ; real_T P_158 ; real_T P_159 ; real_T
P_160 [ 6 ] ; real_T P_161 ; real_T P_162 ; real_T P_163 ; real_T P_164 ;
real_T P_165 ; real_T P_166 ; real_T P_167 ; real_T P_168 ; real_T P_169 ;
real_T P_170 ; real_T P_171 ; real_T P_172 ; real_T P_173 ; real_T P_174 ;
real_T P_175 ; real_T P_176 ; real_T P_177 ; real_T P_178 ; real_T P_179 [ 3
] ; real_T P_180 ; real_T P_181 ; boolean_T P_182 ; char_T pad_P_182 [ 7 ] ;
P_Subsystem1_spr_sim_T Subsystem1 ; P_Subsystempi2delay_spr_sim_T
Subsystempi2delay ; P_Subsystem1_spr_sim_T Subsystem1_p ;
P_Subsystempi2delay_spr_sim_T Subsystempi2delay_h ; } ; extern P_spr_sim_T
spr_sim_rtDefaultP ;
#endif
