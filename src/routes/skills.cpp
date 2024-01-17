#include "main.h"

void skills() {

    motion_profile motionProfile;
    uint32_t lastPressed = -800;
    angleOffset = 50;
    toggleHang();
    while (potentiometer.get() > 1825)
    {
        catapult.moveVoltage(12000);
        pros::delay(10);
    }
    catapult.moveVoltage(0);
    catapult.tarePosition();
    int stepC = 1;
    toggleHang();

    /*--Setup--*/ // -20 firing angle

    motionProfile.moveDistance(-7, 50, 1, {0.05, 0, 0.01}, {65, 0.1, 0.3, 50});
    rotationTurn(-20, 9500, 1, 1000, {0.017, 0, 0.08});
    motionProfile.moveDistance(-3, -20, 1, {0.05, 0, 0.01}, {40, 0.1, 0.3, 20}, 500);
    toggleRightRearWing();

    /*--Firing--*/

    // while (stepC <= 47)
    // {
    //     catapult.moveAbsolute(180 * stepC, 12000);
    //     stepC++; // no way c++??????
    //     pros::delay(650);
    // }
    toggleRightRearWing();
    gyro.reset();
    pros::delay(2500);
    angleOffset = -20;

    /*--Cross sides--*/

    rotationTurn(48, 9500, 1, 1000, {0.017, 0, 0.08});
    motionProfile.moveDistance(14, 48, 1, {0.05, 0, 0.01}, {65, 0.1, 0.3, 50});
    rotationTurn(0, 9500, 1, 1000, {0.019, 0, 0.08});
    motionProfile.moveDistance(75 /*78 if side push*/, 0, 1, {0.05, 0, 0.01}, {60, 0.1, 0.3, 40});

    /*--Right push--*/
    
    // rotationTurn(152, 9500, 1, 800, {0.015, 0, 0.08});
    // motionProfile.moveDistance(-6, 152, 1, {0.05, 0, 0.01}, {65, 0.1, 0.3, 50}, 400);
    // rotationTurn(138, 9500, 1, 400, {0.019, 0, 0.08});
    // motionProfile.moveDistance(-12, 138, 1, {0.05, 0, 0.01}, {65, 0.1, 0.3, 50}, 500);
    // rotationTurn(90, 9500, 1, 400, {0.018, 0, 0.08});
    // motionProfile.moveDistance(2, 90, 1, {0.05, 0, 0.01}, {65, 0.1, 0.3, 50}, 500);
    // driveGroup.moveVoltage(-12000);
    // pros::delay(600);
    // driveGroup.moveVoltage(0);
    // motionProfile.moveDistance(9, 90, 1, {0.05, 0, 0.01}, {65, 0.1, 0.3, 50}, 500);
    // driveGroup.moveVoltage(-12000);
    // pros::delay(600);
    // driveGroup.moveVoltage(0);
    // motionProfile.moveDistance(8, 90, 1, {0.05, 0, 0.01}, {65, 0.1, 0.3, 50}, 400);
    // rotationTurn(0, 9500, 1, 1000, {0.016, 0, 0.08});
    // motionProfile.moveDistance(-12, 0, 1, {0.05, 0, 0.01}, {65, 0.1, 0.3, 50});

    /*--Right Diagonal--*/

    rotationTurn(-90, 9500, 1, 1000, {0.016, 0, 0.08});
    motionProfile.moveDistance(11 /*6 if theres a right side push*/, -90, 1, {0.05, 0, 0.01}, {65, 0.1, 0.3, 50});
    rotationTurn(-135, 9500, 1, 1000, {0.018, 0, 0.08});
    motionProfile.moveDistance(12, -135, 1, {0.05, 0, 0.01}, {65, 0.1, 0.3, 50});
    toggleLeftWing();
    pivotTurn(-18, 9500, 0.5, 750, true, {0.016, 0, 0.02});
    motionProfile.moveDistance(10, -18, 1, {0.05, 0, 0.01}, {65, 0.1, 0.3, 50});
    pivotTurn(-5, 9500, 0.5, 750, true, {0.016, 0, 0.02});
    driveGroup.moveVoltage(12000);
    pros::delay(650);
    driveGroup.moveVoltage(0);
    rotationTurn(0, 9500, 1, 500, {0.019, 0, 0.08});
    toggleLeftWing();
    motionProfile.moveDistance(-26, 0, 1, {0.05, 0, 0.01}, {65, 0.1, 0.3, 50});

    /*--Left/Middle Diagonal--*/

    rotationTurn(-90, 9500, 1, 500, {0.018, 0, 0.08});
    motionProfile.moveDistance(22, -90, 1, {0.05, 0, 0.01}, {65, 0.1, 0.3, 50});
    pivotTurn(23, 9500, 0.5, 750, true, {0.016, 0, 0.02});
    toggleRightWing();
    motionProfile.moveDistance(4, 23, 1, {0.05, 0, 0.01}, {65, 0.1, 0.3, 50});
    pivotTurn(48, 9500, 0.5, 750, true, {0.016, 0, 0.02});
    toggleLeftWing();
    motionProfile.moveDistance(8, 48, 1, {0.05, 0, 0.01}, {65, 0.1, 0.3, 50});
    pivotTurn(0, 9500, 0.5, 750, false, {0.016, 0, 0.02});
    driveGroup.moveVoltage(12000);
    pros::delay(400);
    driveGroup.moveVoltage(0);
    toggleLeftWing();
    toggleRightWing();
    rotationTurn(0, 9500, 1, 400, {0.019, 0, 0.08});
    motionProfile.moveDistance(-22, 0, 1, {0.05, 0, 0.01}, {65, 0.1, 0.3, 50});

    /*--Left Diagonal--*/

    rotationTurn(-90, 9500, 1, 500, {0.017, 0, 0.08});
    motionProfile.moveDistance(19, -90, 1, {0.05, 0, 0.01}, {65, 0.1, 0.3, 50});
    pivotTurn(23, 9500, 0.5, 750, true, {0.016, 0, 0.02});
    toggleRightWing();
    motionProfile.moveDistance(6, 23, 1, {0.05, 0, 0.01}, {65, 0.1, 0.3, 50});
    toggleLeftWing();
    pivotTurn(67, 9500, 0.5, 750, true, {0.016, 0, 0.02});
    motionProfile.moveDistance(18, 67, 1, {0.05, 0, 0.01}, {65, 0.1, 0.3, 50});
    pivotTurn(0, 9500, 0.5, 750, false, {0.016, 0, 0.02});
    driveGroup.moveVoltage(12000);
    pros::delay(400);
    driveGroup.moveVoltage(0);
    toggleLeftWing();
    toggleRightWing();
    motionProfile.moveDistance(-22, 0, 1, {0.05, 0, 0.01}, {65, 0.1, 0.3, 50});

    /*--Left push--*/

    rotationTurn(-45, 9500, 1, 500, {0.019, 0, 0.08});
    motionProfile.moveDistance(35.5, -45, 1, {0.05, 0, 0.01}, {65, 0.1, 0.3, 50});
    pivotTurn(-154, 9500, 0.5, 750, false, {0.016, 0, 0.02});
    motionProfile.moveDistance(-14, -154, 1, {0.05, 0, 0.01}, {65, 0.1, 0.3, 50});
    pivotTurn(-90, 9500, 0.5, 750, false, {0.016, 0, 0.02});
    motionProfile.moveDistance(-4, -90, 1, {0.05, 0, 0.01}, {65, 0.1, 0.3, 50});
    driveGroup.moveVoltage(-12000);
    pros::delay(600);
    driveGroup.moveVoltage(12000);
    pros::delay(400);
    driveGroup.moveVoltage(-12000);
    pros::delay(600);
}