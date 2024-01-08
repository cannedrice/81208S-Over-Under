#include "subsystems/catapult.hpp"
// uint32_t lastPressed = -800;

void opCatapult()
{
	// if (r2.changedToPressed())
	// 	{
	// 		cataToggle = !cataToggle;
	// 	}
	// 	// Down Pos: 1180
	// 	// NOTICE: there is delay when it comes to updating values, so it is best if you make the potentiometer value around ~200ish lower than the value you want.
	// 	if (cataToggle)
	// 	{
	// 		catapult.moveVoltage(12000);
	// 	}
	// 	else
	// 	{
	// 		if (potentiometer.get() < 1180)
	// 		{
	// 			catapult.moveVoltage(12000);
	// 		}
	// 		else if (r1.changedToPressed())
	// 		{
	// 			lastPressed = pros::millis();
	// 			catapult.moveRelative(1000, 12000);
	// 		}
	// 		else if (pros::millis() - lastPressed > 350 && r1.isPressed())
	// 		{
	// 			catapult.moveVoltage(12000);
	// 		}
	// 		else
	// 		{
	// 			catapult.moveVoltage(0);
	// 		}
	// 	}
}