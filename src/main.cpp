#include "main.h"

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
	autonNumber = 5;
	// 1 = Safe Winpoint
	// 2 = Winpoint
	// 3 = Eliminations
	// 4 = Troll Elim
	// 5 = Score 5
	// 6 = Score 6
	// 7 = Skills
	// 0 = Tests
	uint32_t startTime = pros::millis();
	motion_profile motionProfile;
	switch (autonNumber)
	{
	case 1:
		safeWinpoint();
		break;
	case 2:
		winpoint();
		break;
	case 3:
		destruction();
		break;
	case 4:
		troll();
		break;
	case 5:
		scorefive();
		break;
	case 6:
		scoresix();
		break;
	case 7:
		skills();
		break;
	case 0:
		tests();
		break;
	}
	pros::lcd::print(1, "time: %f", (pros::millis() - (float)startTime)/1000);
}

void opcontrol()
{
	pros::Controller master(pros::E_CONTROLLER_MASTER);
	uint32_t driveTime = pros::millis();
	if (autonNumber == 7)
	{
		driverSkills();
	}
	else
	{
		cataToggle = false;
	}
	int stepC = 1;

	while (true)
	{

		/*--chassis control--*/
		driveChassis();
		updateIntake();
		updatePneumatics();
		opCatapult();

		/*--info--*/
		pros::lcd::print(2, "Yaw: %f", getIMU());
		pros::lcd::print(3, "Average drive train temp: %f", getDriveTemp());
		pros::lcd::print(4, "Cata temp: %f", catapult.getTemperature());

		master.set_text(2, 0, std::to_string(stepC - 1));
		if ((pros::millis()-driveTime > 115000 && pros::millis()-driveTime < 116500) || (pros::millis()-driveTime > 135000 && pros::millis()-driveTime < 136500))
		{
			master.rumble(". ");
		}
		pros::delay(20);
	}
}