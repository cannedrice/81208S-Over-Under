#include "main.h"
int autonNumber = 1;
// 1 = Winpoint
// 2 = Winpoint destruction
// 3 = Score 5
// 4 = Score 5 corner
// 5 = Score 6
// 0 = Tests

void on_center_button() {}

void initialize()
{
	pros::lcd::initialize();
	gyro.reset();

	pros::lcd::register_btn1_cb(on_center_button);
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
		winpointAuton();
		break;
	case 2:
		destruction();
		break;
	case 3:
		scorefive();
		break;
	case 4:
		scorefiveCorner();
		break;
	case 5:
		scoresix();
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

	while (true)
	{
		/*--chassis control--*/
		driveChassis();
		updateIntake();
		updatePneumatics();
		updateHang();

		/*--info--*/
		pros::lcd::print(2, "Yaw: %f", getIMU());
		pros::lcd::print(3, "Average drive train temp: %f", getDriveTemp());
		// put more info here, tbd
		if ((pros::millis() > 115000 && pros::millis() < 116500) || (pros::millis() > 135000 && pros::millis() < 136500))
		{
			master.rumble(". ");
		}
		pros::delay(20);
	}
}