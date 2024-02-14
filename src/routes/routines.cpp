#include "main.h"

double distancePIDValues[3] = {0, 0, 0};
double rotationPIDValues[3] = {0, 0, 0};
double pivotPIDValues[3] = {0, 0, 0};

void tests()
{
    // toggleHang();
    // pros::delay(500);
    // intake.moveVoltage(12000);
    // pros::delay(500);
    // intake.moveVoltage(0);
    motion_profile motionProfile;
    angleOffset = -35;
    // toggleHang();
    openRightWing();

    pros::delay(350);
    // toggleHang();
    closeRightWing();
    intake.moveVoltage(12000);
    motionProfile.moveDistance(60, -35, 2, {distancePIDValues[3]}, {65, 0.1, 0.3, 55}, 1500); //temp time out, will decrease

    // pros::delay(500);

    rotationTurn(90, 9500, 0.5, 750, {rotationPIDValues[3]}); //face net

    openLeftWing();
    openRightWing();

    intake.moveVoltage(-12000);
    pros::delay(100);

    motionProfile.moveDistance(16, 90, 2, {distancePIDValues[3]}, {70, 0.1, 0.3, 60}, 1500);
    intake.moveVoltage(0);
    motionProfile.moveDistance(16, 90, 2, {distancePIDValues[3]}, {60, 0.1, 0.3, 60}, 1500); //rams
    driveGroup.moveVoltage(-12000);
    pros::delay(250);
    driveGroup.moveVoltage(0);

    closeLeftWing();
    closeRightWing();

    //this has to be right to the ball
    pivotTurn(0, 9500, 0.5, 750, true, {pivotPIDValues[3]}); //INCREASE //delay was 1000 WEIRD PAUSE

    motionProfile.moveDistance(-12, 0, 2,{distancePIDValues[3]}, {60, 0.1, 0.3, 50}, 750);//-13

    rotationTurn(-85, 9500, 0.5, 500, {rotationPIDValues[3]}); //turn to ball //INCREASE

    intake.moveVoltage(12000);

    //reset pos???? maybe better to not touch the bar
    motionProfile.moveDistance(22, -85, 2, {distancePIDValues[3]}, {50, 0.1, 0.3, 40}, 1500);

    motionProfile.moveDistance(-15, -85, 2, {distancePIDValues[3]}, {50, 0.1, 0.3, 50}, 1500);

    //might have to purely stop with timeout or use drivegroup
    pivotTurn(-15, 9500, 0.5, 650, false, {pivotPIDValues[3]}); //test this one now, see if anything changes

    motionProfile.moveDistance(-29, -15, 2, {distancePIDValues[3]}, {60, 0.1, 0.3, 40}, 1500);//INCREASE //WATCH FOR THIS!

    //face side of net
    rotationTurn(33, 9500, 0.5, 500, {rotationPIDValues[3]}); //INCREASE

    intake.moveVoltage(-12000);
    pros::delay(350);
    intake.moveVoltage(0);
    rotationTurn(-87, 9500, 0.5, 750, {rotationPIDValues[3]}); //INCREASE

    intake.moveVoltage(12000);

    //MAKE SURE THIS DOESN'T CROSS
    motionProfile.moveDistance(32, -87, 2,{distancePIDValues[3]}, {60, 0.1, 0.3, 40}, 2000);

    motionProfile.moveDistance(-29, -87, 2,{distancePIDValues[3]}, {60, 0.1, 0.3, 40}, 2000);
    intake.moveVoltage(0);

    //foward ram-------
    rotationTurn(45, 9500, 0.5, 750, {rotationPIDValues[3]});//INCREASE

    // toggleRightRearWing();
    // pros::delay(100);

    motionProfile.moveDistance(13, 45, 2, {distancePIDValues[3]}, {50, 0.1, 0.3, 40}, 500);

    //get ball out of corner
    rotationTurn(-45, 12000, 0.5, 800,{rotationPIDValues[3]});



    // toggleRightRearWing();
    // pros::delay(150);

    rotationTurn(30, 9500, 0.5, 800, {rotationPIDValues[3]}); //face net //INCREASE
    intake.moveVoltage(-12000);

    // pros::delay(100);

    //rams, also adjust these angles so that they are straighter and will have no difficulty pushing it in.
    motionProfile.moveDistance(22, 30, 2, {distancePIDValues[3]}, {70, 0.1, 0.3, 70}, 650);

    pivotTurn(0, 9500, 0.5, 650, true, {pivotPIDValues[3]});
    motionProfile.moveDistance(-10.5, 15, 2, {distancePIDValues[3]}, {60, 0.1, 0.3, 60}, 1500);

    // motionProfile.moveDistance(16, 18, 2, {distancePIDValues[3]}, {70, 0.1, 0.3, 70}, 1500);

    driveGroup.moveVoltage(12000);
    pros::delay(500);
    driveGroup.moveVoltage(0);

    motionProfile.moveDistance(-9, 0, 2, {distancePIDValues[3]}, {60, 0.1, 0.3, 60}, 1500);//move back so not touching

}

void scorefiveCorner()
{
    motion_profile motionProfile;
    /*--Deploy--*/
    // toggleHang();
    pros::delay(500);
    // intake.moveVoltage(12000);
    pros::delay(100);
    // intake.moveVoltage(0);
    // toggleHang();

    /*--Side triball--*/
    rotationTurn(-40, 8000, 1, 500, {rotationPIDValues[3]});
    toggleLeftRearWing();
    motionProfile.moveDistance(-8, -40, 1, {distancePIDValues[3]}, {60, 0.05, 0.2, 10}, 500);
    rotationTurn(-90, 8000, 1, 600, {rotationPIDValues[3]});
    toggleLeftRearWing();
    rotationTurn(-40, 8000, 1, 500, {rotationPIDValues[3]});
    motionProfile.moveDistance(-9, -40, 1, {distancePIDValues[3]}, {50, 0.05, 0.02, 40}, 500);
    rotationTurn(-90, 8000, 1, 500, {0.018, 0, 0.08});
    driveGroup.moveVoltage(-12000);
    pros::delay(600);
    driveGroup.moveVoltage(0);

    /*--Preload--*/
    motionProfile.moveDistance(11, -90, 1, {distancePIDValues[3]}, {60, 0.05, 0.2, 10}, 1000);
    rotationTurn(20.5, 9500, 1, 500, {0.013, 0, 0.06});
    motionProfile.moveDistance(49, 20.5, 1, {0.04, 0, 0.02}, {65, 0.1, 0.5, 10}, 2000);
    intake.moveVoltage(12000);
    pros::delay(130);
    intake.moveVoltage(0);
    motionProfile.moveDistance(-1, 165, 1, {0.017, 0, 0.04}, {60, 0.01, 0.5, 40});
    rotationTurn(160, 8000, 1, 500, {rotationPIDValues[3]});
    motionProfile.moveDistance(8, 160, 1, {0.02, 0, 0.04}, {60, 0.01, 0.2, 25}, 1000);
    intake.moveVoltage(-12000);
    pros::delay(220);
    intake.moveVoltage(0);
    // motionProfile.moveDistance(-5, 162, 1, {0.02, 0, 0.04}, {60, 0.01, 0.2, 25}, 1000);

    /*--Experimental 2nd & 3rd triball*/
    // rotationTurn(20.5, 8000, 1, 500, {rotationPIDValues[3]});
    // motionProfile.moveDistance(15, 20.5, 1, {distancePIDValues[3]}, {65, 0.1, 0.5, 10}, 1000);
    // intake.moveVoltage(12000);
    // pros::delay(110);
    // intake.moveVoltage(0);
    // motionProfile.moveDistance(-1, 165, 1, {0.017, 0, 0.04}, {60, 0.01, 0.5, 40});
    // rotationTurn(160, 8000, 1, 500, {rotationPIDValues[3]});
    // motionProfile.moveDistance(8, 160, 1, {0.02, 0, 0.04}, {60, 0.01, 0.2, 25}, 1000);
    // intake.moveVoltage(-12000);
    // pros::delay(220);
    // intake.moveVoltage(0);
    // rotationTurn(60, 8000, 1, 500, {rotationPIDValues[3]});
    // intake.moveVoltage(12000);
    // motionProfile.moveDistance(24, 60, 1, {distancePIDValues[3]}, {62, 0.1, 0.2, 10}, 1000);
    // pros::delay(175);
    // intake.moveVoltage(0);
    // motionProfile.moveDistance(-8.5, 60, 1, {distancePIDValues[3]}, {60, 0.01, 0.2, 10}, 1000);
    // rotationTurn(126.5, 8000, 1, 500, {rotationPIDValues[3]});
    // toggleLeftWing();
    // toggleRightWing();
    // motionProfile.moveDistance(9, 126.5, 1, {distancePIDValues[3]}, {60, 0.1, 0.2, 10}, 1000);

    /*--2nd & 3rd triball--*/
    rotationTurn(55, 9500, 1, 500, {rotationPIDValues[3]});
    intake.moveVoltage(12000);
    motionProfile.moveDistance(27.5, 55, 1, {distancePIDValues[3]}, {62, 0.1, 0.2, 10}, 1000);
    pros::delay(200);
    motionProfile.moveDistance(-8.5, 68.5, 1, {distancePIDValues[3]}, {60, 0.01, 0.2, 10}, 1000);
    rotationTurn(126.5, 8000, 1, 500, {rotationPIDValues[3]});
    intake.moveVoltage(0);
    toggleLeftWing();
    toggleRightWing();
    motionProfile.moveDistance(9, 126.5, 1, {distancePIDValues[3]}, {60, 0.1, 0.2, 10}, 1000);

    /*--Lining up for push--*/
    rotationTurn(178, 8000, 1, 500, {rotationPIDValues[3]});
    intake.moveVoltage(-12000);
    driveGroup.moveVoltage(12000);
    pros::delay(750);
    driveGroup.moveVoltage(-12000);
    pros::delay(270);
    driveGroup.moveVoltage(0);
    intake.moveVoltage(0);
    toggleLeftWing();
    toggleRightWing();
}

void scorefive()
{
    motion_profile motionProfile;
    angleOffset = -35;
    // toggleHang();
    // openRightWing();

    pros::delay(350);
    // toggleHang();
    // closeRightWing();
    intake.moveVoltage(12000);
    motionProfile.moveDistance(63.5, -35, 2, {distancePIDValues[3]}, {65, 0.1, 0.3, 55}, 1500); //temp time out, will decrease

    pros::delay(120);

    rotationTurn(90, 9500, 0.5, 750, {rotationPIDValues[3]}); //face net

    openLeftWing();
    openRightWing();

    intake.moveVoltage(-12000);
    pros::delay(100);

    motionProfile.moveDistance(16, 90, 2, {distancePIDValues[3]}, {70, 0.1, 0.3, 60}, 1500);
    intake.moveVoltage(0);
    motionProfile.moveDistance(16, 90, 2, {distancePIDValues[3]}, {60, 0.1, 0.3, 60}, 1500); //rams
    driveGroup.moveVoltage(-12000);
    pros::delay(250);
    driveGroup.moveVoltage(0);

    closeLeftWing();
    closeRightWing();

    //this has to be right to the ball
    pivotTurn(0, 9500, 0.5, 750, true, {pivotPIDValues[3]}); //INCREASE //delay was 1000 WEIRD PAUSE
    motionProfile.moveDistance(-12, 0, 2,{distancePIDValues[3]}, {60, 0.1, 0.3, 50}, 750);//-13
    rotationTurn(-86, 9500, 0.5, 500, {rotationPIDValues[3]}); //turn to ball //INCREASE

    intake.moveVoltage(12000);

    //reset pos???? maybe better to not touch the bar
    motionProfile.moveDistance(24, -86, 2, {distancePIDValues[3]}, {50, 0.1, 0.3, 40}, 1500);
    pros::delay(120);
    motionProfile.moveDistance(-15, -86, 2, {distancePIDValues[3]}, {50, 0.1, 0.3, 50}, 1500);

    pivotTurn(60, 9500, 0.5, 750, true, {pivotPIDValues[3]});

    motionProfile.moveDistance(7, 60, 2, {distancePIDValues[3]}, {50, 0.1, 0.3, 50}, 1500);
    pivotTurn(90, 9500, 0.5, 750, true, {pivotPIDValues[3]});
    intake.moveVoltage(-12000);
    pros::delay(120);
    driveGroup.moveVoltage(12000);
    pros::delay(600);
    driveGroup.moveVoltage(0);

    intake.moveVoltage(0);

    motionProfile.moveDistance(-8, 90, 2, {distancePIDValues[3]}, {50, 0.1, 0.3, 50}, 1500);
    pivotTurn(-27.5, 9500, 0.5, 750, true, {pivotPIDValues[3]});
    motionProfile.moveDistance(-32.5, -27.5, 2, {distancePIDValues[3]}, {65, 0.1, 0.3, 50}, 1500);
    pivotTurn(-120, 9500, 0.5, 750, true, {pivotPIDValues[3]});
    toggleLeftRearWing();
    motionProfile.moveDistance(-7, -120, 2, {distancePIDValues[3]}, {50, 0.1, 0.3, 50}, 1500);
    pivotTurn(-160, 9500, 0.5, 750, true, {pivotPIDValues[3]});
    toggleLeftRearWing();
    rotationTurn(-154, 9500, 0.5, 500, {rotationPIDValues[3]}); //turn to ball //INCREASE
    motionProfile.moveDistance(-6, -154, 2, {distancePIDValues[3]}, {50, 0.1, 0.3, 50}, 1000);
    pivotTurn(-167, 9500, 0.5, 750, true, {pivotPIDValues[3]});
    motionProfile.moveDistance(-7, -167, 2, {distancePIDValues[3]}, {50, 0.1, 0.3, 50}, 1000);
    pivotTurn(-174, 9500, 0.5, 750, true, {pivotPIDValues[3]});
    driveGroup.moveVoltage(-12000);
    pros::delay(750);
    driveGroup.moveVoltage(12000);
    pros::delay(400);
    driveGroup.moveVoltage(-12000);
    pros::delay(600);
    driveGroup.moveVoltage(0);

    // motionProfile.moveDistance(-5, 90, 2, {distancePIDValues[3]}, {50, 0.1, 0.3, 50}, 1500);
    // rotationTurn(-3, 9500, 0.5, 500, {rotationPIDValues[3]});
    // motionProfile.moveDistance(-34.5, -3, 2, {distancePIDValues[3]}, {65, 0.1, 0.3, 50}, 1500);
    // pivotTurn(-96, 9500, 0.5, 750, true, {pivotPIDValues[3]});
    // intake.moveVoltage(12000);
    // motionProfile.moveDistance(37, -96, 2, {distancePIDValues[3]}, {65, 0.1, 0.3, 50}, 1500);
    // pros::delay(120);
    // motionProfile.moveDistance(-37, -96, 2, {distancePIDValues[3]}, {65, 0.1, 0.3, 50}, 1500);
    // intake.moveVoltage(0);
    // rotationTurn(60, 9500, 0.5, 500, {rotationPIDValues[3]});
    // motionProfile.moveDistance(7, 60, 2, {distancePIDValues[3]}, {50, 0.1, 0.3, 50}, 1500);
    // pivotTurn(5, 9500, 0.5, 750, false, {pivotPIDValues[3]});
    // intake.moveVoltage(-12000);
    // motionProfile.moveDistance(8, 5, 2, {distancePIDValues[3]}, {50, 0.1, 0.3, 50}, 1500);

    // driveGroup.moveVoltage(12000);
    // pros::delay(600);
    // driveGroup.moveVoltage(-12000);
    // pros::delay(300);
    // driveGroup.moveVoltage(12000);
    // pros::delay(600);
    // driveGroup.moveVoltage(0);
    // intake.moveVoltage(0);

}

void scoresix()
{
    motion_profile motionProfile;

    angleOffset = -90;
    // toggleHang();
    pros::delay(350);
    // toggleHang();

    intake.moveVoltage(12000);
    motionProfile.moveDistance(4, -90, 2, {distancePIDValues[3]}, {65, 0.05, 0.1, 60}, 750);
    pros::delay(200);

    motionProfile.moveDistance(-24, -90, 2, {distancePIDValues[3]}, {65, 0.05, 0.2, 55}, 1500);

    /*-- JONATHAN CODE --*/

    // angleOffset = -35;
    // toggleHang();
    // openRightWing();

    // pros::delay(350);
    // toggleHang();
    // closeRightWing();
    // intake.moveVoltage(12000);
    // motionProfile.moveDistance(60, -35, 2, {distancePIDValues[3]}, {65, 0.1, 0.3, 55}, 1500); //temp time out, will decrease

    // // pros::delay(500);

    // rotationTurn(90, 9500, 0.5, 750, {rotationPIDValues[3]}); //face net

    // openLeftWing();
    // openRightWing();

    // intake.moveVoltage(-12000);
    // pros::delay(100);

    // motionProfile.moveDistance(16, 90, 2, {distancePIDValues[3]}, {70, 0.1, 0.3, 60}, 1500);
    // intake.moveVoltage(0);
    // motionProfile.moveDistance(16, 90, 2, {distancePIDValues[3]}, {60, 0.1, 0.3, 60}, 1500); //rams
    // driveGroup.moveVoltage(-12000);
    // pros::delay(250);
    // driveGroup.moveVoltage(0);

    // closeLeftWing();
    // closeRightWing();

    // //this has to be right to the ball
    // pivotTurn(0, 9500, 0.5, 750, true, {pivotPIDValues[3]}); //INCREASE //delay was 1000 WEIRD PAUSE

    // motionProfile.moveDistance(-12, 0, 2,{distancePIDValues[3]}, {60, 0.1, 0.3, 50}, 750);//-13

    // rotationTurn(-85, 9500, 0.5, 500, {rotationPIDValues[3]}); //turn to ball //INCREASE

    // intake.moveVoltage(12000);

    // //reset pos???? maybe better to not touch the bar
    // motionProfile.moveDistance(22, -85, 2, {distancePIDValues[3]}, {50, 0.1, 0.3, 40}, 1500);

    // motionProfile.moveDistance(-15, -85, 2, {distancePIDValues[3]}, {50, 0.1, 0.3, 50}, 1500);

    // //might have to purely stop with timeout or use drivegroup
    // pivotTurn(-15, 9500, 0.5, 650, false, {pivotPIDValues[3]}); //test this one now, see if anything changes

    // motionProfile.moveDistance(-29, -15, 2, {distancePIDValues[3]}, {60, 0.1, 0.3, 40}, 1500);//INCREASE //WATCH FOR THIS!

    // //face side of net
    // rotationTurn(33, 9500, 0.5, 500, {rotationPIDValues[3]}); //INCREASE

    // intake.moveVoltage(-12000);
    // pros::delay(350);
    // intake.moveVoltage(0);
    // rotationTurn(-87, 9500, 0.5, 750, {rotationPIDValues[3]}); //INCREASE

    // intake.moveVoltage(12000);

    // //MAKE SURE THIS DOESN'T CROSS
    // motionProfile.moveDistance(32, -87, 2,{distancePIDValues[3]}, {60, 0.1, 0.3, 40}, 2000);

    // motionProfile.moveDistance(-29, -87, 2,{distancePIDValues[3]}, {60, 0.1, 0.3, 40}, 2000);
    // intake.moveVoltage(0);

    // //foward ram-------
    // rotationTurn(45, 9500, 0.5, 750, {rotationPIDValues[3]});//INCREASE

    // // toggleRightRearWing();
    // // pros::delay(100);

    // // motionProfile.moveDistance(13, 45, 2, {distancePIDValues[3]}, {50, 0.1, 0.3, 40}, 500);

    // //get ball out of corner
    // // rotationTurn(-45, 12000, 0.5, 800,{rotationPIDValues[3]});

    // // toggleRightRearWing();
    // // pros::delay(150);

    // rotationTurn(30, 9500, 0.5, 800, {rotationPIDValues[3]}); //face net //INCREASE
    // intake.moveVoltage(-12000);

    // pros::delay(100);

    // //rams, also adjust these angles so that they are straighter and will have no difficulty pushing it in.
    // motionProfile.moveDistance(22, 30, 2, {distancePIDValues[3]}, {70, 0.1, 0.3, 70}, 650);

    // pivotTurn(0, 9500, 0.5, 650, true, {pivotPIDValues[3]});
    // motionProfile.moveDistance(-10.5, 15, 2, {distancePIDValues[3]}, {60, 0.1, 0.3, 60}, 1500);

    // // motionProfile.moveDistance(16, 18, 2, {distancePIDValues[3]}, {70, 0.1, 0.3, 70}, 1500);

    // driveGroup.moveVoltage(12000);
    // pros::delay(500);
    // driveGroup.moveVoltage(0);

    // motionProfile.moveDistance(-9, 0, 2, {distancePIDValues[3]}, {60, 0.1, 0.3, 60}, 1500);//move back so not touching

}

void scoreSixSafe()
{
    motion_profile motionProfile;
    angleOffset = -35;

    openRightWing();

    pros::delay(350);

    closeRightWing();

    intake.moveVoltage(12000);
    motionProfile.moveDistance(60, -35, 2, {distancePIDValues[3]}, {65, 0.1, 0.3, 55}, 1500); //temp time out, will decrease

    // pros::delay(500);

    rotationTurn(90, 9500, 0.5, 750, {rotationPIDValues[3]}); //face net

    openLeftWing();
    openRightWing();

    motionProfile.moveDistance(16, 90, 2, {distancePIDValues[3]}, {70, 0.1, 0.3, 60}, 1500);
    intake.moveVoltage(0);
    motionProfile.moveDistance(16, 90, 2, {distancePIDValues[3]}, {60, 0.1, 0.3, 60}, 1500); //rams

    closeLeftWing();
    closeRightWing();

    //this has to be right to the ball
    pivotTurn(0, 9500, 0.5, 750, true, {pivotPIDValues[3]}); //INCREASE //delay was 1000 WEIRD PAUSE

    motionProfile.moveDistance(-11, 0, 2,{distancePIDValues[3]}, {50, 0.1, 0.3, 50}, 750);//-13

    rotationTurn(-85, 9500, 0.5, 500, {rotationPIDValues[3]}); //turn to ball //INCREASE

    intake.moveVoltage(12000);

    //reset pos???? maybe better to not touch the bar
    motionProfile.moveDistance(22, -85, 2, {distancePIDValues[3]}, {50, 0.1, 0.3, 40}, 1500);
    intake.moveVoltage(0);

    motionProfile.moveDistance(-15, -85, 2, {distancePIDValues[3]}, {50, 0.1, 0.3, 50}, 1500);

    //might have to purely stop with timeout or use drivegroup
    pivotTurn(-15, 9500, 0.5, 650, false, {pivotPIDValues[3]}); //test this one now, see if anything changes

    motionProfile.moveDistance(-29, -15, 2, {distancePIDValues[3]}, {60, 0.1, 0.3, 40}, 1500);//INCREASE //WATCH FOR THIS!



    //face side of net
    rotationTurn(33, 9500, 0.5, 500, {rotationPIDValues[3]}); //INCREASE

    intake.moveVoltage(-12000);
    pros::delay(550);

    rotationTurn(-87, 9500, 0.5, 750, {rotationPIDValues[3]}); //INCREASE

    intake.moveVoltage(12000);

    //MAKE SURE THIS DOESN'T CROSS
    motionProfile.moveDistance(32, -87, 2,{distancePIDValues[3]}, {60, 0.1, 0.3, 40}, 2000);

    motionProfile.moveDistance(-29, -87, 2,{distancePIDValues[3]}, {60, 0.1, 0.3, 40}, 2000);
    intake.moveVoltage(0);

    // back ram------
    motionProfile.moveDistance(-25, -87, 2,{distancePIDValues[3]}, {60, 0.1, 0.3, 40});

    intake.moveVoltage(0);

    pivotTurn(-135, 9500, 0.5, 750, true, {pivotPIDValues[3]});
    // rotationTurn(-135, 9500, 0.5, 750, {rotationPIDValues[3]});//INCREASE
    toggleLeftRearWing();
    pros::delay(100);

    motionProfile.moveDistance(-13, -135, 1,{distancePIDValues[3]}, {50, 0.1, 0.3, 20} );

    rotationTurn(-180, 12000, 1, 1000, {rotationPIDValues[3]});

    pros::delay(100);

    toggleLeftRearWing();

    rotationTurn(-150, 9500, 0.5, 800, {rotationPIDValues[3]}); //face net //INCREASE

    // pros::delay(100);

    //rams
    motionProfile.moveDistance(-20, -150, 2, {distancePIDValues[3]}, {70, 0.1, 0.3, 70}, 550);

    motionProfile.moveDistance(11, -180, 2, {distancePIDValues[3]}, {60, 0.1, 0.3, 60});

    rotationTurn(0, 9000, 1, 1000, {rotationPIDValues[3]});
    intake.moveVoltage(-12000);
    motionProfile.moveDistance(16, 0, 2, {distancePIDValues[3]}, {70, 0.1, 0.3, 70});
}

void winpointAuton()
{
    // set up with the backwheel on the edge of the 3rd tile tooth thing and with the back sloping until you see the corner of the 2nd tile to the right
    // it's jank, but ill show it to you later
    motion_profile motionProfile;

    /*--Deploy intake--*/
    angleOffset = 12;
    // toggleHang();
    pros::delay(500);
    intake.moveVoltage(12000);
    pros::delay(500);
    intake.moveVoltage(0);
    // toggleHang();

    /*--Destroy & score--*/
    motionProfile.moveDistance(-41, 12, 1, {0.0175, 0, 0.01}, {60, 0.1, 0.3, 10});
    rotationTurn(90, 8000, 1, 500, {rotationPIDValues[3]});
    intake.moveVoltage(-12000);
    pros::delay(200);
    intake.moveVoltage(0);
    toggleLeftWing();
    rotationTurn(-80, 8000, 1, 1200, {rotationPIDValues[3]});
    motionProfile.moveDistance(24, -80, 1, {0.0175, 0, 0.01}, {65, 0.1, 0.3, 10}, 1000);
    toggleLeftWing();
    toggleLeftRearWing();
    motionProfile.moveDistance(-38, -90, 1, {0.0175, 0, 0.01}, {60, 0.1, 0.3, 10}, 1500);
    motionProfile.moveDistance(16, -90, 1, {0.0175, 0, 0.01}, {40, 0.1, 0.3, 30});
    toggleLeftRearWing();

    /*--Get to matchload area--*/
    rotationTurn(30, 8000, 1, 1200, {rotationPIDValues[3]});
    motionProfile.moveDistance(46.5, 30, 1, {0.0175, 0, 0.01}, {65, 0.1, 0.3, 10});
    toggleRightRearWing();
    pros::delay(150);
    driveLeftGroup.moveVoltage(-7500);
    driveRightGroup.moveVoltage(7500);
    pros::delay(650); // flying
    driveLeftGroup.moveVoltage(0);
    driveRightGroup.moveVoltage(0);

    toggleRightRearWing();

    /*--Winpoint ending--*/
    rotationTurn(-39, 8000, 1, 1200, {rotationPIDValues[3]});
    motionProfile.moveDistance(7.75, -39, 1, {0.0175, 0, 0.01}, {40, 0.01, 0.3, 10}, 1000);
    rotationTurn(-93, 8000, 1, 800, {rotationPIDValues[3]});
    pros::delay(75);
    intake.moveVoltage(-12000);
    motionProfile.moveDistance(31.75, -93, 1, {0.0175, 0, 0.01}, {65, 0.01, 0.4, 20}); // tounches bar
    driveGroup.moveVoltage(0);
    intake.moveVoltage(0);

    /*--Destroy ending--*/
    //     rotationTurn(30, 8000, 1, 1200, {rotationPIDValues[3]});
    //     motionProfile.moveDistance(10, 136.5, 1, {0.0175, 0, 0.01}, {30, 0.01, 0.3, 3});
    //     rotationTurn(110, 8000, 1, 1200, {rotationPIDValues[3]});
    //     motionProfile.moveDistance(6, 110, 1, {0.0175, 0, 0.01}, {30, 0.01, 0.3, 3});
}

void destruction()
{
    // same setup as regular winpoint, but intake facing front
    motion_profile motionProfile;

    /*--Deploy intake--*/
    angleOffset = 12;
    // toggleHang();
    pros::delay(500);
    intake.moveVoltage(12000);
    pros::delay(500);
    intake.moveVoltage(0);
    // toggleHang();

    /*--Destroy--*/

    motionProfile.moveDistance(-41, 12, 1, {0.0175, 0, 0.01}, {60, 0.1, 0.3, 10});
    rotationTurn(90, 8000, 1, 500, {rotationPIDValues[3]});
    intake.moveVoltage(-12000);
    pros::delay(200);
    intake.moveVoltage(0);
    toggleLeftWing();
    rotationTurn(-80, 8000, 1, 1200, {rotationPIDValues[3]});
    motionProfile.moveDistance(24, -80, 1, {0.0175, 0, 0.01}, {65, 0.1, 0.3, 10}, 1000);
    toggleLeftWing();
    toggleLeftRearWing();
    motionProfile.moveDistance(-38, -90, 1, {0.0175, 0, 0.01}, {60, 0.1, 0.3, 10}, 1500);
    motionProfile.moveDistance(16, -90, 1, {0.0175, 0, 0.01}, {40, 0.1, 0.3, 30});
    toggleLeftRearWing();

    /*--Get to matchload area--*/
    rotationTurn(30, 8000, 1, 1200, {rotationPIDValues[3]});
    motionProfile.moveDistance(50, 30, 1, {0.0175, 0, 0.01}, {65, 0.1, 0.3, 10});
    toggleRightRearWing();
    pros::delay(150);
    driveLeftGroup.moveVoltage(-7500);
    driveRightGroup.moveVoltage(7500);
    pros::delay(650); // flying
    driveLeftGroup.moveVoltage(0);
    driveRightGroup.moveVoltage(0);

    toggleRightRearWing();

    /*--Destroy ending--*/
    rotationTurn(30, 8000, 1, 1200, {rotationPIDValues[3]});
    motionProfile.moveDistance(10, 136.5, 1, {0.0175, 0, 0.01}, {30, 0.01, 0.3, 3});
    rotationTurn(110, 8000, 1, 1200, {rotationPIDValues[3]});
    motionProfile.moveDistance(6, 110, 1, {0.0175, 0, 0.01}, {30, 0.01, 0.3, 3});
}