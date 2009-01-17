#include "WPILib.h"

/**
 * This is a demo program showing the use of the RobotBase class.
 * The SimpleRobot class is the base of a robot application that will automatically call your
 * Autonomous and OperatorControl methods at the right time as controlled by the switches on
 * the driver station or the field controls.
 */ 
class RobotDemo : public SimpleRobot
{
	const static float treadSpeed = 0.5; // controls speed of treads
	RobotDrive myRobot; // robot drive system
	Joystick stick1; //  joystick 1
	Joystick stick2; // joystick 2 (two total joysticks)
	Jaguar treadsController1; // Jaguar speed controller for treads motor 1
	Jaguar treadsController2; // Jaguar speed controller for treads motor
public:
	RobotDemo(void):
		myRobot(1, 2),	// these must be initialized in the same order
		stick1(1),		// as they are declared above.
		stick2(2),
		treadsController1(3), // controllers in PWM ports 3 and 4
		treadsController2(4)
		{
		GetWatchdog().SetExpiration(300);
		GetWatchdog().SetEnabled(false); //disable watchdog for testing reasons
		}

	/**
	 * Drive left & right motors for 2 seconds then stop
	 */
	void Autonomous(void)
	{
		GetWatchdog().SetEnabled(false);
		myRobot.Drive(0.5, 0.0); 	// drive forwards half speed
		Wait(2.0); 				//    for 2 seconds
		myRobot.Drive(-0.5, 0.0);	// reverse robot
	}

	/**
	 * Runs the motors with tank steering. 
	 */
	void OperatorControl(void)
	{
		//GetWatchdog().SetEnabled(true);
		while (IsOperatorControl())
		{
			//GetWatchdog().Feed();
			if(stick1.GetTrigger()) {
				myRobot.Drive(0.0, 0.0);
			}
			else {
				myRobot.ArcadeDrive(stick1); // drive with arcade style (use right stick)
				if(stick2.GetTop()) {
					treadsController1.Set(treadSpeed);
					treadsController2.Set(treadSpeed);
				}
				else if(stick1.GetTop()) {
					treadsController1.Set(-treadSpeed);
					treadsController2.Set(-treadSpeed);
				}
			}
		}
	}
};

START_ROBOT_CLASS(RobotDemo);

