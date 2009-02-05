#ifndef ADD_H
#define ADD_H

#include "WPILib.h"

using namespace std;
class Belt : public SimpleRobot
{
  public:
	Belt();
    Belt(Joystick stick3, int motor1, int motor2);
    bool Stop();
    bool Go(float speedLeft);
  private:
	
};

#endif
