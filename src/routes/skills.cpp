#include "main.h"

void skills() {

    motion_profile motionProfile;
    angleOffset = 50;
    toggleHang();
    while (potentiometer.get() < 1780)
    {
        catapult.moveVoltage(12000);
        pros::delay(10);
    }
    catapult.moveVoltage(0);
    catapult.tarePosition();
    int stepC = 1;
    pros::delay(150);
    toggleHang();

    /*--Setup--*/ // -20 firing angle

    motionProfile.moveDistance(-7, 50, 1, {0.05, 0, 0.01}, {65, 0.1, 0.3, 50});
    rotationTurn(-21.5, 9500, 1, 1000, {0.017, 0, 0.08});
    motionProfile.moveDistance(-3, -21.5, 1, {0.05, 0, 0.01}, {40, 0.1, 0.3, 20}, 500);
    toggleRightRearWing();

    /*--Firing--*/

    while (stepC <= 48)
    {
        catapult.moveAbsolute(180 * stepC, 12000);
        stepC++; // no way c++??????
        pros::delay(550);
    }
    toggleRightRearWing();
    gyro.reset();
    pros::delay(2000);
    angleOffset = -21.5;

    /*--Cross sides--*/

    rotationTurn(48, 9500, 1, 1000, {0.017, 0, 0.08});
    motionProfile.moveDistance(15, 48, 1, {0.05, 0, 0.01}, {65, 0.1, 0.3, 50});
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
    rotationTurn(-141, 9500, 1, 1000, {0.018, 0, 0.08});
    motionProfile.moveDistance(16, -141, 1, {0.05, 0, 0.01}, {65, 0.1, 0.3, 50}, 800);
    // toggleLeftWing();
    toggleRightWing();
    pivotTurn(-14, 9500, 0.5, 750, true, {0.016, 0, 0.02});
    intake.moveVoltage(-12000);
    motionProfile.moveDistance(8, -14, 1, {0.05, 0, 0.01}, {65, 0.1, 0.3, 50}, 300); //300
    pivotTurn(-5, 9500, 0.5, 750, true, {0.016, 0, 0.02});
    driveGroup.moveVoltage(12000);
    pros::delay(650);
    driveGroup.moveVoltage(0);
    rotationTurn(0, 9500, 1, 500, {0.019, 0, 0.08});
    // toggleLeftWing();
    toggleRightWing();
    intake.moveVoltage(0);
    motionProfile.moveDistance(-25.5, 0, 1, {0.05, 0, 0.01}, {65, 0.1, 0.3, 50}, 1200);

    /*--Left/Middle Diagonal--*/

    rotationTurn(-90, 9500, 1, 500, {0.018, 0, 0.08});
    motionProfile.moveDistance(8, -90, 1, {0.05, 0, 0.01}, {65, 0.1, 0.3, 50}, 1000);
    toggleRightWing();
    pivotTurn(-16, 9500, 0.5, 750, true, {0.016, 0, 0.02});
    toggleLeftWing();
    motionProfile.moveDistance(3, -16, 1, {0.05, 0, 0.01}, {65, 0.1, 0.3, 50}, 300); //300
    pivotTurn(0, 9500, 0.5, 750, true, {0.016, 0, 0.02});
    motionProfile.moveDistance(5, 0, 1, {0.05, 0, 0.01}, {65, 0.1, 0.3, 50}, 300); //300
    pivotTurn(15, 9500, 0.5, 500, true, {0.016, 0, 0.02});
    intake.moveVoltage(-12000);
    motionProfile.moveDistance(12, 15, 1, {0.05, 0, 0.01}, {50, 0.1, 0.3, 40}, 500); //500
    pivotTurn(0, 9500, 0.5, 500, false, {0.016, 0, 0.02});
    driveGroup.moveVoltage(12000);
    pros::delay(400);
    driveGroup.moveVoltage(-12000);
    pros::delay(300);
    driveGroup.moveVoltage(0);
    pros::delay(200);
    driveGroup.moveVoltage(12000);
    pros::delay(400);
    driveGroup.moveVoltage(0);
    toggleLeftWing();
    toggleRightWing();
    rotationTurn(0, 9500, 1, 400, {0.019, 0, 0.08});
    intake.moveVoltage(0);
    motionProfile.moveDistance(-22, 0, 1, {0.05, 0, 0.01}, {65, 0.1, 0.3, 50}, 1200);

    /*--Left Diagonal--*/

    rotationTurn(-90, 9500, 1, 500, {0.017, 0, 0.08});
    intake.moveVoltage(12000);
    motionProfile.moveDistance(24, -90, 1, {0.05, 0, 0.01}, {65, 0.1, 0.3, 50}, 1200);
    pivotTurn(23, 8000, 0.5, 750, true, {0.016, 0, 0.02});
    toggleRightWing();
    motionProfile.moveDistance(6, 23, 1, {0.05, 0, 0.01}, {50, 0.1, 0.3, 40}, 600);
    toggleLeftWing();
    pivotTurn(71, 9500, 0.5, 750, true, {0.016, 0, 0.02});
    motionProfile.moveDistance(24, 71, 1, {0.05, 0, 0.01}, {65, 0.1, 0.3, 50}, 1500);
    pivotTurn(0, 9500, 0.5, 750, false, {0.016, 0, 0.02});
    intake.moveVoltage(-12000);
    pros::delay(200);
    driveGroup.moveVoltage(12000);
    pros::delay(400);
    driveGroup.moveVoltage(0);
    toggleLeftWing();
    toggleRightWing();
    intake.moveVoltage(0);
    motionProfile.moveDistance(-23, 0, 1, {0.05, 0, 0.01}, {65, 0.1, 0.3, 50}, 1200);

    /*--Left push--*/

    rotationTurn(-58, 9500, 1, 500, {0.019, 0, 0.08});
    intake.moveVoltage(-12000);
    motionProfile.moveDistance(42, -58, 1, {0.05, 0, 0.01}, {65, 0.1, 0.3, 50}, 3500);
    pros::delay(200);
    intake.moveVoltage(0);
    // pivotTurn(-122, 9500, 0.5, 1000, false, {0.016, 0, 0.02});
    // motionProfile.moveDistance(7, -122, 1, {0.05, 0, 0.01}, {65, 0.1, 0.3, 50}, 1000);
    pivotTurn(-158, 9500, 0.5, 750, false, {0.016, 0, 0.02});
    motionProfile.moveDistance(-18, -158, 1, {0.05, 0, 0.01}, {65, 0.1, 0.3, 50}, 1500);
    pivotTurn(-90, 9500, 0.5, 1100, false, {0.016, 0, 0.02});
    motionProfile.moveDistance(-4, -90, 1, {0.05, 0, 0.01}, {65, 0.1, 0.3, 50}, 700);
    driveGroup.moveVoltage(-12000);
    pros::delay(600);
    driveGroup.moveVoltage(9000);
    pros::delay(450);
    driveGroup.moveVoltage(-12000);
    pros::delay(600);
    driveGroup.moveVoltage(0);
}

void driverSkills() {
    motion_profile motionProfile;
    angleOffset = 50;
    toggleHang();
    while (potentiometer.get() < 1780)
    {
        catapult.moveVoltage(12000);
        pros::delay(10);
    }
    catapult.moveVoltage(0);
    catapult.tarePosition();
    int stepC = 1;
    pros::delay(150);
    toggleHang();

    /*--Setup--*/ // -20 firing angle

    motionProfile.moveDistance(-7, 50, 1, {0.05, 0, 0.01}, {65, 0.1, 0.3, 50});
    rotationTurn(-20, 9500, 1, 1000, {0.017, 0, 0.08});
    motionProfile.moveDistance(-3, -20, 1, {0.05, 0, 0.01}, {40, 0.1, 0.3, 20}, 500);
    toggleRightRearWing();

    /*--Firing--*/

    while (stepC <= 47)
    {
        catapult.moveAbsolute(180 * stepC, 12000);
        stepC++; // no way c++??????
        pros::delay(550);
    }
    toggleRightRearWing();
}