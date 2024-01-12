#include "main.h"

void skills()
{

    motion_profile motionProfile;

    // not that normal setup we're gonna need a jig for that lmao
    // parallel to the matchload bar just like 12inches away
    // outtake while pushing front

    /*--Deploy intake--*/
    catapult.moveVoltage(12000);
    pros::delay(125);
    catapult.moveVoltage(0);

    // /*--Alliance Balls--*/
    // motionProfile.moveDistance(-21, 0, 1, {0.05, 0, 0.01}, {40, 0.01, 0.3, 3});
    // rotationTurn(45, 6000, 1, 1000, {0.02, 0, 0.08});
    // driveGroup.moveVoltage(-12000);
    // pros::delay(600);
    // driveGroup.moveVoltage(0);
    // motionProfile.moveDistance(8, 45, 1, {0.05, 0, 0.01}, {40, 0.01, 0.3, 3});

    // /*--Cata--*/
    // rotationTurn(135, 8000, 1, 1000, {0.02, 0, 0.08});
    // motionProfile.moveDistance(-12, 135, 1, {0.05, 0, 0.01}, {40, 0.01, 0.3, 3});
    // rotationTurn(103, 8000, 1, 1000, {0.02, 0, 0.08});
    // motionProfile.moveDistance(17, 103, 1, {0.05, 0, 0.01}, {30, 0.01, 0.3, 3}, 750);

    /*--Setup--*/
    motionProfile.moveDistance(16, 0, 1, {0.05, 0, 0.01}, {40, 0.01, 0.3, 40});
    rotationTurn(-40, 8000, 1, 1000, {0.02, 0, 0.08});
    toggleLeftWing();

    /*--Firing--*/
    pros::delay(500);
    // catapult.moveVoltage(12000);
    // pros::delay(43100); // We should create an auto setting function, do this later
    // catapult.moveVoltage(0);
    toggleLeftWing();
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