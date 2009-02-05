#include "AxisCamera.h"
#include "BaeUtilities.h"
#include "FrcError.h"
#include "TrackAPI.h" 
#include "WPILib.h"
#include "math.h"
#include "belt.h"

using namespace std;
Belt::Belt()
{
	//AutoStuff Here
}
Belt::Belt(Joystick stick3, int motor1, int motor2)
{
	RobotDrive belts(motor1,motor2);
	GetWatchdog().SetEnabled(true);
	// Set belt control integer
	//	1 - Arcade belt control
	//	2 - Button belt control
	int flagSetBelt = 1;
	GetWatchdog().SetEnabled(true);
	while (IsOperatorControl()) {
		GetWatchdog().Feed();
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
	}
}
