#include "main.h"
uint32_t lastFire = -800;
int autonNumber = 1; 
// right now naming is kinda convoluted ill figure out how to make it more descriptive without making it too long xd
	// 1 = Qual closeside safe (Q_CS Safe)
	// 2 = Qual closeside disrupt (Q_CS Disrupt)
	// 3 = Qual farside 6 ball (Q_FS 6)
	// 4 = Elim closeside disrupt (E_CS Disrupt)
	// 5 = Elim closeside disrupt troll (E_CS Troll)
	// 6 = Elim farside 6 mid rush (E_FS Rush)
	// 7 = Skills (Skills lmao)
	// 0 = Tests

void initialize()
{
	pros::lcd::initialize();
	//makes sure that the hang mech stays down at the start
	hangState = true;
	leftHang.set_value(true);
	rightHang.set_value(true);
	gyro.reset();
	driveGroup.setBrakeMode(okapi::AbstractMotor::brakeMode::brake);
}

void disabled() {}

void competition_initialize() {}

void autonomous()
{
	uint32_t startTime = pros::millis();
	motion_profile motionProfile;
	switch (autonNumber)
	{
	case 1:
		qualCloseside();
		break;
	case 2:
		qualCloseside2();
		break;
	case 3:
		qualFarside();
		break;
	case 4:
		elimCloseside();
		break;
	case 5:
		elimCloseside2();
		break;
	case 6:
		//center rush 6 ball
		break;
	case 7:
		skills();
		break;
	case 0:
		tests();
		break;
	}
	pros::lcd::print(1, "time: %f", (pros::millis() - (float)startTime) / 1000);
}

void opcontrol()
{
	pros::Controller master(pros::E_CONTROLLER_MASTER);
	uint32_t driveTime = pros::millis();
	//peter remember to remove this when ur done tuning LOL
	pros::delay(2000);
	motion_profile motionProfile;
	pivotTurn(180, 9500, 0.5, 3000, true, piv);  
	pros::delay(200);
	
	while (true)
	{
		/*--chassis control--*/
		driveChassis();
		updateIntake();
		updatePneumatics();

		/*--info--*/
		pros::lcd::print(2, "Yaw: %f", getIMU());
		pros::lcd::print(3, "Drive train temp: %f", getDriveTemp());
		// put more info here, tbd
		if ((pros::millis() > 115000 && pros::millis() < 116500) || (pros::millis() > 135000 && pros::millis() < 136500)) // reminder for 30 seconds and 10 second
		{
			master.rumble(". ");
		}

		/*--future cata code here--*/

		pros::delay(20);
	}
}