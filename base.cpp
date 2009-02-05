#include "AxisCamera.h"
#include "BaeUtilities.h"
#include "FrcError.h"
#include "TrackAPI.h" 
#include "WPILib.h"
#include "math.h"
#include "base.h"

using namespace std;
Base::Base()
{
	//AutoJunk Here
}

Base::Base(Joystick stick1, Joystick stick2, int motor1, int motor2)
{
	RobotDrive base(motor1,motor2);
	// Set drive control interger
	//	1 - Arcade control
	//	2 - Tank control
	int flagSetDrive = 1;
	GetWatchdog().SetEnabled(true);
	while (IsOperatorControl()) {
		GetWatchdog().Feed();
		switch(flagSetDrive) {
		case 1:
			base.ArcadeDrive(stick2);
			break;
		case 2:
			base.TankDrive(stick1,stick2);
			break;
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
