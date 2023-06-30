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
#include "Subsystem.h"                // Model header file
#include <iostream>
#include <fstream>
#include "ros/ros.h"
#include <ros/package.h>
#include "boost/thread.hpp"
#include "geometry_msgs/Vector3.h"
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
		void cb(geometry_msgs::Wrench::ConstPtr odom);
    void loop(void);
    
	private:
    Subsystem rtObj;
    double position[3]; 
    double linear_vel[3];
    double eta[3];
    double eta_dot[3];
    double force[3];
    double torque[3];
		ros::NodeHandle _nh;
		ros::Subscriber _topic_sub;
    ros::Publisher _topic_pub_pos;
    ros::Publisher _topic_pub_pos_dot;
    ros::Publisher _topic_pub_eta;
    ros::Publisher _topic_pub_eta_dot;
		ros::Rate _rate;
};

PubSubs::PubSubs(): _rate(_freq){

  _topic_sub = _nh.subscribe("/wrench", 1, &PubSubs::cb, this);
	_topic_pub_pos = _nh.advertise<geometry_msgs::Vector3>("/position", 1);
  _topic_pub_pos_dot = _nh.advertise<geometry_msgs::Vector3>("/position_dot", 1);
	_topic_pub_eta = _nh.advertise<geometry_msgs::Vector3>("/eta", 1);
  _topic_pub_eta_dot = _nh.advertise<geometry_msgs::Vector3>("/eta_dot", 1);


  for(int i = 0; i < 3; i++){
    position[i] = 0; 
    linear_vel[i] = 0;
    eta[i] = 0;   
    eta_dot[i] = 0;
    rtObj.rtU.f_ext[i] = 0;
    rtObj.rtU.tau_ext[i] = 0;
  }
  
  force[0]  = 0;
  force[1]  = 0;
  force[2]  = 0;
  torque[0] = 0;
  torque[1] = 0;
  torque[2] = 0;
   
  rtObj.initialize();

  boost::thread(&PubSubs::loop, this);
}

PubSubs::~PubSubs(){
}

void PubSubs::loop(void){
  // static boolean_T OverrunFlag;

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

    for(int i = 0; i < 3; i++){
      rtObj.rtU.u[i] = force[i];
      rtObj.rtU.u[i+3] = torque[i];
    }

    // Step the model
    rtObj.step();

    // Get model outputs here
    for(int i = 0; i < 3; i++){
      position[i] = rtObj.rtY.p[i]; 
      linear_vel[i] = rtObj.rtY.p_dot[i];
      eta[i] = rtObj.rtY.eta[i];
      eta_dot[i] = rtObj.rtY.eta_dot[i];
    }

    // Publish
    geometry_msgs::Vector3 p_m;
    geometry_msgs::Vector3 p_dot_m;
    geometry_msgs::Vector3 eta_m;
    geometry_msgs::Vector3 eta_dot_m;

    p_m.x = position[0];
    p_dot_m.x = linear_vel[0];
    eta_m.x = eta[0];
    eta_dot_m.x = eta_dot[0];
    p_m.y = position[1];
    p_dot_m.y = linear_vel[1];
    eta_m.y = eta[1];
    eta_dot_m.y = eta_dot[1];
    p_m.z = position[2];
    p_dot_m.z = linear_vel[2];
    eta_m.z = eta[2];
    eta_dot_m.z = eta_dot[2];

    _topic_pub_pos.publish(p_m);
    _topic_pub_pos_dot.publish(p_dot_m);
    _topic_pub_eta.publish(eta_m);
    _topic_pub_eta_dot.publish(eta_dot_m);

    // OverrunFlag = false;

    // Disable interrupts here
    // Restore FPU context here (if necessary)
    // Enable interrupts here
    
    // std::cout << position[2] << "\t" << linear_vel[2] << "\t" << eta[2] << "\t" << eta_dot[0] << "\n";
    // if(i_ref < N-1){
    //   // i_ref++;
    // }
    _rate.sleep();
  }
}

void PubSubs::cb(geometry_msgs::Wrench::ConstPtr odom){

  force[0] = odom->force.x;
  force[1] = odom->force.y;
  force[2] = odom->force.z;
  torque[0] = odom->torque.x;
  torque[1] = odom->torque.y;
  torque[2] = odom->torque.z;

}

int_T main(int_T argc, char *argv[])
{

  ros::init(argc, argv, "HexModel");

  // Unused arguments
  (void)(argc);
  (void)(argv);

  PubSubs Obj;

  ros::spin();

  return 0;
}

//
// File trailer for generated code.
//
// [EOF]
//
