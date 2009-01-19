#include "AxisCamera.h"
#include "BaeUtilities.h"
#include "FrcError.h"
#include "TrackAPI.h" 
#include "WPILib.h"
#include "math.h"

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
	Joystick stick2;// joystick 2 
	Joystick stick3; // joystick 3 (for belts)
	Jaguar belt3; // 3rd motor on pwm three (for arm)
	Jaguar belt4;// 4th motor on pwm four (for arm)
	//int framespersecond; // frames per second of the camera
	//int camerarotation; // how much the camera is roatated
	//Servo horizontalservo; // horizontal servo for rotating camera
public:
	RobotDemo(void):
		myRobot(1, 2),	// these must be initialized in the same order
		stick1(1),		// as they are declared above.
		stick2(2),// this initialized both joysticks
		stick3(3),
		belt3(3),
		belt4(4)	//initializing both motors for arm (pwm ports)
		//horizontalservo(5) // servo for spinning camera pwm port 5
		{
		GetWatchdog().SetExpiration(300);
	}

	/**
	 * Drive left & right motors for 3 seconds then stop
	 */
	void Autonomous(void)
	{
		GetWatchdog().SetEnabled(false);
		myRobot.Drive(0.0, 0.0); 	// drive forwards zero speed
		Wait(3.0); 				//    for 3 seconds
		myRobot.Drive(0.0, 0.0);	// stop robot
	}

	/**
	 * Runs the motors with arcade steering. 
	 */
	void OperatorControl(void)		//TESTING PURPOSES ONLY
	{
		float increment3= 0.00; // increment testing for belt3
		float increment4= 0.00;	// increment testing for belt4
		GetWatchdog().SetEnabled(true);
		while (IsOperatorControl())
		{
			GetWatchdog().Feed();
			belt3.Set(increment3); //set the speed to increment3 (which is zero right now)
			belt4.Set(increment4);	//set the speed to increment4 (which is zero right now)
			if(stick1.GetRawButton(2)) { //when you press button 2 on controller 1, increment belt3 down
				increment3= increment3 - 0.05;
				Wait(1.0);
			}
			if(stick2.GetRawButton(2))//when you press button 2 on controller 2, increment belt3 down
			{	increment4= increment4 - 0.05;
				Wait(1.0);
			
			}
			if(stick1.GetRawButton(3)) {//when you press button 2 on controller 1, increment belt3 up
				increment3= increment3 + 0.05;
				Wait(1.0);
			}
			if(stick2.GetRawButton(3)) {//when you press button 2 on controller 2, increment belt3 up
				increment4= increment4 + 0.05;
				Wait(1.0);
			}
				
		}
	}
};

START_ROBOT_CLASS(RobotDemo);

