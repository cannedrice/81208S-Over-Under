#include "main.h"
uint32_t lastFire = -800;
int autonNumber = 1;
	// 1 = Qual closeside
	// 2 = Qual closeside 2
	// 3 = Qual farside
	// 4 = Elim closeside
	// 5 = Elim closeside 2
	// 6 = Elim farside
	// 7 = Skills
	// 0 = Tests

void initialize()
{
	pros::lcd::initialize();
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