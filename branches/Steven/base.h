#ifndef ADD_H
#define ADD_H

#include "WPILib.h"

using namespace std;
class Base : public SimpleRobot
{
  public:
	Base();
    Base(Joystick stick1, Joystick stick2, int motor1, int motor2);
    bool Stop();
    bool Go(float speedLeft, float speedRight);
  private:
	
};

#endif
