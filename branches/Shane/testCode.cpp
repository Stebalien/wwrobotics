#include <iostream>
#include "WPILib.h"
Robotdrive drive(1, 2);
Joystick stick(1);

class Robotdemo : public SimpleRobot
{
	RobotDemo (void)
	{
		GetWatchdog().SetEnabled(false);
	}
	Void Autonomous (void)
	{
		for (int i = 0; i<4; i++)
		drivetrain.Drive(.5, 0.0);
		wait(2000);
		drivetrain.Drive(0.0, 0.75);
		wait(750);
	}
	Void OperatorControl (void)
	{
		while (1)
		{
			drivetrain.Tank(&stick1, &stick2);
		}
	}
};
START_ROBOT_CLASS (RobotDemo);

