#include "main.h"

// movement profile = {0.05, 0, 0.01}
// rotation turn 8000, 0.5, 6000, {0.016, 0, 0.08} 90 deg
// 400 chassis has max speed of ~68.07 inches/sec, use 67 or 68 for max, use 60 reg

void tests()
{
    motion_profile motionProfile;
    // motionProfile.moveDistance(4, 0, 1, {0.0175, 0, 0.01}, {30, 0.01, 0.3, 30});
    // motionProfile.moveDistance(12, 0, 1, {0.0175, 0, 0.01}, {50, 0.01, 0.3, 5});
    // motionProfile.moveDistance(20, 0, 1, {0.0175, 0, 0.01}, {50, 0.1, 0.3, 5});
    // motionProfile.moveDistance(40, 0, 1, {0.0175, 0, 0.01}, {55, 0.1, 0.3, 5});
    // rotationTurn(45, 8000, 1, 1200, {0.019, 0, 0.08});
    // motionProfile.moveDistance(12, 45, 1, {0.0175, 0, 0.01}, {50, 0.01, 0.3, 5});
    // pros::delay(5000);
    // rotationTurn(90, 8000, 1, 1200, {0.015, 0, 0.08});
    // motionProfile.moveDistance(12, 90, 1, {0.0175, 0, 0.01}, {50, 0.01, 0.3, 5});
    // pros::delay(5000);
    // rotationTurn(135, 8000, 1, 1200, {0.015, 0, 0.08});
    // motionProfile.moveDistance(12, 135, 1, {0.0175, 0, 0.01}, {50, 0.01, 0.3, 5});
    // pros::delay(5000);
}

void scoring()
{
    motion_profile motionProfile;

    /*--Deploy intake--*/
    catapult.moveVoltage(12000);
    pros::delay(125);
    catapult.moveVoltage(0);

    /*--Alliance triball--*/
    pros::delay(210);
    intake.moveVoltage(12000);
    pros::delay(180);
    intake.moveVoltage(0);
    motionProfile.moveDistance(3, 0, 1, {0.02, 0, 0.04}, {25, 0.01, 0.3, 25}); // to not hit bar
    pros::delay(100);

    rotationTurn(75, 8000, 1, 1200, {0.016, 0, 0.08}); // get to goal:
    pros::delay(100);

    /*--4 Balls--*/
    motionProfile.moveDistance(18, 75, 1, {0.05, 0, 0.01}, {40, 0.1, 0.3, 3});
    /*--End--*/

    rotationTurn(45, 8000, 1, 800, {0.016, 0, 0.08}); // pushing triball:
    intake.moveVoltage(-12000);
    pros::delay(500);
    driveGroup.moveVoltage(12000);
    pros::delay(1000);
    driveGroup.moveVoltage(0);
    intake.moveVoltage(0);
    // pros::delay(500);
    motionProfile.moveDistance(-14.5, 45, 1, {0.05, 0, 0.01}, {40, 0.01, 0.3, 3});

    /*--Additional triballs--*/

    // pros::delay(500);
    rotationTurn(-22, 8000, 1, 1200, {0.016, 0, 0.08}); // get to first triball:
    // pros::delay(500);
    motionProfile.moveDistance(46, -22, 1, {0.05, 0, 0.01}, {40, 0.01, 0.3, 3});
    intake.moveVoltage(12000);
    pros::delay(230);
    intake.moveVoltage(0);
    motionProfile.moveDistance(-1, 95, 1, {0.02, 0, 0.04}, {25, 0.01, 0.3, 25}); // get triball to goal:
    rotationTurn(95, 8000, 1, 1200, {0.016, 0, 0.08});
    motionProfile.moveDistance(8, 95, 1, {0.02, 0, 0.04}, {25, 0.01, 0.3, 25});
    intake.moveVoltage(-12000);
    pros::delay(500);
    intake.moveVoltage(0);
    motionProfile.moveDistance(-5, 95, 1, {0.02, 0, 0.04}, {25, 0.01, 0.3, 25});
    rotationTurn(20, 8000, 1, 1200, {0.016, 0, 0.08}); // get second and third triball:
    pros::delay(250);
    intake.moveVoltage(12000);
    motionProfile.moveDistance(21.5, 20, 1, {0.05, 0, 0.01}, {40, 0.01, 0.3, 3});
    pros::delay(200);
    intake.moveVoltage(0);
    motionProfile.moveDistance(-7, 20, 1, {0.05, 0, 0.01}, {40, 0.01, 0.3, 3});
    // pros::delay(500);
    rotationTurn(81.5, 8000, 1, 1200, {0.016, 0, 0.08});
    toggleLeftWing(); // open wings
    toggleRightWing();
    motionProfile.moveDistance(12, 81.5, 1, {0.05, 0, 0.01}, {45, 0.01, 0.3, 3});
    rotationTurn(135, 8000, 1, 1200, {0.016, 0, 0.08}); // pushing triballs:
    intake.moveVoltage(-12000);
    pros::delay(75);
    driveGroup.moveVoltage(12000);
    pros::delay(850);
    driveGroup.moveVoltage(-12000);
    pros::delay(300);
    driveGroup.moveVoltage(0);
    intake.moveVoltage(0);
    toggleLeftWing();
    toggleRightWing();
}

void scorefive()
{
    motion_profile motionProfile;

    /*--Deploy intake--*/
    catapult.moveVoltage(12000);
    pros::delay(125);
    catapult.moveVoltage(0);

    /*--Alliance triball--*/
    // toggleMatchload(); FIX
    pros::delay(100);
    driveRightGroup.moveVoltage(-500);
    driveLeftGroup.moveVoltage(-6500);
    pros::delay(60);
    driveRightGroup.moveVoltage(0);
    pros::delay(250);
    driveLeftGroup.moveVoltage(0);
    rotationTurn(-63, 8000, 1, 1200, {0.016, 0, 0.08});
    motionProfile.moveDistance(-16, -63, 1, {0.02, 0, 0.04}, {30, 0.01, 0.3, 3});
    rotationTurn(-90, 8000, 1, 1200, {0.016, 0, 0.08});
    driveGroup.moveVoltage(-12000);
    pros::delay(1000);
    driveGroup.moveVoltage(0);
    motionProfile.moveDistance(9, -90, 1, {0.05, 0, 0.01}, {45, 0.01, 0.3, 3});

    /*--Additional triballs--*/

    // toggleMatchload(); FIX
    rotationTurn(-22 + 45, 8000, 1, 1200, {0.016, 0, 0.08}); // get to first triball:
    motionProfile.moveDistance(49.75, -22 + 45, 1, {0.05, 0, 0.01}, {60, 0.01, 0.3, 3});
    intake.moveVoltage(12000);
    pros::delay(230);
    intake.moveVoltage(0);
    motionProfile.moveDistance(-1, 95 + 45, 1, {0.02, 0, 0.04}, {25, 0.01, 0.3, 25}); // get triball to goal:
    rotationTurn(95 + 45, 8000, 1, 1200, {0.016, 0, 0.08});
    motionProfile.moveDistance(8, 95 + 45, 1, {0.02, 0, 0.04}, {25, 0.01, 0.3, 25});
    intake.moveVoltage(-12000);
    pros::delay(500);
    intake.moveVoltage(0);
    motionProfile.moveDistance(-5, 95 + 45, 1, {0.02, 0, 0.04}, {25, 0.01, 0.3, 25});
    rotationTurn(20 + 45, 8000, 1, 1200, {0.016, 0, 0.08}); // get second and third triball:
    pros::delay(250);
    intake.moveVoltage(12000);
    motionProfile.moveDistance(21.5, 20 + 45, 1, {0.05, 0, 0.01}, {40, 0.01, 0.3, 3});
    pros::delay(170);
    intake.moveVoltage(0);
    motionProfile.moveDistance(-7, 20 + 45, 1, {0.05, 0, 0.01}, {40, 0.01, 0.3, 3});
    // pros::delay(500);
    rotationTurn(81.5 + 45, 8000, 1, 1200, {0.016, 0, 0.08});
    toggleLeftWing(); // open wings
    toggleRightWing();
    motionProfile.moveDistance(12, 81.5 + 45, 1, {0.05, 0, 0.01}, {45, 0.01, 0.3, 3});
    rotationTurn(135 + 43, 8000, 1, 1200, {0.016, 0, 0.08}); // pushing triballs:
    intake.moveVoltage(-12000);
    pros::delay(75);
    driveGroup.moveVoltage(12000);
    pros::delay(850);
    driveGroup.moveVoltage(-12000);
    pros::delay(300);
    driveGroup.moveVoltage(0);
    intake.moveVoltage(0);
    toggleLeftWing();
    toggleRightWing();
}

void scoresix()
{
    motion_profile motionProfile;

    // SETUP WITH BACK POLYCARB BETWEEN TEETH ROW, FULLY PARALLEL (VERY IMPORTANT), RIGHT ROLLER BETWEEN 2ND INNER AND OUTER TEETH
    // MAKE SURE AIR IS VERY FULL, OR ELSE MATCHLOAD BALL WILL NOT COME OUT
    // PUT ALLIANCE TRIBALL TO THE LEFT OF THE RIGHTMOST SCREW OF THE POLYCARB (MAKE SURE IT DOESNT ROLL AWAY)


    rotationTurn(-8.5, 8000, 1, 400, {0.016, 0, 0.08});

    /*--Ball under bar--*/
    intake.moveVoltage(12000);
    motionProfile.moveDistance(10, -8.5, 1, {0.02, 0, 0.04}, {45, 0.01, 0.3, 3});
    pros::delay(190);
    intake.moveVoltage(0);
    // motionProfile.moveDistance(-14, -8.5, 1, {0.02, 0, 0.04}, {30, 0.01, 0.3, 3});
    motionProfile.moveDistance(-48/*-34*/, -8.5, 1, {0.02, 0, 0.04}, {65, 0.1, 1.5/*1*/, 3}); // buh
    /*--End--*/

    /*--Alliance triball--*/
    pros::delay(100);
    toggleRightRearWing();
    driveRightGroup.moveVoltage(-500);
    driveLeftGroup.moveVoltage(-6500);
    pros::delay(54);
    driveRightGroup.moveVoltage(0);
    pros::delay(225);
    driveLeftGroup.moveVoltage(0);
    rotationTurn(-63, 8000, 1, 1200, {0.016, 0, 0.08});
    motionProfile.moveDistance(-13, -63, 1, {0.02, 0, 0.04}, {55, 0.1, 0.3, 5});
    toggleRightRearWing();
    rotationTurn(-90, 8000, 1, 400, {0.016, 0, 0.08});
    driveGroup.moveVoltage(-12000);
    pros::delay(800);
    driveGroup.moveVoltage(0);
    motionProfile.moveDistance(10.5, -90, 1, {0.05, 0, 0.01}, {55, 0.1, 0.3, 5});

    /*--Additional triballs--*/

    rotationTurn(-22 + 45, 8000, 1, 1200, {0.016, 0, 0.08}); // get to first triball:
    motionProfile.moveDistance(36 /*47 -> 36 + 11*/, -22 + 45, 1, {0.05, 0, 0.01}, {65, 0.1, 0.3, 5});
    rotationTurn(144 /*35*/, 8000, 1, 1200, {0.016, 0, 0.08});
    intake.moveVoltage(-12000);
    pros::delay(250);
    intake.moveVoltage(0);
    rotationTurn(-22 + 45, 8000, 1, 1200, {0.016, 0, 0.08});
    motionProfile.moveDistance(11 /*35*/ /*47 -> 36 + 11*/, -22 + 45, 1, {0.05, 0, 0.01}, {55, 0.1, 0.3, 5});
    intake.moveVoltage(12000);
    pros::delay(110);
    intake.moveVoltage(0);
    motionProfile.moveDistance(-1, 95 + 45, 1, {0.017, 0, 0.04}, {30, 0.01, 0.3, 25}); // get triball to goal:
    rotationTurn(95 + 45-15, 8000, 1, 1200, {0.016, 0, 0.08});
    motionProfile.moveDistance(8, 95 + 45-15, 1, {0.02, 0, 0.04}, {45, 0.01, 0.3, 25});
    intake.moveVoltage(-12000);
    pros::delay(500);
    intake.moveVoltage(0);
    motionProfile.moveDistance(-5, 95 + 45-15, 1, {0.02, 0, 0.04}, {35, 0.01, 0.3, 25});// CHANGES HERE!
    rotationTurn(20 + 45, 8000, 1, 1200, {0.019, 0, 0.08}); // get second and third triball:
    pros::delay(250);
    intake.moveVoltage(12000);
    motionProfile.moveDistance(17.5, 20 + 45, 1, {0.05, 0, 0.01}, {62, 0.1, 0.3, 5});
    pros::delay(145);
    intake.moveVoltage(0);
    motionProfile.moveDistance(-7.5, 20 + 45, 1, {0.05, 0, 0.01}, {40, 0.01, 0.3, 5});
    // pros::delay(500);
    rotationTurn(81.5 + 45, 8000, 1, 1200, {0.016, 0, 0.08});
    // toggleLeftWing(); // open wings
    // toggleRightWing();
    motionProfile.moveDistance(9, 81.5 + 45, 1, {0.05, 0, 0.01}, {50, 0.1, 0.3, 5});
    rotationTurn(135 + 43, 8000, 1, 1200, {0.016, 0, 0.08}); // pushing triballs:
    intake.moveVoltage(-12000);
    pros::delay(120);
    driveGroup.moveVoltage(12000);
    pros::delay(750);
    driveGroup.moveVoltage(-12000);
    pros::delay(270);
    driveGroup.moveVoltage(0);
    intake.moveVoltage(0);
    // toggleLeftWing();
    // toggleRightWing();
}

void scoresixalt()
{
    motion_profile motionProfile;

    /*--Deploy intake--*/
    catapult.moveVoltage(12000);
    pros::delay(125);
    catapult.moveVoltage(0);

    /*--Alliance triball--*/
    // pros::delay(150); // testing
    intake.moveVoltage(12000);
    motionProfile.moveDistance(6, 0, 1, {0.02, 0, 0.04}, {40, 0.01, 0.3, 3});
    pros::delay(180);
    intake.moveVoltage(0);
    // toggleMatchload(); FIX
    motionProfile.moveDistance(-36, 0, 1, {0.02, 0, 0.04}, {40, 0.01, 0.3, 3});
    rotationTurn(-8 /*-10*/, 8000, 1, 1200, {0.016, 0, 0.08});
    motionProfile.moveDistance(-15, -10 /*20*/, 1, {0.02, 0, 0.04}, {40, 0.01, 0.3, 3});
    // matchload removal
    driveRightGroup.moveVoltage(-500);
    driveLeftGroup.moveVoltage(-6500);
    pros::delay(10);
    driveRightGroup.moveVoltage(0);
    pros::delay(250);
    driveLeftGroup.moveVoltage(0);
    // end
    rotationTurn(-63, 8000, 1, 1200, {0.016, 0, 0.08});
    motionProfile.moveDistance(-16, -63, 1, {0.02, 0, 0.04}, {40, 0.01, 0.3, 3});
    rotationTurn(-90, 8000, 1, 1200, {0.016, 0, 0.08});
    driveGroup.moveVoltage(-12000);
    pros::delay(1000);
    driveGroup.moveVoltage(0);
    motionProfile.moveDistance(9, -90, 1, {0.05, 0, 0.01}, {40, 0.01, 0.3, 3}); // push

    /*--Additional triballs--*/

    // toggleMatchload(); FIX
    rotationTurn(-22 + 45, 8000, 1, 1200, {0.016, 0, 0.08}); // get to first triball:
    motionProfile.moveDistance(37.75 /*49.75 -> 37.75 + 12*/, -22 + 45, 1, {0.05, 0, 0.01}, {40, 0.01, 0.3, 3});
    rotationTurn(150 /*35*/, 8000, 1, 1200, {0.016, 0, 0.08});
    intake.moveVoltage(-12000);
    pros::delay(250);
    intake.moveVoltage(0);
    rotationTurn(-22 + 45, 8000, 1, 1200, {0.016, 0, 0.08});
    motionProfile.moveDistance(12 /*35*/ /*49.75 -> 37.75 + 12*/, -22 + 45, 1, {0.05, 0, 0.01}, {40, 0.01, 0.3, 3});
    intake.moveVoltage(12000);
    pros::delay(230);
    intake.moveVoltage(0);
    motionProfile.moveDistance(-1, 95 + 45, 1, {0.02, 0, 0.04}, {25, 0.01, 0.3, 25}); // get triball to goal:
    rotationTurn(105 + 45 /*95*/, 8000, 1, 1200, {0.016, 0, 0.08});
    motionProfile.moveDistance(8, 105 + 45, 1, {0.02, 0, 0.04}, {25, 0.01, 0.3, 25});
    intake.moveVoltage(-12000);
    pros::delay(500);
    intake.moveVoltage(0);
    motionProfile.moveDistance(-5, 105 + 45, 1, {0.02, 0, 0.04}, {25, 0.01, 0.3, 25});
    rotationTurn(20 + 45, 8000, 1, 1200, {0.016, 0, 0.08}); // get second and third triball:
    pros::delay(250);
    intake.moveVoltage(12000);
    motionProfile.moveDistance(21.5, 20 + 45, 1, {0.05, 0, 0.01}, {40, 0.01, 0.3, 3});
    pros::delay(200);
    intake.moveVoltage(0);
    motionProfile.moveDistance(-7, 20 + 45, 1, {0.05, 0, 0.01}, {40, 0.01, 0.3, 3});
    // pros::delay(500);
    rotationTurn(81.5 + 45, 8000, 1, 1200, {0.016, 0, 0.08});
    toggleLeftWing(); // open wings
    toggleRightWing();
    motionProfile.moveDistance(12, 81.5 + 45, 1, {0.05, 0, 0.01}, {45, 0.01, 0.3, 3});
    rotationTurn(135 + 43, 8000, 1, 1200, {0.016, 0, 0.08}); // pushing triballs:
    intake.moveVoltage(-12000);
    pros::delay(75);
    driveGroup.moveVoltage(12000);
    pros::delay(850);
    driveGroup.moveVoltage(-12000);
    pros::delay(300);
    driveGroup.moveVoltage(0);
    intake.moveVoltage(0);
    toggleLeftWing();
    toggleRightWing();
}

// this path is illegal sometimes? also destruction auton works well enough to just not use this path

void soloWP()
{

    motion_profile motionProfile;

    /*--Deploy intake--*/
    catapult.moveVoltage(12000);
    intake.moveVoltage(12000);
    pros::delay(125);
    catapult.moveVoltage(0);
    pros::delay(212);
    intake.moveVoltage(0);

    // SETUP IS PARALLEL TO WALL, FACING OPPOSITE SIDE, ROLLER BETWEEN TEETH AND ON THE 2ND OUTER TILE TOOTH

    // toggleMatchload(); FIX
    pros::delay(150);
    driveLeftGroup.moveVoltage(-7500);
    driveRightGroup.moveVoltage(7500);
    pros::delay(400); // flying
    driveLeftGroup.moveVoltage(0);
    driveRightGroup.moveVoltage(0);
    // toggleMatchload(); FIX

    rotationTurn(136.5 - 90, 8000, 1, 1200, {0.016, 0, 0.08});
    motionProfile.moveDistance(8, 136.5 - 90, 1, {0.0175, 0, 0.01}, {40, 0.01, 0.3, 3});
    rotationTurn(90 - 90, 8000, 1, 1200, {0.016, 0, 0.08});
    pros::delay(75);
    motionProfile.moveDistance(80, 90 - 90, 1, {0.0175, 0, 0.01}, {55, 0.1, 0.3, 20});

    rotationTurn(-46, 8000, 1, 1200, {0.016, 0, 0.08}); // get to goal:
    pros::delay(50);

    motionProfile.moveDistance(30, -46, 1, {0.05, 0, 0.01}, {50, 0.1, 0.3, 3});

    intake.moveVoltage(-12000);
    rotationTurn(45 - 135, 8000, 1, 800, {0.016, 0, 0.08}); // pushing triball:
    motionProfile.moveDistance(-5, 45 - 135, 1, {0.05, 0, 0.01}, {40, 0.01, 0.3, 3});
    pros::delay(500);
    driveGroup.moveVoltage(12000);
    pros::delay(1000);
    driveGroup.moveVoltage(0);
    intake.moveVoltage(0);
    // pros::delay(500);
    motionProfile.moveDistance(-14.5, 45 - 135, 1, {0.05, 0, 0.01}, {40, 0.01, 0.3, 3});

    /*--Additional triballs--*/

    // pros::delay(500);
    rotationTurn(-22 - 135, 8000, 1, 1200, {0.016, 0, 0.08}); // get to first triball:
    // pros::delay(500);
    motionProfile.moveDistance(46, -22 - 135, 1, {0.05, 0, 0.01}, {55, 0.1, 0.3, 3});
    intake.moveVoltage(12000);
    pros::delay(212);
    intake.moveVoltage(0);
    motionProfile.moveDistance(-1, 88 - 135, 1, {0.02, 0, 0.04}, {25, 0.01, 0.3, 25}); // get triball to goal:
    rotationTurn(88 - 135, 8000, 1, 1200, {0.016, 0, 0.08});
    toggleLeftWing();
    motionProfile.moveDistance(23, 88 - 135, 1, {0.02, 0, 0.04}, {40, 0.01, 0.3, 25});
    rotationTurn(0, 6000, 1, 1200, {0.016, 0, 0.08});
    intake.moveVoltage(-12000);
    pros::delay(75);
    driveGroup.moveVoltage(12000);
    pros::delay(750);
    driveGroup.moveVoltage(0);
    intake.moveVoltage(0);
    toggleLeftWing();
    motionProfile.moveDistance(-18, 0, 1, {0.02, 0, 0.04}, {40, 0.01, 0.3, 25});

    /*--4 BALL--*/
    // intake.moveVoltage(-12000);
    // pros::delay(500);
    // intake.moveVoltage(0);
    // motionProfile.moveDistance(-5, 95-135, 1, {0.02, 0, 0.04}, {25, 0.01, 0.3, 25});
    // rotationTurn(20-135, 8000, 1, 1200, {0.016, 0, 0.08}); // get second and third triball:
    // pros::delay(250);
    // intake.moveVoltage(12000);
    // motionProfile.moveDistance(21.5, 20-135, 1, {0.05, 0, 0.01}, {40, 0.01, 0.3, 3});
    // pros::delay(200);
    // intake.moveVoltage(0);
    // motionProfile.moveDistance(-7, 20-135, 1, {0.05, 0, 0.01}, {40, 0.01, 0.3, 3});
    // // pros::delay(500);
    // rotationTurn(81.5-135, 8000, 1, 1200, {0.016, 0, 0.08});
    // toggleLeftWing(); // open wings
    // toggleRightWing();
    // motionProfile.moveDistance(12, 81.5-135, 1, {0.05, 0, 0.01}, {45, 0.01, 0.3, 3});
    // rotationTurn(135-135, 8000, 1, 1200, {0.016, 0, 0.08}); // pushing triballs:
    // intake.moveVoltage(-12000);
    // pros::delay(75);
    // driveGroup.moveVoltage(12000);
    // pros::delay(850);
    // driveGroup.moveVoltage(-12000);
    // pros::delay(300);
    // driveGroup.moveVoltage(0);
    // intake.moveVoltage(0);
    // toggleLeftWing();
    // toggleRightWing();
    /*--END--*/
}

void winpointAuton()
{
    // setup against wall and matchload bar
    motion_profile motionProfile;

    /*--Deploy intake--*/
    catapult.moveVoltage(12000);
    intake.moveVoltage(12000);
    pros::delay(125);
    catapult.moveVoltage(0);
    pros::delay(212);
    intake.moveVoltage(0);

    /*--Destroy--*/
    motionProfile.moveDistance(23, 0, 1, {0.0175, 0, 0.01}, {40, 0.01, 0.3, 3});
    rotationTurn(30, 8000, 1, 1200, {0.016, 0, 0.08});
    motionProfile.moveDistance(20, 30, 1, {0.0175, 0, 0.01}, {40, 0.01, 0.3, 3});
    rotationTurn(0, 8000, 1, 1200, {0.016, 0, 0.08});
    motionProfile.moveDistance(4, 0, 1, {0.0175, 0, 0.01}, {40, 0.01, 0.3, 3});
    toggleLeftWing();
    rotationTurn(90, 8000, 1, 1200, {0.016, 0, 0.08}); // test
    motionProfile.moveDistance(26, 90, 1, {0.0175, 0, 0.01}, {40, 0.01, 0.3, 3}, 1000);
    toggleLeftWing();
    motionProfile.moveDistance(-12, 90, 1, {0.0175, 0, 0.01}, {40, 0.01, 0.3, 3});
    rotationTurn(-90, 8000, 1, 1200, {0.016, 0, 0.08});
    motionProfile.moveDistance(7.5, -90, 1, {0.0175, 0, 0.01}, {40, 0.01, 0.3, 3}); // alliance triball pushin
    intake.moveVoltage(-12000);
    pros::delay(200);
    driveGroup.moveVoltage(12000);
    pros::delay(700);
    intake.moveVoltage(0);

    /*--Get to matchload area--*/
    motionProfile.moveDistance(-16, -90, 1, {0.0175, 0, 0.01}, {40, 0.01, 0.3, 3});
    rotationTurn(-150, 8000, 1, 1200, {0.016, 0, 0.08});
    motionProfile.moveDistance(46, -150, 1, {0.0175, 0, 0.01}, {40, 0.01, 0.3, 3}); // trying to get the triball out
    // somehow works:
    toggleRightRearWing();
    // toggleMatchload(); FIX
    pros::delay(150);
    driveLeftGroup.moveVoltage(-7500);
    driveRightGroup.moveVoltage(7500);
    pros::delay(725); // flying
    driveLeftGroup.moveVoltage(0);
    driveRightGroup.moveVoltage(0);
    ////toggleMatchload(); FIX FIX
    toggleRightRearWing();

    /*--Winpoint ending--*/
    rotationTurn(136.5, 8000, 1, 1200, {0.016, 0, 0.08});
    motionProfile.moveDistance(8, 136.5, 1, {0.0175, 0, 0.01}, {40, 0.01, 0.3, 3});
    rotationTurn(90, 8000, 1, 1200, {0.016, 0, 0.08});
    pros::delay(75);
    intake.moveVoltage(-12000);
    motionProfile.moveDistance(36.75, 90, 1, {0.0175, 0, 0.01}, {40, 0.01, 0.3, 20});
    driveGroup.moveVoltage(0);
    intake.moveVoltage(0);

    /*--Destroy ending--*/
    //     rotationTurn(30, 8000, 1, 1200, {0.016, 0, 0.08});
    //     motionProfile.moveDistance(10, 136.5, 1, {0.0175, 0, 0.01}, {30, 0.01, 0.3, 3});
    //     rotationTurn(110, 8000, 1, 1200, {0.016, 0, 0.08});
    //     motionProfile.moveDistance(6, 110, 1, {0.0175, 0, 0.01}, {30, 0.01, 0.3, 3});
}

void destruction()
{
    // setup against wall and matchload bar
    motion_profile motionProfile;

    /*--Deploy intake--*/
    catapult.moveVoltage(12000);
    intake.moveVoltage(12000);
    pros::delay(125);
    catapult.moveVoltage(0);
    pros::delay(212);
    intake.moveVoltage(0);

    /*--Destroy--*/
    motionProfile.moveDistance(24, 0, 1, {0.0175, 0, 0.01}, {40, 0.01, 0.3, 3});
    rotationTurn(30, 8000, 1, 1200, {0.016, 0, 0.08});
    motionProfile.moveDistance(20, 30, 1, {0.0175, 0, 0.01}, {40, 0.01, 0.3, 3});
    rotationTurn(0, 8000, 1, 1200, {0.016, 0, 0.08});
    motionProfile.moveDistance(4, 0, 1, {0.0175, 0, 0.01}, {40, 0.01, 0.3, 3});
    toggleLeftWing();
    rotationTurn(90, 8000, 1, 1200, {0.016, 0, 0.08}); // test
    motionProfile.moveDistance(26, 90, 1, {0.0175, 0, 0.01}, {40, 0.01, 0.3, 3}, 1000);
    toggleLeftWing();
    motionProfile.moveDistance(-12, 90, 1, {0.0175, 0, 0.01}, {40, 0.01, 0.3, 3});
    rotationTurn(-90, 8000, 1, 1200, {0.016, 0, 0.08});
    motionProfile.moveDistance(7.5, -90, 1, {0.0175, 0, 0.01}, {40, 0.01, 0.3, 3}); // alliance triball pushin
    intake.moveVoltage(-12000);
    pros::delay(200);
    driveGroup.moveVoltage(12000);
    pros::delay(700);
    intake.moveVoltage(0);

    /*--Get to matchload area--*/
    motionProfile.moveDistance(-16, -90, 1, {0.0175, 0, 0.01}, {40, 0.01, 0.3, 3});
    rotationTurn(-150, 8000, 1, 1200, {0.016, 0, 0.08});
    motionProfile.moveDistance(44.5, -150, 1, {0.0175, 0, 0.01}, {40, 0.01, 0.3, 3}); // trying to get the triball out
    // somehow works:
    ////toggleMatchload(); FIX FIX
    pros::delay(150);
    driveLeftGroup.moveVoltage(-7500);
    driveRightGroup.moveVoltage(7500);
    pros::delay(725); // flying
    driveLeftGroup.moveVoltage(0);
    driveRightGroup.moveVoltage(0);
    ////toggleMatchload(); FIX FIX

    /*--Destroy ending--*/
    rotationTurn(30, 8000, 1, 1200, {0.016, 0, 0.08});
    motionProfile.moveDistance(10, 136.5, 1, {0.0175, 0, 0.01}, {30, 0.01, 0.3, 3});
    rotationTurn(110, 8000, 1, 1200, {0.016, 0, 0.08});
    motionProfile.moveDistance(6, 110, 1, {0.0175, 0, 0.01}, {30, 0.01, 0.3, 3});
}