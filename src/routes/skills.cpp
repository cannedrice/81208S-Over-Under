#include "main.h"

void skills()
{

    motion_profile motionProfile;
    uint32_t lastPressed = -800;
    /*--Deploy intake--*/
    //tbf

    /*--Setup + firing--*/
    while (potentiometer.get() > 1825)
    {
        catapult.moveVoltage(12000);
        pros::delay(10);
    }
    catapult.moveVoltage(0);
    catapult.tarePosition();
    int stepC = 1;
    //put setup shit here
    while (stepC <= 45)
    {
        catapult.moveAbsolute(180 * stepC, 12000);
        stepC++; // no way c++??????
        pros::delay(650);
    }
    gyro.reset();
    pros::delay(2500);

    /*--Get alliance triball and get to other side--*/
    motionProfile.moveDistance(-7.8, -8, 1, {0.05, 0, 0.01}, {20, 0.01, 0.3, 3});
    rotationTurn(68, 8000, 1, 1000, {0.02, 0, 0.08});
    motionProfile.moveDistance(-26.5, 68, 1, {0.05, 0, 0.01}, {40, 0.01, 0.3, 3});
    rotationTurn(24, 8000, 1, 1000, {0.02, 0, 0.08});
    motionProfile.moveDistance(-77, 24, 1, {0.05, 0, 0.01}, {40, 0.1, 0.3, 3});

    /*-- 2 front pushes --*/

    // /*--Get to center--*/
    // rotationTurn(-21, 8000, 1, 1000, {0.02, 0, 0.08});
    // motionProfile.moveDistance(-10, -21, 1, {0.05, 0, 0.01}, {40, 0.01, 0.3, 3});
    // rotationTurn(69, 8000, 1, 1000, {0.02, 0, 0.08});
    // motionProfile.moveDistance(23, 69, 1, {0.05, 0, 0.01}, {40, 0.01, 0.3, 3});
    // toggleLeftWing();
    // driveRightGroup.moveVoltage(4500);
    // driveLeftGroup.moveVoltage(7000);
    // pros::delay(1000); // 850
    // driveGroup.moveVoltage(0);

    // /*--Front push x2--*/
    // toggleRightWing();
    // moveLeftGroup(12000); // section is where it should help the robot rotate correctly lol
    // moveRightGroup(-12000);
    // pros::delay(400);
    // driveGroup.moveVoltage(0);
    // rotationTurn(-176 /*-175.5*/, 6000, 1, 1000, {0.02, 0, 0.08});

    // pros::delay(150);
    // driveGroup.moveVoltage(10000);
    // pros::delay(1200);
    // driveGroup.moveVoltage(0);
    // toggleLeftWing();
    // toggleRightWing();
    // motionProfile.moveDistance(-29, -158, 1, {0.05, 0, 0.01}, {40, 0.01, 0.3, 3}); // eh we can work on this shit later
    // toggleLeftWing();
    // toggleRightWing();
    // driveGroup.moveVoltage(12000);
    // pros::delay(1400);
    // driveGroup.moveVoltage(0);
    // toggleLeftWing();
    // toggleRightWing();

    /*-- End --*/

    /*-- 2 Diagonal pushes --*/

    /*--Get to center--*/
    rotationTurn(-21, 8000, 1, 1000, {0.02, 0, 0.08});
    motionProfile.moveDistance(-10, -21, 1, {0.05, 0, 0.01}, {40, 0.01, 0.3, 3});
    rotationTurn(69, 8000, 1, 1000, {0.02, 0, 0.08});
    motionProfile.moveDistance(23, 69, 1, {0.05, 0, 0.01}, {40, 0.01, 0.3, 3});
    toggleLeftWing();
    driveRightGroup.moveVoltage(5500);
    driveLeftGroup.moveVoltage(7500);
    pros::delay(825); // 850
    driveGroup.moveVoltage(0);

    /*--Front push x2--*/
    toggleRightWing();
    driveGroup.moveVoltage(0);
    rotationTurn(170 /*-175.5*/, 6000, 1, 1000, {0.02, 0, 0.08});
    pros::delay(150);
    driveGroup.moveVoltage(12000);
    pros::delay(1200);
    driveGroup.moveVoltage(0);
    toggleLeftWing();
    toggleRightWing();
    driveLeftGroup.moveVoltage(-10000);
    driveRightGroup.moveVoltage(-12000);
    pros::delay(850);
    driveGroup.moveVoltage(0);
    rotationTurn(-158, 6000, 1, 1000, {0.02, 0, 0.08});
    toggleRightWing();
    driveLeftGroup.moveVoltage(10800);
    driveRightGroup.moveVoltage(8000);
    pros::delay(400);
    toggleLeftWing();
    pros::delay(660);
    driveGroup.moveVoltage(12000);
    pros::delay(250);
    driveGroup.moveVoltage(0);
    toggleLeftWing();
    toggleRightWing();
}