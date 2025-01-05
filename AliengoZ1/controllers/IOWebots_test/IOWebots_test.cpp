#include <iostream>
#include <webots/Robot.hpp>
#include <webots/PositionSensor.hpp>

using namespace webots;

struct MotorState
{
    unsigned int mode;
    float q;
    float dq;

    MotorState()
    {
        mode = 10;
        q = 0;
        dq = 0;
    }
};


struct LowlevelState
{
    MotorState motorState[12];
};

class IOWebots
{
public:
    IOWebots(webots::Robot* robot);
    ~IOWebots();
    void Recv(LowlevelState *state);
    webots::Robot *_robot;
    int _timeStep;
    
private:
    void initRecv();
    void recvState(LowlevelState *state);
    
    double _lastq[12];
    webots::PositionSensor *_jointSensorLeg[12];
    std::string _jointSensorLegName[12] = {"leg1_hip_joint_sensor", "leg1_thigh_joint_sensor", "leg1_calf_joint_sensor",
                                           "leg2_hip_joint_sensor", "leg2_thigh_joint_sensor", "leg2_calf_joint_sensor",
                                           "leg3_hip_joint_sensor", "leg3_thigh_joint_sensor", "leg3_calf_joint_sensor",
                                           "leg4_hip_joint_sensor", "leg4_thigh_joint_sensor", "leg4_calf_joint_sensor"};
};


IOWebots::IOWebots(webots::Robot* robot)
{
    _robot = robot;
    _timeStep = (int)_robot->getBasicTimeStep();
    std::cout << "timeStep in simulation is :" << _timeStep << std::endl;
    initRecv();
}

IOWebots::~IOWebots()
{
    delete _robot;
}

void IOWebots::Recv(LowlevelState *state)
{
    recvState(state);
}


void IOWebots::recvState(LowlevelState *state)
{
    for (int i = 0; i < 12; i++)
    {
        std::cout << _jointSensorLeg[i]->getValue() << std::endl;
        state->motorState[i].q = _jointSensorLeg[i]->getValue();
        std::cout << "test" << std::endl;
        state->motorState[i].dq = (state->motorState[i].q - _lastq[i]) / _timeStep / 1000;
        _lastq[i] = state->motorState[i].q;
    }
}

void IOWebots::initRecv()
{
    for (int i = 0; i < 12; i++)
    {
        _jointSensorLeg[i] = _robot->getPositionSensor(_jointSensorLegName[i]);
        _jointSensorLeg[i]->enable(_timeStep);
        // _lastq[i] = _jointSensorLeg[i]->getValue();
        _lastq[i] = 0.0;
    }
}



int main(int argc, char **argv) 
{
  webots::Robot *robot_node = new webots::Robot();
  IOWebots *ioWebots = new IOWebots(robot_node);
  LowlevelState *state = new LowlevelState();
  
  while (ioWebots->_robot->step(ioWebots->_timeStep) != -1) 
  {
    ioWebots->Recv(state);
  };



  delete robot_node;
  delete ioWebots;
  delete state;
  return 0;
}
