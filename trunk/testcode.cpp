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
	RobotDrive belts; // belts drive system
public:
	RobotDemo(void):
		
		myRobot(1, 2),	// these must be initialized in the same order
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
		myRobot.TankDrive(1.0,1.0);
		belts.TankDrive(1.0,1.0);
	}
};

START_ROBOT_CLASS(RobotDemo);

