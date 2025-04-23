#include <webots/Robot.hpp>
#include <webots/Joystick.hpp>
#include <iostream>

using namespace webots;
using namespace std;


int main(int argc, char **argv) {
  Robot *robot = new Robot();
  Joystick *joystick = new Joystick();
  
  int timeStep = (int)robot->getBasicTimeStep();
  joystick -> enable(timeStep);

  while (robot->step(timeStep) != -1) {
    
    int key1 = joystick->getPressedButton();
    int key2 = joystick->getPressedButton();
    
    cout << "Value of axis 0: \t"<<joystick->getAxisValue(0) << endl;
    cout << "Value of axis 1: \t"<<joystick->getAxisValue(1) << endl;
    cout << "Value of axis 2: \t"<<joystick->getAxisValue(2) << endl;
    cout << "Value of axis 3: \t"<<joystick->getAxisValue(3) << endl;
    cout << "Value of axis 4: \t"<<joystick->getAxisValue(4) << endl;
    cout << "Value of axis 5: \t"<<joystick->getAxisValue(5) << endl;
    cout << "Value of pov 0: \t"<<joystick->getPovValue(0) << endl;
    cout << "Value of pov 1: \t"<<joystick->getPovValue(1) << endl;
    cout << "PressedButton: \t"<<key1<< endl;
    cout << "PressedButton: \t"<<key2 << endl;

  };

  delete robot;
  return 0;
}