#include "WPILib.h"

/**
 * This is a demo program showing the use of the RobotBase class.
 * The SimpleRobot class is the base of a robot application that will automatically call your
 * Autonomous and OperatorControl methods at the right time as controlled by the switches on
 * the driver station or the field controls.
 */ 
class RobotDemo : public SimpleRobot
{ 
	RobotDrive myRobot; // robot drive system
	Joystick stick1; //  joystick 1
	Joystick stick2; // joystick 2 (two total joysticks)
	//Servo servo1; //controls spike (not speed controller) at PWM port 3 
	
public:
	RobotDemo(void):
		myRobot(1, 2, .25),	// these must be initialized in the same order
							// values 1,2 declare ports for motor, 3rd value controls sensitivity (default = .5)
		stick1(1),		// as they are declared above.
		stick2(2)
		
		//servo1(3)
		{
		GetWatchdog().SetExpiration(300);
	}

	/**
	 * Drive left & right motors for 2 seconds then stop
	 */
	void Autonomous(void)
	{
		GetWatchdog().SetEnabled(false);
		//servo1.SetAngle(180);
		myRobot.Drive(0.5, 0.0); 	// drive forwards half speed
		Wait(2.0); 				//    for 2 seconds
		myRobot.Drive(0.0, 0.0);	// stop robot
	}

	/**
	 * Runs the motors with arcade steering. 
	 */
	void OperatorControl(void)
	{
		int controlMode = 0;
		GetWatchdog().SetEnabled(true);
		while (IsOperatorControl())
		{
			GetWatchdog().Feed();
			if(stick1.GetTrigger()) {
				myRobot.Drive(0.0, 0.0);
			}
			if(stick2.GetTrigger())
				controlMode = 1;

			if(stick2.GetTop())
				controlMode = 0;
			
			if(controlMode == 1) 
				myRobot.ArcadeDrive(stick2);
			else
				myRobot.TankDrive(stick1, stick2); // drive with arcade style (use right stick)
		}
	}
};

START_ROBOT_CLASS(RobotDemo);

