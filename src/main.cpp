#include "main.h"
uint32_t lastFire = -800;
int autonNumber = 3;
// 1 = Winpoint
// 2 = SoloWP
// 3 = Wp auton safe
// 4 = Score 5
// 5 = Skills
// 6 = Score 5 corner
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
	motion_profile motionProfile;
	switch (autonNumber)
	{
	case 1:
		winpointAuton();
		break;
	case 2:
		soloWP();
		break;
	case 3:
		wpAutonsafe();
		break;
	case 4:
		scorefive();
		break;
	case 5:
		skills();
		break;
	case 6:
		scorefiveCorner();
		break;
	case 0:
		tests();
		break;
	}
}

void opcontrol()
{
	pros::Controller master(pros::E_CONTROLLER_MASTER);
	/*--NOT TOGGLE--*/
	// while (potentiometer.get() > 1825) {
	//  	catapult.moveVoltage(12000);
	// 	pros::delay(10);
	// }
	// catapult.moveVoltage(0);
	// catapult.tarePosition();
	/*----*/

	/*--TOGGLE--*/
	cataToggle = true;
	/*----*/

		/*--SKILLS SETUP + CATA, COMMENT OTHERWISE--*/
	if (autonNumber == 5)
	{
		driverSkills();
	}
	else
	{
		cataToggle = false;
	}
	int stepC = 1;
	/*--SKILLS SETUP + CATA, COMMENT OTHERWISE--*/

	while (true)
	{
		/*--chassis control--*/

		driveChassis();
		updateIntake();
		updatePneumatics();

		/*--info--*/
		pros::lcd::print(2, "Yaw: %f", getIMU());
		pros::lcd::print(3, "Average drive train temp: %f", getDriveTemp());
		pros::lcd::print(4, "Cata temp: %f", catapult.getTemperature());

		/*--TOGGLE--*/
		// toggle true = can fire
		if (autonNumber != 5)
		{
			if (r2.changedToPressed())
			{
				cataToggle = !cataToggle;
				if (cataToggle)
				{
					while (potentiometer.get() < 1780)
					{
						catapult.moveVoltage(12000);
						pros::delay(20);
					}
					catapult.moveVoltage(0);
					catapult.tarePosition();
					stepC = 1;
				}
			}
			if (cataToggle)
			{
				if (r1.isPressed() && pros::millis() - lastFire > 650)
				{
					lastFire = pros::millis();
					catapult.moveAbsolute(180 * stepC, 12000);
					stepC++; // no way c++??????
				}
			}
			else
			{
				if (potentiometer.get() > 1300)
				{
					catapult.moveVoltage(12000);
				}
				else
				{
					catapult.moveVoltage(0);
				}
			}
		}

		/*----*/

		/*--NO TOGGLE--*/
		// if (r1.isPressed() && pros::millis() - lastFire > 650) {
		// 	lastFire=pros::millis();
		// 	catapult.moveAbsolute(180 * stepC, 12000);
		// 	stepC++; // no way c++??????
		// }
		/*----*/

		/*--experimental controller code--*/
		master.set_text(2, 0, std::to_string(stepC - 1));

		/*--old cata code v2--*/
		// if (r1.isPressed()) {
		// 	catapult.moveAbsolute(180 * stepC, 12000);
		// 	stepC++; // no way c++??????
		// 	driveGroup.moveVoltage(0);
		// 	pros::delay(650);
		// }

		/*--old cata code--*/
		// if (r2.changedToPressed())
		// {
		// 	cataToggle = !cataToggle;
		// }
		// // Down Pos: 2490 -> 1680
		// if (cataToggle) {
		// 	catapult.moveVoltage(9000);
		// } else {
		// 	if (potentiometer.get() > 1950) { // CHANGE THIS POSITION
		// 		catapult.moveVoltage(12000);/*8500*/
		// 	} else {
		// 		if (r1.isPressed()) {
		// 			catapult.moveVoltage(1000);
		// 			pros::delay(150);
		// 			catapult.moveVoltage(12000);
		// 			pros::delay(200);
		// 		} else {
		// 			catapult.moveVoltage(0);
		// 		}
		// 	}
		// }
		pros::delay(20);
	}
}