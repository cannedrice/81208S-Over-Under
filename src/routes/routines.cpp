#include "main.h"

// movement profile = {0.05, 0, 0.01}
// rotation turn 8000, 0.5, 6000, {0.016, 0, 0.08} 90 deg
// 400 chassis has max speed of ~68.07 inches/sec, use 67 or 68 for max, use 60 reg

void tests()
{
    // toggleHang();
    // pros::delay(500);
    // intake.moveVoltage(12000);
    // pros::delay(500);
    // intake.moveVoltage(0);
    motion_profile motionProfile;
    angleOffset = -35;
    toggleHang();
    openRightWing();

    pros::delay(350);
    toggleHang();
    closeRightWing();
    intake.moveVoltage(12000);
    motionProfile.moveDistance(60, -35, 2, {0.05, 0, 0.01}, {65, 0.1, 0.3, 55}, 1500); //temp time out, will decrease

    // pros::delay(500);

    rotationTurn(90, 9500, 0.5, 750, {0.015, 0, 0.08}); //face net

    openLeftWing();
    openRightWing();

    intake.moveVoltage(-12000);
    pros::delay(100);

    motionProfile.moveDistance(16, 90, 2, {0.05, 0, 0.01}, {70, 0.1, 0.3, 60}, 1500);
    intake.moveVoltage(0);
    motionProfile.moveDistance(16, 90, 2, {0.05, 0, 0.01}, {60, 0.1, 0.3, 60}, 1500); //rams
    driveGroup.moveVoltage(-12000);
    pros::delay(250);
    driveGroup.moveVoltage(0);

    closeLeftWing();
    closeRightWing();

    //this has to be right to the ball
    pivotTurn(0, 9500, 0.5, 750, true, {0.016, 0, 0.02}); //INCREASE //delay was 1000 WEIRD PAUSE

    motionProfile.moveDistance(-12, 0, 2,{0.05, 0, 0.01}, {60, 0.1, 0.3, 50}, 750);//-13

    rotationTurn(-85, 9500, 0.5, 500, {0.016, 0, 0.08}); //turn to ball //INCREASE

    intake.moveVoltage(12000);

    //reset pos???? maybe better to not touch the bar
    motionProfile.moveDistance(22, -85, 2, {0.05, 0, 0.01}, {50, 0.1, 0.3, 40}, 1500);

    motionProfile.moveDistance(-15, -85, 2, {0.05, 0, 0.01}, {50, 0.1, 0.3, 50}, 1500);

    //might have to purely stop with timeout or use drivegroup
    pivotTurn(-15, 9500, 0.5, 650, false, {0.016, 0, 0.02}); //test this one now, see if anything changes

    motionProfile.moveDistance(-29, -15, 2, {0.05, 0, 0.01}, {60, 0.1, 0.3, 40}, 1500);//INCREASE //WATCH FOR THIS!

    //face side of net
    rotationTurn(33, 9500, 0.5, 500, {0.019, 0, 0.08}); //INCREASE

    intake.moveVoltage(-12000);
    pros::delay(350);
    intake.moveVoltage(0);
    rotationTurn(-87, 9500, 0.5, 750, {0.017, 0, 0.08}); //INCREASE

    intake.moveVoltage(12000);

    //MAKE SURE THIS DOESN'T CROSS
    motionProfile.moveDistance(32, -87, 2,{0.05, 0, 0.01}, {60, 0.1, 0.3, 40}, 2000);

    motionProfile.moveDistance(-29, -87, 2,{0.05, 0, 0.01}, {60, 0.1, 0.3, 40}, 2000);
    intake.moveVoltage(0);

    //foward ram-------
    rotationTurn(45, 9500, 0.5, 750, {0.016, 0, 0.08});//INCREASE

    // toggleRightRearWing();
    // pros::delay(100);

    motionProfile.moveDistance(13, 45, 2, {0.05, 0, 0.01}, {50, 0.1, 0.3, 40}, 500);

    //get ball out of corner
    rotationTurn(-45, 12000, 0.5, 800,{0.016, 0, 0.08});



    // toggleRightRearWing();
    // pros::delay(150);

    rotationTurn(30, 9500, 0.5, 800, {0.017, 0, 0.08}); //face net //INCREASE
    intake.moveVoltage(-12000);

    // pros::delay(100);

    //rams, also adjust these angles so that they are straighter and will have no difficulty pushing it in.
    motionProfile.moveDistance(22, 30, 2, {0.05, 0, 0.01}, {70, 0.1, 0.3, 70}, 650);

    pivotTurn(0, 9500, 0.5, 650, true, {0.016, 0, 0.02});
    motionProfile.moveDistance(-10.5, 15, 2, {0.05, 0, 0.01}, {60, 0.1, 0.3, 60}, 1500);

    // motionProfile.moveDistance(16, 18, 2, {0.05, 0, 0.01}, {70, 0.1, 0.3, 70}, 1500);

    driveGroup.moveVoltage(12000);
    pros::delay(500);
    driveGroup.moveVoltage(0);

    motionProfile.moveDistance(-9, 0, 2, {0.05, 0, 0.01}, {60, 0.1, 0.3, 60}, 1500);//move back so not touching

}

void scorefiveCorner() /*--father son holy spirit amen  shorten timeouts if needed--*/
{
    motion_profile motionProfile;
    //new setup is parallel to wall, touching diagonal bar, wheels (not gears) on foam tile connecting layer, facing opposite offensive zone
    /*--Deploy--*/
    toggleHang();
    pros::delay(500);
    // intake.moveVoltage(12000);
    pros::delay(100);
    // intake.moveVoltage(0);
    toggleHang();

    /*--Side triball--*/
    rotationTurn(-40, 8000, 1, 500, {0.019, 0, 0.08});
    toggleLeftRearWing();
    motionProfile.moveDistance(-8, -40, 1, {0.05, 0, 0.01}, {60, 0.05, 0.2, 10}, 500);
    rotationTurn(-90, 8000, 1, 600, {0.017, 0, 0.08});
    toggleLeftRearWing();
    rotationTurn(-40, 8000, 1, 500, {0.019, 0, 0.08});
    motionProfile.moveDistance(-9, -40, 1, {0.05, 0, 0.01}, {50, 0.05, 0.02, 40}, 500);
    rotationTurn(-90, 8000, 1, 500, {0.018, 0, 0.08});
    driveGroup.moveVoltage(-12000);
    pros::delay(600);
    driveGroup.moveVoltage(0);

    /*--Preload--*/
    motionProfile.moveDistance(11, -90, 1, {0.05, 0, 0.01}, {60, 0.05, 0.2, 10}, 1000);
    rotationTurn(20.5, 9500, 1, 500, {0.013, 0, 0.06});
    motionProfile.moveDistance(49, 20.5, 1, {0.04, 0, 0.02}, {65, 0.1, 0.5, 10}, 2000);
    intake.moveVoltage(12000);
    pros::delay(130);
    intake.moveVoltage(0);
    motionProfile.moveDistance(-1, 165, 1, {0.017, 0, 0.04}, {60, 0.01, 0.5, 40});
    rotationTurn(160, 8000, 1, 500, {0.016, 0, 0.08});
    motionProfile.moveDistance(8, 160, 1, {0.02, 0, 0.04}, {60, 0.01, 0.2, 25}, 1000);
    intake.moveVoltage(-12000);
    pros::delay(220);
    intake.moveVoltage(0);
    // motionProfile.moveDistance(-5, 162, 1, {0.02, 0, 0.04}, {60, 0.01, 0.2, 25}, 1000);

    /*--Experimental 2nd & 3rd triball*/
    // rotationTurn(20.5, 8000, 1, 500, {0.016, 0, 0.08});
    // motionProfile.moveDistance(15, 20.5, 1, {0.05, 0, 0.01}, {65, 0.1, 0.5, 10}, 1000);
    // intake.moveVoltage(12000);
    // pros::delay(110);
    // intake.moveVoltage(0);
    // motionProfile.moveDistance(-1, 165, 1, {0.017, 0, 0.04}, {60, 0.01, 0.5, 40});
    // rotationTurn(160, 8000, 1, 500, {0.016, 0, 0.08});
    // motionProfile.moveDistance(8, 160, 1, {0.02, 0, 0.04}, {60, 0.01, 0.2, 25}, 1000);
    // intake.moveVoltage(-12000);
    // pros::delay(220);
    // intake.moveVoltage(0);
    // rotationTurn(60, 8000, 1, 500, {0.019, 0, 0.08});
    // intake.moveVoltage(12000);
    // motionProfile.moveDistance(24, 60, 1, {0.05, 0, 0.01}, {62, 0.1, 0.2, 10}, 1000);
    // pros::delay(175);
    // intake.moveVoltage(0);
    // motionProfile.moveDistance(-8.5, 60, 1, {0.05, 0, 0.01}, {60, 0.01, 0.2, 10}, 1000);
    // rotationTurn(126.5, 8000, 1, 500, {0.016, 0, 0.08});
    // toggleLeftWing();
    // toggleRightWing();
    // motionProfile.moveDistance(9, 126.5, 1, {0.05, 0, 0.01}, {60, 0.1, 0.2, 10}, 1000);

    /*--2nd & 3rd triball--*/
    rotationTurn(55, 9500, 1, 500, {0.017, 0, 0.08});
    intake.moveVoltage(12000);
    motionProfile.moveDistance(27.5, 55, 1, {0.05, 0, 0.01}, {62, 0.1, 0.2, 10}, 1000);
    pros::delay(200);
    motionProfile.moveDistance(-8.5, 68.5, 1, {0.05, 0, 0.01}, {60, 0.01, 0.2, 10}, 1000);
    rotationTurn(126.5, 8000, 1, 500, {0.016, 0, 0.08});
    intake.moveVoltage(0);
    toggleLeftWing();
    toggleRightWing();
    motionProfile.moveDistance(9, 126.5, 1, {0.05, 0, 0.01}, {60, 0.1, 0.2, 10}, 1000);

    /*--Lining up for push--*/
    rotationTurn(178, 8000, 1, 500, {0.016, 0, 0.08});
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
    toggleHang();
    // openRightWing();

    pros::delay(350);
    toggleHang();
    // closeRightWing();
    intake.moveVoltage(12000);
    motionProfile.moveDistance(62.75, -35, 2, {0.05, 0, 0.01}, {67, 0.1, 0.3, 60}, 1500); //temp time out, will decrease

    pros::delay(120);

    rotationTurn(90, 9500, 0.5, 750, {0.015, 0, 0.08}); //face net

    openLeftWing();
    openRightWing();

    intake.moveVoltage(-12000);
    pros::delay(100);

    motionProfile.moveDistance(16, 90, 2, {0.05, 0, 0.01}, {70, 0.1, 0.3, 60}, 1500);
    motionProfile.moveDistance(16, 90, 2, {0.05, 0, 0.01}, {65, 0.1, 0.3, 60}, 1500); //rams
    driveGroup.moveVoltage(-12000);
    pros::delay(250);
    driveGroup.moveVoltage(0);

    closeLeftWing();
    closeRightWing();

    //this has to be right to the ball
    pivotTurn(0, 9500, 0.5, 750, true, {0.016, 0, 0.02}); //INCREASE //delay was 1000 WEIRD PAUSE
    motionProfile.moveDistance(-11, 0, 2,{0.05, 0, 0.01}, {65, 0.1, 0.3, 50}, 750);//-13
    rotationTurn(-86, 9500, 0.5, 500, {0.016, 0, 0.08}); //turn to ball //INCREASE

    intake.moveVoltage(12000);

    //reset pos???? maybe better to not touch the bar
    motionProfile.moveDistance(24, -86, 2, {0.05, 0, 0.01}, {65, 0.1, 0.3, 55}, 1500);
    pros::delay(120);
    motionProfile.moveDistance(-15, -86, 2, {0.05, 0, 0.01}, {65, 0.1, 0.3, 55}, 1500);
    
    pivotTurn(60, 9500, 0.5, 750, true, {0.016, 0, 0.02}); 

    motionProfile.moveDistance(7, 60, 2, {0.05, 0, 0.01}, {60, 0.1, 0.3, 50}, 1500);
    pivotTurn(90, 9500, 0.5, 750, true, {0.016, 0, 0.02}); 
    intake.moveVoltage(-12000);
    pros::delay(120);
    driveGroup.moveVoltage(12000);
    pros::delay(600);
    driveGroup.moveVoltage(0);

    intake.moveVoltage(0);

    motionProfile.moveDistance(-8, 90, 2, {0.05, 0, 0.01}, {60, 0.1, 0.3, 55}, 1500);
    pivotTurn(-28.25, 9500, 0.5, 750, true, {0.016, 0, 0.02});
    motionProfile.moveDistance(-29.2, -28.25, 2, {0.05, 0, 0.01}, {68, 0.1, 0.3, 55}, 1500);
    pivotTurn(-125, 9500, 0.5, 750, true, {0.016, 0, 0.02});
    toggleLeftRearWing();
    motionProfile.moveDistance(-5, -125, 2, {0.05, 0, 0.01}, {60, 0.1, 0.3, 55}, 1500);
    pivotTurn(-160, 10500, 0.5, 500, true, {0.016, 0, 0.02}); 
    toggleLeftRearWing();
    motionProfile.moveDistance(5, -120, 2, {0.05, 0, 0.01}, {60, 0.1, 0.3, 55}, 1500);
    pivotTurn(-147, 9500, 0.5, 500, true, {0.016, 0, 0.02}); //turn to ball //INCREASE
    motionProfile.moveDistance(-9, -147, 2, {0.05, 0, 0.01}, {60, 0.1, 0.3, 55}, 1000);
    pivotTurn(-167, 9500, 0.5, 750, true, {0.016, 0, 0.02});
    motionProfile.moveDistance(-7, -167, 2, {0.05, 0, 0.01}, {60, 0.1, 0.3, 55}, 1000);
    pivotTurn(-174, 9500, 0.5, 750, true, {0.016, 0, 0.02});
    driveGroup.moveVoltage(-12000);
    pros::delay(750);
    driveGroup.moveVoltage(12000);
    pros::delay(400);
    driveGroup.moveVoltage(-12000);
    pros::delay(600);
    driveGroup.moveVoltage(0);

    // motionProfile.moveDistance(-5, 90, 2, {0.05, 0, 0.01}, {50, 0.1, 0.3, 50}, 1500);
    // rotationTurn(-3, 9500, 0.5, 500, {0.016, 0, 0.08});
    // motionProfile.moveDistance(-34.5, -3, 2, {0.05, 0, 0.01}, {65, 0.1, 0.3, 50}, 1500);
    // pivotTurn(-96, 9500, 0.5, 750, true, {0.016, 0, 0.02});
    // intake.moveVoltage(12000);
    // motionProfile.moveDistance(37, -96, 2, {0.05, 0, 0.01}, {65, 0.1, 0.3, 50}, 1500);
    // pros::delay(120);
    // motionProfile.moveDistance(-37, -96, 2, {0.05, 0, 0.01}, {65, 0.1, 0.3, 50}, 1500);
    // intake.moveVoltage(0);
    // rotationTurn(60, 9500, 0.5, 500, {0.016, 0, 0.08});
    // motionProfile.moveDistance(7, 60, 2, {0.05, 0, 0.01}, {50, 0.1, 0.3, 50}, 1500);
    // pivotTurn(5, 9500, 0.5, 750, false, {0.016, 0, 0.02});
    // intake.moveVoltage(-12000);
    // motionProfile.moveDistance(8, 5, 2, {0.05, 0, 0.01}, {50, 0.1, 0.3, 50}, 1500);
    
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
    // edge of chassis on middle of second tooth
    angleOffset = 0;
    toggleHang();
    pros::delay(350);
    toggleHang();
    
    intake.moveVoltage(12000);
    motionProfile.moveDistance(6, 0, 2, {0.05, 0, 0.01}, {65, 0.05, 0.1, 60}, 750);
    pros::delay(200);

    motionProfile.moveDistance(-21.75, 0, 2, {0.05, 0, 0.01}, {67, 0.05, 0.2, 60}, 1500);
    pivotTurn(-33, 9500, 0.5, 750, true, {0.016, 0, 0.02});
    toggleLeftRearWing();
    motionProfile.moveDistance(-11.5, -33, 2, {0.05, 0, 0.01}, {69, 0.05, 0.2, 60}, 1500);
    pivotTurn(-60, 9500, 0.5, 750, true, {0.016, 0, 0.02});
    toggleLeftRearWing();
    motionProfile.moveDistance(2.5, -60, 2, {0.05, 0, 0.01}, {65, 0.05, 0.2, 60}, 1500);
    motionProfile.moveDistance(-6.5, -60, 2, {0.05, 0, 0.01}, {70, 0.05, 0.2, 60}, 1500);
    pivotTurn(-85, 9500, 0.5, 750, true, {0.016, 0, 0.02});
    motionProfile.moveDistance(-4, -85, 2, {0.05, 0, 0.01}, {65, 0.05, 0.2, 60}, 1500);
    driveGroup.moveVoltage(-12000);
    pros::delay(500);
    driveGroup.moveVoltage(0);
    motionProfile.moveDistance(7, -90, 2, {0.05, 0, 0.01}, {70, 0.05, 0.2, 60}, 1500);
    pivotTurn(32, 9500, 0.5, 1200, true, {0.016, 0, 0.02});
    motionProfile.moveDistance(17, 35, 2, {0.05, 0, 0.01}, {70, 0.05, 0.2, 60}, 1500);
    pivotTurn(150, 9500, 0.5, 1200, true, {0.016, 0, 0.02});
    intake.moveVoltage(-12000);
    pros::delay(200);
    intake.moveVoltage(12000);
    motionProfile.moveDistance(-5, 150, 2, {0.05, 0, 0.01}, {65, 0.05, 0.2, 60}, 1500);
    rotationTurn(15, 9500, 1, 1200, {0.017, 0, 0.08});
    motionProfile.moveDistance(12, 17, 2, {0.05, 0, 0.01}, {70, 0.05, 0.2, 60}, 1500);
    pros::delay(200);
    motionProfile.moveDistance(-6, 15, 2, {0.05, 0, 0.01}, {65, 0.05, 0.2, 60}, 1500);
    rotationTurn(132, 10000, 1, 600, {0.015, 0, 0.06});
    motionProfile.moveDistance(8, 137, 2, {0.05, 0, 0.01}, {70, 0.05, 0.2, 60}, 1500);
    intake.moveVoltage(-12000);
    pros::delay(250);
    intake.moveVoltage(12000);
    rotationTurn(43, 10000, 1, 600, {0.017, 0, 0.08});
    motionProfile.moveDistance(29.25, 45, 2, {0.05, 0, 0.01}, {70, 0.05, 0.2, 60}, 1200);
    motionProfile.moveDistance(-5.5, 45, 2, {0.05, 0, 0.01}, {65, 0.05, 0.2, 60}, 1500);
    rotationTurn(110, 10000, 1, 600, {0.017, 0, 0.08});
    pivotTurn(175, 10000, 0.5, 800, true, {0.016, 0, 0.02});
    toggleLeftWing();
    toggleRightWing();
    motionProfile.moveDistance(4, 175, 2, {0.05, 0, 0.01}, {70, 0.05, 0.2, 60}, 1500);
    intake.moveVoltage(-12000);
    driveGroup.moveVoltage(12000);
    pros::delay(900);
    driveGroup.moveVoltage(0);
    intake.moveVoltage(0);
    toggleLeftWing();
    toggleRightWing();










    

    /*-- JONATHAN CODE --*/

    // angleOffset = -35;
    // toggleHang();
    // openRightWing();

    // pros::delay(350);
    // toggleHang();
    // closeRightWing();
    // intake.moveVoltage(12000);
    // motionProfile.moveDistance(60, -35, 2, {0.05, 0, 0.01}, {65, 0.1, 0.3, 55}, 1500); //temp time out, will decrease

    // // pros::delay(500);

    // rotationTurn(90, 9500, 0.5, 750, {0.015, 0, 0.08}); //face net

    // openLeftWing();
    // openRightWing();

    // intake.moveVoltage(-12000);
    // pros::delay(100);

    // motionProfile.moveDistance(16, 90, 2, {0.05, 0, 0.01}, {70, 0.1, 0.3, 60}, 1500);
    // intake.moveVoltage(0);
    // motionProfile.moveDistance(16, 90, 2, {0.05, 0, 0.01}, {60, 0.1, 0.3, 60}, 1500); //rams
    // driveGroup.moveVoltage(-12000);
    // pros::delay(250);
    // driveGroup.moveVoltage(0);

    // closeLeftWing();
    // closeRightWing();

    // //this has to be right to the ball
    // pivotTurn(0, 9500, 0.5, 750, true, {0.016, 0, 0.02}); //INCREASE //delay was 1000 WEIRD PAUSE

    // motionProfile.moveDistance(-12, 0, 2,{0.05, 0, 0.01}, {60, 0.1, 0.3, 50}, 750);//-13

    // rotationTurn(-85, 9500, 0.5, 500, {0.016, 0, 0.08}); //turn to ball //INCREASE

    // intake.moveVoltage(12000);

    // //reset pos???? maybe better to not touch the bar
    // motionProfile.moveDistance(22, -85, 2, {0.05, 0, 0.01}, {50, 0.1, 0.3, 40}, 1500);

    // motionProfile.moveDistance(-15, -85, 2, {0.05, 0, 0.01}, {50, 0.1, 0.3, 50}, 1500);

    // //might have to purely stop with timeout or use drivegroup
    // pivotTurn(-15, 9500, 0.5, 650, false, {0.016, 0, 0.02}); //test this one now, see if anything changes

    // motionProfile.moveDistance(-29, -15, 2, {0.05, 0, 0.01}, {60, 0.1, 0.3, 40}, 1500);//INCREASE //WATCH FOR THIS!

    // //face side of net
    // rotationTurn(33, 9500, 0.5, 500, {0.019, 0, 0.08}); //INCREASE

    // intake.moveVoltage(-12000);
    // pros::delay(350);
    // intake.moveVoltage(0);
    // rotationTurn(-87, 9500, 0.5, 750, {0.017, 0, 0.08}); //INCREASE

    // intake.moveVoltage(12000);

    // //MAKE SURE THIS DOESN'T CROSS
    // motionProfile.moveDistance(32, -87, 2,{0.05, 0, 0.01}, {60, 0.1, 0.3, 40}, 2000);

    // motionProfile.moveDistance(-29, -87, 2,{0.05, 0, 0.01}, {60, 0.1, 0.3, 40}, 2000);
    // intake.moveVoltage(0);

    // //foward ram-------
    // rotationTurn(45, 9500, 0.5, 750, {0.016, 0, 0.08});//INCREASE

    // // toggleRightRearWing();
    // // pros::delay(100);

    // // motionProfile.moveDistance(13, 45, 2, {0.05, 0, 0.01}, {50, 0.1, 0.3, 40}, 500);

    // //get ball out of corner
    // // rotationTurn(-45, 12000, 0.5, 800,{0.016, 0, 0.08});

    // // toggleRightRearWing();
    // // pros::delay(150);

    // rotationTurn(30, 9500, 0.5, 800, {0.017, 0, 0.08}); //face net //INCREASE
    // intake.moveVoltage(-12000);

    // pros::delay(100);

    // //rams, also adjust these angles so that they are straighter and will have no difficulty pushing it in.
    // motionProfile.moveDistance(22, 30, 2, {0.05, 0, 0.01}, {70, 0.1, 0.3, 70}, 650);

    // pivotTurn(0, 9500, 0.5, 650, true, {0.016, 0, 0.02});
    // motionProfile.moveDistance(-10.5, 15, 2, {0.05, 0, 0.01}, {60, 0.1, 0.3, 60}, 1500);

    // // motionProfile.moveDistance(16, 18, 2, {0.05, 0, 0.01}, {70, 0.1, 0.3, 70}, 1500);

    // driveGroup.moveVoltage(12000);
    // pros::delay(500);
    // driveGroup.moveVoltage(0);

    // motionProfile.moveDistance(-9, 0, 2, {0.05, 0, 0.01}, {60, 0.1, 0.3, 60}, 1500);//move back so not touching

}

void safeWinpoint()
{
    // setup against wall and matchload bar
    motion_profile motionProfile;

    /*--Deploy intake--*/
    angleOffset = 45;
    toggleHang();
    pros::delay(400);
    toggleHang();

    /*--Alliance ball--*/
    motionProfile.moveDistance(-10, 45, 1, {0.05, 0, 0.01}, {60, 0.05, 0.2, 40});
    pivotTurn(90, 9500, 0.5, 800, false, {0.016, 0, 0.02});
    motionProfile.moveDistance(-4, 90, 1, {0.05, 0, 0.01}, {60, 0.05, 0.2, 40});
    pros::delay(200);
    driveGroup.moveVoltage(-10000);
    pros::delay(300);
    driveGroup.moveVoltage(0);
    motionProfile.moveDistance(9, 90, 1, {0.05, 0, 0.01}, {60, 0.05, 0.2, 40});
    pivotTurn(40, 9500, 0.5, 800, false, {0.016, 0, 0.02});
    motionProfile.moveDistance(8, 40, 1, {0.05, 0, 0.01}, {60, 0.05, 0.2, 40});
    toggleRightRearWing();
    pros::delay(150);
    driveLeftGroup.moveVoltage(-7500);
    driveRightGroup.moveVoltage(7500);
    pros::delay(350); // flying
    driveLeftGroup.moveVoltage(0);
    driveRightGroup.moveVoltage(0);
    toggleRightRearWing();
    rotationTurn(35, 9500, 1, 1200, {0.017, 0, 0.08});
    intake.moveVoltage(-12000);
    motionProfile.moveDistance(11.5, 35, 1, {0.05, 0, 0.01}, {60, 0.05, 0.2, 40});
    pivotTurn(0, 9500, 0.5, 800, false, {0.016, 0, 0.02});
    motionProfile.moveDistance(21.5, 0, 1, {0.05, 0, 0.01}, {60, 0.05, 0.2, 40});
}

void winpoint(){
    // set up with the backwheel on the edge of the 3rd tile tooth thing and with the back sloping until you see the corner of the 2nd tile to the right
    // it's jank, but ill show it to you later
    motion_profile motionProfile;

    /*--Deploy intake--*/
    angleOffset = 12;
    toggleHang();
    pros::delay(500);
    intake.moveVoltage(12000);
    pros::delay(500);
    intake.moveVoltage(0);
    toggleHang();

    /*--Destroy & score--*/
    motionProfile.moveDistance(-41, 12, 1, {0.0175, 0, 0.01}, {60, 0.1, 0.3, 25});
    rotationTurn(90, 8000, 1, 500, {0.016, 0, 0.08});
    intake.moveVoltage(-12000);
    pros::delay(200);
    intake.moveVoltage(0);
    toggleLeftWing();
    rotationTurn(-80, 8000, 1, 1200, {0.016, 0, 0.08});
    motionProfile.moveDistance(24, -80, 1, {0.0175, 0, 0.01}, {65, 0.1, 0.3, 25}, 1000);
    toggleLeftWing();
    toggleLeftRearWing();
    motionProfile.moveDistance(-38, -90, 1, {0.0175, 0, 0.01}, {60, 0.1, 0.3, 25}, 1500);
    motionProfile.moveDistance(16, -90, 1, {0.0175, 0, 0.01}, {40, 0.1, 0.3, 30});
    toggleLeftRearWing();

    /*--Get to matchload area--*/
    rotationTurn(30, 8000, 1, 1200, {0.016, 0, 0.08});
    motionProfile.moveDistance(45.25, 30, 1, {0.0175, 0, 0.01}, {65, 0.1, 0.3, 10});
    toggleRightRearWing();
    pros::delay(150);
    driveLeftGroup.moveVoltage(-7500);
    driveRightGroup.moveVoltage(7500);
    pros::delay(650); // flying
    driveLeftGroup.moveVoltage(0);
    driveRightGroup.moveVoltage(0);

    toggleRightRearWing();

    /*--Winpoint ending--*/
    rotationTurn(-39, 8000, 1, 1200, {0.016, 0, 0.08});
    motionProfile.moveDistance(7.75, -39, 1, {0.0175, 0, 0.01}, {40, 0.01, 0.3, 10}, 1000);
    rotationTurn(-93, 8000, 1, 800, {0.016, 0, 0.08});
    pros::delay(75);
    intake.moveVoltage(-12000);
    motionProfile.moveDistance(31.75, -93, 1, {0.0175, 0, 0.01}, {65, 0.01, 0.4, 20}); // tounches bar
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
    // set up with the backwheel on the edge of the 3rd tile tooth thing and with the back sloping until you see the corner of the 2nd tile to the right
    // it's jank, but ill show it to you later
    motion_profile motionProfile;

    /*--Deploy intake--*/
    angleOffset = -78;
    toggleHang();
    toggleLeftWing();
    intake.moveVoltage(12000);
    pros::delay(400);
    toggleHang();
    toggleLeftWing();

    motionProfile.moveDistance(42, -78, 1, {0.05, 0, 0.01}, {70, 0.05, 0.2, 60});
    pros::delay(1000);
    motionProfile.moveDistance(-37, -78, 1, {0.05, 0, 0.01}, {70, 0.05, 0.2, 60});
    pivotTurn(45, 9500, 0.5, 800, false, {0.016, 0, 0.02});
    motionProfile.moveDistance(-10, 45, 1, {0.05, 0, 0.01}, {65, 0.05, 0.2, 55});
    pivotTurn(90, 9500, 0.5, 800, false, {0.016, 0, 0.02});
    motionProfile.moveDistance(-4, 90, 1, {0.05, 0, 0.01}, {60, 0.05, 0.2, 40});
    pros::delay(200);
    driveGroup.moveVoltage(-10000);
    pros::delay(300);
    driveGroup.moveVoltage(0);
    motionProfile.moveDistance(9, 90, 1, {0.05, 0, 0.01}, {65, 0.05, 0.2, 55});
    pivotTurn(40, 9500, 0.5, 800, false, {0.016, 0, 0.02});
    motionProfile.moveDistance(9, 40, 1, {0.05, 0, 0.01}, {65, 0.05, 0.2, 55});
    toggleRightRearWing();
    pros::delay(150);
    driveLeftGroup.moveVoltage(-7500);
    driveRightGroup.moveVoltage(7500);
    pros::delay(350); // flying
    driveLeftGroup.moveVoltage(0);
    driveRightGroup.moveVoltage(0);
    toggleRightRearWing();
    rotationTurn(35, 9500, 1, 1200, {0.017, 0, 0.08});
    intake.moveVoltage(-12000);
    motionProfile.moveDistance(11.5, 35, 1, {0.05, 0, 0.01}, {65, 0.05, 0.2, 55});
    pivotTurn(0, 9500, 0.5, 800, false, {0.016, 0, 0.02});
    motionProfile.moveDistance(21.5, 0, 1, {0.05, 0, 0.01}, {60, 0.05, 0.2, 40});
}

void troll()
{
    // set up with the backwheel on the edge of the 3rd tile tooth thing and with the back sloping until you see the corner of the 2nd tile to the right
    // it's jank, but ill show it to you later
    motion_profile motionProfile;

    /*--Deploy intake--*/
    angleOffset = -78;
    toggleHang();
    toggleLeftWing();
    intake.moveVoltage(12000);
    pros::delay(500);
    toggleLeftWing();

    motionProfile.moveDistance(42, -78, 1, {0.05, 0, 0.01}, {70, 0.05, 0.2, 60});
    toggleHang();
    pros::delay(200);
    motionProfile.moveDistance(-2, -78, 1, {0.05, 0, 0.01}, {65, 0.05, 0.2, 55});
    rotationTurn(0, 9500, 1, 1200, {0.017, 0, 0.08});
    toggleLeftWing();
    motionProfile.moveDistance(19, 0, 1, {0.05, 0, 0.01}, {65, 0.05, 0.2, 55}, 600);
    toggleLeftWing();
    intake.moveVoltage(-12000);
    motionProfile.moveDistance(-3, 0, 1, {0.05, 0, 0.01}, {65, 0.05, 0.2, 55}, 500);
    pros::delay(500);
    intake.moveVoltage(0);
    motionProfile.moveDistance(-20, 0, 1, {0.05, 0, 0.01}, {65, 0.05, 0.2, 55}, 1000);
}