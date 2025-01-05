// File:          joystick_test.cpp
// Date:
// Description:
// Author:
// Modifications:

// You may need to add webots include files such as
// <webots/DistanceSensor.hpp>, <webots/Motor.hpp>, etc.
// and/or to add some other includes
#include <webots/Robot.hpp>
#include <webots/Joystick.hpp>
#include <iostream>

// All the webots classes are defined in the "webots" namespace
using namespace webots;
using namespace std;
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
  Joystick *joystick = new Joystick();
  
  // get the time step of the current world.
  int timeStep = (int)robot->getBasicTimeStep();
  joystick -> enable(timeStep);
  // You should insert a getDevice-like function in order to get the
  // instance of a device of the robot. Something like:
  //  Motor *motor = robot->getMotor("motorname");
  //  DistanceSensor *ds = robot->getDistanceSensor("dsname");
  //  ds->enable(timeStep);

  // Main loop:
  // - perform simulation steps until Webots is stopping the controller
  while (robot->step(timeStep) != -1) {
    // Read the sensors:
    // Enter here functions to read sensor data, like:
    //  double val = ds->getValue();
    cout << "getAxisValue(0)   "<<joystick->getAxisValue(0) << endl;
    cout << "getAxisValue(1)   "<<joystick->getAxisValue(1) << endl;
    cout << "getAxisValue(2)   "<<joystick->getAxisValue(2) << endl;
    cout << "getAxisValue(3)   "<<joystick->getAxisValue(3) << endl;
    // Process sensor data here.

    // Enter here functions to send actuator commands, like:
    //  motor->setPosition(10.0);
  };

  // Enter here exit cleanup code.

  delete robot;
  return 0;
}
