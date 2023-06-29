//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: ert_main.cpp
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
#include <stdio.h>              // This example main program uses printf/fflush
#include "Subsystem1.h"                // Model header file
#include <iostream>
#include <fstream>
#include "ros/ros.h"
#include <ros/package.h>

using namespace std;

static Subsystem1 rtObj;               // Instance of model class

//
// Associating rt_OneStep with a real-time clock or interrupt service routine
// is what makes the generated code "real-time".  The function rt_OneStep is
// always associated with the base rate of the model.  Subrates are managed
// by the base rate from inside the generated code.  Enabling/disabling
// interrupts and floating point context switches are target specific.  This
// example code indicates where these should take place relative to executing
// the generated code step function.  Overrun behavior should be tailored to
// your application needs.  This example simply sets an error status in the
// real-time model and returns from rt_OneStep.
//
void rt_OneStep(void);
void rt_OneStep(void)
{
  static boolean_T OverrunFlag{ false };

  // Disable interrupts here

  // Check for overrun
  if (OverrunFlag) {
    rtmSetErrorStatus(rtObj.getRTM(), "Overrun");
    return;
  }

  OverrunFlag = true;

  // Save FPU context here (if necessary)
  // Re-enable timer or interrupt here
  // Set model inputs here

  // Step the model
  rtObj.step();

  // Get model outputs here

  // Indicate task complete
  OverrunFlag = false;

  // Disable interrupts here
  // Restore FPU context here (if necessary)
  // Enable interrupts here
}

//
// The example main function illustrates what is required by your
// application code to initialize, execute, and terminate the generated code.
// Attaching rt_OneStep to a real-time clock is target specific. This example
// illustrates how you do this relative to initializing the model.
//
int_T main(int_T argc, char *argv[])
{

  ros::init(argc, argv, "HexC");

  // Unused arguments
  (void)(argc);
  (void)(argv);

  // Read the trajectory from file

	ifstream ref;

	string pkg_loc = ros::package::getPath("HexC");
	ref.open(pkg_loc + "/Trajectory_ref.txt", ios::in); 

	if (!ref.is_open()) {
		cout<<"Error opening the file!";
		exit(1);
	}

	//trajectory length
	int N;
	ref>>N;

	double* x_d = new double[N];
	double* y_d = new double[N];
	double* z_d = new double[N];
  double* x_d_dot = new double[N];
	double* y_d_dot = new double[N];
	double* z_d_dot = new double[N];
	double* x_d_ddot = new double[N];
	double* y_d_ddot = new double[N];
	double* z_d_ddot = new double[N];
  double* phi_d = new double[N];
	double* phi_d_dot = new double[N];
	double* phi_d_ddot = new double[N];
  double* theta_d = new double[N];
	double* theta_d_dot = new double[N];
	double* theta_d_ddot = new double[N];
  double* psi_d = new double[N];
	double* psi_d_dot = new double[N];
	double* psi_d_ddot = new double[N];

	for (int i = 0; i<N; i++) {
		ref>>x_d[i];
		ref>>y_d[i];
		ref>>z_d[i];
    ref>>x_d_dot[i];
    ref>>y_d_dot[i];
    ref>>z_d_dot[i];
    ref>>x_d_ddot[i];
    ref>>y_d_ddot[i];
    ref>>z_d_ddot[i];
    ref>>phi_d[i];
    ref>>phi_d_dot[i];
    ref>>phi_d_ddot[i];
    ref>>theta_d[i];
    ref>>theta_d_dot[i];
    ref>>theta_d_ddot[i];
    ref>>psi_d[i];
    ref>>psi_d_dot[i];
    ref>>psi_d_ddot[i];
	}

	ref.close();

  // Initialize model
  rtObj.initialize();

  // Attach rt_OneStep to a timer or interrupt service routine with
  //  period 0.001 seconds (base rate of the model) here.
  //  The call syntax for rt_OneStep is
  //
  //   rt_OneStep();

  fflush((nullptr));

  int i = 0; // The controller will work as long as there are reference points in the trajectory

  while ((rtmGetErrorStatus(rtObj.getRTM()) == (nullptr)) && (ros::ok()) && i<N) {
    //  Perform application tasks here
    cout<<x_d[i];
    i++;
  }

  delete [] x_d;
  delete [] y_d;
  delete [] z_d;
  delete [] x_d_dot;
  delete [] y_d_dot;
  delete [] z_d_dot;
  delete [] x_d_ddot;
  delete [] y_d_ddot;
  delete [] z_d_ddot;
  delete [] phi_d;
  delete [] phi_d_dot;
  delete [] phi_d_ddot;
  delete [] theta_d;
  delete [] theta_d_dot;
  delete [] theta_d_ddot;
  delete [] psi_d;
  delete [] psi_d_dot;
  delete [] psi_d_ddot;


  return 0;
}

//
// File trailer for generated code.
//
// [EOF]
//
