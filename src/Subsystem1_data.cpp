//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: Subsystem1_data.cpp
//
// Code generated for Simulink model 'Subsystem1'.
//
// Model version                  : 3.4
// Simulink Coder version         : 9.9 (R2023a) 19-Nov-2022
// C/C++ source code generated on : Wed Jun 28 16:26:54 2023
//
// Target selection: ert.tlc
// Embedded hardware selection: Intel->x86-64 (Linux 64)
// Code generation objectives:
//    1. Execution efficiency
//    2. RAM efficiency
// Validation result: Not run
//
#include "Subsystem1.h"

// Constant parameters (default storage)
const Subsystem1::ConstP rtConstP{
  // Expression: D0
  //  Referenced by: '<S2>/Inner-loop control'

  { 10.0, 0.0, 0.0, 0.0, 10.0, 0.0, 0.0, 0.0, 10.0 },

  // Pooled Parameter (Expression: Ib)
  //  Referenced by:
  //    '<S1>/MATLAB Function'
  //    '<S1>/MATLAB Function1'
  //    '<S2>/Inner-loop control'

  { 0.0347563, 0.0, 0.0, 0.0, 0.0458929, 0.0, 0.0, 0.0, 0.0977 },

  // Expression: K0
  //  Referenced by: '<S2>/Inner-loop control'

  { 100.0, 0.0, 0.0, 0.0, 100.0, 0.0, 0.0, 0.0, 100.0 },

  // Expression: M_bar
  //  Referenced by: '<S1>/MATLAB Function2'

  { 0.171, 0.2962, -0.9397, 0.1092, 0.1639, 0.0886, -0.342, 0.0, -0.9397, 0.1966,
    0.0127, -0.0886, 0.171, -0.2962, -0.9397, 0.0873, -0.1766, 0.0886, 0.171,
    0.2962, -0.9397, -0.0873, -0.1766, -0.0886, -0.342, 0.0, -0.9397, -0.1966,
    0.0127, 0.0886, 0.171, -0.2962, -0.9397, -0.1092, 0.1639, -0.0886 },

  // Expression: Kd
  //  Referenced by: '<S1>/Outer-loop control'

  { 54.000000000000064, 0.0, 0.0, 0.0, 42.000000000000043, 0.0, 0.0, 0.0,
    26.000000000000004 },

  // Expression: Kp
  //  Referenced by: '<S1>/Outer-loop control'

  { 728.00000000000182, 0.0, 0.0, 0.0, 440.0000000000008, 0.0, 0.0, 0.0,
    48.000000000000007 }
};

//
// File trailer for generated code.
//
// [EOF]
//
