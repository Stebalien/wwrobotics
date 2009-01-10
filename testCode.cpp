#include <iostream>
#include "WPILib.h"
Robotdrive drive(1, 2);
Joystick stick(1);

class Robotdemo : public SimpleRobot
{
	RobotDemo (void)
	{
		GetWatchdog().SetEnabled(false); // disables watchdog
	}
	Void Autonomous (void)
	{
		for (int i = 0; i<4; i++)
		drivetrain.Drive(.5, 0.0); // after Driver the .5 means 50% speed and the 0.0 is a 0% turn
		wait(2000); // measured in miliseconds, so 2 second wait
		drivetrain.Drive(0.0, 0.75); // 0%  power/speed and 75% turn
		wait(750);
		drivetrain.Drive(0.0, 0.0); // stops movement (I don't know if this is needed but it was in the guide with essentially this comment)
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







