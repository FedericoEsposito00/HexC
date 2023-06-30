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
#include "boost/thread.hpp"
#include "nav_msgs/Odometry.h"
#include "mav_msgs/Actuators.h"
#include <tf2/LinearMath/Quaternion.h>
#include <tf2_geometry_msgs/tf2_geometry_msgs.h>

// static Subsystem1 rtObj;               // Instance of model class
#define _freq 1000
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
// void rt_OneStep(void);
// void rt_OneStep(void)
// {
//   static boolean_T OverrunFlag{ false };

//   // Disable interrupts here

//   // Check for overrun
//   if (OverrunFlag) {
//     rtmSetErrorStatus(rtObj.getRTM(), "Overrun");
//     return;
//   }

//   OverrunFlag = true;

//   // Save FPU context here (if necessary)
//   // Re-enable timer or interrupt here
//   // Set model inputs here

//   // Step the model
//   rtObj.step();

//   // Get model outputs here

//   // Indicate task complete
//   OverrunFlag = false;

//   // Disable interrupts here
//   // Restore FPU context here (if necessary)
//   // Enable interrupts here
// }

class PubSubs {
	public:
		PubSubs();
    ~PubSubs();
		void cb(nav_msgs::Odometry::ConstPtr odom);
    void loop(void);
    
	private:
    Subsystem1 rtObj;
    int N;
    double* x_d;
    double* y_d;
    double* z_d;
    double* x_d_dot;
    double* y_d_dot;
    double* z_d_dot;
    double* x_d_ddot;
    double* y_d_ddot;
    double* z_d_ddot;
    double* phi_d;
    double* phi_d_dot;
    double* phi_d_ddot;
    double* theta_d;
    double* theta_d_dot ;
    double* theta_d_ddot;
    double* psi_d;
    double* psi_d_dot;
    double* psi_d_ddot;
    double position[3]; 
    double linear_vel[3];
    double eta[3];      
    double eta_dot[3];
		ros::NodeHandle _nh;
		ros::Subscriber _topic_sub;
		ros::Publisher _topic_pub;
    ros::Publisher _topic_pub_wrench;
		ros::Rate _rate;
};

PubSubs::PubSubs(): _rate(_freq){


  _topic_sub = _nh.subscribe("/firefly/ground_truth/odometry", 1, &PubSubs::cb, this);
	_topic_pub = _nh.advertise<mav_msgs::Actuators>("/firefly/command/motor_speed", 1);
  _topic_pub_wrench = _nh.advertise<geometry_msgs::Wrench>("/firefly/command/wrench", 1);

  std::ifstream ref;

	std::string pkg_loc = ros::package::getPath("HexC");
	ref.open(pkg_loc + "/Trajectory_ref.txt", std::ios::in); 

	if (!ref.is_open()) {
		std::cout << "Error opening the file!" << std::endl;
		exit(1);
	}


	//trajectory length
	ref >>  N;
  
  x_d = new double[N];
  y_d = new double[N];
  z_d = new double[N];
  x_d_dot = new double[N];
  y_d_dot = new double[N];
  z_d_dot = new double[N];
  x_d_ddot = new double[N];
  y_d_ddot = new double[N];
  z_d_ddot = new double[N];
  phi_d = new double[N];
  phi_d_dot = new double[N];
  phi_d_ddot = new double[N];
  theta_d = new double[N];
  theta_d_dot = new double[N];
  theta_d_ddot = new double[N];
  psi_d = new double[N];
  psi_d_dot = new double[N];
  psi_d_ddot = new double[N];

	for (int i = 0; i<N; i++) {
		ref >> x_d[i];
		ref >> y_d[i];
		ref >> z_d[i];
    ref >> x_d_dot[i];
    ref >> y_d_dot[i];
    ref >> z_d_dot[i];
    ref >> x_d_ddot[i];
    ref >> y_d_ddot[i];
    ref >> z_d_ddot[i];
    ref >> phi_d[i];
    ref >> phi_d_dot[i];
    ref >> phi_d_ddot[i];
    ref >> theta_d[i];
    ref >> theta_d_dot[i];
    ref >> theta_d_ddot[i];
    ref >> psi_d[i];
    ref >> psi_d_dot[i];
    ref >> psi_d_ddot[i];
	}

	ref.close();

  rtObj.initialize();

  boost::thread(&PubSubs::loop, this);

}

PubSubs::~PubSubs(){
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
}

void PubSubs::loop(void){
  // static boolean_T OverrunFlag;
  int i_ref = 0;

  // std::cout << "I am looping!\n";

  while(ros::ok()){

    // OverrunFlag = false;

    // Disable interrupts here

    // Check for overrun
    // if (OverrunFlag) {
    //   rtmSetErrorStatus(rtObj.getRTM(), "Overrun");
    //   return;
    // }

    // OverrunFlag = true;

    // Save FPU context here (if necessary)
    // Re-enable timer or interrupt here
    // Set model inputs here

    rtObj.rtU.position[0] =  position[0]; 
    rtObj.rtU.linear_vel[0] = linear_vel[0];
    rtObj.rtU.eta[0] = eta[0];      
    rtObj.rtU.eta_dot[0] =  eta_dot[0];
    rtObj.rtU.position[1] =  position[1]; 
    rtObj.rtU.linear_vel[1] = linear_vel[1];
    rtObj.rtU.eta[1] = eta[1];      
    rtObj.rtU.eta_dot[1] =  eta_dot[1];
    rtObj.rtU.position[2] =  position[2]; 
    rtObj.rtU.linear_vel[2] = linear_vel[2];
    rtObj.rtU.eta[2] = eta[2];      
    rtObj.rtU.eta_dot[2] =  eta_dot[2];

    rtObj.rtU.position_des[0] =  x_d[i_ref];
    rtObj.rtU.position_des[1] =  y_d[i_ref]; 
    rtObj.rtU.position_des[2] =  z_d[i_ref];
    rtObj.rtU.vel_linear_des[0] =  x_d_dot[i_ref];
    rtObj.rtU.vel_linear_des[1] =  y_d_dot[i_ref]; 
    rtObj.rtU.vel_linear_des[2] =  z_d_dot[i_ref];
    rtObj.rtU.acc_linear_des[0] =  x_d_ddot[i_ref];
    rtObj.rtU.acc_linear_des[1] =  y_d_ddot[i_ref]; 
    rtObj.rtU.acc_linear_des[2] =  z_d_ddot[i_ref];
    rtObj.rtU.phi_d = phi_d[i_ref];
    rtObj.rtU.theta_d = theta_d[i_ref];
    rtObj.rtU.psi_d = psi_d[i_ref];

  
    // std::cout << "Data sent to model!\n";

    // Step the model
    rtObj.step();
    // std::cout << "Exiting step " << i_ref << "\n";
    // Get model outputs here
    
    mav_msgs::Actuators speeds;
    // speeds.angular_velocities = [rtObj.rtY.velocities[0], rtObj.rtY.velocities[1], rtObj.rtY.velocities[2], rtObj.rtY.velocities[3], rtObj.rtY.velocities[4], rtObj.rtY.velocities[5]];
    // for(int i = 0; i++; i < 6){
    //   speeds.angular_velocities[i] = rtObj.rtY.velocities[i];
    // }
    for (int i = 0; i < 6; i++){
      if(rtObj.rtY.velocities[i] > 1200){
        speeds.angular_velocities.push_back(1200);
      }else if(rtObj.rtY.velocities[i] < -1200){
        speeds.angular_velocities.push_back(-1200);
      }else{
        speeds.angular_velocities.push_back(rtObj.rtY.velocities[i]);
      }
    }
    // std::cout << "Sending speeds\n"; 
    _topic_pub.publish(speeds);

    for (int i = 0; i < 6; i++){
        std::cout << rtObj.rtY.u[i] << "\t";
    }
    std::cout << std::endl;

    // std::cout << "Speed is" << speeds.angular_velocities[3] << "\n";

    // Indicate task complete
    // OverrunFlag = false;

    // Disable interrupts here
    // Restore FPU context here (if necessary)
    // Enable interrupts here
    
    // std::cout << position[2] << "\t" << linear_vel[2] << "\t" << eta[2] << "\t" << eta_dot[0] << "\n";
    if(i_ref < N-1){
      i_ref++;
    }
    _rate.sleep();
  }
}

void PubSubs::cb(nav_msgs::Odometry::ConstPtr odom){

  tf2::Quaternion q;
  double temp_vel[3];

  // Position
  position[0] = odom->pose.pose.position.x;
  position[1] = odom->pose.pose.position.y;
  position[2] = -odom->pose.pose.position.z;

  // Quaternion
  tf2::convert(odom->pose.pose.orientation, q);
  tf2::Matrix3x3 m(q);

  // Quaternion to Eta
  m.getRPY( eta[0],  eta[1],  eta[2]);
  eta[1] = eta[1];
  eta[2] = eta[2];

  // Linear Velocity
  linear_vel[0] = odom->twist.twist.linear.x;
  linear_vel[1] = odom->twist.twist.linear.y;
  linear_vel[2] = -odom->twist.twist.linear.z;
  tf2::Vector3 temp_vel2 = m*tf2::Vector3(linear_vel[0], linear_vel[1], linear_vel[2]);
  linear_vel[0] = temp_vel2[0];
  linear_vel[1] = temp_vel2[1];
  linear_vel[2] = temp_vel2[2];

  // Angular Velocity w
  temp_vel[0] = odom->twist.twist.angular.x;
  temp_vel[1] = odom->twist.twist.angular.y;
  temp_vel[2] = -odom->twist.twist.angular.z;

  // w to Eta_dot
  eta_dot[0] = temp_vel[0] + temp_vel[2]*cos(eta[0])*tan(eta[1]) + temp_vel[1]*sin(eta[0])*tan(eta[1]);
  eta_dot[1] = temp_vel[1]*cos(eta[0]) - temp_vel[2]*sin(eta[0]);
  eta_dot[2] = temp_vel[2]*cos(eta[0])/cos(eta[1]) + temp_vel[1]*sin(eta[0])/cos(eta[1]);

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

  // // Read the trajectory from file

	// std::ifstream ref;

	// std::string pkg_loc = ros::package::getPath("HexC");
	// ref.open(pkg_loc + "/Trajectory_ref.txt", ios::in); 

	// if (!ref.is_open()) {
	// 	std::cout << "Error opening the file!";
	// 	exit(1);
	// }

	// //trajectory length
	// int N;
	// ref >>  N;

	// double* x_d = new double[N];
	// double* y_d = new double[N];
	// double* z_d = new double[N];
  // double* x_d_dot = new double[N];
	// double* y_d_dot = new double[N];
	// double* z_d_dot = new double[N];
	// double* x_d_ddot = new double[N];
	// double* y_d_ddot = new double[N];
	// double* z_d_ddot = new double[N];
  // double* phi_d = new double[N];
	// double* phi_d_dot = new double[N];
	// double* phi_d_ddot = new double[N];
  // double* theta_d = new double[N];
	// double* theta_d_dot = new double[N];
	// double* theta_d_ddot = new double[N];
  // double* psi_d = new double[N];
	// double* psi_d_dot = new double[N];
	// double* psi_d_ddot = new double[N];

	// for (int i = 0; i<N; i++) {
	// 	ref >> x_d[i];
	// 	ref >> y_d[i];
	// 	ref >> z_d[i];
  //   ref >> x_d_dot[i];
  //   ref >> y_d_dot[i];
  //   ref >> z_d_dot[i];
  //   ref >> x_d_ddot[i];
  //   ref >> y_d_ddot[i];
  //   ref >> z_d_ddot[i];
  //   ref >> phi_d[i];
  //   ref >> phi_d_dot[i];
  //   ref >> phi_d_ddot[i];
  //   ref >> theta_d[i];
  //   ref >> theta_d_dot[i];
  //   ref >> theta_d_ddot[i];
  //   ref >> psi_d[i];
  //   ref >> psi_d_dot[i];
  //   ref >> psi_d_ddot[i];
	// }

	// ref.close();

  // Initialize model
  // rtObj.initialize();

  // Attach rt_OneStep to a timer or interrupt service routine with
  //  period 0.001 seconds (base rate of the model) here.
  //  The call syntax for rt_OneStep is
  //
  //   rt_OneStep();

  // fflush((nullptr));

  // int i = 0; // The controller will work as long as there are reference points in the trajectory

  // while ((rtmGetErrorStatus(rtObj.getRTM()) == (nullptr)) && (ros::ok()) && i<N) {
  //   //  Perform application tasks here
  //   i++;
  // }

  // delete [] x_d;
  // delete [] y_d;
  // delete [] z_d;
  // delete [] x_d_dot;
  // delete [] y_d_dot;
  // delete [] z_d_dot;
  // delete [] x_d_ddot;
  // delete [] y_d_ddot;
  // delete [] z_d_ddot;
  // delete [] phi_d;
  // delete [] phi_d_dot;
  // delete [] phi_d_ddot;
  // delete [] theta_d;
  // delete [] theta_d_dot;
  // delete [] theta_d_ddot;
  // delete [] psi_d;
  // delete [] psi_d_dot;
  // delete [] psi_d_ddot;


  PubSubs Obj;

  ros::spin();

  return 0;
}

//
// File trailer for generated code.
//
// [EOF]
//
