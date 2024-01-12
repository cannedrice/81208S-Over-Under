#include "subsystems/drive.hpp"

void moveLeftGroup(double power)
{
        driveLeftGroup.moveVoltage(power);
}

void moveRightGroup(double power)
{
        driveRightGroup.moveVoltage(power);
}

void driveChassis()
{
        double forward = controller.getAnalog(okapi::ControllerAnalog::leftY);
        double turn = controller.getAnalog(okapi::ControllerAnalog::rightX);

        /*
        forward gets value of vertical position of left joystick on controller, controls forward/backwards movement
        turn gets value of horizontal position of right joystick on controller, controls turning/left right movement
        */

        moveLeftGroup(std::clamp((forward + turn), -1.0, 1.0) * 12000);
        moveRightGroup(std::clamp((forward - turn), -1.0, 1.0) * 12000);

        /*
        uses values of joystick positions to calculate what way to move / how much to move each side
        clamp -> if the value is not in range -> "clamps it"
        max is 127, 128 -> 127
        min is -127 , -200 -> -127
        max 1, joystick results is 2, -> 1
        */
}
