#include "subsystems/catapult.hpp"
uint32_t lastFire = -800;
int stepC = 1;
void opCatapult()
{
	/*--TOGGLE--*/
		// toggle true = can fire
		if (autonNumber != 5)
		{
			if (PTOState)
			{
				//move hang thing up and down
			}else{

				if (r1.isPressed() && pros::millis() - lastFire > 650)
				{
					lastFire = pros::millis();
					catapult.moveAbsolute(180 * stepC, 12000);
					stepC++; // no way c++??????
				}
			
			}

		}
}