#include "AxisCamera.h"
#include "BaeUtilities.h"
#include "FrcError.h"
#include "TrackAPI.h" 
#include "WPILib.h"
#include "math.h"
#include "base.h"
#include "belt.h"

/**
 * This is a demo program showing the use of the RobotBase class.
 * The SimpleRobot class is the base of a robot application that will automatically call your
 * Autonomous and OperatorControl methods at the right time as controlled by the switches on
 * the driver station or the field controls.
 */ 

class Robot : public SimpleRobot
{
	Joystick stick1; //  joystick 1
	Joystick stick2;// joystick 2 
	Joystick stick3; //joystick 3
	RobotDrive belts; // belts drive system
	//int framespersecond; // frames per second of the camera
	//int camerarotation; // how much the camera is roatated
	//Servo horizontalservo; // horizontal servo for rotating camera
public:
	Robot(void):
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
		}
	}

	/**
	 * !TODO!:Code description needed here.
	 */
	void OperatorControl(void)		//TESTING PURPOSES ONLY
	{
		//Do nothing
	}
};

START_ROBOT_CLASS(Robot);

