//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: Subsystem1.h
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
#ifndef RTW_HEADER_Subsystem1_h_
#define RTW_HEADER_Subsystem1_h_
#include "rtwtypes.h"
#include <stddef.h>

// Macros for accessing real-time model data structure
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

extern "C"
{
  static real_T rtGetNaN(void);
  static real32_T rtGetNaNF(void);
}                                      // extern "C"

#define NOT_USING_NONFINITE_LITERALS   1

extern "C"
{
  extern real_T rtInf;
  extern real_T rtMinusInf;
  extern real_T rtNaN;
  extern real32_T rtInfF;
  extern real32_T rtMinusInfF;
  extern real32_T rtNaNF;
  static void rt_InitInfAndNaN(size_t realSize);
  static boolean_T rtIsInf(real_T value);
  static boolean_T rtIsInfF(real32_T value);
  static boolean_T rtIsNaN(real_T value);
  static boolean_T rtIsNaNF(real32_T value);
  struct BigEndianIEEEDouble {
    struct {
      uint32_T wordH;
      uint32_T wordL;
    } words;
  };

  struct LittleEndianIEEEDouble {
    struct {
      uint32_T wordL;
      uint32_T wordH;
    } words;
  };

  struct IEEESingle {
    union {
      real32_T wordLreal;
      uint32_T wordLuint;
    } wordL;
  };
}                                      // extern "C"

extern "C"
{
  static real_T rtGetInf(void);
  static real32_T rtGetInfF(void);
  static real_T rtGetMinusInf(void);
  static real32_T rtGetMinusInfF(void);
}                                      // extern "C"

// Class declaration for model Subsystem1
class Subsystem1 final
{
  // public data and function members
 public:
  // Block signals and states (default storage) for system '<Root>'
  struct DW {
    real_T DiscreteTimeIntegrator_DSTATE[6];// '<S1>/Discrete-Time Integrator'
    real_T DiscreteTimeIntegrator2_DSTATE[6];// '<S1>/Discrete-Time Integrator2' 
    real_T DiscreteTimeIntegrator1_DSTATE[6];// '<S1>/Discrete-Time Integrator1' 
    real_T UnitDelayu0mass92_DSTATE[3];// '<S1>/Unit Delay u0=mass*9.2'
    real_T UnitDelay2_DSTATE[3];       // '<S1>/Unit Delay2'
    real_T Derivation_states[3];       // '<S2>/Derivation'
    real_T Derivation1_states[3];      // '<S2>/Derivation1'
  };

  // Constant parameters (default storage)
  struct ConstP {
    // Expression: D0
    //  Referenced by: '<S2>/Inner-loop control'

    real_T Innerloopcontrol_D0[9];

    // Pooled Parameter (Expression: Ib)
    //  Referenced by:
    //    '<S1>/MATLAB Function'
    //    '<S1>/MATLAB Function1'
    //    '<S2>/Inner-loop control'

    real_T pooled1[9];

    // Expression: K0
    //  Referenced by: '<S2>/Inner-loop control'

    real_T Innerloopcontrol_K0[9];

    // Expression: M_bar
    //  Referenced by: '<S1>/MATLAB Function2'

    real_T MATLABFunction2_M_bar[36];

    // Expression: Kd
    //  Referenced by: '<S1>/Outer-loop control'

    real_T Outerloopcontrol_Kd[9];

    // Expression: Kp
    //  Referenced by: '<S1>/Outer-loop control'

    real_T Outerloopcontrol_Kp[9];
  };

  // External inputs (root inport signals with default storage)
  struct ExtU {
    real_T position[3];                // '<Root>/position'
    real_T linear_vel[3];              // '<Root>/linear_vel'
    real_T eta[3];                     // '<Root>/eta'
    real_T eta_dot[3];                 // '<Root>/eta_dot'
    real_T position_des[3];            // '<Root>/position_des'
    real_T vel_linear_des[3];          // '<Root>/vel_linear_des'
    real_T acc_linear_des[3];          // '<Root>/acc_linear_des'
    real_T phi_d;                      // '<Root>/phi_d'
    real_T theta_d;                    // '<Root>/theta_d'
    real_T psi_d;                      // '<Root>/psi_d'
  };

  // External outputs (root outports fed by signals with default storage)
  struct ExtY {
    real_T u[6];                       // '<Root>/u'
    real_T velocities[6];              // '<Root>/velocities'
  };

  // Real-time Model Data Structure
  struct RT_MODEL {
    const char_T * volatile errorStatus;
  };

  // Copy Constructor
  Subsystem1(Subsystem1 const&) = delete;

  // Assignment Operator
  Subsystem1& operator= (Subsystem1 const&) & = delete;

  // Move Constructor
  Subsystem1(Subsystem1 &&) = delete;

  // Move Assignment Operator
  Subsystem1& operator= (Subsystem1 &&) = delete;

  // Real-Time Model get method
  Subsystem1::RT_MODEL * getRTM();

  // External inputs
  ExtU rtU;

  // External outputs
  ExtY rtY;

  // model initialize function
  void initialize();

  // model step function
  void step();

  // Constructor
  Subsystem1();

  // Destructor
  ~Subsystem1();

  // private data and function members
 private:
  // Block states
  DW rtDW;

  // Real-Time Model
  RT_MODEL rtM;
};

// Constant parameters (default storage)
extern const Subsystem1::ConstP rtConstP;

//-
//  These blocks were eliminated from the model due to optimizations:
//
//  Block '<S1>/Scope' : Unused code path elimination
//  Block '<S1>/Scope1' : Unused code path elimination
//  Block '<S1>/Scope2' : Unused code path elimination
//  Block '<S1>/Scope3' : Unused code path elimination
//  Block '<S1>/Scope4' : Unused code path elimination
//  Block '<S1>/Scope5' : Unused code path elimination
//  Block '<S1>/Scope6' : Unused code path elimination
//  Block '<S1>/Scope7' : Unused code path elimination
//  Block '<S1>/To Workspace10' : Unused code path elimination
//  Block '<S1>/To Workspace11' : Unused code path elimination
//  Block '<S1>/To Workspace12' : Unused code path elimination
//  Block '<S1>/To Workspace13' : Unused code path elimination
//  Block '<S1>/To Workspace7' : Unused code path elimination
//  Block '<S1>/To Workspace8' : Unused code path elimination
//  Block '<S1>/To Workspace9' : Unused code path elimination


//-
//  The generated code includes comments that allow you to trace directly
//  back to the appropriate location in the model.  The basic format
//  is <system>/block_name, where system is the system number (uniquely
//  assigned by Simulink) and block_name is the name of the block.
//
//  Note that this particular code originates from a subsystem build,
//  and has its own system numbers different from the parent model.
//  Refer to the system hierarchy for this subsystem below, and use the
//  MATLAB hilite_system command to trace the generated code back
//  to the parent model.  For example,
//
//  hilite_system('HexC_FeedbackLinearizationControllerCodeGeneration/Subsystem1')    - opens subsystem HexC_FeedbackLinearizationControllerCodeGeneration/Subsystem1
//  hilite_system('HexC_FeedbackLinearizationControllerCodeGeneration/Subsystem1/Kp') - opens and selects block Kp
//
//  Here is the system hierarchy for this model
//
//  '<Root>' : 'HexC_FeedbackLinearizationControllerCodeGeneration'
//  '<S1>'   : 'HexC_FeedbackLinearizationControllerCodeGeneration/Subsystem1'
//  '<S2>'   : 'HexC_FeedbackLinearizationControllerCodeGeneration/Subsystem1/Inner-loop control'
//  '<S3>'   : 'HexC_FeedbackLinearizationControllerCodeGeneration/Subsystem1/MATLAB Function'
//  '<S4>'   : 'HexC_FeedbackLinearizationControllerCodeGeneration/Subsystem1/MATLAB Function1'
//  '<S5>'   : 'HexC_FeedbackLinearizationControllerCodeGeneration/Subsystem1/MATLAB Function2'
//  '<S6>'   : 'HexC_FeedbackLinearizationControllerCodeGeneration/Subsystem1/Outer-loop control'
//  '<S7>'   : 'HexC_FeedbackLinearizationControllerCodeGeneration/Subsystem1/Inner-loop control/Inner-loop control'

#endif                                 // RTW_HEADER_Subsystem1_h_

//
// File trailer for generated code.
//
// [EOF]
//
