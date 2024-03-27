#include "main.h"
uint32_t lastFire = -800;
int autonNumber = 5; // When uploading make sure that slot number and auton number match!!!!
// old
	// 1 = Safe Winpoint
	// 2 = Winpoint
	// 3 = Eliminations
	// 4 = Troll Elim
	// 5 = Score 5
	// 6 = Score 6
	// 7 = Skills
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
	// switch (autonNumber)
	// {
	// case 1:
	// 	safeWinpoint();
	// 	break;
	// case 2:
	// 	winpoint();
	// 	break;
	// case 3:
	// 	destruction();
	// 	break;
	// case 4:
	// 	troll();
	// 	break;
	// case 5:
	// 	scorefive();
	// 	break;
	// case 6:
	// 	scoresix();
	// 	break;
	// case 7:
	// 	skills();
	// 	break;
	// case 0:
	// 	tests();
	// 	break;
	// }
	
	pros::lcd::print(1, "time: %f", (pros::millis() - (float)startTime) / 1000);
}

void opcontrol()
{
	pros::Controller master(pros::E_CONTROLLER_MASTER);
	uint32_t driveTime = pros::millis();
	
	while (true)
	{
		/*--chassis control--*/
		driveChassis();
		updateIntake();
		updatePneumatics();

		/*--info--*/
		pros::lcd::print(2, "Yaw: %f", getIMU());

		/*--TOGGLE--*/
		// toggle true = can fire
		// if (autonNumber != 5)
		// {
		// 	if (r2.changedToPressed())
		// 	{
		// 		cataToggle = !cataToggle;
		// 		if (cataToggle)
		// 		{
		// 			while (potentiometer.get() < 1780)
		// 			{
		// 				catapult.moveVoltage(12000);
		// 				pros::delay(20);
		// 			}
		// 			catapult.moveVoltage(0);
		// 			catapult.tarePosition();
		// 			stepC = 1;
		// 		}
		// 	}
		// 	if (cataToggle)
		// 	{
		// 		if (r1.isPressed() && pros::millis() - lastFire > 650)
		// 		{
		// 			lastFire = pros::millis();
		// 			catapult.moveAbsolute(180 * stepC, 12000);
		// 			stepC++; // no way c++??????
		// 		}
		// 	}
		// 	else
		// 	{
		// 		if (potentiometer.get() > 1300)
		// 		{
		// 			catapult.moveVoltage(12000);
		// 		}
		// 		else
		// 		{
		// 			catapult.moveVoltage(0);
		// 		}
		// 	}
		// }

		if ((((pros::millis() - (float)driveTime) / 1000) > 115 && ((pros::millis() - (float)driveTime) / 1000) < 116) || (((pros::millis() - (float)driveTime) / 1000) > 135 && ((pros::millis() - (float)driveTime) / 1000) < 136))
		{
			master.rumble(". ");
		}
		pros::delay(20);
	}
}