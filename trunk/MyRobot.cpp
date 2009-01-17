#include "WPILib.h"
#include "Math.h"
/*
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
	 * Converts a number between 0-255 to -1.0 to 1.0
	 * Useful for converting axis position of joysticks to
	 * speeds for speed controllers 
	 * If number not in range, returns 0.
	 * Input = Output: 127 = 0, 255 = 1.0, 0 = -0.9921
	 */
	float ConvertBitToPercent(float num) {
		num = floor(num);
		if( (num>255)||(num<0) ) {
			num -= 127;
			num /= 128;
		}
		else num = 0;
		return num;
	}

	/**
	 * Same as ConvertBitToPercent, but reversed
	 * Input = Output: 0 = 127, 1.0 = 254, -1.0 = 0
	 */
	float ConvertPercentToBit(float num) {
		num = floor(num);
		if( (num>1.0)||(num<-1.0) ) {
			num *= 127;
			num += 127;
		}
		else num = 0;
		return num;
	}
	
	/**
	 * Runs the motors with arcade steering.
	 * If button2[top button] on stick1,stick2 are pressed, the tread
	 * move at constant treadSpeed (originally = 0.5)
	 * If trigger of stick1 pressed, emergency stop 
	 */
	void OperatorControl(void)
	{
		//GetWatchdog().SetEnabled(true);
		while (IsOperatorControl())
		{
			//GetWatchdog().Feed();
			if(stick1.GetTrigger()) { //if pressed, emergency stop
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

