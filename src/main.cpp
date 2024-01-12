/* ALL AUTON FILES ARE COMMENTED OUT DUE TO PNEUMATICS*/
/* PNEUMATICS FILES ARE COMMENTED OUT */
/* AUTON RUNNING IS COMMENTED OUT IN MAIN */
/* UPDATE PNEUMATICS IS COMMENTED OUT IN OPCONTROL */

#include "main.h"
uint32_t lastPressed = -800;
int autonNumber = 0;
// 0 = Winpoint
// 1 = SoloWP
// 2 = Score 5
// 3 = Score 6
// 4 = Skills
// 7 = Tests

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
	case 0:
		pros::lcd::set_text(1, "Winpoint");
		winpointAuton();
		break;
	case 1:
		pros::lcd::set_text(1, "Solo WP");
		soloWP();
		break;
	case 2:
		pros::lcd::set_text(1, "Score 5");
		scorefive();
		break;
	case 3:
		pros::lcd::set_text(1, "Score 6");
		scoresix();
		break;
	case 4:
		pros::lcd::set_text(1, "SKILLS");
		skills();
		break;
	case 7:
		pros::lcd::set_text(1, "Test");
		tests();
		break;
	}
}

void opcontrol()
{
	pros::Controller master(pros::E_CONTROLLER_MASTER);
	// COMMENT OUT ONCE AUTON IS CODED
	while (potentiometer.get() > 1825) {
	 	catapult.moveVoltage(12000);
		pros::delay(10);
	}
	catapult.moveVoltage(0);
	// END

	catapult.tarePosition();
	int stepC = 1;
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

		/*--current cata code--*/
		if (r1.isPressed() && pros::millis() - lastPressed > 650) {
			lastPressed=pros::millis();
			catapult.moveAbsolute(180 * stepC, 12000);
			stepC++; // no way c++??????
		}

		/*--experimental controller code--*/
		master.set_text(2, 0, std::to_string(stepC-1));
		master.set_text(2, 2, " ");
		master.set_text(2, 3, std::to_string(getDriveTemp()));
		master.set_text(2, 5, " ");
		master.set_text(2, 6, std::to_string(catapult.getTemperature()));
		

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