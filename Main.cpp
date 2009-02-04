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
	Joystick stick3; //joystick 3
	RobotDrive belts; // belts drive system
	//int framespersecond; // frames per second of the camera
	//int camerarotation; // how much the camera is roatated
	//Servo horizontalservo; // horizontal servo for rotating camera
public:
	RobotDemo(void):
		myRobot(1, 2),	// these must be initialized in the same order
		stick1(1),		// as they are declared above. 
		stick2(2),// this initialized both joysticks
		stick3(3), //joysticks 1,2,3 in usb ports 1,2,3 (respective)
		belts(3,4) //pwm ports 3/4 for belt motors
		//horizontalservo(5) // servo for spinning camera pwm port 5
		{
			GetWatchdog().SetExpiration(100);
	}

	/* ***
	 * !TODO!Code description needed here
	*/
	void Autonomous(void)
	{
		//GetWatchdog().SetEnabled(false); //only disable watchdog for DEBUGGING
		while (IsAutonomous()){
			GetWatchdog().Feed();
			
			/*
			if(stick3.GetRawButton(11)){
				belts.Drive(0.5,0.0);
			}
			if(stick3.GetRawButton(10)){
				belts.Drive(0.25,0.0);
			}
			if(stick3.GetRawButton(6)){
				belts.Drive(-0.25,0.0);
			}
			if(stick3.GetRawButton(7)){
				belts.Drive(-.5,0.0);
			}
			if(stick3.GetRawButton(8)){
				belts.Drive(0.0,0.0);
			}
			if(stick3.GetRawButton(9)){
				belts.Drive(0.0,0.0);
			}
			*/ //no use for this (no user input on autonomous section anyway)
		}
	}

	/**
	 * !TODO!:Code description needed here.
	 */
	void OperatorControl(void)		//TESTING PURPOSES ONLY
	{	
		// Set belt control integer
		//	1 - Arcade belt control
		//	2 - Button belt control
		int flagSetBelt = 1;
		// Set drive control interger
		//	1 - Arcade control
		//	2 - Tank control
		int flagSetDrive = 1;
		GetWatchdog().SetEnabled(true);
		while (IsOperatorControl()) {
			GetWatchdog().Feed();

			switch(flagSetDrive) {
			case 1:
				myRobot.ArcadeDrive(stick2);
				break;
			case 2:
				myRobot.TankDrive(stick1,stick2);
				break;
			}
			
			switch(flagSetBelt) {
			case 1:
				// Control with stick
				belts.ArcadeDrive(stick3);
				break;
			
			case 2:
			// Control with buttons
				if(stick3.GetRawButton(11)){
					belts.Drive(0.5,0.0);
					}
				if(stick3.GetRawButton(10)){
					belts.Drive(0.25,0.0);
					}
				if(stick3.GetRawButton(6)){
					belts.Drive(-0.25,0.0);
					}
				if(stick3.GetRawButton(7)){
					belts.Drive(-.5,0.0);
					}
				if(stick3.GetRawButton(8)){
					belts.Drive(0.0,0.0);
					}
				if(stick3.GetRawButton(9)){
					belts.Drive(1.0,0.0);
					}
				break;
			}
			/****** Belt Stuff ******/
			
			//
			// Get whether to control the belt with the buttons or stick
			//
			
			// Stick
			if(stick3.GetRawButton(3)){
				flagSetBelt = 1;
			}
			
			// Buttons
			else if(stick3.GetRawButton(2)){
				flagSetBelt = 2;
			}
			
			/****** Base Stuff ******/
			
			// press, do not have to hold down 5 to use tank drive
			if(stick1.GetRawButton(5)) { 
				flagSetDrive = 1;
			}
			//press, do not have to hold down 4 to use tank drive
			if(stick1.GetRawButton(4)) {
				flagSetDrive = 2;
			}
			// Trigger stuff
			/*if(stick1.GetRawButton(1)) { //when you press trigger on controller 1 robot (should) stop
				myRobot.TankDrive(0.0,0.0);
			}
			if(stick2.GetRawButton(1)) { //when you press trigger on controller 2 robot (should) stop
				myRobot.TankDrive(0.0,0.0);
			}*/
			if(stick1.GetRawButton(5)){ // press, do not have to hold down 5 to use tank drive
				flagSetDrive = 1;
			}
			if(stick1.GetRawButton(4)) //press, do not have to hold down 4 to use tank drive
				flagSetDrive = 2;
		}
	}
};

START_ROBOT_CLASS(RobotDemo);

