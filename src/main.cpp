#include "main.h"
uint32_t lastPressed = -800;
int autonNumber = 4;
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

	pros::lcd::print(2, "Catapult pos: %f", potentiometer.get());
	pros::lcd::print(3, "Yaw: %f", getIMU());
	pros::lcd::register_btn1_cb(on_center_button);
	driveGroup.setBrakeMode(okapi::AbstractMotor::brakeMode::brake);

	/* new auton selector hope it works */
	// bool exit = true;
	// while (exit)
	// {
	// 	if (XButton.changedToPressed())
	// 	{
	// 		autonNumber++;
	// 		autonNumber = (autonNumber + 4) % 4; // remember to change this when adding new paths
	// 	}
	// 	else if (BButton.changedToPressed())
	// 	{
	// 		autonNumber--;
	// 		autonNumber = (autonNumber + 4) % 4; // remember to change this when adding new paths
	// 	}
	// 	if (BButton.isPressed() || XButton.isPressed())
	// 	{
	// 		switch (autonNumber)
	// 		{
	// 		case 0:
	// 			controller.rumble(".");
	// 			pros::lcd::print(1, "Auton: Winpoint (depreciated)", autonNumber);
	// 			break;
	// 		case 1:
	// 			controller.rumble("-");
	// 			pros::lcd::print(1, "Auton: Scoring ", autonNumber);
	// 			break;
	// 		case 2:
	// 			pros::lcd::print(1, "Auton: Destruction Winpoint", autonNumber);
	// 			controller.rumble("- .");
	// 			break;
	// 		case 3:
	// 			pros::lcd::print(1, "Auton: Skills", autonNumber);
	// 			controller.rumble("- -");
	// 			break;
	// 		default:									// this should never run
	// 			controller.rumble(". . . - - - . . ."); // haha sos bro the controllers battery is gonna be nonexistant after this one. well it shouldnt happen anyways
	// 			break;
	// 		}
	// 	}
	// 	if (YButton.changedToPressed())
	// 	{
	// 		exit = false;
	// 	}
	// 	pros::delay(20);
	// }
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
	// okapi::ControllerButton fire(okapi::ControllerDigital::R1);
	// okapi::ControllerButton cToggle(okapi::ControllerDigital::up); experimental, possible doesn't work
	while (true)
	{
		// basic chassis control, do not touch.
		driveChassis();
		updateIntake();
		updatePneumatics();
		// cata

		//yo! engineering explination here!
		//first have a way to toggle the catapult, in the case that something gets jammed
		//l2
		//For the main catapult code, we first check if the catapult is toggled or not.
		//if it is toggled, don't move the catapult
		//if it isn't, automatically set the catapult to a downwards position
		//next, check whether if the user pressed l1. If it is, then just simply run the catapult motor
		//also check whether if the user pressed the catapult in the last .3 seconds
		// as to give the catapult time to resettle before firing


		if (r2.changedToPressed())
		{
			cataToggle = !cataToggle;
		}
		// Down Pos: 1180
		// NOTICE: there is delay when it comes to updating values, so it is best if you make the potentiometer value around ~200ish lower than the value you want.
		if (cataToggle)
		{
			catapult.moveVoltage(12000);
		}
		else
		{
			if (potentiometer.get() < 1180)
			{
				catapult.moveVoltage(12000);
			}
			else if (r1.changedToPressed())
			{
				lastPressed = pros::millis();
				catapult.moveRelative(1000, 12000);
			}
			else if (pros::millis() - lastPressed > 350 && r1.isPressed())
			{
				catapult.moveVoltage(12000);
			}
			else
			{
				catapult.moveVoltage(0);
			}
		}
		pros::delay(20);
	}
}
