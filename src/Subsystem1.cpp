//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: Subsystem1.cpp
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
#include <cmath>
#include <emmintrin.h>
#include <cstring>
#include "rtwtypes.h"
#include <stddef.h>
#define NumBitsPerChar                 8U
#define Ts 0.001

extern "C"
{
  real_T rtInf;
  real_T rtMinusInf;
  real_T rtNaN;
  real32_T rtInfF;
  real32_T rtMinusInfF;
  real32_T rtNaNF;
}

extern "C"
{
  //
  // Initialize rtNaN needed by the generated code.
  // NaN is initialized as non-signaling. Assumes IEEE.
  //
  static real_T rtGetNaN(void)
  {
    size_t bitsPerReal{ sizeof(real_T) * (NumBitsPerChar) };

    real_T nan{ 0.0 };

    if (bitsPerReal == 32U) {
      nan = rtGetNaNF();
    } else {
      union {
        LittleEndianIEEEDouble bitVal;
        real_T fltVal;
      } tmpVal;

      tmpVal.bitVal.words.wordH = 0xFFF80000U;
      tmpVal.bitVal.words.wordL = 0x00000000U;
      nan = tmpVal.fltVal;
    }

    return nan;
  }

  //
  // Initialize rtNaNF needed by the generated code.
  // NaN is initialized as non-signaling. Assumes IEEE.
  //
  static real32_T rtGetNaNF(void)
  {
    IEEESingle nanF{ { 0.0F } };

    nanF.wordL.wordLuint = 0xFFC00000U;
    return nanF.wordL.wordLreal;
  }
}

extern "C"
{
  //
  // Initialize the rtInf, rtMinusInf, and rtNaN needed by the
  // generated code. NaN is initialized as non-signaling. Assumes IEEE.
  //
  static void rt_InitInfAndNaN(size_t realSize)
  {
    (void) (realSize);
    rtNaN = rtGetNaN();
    rtNaNF = rtGetNaNF();
    rtInf = rtGetInf();
    rtInfF = rtGetInfF();
    rtMinusInf = rtGetMinusInf();
    rtMinusInfF = rtGetMinusInfF();
  }

  // Test if value is infinite
  static boolean_T rtIsInf(real_T value)
  {
    return (boolean_T)((value==rtInf || value==rtMinusInf) ? 1U : 0U);
  }

  // Test if single-precision value is infinite
  static boolean_T rtIsInfF(real32_T value)
  {
    return (boolean_T)(((value)==rtInfF || (value)==rtMinusInfF) ? 1U : 0U);
  }

  // Test if value is not a number
  static boolean_T rtIsNaN(real_T value)
  {
    boolean_T result{ (boolean_T) 0 };

    size_t bitsPerReal{ sizeof(real_T) * (NumBitsPerChar) };

    if (bitsPerReal == 32U) {
      result = rtIsNaNF((real32_T)value);
    } else {
      union {
        LittleEndianIEEEDouble bitVal;
        real_T fltVal;
      } tmpVal;

      tmpVal.fltVal = value;
      result = (boolean_T)((tmpVal.bitVal.words.wordH & 0x7FF00000) ==
                           0x7FF00000 &&
                           ( (tmpVal.bitVal.words.wordH & 0x000FFFFF) != 0 ||
                            (tmpVal.bitVal.words.wordL != 0) ));
    }

    return result;
  }

  // Test if single-precision value is not a number
  static boolean_T rtIsNaNF(real32_T value)
  {
    IEEESingle tmp;
    tmp.wordL.wordLreal = value;
    return (boolean_T)( (tmp.wordL.wordLuint & 0x7F800000) == 0x7F800000 &&
                       (tmp.wordL.wordLuint & 0x007FFFFF) != 0 );
  }
}

extern "C"
{
  //
  // Initialize rtInf needed by the generated code.
  // Inf is initialized as non-signaling. Assumes IEEE.
  //
  static real_T rtGetInf(void)
  {
    size_t bitsPerReal{ sizeof(real_T) * (NumBitsPerChar) };

    real_T inf{ 0.0 };

    if (bitsPerReal == 32U) {
      inf = rtGetInfF();
    } else {
      union {
        LittleEndianIEEEDouble bitVal;
        real_T fltVal;
      } tmpVal;

      tmpVal.bitVal.words.wordH = 0x7FF00000U;
      tmpVal.bitVal.words.wordL = 0x00000000U;
      inf = tmpVal.fltVal;
    }

    return inf;
  }

  //
  // Initialize rtInfF needed by the generated code.
  // Inf is initialized as non-signaling. Assumes IEEE.
  //
  static real32_T rtGetInfF(void)
  {
    IEEESingle infF;
    infF.wordL.wordLuint = 0x7F800000U;
    return infF.wordL.wordLreal;
  }

  //
  // Initialize rtMinusInf needed by the generated code.
  // Inf is initialized as non-signaling. Assumes IEEE.
  //
  static real_T rtGetMinusInf(void)
  {
    size_t bitsPerReal{ sizeof(real_T) * (NumBitsPerChar) };

    real_T minf{ 0.0 };

    if (bitsPerReal == 32U) {
      minf = rtGetMinusInfF();
    } else {
      union {
        LittleEndianIEEEDouble bitVal;
        real_T fltVal;
      } tmpVal;

      tmpVal.bitVal.words.wordH = 0xFFF00000U;
      tmpVal.bitVal.words.wordL = 0x00000000U;
      minf = tmpVal.fltVal;
    }

    return minf;
  }

  //
  // Initialize rtMinusInfF needed by the generated code.
  // Inf is initialized as non-signaling. Assumes IEEE.
  //
  static real32_T rtGetMinusInfF(void)
  {
    IEEESingle minfF;
    minfF.wordL.wordLuint = 0xFF800000U;
    return minfF.wordL.wordLreal;
  }
}

// Model step function
void Subsystem1::step()
{
  static const real_T b[3]{ 0.0, 0.0, 9.81 };

  static const real_T b_1[3]{ 0.0, 0.0, 9.81 };

  static const int8_T b_0[9]{ 1, 0, 0, 0, 1, 0, 0, 0, 1 };

  __m128d tmp_2;
  __m128d tmp_3;
  __m128d tmp_4;
  __m128d tmp_5;
  __m128d tmp_6;
  __m128d tmp_7;
  __m128d tmp_8;
  __m128d tmp_9;
  __m128d tmp_a;
  real_T A[36];
  real_T A_0[9];
  real_T A_1[9];
  real_T A_2[9];
  real_T A_3[9];
  real_T B_tmp[9];
  real_T Q_tmp[9];
  real_T Q_tmp_0[9];
  real_T Q_tmp_1[9];
  real_T a[9];
  real_T tmp_0[9];
  real_T tmp_1[9];
  real_T omega2[6];
  real_T rtb_Gain[6];
  real_T rtb_Gain1[6];
  real_T rtb_TmpSignalConversionAtSFunct[6];
  real_T tmp[6];
  real_T Derivation[3];
  real_T Derivation1[3];
  real_T Derivation1_tmp[3];
  real_T Derivation_tmp[3];
  real_T ct[3];
  real_T ct_0[3];
  real_T rtb_err_eta[3];
  real_T rtb_err_eta_dot[3];
  real_T rtb_err_eta_dot_0[3];
  real_T rtb_tau[3];
  real_T Q_tmp_2;
  real_T Q_tmp_3;
  real_T Q_tmp_4;
  real_T Q_tmp_tmp;
  real_T Q_tmp_tmp_0;
  real_T Q_tmp_tmp_1;
  real_T Q_tmp_tmp_2;
  real_T Q_tmp_tmp_tmp;
  real_T a_tmp;
  real_T a_tmp_0;
  real_T s;
  real_T smax;
  real_T st_idx_0;
  real_T st_idx_1;
  real_T st_idx_2;
  int32_T b_ix;
  int32_T c_k;
  int32_T ijA;
  int32_T iy;
  int32_T jj;
  int32_T kAcol;
  int32_T vectorUB;
  int8_T ipiv[6];
  int8_T ipiv_0;

  // Outputs for Atomic SubSystem: '<Root>/Subsystem1'
  // MATLAB Function: '<S1>/MATLAB Function' incorporates:
  //   Inport: '<Root>/eta'
  //   Inport: '<Root>/eta_dot'
  //   Inport: '<Root>/linear_vel'
  //   MATLAB Function: '<S1>/MATLAB Function1'
  //   MATLAB Function: '<S1>/Outer-loop control'
  //   MATLAB Function: '<S2>/Inner-loop control'

  Q_tmp_tmp_0 = std::sin(rtU.eta[0]);
  Q_tmp_tmp_1 = std::cos(rtU.eta[1]);
  Q_tmp_tmp = std::cos(rtU.eta[0]);
  Q_tmp_tmp_tmp = std::sin(rtU.eta[1]);
  Q_tmp[0] = 1.0;
  Q_tmp[3] = 0.0;
  Q_tmp[6] = -Q_tmp_tmp_tmp;
  Q_tmp[1] = 0.0;
  Q_tmp[4] = Q_tmp_tmp;
  Q_tmp[7] = Q_tmp_tmp_1 * Q_tmp_tmp_0;
  Q_tmp[2] = 0.0;
  Q_tmp[5] = -Q_tmp_tmp_0;
  Q_tmp_tmp_2 = Q_tmp_tmp_1 * Q_tmp_tmp;
  Q_tmp[8] = Q_tmp_tmp_2;
  for (kAcol = 0; kAcol < 3; kAcol++) {
    Q_tmp_2 = Q_tmp[3 * kAcol + 1];
    Q_tmp_3 = Q_tmp[3 * kAcol];
    Q_tmp_4 = Q_tmp[3 * kAcol + 2];
    for (jj = 0; jj < 3; jj++) {
      Q_tmp_0[kAcol + 3 * jj] = (rtConstP.pooled1[3 * jj + 1] * Q_tmp_2 +
        rtConstP.pooled1[3 * jj] * Q_tmp_3) + rtConstP.pooled1[3 * jj + 2] *
        Q_tmp_4;
    }

    Q_tmp_2 = Q_tmp_0[kAcol + 3];
    Q_tmp_3 = Q_tmp_0[kAcol];
    Q_tmp_4 = Q_tmp_0[kAcol + 6];
    for (jj = 0; jj < 3; jj++) {
      Q_tmp_1[kAcol + 3 * jj] = (Q_tmp[3 * jj + 1] * Q_tmp_2 + Q_tmp[3 * jj] *
        Q_tmp_3) + Q_tmp[3 * jj + 2] * Q_tmp_4;
      iy = 6 * kAcol + jj;
      A[iy] = static_cast<real_T>(b_0[3 * kAcol + jj]) * 1.56779;
      A[jj + 6 * (kAcol + 3)] = 0.0;
      A[iy + 3] = 0.0;
    }
  }

  for (kAcol = 0; kAcol < 3; kAcol++) {
    jj = (kAcol + 3) * 6;
    A[jj + 3] = Q_tmp_1[3 * kAcol];
    A[jj + 4] = Q_tmp_1[3 * kAcol + 1];
    A[jj + 5] = Q_tmp_1[3 * kAcol + 2];
    tmp[kAcol] = rtU.linear_vel[kAcol];
    tmp[kAcol + 3] = rtU.eta_dot[kAcol];
  }

  for (jj = 0; jj < 6; jj++) {
    // Sum: '<S1>/Subtract' incorporates:
    //   MATLAB Function: '<S1>/MATLAB Function'

    Q_tmp_2 = 0.0;
    for (kAcol = 0; kAcol < 6; kAcol++) {
      Q_tmp_2 += A[6 * kAcol + jj] * tmp[kAcol];
    }

    // Gain: '<S1>/Gain' incorporates:
    //   DiscreteIntegrator: '<S1>/Discrete-Time Integrator'
    //   MATLAB Function: '<S1>/MATLAB Function'
    //   Sum: '<S1>/Subtract'

    rtb_Gain[jj] = (Q_tmp_2 - rtDW.DiscreteTimeIntegrator_DSTATE[jj]) * 1.0E+6;

    // Gain: '<S1>/Gain1' incorporates:
    //   DiscreteIntegrator: '<S1>/Discrete-Time Integrator2'

    rtb_Gain1[jj] = 30000.0 * rtDW.DiscreteTimeIntegrator2_DSTATE[jj];
  }

  // Outport: '<Root>/u' incorporates:
  //   UnitDelay: '<S1>/Unit Delay u0=mass*9.2'
  //   UnitDelay: '<S1>/Unit Delay2'

  rtY.u[0] = rtDW.UnitDelayu0mass92_DSTATE[0];
  rtY.u[3] = rtDW.UnitDelay2_DSTATE[0];
  rtY.u[1] = rtDW.UnitDelayu0mass92_DSTATE[1];
  rtY.u[4] = rtDW.UnitDelay2_DSTATE[1];
  rtY.u[2] = rtDW.UnitDelayu0mass92_DSTATE[2];
  rtY.u[5] = rtDW.UnitDelay2_DSTATE[2];

  // MATLAB Function: '<S1>/MATLAB Function1' incorporates:
  //   Inport: '<Root>/eta'
  //   Inport: '<Root>/eta_dot'
  //   MATLAB Function: '<S1>/Outer-loop control'

  st_idx_0 = std::cos(rtU.eta[2]);
  Q_tmp_2 = std::sin(rtU.eta[2]);
  st_idx_1 = Q_tmp_tmp_1 * st_idx_0;
  a[0] = st_idx_1;
  Q_tmp_3 = -Q_tmp_tmp_1 * Q_tmp_2;
  a[3] = Q_tmp_3;
  a[6] = Q_tmp_tmp_tmp;
  Q_tmp_4 = Q_tmp_tmp_0 * st_idx_0;
  st_idx_2 = Q_tmp_4 * Q_tmp_tmp_tmp + Q_tmp_tmp * Q_tmp_2;
  a[1] = st_idx_2;
  st_idx_0 *= Q_tmp_tmp;
  a_tmp = st_idx_0 - Q_tmp_tmp_0 * Q_tmp_tmp_tmp * Q_tmp_2;
  a[4] = a_tmp;
  a_tmp_0 = -Q_tmp_tmp_1 * Q_tmp_tmp_0;
  a[7] = a_tmp_0;
  st_idx_0 = Q_tmp_tmp_0 * Q_tmp_2 - st_idx_0 * Q_tmp_tmp_tmp;
  a[2] = st_idx_0;
  Q_tmp_4 += Q_tmp_tmp * Q_tmp_tmp_tmp * Q_tmp_2;
  a[5] = Q_tmp_4;
  a[8] = Q_tmp_tmp_2;
  Q_tmp_2 = rtU.eta_dot[1];
  smax = rtU.eta_dot[0];
  s = rtU.eta_dot[2];

  // End of Outputs for SubSystem: '<Root>/Subsystem1'
  for (jj = 0; jj <= 0; jj += 2) {
    // Outputs for Atomic SubSystem: '<Root>/Subsystem1'
    // MATLAB Function: '<S1>/MATLAB Function1'
    tmp_8 = _mm_loadu_pd(&Q_tmp[jj + 3]);
    tmp_9 = _mm_loadu_pd(&Q_tmp[jj]);
    tmp_a = _mm_loadu_pd(&Q_tmp[jj + 6]);
    _mm_storeu_pd(&ct[jj], _mm_add_pd(_mm_add_pd(_mm_mul_pd(tmp_8, _mm_set1_pd
      (Q_tmp_2)), _mm_mul_pd(tmp_9, _mm_set1_pd(smax))), _mm_mul_pd(tmp_a,
      _mm_set1_pd(s))));

    // UnitDelay: '<S1>/Unit Delay u0=mass*9.2' incorporates:
    //   MATLAB Function: '<S1>/MATLAB Function1'

    tmp_8 = _mm_loadu_pd(&rtDW.UnitDelayu0mass92_DSTATE[jj]);

    // SignalConversion generated from: '<S5>/ SFunction ' incorporates:
    //   MATLAB Function: '<S1>/MATLAB Function1'
    //   MATLAB Function: '<S1>/MATLAB Function2'

    _mm_storeu_pd(&rtb_TmpSignalConversionAtSFunct[jj], tmp_8);

    // UnitDelay: '<S1>/Unit Delay2' incorporates:
    //   MATLAB Function: '<S1>/MATLAB Function1'

    tmp_8 = _mm_loadu_pd(&rtDW.UnitDelay2_DSTATE[jj]);

    // SignalConversion generated from: '<S5>/ SFunction ' incorporates:
    //   MATLAB Function: '<S1>/MATLAB Function1'
    //   MATLAB Function: '<S1>/MATLAB Function2'

    _mm_storeu_pd(&rtb_TmpSignalConversionAtSFunct[jj + 3], tmp_8);

    // End of Outputs for SubSystem: '<Root>/Subsystem1'
  }

  // Outputs for Atomic SubSystem: '<Root>/Subsystem1'
  for (jj = 2; jj < 3; jj++) {
    // MATLAB Function: '<S1>/MATLAB Function1'
    ct[jj] = (Q_tmp[jj + 3] * Q_tmp_2 + Q_tmp[jj] * smax) + Q_tmp[jj + 6] * s;

    // SignalConversion generated from: '<S5>/ SFunction ' incorporates:
    //   MATLAB Function: '<S1>/MATLAB Function2'
    //   UnitDelay: '<S1>/Unit Delay u0=mass*9.2'
    //   UnitDelay: '<S1>/Unit Delay2'

    rtb_TmpSignalConversionAtSFunct[jj] = rtDW.UnitDelayu0mass92_DSTATE[jj];
    rtb_TmpSignalConversionAtSFunct[jj + 3] = rtDW.UnitDelay2_DSTATE[jj];
  }

  // MATLAB Function: '<S1>/MATLAB Function2'
  std::memcpy(&A[0], &rtConstP.MATLABFunction2_M_bar[0], 36U * sizeof(real_T));
  omega2[0] = -rtb_TmpSignalConversionAtSFunct[0];
  omega2[3] = rtb_TmpSignalConversionAtSFunct[3];
  omega2[1] = -rtb_TmpSignalConversionAtSFunct[1];
  omega2[4] = rtb_TmpSignalConversionAtSFunct[4];
  omega2[2] = -rtb_TmpSignalConversionAtSFunct[2];
  omega2[5] = rtb_TmpSignalConversionAtSFunct[5];
  for (kAcol = 0; kAcol < 6; kAcol++) {
    ipiv[kAcol] = static_cast<int8_T>(kAcol + 1);
  }

  for (kAcol = 0; kAcol < 5; kAcol++) {
    jj = kAcol * 7;
    iy = 6 - kAcol;
    b_ix = 0;
    smax = std::abs(A[jj]);
    for (c_k = 2; c_k <= iy; c_k++) {
      s = std::abs(A[(jj + c_k) - 1]);
      if (s > smax) {
        b_ix = c_k - 1;
        smax = s;
      }
    }

    if (A[jj + b_ix] != 0.0) {
      if (b_ix != 0) {
        iy = kAcol + b_ix;
        ipiv[kAcol] = static_cast<int8_T>(iy + 1);
        for (b_ix = 0; b_ix < 6; b_ix++) {
          c_k = b_ix * 6 + kAcol;
          smax = A[c_k];
          A[c_k] = A[iy];
          A[iy] = smax;
          iy += 6;
        }
      }

      iy = (jj - kAcol) + 6;
      c_k = (((((iy - jj) - 1) / 2) << 1) + jj) + 2;
      vectorUB = c_k - 2;
      for (b_ix = jj + 2; b_ix <= vectorUB; b_ix += 2) {
        tmp_8 = _mm_loadu_pd(&A[b_ix - 1]);
        _mm_storeu_pd(&A[b_ix - 1], _mm_div_pd(tmp_8, _mm_set1_pd(A[jj])));
      }

      for (b_ix = c_k; b_ix <= iy; b_ix++) {
        A[b_ix - 1] /= A[jj];
      }
    }

    iy = 4 - kAcol;
    b_ix = jj + 8;
    for (c_k = 0; c_k <= iy; c_k++) {
      Q_tmp_2 = A[(c_k * 6 + jj) + 6];
      if (Q_tmp_2 != 0.0) {
        vectorUB = (b_ix - kAcol) + 4;
        for (ijA = b_ix; ijA <= vectorUB; ijA++) {
          A[ijA - 1] += A[((jj + ijA) - b_ix) + 1] * -Q_tmp_2;
        }
      }

      b_ix += 6;
    }
  }

  for (kAcol = 0; kAcol < 5; kAcol++) {
    ipiv_0 = ipiv[kAcol];
    if (kAcol + 1 != ipiv_0) {
      smax = omega2[kAcol];
      omega2[kAcol] = omega2[ipiv_0 - 1];
      omega2[ipiv_0 - 1] = smax;
    }
  }

  for (jj = 0; jj < 6; jj++) {
    kAcol = 6 * jj;
    if (omega2[jj] != 0.0) {
      for (iy = jj + 2; iy < 7; iy++) {
        omega2[iy - 1] -= A[(iy + kAcol) - 1] * omega2[jj];
      }
    }
  }

  for (kAcol = 5; kAcol >= 0; kAcol--) {
    jj = 6 * kAcol;
    Q_tmp_2 = omega2[kAcol];
    if (Q_tmp_2 != 0.0) {
      omega2[kAcol] = Q_tmp_2 / A[kAcol + jj];
      for (b_ix = 0; b_ix < kAcol; b_ix++) {
        omega2[b_ix] -= A[b_ix + jj] * omega2[kAcol];
      }
    }
  }

  for (kAcol = 0; kAcol < 6; kAcol++) {
    Q_tmp_2 = omega2[kAcol] / 8.54858E-6;
    smax = std::abs(Q_tmp_2);
    if (std::isnan(Q_tmp_2)) {
      Q_tmp_2 = (rtNaN);
    } else if (Q_tmp_2 < 0.0) {
      Q_tmp_2 = -1.0;
    } else {
      Q_tmp_2 = (Q_tmp_2 > 0.0);
    }

    omega2[kAcol] = Q_tmp_2;

    // Outport: '<Root>/velocities'
    rtY.velocities[kAcol] = std::sqrt(smax) * Q_tmp_2;
  }

  // MATLAB Function: '<S1>/Outer-loop control' incorporates:
  //   Inport: '<Root>/linear_vel'
  //   Inport: '<Root>/position'
  //   Inport: '<Root>/position_des'
  //   Inport: '<Root>/vel_linear_des'

  A_0[0] = st_idx_1;
  A_0[3] = Q_tmp_3;
  A_0[6] = Q_tmp_tmp_tmp;
  A_0[1] = st_idx_2;
  A_0[4] = a_tmp;
  A_0[7] = a_tmp_0;
  A_0[2] = st_idx_0;
  A_0[5] = Q_tmp_4;
  A_0[8] = Q_tmp_tmp_2;
  Q_tmp_2 = rtU.position[0] - rtU.position_des[0];
  Q_tmp_tmp_2 = rtU.linear_vel[0] - rtU.vel_linear_des[0];
  Q_tmp_3 = rtU.position[1] - rtU.position_des[1];
  smax = rtU.linear_vel[1] - rtU.vel_linear_des[1];
  Q_tmp_4 = rtU.position[2] - rtU.position_des[2];
  s = rtU.linear_vel[2] - rtU.vel_linear_des[2];

  // End of Outputs for SubSystem: '<Root>/Subsystem1'
  for (kAcol = 0; kAcol <= 0; kAcol += 2) {
    // Outputs for Atomic SubSystem: '<Root>/Subsystem1'
    // MATLAB Function: '<S1>/Outer-loop control' incorporates:
    //   DiscreteIntegrator: '<S1>/Discrete-Time Integrator2'
    //   Inport: '<Root>/acc_linear_des'

    tmp_8 = _mm_loadu_pd(&rtDW.DiscreteTimeIntegrator2_DSTATE[kAcol]);
    _mm_storeu_pd(&ct_0[kAcol], _mm_mul_pd(_mm_sub_pd(_mm_add_pd(_mm_add_pd
      (_mm_add_pd(_mm_add_pd(_mm_mul_pd(_mm_loadu_pd
      (&rtConstP.Outerloopcontrol_Kp[kAcol + 3]), _mm_set1_pd(Q_tmp_3)),
      _mm_mul_pd(_mm_loadu_pd(&rtConstP.Outerloopcontrol_Kp[kAcol]), _mm_set1_pd
                 (Q_tmp_2))), _mm_mul_pd(_mm_loadu_pd
      (&rtConstP.Outerloopcontrol_Kp[kAcol + 6]), _mm_set1_pd(Q_tmp_4))),
       _mm_add_pd(_mm_mul_pd(_mm_set1_pd(0.63784052711141159), tmp_8),
                  _mm_loadu_pd(&b[kAcol]))), _mm_add_pd(_mm_add_pd(_mm_mul_pd
      (_mm_loadu_pd(&rtConstP.Outerloopcontrol_Kd[kAcol + 3]), _mm_set1_pd(smax)),
      _mm_mul_pd(_mm_loadu_pd(&rtConstP.Outerloopcontrol_Kd[kAcol]), _mm_set1_pd
                 (Q_tmp_tmp_2))), _mm_mul_pd(_mm_loadu_pd
      (&rtConstP.Outerloopcontrol_Kd[kAcol + 6]), _mm_set1_pd(s)))),
      _mm_loadu_pd(&rtU.acc_linear_des[kAcol])), _mm_set1_pd(1.56779)));

    // End of Outputs for SubSystem: '<Root>/Subsystem1'
  }

  // Outputs for Atomic SubSystem: '<Root>/Subsystem1'
  // MATLAB Function: '<S1>/Outer-loop control' incorporates:
  //   DiscreteIntegrator: '<S1>/Discrete-Time Integrator2'
  //   Inport: '<Root>/acc_linear_des'

  for (kAcol = 2; kAcol < 3; kAcol++) {
    ct_0[kAcol] = (((((rtConstP.Outerloopcontrol_Kp[kAcol + 3] * Q_tmp_3 +
                       rtConstP.Outerloopcontrol_Kp[kAcol] * Q_tmp_2) +
                      rtConstP.Outerloopcontrol_Kp[kAcol + 6] * Q_tmp_4) +
                     (0.63784052711141159 *
                      rtDW.DiscreteTimeIntegrator2_DSTATE[kAcol] + b_1[kAcol]))
                    + ((rtConstP.Outerloopcontrol_Kd[kAcol + 3] * smax +
                        rtConstP.Outerloopcontrol_Kd[kAcol] * Q_tmp_tmp_2) +
                       rtConstP.Outerloopcontrol_Kd[kAcol + 6] * s)) -
                   rtU.acc_linear_des[kAcol]) * 1.56779;
  }

  kAcol = 0;
  jj = 1;
  iy = 2;
  smax = std::abs(st_idx_1);
  s = std::abs(st_idx_2);
  if (s > smax) {
    smax = s;
    kAcol = 1;
    jj = 0;
  }

  if (std::abs(st_idx_0) > smax) {
    kAcol = 2;
    jj = 1;
    iy = 0;
  }

  A_0[jj] /= A_0[kAcol];
  A_0[iy] /= A_0[kAcol];
  A_0[jj + 3] -= A_0[kAcol + 3] * A_0[jj];
  A_0[iy + 3] -= A_0[kAcol + 3] * A_0[iy];
  A_0[jj + 6] -= A_0[kAcol + 6] * A_0[jj];
  A_0[iy + 6] -= A_0[kAcol + 6] * A_0[iy];
  if (std::abs(A_0[iy + 3]) > std::abs(A_0[jj + 3])) {
    b_ix = jj;
    jj = iy;
    iy = b_ix;
  }

  A_0[iy + 3] /= A_0[jj + 3];
  A_0[iy + 6] -= A_0[iy + 3] * A_0[jj + 6];
  st_idx_1 = ct_0[jj] - ct_0[kAcol] * A_0[jj];
  st_idx_2 = ((ct_0[iy] - ct_0[kAcol] * A_0[iy]) - A_0[iy + 3] * st_idx_1) /
    A_0[iy + 6];
  st_idx_1 = (st_idx_1 - A_0[jj + 6] * st_idx_2) / A_0[jj + 3];
  st_idx_0 = ((ct_0[kAcol] - A_0[kAcol + 6] * st_idx_2) - A_0[kAcol + 3] *
              st_idx_1) / A_0[kAcol];

  // SignalConversion generated from: '<S2>/Derivation' incorporates:
  //   Inport: '<Root>/phi_d'
  //   Inport: '<Root>/psi_d'
  //   Inport: '<Root>/theta_d'

  ct_0[0] = rtU.phi_d;
  ct_0[1] = rtU.theta_d;
  ct_0[2] = rtU.psi_d;

  // MATLAB Function: '<S2>/Inner-loop control' incorporates:
  //   Inport: '<Root>/eta'
  //   Inport: '<Root>/phi_d'
  //   Inport: '<Root>/psi_d'
  //   Inport: '<Root>/theta_d'

  rtb_err_eta[0] = rtU.eta[0] - rtU.phi_d;
  rtb_err_eta[1] = rtU.eta[1] - rtU.theta_d;
  rtb_err_eta[2] = rtU.eta[2] - rtU.psi_d;
  for (jj = 0; jj < 3; jj++) {
    // DiscreteTransferFcn: '<S2>/Derivation'
    Q_tmp_2 = rtDW.Derivation_states[jj];
    Q_tmp_tmp_2 = (ct_0[jj] - 0.0 * Q_tmp_2) / Ts;
    Derivation_tmp[jj] = Q_tmp_tmp_2;
    smax = Q_tmp_tmp_2 - Q_tmp_2;

    // DiscreteTransferFcn: '<S2>/Derivation'
    Derivation[jj] = smax;

    // DiscreteTransferFcn: '<S2>/Derivation1' incorporates:
    //   DiscreteTransferFcn: '<S2>/Derivation'

    Q_tmp_2 = rtDW.Derivation1_states[jj];
    Q_tmp_tmp_2 = (smax - 0.0 * Q_tmp_2) / Ts;
    Derivation1_tmp[jj] = Q_tmp_tmp_2;
    Derivation1[jj] = Q_tmp_tmp_2 - Q_tmp_2;

    // MATLAB Function: '<S2>/Inner-loop control' incorporates:
    //   DiscreteTransferFcn: '<S2>/Derivation'
    //   Inport: '<Root>/eta_dot'

    rtb_err_eta_dot[jj] = rtU.eta_dot[jj] - smax;
    Q_tmp_2 = Q_tmp[jj];
    Q_tmp_tmp_2 = Q_tmp_2 * rtU.eta_dot[0];
    A_0[3 * jj] = Q_tmp_2;
    Q_tmp_2 = Q_tmp[jj + 3];
    Q_tmp_tmp_2 += Q_tmp_2 * rtU.eta_dot[1];
    A_0[3 * jj + 1] = Q_tmp_2;
    Q_tmp_2 = Q_tmp[jj + 6];
    A_0[3 * jj + 2] = Q_tmp_2;
    rtb_tau[jj] = Q_tmp_2 * rtU.eta_dot[2] + Q_tmp_tmp_2;
  }

  // MATLAB Function: '<S2>/Inner-loop control' incorporates:
  //   Inport: '<Root>/eta_dot'
  //   MATLAB Function: '<S1>/MATLAB Function'
  //   MATLAB Function: '<S1>/MATLAB Function1'

  tmp_0[0] = 0.0;
  tmp_0[3] = -rtb_tau[2];
  tmp_0[6] = rtb_tau[1];
  tmp_0[1] = rtb_tau[2];
  tmp_0[4] = 0.0;
  tmp_0[7] = -rtb_tau[0];
  tmp_0[2] = -rtb_tau[1];
  tmp_0[5] = rtb_tau[0];
  tmp_0[8] = 0.0;
  tmp_1[0] = 0.0;
  tmp_1[3] = 0.0;
  Q_tmp_2 = -rtU.eta_dot[1] * Q_tmp_tmp_1;
  tmp_1[6] = Q_tmp_2;
  tmp_1[1] = 0.0;
  Q_tmp_tmp_2 = -rtU.eta_dot[0] * Q_tmp_tmp_0;
  tmp_1[4] = Q_tmp_tmp_2;
  Q_tmp_tmp_tmp *= -rtU.eta_dot[1];
  smax = rtU.eta_dot[0] * Q_tmp_tmp_1;
  Q_tmp_tmp_1 = Q_tmp_tmp_tmp * Q_tmp_tmp_0 + smax * Q_tmp_tmp;
  tmp_1[7] = Q_tmp_tmp_1;
  tmp_1[2] = 0.0;
  Q_tmp_3 = -rtU.eta_dot[0] * Q_tmp_tmp;
  tmp_1[5] = Q_tmp_3;
  Q_tmp_tmp_tmp = Q_tmp_tmp_tmp * Q_tmp_tmp - smax * Q_tmp_tmp_0;
  tmp_1[8] = Q_tmp_tmp_tmp;
  for (jj = 0; jj < 3; jj++) {
    Q_tmp_tmp_0 = A_0[jj + 3];
    Q_tmp_tmp = A_0[jj];
    smax = A_0[jj + 6];
    for (kAcol = 0; kAcol < 3; kAcol++) {
      Q_tmp_0[jj + 3 * kAcol] = (rtConstP.pooled1[3 * kAcol + 1] * Q_tmp_tmp_0 +
        rtConstP.pooled1[3 * kAcol] * Q_tmp_tmp) + rtConstP.pooled1[3 * kAcol +
        2] * smax;
    }

    ct_0[jj] = 10.0 * rtb_err_eta[jj];
    rtb_err_eta_dot_0[jj] = Derivation1[jj] - 10.0 * rtb_err_eta_dot[jj];
    Q_tmp_4 = Q_tmp_0[jj + 3];
    s = Q_tmp_0[jj];
    a_tmp = Q_tmp_0[jj + 6];
    for (kAcol = 0; kAcol < 3; kAcol++) {
      iy = 3 * kAcol + 1;
      b_ix = 3 * kAcol + 2;
      c_k = 3 * kAcol + jj;
      A_1[c_k] = (tmp_0[3 * kAcol] * Q_tmp_tmp + tmp_0[iy] * Q_tmp_tmp_0) +
        tmp_0[b_ix] * smax;
      Q_tmp_1[c_k] = (Q_tmp[3 * kAcol] * s + Q_tmp[iy] * Q_tmp_4) + Q_tmp[b_ix] *
        a_tmp;
    }

    Q_tmp_tmp_0 = A_1[jj + 3];
    Q_tmp_tmp = A_1[jj];
    smax = A_1[jj + 6];
    for (kAcol = 0; kAcol < 3; kAcol++) {
      A_2[jj + 3 * kAcol] = (rtConstP.pooled1[3 * kAcol + 1] * Q_tmp_tmp_0 +
        rtConstP.pooled1[3 * kAcol] * Q_tmp_tmp) + rtConstP.pooled1[3 * kAcol +
        2] * smax;
    }

    Q_tmp_tmp_0 = A_2[jj + 3];
    Q_tmp_tmp = A_2[jj];
    smax = A_2[jj + 6];
    for (kAcol = 0; kAcol < 3; kAcol++) {
      iy = 3 * kAcol + 1;
      b_ix = 3 * kAcol + 2;
      c_k = 3 * kAcol + jj;
      B_tmp[c_k] = (tmp_1[3 * kAcol] * s + tmp_1[iy] * Q_tmp_4) + tmp_1[b_ix] *
        a_tmp;
      A_3[c_k] = (Q_tmp[3 * kAcol] * Q_tmp_tmp + Q_tmp[iy] * Q_tmp_tmp_0) +
        Q_tmp[b_ix] * smax;
    }
  }

  // End of Outputs for SubSystem: '<Root>/Subsystem1'
  for (kAcol = 0; kAcol <= 6; kAcol += 2) {
    // Outputs for Atomic SubSystem: '<Root>/Subsystem1'
    // MATLAB Function: '<S2>/Inner-loop control'
    tmp_8 = _mm_loadu_pd(&A_3[kAcol]);
    tmp_9 = _mm_loadu_pd(&B_tmp[kAcol]);
    _mm_storeu_pd(&A_1[kAcol], _mm_add_pd(tmp_8, tmp_9));

    // End of Outputs for SubSystem: '<Root>/Subsystem1'
  }

  // Outputs for Atomic SubSystem: '<Root>/Subsystem1'
  // MATLAB Function: '<S2>/Inner-loop control'
  for (kAcol = 8; kAcol < 9; kAcol++) {
    A_1[kAcol] = A_3[kAcol] + B_tmp[kAcol];
  }

  smax = rtb_err_eta_dot_0[1];
  Q_tmp_tmp_0 = rtb_err_eta_dot_0[0];
  Q_tmp_tmp = rtb_err_eta_dot_0[2];

  // End of Outputs for SubSystem: '<Root>/Subsystem1'
  for (kAcol = 0; kAcol <= 0; kAcol += 2) {
    // Outputs for Atomic SubSystem: '<Root>/Subsystem1'
    // MATLAB Function: '<S2>/Inner-loop control'
    tmp_8 = _mm_loadu_pd(&Derivation[kAcol]);
    tmp_9 = _mm_loadu_pd(&ct_0[kAcol]);
    _mm_storeu_pd(&rtb_err_eta_dot_0[kAcol], _mm_sub_pd(tmp_8, tmp_9));
    tmp_8 = _mm_loadu_pd(&Q_tmp_1[kAcol + 3]);
    tmp_9 = _mm_loadu_pd(&Q_tmp_1[kAcol]);
    tmp_a = _mm_loadu_pd(&Q_tmp_1[kAcol + 6]);
    _mm_storeu_pd(&Derivation1[kAcol], _mm_add_pd(_mm_add_pd(_mm_mul_pd(tmp_8,
      _mm_set1_pd(smax)), _mm_mul_pd(tmp_9, _mm_set1_pd(Q_tmp_tmp_0))),
      _mm_mul_pd(tmp_a, _mm_set1_pd(Q_tmp_tmp))));

    // End of Outputs for SubSystem: '<Root>/Subsystem1'
  }

  // Outputs for Atomic SubSystem: '<Root>/Subsystem1'
  // MATLAB Function: '<S2>/Inner-loop control'
  for (kAcol = 2; kAcol < 3; kAcol++) {
    rtb_err_eta_dot_0[kAcol] = Derivation[kAcol] - ct_0[kAcol];
    Derivation1[kAcol] = (Q_tmp_1[kAcol + 3] * smax + Q_tmp_1[kAcol] *
                          Q_tmp_tmp_0) + Q_tmp_1[kAcol + 6] * Q_tmp_tmp;
  }

  smax = rtb_err_eta_dot_0[1];
  Q_tmp_tmp_0 = rtb_err_eta_dot_0[0];
  Q_tmp_tmp = rtb_err_eta_dot_0[2];

  // End of Outputs for SubSystem: '<Root>/Subsystem1'
  for (kAcol = 0; kAcol <= 0; kAcol += 2) {
    // Outputs for Atomic SubSystem: '<Root>/Subsystem1'
    // MATLAB Function: '<S2>/Inner-loop control'
    tmp_8 = _mm_loadu_pd(&A_1[kAcol + 3]);
    tmp_9 = _mm_loadu_pd(&A_1[kAcol]);
    tmp_a = _mm_loadu_pd(&A_1[kAcol + 6]);
    _mm_storeu_pd(&Derivation[kAcol], _mm_add_pd(_mm_add_pd(_mm_mul_pd(tmp_8,
      _mm_set1_pd(smax)), _mm_mul_pd(tmp_9, _mm_set1_pd(Q_tmp_tmp_0))),
      _mm_mul_pd(tmp_a, _mm_set1_pd(Q_tmp_tmp))));
    tmp_8 = _mm_loadu_pd(&rtb_err_eta_dot[kAcol]);
    tmp_9 = _mm_loadu_pd(&ct_0[kAcol]);
    _mm_storeu_pd(&rtb_err_eta_dot_0[kAcol], _mm_add_pd(tmp_8, tmp_9));

    // End of Outputs for SubSystem: '<Root>/Subsystem1'
  }

  // Outputs for Atomic SubSystem: '<Root>/Subsystem1'
  // MATLAB Function: '<S2>/Inner-loop control'
  for (kAcol = 2; kAcol < 3; kAcol++) {
    Derivation[kAcol] = (A_1[kAcol + 3] * smax + A_1[kAcol] * Q_tmp_tmp_0) +
      A_1[kAcol + 6] * Q_tmp_tmp;
    rtb_err_eta_dot_0[kAcol] = rtb_err_eta_dot[kAcol] + ct_0[kAcol];
  }

  Q_tmp_tmp_0 = rtb_err_eta_dot_0[1];
  Q_tmp_tmp = rtb_err_eta_dot_0[0];
  smax = rtb_err_eta_dot_0[2];
  Q_tmp_4 = rtb_err_eta[1];
  s = rtb_err_eta[0];
  a_tmp = rtb_err_eta[2];

  // End of Outputs for SubSystem: '<Root>/Subsystem1'
  for (kAcol = 0; kAcol <= 0; kAcol += 2) {
    // Outputs for Atomic SubSystem: '<Root>/Subsystem1'
    // MATLAB Function: '<S2>/Inner-loop control' incorporates:
    //   DiscreteIntegrator: '<S1>/Discrete-Time Integrator2'

    tmp_8 = _mm_loadu_pd(&Derivation1[kAcol]);
    tmp_9 = _mm_loadu_pd(&Derivation[kAcol]);
    tmp_a = _mm_loadu_pd(&rtDW.DiscreteTimeIntegrator2_DSTATE[kAcol + 3]);
    _mm_storeu_pd(&ct_0[kAcol], _mm_sub_pd(_mm_sub_pd(_mm_sub_pd(_mm_add_pd
      (tmp_8, tmp_9), tmp_a), _mm_add_pd(_mm_add_pd(_mm_mul_pd(_mm_loadu_pd
      (&rtConstP.Innerloopcontrol_D0[kAcol + 3]), _mm_set1_pd(Q_tmp_tmp_0)),
      _mm_mul_pd(_mm_loadu_pd(&rtConstP.Innerloopcontrol_D0[kAcol]), _mm_set1_pd
                 (Q_tmp_tmp))), _mm_mul_pd(_mm_loadu_pd
      (&rtConstP.Innerloopcontrol_D0[kAcol + 6]), _mm_set1_pd(smax)))),
      _mm_add_pd(_mm_add_pd(_mm_mul_pd(_mm_loadu_pd
      (&rtConstP.Innerloopcontrol_K0[kAcol + 3]), _mm_set1_pd(Q_tmp_4)),
      _mm_mul_pd(_mm_loadu_pd(&rtConstP.Innerloopcontrol_K0[kAcol]), _mm_set1_pd
                 (s))), _mm_mul_pd(_mm_loadu_pd
      (&rtConstP.Innerloopcontrol_K0[kAcol + 6]), _mm_set1_pd(a_tmp)))));

    // End of Outputs for SubSystem: '<Root>/Subsystem1'
  }

  // Outputs for Atomic SubSystem: '<Root>/Subsystem1'
  // MATLAB Function: '<S2>/Inner-loop control' incorporates:
  //   DiscreteIntegrator: '<S1>/Discrete-Time Integrator2'

  for (kAcol = 2; kAcol < 3; kAcol++) {
    ct_0[kAcol] = (((Derivation1[kAcol] + Derivation[kAcol]) -
                    rtDW.DiscreteTimeIntegrator2_DSTATE[kAcol + 3]) -
                   ((rtConstP.Innerloopcontrol_D0[kAcol + 3] * Q_tmp_tmp_0 +
                     rtConstP.Innerloopcontrol_D0[kAcol] * Q_tmp_tmp) +
                    rtConstP.Innerloopcontrol_D0[kAcol + 6] * smax)) -
      ((rtConstP.Innerloopcontrol_K0[kAcol + 3] * Q_tmp_4 +
        rtConstP.Innerloopcontrol_K0[kAcol] * s) +
       rtConstP.Innerloopcontrol_K0[kAcol + 6] * a_tmp);
  }

  kAcol = 0;
  jj = 1;
  iy = 2;
  smax = A_0[0];
  s = std::abs(A_0[1]);
  if (s > A_0[0]) {
    smax = s;
    kAcol = 1;
    jj = 0;
  }

  if (std::abs(A_0[2]) > smax) {
    kAcol = 2;
    jj = 1;
    iy = 0;
  }

  A_0[jj] /= A_0[kAcol];
  A_0[iy] /= A_0[kAcol];
  A_0[jj + 3] -= A_0[kAcol + 3] * A_0[jj];
  A_0[iy + 3] -= A_0[kAcol + 3] * A_0[iy];
  A_0[jj + 6] -= A_0[kAcol + 6] * A_0[jj];
  A_0[iy + 6] -= A_0[kAcol + 6] * A_0[iy];
  if (std::abs(A_0[iy + 3]) > std::abs(A_0[jj + 3])) {
    b_ix = jj;
    jj = iy;
    iy = b_ix;
  }

  A_0[iy + 3] /= A_0[jj + 3];
  A_0[iy + 6] -= A_0[iy + 3] * A_0[jj + 6];
  rtb_tau[1] = ct_0[jj] - ct_0[kAcol] * A_0[jj];
  rtb_tau[2] = (ct_0[iy] - ct_0[kAcol] * A_0[iy]) - A_0[iy + 3] * rtb_tau[1];
  rtb_tau[2] /= A_0[iy + 6];
  rtb_tau[0] = ct_0[kAcol] - A_0[kAcol + 6] * rtb_tau[2];
  rtb_tau[1] -= A_0[jj + 6] * rtb_tau[2];
  rtb_tau[1] /= A_0[jj + 3];
  rtb_tau[0] -= A_0[kAcol + 3] * rtb_tau[1];
  rtb_tau[0] /= A_0[kAcol];

  // UnitDelay: '<S1>/Unit Delay u0=mass*9.2' incorporates:
  //   MATLAB Function: '<S1>/MATLAB Function1'

  Q_tmp_tmp_0 = rtDW.UnitDelayu0mass92_DSTATE[1];
  Q_tmp_tmp = rtDW.UnitDelayu0mass92_DSTATE[0];
  smax = rtDW.UnitDelayu0mass92_DSTATE[2];
  for (kAcol = 0; kAcol < 3; kAcol++) {
    // MATLAB Function: '<S1>/MATLAB Function1'
    A_0[3 * kAcol] = Q_tmp[kAcol];
    A_0[3 * kAcol + 1] = Q_tmp[kAcol + 3];
    A_0[3 * kAcol + 2] = Q_tmp[kAcol + 6];

    // Sum: '<S1>/Sum' incorporates:
    //   DiscreteIntegrator: '<S1>/Discrete-Time Integrator2'
    //   MATLAB Function: '<S1>/MATLAB Function1'
    //   UnitDelay: '<S1>/Unit Delay u0=mass*9.2'

    rtb_err_eta_dot_0[kAcol] = (1.56779 * b_1[kAcol] - ((a[kAcol + 3] *
      Q_tmp_tmp_0 + a[kAcol] * Q_tmp_tmp) + a[kAcol + 6] * smax)) +
      rtDW.DiscreteTimeIntegrator2_DSTATE[kAcol];
  }

  // MATLAB Function: '<S1>/MATLAB Function1'
  tmp_0[0] = 0.0;
  tmp_0[3] = -ct[2];
  tmp_0[6] = ct[1];
  tmp_0[1] = ct[2];
  tmp_0[4] = 0.0;
  tmp_0[7] = -ct[0];
  tmp_0[2] = -ct[1];
  tmp_0[5] = ct[0];
  tmp_0[8] = 0.0;
  for (kAcol = 0; kAcol < 3; kAcol++) {
    Q_tmp_tmp_0 = A_0[kAcol + 3];
    Q_tmp_tmp = A_0[kAcol];
    smax = A_0[kAcol + 6];
    for (jj = 0; jj < 3; jj++) {
      A_1[kAcol + 3 * jj] = (tmp_0[3 * jj + 1] * Q_tmp_tmp_0 + tmp_0[3 * jj] *
        Q_tmp_tmp) + tmp_0[3 * jj + 2] * smax;
    }

    Q_tmp_tmp_0 = A_1[kAcol + 3];
    Q_tmp_tmp = A_1[kAcol];
    smax = A_1[kAcol + 6];
    for (jj = 0; jj < 3; jj++) {
      A_2[kAcol + 3 * jj] = (rtConstP.pooled1[3 * jj + 1] * Q_tmp_tmp_0 +
        rtConstP.pooled1[3 * jj] * Q_tmp_tmp) + rtConstP.pooled1[3 * jj + 2] *
        smax;
    }
  }

  tmp_0[0] = 0.0;
  tmp_0[3] = 0.0;
  tmp_0[6] = Q_tmp_2;
  tmp_0[1] = 0.0;
  tmp_0[4] = Q_tmp_tmp_2;
  tmp_0[7] = Q_tmp_tmp_1;
  tmp_0[2] = 0.0;
  tmp_0[5] = Q_tmp_3;
  tmp_0[8] = Q_tmp_tmp_tmp;
  for (kAcol = 0; kAcol < 3; kAcol++) {
    Q_tmp_2 = Q_tmp[3 * kAcol + 1];
    Q_tmp_3 = Q_tmp[3 * kAcol];
    Q_tmp_4 = Q_tmp[3 * kAcol + 2];
    Q_tmp_tmp_0 = A_0[kAcol + 3];
    Q_tmp_tmp = A_0[kAcol];
    smax = A_0[kAcol + 6];
    for (jj = 0; jj < 3; jj++) {
      iy = 3 * jj + kAcol;
      A_3[iy] = (A_2[jj + 3] * Q_tmp_2 + Q_tmp_3 * A_2[jj]) + A_2[jj + 6] *
        Q_tmp_4;
      A_1[iy] = (rtConstP.pooled1[3 * jj + 1] * Q_tmp_tmp_0 + rtConstP.pooled1[3
                 * jj] * Q_tmp_tmp) + rtConstP.pooled1[3 * jj + 2] * smax;
    }
  }

  for (kAcol = 0; kAcol < 3; kAcol++) {
    Q_tmp_2 = tmp_0[3 * kAcol + 1];
    Q_tmp_tmp_2 = tmp_0[3 * kAcol];
    Q_tmp_tmp_tmp = tmp_0[3 * kAcol + 2];
    for (jj = 0; jj < 3; jj++) {
      A_2[kAcol + 3 * jj] = (A_1[jj + 3] * Q_tmp_2 + Q_tmp_tmp_2 * A_1[jj]) +
        A_1[jj + 6] * Q_tmp_tmp_tmp;
    }
  }

  // End of Outputs for SubSystem: '<Root>/Subsystem1'
  for (kAcol = 0; kAcol <= 6; kAcol += 2) {
    // Outputs for Atomic SubSystem: '<Root>/Subsystem1'
    // MATLAB Function: '<S1>/MATLAB Function1'
    tmp_8 = _mm_loadu_pd(&A_3[kAcol]);
    tmp_9 = _mm_loadu_pd(&A_2[kAcol]);
    _mm_storeu_pd(&A_1[kAcol], _mm_add_pd(tmp_8, tmp_9));

    // End of Outputs for SubSystem: '<Root>/Subsystem1'
  }

  // Outputs for Atomic SubSystem: '<Root>/Subsystem1'
  // MATLAB Function: '<S1>/MATLAB Function1' incorporates:
  //   Inport: '<Root>/eta_dot'

  for (kAcol = 8; kAcol < 9; kAcol++) {
    A_1[kAcol] = A_3[kAcol] + A_2[kAcol];
  }

  Q_tmp_2 = rtU.eta_dot[1];
  smax = rtU.eta_dot[0];
  s = rtU.eta_dot[2];

  // UnitDelay: '<S1>/Unit Delay2' incorporates:
  //   MATLAB Function: '<S1>/MATLAB Function1'

  Q_tmp_tmp_0 = rtDW.UnitDelay2_DSTATE[1];
  Q_tmp_tmp = rtDW.UnitDelay2_DSTATE[0];
  Q_tmp_tmp_1 = rtDW.UnitDelay2_DSTATE[2];

  // End of Outputs for SubSystem: '<Root>/Subsystem1'
  for (kAcol = 0; kAcol <= 0; kAcol += 2) {
    // Outputs for Atomic SubSystem: '<Root>/Subsystem1'
    // Update for DiscreteIntegrator: '<S1>/Discrete-Time Integrator' incorporates:
    //   MATLAB Function: '<S1>/MATLAB Function1'

    tmp_8 = _mm_loadu_pd(&rtb_err_eta_dot_0[kAcol]);
    tmp_9 = _mm_set1_pd(Ts);
    tmp_a = _mm_loadu_pd(&rtDW.DiscreteTimeIntegrator_DSTATE[kAcol]);

    // MATLAB Function: '<S1>/MATLAB Function1' incorporates:
    //   DiscreteIntegrator: '<S1>/Discrete-Time Integrator'

    _mm_storeu_pd(&tmp[kAcol], _mm_add_pd(_mm_mul_pd(tmp_9, tmp_8), tmp_a));
    tmp_8 = _mm_loadu_pd(&A_1[kAcol + 3]);
    tmp_a = _mm_loadu_pd(&A_1[kAcol]);
    tmp_2 = _mm_loadu_pd(&A_1[kAcol + 6]);
    tmp_3 = _mm_loadu_pd(&A_0[kAcol + 3]);
    tmp_4 = _mm_loadu_pd(&A_0[kAcol]);
    tmp_5 = _mm_loadu_pd(&A_0[kAcol + 6]);

    // Update for DiscreteIntegrator: '<S1>/Discrete-Time Integrator' incorporates:
    //   DiscreteIntegrator: '<S1>/Discrete-Time Integrator2'
    //   MATLAB Function: '<S1>/MATLAB Function1'
    //   Sum: '<S1>/Sum'

    tmp_6 = _mm_loadu_pd(&rtDW.DiscreteTimeIntegrator2_DSTATE[kAcol + 3]);
    tmp_7 = _mm_loadu_pd(&rtDW.DiscreteTimeIntegrator_DSTATE[kAcol + 3]);

    // MATLAB Function: '<S1>/MATLAB Function1' incorporates:
    //   DiscreteIntegrator: '<S1>/Discrete-Time Integrator'
    //   UnitDelay: '<S1>/Unit Delay2'

    _mm_storeu_pd(&tmp[kAcol + 3], _mm_add_pd(_mm_mul_pd(_mm_add_pd(_mm_add_pd
      (_mm_add_pd(_mm_add_pd(_mm_mul_pd(tmp_8, _mm_set1_pd(Q_tmp_2)), _mm_mul_pd
      (tmp_a, _mm_set1_pd(smax))), _mm_mul_pd(tmp_2, _mm_set1_pd(s))),
       _mm_add_pd(_mm_add_pd(_mm_mul_pd(tmp_3, _mm_set1_pd(Q_tmp_tmp_0)),
      _mm_mul_pd(tmp_4, _mm_set1_pd(Q_tmp_tmp))), _mm_mul_pd(tmp_5, _mm_set1_pd
      (Q_tmp_tmp_1)))), tmp_6), tmp_9), tmp_7));

    // End of Outputs for SubSystem: '<Root>/Subsystem1'
  }

  // Outputs for Atomic SubSystem: '<Root>/Subsystem1'
  // MATLAB Function: '<S1>/MATLAB Function1' incorporates:
  //   DiscreteIntegrator: '<S1>/Discrete-Time Integrator'
  //   DiscreteIntegrator: '<S1>/Discrete-Time Integrator2'
  //   Sum: '<S1>/Sum'
  //   UnitDelay: '<S1>/Unit Delay2'

  for (kAcol = 2; kAcol < 3; kAcol++) {
    tmp[kAcol] = Ts * rtb_err_eta_dot_0[kAcol] +
      rtDW.DiscreteTimeIntegrator_DSTATE[kAcol];
    tmp[kAcol + 3] = ((((A_1[kAcol + 3] * Q_tmp_2 + A_1[kAcol] * smax) +
                        A_1[kAcol + 6] * s) + ((A_0[kAcol + 3] * Q_tmp_tmp_0 +
      A_0[kAcol] * Q_tmp_tmp) + A_0[kAcol + 6] * Q_tmp_tmp_1)) +
                      rtDW.DiscreteTimeIntegrator2_DSTATE[kAcol + 3]) * Ts +
      rtDW.DiscreteTimeIntegrator_DSTATE[kAcol + 3];
  }

  // End of Outputs for SubSystem: '<Root>/Subsystem1'
  for (kAcol = 0; kAcol <= 4; kAcol += 2) {
    // Outputs for Atomic SubSystem: '<Root>/Subsystem1'
    // Update for DiscreteIntegrator: '<S1>/Discrete-Time Integrator'
    tmp_8 = _mm_loadu_pd(&tmp[kAcol]);
    _mm_storeu_pd(&rtDW.DiscreteTimeIntegrator_DSTATE[kAcol], tmp_8);

    // Update for DiscreteIntegrator: '<S1>/Discrete-Time Integrator2' incorporates:
    //   DiscreteIntegrator: '<S1>/Discrete-Time Integrator'

    tmp_8 = _mm_loadu_pd(&rtDW.DiscreteTimeIntegrator2_DSTATE[kAcol]);

    // DiscreteIntegrator: '<S1>/Discrete-Time Integrator1' incorporates:
    //   DiscreteIntegrator: '<S1>/Discrete-Time Integrator'

    tmp_9 = _mm_loadu_pd(&rtDW.DiscreteTimeIntegrator1_DSTATE[kAcol]);

    // Update for DiscreteIntegrator: '<S1>/Discrete-Time Integrator2' incorporates:
    //   DiscreteIntegrator: '<S1>/Discrete-Time Integrator'
    //   Gain: '<S1>/Gain2'

    tmp_a = _mm_set1_pd(Ts);
    _mm_storeu_pd(&rtDW.DiscreteTimeIntegrator2_DSTATE[kAcol], _mm_add_pd
                  (_mm_mul_pd(_mm_sub_pd(tmp_9, _mm_mul_pd(_mm_set1_pd(300.0),
      tmp_8)), tmp_a), tmp_8));

    // Sum: '<S1>/Subtract1' incorporates:
    //   DiscreteIntegrator: '<S1>/Discrete-Time Integrator'

    tmp_8 = _mm_loadu_pd(&rtb_Gain[kAcol]);
    tmp_2 = _mm_loadu_pd(&rtb_Gain1[kAcol]);

    // Update for DiscreteIntegrator: '<S1>/Discrete-Time Integrator1' incorporates:
    //   DiscreteIntegrator: '<S1>/Discrete-Time Integrator'

    _mm_storeu_pd(&rtDW.DiscreteTimeIntegrator1_DSTATE[kAcol], _mm_add_pd
                  (_mm_mul_pd(_mm_sub_pd(tmp_8, tmp_2), tmp_a), tmp_9));

    // End of Outputs for SubSystem: '<Root>/Subsystem1'
  }

  // Outputs for Atomic SubSystem: '<Root>/Subsystem1'
  // Update for UnitDelay: '<S1>/Unit Delay u0=mass*9.2'
  rtDW.UnitDelayu0mass92_DSTATE[0] = st_idx_0;

  // Update for UnitDelay: '<S1>/Unit Delay2'
  rtDW.UnitDelay2_DSTATE[0] = rtb_tau[0];

  // Update for DiscreteTransferFcn: '<S2>/Derivation'
  rtDW.Derivation_states[0] = Derivation_tmp[0];

  // Update for DiscreteTransferFcn: '<S2>/Derivation1'
  rtDW.Derivation1_states[0] = Derivation1_tmp[0];

  // Update for UnitDelay: '<S1>/Unit Delay u0=mass*9.2'
  rtDW.UnitDelayu0mass92_DSTATE[1] = st_idx_1;

  // Update for UnitDelay: '<S1>/Unit Delay2'
  rtDW.UnitDelay2_DSTATE[1] = rtb_tau[1];

  // Update for DiscreteTransferFcn: '<S2>/Derivation'
  rtDW.Derivation_states[1] = Derivation_tmp[1];

  // Update for DiscreteTransferFcn: '<S2>/Derivation1'
  rtDW.Derivation1_states[1] = Derivation1_tmp[1];

  // Update for UnitDelay: '<S1>/Unit Delay u0=mass*9.2'
  rtDW.UnitDelayu0mass92_DSTATE[2] = st_idx_2;

  // Update for UnitDelay: '<S1>/Unit Delay2'
  rtDW.UnitDelay2_DSTATE[2] = rtb_tau[2];

  // Update for DiscreteTransferFcn: '<S2>/Derivation'
  rtDW.Derivation_states[2] = Derivation_tmp[2];

  // Update for DiscreteTransferFcn: '<S2>/Derivation1'
  rtDW.Derivation1_states[2] = Derivation1_tmp[2];

  // End of Outputs for SubSystem: '<Root>/Subsystem1'
}

// Model initialize function
void Subsystem1::initialize()
{
  // Registration code

  // initialize non-finites
  rt_InitInfAndNaN(sizeof(real_T));

  // SystemInitialize for Atomic SubSystem: '<Root>/Subsystem1'
  // InitializeConditions for UnitDelay: '<S1>/Unit Delay u0=mass*9.2'
  rtDW.UnitDelayu0mass92_DSTATE[0] = 0.0;
  rtDW.UnitDelayu0mass92_DSTATE[1] = 0.0;
  rtDW.UnitDelayu0mass92_DSTATE[2] = 15.3800199;

  // End of SystemInitialize for SubSystem: '<Root>/Subsystem1'
}

// Constructor
Subsystem1::Subsystem1() :
  rtU(),
  rtY(),
  rtDW(),
  rtM()
{
  // Currently there is no constructor body generated.
}

// Destructor
// Currently there is no destructor body generated.
Subsystem1::~Subsystem1() = default;

// Real-Time Model get method
Subsystem1::RT_MODEL * Subsystem1::getRTM()
{
  return (&rtM);
}

//
// File trailer for generated code.
//
// [EOF]
//
