// File:          norm_stand.cpp
// Date:
// Description:
// Author:
// Modifications:

// You may need to add webots include files such as
// <webots/DistanceSensor.hpp>, <webots/Motor.hpp>, etc.
// and/or to add some other includes
#include <webots/Robot.hpp>
#include <webots/Motor.hpp>

#include <iostream>
// All the webots classes are defined in the "webots" namespace
using namespace webots;

// This is the main program of your controller.
// It creates an instance of your Robot instance, launches its
// function(s) and destroys it at the end of the execution.
// Note that only one instance of Robot should be created in
// a controller program.
// The arguments of the main function can be specified by the
// "controllerArgs" field of the Robot node
int main(int argc, char **argv) {
  // create the Robot instance.
  Robot *robot = new Robot();
  Motor *jointLeg[12];

  std::string jointLegName[12] = {"leg1_hip_joint", "leg1_thigh_joint", "leg1_calf_joint",
                                 "leg2_hip_joint", "leg2_thigh_joint", "leg2_calf_joint",
                                 "leg3_hip_joint", "leg3_thigh_joint", "leg3_calf_joint",
                                 "leg4_hip_joint", "leg4_thigh_joint", "leg4_calf_joint"};
  for (int i = 0; i < 12; i++)
    jointLeg[i] = robot->getMotor(jointLegName[i]);
  
  double q[12] = {0.0, 0.67, -1.3, 0.0, 0.67, -1.3, 0.0, 0.67, -1.3, 0.0, 0.67, -1.3};
  
  int timeStep = (int)robot->getBasicTimeStep();


  while (robot->step(timeStep) != -1) 
  {
    for (int i = 0; i < 12; i++)
      jointLeg[i]->setPosition(q[i]);
  };

  // Enter here exit cleanup code.

  delete robot;
  return 0;
}
