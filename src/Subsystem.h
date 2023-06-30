//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: Subsystem.h
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
#ifndef RTW_HEADER_Subsystem_h_
#define RTW_HEADER_Subsystem_h_
#include "rtwtypes.h"

// Macros for accessing real-time model data structure
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

// Class declaration for model Subsystem
class Subsystem final
{
  // public data and function members
 public:
  // Block signals and states (default storage) for system '<Root>'
  struct DW {
    real_T DiscreteTimeIntegrator_DSTATE[3];// '<S1>/Discrete-Time Integrator'
    real_T DiscreteTimeIntegrator1_DSTATE[3];// '<S1>/Discrete-Time Integrator1' 
    real_T DiscreteTimeIntegrator2_DSTATE[3];// '<S1>/Discrete-Time Integrator2' 
    real_T DiscreteTimeQUELLOIMPORTANTE_DS[3];
                                      // '<S1>/Discrete-Time QUELLO IMPORTANTE'
  };

  // Constant parameters (default storage)
  struct ConstP {
    // Expression: Ib
    //  Referenced by: '<S1>/MATLAB Function'

    real_T MATLABFunction_Ib[9];
  };

  // External inputs (root inport signals with default storage)
  struct ExtU {
    real_T u[6];                       // '<Root>/u'
    real_T f_ext[3];                   // '<Root>/f_ext'
    real_T tau_ext[3];                 // '<Root>/tau_ext'
  };

  // External outputs (root outports fed by signals with default storage)
  struct ExtY {
    real_T p_dot[3];                   // '<Root>/p_dot'
    real_T p[3];                       // '<Root>/p'
    real_T eta_dot[3];                 // '<Root>/eta_dot'
    real_T eta[3];                     // '<Root>/eta'
    real_T p_ddot[3];                  // '<Root>/p_ddot'
    real_T omega[3];                   // '<Root>/omega'
  };

  // Real-time Model Data Structure
  struct RT_MODEL {
    const char_T * volatile errorStatus;
  };

  // Copy Constructor
  Subsystem(Subsystem const&) = delete;

  // Assignment Operator
  Subsystem& operator= (Subsystem const&) & = delete;

  // Move Constructor
  Subsystem(Subsystem &&) = delete;

  // Move Assignment Operator
  Subsystem& operator= (Subsystem &&) = delete;

  // Real-Time Model get method
  Subsystem::RT_MODEL * getRTM();

  // External inputs
  ExtU rtU;

  // External outputs
  ExtY rtY;

  // model initialize function
  static void initialize();

  // model step function
  void step();

  // Constructor
  Subsystem();

  // Destructor
  ~Subsystem();

  // private data and function members
 private:
  // Block states
  DW rtDW;

  // Real-Time Model
  RT_MODEL rtM;
};

// Constant parameters (default storage)
extern const Subsystem::ConstP rtConstP;

//-
//  These blocks were eliminated from the model due to optimizations:
//
//  Block '<S1>/Scope' : Unused code path elimination
//  Block '<S1>/Scope1' : Unused code path elimination
//  Block '<S1>/Scope2' : Unused code path elimination


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
//  hilite_system('HexC_FeedbackLinearizationController/Subsystem')    - opens subsystem HexC_FeedbackLinearizationController/Subsystem
//  hilite_system('HexC_FeedbackLinearizationController/Subsystem/Kp') - opens and selects block Kp
//
//  Here is the system hierarchy for this model
//
//  '<Root>' : 'HexC_FeedbackLinearizationController'
//  '<S1>'   : 'HexC_FeedbackLinearizationController/Subsystem'
//  '<S2>'   : 'HexC_FeedbackLinearizationController/Subsystem/MATLAB Function'

#endif                                 // RTW_HEADER_Subsystem_h_

//
// File trailer for generated code.
//
// [EOF]
//
