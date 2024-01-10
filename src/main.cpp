/* ALL AUTON FILES ARE COMMENTED OUT DUE TO PNEUMATICS*/
/* PNEUMATICS FILES ARE COMMENTED OUT */
/* AUTON RUNNING IS COMMENTED OUT IN MAIN */
/* UPDATE PNEUMATICS IS COMMENTED OUT IN OPCONTROL */

#include "main.h"
uint32_t lastPressed = -800;
int autonNumber = 0;
// 0 = Winpoint
// 1 = Destruction
// 2 = Score 4
// 3 = Score 5
// 4 = Score 6
// 5 = Skills
// 6 = SoloWP
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
		pros::lcd::set_text(1, "Destruction");
		destruction();
		break;
	case 2:
		pros::lcd::set_text(1, "Score 4");
		scoring();
		break;
	case 3:
		pros::lcd::set_text(1, "Score 5");
		scorefive();
		break;
	case 4:
		pros::lcd::set_text(1, "Score 6");
		scoresix();
		break;
	case 5:
		pros::lcd::set_text(1, "SKILLS");
		skills();
		break;
	case 6:
		pros::lcd::set_text(1, "Solo WP");
		soloWP();
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
	// while (potentiometer.get() > 1810) {
	//  	catapult.moveVoltage(12000);
	// 	pros::delay(20);
	// }
	// catapult.moveVoltage(0);
	// END

	catapult.tarePosition();
	int stepC = 1;
	while (true)
	{
		// basic chassis control, do not touch.
		driveChassis();
		updateIntake();
		updatePneumatics();
		// opCatapult(); might add this one later, don't know if it works or not
		pros::lcd::print(2, "Catapult pos: %f", potentiometer.get());
		pros::lcd::print(3, "Yaw: %f", getIMU());
		pros::lcd::print(4, "Average drive train temp: %f", getDriveTemp());
		pros::lcd::print(5, "Cata shooter: %f", catapult.getTemperature());

		if (r1.isPressed()) {
			catapult.moveAbsolute(180 * stepC, 12000);
			stepC++; // no way c++??????
			pros::delay(650);
		}
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