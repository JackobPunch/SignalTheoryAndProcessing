#include "spr_sim_acc.h"
#include "spr_sim_acc_types.h"
#include "rtwtypes.h"
#include "spr_sim_acc_private.h"
#include "mwmathutil.h"
#include "rt_look.h"
#include "rt_look1d.h"
#include "multiword_types.h"
#include "simstruc_types.h"
#include <stdio.h>
#include "slexec_vm_simstruct_bridge.h"
#include "slexec_vm_zc_functions.h"
#include "slexec_vm_lookup_functions.h"
#include "slsv_diagnostic_codegen_c_api.h"
#include "simtarget/slSimTgtMdlrefSfcnBridge.h"
#include "simstruc.h"
#include "fixedpoint.h"
#define CodeFormat S-Function
#define AccDefine1 Accelerator_S-Function
#include "simtarget/slAccSfcnBridge.h"
#ifndef __RTW_UTFREE__  
extern void * utMalloc ( size_t ) ; extern void utFree ( void * ) ;
#endif
boolean_T spr_sim_acc_rt_TDelayUpdateTailOrGrowBuf ( int_T * bufSzPtr , int_T
* tailPtr , int_T * headPtr , int_T * lastPtr , real_T tMinusDelay , real_T *
* uBufPtr , boolean_T isfixedbuf , boolean_T istransportdelay , int_T *
maxNewBufSzPtr ) { int_T testIdx ; int_T tail = * tailPtr ; int_T bufSz = *
bufSzPtr ; real_T * tBuf = * uBufPtr + bufSz ; real_T * xBuf = ( NULL ) ;
int_T numBuffer = 2 ; if ( istransportdelay ) { numBuffer = 3 ; xBuf = *
uBufPtr + 2 * bufSz ; } testIdx = ( tail < ( bufSz - 1 ) ) ? ( tail + 1 ) : 0
; if ( ( tMinusDelay <= tBuf [ testIdx ] ) && ! isfixedbuf ) { int_T j ;
real_T * tempT ; real_T * tempU ; real_T * tempX = ( NULL ) ; real_T * uBuf =
* uBufPtr ; int_T newBufSz = bufSz + 1024 ; if ( newBufSz > * maxNewBufSzPtr
) { * maxNewBufSzPtr = newBufSz ; } tempU = ( real_T * ) utMalloc ( numBuffer
* newBufSz * sizeof ( real_T ) ) ; if ( tempU == ( NULL ) ) { return ( false
) ; } tempT = tempU + newBufSz ; if ( istransportdelay ) tempX = tempT +
newBufSz ; for ( j = tail ; j < bufSz ; j ++ ) { tempT [ j - tail ] = tBuf [
j ] ; tempU [ j - tail ] = uBuf [ j ] ; if ( istransportdelay ) tempX [ j -
tail ] = xBuf [ j ] ; } for ( j = 0 ; j < tail ; j ++ ) { tempT [ j + bufSz -
tail ] = tBuf [ j ] ; tempU [ j + bufSz - tail ] = uBuf [ j ] ; if (
istransportdelay ) tempX [ j + bufSz - tail ] = xBuf [ j ] ; } if ( * lastPtr
> tail ) { * lastPtr -= tail ; } else { * lastPtr += ( bufSz - tail ) ; } *
tailPtr = 0 ; * headPtr = bufSz ; utFree ( uBuf ) ; * bufSzPtr = newBufSz ; *
uBufPtr = tempU ; } else { * tailPtr = testIdx ; } return ( true ) ; } real_T
spr_sim_acc_rt_VTDelayfindtDInterpolate ( real_T x , real_T * uBuf , int_T
bufSz , int_T head , int_T tail , int_T * pLast , real_T t , real_T tStart ,
boolean_T discrete , boolean_T minorStepAndTAtLastMajorOutput , real_T
initOutput , real_T * appliedDelay ) { int_T n , k ; real_T f ; int_T kp1 ;
real_T tminustD , tL , tR , uD , uL , uR , fU ; real_T * tBuf = uBuf + bufSz
; real_T * xBuf = uBuf + 2 * bufSz ; if ( minorStepAndTAtLastMajorOutput ) {
if ( * pLast == head ) { * pLast = ( * pLast == 0 ) ? bufSz - 1 : * pLast - 1
; } head = ( head == 0 ) ? bufSz - 1 : head - 1 ; } if ( x <= 1 ) { return
initOutput ; } k = * pLast ; n = 0 ; for ( ; ; ) { n ++ ; if ( n > bufSz )
break ; if ( x - xBuf [ k ] > 1.0 ) { if ( k == head ) { int_T km1 ; f = ( x
- 1.0 - xBuf [ k ] ) / ( x - xBuf [ k ] ) ; tminustD = ( 1.0 - f ) * tBuf [ k
] + f * t ; km1 = k - 1 ; if ( km1 < 0 ) km1 = bufSz - 1 ; tL = tBuf [ km1 ]
; tR = tBuf [ k ] ; uL = uBuf [ km1 ] ; uR = uBuf [ k ] ; break ; } kp1 = k +
1 ; if ( kp1 == bufSz ) kp1 = 0 ; if ( x - xBuf [ kp1 ] <= 1.0 ) { f = ( x -
1.0 - xBuf [ k ] ) / ( xBuf [ kp1 ] - xBuf [ k ] ) ; tL = tBuf [ k ] ; tR =
tBuf [ kp1 ] ; uL = uBuf [ k ] ; uR = uBuf [ kp1 ] ; tminustD = ( 1.0 - f ) *
tL + f * tR ; break ; } k = kp1 ; } else { if ( k == tail ) { f = ( x - 1.0 )
/ xBuf [ k ] ; if ( discrete ) { return ( uBuf [ tail ] ) ; } kp1 = k + 1 ;
if ( kp1 == bufSz ) kp1 = 0 ; tminustD = ( 1 - f ) * tStart + f * tBuf [ k ]
; tL = tBuf [ k ] ; tR = tBuf [ kp1 ] ; uL = uBuf [ k ] ; uR = uBuf [ kp1 ] ;
break ; } k = k - 1 ; if ( k < 0 ) k = bufSz - 1 ; } } * pLast = k ; if ( tR
== tL ) { fU = 1.0 ; } else { fU = ( tminustD - tL ) / ( tR - tL ) ; } if (
discrete ) { uD = ( fU > ( 1.0 - fU ) ) ? uR : uL ; } else { uD = ( 1.0 - fU
) * uL + fU * uR ; } * appliedDelay = t - tminustD ; return uD ; } void
rt_ssGetBlockPath ( SimStruct * S , int_T sysIdx , int_T blkIdx , char_T * *
path ) { _ssGetBlockPath ( S , sysIdx , blkIdx , path ) ; } void
rt_ssSet_slErrMsg ( void * S , void * diag ) { SimStruct * castedS = (
SimStruct * ) S ; if ( ! _ssIsErrorStatusAslErrMsg ( castedS ) ) {
_ssSet_slErrMsg ( castedS , diag ) ; } else { _ssDiscardDiagnostic ( castedS
, diag ) ; } } void rt_ssReportDiagnosticAsWarning ( void * S , void * diag )
{ _ssReportDiagnosticAsWarning ( ( SimStruct * ) S , diag ) ; } void
rt_ssReportDiagnosticAsInfo ( void * S , void * diag ) {
_ssReportDiagnosticAsInfo ( ( SimStruct * ) S , diag ) ; } void
spr_sim_Subsystempi2delay_Init ( SimStruct * S ,
B_Subsystempi2delay_spr_sim_T * localB , P_Subsystempi2delay_spr_sim_T *
localP ) { localB -> B_2_250_1784 = localP -> P_0 [ 0 ] ; localB ->
B_2_251_1792 = localP -> P_0 [ 1 ] ; } void spr_sim_Subsystempi2delay_Disable
( SimStruct * S , DW_Subsystempi2delay_spr_sim_T * localDW ) { localDW ->
Subsystempi2delay_MODE = false ; } void spr_sim_Subsystempi2delay ( SimStruct
* S , uint8_T rtu_Enable , const real_T rtu_alpha_beta [ 2 ] , real_T rtu_wt
, B_Subsystempi2delay_spr_sim_T * localB , DW_Subsystempi2delay_spr_sim_T *
localDW ) { int32_T isHit ; isHit = ssIsSampleHit ( S , 1 , 0 ) ; if ( (
isHit != 0 ) && ssIsModeUpdateTimeStep ( S ) ) { if ( rtu_Enable > 0 ) { if (
! localDW -> Subsystempi2delay_MODE ) { if ( ssGetTaskTime ( S , 1 ) !=
ssGetTStart ( S ) ) { ssSetBlockStateForSolverChangedAtMajorStep ( S ) ; }
localDW -> Subsystempi2delay_MODE = true ; } } else if ( localDW ->
Subsystempi2delay_MODE ) { ssSetBlockStateForSolverChangedAtMajorStep ( S ) ;
spr_sim_Subsystempi2delay_Disable ( S , localDW ) ; } } if ( localDW ->
Subsystempi2delay_MODE ) { localB -> B_2_250_1784 = rtu_alpha_beta [ 0 ] *
muDoubleScalarSin ( rtu_wt ) - rtu_alpha_beta [ 1 ] * muDoubleScalarCos (
rtu_wt ) ; localB -> B_2_251_1792 = rtu_alpha_beta [ 0 ] * muDoubleScalarCos
( rtu_wt ) + rtu_alpha_beta [ 1 ] * muDoubleScalarSin ( rtu_wt ) ; if (
ssIsModeUpdateTimeStep ( S ) ) { srUpdateBC ( localDW ->
Subsystempi2delay_SubsysRanBC ) ; } } } void spr_sim_Subsystempi2delay_Term (
SimStruct * const S ) { } void spr_sim_Subsystem1_Init ( SimStruct * S ,
B_Subsystem1_spr_sim_T * localB , P_Subsystem1_spr_sim_T * localP ) { localB
-> B_3_248_1768 = localP -> P_0 [ 0 ] ; localB -> B_3_249_1776 = localP ->
P_0 [ 1 ] ; } void spr_sim_Subsystem1_Disable ( SimStruct * S ,
DW_Subsystem1_spr_sim_T * localDW ) { localDW -> Subsystem1_MODE = false ; }
void spr_sim_Subsystem1 ( SimStruct * S , uint8_T rtu_Enable , const real_T
rtu_alpha_beta [ 2 ] , real_T rtu_wt , B_Subsystem1_spr_sim_T * localB ,
DW_Subsystem1_spr_sim_T * localDW ) { int32_T isHit ; isHit = ssIsSampleHit (
S , 1 , 0 ) ; if ( ( isHit != 0 ) && ssIsModeUpdateTimeStep ( S ) ) { if (
rtu_Enable > 0 ) { if ( ! localDW -> Subsystem1_MODE ) { if ( ssGetTaskTime (
S , 1 ) != ssGetTStart ( S ) ) { ssSetBlockStateForSolverChangedAtMajorStep (
S ) ; } localDW -> Subsystem1_MODE = true ; } } else if ( localDW ->
Subsystem1_MODE ) { ssSetBlockStateForSolverChangedAtMajorStep ( S ) ;
spr_sim_Subsystem1_Disable ( S , localDW ) ; } } if ( localDW ->
Subsystem1_MODE ) { localB -> B_3_248_1768 = rtu_alpha_beta [ 0 ] *
muDoubleScalarCos ( rtu_wt ) + rtu_alpha_beta [ 1 ] * muDoubleScalarSin (
rtu_wt ) ; localB -> B_3_249_1776 = - rtu_alpha_beta [ 0 ] *
muDoubleScalarSin ( rtu_wt ) + rtu_alpha_beta [ 1 ] * muDoubleScalarCos (
rtu_wt ) ; if ( ssIsModeUpdateTimeStep ( S ) ) { srUpdateBC ( localDW ->
Subsystem1_SubsysRanBC ) ; } } } void spr_sim_Subsystem1_Term ( SimStruct *
const S ) { } static void mdlOutputs ( SimStruct * S , int_T tid ) { real_T
B_15_269_1936 ; B_spr_sim_T * _rtB ; DW_spr_sim_T * _rtDW ; P_spr_sim_T *
_rtP ; PrevZCX_spr_sim_T * _rtZCE ; X_spr_sim_T * _rtX ; real_T
rtb_B_15_362_2680 [ 9 ] ; real_T rtb_B_15_371_2752 [ 6 ] ; real_T
rtb_B_15_283_2048 [ 2 ] ; real_T B_15_257_1840_idx_0 ; real_T
B_15_257_1840_idx_1 ; real_T B_15_257_1840_idx_2 ; real_T B_15_359_2656_idx_0
; real_T B_15_359_2656_idx_1 ; real_T B_15_70_568_0 ; real_T
rtb_B_14_291_2112 ; real_T rtb_B_14_292_2120 ; real_T rtb_B_9_312_2280 ;
int32_T i ; int32_T isHit ; boolean_T rtb_B_15_377_2800 [ 6 ] ; boolean_T
B_15_377_2800 ; boolean_T B_15_377_2800_0 ; boolean_T rtb_B_15_383_2806 ;
_rtDW = ( ( DW_spr_sim_T * ) ssGetRootDWork ( S ) ) ; _rtZCE = ( (
PrevZCX_spr_sim_T * ) _ssGetPrevZCSigState ( S ) ) ; _rtX = ( ( X_spr_sim_T *
) ssGetContStates ( S ) ) ; _rtP = ( ( P_spr_sim_T * ) ssGetModelRtp ( S ) )
; _rtB = ( ( B_spr_sim_T * ) _ssGetModelBlockIO ( S ) ) ; isHit =
ssIsSampleHit ( S , 2 , 0 ) ; if ( isHit != 0 ) { _rtB -> B_15_1_16 = _rtP ->
P_89 ; isHit = ssIsSampleHit ( S , 2 , 0 ) ; if ( ( isHit != 0 ) &&
ssIsModeUpdateTimeStep ( S ) ) { if ( _rtB -> B_15_1_16 > 0.0 ) { if ( !
_rtDW -> Signalgenerator_MODE ) { if ( ssGetTaskTime ( S , 2 ) != ssGetTStart
( S ) ) { ssSetBlockStateForSolverChangedAtMajorStep ( S ) ; } _rtDW ->
Signalgenerator_MODE = true ; } } else if ( _rtDW -> Signalgenerator_MODE ) {
ssSetBlockStateForSolverChangedAtMajorStep ( S ) ; _rtDW ->
DiscreteTimeIntegrator_DSTATE = _rtB -> B_14_138_1112 ; _rtDW ->
DiscreteTimeIntegrator1_DSTATE = _rtB -> B_14_139_1120 ; _rtB ->
B_14_137_1104 = _rtP -> P_49 ; _rtB -> B_14_236_1728 = _rtP -> P_182 ; _rtB
-> B_14_143_1152 = _rtP -> P_50 ; _rtB -> B_14_142_1144 = _rtP -> P_51 ; _rtB
-> B_14_144_1160 = _rtP -> P_52 ; _rtDW -> Signalgenerator_MODE = false ; } }
if ( _rtDW -> Signalgenerator_MODE ) { isHit = ssIsSampleHit ( S , 2 , 0 ) ;
if ( isHit != 0 ) { _rtB -> B_14_137_1104 = rt_Lookup ( & _rtP -> P_53 [ 0 ]
, 8 , ssGetTaskTime ( S , 2 ) , & _rtP -> P_54 [ 0 ] ) ; _rtB ->
B_14_138_1112 = _rtDW -> DiscreteTimeIntegrator_DSTATE ; if ( ssGetTaskTime (
S , 2 ) < _rtP -> P_57 ) { rtb_B_14_291_2112 = _rtP -> P_58 ; } else {
rtb_B_14_291_2112 = _rtP -> P_59 ; } if ( ssGetTaskTime ( S , 2 ) < _rtP ->
P_60 ) { rtb_B_14_292_2120 = _rtP -> P_61 ; } else { rtb_B_14_292_2120 = _rtP
-> P_62 ; } _rtB -> B_14_139_1120 = _rtDW -> DiscreteTimeIntegrator1_DSTATE ;
if ( rtb_B_14_291_2112 >= _rtP -> P_66 ) { switch ( ( int32_T ) _rtB ->
B_14_149_1200 ) { case 1 : rtb_B_9_312_2280 = _rtB -> B_14_155_1248 *
rtb_B_14_292_2120 ; break ; case 2 : rtb_B_9_312_2280 = _rtB -> B_14_139_1120
; break ; case 3 : rtb_B_9_312_2280 = muDoubleScalarSin ( _rtB ->
B_14_139_1120 * _rtB -> B_14_153_1232 ) * _rtB -> B_14_156_1256 ; break ;
default : rtb_B_9_312_2280 = _rtB -> B_14_152_1224 ; break ; } _rtB ->
B_14_140_1128 = rtb_B_9_312_2280 ; } else { _rtB -> B_14_140_1128 = _rtDW ->
UnitDelay_DSTATE ; } if ( ( ! ( rtb_B_14_291_2112 != 0.0 ) ) && _rtB ->
B_14_241_1733 ) { rtb_B_14_291_2112 = _rtB -> B_14_150_1208 ; } else {
rtb_B_14_291_2112 = _rtB -> B_14_140_1128 ; } if ( _rtB -> B_14_239_1731 ) {
B_15_70_568_0 = rtb_B_14_291_2112 ; } else { B_15_70_568_0 = _rtB ->
B_14_148_1192 ; } _rtB -> B_14_141_1136 = _rtP -> P_67 * B_15_70_568_0 ; _rtB
-> B_14_236_1728 = ( _rtB -> B_14_240_1732 && _rtB -> B_14_237_1729 ) ; _rtB
-> B_14_142_1144 = _rtB -> B_14_138_1112 ; if ( _rtB -> B_14_237_1729 ) {
_rtB -> B_14_143_1152 = rtb_B_14_291_2112 ; } else { _rtB -> B_14_143_1152 =
_rtB -> B_14_146_1176 ; } if ( _rtB -> B_14_238_1730 ) { _rtB ->
B_14_144_1160 = _rtP -> P_48 * rtb_B_14_291_2112 ; } else { _rtB ->
B_14_144_1160 = _rtB -> B_14_147_1184 ; } if ( rtb_B_14_292_2120 >= _rtP ->
P_68 ) { _rtB -> B_14_145_1168 = _rtB -> B_14_154_1240 ; } else { _rtB ->
B_14_145_1168 = _rtB -> B_14_151_1216 ; } } if ( ssIsModeUpdateTimeStep ( S )
) { srUpdateBC ( _rtDW -> Signalgenerator_SubsysRanBC ) ; } }
rtb_B_14_292_2120 = _rtB -> B_14_143_1152 + _rtB -> B_15_136_1096 ; if ( _rtB
-> B_14_236_1728 ) { rtb_B_14_291_2112 = _rtB -> B_14_137_1104 ; } else {
rtb_B_14_291_2112 = rtb_B_14_292_2120 ; } B_15_359_2656_idx_0 =
rtb_B_14_291_2112 ; if ( _rtB -> B_15_135_1088 >= _rtP -> P_90 ) {
B_15_359_2656_idx_1 = rtb_B_14_292_2120 ; } else { B_15_359_2656_idx_1 =
rtb_B_14_291_2112 ; } rtb_B_14_292_2120 = ssGetTaskTime ( S , 2 ) * _rtB ->
B_15_130_1048 + _rtB -> B_14_142_1144 ; B_15_257_1840_idx_0 = ( _rtB ->
B_15_131_1056 + _rtB -> B_15_132_1064 [ 0 ] ) + _rtB -> B_14_144_1160 ;
B_15_257_1840_idx_1 = ( _rtB -> B_15_131_1056 + _rtB -> B_15_132_1064 [ 1 ] )
+ _rtB -> B_14_144_1160 ; B_15_257_1840_idx_2 = ( _rtB -> B_15_131_1056 +
_rtB -> B_15_132_1064 [ 2 ] ) + _rtB -> B_14_144_1160 ; B_15_269_1936 = _rtP
-> P_91 ; isHit = ssIsSampleHit ( S , 2 , 0 ) ; if ( ( isHit != 0 ) &&
ssIsModeUpdateTimeStep ( S ) ) { if ( B_15_269_1936 > 0.0 ) { if ( ! _rtDW ->
HarmonicGenerator_MODE ) { if ( ssGetTaskTime ( S , 2 ) != ssGetTStart ( S )
) { ssSetBlockStateForSolverChangedAtMajorStep ( S ) ; } _rtDW ->
HarmonicGenerator_MODE = true ; } } else if ( _rtDW -> HarmonicGenerator_MODE
) { ssSetBlockStateForSolverChangedAtMajorStep ( S ) ; _rtB -> B_9_157_1264 [
0 ] = _rtP -> P_22 ; _rtB -> B_9_160_1288 [ 0 ] = _rtP -> P_23 ; _rtB ->
B_9_157_1264 [ 1 ] = _rtP -> P_22 ; _rtB -> B_9_160_1288 [ 1 ] = _rtP -> P_23
; _rtB -> B_9_157_1264 [ 2 ] = _rtP -> P_22 ; _rtB -> B_9_160_1288 [ 2 ] =
_rtP -> P_23 ; _rtDW -> HarmonicGenerator_MODE = false ; } } if ( _rtDW ->
HarmonicGenerator_MODE ) { isHit = ssIsSampleHit ( S , 2 , 0 ) ; if ( isHit
!= 0 ) { rtb_B_9_312_2280 = _rtP -> P_24 * rtb_B_14_292_2120 ; if (
ssGetTaskTime ( S , 2 ) < _rtP -> P_25 ) { B_15_70_568_0 = _rtP -> P_26 ; }
else { B_15_70_568_0 = _rtP -> P_27 ; } if ( ssGetTaskTime ( S , 2 ) < _rtP
-> P_28 ) { rtb_B_14_291_2112 = _rtP -> P_29 ; } else { rtb_B_14_291_2112 =
_rtP -> P_30 ; } rtb_B_14_291_2112 += B_15_70_568_0 ; _rtB -> B_9_157_1264 [
0 ] = muDoubleScalarSin ( ( rtb_B_9_312_2280 + _rtB -> B_9_163_1312 ) + _rtB
-> B_9_164_1320 [ 0 ] ) * ( rtb_B_14_291_2112 * _rtB -> B_9_167_1344 ) ; _rtB
-> B_9_157_1264 [ 1 ] = muDoubleScalarSin ( ( rtb_B_9_312_2280 + _rtB ->
B_9_163_1312 ) + _rtB -> B_9_164_1320 [ 1 ] ) * ( rtb_B_14_291_2112 * _rtB ->
B_9_167_1344 ) ; _rtB -> B_9_157_1264 [ 2 ] = muDoubleScalarSin ( (
rtb_B_9_312_2280 + _rtB -> B_9_163_1312 ) + _rtB -> B_9_164_1320 [ 2 ] ) * (
rtb_B_14_291_2112 * _rtB -> B_9_167_1344 ) ; rtb_B_9_312_2280 = _rtP -> P_31
* rtb_B_14_292_2120 ; _rtB -> B_9_160_1288 [ 0 ] = muDoubleScalarSin ( (
rtb_B_9_312_2280 + _rtB -> B_9_168_1352 ) + _rtB -> B_9_169_1360 [ 0 ] ) * (
rtb_B_14_291_2112 * _rtB -> B_9_172_1384 ) ; _rtB -> B_9_160_1288 [ 1 ] =
muDoubleScalarSin ( ( rtb_B_9_312_2280 + _rtB -> B_9_168_1352 ) + _rtB ->
B_9_169_1360 [ 1 ] ) * ( rtb_B_14_291_2112 * _rtB -> B_9_172_1384 ) ; _rtB ->
B_9_160_1288 [ 2 ] = muDoubleScalarSin ( ( rtb_B_9_312_2280 + _rtB ->
B_9_168_1352 ) + _rtB -> B_9_169_1360 [ 2 ] ) * ( rtb_B_14_291_2112 * _rtB ->
B_9_172_1384 ) ; } if ( ssIsModeUpdateTimeStep ( S ) ) { srUpdateBC ( _rtDW
-> HarmonicGenerator_SubsysRanBC ) ; } } _rtB -> B_15_2_24 [ 0 ] = (
muDoubleScalarSin ( rtb_B_14_292_2120 + B_15_257_1840_idx_0 ) *
B_15_359_2656_idx_0 + _rtB -> B_9_157_1264 [ 0 ] ) + _rtB -> B_9_160_1288 [ 0
] ; _rtB -> B_15_2_24 [ 1 ] = ( muDoubleScalarSin ( rtb_B_14_292_2120 +
B_15_257_1840_idx_1 ) * B_15_359_2656_idx_1 + _rtB -> B_9_157_1264 [ 1 ] ) +
_rtB -> B_9_160_1288 [ 1 ] ; _rtB -> B_15_2_24 [ 2 ] = ( muDoubleScalarSin (
rtb_B_14_292_2120 + B_15_257_1840_idx_2 ) * B_15_359_2656_idx_1 + _rtB ->
B_9_157_1264 [ 2 ] ) + _rtB -> B_9_160_1288 [ 2 ] ; ssCallAccelRunBlock ( S ,
15 , 15 , SS_CALL_MDL_OUTPUTS ) ; } isHit = ssIsSampleHit ( S , 1 , 0 ) ; if
( isHit != 0 ) { if ( ssIsModeUpdateTimeStep ( S ) ) { _rtDW ->
RelationalOperator_Mode = ( _rtX -> Integrator_CSTATE > _rtB -> B_15_127_1024
) ; } _rtB -> B_15_216_1708 = _rtDW -> RelationalOperator_Mode ; } _rtB ->
B_15_28_232 = _rtX -> Integrator_CSTATE - _rtB -> B_15_127_1024 ; if ( (
_rtDW -> Initial_FirstOutputTime == ( rtMinusInf ) ) || ( _rtDW ->
Initial_FirstOutputTime == ssGetTaskTime ( S , 0 ) ) ) { _rtDW ->
Initial_FirstOutputTime = ssGetTaskTime ( S , 0 ) ; _rtB -> B_15_29_240 =
_rtP -> P_102 ; } else { _rtB -> B_15_29_240 = _rtB -> B_15_28_232 ; } if (
ssIsModeUpdateTimeStep ( S ) ) { rtb_B_15_383_2806 = ( _rtB -> B_15_216_1708
&& ( _rtZCE -> Integrator_Reset_ZCE != POS_ZCSIG ) ) ; _rtZCE ->
Integrator_Reset_ZCE = _rtB -> B_15_216_1708 ; if ( rtb_B_15_383_2806 || (
_rtDW -> Integrator_IWORK != 0 ) ) { rtb_B_15_383_2806 = ( _rtX ->
Integrator_CSTATE != _rtB -> B_15_29_240 ) ; _rtX -> Integrator_CSTATE = _rtB
-> B_15_29_240 ; if ( rtb_B_15_383_2806 ) {
ssSetBlockStateForSolverChangedAtMajorStep ( S ) ;
ssSetContTimeOutputInconsistentWithStateAtMajorStep ( S ) ; } } if ( _rtX ->
Integrator_CSTATE >= _rtP -> P_103 ) { if ( _rtX -> Integrator_CSTATE != _rtP
-> P_103 ) { _rtX -> Integrator_CSTATE = _rtP -> P_103 ;
ssSetBlockStateForSolverChangedAtMajorStep ( S ) ;
ssSetContTimeOutputInconsistentWithStateAtMajorStep ( S ) ; } _rtDW ->
Integrator_MODE = 3 ; } else if ( _rtX -> Integrator_CSTATE <= _rtP -> P_104
) { if ( _rtX -> Integrator_CSTATE != _rtP -> P_104 ) { _rtX ->
Integrator_CSTATE = _rtP -> P_104 ;
ssSetBlockStateForSolverChangedAtMajorStep ( S ) ;
ssSetContTimeOutputInconsistentWithStateAtMajorStep ( S ) ; } _rtDW ->
Integrator_MODE = 4 ; } else { if ( _rtDW -> Integrator_MODE != 0 ) {
ssSetBlockStateForSolverChangedAtMajorStep ( S ) ; } _rtDW -> Integrator_MODE
= 0 ; } _rtB -> B_15_30_248 = _rtX -> Integrator_CSTATE ; } else { _rtB ->
B_15_30_248 = _rtX -> Integrator_CSTATE ; } isHit = ssIsSampleHit ( S , 1 , 0
) ; for ( i = 0 ; i < 6 ; i ++ ) { if ( isHit != 0 ) { _rtB -> B_15_31_256 [
i ] = _rtP -> P_105 [ i ] ; } rtb_B_15_371_2752 [ i ] = _rtB -> B_15_30_248 +
_rtB -> B_15_31_256 [ i ] ; } isHit = ssIsSampleHit ( S , 1 , 0 ) ; if (
isHit != 0 ) { _rtB -> B_15_37_304 = _rtP -> P_106 ; } for ( i = 0 ; i < 6 ;
i ++ ) { rtb_B_14_292_2120 = muDoubleScalarMod ( rtb_B_15_371_2752 [ i ] ,
_rtB -> B_15_37_304 ) ; rtb_B_15_371_2752 [ i ] = rtb_B_14_292_2120 ; _rtB ->
B_15_38_312 [ i ] = _rtP -> P_107 * rtb_B_14_292_2120 ; } isHit =
ssIsSampleHit ( S , 1 , 0 ) ; if ( isHit != 0 ) { if ( ssIsModeUpdateTimeStep
( S ) ) { for ( i = 0 ; i < 6 ; i ++ ) { _rtDW -> RelationalOperator2_Mode [
i ] = ( _rtB -> B_15_38_312 [ i ] >= _rtB -> B_15_125_1008 ) ; } } for ( i =
0 ; i < 6 ; i ++ ) { rtb_B_15_383_2806 = _rtDW -> RelationalOperator2_Mode [
i ] ; _rtB -> B_15_217_1709 [ i ] = rtb_B_15_383_2806 ; _rtB -> B_15_223_1715
[ i ] = ! rtb_B_15_383_2806 ; } } for ( i = 0 ; i < 6 ; i ++ ) {
rtb_B_15_377_2800 [ i ] = _rtB -> B_15_223_1715 [ i ] ; } isHit =
ssIsSampleHit ( S , 1 , 0 ) ; for ( i = 0 ; i < 6 ; i ++ ) { if ( isHit != 0
) { _rtB -> B_15_44_360 [ i ] = _rtDW -> ICic_PreviousInput [ i ] ; } if (
rtb_B_15_377_2800 [ i ] ) { _rtB -> B_15_50_408 [ i ] = _rtB -> B_15_125_1008
; } else { _rtB -> B_15_50_408 [ i ] = _rtB -> B_15_44_360 [ i ] ; } } isHit
= ssIsSampleHit ( S , 1 , 0 ) ; if ( isHit != 0 ) { _rtB -> B_15_56_456 =
_rtP -> P_109 ; } for ( i = 0 ; i < 6 ; i ++ ) { _rtB -> B_15_57_464 [ i ] =
_rtB -> B_15_50_408 [ i ] + _rtB -> B_15_56_456 ; } isHit = ssIsSampleHit ( S
, 1 , 0 ) ; if ( isHit != 0 ) { if ( ssIsModeUpdateTimeStep ( S ) ) { for ( i
= 0 ; i < 6 ; i ++ ) { _rtDW -> RelationalOperator4_Mode [ i ] = ( _rtB ->
B_15_38_312 [ i ] <= _rtB -> B_15_57_464 [ i ] ) ; } } for ( i = 0 ; i < 6 ;
i ++ ) { _rtB -> B_15_229_1721 [ i ] = _rtDW -> RelationalOperator4_Mode [ i
] ; } } rtb_B_15_383_2806 = true ; for ( i = 0 ; i < 6 ; i ++ ) {
rtb_B_15_377_2800 [ i ] = ( _rtB -> B_15_217_1709 [ i ] && _rtB ->
B_15_229_1721 [ i ] ) ; } isHit = ssIsSampleHit ( S , 1 , 0 ) ; if ( isHit !=
0 ) { _rtB -> B_15_63_512 = _rtP -> P_110 ; } if ( _rtB -> B_15_63_512 > _rtP
-> P_111 ) { B_15_377_2800 = rtb_B_15_377_2800 [ 0 ] ; B_15_377_2800_0 =
rtb_B_15_377_2800 [ 5 ] ; for ( i = 0 ; i < 5 ; i ++ ) { rtb_B_15_377_2800 [
i ] = ( rtb_B_15_377_2800 [ i + 1 ] || rtb_B_15_377_2800 [ i ] ) ; }
rtb_B_15_377_2800 [ 5 ] = ( B_15_377_2800 || B_15_377_2800_0 ) ; } for ( i =
0 ; i < 6 ; i ++ ) { _rtB -> B_15_64_520 [ i ] = rtb_B_15_377_2800 [ i ] ; }
ssCallAccelRunBlock ( S , 15 , 39 , SS_CALL_MDL_OUTPUTS ) ; isHit =
ssIsSampleHit ( S , 2 , 0 ) ; if ( isHit != 0 ) { _rtB -> B_15_206_1656 [ 0 ]
= _rtP -> P_112 * _rtB -> B_15_5_48 [ 9 ] * _rtP -> P_115 ; _rtB ->
B_15_206_1656 [ 1 ] = _rtP -> P_113 * _rtB -> B_15_5_48 [ 10 ] * _rtP ->
P_115 ; _rtB -> B_15_206_1656 [ 2 ] = _rtP -> P_114 * _rtB -> B_15_5_48 [ 11
] * _rtP -> P_115 ; _rtB -> B_15_209_1680 [ 0 ] = _rtP -> P_116 * _rtB ->
B_15_5_48 [ 14 ] * _rtP -> P_119 ; _rtB -> B_15_209_1680 [ 1 ] = _rtP ->
P_117 * _rtB -> B_15_5_48 [ 15 ] * _rtP -> P_119 ; _rtB -> B_15_209_1680 [ 2
] = _rtP -> P_118 * _rtB -> B_15_5_48 [ 16 ] * _rtP -> P_119 ;
ssCallAccelRunBlock ( S , 15 , 48 , SS_CALL_MDL_OUTPUTS ) ; _rtB ->
B_15_70_568 [ 0 ] = _rtP -> P_120 * _rtB -> B_15_5_48 [ 6 ] * _rtP -> P_123 ;
_rtB -> B_15_70_568 [ 1 ] = _rtP -> P_121 * _rtB -> B_15_5_48 [ 7 ] * _rtP ->
P_123 ; _rtB -> B_15_70_568 [ 2 ] = _rtP -> P_122 * _rtB -> B_15_5_48 [ 8 ] *
_rtP -> P_123 ; rtb_B_15_362_2680 [ 0 ] = _rtB -> B_15_209_1680 [ 0 ] ;
rtb_B_15_362_2680 [ 3 ] = _rtB -> B_15_206_1656 [ 0 ] ; rtb_B_15_362_2680 [ 6
] = _rtB -> B_15_70_568 [ 0 ] ; rtb_B_15_362_2680 [ 1 ] = _rtB ->
B_15_209_1680 [ 1 ] ; rtb_B_15_362_2680 [ 4 ] = _rtB -> B_15_206_1656 [ 1 ] ;
rtb_B_15_362_2680 [ 7 ] = _rtB -> B_15_70_568 [ 1 ] ; rtb_B_15_362_2680 [ 2 ]
= _rtB -> B_15_209_1680 [ 2 ] ; rtb_B_15_362_2680 [ 5 ] = _rtB ->
B_15_206_1656 [ 2 ] ; rtb_B_15_362_2680 [ 8 ] = _rtB -> B_15_70_568 [ 2 ] ; {
if ( _rtDW -> _asyncqueue_inserted_for_ToWorkspace_PWORK . AQHandles &&
ssGetLogOutput ( S ) ) { sdiWriteSignal ( _rtDW ->
_asyncqueue_inserted_for_ToWorkspace_PWORK . AQHandles , ssGetTaskTime ( S ,
2 ) , ( char * ) & rtb_B_15_362_2680 [ 0 ] + 0 ) ; } } } isHit =
ssIsSampleHit ( S , 1 , 0 ) ; if ( isHit != 0 ) { _rtB -> B_15_73_592 = _rtDW
-> Memory_PreviousInput ; if ( ssIsModeUpdateTimeStep ( S ) ) { if ( _rtB ->
B_15_126_1016 > 0.0 ) { if ( ! _rtDW -> AutomaticGainControl_MODE ) { if (
ssGetTaskTime ( S , 1 ) != ssGetTStart ( S ) ) {
ssSetBlockStateForSolverChangedAtMajorStep ( S ) ; } ( void ) memset ( & ( (
( XDis_spr_sim_T * ) ssGetContStateDisabled ( S ) ) ->
VariableTransportDelay_CSTATE_f ) , 0 , 4 * sizeof ( boolean_T ) ) ; _rtDW ->
AutomaticGainControl_MODE = true ; } } else { if ( ssGetTaskTime ( S , 1 ) ==
ssGetTStart ( S ) ) { ( void ) memset ( & ( ( ( XDis_spr_sim_T * )
ssGetContStateDisabled ( S ) ) -> VariableTransportDelay_CSTATE_f ) , 1 , 4 *
sizeof ( boolean_T ) ) ; } if ( _rtDW -> AutomaticGainControl_MODE ) {
ssSetBlockStateForSolverChangedAtMajorStep ( S ) ; ( void ) memset ( & ( ( (
XDis_spr_sim_T * ) ssGetContStateDisabled ( S ) ) ->
VariableTransportDelay_CSTATE_f ) , 1 , 4 * sizeof ( boolean_T ) ) ; if (
_rtDW -> Subsystempi2delay_h . Subsystempi2delay_MODE ) {
spr_sim_Subsystempi2delay_Disable ( S , & _rtDW -> Subsystempi2delay_h ) ; }
if ( _rtDW -> Subsystem1_p . Subsystem1_MODE ) { spr_sim_Subsystem1_Disable (
S , & _rtDW -> Subsystem1_p ) ; } _rtDW -> AutomaticGainControl_MODE = false
; } } } } if ( _rtDW -> AutomaticGainControl_MODE ) { { real_T * * uBuffer =
( real_T * * ) & _rtDW -> VariableTransportDelay_PWORK_a . TUbufferPtrs [ 0 ]
; real_T simTime = ssGetT ( S ) ; real_T appliedDelay ; _rtB -> B_4_175_1408
= spr_sim_acc_rt_VTDelayfindtDInterpolate ( ( ( X_spr_sim_T * )
ssGetContStates ( S ) ) -> VariableTransportDelay_CSTATE_f , * uBuffer ,
_rtDW -> VariableTransportDelay_IWORK_m . CircularBufSize , _rtDW ->
VariableTransportDelay_IWORK_m . Head , _rtDW ->
VariableTransportDelay_IWORK_m . Tail , & _rtDW ->
VariableTransportDelay_IWORK_m . Last , simTime , 0.0 , 0 , ( boolean_T ) (
ssIsMinorTimeStep ( S ) && ( ( * uBuffer + _rtDW ->
VariableTransportDelay_IWORK_m . CircularBufSize ) [ _rtDW ->
VariableTransportDelay_IWORK_m . Head ] == ssGetT ( S ) ) ) , _rtP -> P_2 , &
appliedDelay ) ; } _rtB -> B_4_176_1416 = _rtX -> integrator_CSTATE_c ; _rtB
-> B_4_177_1424 = ssGetT ( S ) ; isHit = ssIsSampleHit ( S , 1 , 0 ) ; if (
isHit != 0 ) { if ( ssIsModeUpdateTimeStep ( S ) ) { _rtDW ->
RelationalOperator_Mode_j = ( _rtB -> B_4_177_1424 >= _rtB -> B_4_198_1592 )
; } _rtB -> B_4_242_1734 = _rtDW -> RelationalOperator_Mode_j ; } if ( _rtB
-> B_4_242_1734 ) { _rtB -> B_0_204_1640 = _rtB -> B_4_176_1416 - _rtB ->
B_4_175_1408 ; _rtB -> B_0_205_1648 = _rtB -> B_0_204_1640 * _rtB ->
B_15_73_592 ; _rtB -> B_4_178_1432 = _rtB -> B_0_205_1648 ; } else { _rtB ->
B_4_178_1432 = _rtB -> B_4_199_1600 ; } { real_T * * uBuffer = ( real_T * * )
& _rtDW -> VariableTransportDelay_PWORK_g . TUbufferPtrs [ 0 ] ; real_T
simTime = ssGetT ( S ) ; real_T appliedDelay ; _rtB -> B_4_179_1440 =
spr_sim_acc_rt_VTDelayfindtDInterpolate ( ( ( X_spr_sim_T * ) ssGetContStates
( S ) ) -> VariableTransportDelay_CSTATE_e , * uBuffer , _rtDW ->
VariableTransportDelay_IWORK_p . CircularBufSize , _rtDW ->
VariableTransportDelay_IWORK_p . Head , _rtDW ->
VariableTransportDelay_IWORK_p . Tail , & _rtDW ->
VariableTransportDelay_IWORK_p . Last , simTime , 0.0 , 0 , ( boolean_T ) (
ssIsMinorTimeStep ( S ) && ( ( * uBuffer + _rtDW ->
VariableTransportDelay_IWORK_p . CircularBufSize ) [ _rtDW ->
VariableTransportDelay_IWORK_p . Head ] == ssGetT ( S ) ) ) , _rtP -> P_5 , &
appliedDelay ) ; } _rtB -> B_4_180_1448 = _rtX -> integrator_CSTATE_cy ; _rtB
-> B_4_181_1456 = ssGetT ( S ) ; isHit = ssIsSampleHit ( S , 1 , 0 ) ; if (
isHit != 0 ) { if ( ssIsModeUpdateTimeStep ( S ) ) { _rtDW ->
RelationalOperator_Mode_k = ( _rtB -> B_4_181_1456 >= _rtB -> B_4_200_1608 )
; } _rtB -> B_4_243_1735 = _rtDW -> RelationalOperator_Mode_k ; } if ( _rtB
-> B_4_243_1735 ) { _rtB -> B_1_202_1624 = _rtB -> B_4_180_1448 - _rtB ->
B_4_179_1440 ; _rtB -> B_1_203_1632 = _rtB -> B_1_202_1624 * _rtB ->
B_15_73_592 ; _rtB -> B_4_182_1464 = _rtB -> B_1_203_1632 ; } else { _rtB ->
B_4_182_1464 = _rtB -> B_4_201_1616 ; } _rtB -> B_4_0_0 . re = _rtB ->
B_4_178_1432 ; _rtB -> B_4_0_0 . im = _rtB -> B_4_182_1464 ; _rtB ->
B_4_183_1472 = muDoubleScalarHypot ( _rtB -> B_4_0_0 . re , _rtB -> B_4_0_0 .
im ) ; if ( ssIsModeUpdateTimeStep ( S ) ) { _rtDW -> Saturation_MODE = _rtB
-> B_4_183_1472 >= _rtP -> P_7 ? 1 : _rtB -> B_4_183_1472 > _rtP -> P_8 ? 0 :
- 1 ; } _rtB -> B_4_184_1480 = _rtDW -> Saturation_MODE == 1 ? _rtP -> P_7 :
_rtDW -> Saturation_MODE == - 1 ? _rtP -> P_8 : _rtB -> B_4_183_1472 ; _rtB
-> B_4_185_1488 = 1.0 / _rtB -> B_4_184_1480 ; if ( _rtB -> B_15_73_592 >
_rtP -> P_9 ) { _rtB -> B_4_186_1496 = _rtP -> P_9 ; } else if ( _rtB ->
B_15_73_592 < _rtP -> P_10 ) { _rtB -> B_4_186_1496 = _rtP -> P_10 ; } else {
_rtB -> B_4_186_1496 = _rtB -> B_15_73_592 ; } _rtB -> B_4_187_1504 = 1.0 /
_rtB -> B_4_186_1496 ; if ( _rtB -> B_15_73_592 > _rtP -> P_11 ) { _rtB ->
B_4_188_1512 = _rtP -> P_11 ; } else if ( _rtB -> B_15_73_592 < _rtP -> P_12
) { _rtB -> B_4_188_1512 = _rtP -> P_12 ; } else { _rtB -> B_4_188_1512 =
_rtB -> B_15_73_592 ; } _rtB -> B_4_189_1520 = 1.0 / _rtB -> B_4_188_1512 ;
rtb_B_14_292_2120 = _rtB -> B_15_70_568 [ 1 ] ; rtb_B_9_312_2280 = _rtB ->
B_15_70_568 [ 0 ] ; B_15_70_568_0 = _rtB -> B_15_70_568 [ 2 ] ; for ( i = 0 ;
i < 3 ; i ++ ) { B_15_359_2656_idx_0 = ( _rtP -> P_13 [ i + 3 ] *
rtb_B_14_292_2120 + _rtP -> P_13 [ i ] * rtb_B_9_312_2280 ) + _rtP -> P_13 [
i + 6 ] * B_15_70_568_0 ; _rtB -> B_4_190_1528 [ i ] = B_15_359_2656_idx_0 ;
_rtB -> B_4_193_1552 [ i ] = _rtP -> P_14 * B_15_359_2656_idx_0 ; }
spr_sim_Subsystempi2delay ( S , _rtB -> B_4_215_1707 , & _rtB -> B_4_193_1552
[ 0 ] , _rtB -> B_15_30_248 , & _rtB -> Subsystempi2delay_h , & _rtDW ->
Subsystempi2delay_h ) ; spr_sim_Subsystem1 ( S , _rtB -> B_4_214_1706 , &
_rtB -> B_4_193_1552 [ 0 ] , _rtB -> B_15_30_248 , & _rtB -> Subsystem1_p , &
_rtDW -> Subsystem1_p ) ; if ( _rtB -> B_4_214_1706 != 0 ) { _rtB ->
B_4_196_1576 [ 0 ] = _rtB -> Subsystem1_p . B_3_248_1768 ; _rtB ->
B_4_196_1576 [ 1 ] = _rtB -> Subsystem1_p . B_3_249_1776 ; } else { _rtB ->
B_4_196_1576 [ 0 ] = _rtB -> Subsystempi2delay_h . B_2_250_1784 ; _rtB ->
B_4_196_1576 [ 1 ] = _rtB -> Subsystempi2delay_h . B_2_251_1792 ; } if (
ssIsModeUpdateTimeStep ( S ) ) { srUpdateBC ( _rtDW ->
AutomaticGainControl_SubsysRanBC ) ; } } if ( ssIsModeUpdateTimeStep ( S ) )
{ if ( _rtX -> Integrator_CSTATE_c >= _rtP -> P_127 ) { if ( _rtX ->
Integrator_CSTATE_c != _rtP -> P_127 ) { _rtX -> Integrator_CSTATE_c = _rtP
-> P_127 ; ssSetBlockStateForSolverChangedAtMajorStep ( S ) ; } _rtDW ->
Integrator_MODE_c = 3 ; } else if ( _rtX -> Integrator_CSTATE_c <= _rtP ->
P_128 ) { if ( _rtX -> Integrator_CSTATE_c != _rtP -> P_128 ) { _rtX ->
Integrator_CSTATE_c = _rtP -> P_128 ;
ssSetBlockStateForSolverChangedAtMajorStep ( S ) ; } _rtDW ->
Integrator_MODE_c = 4 ; } else { if ( _rtDW -> Integrator_MODE_c != 0 ) {
ssSetBlockStateForSolverChangedAtMajorStep ( S ) ; } _rtDW ->
Integrator_MODE_c = 0 ; } _rtB -> B_15_74_600 = _rtX -> Integrator_CSTATE_c ;
} else { _rtB -> B_15_74_600 = _rtX -> Integrator_CSTATE_c ; } { real_T * *
uBuffer = ( real_T * * ) & _rtDW -> VariableTransportDelay_PWORK .
TUbufferPtrs [ 0 ] ; real_T simTime = ssGetT ( S ) ; real_T appliedDelay ;
_rtB -> B_15_75_608 = spr_sim_acc_rt_VTDelayfindtDInterpolate ( ( (
X_spr_sim_T * ) ssGetContStates ( S ) ) -> VariableTransportDelay_CSTATE , *
uBuffer , _rtDW -> VariableTransportDelay_IWORK . CircularBufSize , _rtDW ->
VariableTransportDelay_IWORK . Head , _rtDW -> VariableTransportDelay_IWORK .
Tail , & _rtDW -> VariableTransportDelay_IWORK . Last , simTime , 0.0 , 0 , (
boolean_T ) ( ssIsMinorTimeStep ( S ) && ( ( * uBuffer + _rtDW ->
VariableTransportDelay_IWORK . CircularBufSize ) [ _rtDW ->
VariableTransportDelay_IWORK . Head ] == ssGetT ( S ) ) ) , _rtP -> P_130 , &
appliedDelay ) ; } _rtB -> B_15_76_616 = _rtX -> integrator_CSTATE ; _rtB ->
B_15_77_624 = ssGetT ( S ) ; isHit = ssIsSampleHit ( S , 1 , 0 ) ; if ( isHit
!= 0 ) { if ( ssIsModeUpdateTimeStep ( S ) ) { _rtDW ->
RelationalOperator_Mode_f = ( _rtB -> B_15_77_624 >= _rtB -> B_15_128_1032 )
; } _rtB -> B_15_235_1727 = _rtDW -> RelationalOperator_Mode_f ; } if ( _rtB
-> B_15_235_1727 ) { _rtB -> B_5_173_1392 = _rtB -> B_15_76_616 - _rtB ->
B_15_75_608 ; _rtB -> B_5_174_1400 = _rtB -> B_5_173_1392 * _rtB ->
B_15_73_592 ; _rtB -> B_15_78_632 = _rtB -> B_5_174_1400 ; } else { _rtB ->
B_15_78_632 = _rtB -> B_15_129_1040 ; } _rtB -> B_15_79_640 = _rtB ->
B_15_78_632 * _rtB -> B_4_185_1488 ; _rtB -> B_15_80_648 = _rtP -> P_132 *
_rtB -> B_15_79_640 ; _rtB -> B_15_81_656 = _rtP -> P_133 * _rtB ->
B_15_79_640 ; _rtB -> B_15_82_664 = _rtP -> P_134 * _rtB -> B_15_79_640 ;
_rtB -> B_15_83_672 = 0.0 ; _rtB -> B_15_83_672 += _rtP -> P_136 * _rtX ->
TransferFcn_CSTATE ; _rtB -> B_15_83_672 += _rtP -> P_137 * _rtB ->
B_15_82_664 ; _rtB -> B_15_84_680 = ( _rtB -> B_15_80_648 + _rtB ->
B_15_74_600 ) + _rtB -> B_15_83_672 ; if ( ssIsModeUpdateTimeStep ( S ) ) {
_rtDW -> Saturation2_MODE = _rtB -> B_15_84_680 >= _rtP -> P_138 ? 1 : _rtB
-> B_15_84_680 > _rtP -> P_139 ? 0 : - 1 ; } _rtB -> B_15_85_688 = _rtDW ->
Saturation2_MODE == 1 ? _rtP -> P_138 : _rtDW -> Saturation2_MODE == - 1 ?
_rtP -> P_139 : _rtB -> B_15_84_680 ; _rtB -> B_15_86_696 = _rtP -> P_140 *
_rtB -> B_15_85_688 ; if ( _rtDW -> LastMajorTime == ( rtInf ) ) { _rtB ->
B_15_87_704 = _rtB -> B_15_86_696 ; } else { rtb_B_14_291_2112 =
ssGetTaskTime ( S , 0 ) - _rtDW -> LastMajorTime ; if ( _rtDW ->
LastMajorTime == ssGetTaskTime ( S , 0 ) ) { if ( _rtDW -> PrevLimited ) {
_rtB -> B_15_87_704 = _rtDW -> PrevY ; } else { _rtB -> B_15_87_704 = _rtB ->
B_15_86_696 ; } } else { rtb_B_9_312_2280 = rtb_B_14_291_2112 * _rtP -> P_141
; rtb_B_14_292_2120 = _rtB -> B_15_86_696 - _rtDW -> PrevY ; if (
rtb_B_14_292_2120 > rtb_B_9_312_2280 ) { _rtB -> B_15_87_704 = _rtDW -> PrevY
+ rtb_B_9_312_2280 ; } else { rtb_B_14_291_2112 *= _rtP -> P_142 ; if (
rtb_B_14_292_2120 < rtb_B_14_291_2112 ) { _rtB -> B_15_87_704 = _rtDW ->
PrevY + rtb_B_14_291_2112 ; } else { _rtB -> B_15_87_704 = _rtB ->
B_15_86_696 ; rtb_B_15_383_2806 = false ; } } if ( ssIsModeUpdateTimeStep ( S
) ) { _rtDW -> PrevLimited = rtb_B_15_383_2806 ; } } } _rtB -> B_15_88_712 =
_rtX -> Integrator_x1_CSTATE ; _rtB -> B_15_89_720 = _rtP -> P_144 * _rtB ->
B_15_88_712 ; _rtB -> B_15_90_728 = _rtX -> Integrator_x2_CSTATE ; _rtB ->
B_15_91_736 = _rtP -> P_146 * _rtB -> B_15_90_728 ; _rtB -> B_15_92_744 =
_rtP -> P_147 * _rtB -> B_15_88_712 ; _rtB -> B_15_93_752 = _rtP -> P_148 *
_rtB -> B_15_90_728 ; _rtB -> B_15_94_760 = _rtB -> B_15_89_720 + _rtB ->
B_15_91_736 ; _rtB -> B_15_95_768 = _rtB -> B_15_92_744 + _rtB -> B_15_93_752
; _rtB -> B_15_96_776 = _rtP -> P_149 * _rtB -> B_15_87_704 ; _rtB ->
B_15_97_784 = _rtB -> B_15_94_760 + _rtB -> B_15_96_776 ; _rtB -> B_15_98_792
= _rtP -> P_150 * _rtB -> B_15_87_704 ; _rtB -> B_15_99_800 = _rtB ->
B_15_95_768 + _rtB -> B_15_98_792 ; _rtB -> B_15_100_808 = ( _rtP -> P_151 *
_rtB -> B_15_88_712 + _rtP -> P_152 * _rtB -> B_15_90_728 ) + _rtP -> P_153 *
_rtB -> B_15_87_704 ; if ( _rtB -> B_15_73_592 > _rtP -> P_154 ) { _rtB ->
B_15_101_816 = _rtP -> P_154 ; } else if ( _rtB -> B_15_73_592 < _rtP ->
P_155 ) { _rtB -> B_15_101_816 = _rtP -> P_155 ; } else { _rtB ->
B_15_101_816 = _rtB -> B_15_73_592 ; } _rtB -> B_15_102_824 = 1.0 / _rtB ->
B_15_101_816 ; rtb_B_14_292_2120 = _rtB -> B_15_70_568 [ 1 ] ;
rtb_B_9_312_2280 = _rtB -> B_15_70_568 [ 0 ] ; B_15_70_568_0 = _rtB ->
B_15_70_568 [ 2 ] ; for ( i = 0 ; i < 3 ; i ++ ) { B_15_359_2656_idx_0 = (
_rtP -> P_156 [ i + 3 ] * rtb_B_14_292_2120 + _rtP -> P_156 [ i ] *
rtb_B_9_312_2280 ) + _rtP -> P_156 [ i + 6 ] * B_15_70_568_0 ; _rtB ->
B_15_103_832 [ i ] = B_15_359_2656_idx_0 ; _rtB -> B_15_106_856 [ i ] = _rtP
-> P_157 * B_15_359_2656_idx_0 ; } spr_sim_Subsystempi2delay ( S , _rtB ->
B_15_213_1705 , & _rtB -> B_15_106_856 [ 0 ] , _rtB -> B_15_30_248 , & _rtB
-> Subsystempi2delay , & _rtDW -> Subsystempi2delay ) ; spr_sim_Subsystem1 (
S , _rtB -> B_15_212_1704 , & _rtB -> B_15_106_856 [ 0 ] , _rtB ->
B_15_30_248 , & _rtB -> Subsystem1 , & _rtDW -> Subsystem1 ) ; if ( _rtB ->
B_15_212_1704 != 0 ) { _rtB -> B_15_109_880 [ 0 ] = _rtB -> Subsystem1 .
B_3_248_1768 ; _rtB -> B_15_109_880 [ 1 ] = _rtB -> Subsystem1 . B_3_249_1776
; } else { _rtB -> B_15_109_880 [ 0 ] = _rtB -> Subsystempi2delay .
B_2_250_1784 ; _rtB -> B_15_109_880 [ 1 ] = _rtB -> Subsystempi2delay .
B_2_251_1792 ; } isHit = ssIsSampleHit ( S , 2 , 0 ) ; if ( isHit != 0 ) {
_rtB -> B_15_111_896 = _rtP -> P_158 * _rtB -> B_15_5_48 [ 13 ] ; _rtB ->
B_15_112_904 = _rtP -> P_159 * _rtB -> B_15_5_48 [ 12 ] ; ssCallAccelRunBlock
( S , 15 , 177 , SS_CALL_MDL_OUTPUTS ) ; rtb_B_15_283_2048 [ 0 ] = _rtB ->
B_15_111_896 ; rtb_B_15_283_2048 [ 1 ] = _rtB -> B_15_112_904 ; { if ( _rtDW
-> _asyncqueue_inserted_for_ToWorkspace1_PWORK . AQHandles && ssGetLogOutput
( S ) ) { sdiWriteSignal ( _rtDW ->
_asyncqueue_inserted_for_ToWorkspace1_PWORK . AQHandles , ssGetTaskTime ( S ,
2 ) , ( char * ) & rtb_B_15_283_2048 [ 0 ] + 0 ) ; } } } UNUSED_PARAMETER (
tid ) ; } static void mdlOutputsTID3 ( SimStruct * S , int_T tid ) {
B_spr_sim_T * _rtB ; DW_spr_sim_T * _rtDW ; P_spr_sim_T * _rtP ; int32_T i ;
_rtDW = ( ( DW_spr_sim_T * ) ssGetRootDWork ( S ) ) ; _rtP = ( ( P_spr_sim_T
* ) ssGetModelRtp ( S ) ) ; _rtB = ( ( B_spr_sim_T * ) _ssGetModelBlockIO ( S
) ) ; for ( i = 0 ; i < 6 ; i ++ ) { _rtB -> B_15_113_912 [ i ] = _rtP ->
P_160 [ i ] ; } _rtB -> B_15_119_960 = _rtP -> P_161 ; _rtB -> B_15_120_968 =
_rtP -> P_162 ; _rtB -> B_15_121_976 = _rtP -> P_163 ; _rtB -> B_15_122_984 =
_rtP -> P_164 ; _rtB -> B_15_123_992 = _rtP -> P_165 ; _rtB -> B_15_124_1000
= _rtP -> P_166 ; _rtB -> B_15_125_1008 = _rtP -> P_167 ; _rtB ->
B_4_198_1592 = _rtP -> P_15 ; _rtB -> B_4_199_1600 = _rtP -> P_16 ; _rtB ->
B_4_200_1608 = _rtP -> P_17 ; _rtB -> B_4_201_1616 = _rtP -> P_18 ; _rtB ->
B_4_214_1706 = ( uint8_T ) ( _rtP -> P_19 == _rtP -> P_20 ) ; _rtB ->
B_4_215_1707 = ( uint8_T ) ( _rtP -> P_19 == _rtP -> P_21 ) ; if (
ssIsModeUpdateTimeStep ( S ) ) { srUpdateBC ( _rtDW ->
AutomaticGainControl_SubsysRanBC ) ; } _rtB -> B_15_126_1016 = _rtP -> P_168
; _rtB -> B_15_127_1024 = _rtP -> P_169 ; _rtB -> B_15_128_1032 = _rtP ->
P_170 ; _rtB -> B_15_129_1040 = _rtP -> P_171 ; _rtB -> B_15_212_1704 = (
uint8_T ) ( _rtP -> P_172 == _rtP -> P_173 ) ; _rtB -> B_15_213_1705 = (
uint8_T ) ( _rtP -> P_172 == _rtP -> P_174 ) ; _rtB -> B_15_130_1048 = _rtP
-> P_176 * _rtP -> P_175 ; _rtB -> B_15_131_1056 = _rtP -> P_178 * _rtP ->
P_177 ; _rtB -> B_9_163_1312 = _rtP -> P_33 * _rtP -> P_32 ; switch ( (
int32_T ) ( _rtP -> P_34 + _rtP -> P_35 ) ) { case 1 : _rtB -> B_9_164_1320 [
0 ] = _rtP -> P_36 [ 0 ] ; _rtB -> B_9_164_1320 [ 1 ] = _rtP -> P_36 [ 1 ] ;
_rtB -> B_9_164_1320 [ 2 ] = _rtP -> P_36 [ 2 ] ; break ; case 2 : _rtB ->
B_9_164_1320 [ 0 ] = _rtP -> P_37 [ 0 ] ; _rtB -> B_9_164_1320 [ 1 ] = _rtP
-> P_37 [ 1 ] ; _rtB -> B_9_164_1320 [ 2 ] = _rtP -> P_37 [ 2 ] ; break ;
default : _rtB -> B_9_164_1320 [ 0 ] = _rtP -> P_38 [ 0 ] ; _rtB ->
B_9_164_1320 [ 1 ] = _rtP -> P_38 [ 1 ] ; _rtB -> B_9_164_1320 [ 2 ] = _rtP
-> P_38 [ 2 ] ; break ; } _rtB -> B_9_167_1344 = _rtP -> P_39 ; _rtB ->
B_9_168_1352 = _rtP -> P_41 * _rtP -> P_40 ; switch ( ( int32_T ) ( _rtP ->
P_42 + _rtP -> P_43 ) ) { case 1 : _rtB -> B_9_169_1360 [ 0 ] = _rtP -> P_44
[ 0 ] ; _rtB -> B_9_169_1360 [ 1 ] = _rtP -> P_44 [ 1 ] ; _rtB ->
B_9_169_1360 [ 2 ] = _rtP -> P_44 [ 2 ] ; break ; case 2 : _rtB ->
B_9_169_1360 [ 0 ] = _rtP -> P_45 [ 0 ] ; _rtB -> B_9_169_1360 [ 1 ] = _rtP
-> P_45 [ 1 ] ; _rtB -> B_9_169_1360 [ 2 ] = _rtP -> P_45 [ 2 ] ; break ;
default : _rtB -> B_9_169_1360 [ 0 ] = _rtP -> P_46 [ 0 ] ; _rtB ->
B_9_169_1360 [ 1 ] = _rtP -> P_46 [ 1 ] ; _rtB -> B_9_169_1360 [ 2 ] = _rtP
-> P_46 [ 2 ] ; break ; } _rtB -> B_9_172_1384 = _rtP -> P_47 ; if (
ssIsModeUpdateTimeStep ( S ) ) { srUpdateBC ( _rtDW ->
HarmonicGenerator_SubsysRanBC ) ; } _rtB -> B_15_132_1064 [ 0 ] = _rtP ->
P_179 [ 0 ] ; _rtB -> B_15_132_1064 [ 1 ] = _rtP -> P_179 [ 1 ] ; _rtB ->
B_15_132_1064 [ 2 ] = _rtP -> P_179 [ 2 ] ; _rtB -> B_14_146_1176 = _rtP ->
P_70 ; _rtB -> B_14_147_1184 = _rtP -> P_73 ; _rtB -> B_14_148_1192 = _rtP ->
P_74 ; _rtB -> B_14_237_1729 = ( _rtP -> P_76 == _rtP -> P_69 ) ; _rtB ->
B_14_238_1730 = ( _rtP -> P_76 == _rtP -> P_71 ) ; _rtB -> B_14_239_1731 = (
_rtP -> P_76 == _rtP -> P_72 ) ; _rtB -> B_14_149_1200 = _rtP -> P_77 ; _rtB
-> B_14_240_1732 = ( _rtB -> B_14_149_1200 == _rtP -> P_75 ) ; _rtB ->
B_14_150_1208 = _rtP -> P_79 ; _rtB -> B_14_151_1216 = _rtP -> P_82 ; _rtB ->
B_14_152_1224 = _rtP -> P_83 ; _rtB -> B_14_153_1232 = _rtP -> P_85 * _rtP ->
P_84 ; _rtB -> B_14_241_1733 = ( _rtB -> B_14_149_1200 == _rtP -> P_81 ) ; if
( _rtB -> B_14_149_1200 == _rtP -> P_78 ) { _rtB -> B_14_154_1240 = _rtP ->
P_86 ; } else { _rtB -> B_14_154_1240 = _rtP -> P_80 ; } _rtB ->
B_14_155_1248 = _rtP -> P_87 ; _rtB -> B_14_156_1256 = _rtP -> P_88 ; if (
ssIsModeUpdateTimeStep ( S ) ) { srUpdateBC ( _rtDW ->
Signalgenerator_SubsysRanBC ) ; } _rtB -> B_15_135_1088 = _rtP -> P_180 ;
_rtB -> B_15_136_1096 = _rtP -> P_181 ; UNUSED_PARAMETER ( tid ) ; }
#define MDL_UPDATE
static void mdlUpdate ( SimStruct * S , int_T tid ) { B_spr_sim_T * _rtB ;
DW_spr_sim_T * _rtDW ; P_spr_sim_T * _rtP ; XDis_spr_sim_T * _rtXdis ;
int32_T i ; _rtDW = ( ( DW_spr_sim_T * ) ssGetRootDWork ( S ) ) ; _rtXdis = (
( XDis_spr_sim_T * ) ssGetContStateDisabled ( S ) ) ; _rtP = ( ( P_spr_sim_T
* ) ssGetModelRtp ( S ) ) ; _rtB = ( ( B_spr_sim_T * ) _ssGetModelBlockIO ( S
) ) ; i = ssIsSampleHit ( S , 2 , 0 ) ; if ( i != 0 ) { if ( _rtDW ->
Signalgenerator_MODE ) { i = ssIsSampleHit ( S , 2 , 0 ) ; if ( i != 0 ) {
_rtDW -> DiscreteTimeIntegrator_DSTATE += _rtP -> P_55 * _rtB ->
B_14_141_1136 ; _rtDW -> DiscreteTimeIntegrator1_DSTATE += _rtP -> P_63 *
_rtB -> B_14_145_1168 ; _rtDW -> UnitDelay_DSTATE = _rtB -> B_14_140_1128 ; }
} ssCallAccelRunBlock ( S , 15 , 15 , SS_CALL_MDL_UPDATE ) ; } _rtDW ->
Integrator_IWORK = 0 ; switch ( _rtDW -> Integrator_MODE ) { case 3 : if (
_rtB -> B_15_85_688 < 0.0 ) { _rtDW -> Integrator_MODE = 1 ;
ssSetBlockStateForSolverChangedAtMajorStep ( S ) ; } break ; case 4 : if (
_rtB -> B_15_85_688 > 0.0 ) { _rtDW -> Integrator_MODE = 2 ;
ssSetBlockStateForSolverChangedAtMajorStep ( S ) ; } break ; } _rtXdis ->
Integrator_CSTATE = ( ( _rtDW -> Integrator_MODE == 3 ) || ( _rtDW ->
Integrator_MODE == 4 ) ) ; i = ssIsSampleHit ( S , 1 , 0 ) ; if ( i != 0 ) {
for ( i = 0 ; i < 6 ; i ++ ) { _rtDW -> ICic_PreviousInput [ i ] = _rtB ->
B_15_50_408 [ i ] ; } _rtDW -> Memory_PreviousInput = _rtB -> B_15_100_808 ;
} if ( _rtDW -> AutomaticGainControl_MODE ) { { real_T * * uBuffer = ( real_T
* * ) & _rtDW -> VariableTransportDelay_PWORK_a . TUbufferPtrs [ 0 ] ; real_T
simTime = ssGetT ( S ) ; _rtDW -> VariableTransportDelay_IWORK_m . Head = ( (
_rtDW -> VariableTransportDelay_IWORK_m . Head < ( _rtDW ->
VariableTransportDelay_IWORK_m . CircularBufSize - 1 ) ) ? ( _rtDW ->
VariableTransportDelay_IWORK_m . Head + 1 ) : 0 ) ; if ( _rtDW ->
VariableTransportDelay_IWORK_m . Head == _rtDW ->
VariableTransportDelay_IWORK_m . Tail ) { if ( !
spr_sim_acc_rt_TDelayUpdateTailOrGrowBuf ( & _rtDW ->
VariableTransportDelay_IWORK_m . CircularBufSize , & _rtDW ->
VariableTransportDelay_IWORK_m . Tail , & _rtDW ->
VariableTransportDelay_IWORK_m . Head , & _rtDW ->
VariableTransportDelay_IWORK_m . Last , simTime - _rtP -> P_1 , uBuffer , (
boolean_T ) 0 , ( boolean_T ) 1 , & _rtDW -> VariableTransportDelay_IWORK_m .
MaxNewBufSize ) ) { ssSetErrorStatus ( S , "vtdelay memory allocation error"
) ; return ; } } ( * uBuffer + _rtDW -> VariableTransportDelay_IWORK_m .
CircularBufSize ) [ _rtDW -> VariableTransportDelay_IWORK_m . Head ] =
simTime ; ( * uBuffer + 2 * _rtDW -> VariableTransportDelay_IWORK_m .
CircularBufSize ) [ _rtDW -> VariableTransportDelay_IWORK_m . Head ] = ( (
X_spr_sim_T * ) ssGetContStates ( S ) ) -> VariableTransportDelay_CSTATE_f ;
( * uBuffer ) [ _rtDW -> VariableTransportDelay_IWORK_m . Head ] = _rtB ->
B_4_176_1416 ; } { real_T * * uBuffer = ( real_T * * ) & _rtDW ->
VariableTransportDelay_PWORK_g . TUbufferPtrs [ 0 ] ; real_T simTime = ssGetT
( S ) ; _rtDW -> VariableTransportDelay_IWORK_p . Head = ( ( _rtDW ->
VariableTransportDelay_IWORK_p . Head < ( _rtDW ->
VariableTransportDelay_IWORK_p . CircularBufSize - 1 ) ) ? ( _rtDW ->
VariableTransportDelay_IWORK_p . Head + 1 ) : 0 ) ; if ( _rtDW ->
VariableTransportDelay_IWORK_p . Head == _rtDW ->
VariableTransportDelay_IWORK_p . Tail ) { if ( !
spr_sim_acc_rt_TDelayUpdateTailOrGrowBuf ( & _rtDW ->
VariableTransportDelay_IWORK_p . CircularBufSize , & _rtDW ->
VariableTransportDelay_IWORK_p . Tail , & _rtDW ->
VariableTransportDelay_IWORK_p . Head , & _rtDW ->
VariableTransportDelay_IWORK_p . Last , simTime - _rtP -> P_4 , uBuffer , (
boolean_T ) 0 , ( boolean_T ) 1 , & _rtDW -> VariableTransportDelay_IWORK_p .
MaxNewBufSize ) ) { ssSetErrorStatus ( S , "vtdelay memory allocation error"
) ; return ; } } ( * uBuffer + _rtDW -> VariableTransportDelay_IWORK_p .
CircularBufSize ) [ _rtDW -> VariableTransportDelay_IWORK_p . Head ] =
simTime ; ( * uBuffer + 2 * _rtDW -> VariableTransportDelay_IWORK_p .
CircularBufSize ) [ _rtDW -> VariableTransportDelay_IWORK_p . Head ] = ( (
X_spr_sim_T * ) ssGetContStates ( S ) ) -> VariableTransportDelay_CSTATE_e ;
( * uBuffer ) [ _rtDW -> VariableTransportDelay_IWORK_p . Head ] = _rtB ->
B_4_180_1448 ; } } switch ( _rtDW -> Integrator_MODE_c ) { case 3 : if ( _rtB
-> B_15_81_656 < 0.0 ) { _rtDW -> Integrator_MODE_c = 1 ;
ssSetBlockStateForSolverChangedAtMajorStep ( S ) ; } break ; case 4 : if (
_rtB -> B_15_81_656 > 0.0 ) { _rtDW -> Integrator_MODE_c = 2 ;
ssSetBlockStateForSolverChangedAtMajorStep ( S ) ; } break ; } _rtXdis ->
Integrator_CSTATE_c = ( ( _rtDW -> Integrator_MODE_c == 3 ) || ( _rtDW ->
Integrator_MODE_c == 4 ) ) ; { real_T * * uBuffer = ( real_T * * ) & _rtDW ->
VariableTransportDelay_PWORK . TUbufferPtrs [ 0 ] ; real_T simTime = ssGetT (
S ) ; _rtDW -> VariableTransportDelay_IWORK . Head = ( ( _rtDW ->
VariableTransportDelay_IWORK . Head < ( _rtDW -> VariableTransportDelay_IWORK
. CircularBufSize - 1 ) ) ? ( _rtDW -> VariableTransportDelay_IWORK . Head +
1 ) : 0 ) ; if ( _rtDW -> VariableTransportDelay_IWORK . Head == _rtDW ->
VariableTransportDelay_IWORK . Tail ) { if ( !
spr_sim_acc_rt_TDelayUpdateTailOrGrowBuf ( & _rtDW ->
VariableTransportDelay_IWORK . CircularBufSize , & _rtDW ->
VariableTransportDelay_IWORK . Tail , & _rtDW -> VariableTransportDelay_IWORK
. Head , & _rtDW -> VariableTransportDelay_IWORK . Last , simTime - _rtP ->
P_129 , uBuffer , ( boolean_T ) 0 , ( boolean_T ) 1 , & _rtDW ->
VariableTransportDelay_IWORK . MaxNewBufSize ) ) { ssSetErrorStatus ( S ,
"vtdelay memory allocation error" ) ; return ; } } ( * uBuffer + _rtDW ->
VariableTransportDelay_IWORK . CircularBufSize ) [ _rtDW ->
VariableTransportDelay_IWORK . Head ] = simTime ; ( * uBuffer + 2 * _rtDW ->
VariableTransportDelay_IWORK . CircularBufSize ) [ _rtDW ->
VariableTransportDelay_IWORK . Head ] = ( ( X_spr_sim_T * ) ssGetContStates (
S ) ) -> VariableTransportDelay_CSTATE ; ( * uBuffer ) [ _rtDW ->
VariableTransportDelay_IWORK . Head ] = _rtB -> B_15_76_616 ; } _rtDW ->
PrevY = _rtB -> B_15_87_704 ; _rtDW -> LastMajorTime = ssGetTaskTime ( S , 0
) ; UNUSED_PARAMETER ( tid ) ; }
#define MDL_UPDATE
static void mdlUpdateTID3 ( SimStruct * S , int_T tid ) { UNUSED_PARAMETER (
tid ) ; }
#define MDL_DERIVATIVES
static void mdlDerivatives ( SimStruct * S ) { B_spr_sim_T * _rtB ;
DW_spr_sim_T * _rtDW ; P_spr_sim_T * _rtP ; XDis_spr_sim_T * _rtXdis ;
XDot_spr_sim_T * _rtXdot ; X_spr_sim_T * _rtX ; _rtDW = ( ( DW_spr_sim_T * )
ssGetRootDWork ( S ) ) ; _rtXdis = ( ( XDis_spr_sim_T * )
ssGetContStateDisabled ( S ) ) ; _rtXdot = ( ( XDot_spr_sim_T * ) ssGetdX ( S
) ) ; _rtX = ( ( X_spr_sim_T * ) ssGetContStates ( S ) ) ; _rtP = ( (
P_spr_sim_T * ) ssGetModelRtp ( S ) ) ; _rtB = ( ( B_spr_sim_T * )
_ssGetModelBlockIO ( S ) ) ; if ( _rtXdis -> Integrator_CSTATE ) { _rtXdot ->
Integrator_CSTATE = 0.0 ; } else { _rtXdot -> Integrator_CSTATE = _rtB ->
B_15_85_688 ; } if ( _rtDW -> AutomaticGainControl_MODE ) { { real_T
instantDelay ; instantDelay = _rtB -> B_4_187_1504 ; if ( instantDelay > _rtP
-> P_1 ) { instantDelay = _rtP -> P_1 ; } if ( instantDelay < 0.0 ) { ( (
XDot_spr_sim_T * ) ssGetdX ( S ) ) -> VariableTransportDelay_CSTATE_f = 0 ; }
else { ( ( XDot_spr_sim_T * ) ssGetdX ( S ) ) ->
VariableTransportDelay_CSTATE_f = 1.0 / instantDelay ; } } _rtXdot ->
integrator_CSTATE_c = _rtB -> B_4_196_1576 [ 0 ] ; { real_T instantDelay ;
instantDelay = _rtB -> B_4_189_1520 ; if ( instantDelay > _rtP -> P_4 ) {
instantDelay = _rtP -> P_4 ; } if ( instantDelay < 0.0 ) { ( ( XDot_spr_sim_T
* ) ssGetdX ( S ) ) -> VariableTransportDelay_CSTATE_e = 0 ; } else { ( (
XDot_spr_sim_T * ) ssGetdX ( S ) ) -> VariableTransportDelay_CSTATE_e = 1.0 /
instantDelay ; } } _rtXdot -> integrator_CSTATE_cy = _rtB -> B_4_196_1576 [ 1
] ; } else { { real_T * dx ; int_T i ; dx = & ( ( ( XDot_spr_sim_T * )
ssGetdX ( S ) ) -> VariableTransportDelay_CSTATE_f ) ; for ( i = 0 ; i < 4 ;
i ++ ) { dx [ i ] = 0.0 ; } } } if ( _rtXdis -> Integrator_CSTATE_c ) {
_rtXdot -> Integrator_CSTATE_c = 0.0 ; } else { _rtXdot ->
Integrator_CSTATE_c = _rtB -> B_15_81_656 ; } { real_T instantDelay ;
instantDelay = _rtB -> B_15_102_824 ; if ( instantDelay > _rtP -> P_129 ) {
instantDelay = _rtP -> P_129 ; } if ( instantDelay < 0.0 ) { ( (
XDot_spr_sim_T * ) ssGetdX ( S ) ) -> VariableTransportDelay_CSTATE = 0 ; }
else { ( ( XDot_spr_sim_T * ) ssGetdX ( S ) ) ->
VariableTransportDelay_CSTATE = 1.0 / instantDelay ; } } _rtXdot ->
integrator_CSTATE = _rtB -> B_15_109_880 [ 1 ] ; _rtXdot ->
TransferFcn_CSTATE = 0.0 ; _rtXdot -> TransferFcn_CSTATE += _rtP -> P_135 *
_rtX -> TransferFcn_CSTATE ; _rtXdot -> TransferFcn_CSTATE += _rtB ->
B_15_82_664 ; _rtXdot -> Integrator_x1_CSTATE = _rtB -> B_15_97_784 ; _rtXdot
-> Integrator_x2_CSTATE = _rtB -> B_15_99_800 ; }
#define MDL_ZERO_CROSSINGS
static void mdlZeroCrossings ( SimStruct * S ) { B_spr_sim_T * _rtB ;
DW_spr_sim_T * _rtDW ; P_spr_sim_T * _rtP ; X_spr_sim_T * _rtX ;
ZCV_spr_sim_T * _rtZCSV ; real_T B_15_38_312_0 ; int32_T i ; _rtDW = ( (
DW_spr_sim_T * ) ssGetRootDWork ( S ) ) ; _rtZCSV = ( ( ZCV_spr_sim_T * )
ssGetSolverZcSignalVector ( S ) ) ; _rtX = ( ( X_spr_sim_T * )
ssGetContStates ( S ) ) ; _rtP = ( ( P_spr_sim_T * ) ssGetModelRtp ( S ) ) ;
_rtB = ( ( B_spr_sim_T * ) _ssGetModelBlockIO ( S ) ) ; _rtZCSV ->
RelationalOperator_RelopInput_ZC = _rtX -> Integrator_CSTATE - _rtB ->
B_15_127_1024 ; switch ( _rtDW -> Integrator_MODE ) { case 1 : _rtZCSV ->
Integrator_IntgUpLimit_ZC = 0.0 ; _rtZCSV -> Integrator_IntgLoLimit_ZC = _rtP
-> P_103 - _rtP -> P_104 ; break ; case 2 : _rtZCSV ->
Integrator_IntgUpLimit_ZC = _rtP -> P_104 - _rtP -> P_103 ; _rtZCSV ->
Integrator_IntgLoLimit_ZC = 0.0 ; break ; default : _rtZCSV ->
Integrator_IntgUpLimit_ZC = _rtX -> Integrator_CSTATE - _rtP -> P_103 ;
_rtZCSV -> Integrator_IntgLoLimit_ZC = _rtX -> Integrator_CSTATE - _rtP ->
P_104 ; break ; } if ( ( _rtDW -> Integrator_MODE == 3 ) || ( _rtDW ->
Integrator_MODE == 4 ) ) { _rtZCSV -> Integrator_LeaveSaturate_ZC = _rtB ->
B_15_85_688 ; } else { _rtZCSV -> Integrator_LeaveSaturate_ZC = 0.0 ; } for (
i = 0 ; i < 6 ; i ++ ) { B_15_38_312_0 = _rtB -> B_15_38_312 [ i ] ; _rtZCSV
-> RelationalOperator2_RelopInput_ZC [ i ] = B_15_38_312_0 - _rtB ->
B_15_125_1008 ; _rtZCSV -> RelationalOperator4_RelopInput_ZC [ i ] =
B_15_38_312_0 - _rtB -> B_15_57_464 [ i ] ; } _rtZCSV ->
HitCrossing_HitNoOutput_ZC = _rtB -> B_15_30_248 - _rtP -> P_124 ; if ( _rtDW
-> AutomaticGainControl_MODE ) { _rtZCSV ->
RelationalOperator_RelopInput_ZC_e = _rtB -> B_4_177_1424 - _rtB ->
B_4_198_1592 ; _rtZCSV -> RelationalOperator_RelopInput_ZC_d = _rtB ->
B_4_181_1456 - _rtB -> B_4_200_1608 ; _rtZCSV -> Saturation_UprLim_ZC = _rtB
-> B_4_183_1472 - _rtP -> P_7 ; _rtZCSV -> Saturation_LwrLim_ZC = _rtB ->
B_4_183_1472 - _rtP -> P_8 ; } else { { real_T * zcsv = & ( ( ( ZCV_spr_sim_T
* ) ssGetSolverZcSignalVector ( S ) ) -> RelationalOperator_RelopInput_ZC_e )
; int_T i ; for ( i = 0 ; i < 4 ; i ++ ) { zcsv [ i ] = 0.0 ; } } } switch (
_rtDW -> Integrator_MODE_c ) { case 1 : _rtZCSV ->
Integrator_IntgUpLimit_ZC_k = 0.0 ; _rtZCSV -> Integrator_IntgLoLimit_ZC_a =
_rtP -> P_127 - _rtP -> P_128 ; break ; case 2 : _rtZCSV ->
Integrator_IntgUpLimit_ZC_k = _rtP -> P_128 - _rtP -> P_127 ; _rtZCSV ->
Integrator_IntgLoLimit_ZC_a = 0.0 ; break ; default : _rtZCSV ->
Integrator_IntgUpLimit_ZC_k = _rtX -> Integrator_CSTATE_c - _rtP -> P_127 ;
_rtZCSV -> Integrator_IntgLoLimit_ZC_a = _rtX -> Integrator_CSTATE_c - _rtP
-> P_128 ; break ; } if ( ( _rtDW -> Integrator_MODE_c == 3 ) || ( _rtDW ->
Integrator_MODE_c == 4 ) ) { _rtZCSV -> Integrator_LeaveSaturate_ZC_h = _rtB
-> B_15_81_656 ; } else { _rtZCSV -> Integrator_LeaveSaturate_ZC_h = 0.0 ; }
_rtZCSV -> RelationalOperator_RelopInput_ZC_p = _rtB -> B_15_77_624 - _rtB ->
B_15_128_1032 ; _rtZCSV -> Saturation2_UprLim_ZC = _rtB -> B_15_84_680 - _rtP
-> P_138 ; _rtZCSV -> Saturation2_LwrLim_ZC = _rtB -> B_15_84_680 - _rtP ->
P_139 ; } static void mdlInitializeSizes ( SimStruct * S ) { ssSetChecksumVal
( S , 0 , 651609460U ) ; ssSetChecksumVal ( S , 1 , 4139729473U ) ;
ssSetChecksumVal ( S , 2 , 1577264599U ) ; ssSetChecksumVal ( S , 3 ,
1982999488U ) ; { mxArray * slVerStructMat = ( NULL ) ; mxArray * slStrMat =
mxCreateString ( "simulink" ) ; char slVerChar [ 10 ] ; int status =
mexCallMATLAB ( 1 , & slVerStructMat , 1 , & slStrMat , "ver" ) ; if ( status
== 0 ) { mxArray * slVerMat = mxGetField ( slVerStructMat , 0 , "Version" ) ;
if ( slVerMat == ( NULL ) ) { status = 1 ; } else { status = mxGetString (
slVerMat , slVerChar , 10 ) ; } } mxDestroyArray ( slStrMat ) ;
mxDestroyArray ( slVerStructMat ) ; if ( ( status == 1 ) || ( strcmp (
slVerChar , "23.2" ) != 0 ) ) { return ; } } ssSetOptions ( S ,
SS_OPTION_EXCEPTION_FREE_CODE ) ; if ( ssGetSizeofDWork ( S ) != ( SLSize )
sizeof ( DW_spr_sim_T ) ) { static char msg [ 256 ] ; snprintf ( msg , 256 ,
"Unexpected error: Internal DWork sizes do "
"not match for accelerator mex file (%ld vs %lu)." , ( signed long )
ssGetSizeofDWork ( S ) , ( unsigned long ) sizeof ( DW_spr_sim_T ) ) ;
ssSetErrorStatus ( S , msg ) ; } if ( ssGetSizeofGlobalBlockIO ( S ) != (
SLSize ) sizeof ( B_spr_sim_T ) ) { static char msg [ 256 ] ; snprintf ( msg
, 256 , "Unexpected error: Internal BlockIO sizes do "
"not match for accelerator mex file (%ld vs %lu)." , ( signed long )
ssGetSizeofGlobalBlockIO ( S ) , ( unsigned long ) sizeof ( B_spr_sim_T ) ) ;
ssSetErrorStatus ( S , msg ) ; } { int ssSizeofParams ; ssGetSizeofParams ( S
, & ssSizeofParams ) ; if ( ssSizeofParams != sizeof ( P_spr_sim_T ) ) {
static char msg [ 256 ] ; snprintf ( msg , 256 ,
"Unexpected error: Internal Parameters sizes do "
"not match for accelerator mex file (%d vs %lu)." , ssSizeofParams , (
unsigned long ) sizeof ( P_spr_sim_T ) ) ; ssSetErrorStatus ( S , msg ) ; } }
_ssSetModelRtp ( S , ( real_T * ) & spr_sim_rtDefaultP ) ; rt_InitInfAndNaN (
sizeof ( real_T ) ) ; ( ( P_spr_sim_T * ) ssGetModelRtp ( S ) ) -> P_7 =
rtInf ; ( ( P_spr_sim_T * ) ssGetModelRtp ( S ) ) -> P_103 = rtInf ; ( (
P_spr_sim_T * ) ssGetModelRtp ( S ) ) -> P_104 = rtMinusInf ; ( ( P_spr_sim_T
* ) ssGetModelRtp ( S ) ) -> P_127 = rtInf ; ( ( P_spr_sim_T * )
ssGetModelRtp ( S ) ) -> P_138 = rtInf ; } static void
mdlInitializeSampleTimes ( SimStruct * S ) { slAccRegPrmChangeFcn ( S ,
mdlOutputsTID3 ) ; } static void mdlTerminate ( SimStruct * S ) { }
#include "simulink.c"
