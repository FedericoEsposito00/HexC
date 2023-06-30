//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: Subsystem.cpp
//
// Code generated for Simulink model 'Subsystem'.
//
// Model version                  : 3.8
// Simulink Coder version         : 9.8 (R2022b) 13-May-2022
// C/C++ source code generated on : Thu Jun 29 20:18:34 2023
//
// Target selection: ert.tlc
// Embedded hardware selection: Intel->x86-64 (Linux 64)
// Code generation objectives:
//    1. Execution efficiency
//    2. RAM efficiency
// Validation result: Not run
//
#include "Subsystem.h"
#include <cmath>
#include <emmintrin.h>
#include "rtwtypes.h"

// Model step function
void Subsystem::step()
{
  static const real_T c[3]{ 0.0, 0.0, 9.81 };

  static const real_T c_0[3]{ 0.0, 0.0, 9.81 };

  __m128d tmp_2;
  __m128d tmp_3;
  __m128d tmp_4;
  __m128d tmp_5;
  real_T A[9];
  real_T A_tmp[9];
  real_T A_tmp_0[9];
  real_T A_tmp_1[9];
  real_T A_tmp_2[9];
  real_T A_tmp_3[9];
  real_T A_tmp_4[9];
  real_T Q[9];
  real_T b[9];
  real_T tmp[9];
  real_T tmp_0[9];
  real_T B_0[3];
  real_T ct[3];
  real_T rtb_DiscreteTimeIntegrator[3];
  real_T rtb_DiscreteTimeIntegrator1[3];
  real_T st[3];
  real_T a21;
  real_T b_tmp;
  real_T ct_tmp;
  real_T maxval;
  real_T s;
  real_T st_0;
  real_T st_tmp;
  int32_T A_tmp_tmp;
  int32_T aoffset;
  int32_T r1;
  int32_T rtemp;

  // Outputs for Atomic SubSystem: '<Root>/Subsystem'
  // DiscreteIntegrator: '<S1>/Discrete-Time Integrator'
  rtb_DiscreteTimeIntegrator[0] = rtDW.DiscreteTimeIntegrator_DSTATE[0];

  // DiscreteIntegrator: '<S1>/Discrete-Time Integrator1'
  rtb_DiscreteTimeIntegrator1[0] = rtDW.DiscreteTimeIntegrator1_DSTATE[0];

  // Outport: '<Root>/eta' incorporates:
  //   DiscreteIntegrator: '<S1>/Discrete-Time Integrator2'

  rtY.eta[0] = rtDW.DiscreteTimeIntegrator2_DSTATE[0];

  // MATLAB Function: '<S1>/MATLAB Function' incorporates:
  //   DiscreteIntegrator: '<S1>/Discrete-Time Integrator2'

  maxval = std::cos(rtDW.DiscreteTimeIntegrator2_DSTATE[0]);
  a21 = std::sin(rtDW.DiscreteTimeIntegrator2_DSTATE[0]);

  // DiscreteIntegrator: '<S1>/Discrete-Time Integrator'
  rtb_DiscreteTimeIntegrator[1] = rtDW.DiscreteTimeIntegrator_DSTATE[1];

  // DiscreteIntegrator: '<S1>/Discrete-Time Integrator1'
  rtb_DiscreteTimeIntegrator1[1] = rtDW.DiscreteTimeIntegrator1_DSTATE[1];

  // Outport: '<Root>/eta' incorporates:
  //   DiscreteIntegrator: '<S1>/Discrete-Time Integrator2'

  rtY.eta[1] = rtDW.DiscreteTimeIntegrator2_DSTATE[1];

  // MATLAB Function: '<S1>/MATLAB Function' incorporates:
  //   DiscreteIntegrator: '<S1>/Discrete-Time Integrator2'

  ct_tmp = std::cos(rtDW.DiscreteTimeIntegrator2_DSTATE[1]);
  st_tmp = std::sin(rtDW.DiscreteTimeIntegrator2_DSTATE[1]);

  // DiscreteIntegrator: '<S1>/Discrete-Time Integrator'
  rtb_DiscreteTimeIntegrator[2] = rtDW.DiscreteTimeIntegrator_DSTATE[2];

  // DiscreteIntegrator: '<S1>/Discrete-Time Integrator1'
  rtb_DiscreteTimeIntegrator1[2] = rtDW.DiscreteTimeIntegrator1_DSTATE[2];

  // Outport: '<Root>/eta' incorporates:
  //   DiscreteIntegrator: '<S1>/Discrete-Time Integrator2'

  rtY.eta[2] = rtDW.DiscreteTimeIntegrator2_DSTATE[2];

  // MATLAB Function: '<S1>/MATLAB Function' incorporates:
  //   DiscreteIntegrator: '<S1>/Discrete-Time Integrator1'
  //   DiscreteIntegrator: '<S1>/Discrete-Time Integrator2'
  //   Inport: '<Root>/u'

  s = std::cos(rtDW.DiscreteTimeIntegrator2_DSTATE[2]);
  st_0 = std::sin(rtDW.DiscreteTimeIntegrator2_DSTATE[2]);
  b[0] = ct_tmp * s;
  b[3] = -ct_tmp * st_0;
  b[6] = st_tmp;
  b_tmp = a21 * s;
  b[1] = b_tmp * st_tmp + maxval * st_0;
  s *= maxval;
  b[4] = s - a21 * st_tmp * st_0;
  b[7] = -ct_tmp * a21;
  b[2] = a21 * st_0 - s * st_tmp;
  b[5] = maxval * st_tmp * st_0 + b_tmp;
  b_tmp = maxval * ct_tmp;
  b[8] = b_tmp;
  Q[0] = 1.0;
  Q[3] = 0.0;
  Q[6] = -st_tmp;
  Q[1] = 0.0;
  Q[4] = maxval;
  Q[7] = ct_tmp * a21;
  Q[2] = 0.0;
  Q[5] = -a21;
  Q[8] = b_tmp;
  for (aoffset = 0; aoffset < 3; aoffset++) {
    A_tmp[3 * aoffset] = Q[aoffset];
    A_tmp[3 * aoffset + 1] = Q[aoffset + 3];
    A_tmp[3 * aoffset + 2] = Q[aoffset + 6];
  }

  for (r1 = 0; r1 < 3; r1++) {
    for (aoffset = 0; aoffset < 3; aoffset++) {
      A_tmp_tmp = 3 * aoffset + r1;
      A_tmp_0[A_tmp_tmp] = 0.0;
      A_tmp_0[A_tmp_tmp] += rtConstP.MATLABFunction_Ib[3 * aoffset] * A_tmp[r1];
      A_tmp_0[A_tmp_tmp] += rtConstP.MATLABFunction_Ib[3 * aoffset + 1] *
        A_tmp[r1 + 3];
      A_tmp_0[A_tmp_tmp] += rtConstP.MATLABFunction_Ib[3 * aoffset + 2] *
        A_tmp[r1 + 6];
    }

    ct[r1] = 0.0;
    aoffset = r1 * 3;
    s = 0.0;
    for (A_tmp_tmp = 0; A_tmp_tmp < 3; A_tmp_tmp++) {
      rtemp = 3 * A_tmp_tmp + r1;
      A[rtemp] = 0.0;
      A[rtemp] += Q[3 * A_tmp_tmp] * A_tmp_0[r1];
      A[rtemp] += Q[3 * A_tmp_tmp + 1] * A_tmp_0[r1 + 3];
      A[rtemp] += Q[3 * A_tmp_tmp + 2] * A_tmp_0[r1 + 6];
      s += Q[aoffset + A_tmp_tmp] * rtU.u[A_tmp_tmp + 3];
      ct[r1] += Q[rtemp] * rtDW.DiscreteTimeIntegrator1_DSTATE[A_tmp_tmp];
    }

    st[r1] = s;
  }

  tmp[0] = 0.0;
  tmp[3] = -ct[2];
  tmp[6] = ct[1];
  tmp[1] = ct[2];
  tmp[4] = 0.0;
  tmp[7] = -ct[0];
  tmp[2] = -ct[1];
  tmp[5] = ct[0];
  tmp[8] = 0.0;
  tmp_0[0] = 0.0;
  tmp_0[3] = 0.0;
  tmp_0[6] = -rtDW.DiscreteTimeIntegrator1_DSTATE[1] * ct_tmp;
  tmp_0[1] = 0.0;
  tmp_0[4] = -rtDW.DiscreteTimeIntegrator1_DSTATE[0] * a21;
  st_tmp *= -rtDW.DiscreteTimeIntegrator1_DSTATE[1];
  ct_tmp *= rtDW.DiscreteTimeIntegrator1_DSTATE[0];
  tmp_0[7] = st_tmp * a21 + ct_tmp * maxval;
  tmp_0[2] = 0.0;
  tmp_0[5] = -rtDW.DiscreteTimeIntegrator1_DSTATE[0] * maxval;
  tmp_0[8] = st_tmp * maxval - ct_tmp * a21;
  for (aoffset = 0; aoffset < 3; aoffset++) {
    for (r1 = 0; r1 < 3; r1++) {
      A_tmp_tmp = 3 * r1 + aoffset;
      A_tmp_1[A_tmp_tmp] = 0.0;
      A_tmp_1[A_tmp_tmp] += tmp[3 * r1] * A_tmp[aoffset];
      A_tmp_1[A_tmp_tmp] += tmp[3 * r1 + 1] * A_tmp[aoffset + 3];
      A_tmp_1[A_tmp_tmp] += tmp[3 * r1 + 2] * A_tmp[aoffset + 6];
    }

    for (r1 = 0; r1 < 3; r1++) {
      A_tmp_tmp = 3 * r1 + aoffset;
      A_tmp_2[A_tmp_tmp] = 0.0;
      A_tmp_2[A_tmp_tmp] += rtConstP.MATLABFunction_Ib[3 * r1] * A_tmp_1[aoffset];
      A_tmp_2[A_tmp_tmp] += rtConstP.MATLABFunction_Ib[3 * r1 + 1] *
        A_tmp_1[aoffset + 3];
      A_tmp_2[A_tmp_tmp] += rtConstP.MATLABFunction_Ib[3 * r1 + 2] *
        A_tmp_1[aoffset + 6];
    }

    for (r1 = 0; r1 < 3; r1++) {
      A_tmp_tmp = 3 * r1 + aoffset;
      A_tmp_3[A_tmp_tmp] = 0.0;
      A_tmp_3[A_tmp_tmp] += Q[3 * r1] * A_tmp_2[aoffset];
      A_tmp_3[A_tmp_tmp] += Q[3 * r1 + 1] * A_tmp_2[aoffset + 3];
      A_tmp_3[A_tmp_tmp] += Q[3 * r1 + 2] * A_tmp_2[aoffset + 6];
    }

    for (r1 = 0; r1 <= 0; r1 += 2) {
      A_tmp_tmp = 3 * aoffset + r1;
      _mm_storeu_pd(&A_tmp_4[A_tmp_tmp], _mm_set1_pd(0.0));
      tmp_4 = _mm_loadu_pd(&A_tmp_0[r1]);
      tmp_5 = _mm_loadu_pd(&A_tmp_4[A_tmp_tmp]);
      _mm_storeu_pd(&A_tmp_4[A_tmp_tmp], _mm_add_pd(tmp_5, _mm_mul_pd
        (_mm_set1_pd(tmp_0[3 * aoffset]), tmp_4)));
      tmp_4 = _mm_loadu_pd(&A_tmp_0[r1 + 3]);
      tmp_5 = _mm_loadu_pd(&A_tmp_4[A_tmp_tmp]);
      _mm_storeu_pd(&A_tmp_4[A_tmp_tmp], _mm_add_pd(_mm_mul_pd(_mm_set1_pd
        (tmp_0[3 * aoffset + 1]), tmp_4), tmp_5));
      tmp_4 = _mm_loadu_pd(&A_tmp_0[r1 + 6]);
      tmp_5 = _mm_loadu_pd(&A_tmp_4[A_tmp_tmp]);
      _mm_storeu_pd(&A_tmp_4[A_tmp_tmp], _mm_add_pd(_mm_mul_pd(_mm_set1_pd
        (tmp_0[3 * aoffset + 2]), tmp_4), tmp_5));
    }

    for (r1 = 2; r1 < 3; r1++) {
      A_tmp_tmp = 3 * aoffset + r1;
      A_tmp_4[A_tmp_tmp] = 0.0;
      A_tmp_4[A_tmp_tmp] += tmp_0[3 * aoffset] * A_tmp_0[r1];
      A_tmp_4[A_tmp_tmp] += tmp_0[3 * aoffset + 1] * A_tmp_0[r1 + 3];
      A_tmp_4[A_tmp_tmp] += tmp_0[3 * aoffset + 2] * A_tmp_0[r1 + 6];
    }
  }

  // End of Outputs for SubSystem: '<Root>/Subsystem'
  for (aoffset = 0; aoffset <= 6; aoffset += 2) {
    // Outputs for Atomic SubSystem: '<Root>/Subsystem'
    // MATLAB Function: '<S1>/MATLAB Function'
    tmp_4 = _mm_loadu_pd(&A_tmp_3[aoffset]);
    tmp_5 = _mm_loadu_pd(&A_tmp_4[aoffset]);
    _mm_storeu_pd(&A_tmp[aoffset], _mm_mul_pd(_mm_add_pd(tmp_4, tmp_5),
      _mm_set1_pd(-1.0)));

    // End of Outputs for SubSystem: '<Root>/Subsystem'
  }

  // Outputs for Atomic SubSystem: '<Root>/Subsystem'
  // MATLAB Function: '<S1>/MATLAB Function'
  for (aoffset = 8; aoffset < 9; aoffset++) {
    A_tmp[aoffset] = -(A_tmp_3[aoffset] + A_tmp_4[aoffset]);
  }

  // End of Outputs for SubSystem: '<Root>/Subsystem'
  for (aoffset = 0; aoffset <= 0; aoffset += 2) {
    // Outputs for Atomic SubSystem: '<Root>/Subsystem'
    // MATLAB Function: '<S1>/MATLAB Function' incorporates:
    //   DiscreteIntegrator: '<S1>/Discrete-Time Integrator1'
    //   Inport: '<Root>/tau_ext'

    tmp_4 = _mm_loadu_pd(&A_tmp[aoffset + 3]);
    tmp_5 = _mm_loadu_pd(&A_tmp[aoffset]);
    tmp_2 = _mm_loadu_pd(&A_tmp[aoffset + 6]);
    tmp_3 = _mm_loadu_pd(&st[aoffset]);
    _mm_storeu_pd(&B_0[aoffset], _mm_add_pd(_mm_add_pd(_mm_add_pd(_mm_add_pd
      (_mm_mul_pd(tmp_4, _mm_set1_pd(rtDW.DiscreteTimeIntegrator1_DSTATE[1])),
       _mm_mul_pd(tmp_5, _mm_set1_pd(rtDW.DiscreteTimeIntegrator1_DSTATE[0]))),
      _mm_mul_pd(tmp_2, _mm_set1_pd(rtDW.DiscreteTimeIntegrator1_DSTATE[2]))),
      tmp_3), _mm_loadu_pd(&rtU.tau_ext[aoffset])));

    // End of Outputs for SubSystem: '<Root>/Subsystem'
  }

  // Outputs for Atomic SubSystem: '<Root>/Subsystem'
  // MATLAB Function: '<S1>/MATLAB Function' incorporates:
  //   DiscreteIntegrator: '<S1>/Discrete-Time Integrator1'
  //   Inport: '<Root>/tau_ext'

  for (aoffset = 2; aoffset < 3; aoffset++) {
    B_0[aoffset] = (((A_tmp[aoffset + 3] * rtDW.DiscreteTimeIntegrator1_DSTATE[1]
                      + A_tmp[aoffset] * rtDW.DiscreteTimeIntegrator1_DSTATE[0])
                     + A_tmp[aoffset + 6] * rtDW.DiscreteTimeIntegrator1_DSTATE
                     [2]) + st[aoffset]) + rtU.tau_ext[aoffset];
  }

  r1 = 0;
  aoffset = 1;
  A_tmp_tmp = 2;
  maxval = std::abs(A[0]);
  a21 = std::abs(A[1]);
  if (a21 > maxval) {
    maxval = a21;
    r1 = 1;
    aoffset = 0;
  }

  if (std::abs(A[2]) > maxval) {
    r1 = 2;
    aoffset = 1;
    A_tmp_tmp = 0;
  }

  A[aoffset] /= A[r1];
  A[A_tmp_tmp] /= A[r1];
  A[aoffset + 3] -= A[r1 + 3] * A[aoffset];
  A[A_tmp_tmp + 3] -= A[r1 + 3] * A[A_tmp_tmp];
  A[aoffset + 6] -= A[r1 + 6] * A[aoffset];
  A[A_tmp_tmp + 6] -= A[r1 + 6] * A[A_tmp_tmp];
  if (std::abs(A[A_tmp_tmp + 3]) > std::abs(A[aoffset + 3])) {
    rtemp = aoffset;
    aoffset = A_tmp_tmp;
    A_tmp_tmp = rtemp;
  }

  A[A_tmp_tmp + 3] /= A[aoffset + 3];
  A[A_tmp_tmp + 6] -= A[A_tmp_tmp + 3] * A[aoffset + 6];
  st[1] = B_0[aoffset] - B_0[r1] * A[aoffset];
  st[2] = (B_0[A_tmp_tmp] - B_0[r1] * A[A_tmp_tmp]) - A[A_tmp_tmp + 3] * st[1];
  st[2] /= A[A_tmp_tmp + 6];
  st[0] = B_0[r1] - A[r1 + 6] * st[2];
  st[1] -= A[aoffset + 6] * st[2];
  st[1] /= A[aoffset + 3];
  st[0] -= A[r1 + 3] * st[1];
  st[0] /= A[r1];

  // End of Outputs for SubSystem: '<Root>/Subsystem'
  for (r1 = 0; r1 <= 0; r1 += 2) {
    __m128d tmp_1;

    // Outputs for Atomic SubSystem: '<Root>/Subsystem'
    // MATLAB Function: '<S1>/MATLAB Function'
    tmp_4 = _mm_loadu_pd(&ct[r1]);

    // Outport: '<Root>/omega' incorporates:
    //   MATLAB Function: '<S1>/MATLAB Function'

    _mm_storeu_pd(&rtY.omega[r1], tmp_4);

    // MATLAB Function: '<S1>/MATLAB Function' incorporates:
    //   Inport: '<Root>/f_ext'
    //   Inport: '<Root>/u'

    tmp_4 = _mm_loadu_pd(&b[r1 + 3]);
    tmp_5 = _mm_set1_pd(0.63784052711141159);
    tmp_2 = _mm_loadu_pd(&b[r1]);
    tmp_3 = _mm_loadu_pd(&b[r1 + 6]);
    tmp_4 = _mm_add_pd(_mm_sub_pd(_mm_loadu_pd(&c[r1]), _mm_add_pd(_mm_add_pd
      (_mm_mul_pd(_mm_mul_pd(tmp_4, tmp_5), _mm_set1_pd(rtU.u[1])), _mm_mul_pd
       (_mm_mul_pd(tmp_5, tmp_2), _mm_set1_pd(rtU.u[0]))), _mm_mul_pd(_mm_mul_pd
      (tmp_3, tmp_5), _mm_set1_pd(rtU.u[2])))), _mm_div_pd(_mm_loadu_pd
      (&rtU.f_ext[r1]), _mm_set1_pd(1.56779)));

    // DiscreteIntegrator: '<S1>/Discrete-Time QUELLO IMPORTANTE' incorporates:
    //   MATLAB Function: '<S1>/MATLAB Function'

    tmp_5 = _mm_loadu_pd(&rtDW.DiscreteTimeQUELLOIMPORTANTE_DS[r1]);

    // Outport: '<Root>/p' incorporates:
    //   MATLAB Function: '<S1>/MATLAB Function'

    _mm_storeu_pd(&rtY.p[r1], tmp_5);

    // Update for DiscreteIntegrator: '<S1>/Discrete-Time Integrator' incorporates:
    //   MATLAB Function: '<S1>/MATLAB Function'

    tmp_5 = _mm_set1_pd(0.001);
    tmp_2 = _mm_loadu_pd(&rtDW.DiscreteTimeIntegrator_DSTATE[r1]);
    _mm_storeu_pd(&rtDW.DiscreteTimeIntegrator_DSTATE[r1], _mm_add_pd(_mm_mul_pd
      (tmp_5, tmp_4), tmp_2));

    // Update for DiscreteIntegrator: '<S1>/Discrete-Time Integrator1' incorporates:
    //   MATLAB Function: '<S1>/MATLAB Function'

    tmp_2 = _mm_loadu_pd(&st[r1]);
    tmp_3 = _mm_loadu_pd(&rtDW.DiscreteTimeIntegrator1_DSTATE[r1]);
    _mm_storeu_pd(&rtDW.DiscreteTimeIntegrator1_DSTATE[r1], _mm_add_pd
                  (_mm_mul_pd(tmp_5, tmp_2), tmp_3));

    // Update for DiscreteIntegrator: '<S1>/Discrete-Time Integrator2' incorporates:
    //   MATLAB Function: '<S1>/MATLAB Function'

    tmp_2 = _mm_loadu_pd(&rtb_DiscreteTimeIntegrator1[r1]);
    tmp_3 = _mm_loadu_pd(&rtDW.DiscreteTimeIntegrator2_DSTATE[r1]);
    _mm_storeu_pd(&rtDW.DiscreteTimeIntegrator2_DSTATE[r1], _mm_add_pd
                  (_mm_mul_pd(tmp_5, tmp_2), tmp_3));

    // Update for DiscreteIntegrator: '<S1>/Discrete-Time QUELLO IMPORTANTE' incorporates:
    //   MATLAB Function: '<S1>/MATLAB Function'

    tmp_3 = _mm_loadu_pd(&rtb_DiscreteTimeIntegrator[r1]);

    // DiscreteIntegrator: '<S1>/Discrete-Time QUELLO IMPORTANTE' incorporates:
    //   MATLAB Function: '<S1>/MATLAB Function'

    tmp_1 = _mm_loadu_pd(&rtDW.DiscreteTimeQUELLOIMPORTANTE_DS[r1]);

    // Update for DiscreteIntegrator: '<S1>/Discrete-Time QUELLO IMPORTANTE' incorporates:
    //   MATLAB Function: '<S1>/MATLAB Function'

    _mm_storeu_pd(&rtDW.DiscreteTimeQUELLOIMPORTANTE_DS[r1], _mm_add_pd
                  (_mm_mul_pd(tmp_5, tmp_3), tmp_1));

    // Outport: '<Root>/p_dot' incorporates:
    //   MATLAB Function: '<S1>/MATLAB Function'

    _mm_storeu_pd(&rtY.p_dot[r1], tmp_3);

    // Outport: '<Root>/eta_dot' incorporates:
    //   MATLAB Function: '<S1>/MATLAB Function'

    _mm_storeu_pd(&rtY.eta_dot[r1], tmp_2);

    // Outport: '<Root>/p_ddot' incorporates:
    //   MATLAB Function: '<S1>/MATLAB Function'

    _mm_storeu_pd(&rtY.p_ddot[r1], tmp_4);

    // MATLAB Function: '<S1>/MATLAB Function'
    _mm_storeu_pd(&ct[r1], tmp_4);

    // End of Outputs for SubSystem: '<Root>/Subsystem'
  }

  // Outputs for Atomic SubSystem: '<Root>/Subsystem'
  for (r1 = 2; r1 < 3; r1++) {
    // Update for DiscreteIntegrator: '<S1>/Discrete-Time QUELLO IMPORTANTE'
    maxval = rtb_DiscreteTimeIntegrator[r1];

    // Update for DiscreteIntegrator: '<S1>/Discrete-Time Integrator2'
    a21 = rtb_DiscreteTimeIntegrator1[r1];

    // Outport: '<Root>/omega' incorporates:
    //   MATLAB Function: '<S1>/MATLAB Function'

    rtY.omega[r1] = ct[r1];

    // MATLAB Function: '<S1>/MATLAB Function' incorporates:
    //   Inport: '<Root>/f_ext'
    //   Inport: '<Root>/u'

    s = (c_0[r1] - ((b[r1 + 3] * 0.63784052711141159 * rtU.u[1] +
                     0.63784052711141159 * b[r1] * rtU.u[0]) + b[r1 + 6] *
                    0.63784052711141159 * rtU.u[2])) + rtU.f_ext[r1] / 1.56779;

    // Outport: '<Root>/p' incorporates:
    //   DiscreteIntegrator: '<S1>/Discrete-Time QUELLO IMPORTANTE'

    rtY.p[r1] = rtDW.DiscreteTimeQUELLOIMPORTANTE_DS[r1];

    // Update for DiscreteIntegrator: '<S1>/Discrete-Time Integrator'
    rtDW.DiscreteTimeIntegrator_DSTATE[r1] += 0.001 * s;

    // Update for DiscreteIntegrator: '<S1>/Discrete-Time Integrator1'
    rtDW.DiscreteTimeIntegrator1_DSTATE[r1] += 0.001 * st[r1];

    // Update for DiscreteIntegrator: '<S1>/Discrete-Time Integrator2'
    rtDW.DiscreteTimeIntegrator2_DSTATE[r1] += 0.001 * a21;

    // Update for DiscreteIntegrator: '<S1>/Discrete-Time QUELLO IMPORTANTE'
    rtDW.DiscreteTimeQUELLOIMPORTANTE_DS[r1] += 0.001 * maxval;

    // Outport: '<Root>/p_dot'
    rtY.p_dot[r1] = maxval;

    // Outport: '<Root>/eta_dot'
    rtY.eta_dot[r1] = a21;

    // Outport: '<Root>/p_ddot'
    rtY.p_ddot[r1] = s;

    // MATLAB Function: '<S1>/MATLAB Function'
    ct[r1] = s;
  }

  // End of Outputs for SubSystem: '<Root>/Subsystem'
}

// Model initialize function
void Subsystem::initialize()
{
  // (no initialization code required)
}

// Constructor
Subsystem::Subsystem() :
  rtU(),
  rtY(),
  rtDW(),
  rtM()
{
  // Currently there is no constructor body generated.
}

// Destructor
Subsystem::~Subsystem()
{
  // Currently there is no destructor body generated.
}

// Real-Time Model get method
Subsystem::RT_MODEL * Subsystem::getRTM()
{
  return (&rtM);
}

//
// File trailer for generated code.
//
// [EOF]
//
