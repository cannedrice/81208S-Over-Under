#include "main.h"

// movement profile = {0.05, 0, 0.01}
// rotation turn 8000, 0.5, 6000, {0.016, 0, 0.08} 90 deg
// 400 chassis has max speed of ~68.07 inches/sec, use 67 or 68 for max, use 60 reg

void tests()
{
    motion_profile motionProfile;
    toggleHang();
    pros::delay(500);
    intake.moveVoltage(12000);
    pros::delay(500);
    intake.moveVoltage(0);
}

void scoring() //deprecated
{
    motion_profile motionProfile;

    /*--Deploy intake--*/
    

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
    //new setup is parallel to wall, touching diagonal bar, wheels (not gears) on foam tile connecting layer, facing opposite offensive zone
    toggleHang();
    pros::delay(250);
    toggleHang();
    rotationTurn(-40, 8000, 1, 1200, {0.019, 0, 0.08});
    toggleLeftRearWing();
    motionProfile.moveDistance(-8, -40, 1, {0.05, 0, 0.01}, {60, 0.05, 0.2, 10});
    rotationTurn(-45-45, 8000, 1, 1200, {0.017, 0, 0.08});
    toggleLeftRearWing();
    rotationTurn(5-45, 8000, 1, 1200, {0.019, 0, 0.08});
    motionProfile.moveDistance(-9, 5-45, 1, {0.05, 0, 0.01}, {50, 0.05, 0.02, 40});
    rotationTurn(-90, 8000, 1, 1200, {0.018, 0, 0.08});
    driveGroup.moveVoltage(-12000);
    pros::delay(600);
    driveGroup.moveVoltage(0);

    /*--Additional triballs--*/
    motionProfile.moveDistance(13, -45-45, 1, {0.05, 0, 0.01}, {60, 0.05, 0.2, 10});
    rotationTurn(65.5-45, 8000, 1, 1200, {0.016, 0, 0.08});
    motionProfile.moveDistance(48, 65.5-45, 1, {0.05, 0, 0.01}, {65, 0.1, 0.5, 10});
    intake.moveVoltage(12000);
    pros::delay(110);
    intake.moveVoltage(0);
    // motionProfile.moveDistance(-1, -150+315, 1, {0.017, 0, 0.04}, {60, 0.01, 0.5, 40});
    rotationTurn(-150+312, 8000, 1, 1200, {0.016, 0, 0.08});
    motionProfile.moveDistance(8, -150+312, 1, {0.02, 0, 0.04}, {60, 0.01, 0.2, 25});
    intake.moveVoltage(-12000);
    pros::delay(220);
    intake.moveVoltage(0);
    motionProfile.moveDistance(-5, -150+312, 1, {0.02, 0, 0.04}, {60, 0.01, 0.2, 25});
    intake.moveVoltage(12000);
    rotationTurn(113.5-45, 8000, 1, 1200, {0.019, 0, 0.08});
    pros::delay(50);
    motionProfile.moveDistance(24, 113.5-45, 1, {0.05, 0, 0.01}, {62, 0.1, 0.2, 10});
    pros::delay(175);
    intake.moveVoltage(0);
    motionProfile.moveDistance(-8.5, 113.5-45, 1, {0.05, 0, 0.01}, {60, 0.01, 0.2, 10});
    rotationTurn(171.5-45, 8000, 1, 1200, {0.016, 0, 0.08});
    toggleLeftWing();
    toggleRightWing();
    motionProfile.moveDistance(9, 171.5-45, 1, {0.05, 0, 0.01}, {60 , 0.1, 0.2, 10});
    rotationTurn(178, 8000, 1, 1200, {0.016, 0, 0.08});
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

void scoresix()
{
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

    toggleRightRearWing();
    pros::delay(100);

    motionProfile.moveDistance(13, 45, 2, {0.05, 0, 0.01}, {50, 0.1, 0.3, 40}, 500);

    //get ball out of corner
    rotationTurn(-45, 12000, 0.5, 800,{0.016, 0, 0.08});

   

    toggleRightRearWing();
    pros::delay(150);

    rotationTurn(30, 9500, 0.5, 800, {0.017, 0, 0.08}); //face net //INCREASE
    intake.moveVoltage(-12000);

    // pros::delay(100);

    //rams, also adjust these angles so that they are straighter and will have no difficulty pushing it in.
    motionProfile.moveDistance(22, 30, 2, {0.05, 0, 0.01}, {70, 0.1, 0.3, 70}, 650);
    
    pivotTurn(0, 9500, 0.5, 650, true, {0.016, 0, 0.02});
    motionProfile.moveDistance(-10.5, 0, 2, {0.05, 0, 0.01}, {60, 0.1, 0.3, 60}, 1500);

    // motionProfile.moveDistance(16, 18, 2, {0.05, 0, 0.01}, {70, 0.1, 0.3, 70}, 1500);

    driveGroup.moveVoltage(12000);
    pros::delay(500);
    driveGroup.moveVoltage(0);

    motionProfile.moveDistance(-9, 0, 2, {0.05, 0, 0.01}, {60, 0.1, 0.3, 60}, 1500);//move back so not touching

}

void scoreSixSafe() 
{
     motion_profile motionProfile;
    angleOffset = -35;

    openRightWing();

    pros::delay(350);

    closeRightWing();  

    intake.moveVoltage(12000);
    motionProfile.moveDistance(60, -35, 2, {0.05, 0, 0.01}, {65, 0.1, 0.3, 55}, 1500); //temp time out, will decrease 

    // pros::delay(500); 

    rotationTurn(90, 9500, 0.5, 750, {0.019, 0, 0.08}); //face net

    openLeftWing();
    openRightWing();

    motionProfile.moveDistance(16, 90, 2, {0.05, 0, 0.01}, {70, 0.1, 0.3, 60}, 1500); 
    intake.moveVoltage(0);
    motionProfile.moveDistance(16, 90, 2, {0.05, 0, 0.01}, {60, 0.1, 0.3, 60}, 1500); //rams

    closeLeftWing();
    closeRightWing();

    //this has to be right to the ball
    pivotTurn(0, 9500, 0.5, 750, true, {0.016, 0, 0.02}); //INCREASE //delay was 1000 WEIRD PAUSE

    motionProfile.moveDistance(-11, 0, 2,{0.05, 0, 0.01}, {50, 0.1, 0.3, 50}, 750);//-13

    rotationTurn(-85, 9500, 0.5, 500, {0.019, 0, 0.08}); //turn to ball //INCREASE

    intake.moveVoltage(12000);

    //reset pos???? maybe better to not touch the bar
    motionProfile.moveDistance(22, -85, 2, {0.05, 0, 0.01}, {50, 0.1, 0.3, 40}, 1500);
    intake.moveVoltage(0);

    motionProfile.moveDistance(-15, -85, 2, {0.05, 0, 0.01}, {50, 0.1, 0.3, 50}, 1500); 

    //might have to purely stop with timeout or use drivegroup
    pivotTurn(-15, 9500, 0.5, 650, false, {0.016, 0, 0.02}); //test this one now, see if anything changes 

    motionProfile.moveDistance(-29, -15, 2, {0.05, 0, 0.01}, {60, 0.1, 0.3, 40}, 1500);//INCREASE //WATCH FOR THIS!

    

    //face side of net
    rotationTurn(33, 9500, 0.5, 500, {0.019, 0, 0.08}); //INCREASE

    intake.moveVoltage(-12000);
    pros::delay(550);

    rotationTurn(-87, 9500, 0.5, 750, {0.019, 0, 0.08}); //INCREASE

    intake.moveVoltage(12000);

    //MAKE SURE THIS DOESN'T CROSS
    motionProfile.moveDistance(32, -87, 2,{0.05, 0, 0.01}, {60, 0.1, 0.3, 40}, 2000);

    motionProfile.moveDistance(-29, -87, 2,{0.05, 0, 0.01}, {60, 0.1, 0.3, 40}, 2000); 
    intake.moveVoltage(0);

    // back ram------
    motionProfile.moveDistance(-25, -87, 2,{0.05, 0, 0.01}, {60, 0.1, 0.3, 40}); 

    intake.moveVoltage(0);

    pivotTurn(-135, 9500, 0.5, 750, true, {0.016, 0, 0.02}); 
    // rotationTurn(-135, 9500, 0.5, 750, {0.019, 0, 0.08});//INCREASE
    toggleLeftRearWing();
    pros::delay(100);

    motionProfile.moveDistance(-13, -135, 1,{0.05, 0, 0.01}, {50, 0.1, 0.3, 20} );

    rotationTurn(-180, 12000, 1, 1000, {0.019, 0, 0.08});

    pros::delay(100);

    toggleLeftRearWing();

    rotationTurn(-150, 9500, 0.5, 800, {0.019, 0, 0.08}); //face net //INCREASE

    // pros::delay(100);

    //rams
    motionProfile.moveDistance(-20, -150, 2, {0.05, 0, 0.01}, {70, 0.1, 0.3, 70}, 550);
    
    motionProfile.moveDistance(11, -180, 2, {0.05, 0, 0.01}, {60, 0.1, 0.3, 60});

    rotationTurn(0, 9000, 1, 1000, {0.019, 0, 0.08});
    intake.moveVoltage(-12000);
    motionProfile.moveDistance(16, 0, 2, {0.05, 0, 0.01}, {70, 0.1, 0.3, 70});
}


void soloWP() // need to update 
{

    motion_profile motionProfile;

    // FACE WALL ON WALL BETWEEN 3-4TH TOOTH AWAY FROM MATCHLOAD BAR, INTAKE TOUCHING WALL WITHOUT DEPLOY
    toggleHang();
    motionProfile.moveDistance(-26.5, 0, 1, {0.05, 0, 0.01}, {35, 0.3, 0.5, 10});
    toggleHang();
    // toggleRightRearWing();
    pivotTurn(55, 5500, 0.5, 1000, false, {0.017, 0, 0.02});
    pros::delay(600);
    motionProfile.moveDistance(-20, 55, 1, {0.025, 0, 0.01}, {30, 0.3, 1, 10});
    pros::delay(200);
    pivotTurn(90, 5500, 0.5, 1000, false, {0.017, 0, 0.02});
    pros::delay(600);
    motionProfile.moveDistance(-7.5, 90, 1, {0.03, 0, 0.01}, {25, 0.3, 0.5, 10}, 500);
    pros::delay(300);
    toggleShooter();
    pros::delay(300);
    toggleShooter();
    pros::delay(300);
    toggleShooter();
    pros::delay(300);
    gyro.reset(true);
    angleOffset = 90;
    motionProfile.moveDistance(4, 90, 1, {0.05, 0, 0.01}, {65, 0.1, 0.3, 50});
    rotationTurn(38.5, 9500, 1, 500, {0.018, 0, 0.08});
    motionProfile.moveDistance(39, 38.5, 1, {0.05, 0, 0.01}, {65, 0.1, 0.3, 50});
    rotationTurn(-45, 9500, 1, 500, {0.016, 0, 0.08});
    toggleRightRearWing();
    rotationTurn(-135, 9500, 1, 300, {0.013, 0, 0.08});
    toggleRightRearWing();
    rotationTurn(-45, 9500, 1, 500, {0.016, 0, 0.08});
    motionProfile.moveDistance(12, -45, 1, {0.05, 0, 0.01}, {65, 0.1, 0.3, 50});
    gyro.reset();
    angleOffset = -45;
    rotationTurn(-90, 9500, 1, 500, {0.018, 0, 0.08});
    intake.moveVoltage(-12000);
    motionProfile.moveDistance(26, -90, 1, {0.05, 0, 0.01}, {65, 0.1, 0.3, 50});
    
}

void winpointAuton()
{
    // setup against wall and matchload bar
    motion_profile motionProfile;

    /*--Deploy intake--*/
    // catapult.moveVoltage(12000);
    toggleHang();
    pros::delay(500);
    intake.moveVoltage(12000);
    // pros::delay(125);
    // catapult.moveVoltage(0);
    pros::delay(500);
    intake.moveVoltage(0);
    toggleHang();

    /*--Destroy--*/
    motionProfile.moveDistance(20.5, 0, 1, {0.0175, 0, 0.01}, {65, 0.1, 0.3, 10});
    rotationTurn(30, 8000, 1, 300, {0.016, 0, 0.08});
    motionProfile.moveDistance(10, 30, 1, {0.0175, 0, 0.01}, {60, 0.1, 0.3, 10});
    rotationTurn(0, 8000, 1, 300, {0.016, 0, 0.08});
    motionProfile.moveDistance(11, 0, 1, {0.0175, 0, 0.01}, {40, 0.01, 0.3, 30});
    toggleLeftWing();
    rotationTurn(90, 8000, 1, 1200, {0.016, 0, 0.08}); // test
    motionProfile.moveDistance(26, 90, 1, {0.0175, 0, 0.01}, {65, 0.1, 0.3, 10}, 1000);
    toggleLeftWing();
    motionProfile.moveDistance(-12, 90, 1, {0.0175, 0, 0.01}, {55, 0.1, 0.3, 10});
    rotationTurn(-90, 8000, 1, 1200, {0.016, 0, 0.08});
    motionProfile.moveDistance(7.5, -90, 1, {0.0175, 0, 0.01}, {40, 0.1, 0.3, 30}); // alliance triball pushin
    intake.moveVoltage(-12000);
    pros::delay(200);
    driveGroup.moveVoltage(12000);
    pros::delay(400);
    intake.moveVoltage(0);

    /*--Get to matchload area--*/
    motionProfile.moveDistance(-16, -90, 1, {0.0175, 0, 0.01}, {50, 0.1, 0.3, 10});
    rotationTurn(-150, 8000, 1, 1200, {0.016, 0, 0.08});
    motionProfile.moveDistance(46, -150, 1, {0.0175, 0, 0.01}, {65, 0.1, 0.3, 10}); // trying to get the triball out
    // somehow works:
    toggleRightRearWing();
    // toggleMatchload(); FIX
    pros::delay(150);
    driveLeftGroup.moveVoltage(-7500);
    driveRightGroup.moveVoltage(7500);
    pros::delay(650); // flying
    driveLeftGroup.moveVoltage(0);
    driveRightGroup.moveVoltage(0);
    
    toggleRightRearWing();

    /*--Winpoint ending--*/
    rotationTurn(136.5, 8000, 1, 1200, {0.016, 0, 0.08});
    motionProfile.moveDistance(8, 136.5, 1, {0.0175, 0, 0.01}, {40, 0.01, 0.3, 10});
    rotationTurn(80, 8000, 1, 1200, {0.016, 0, 0.08});
    pros::delay(75);
    intake.moveVoltage(-12000);
    motionProfile.moveDistance(27.75, 80, 1, {0.0175, 0, 0.01}, {65, 0.01, 0.3, 20});
    driveGroup.moveVoltage(0);
    intake.moveVoltage(0);

    /*--Destroy ending--*/
    //     rotationTurn(30, 8000, 1, 1200, {0.016, 0, 0.08});
    //     motionProfile.moveDistance(10, 136.5, 1, {0.0175, 0, 0.01}, {30, 0.01, 0.3, 3});
    //     rotationTurn(110, 8000, 1, 1200, {0.016, 0, 0.08});
    //     motionProfile.moveDistance(6, 110, 1, {0.0175, 0, 0.01}, {30, 0.01, 0.3, 3});
}

void wpAutonsafe(){
    // set up with the backwheel on the edge of the 3rd tile tooth thing and with the back sloping until you see the corner of the 2nd tile to the right
    //it's jank, but ill show it to you later
    motion_profile motionProfile;

    /*--Deploy intake--*/
    angleOffset = 12;
    toggleHang();
    pros::delay(500);
    intake.moveVoltage(12000);
    pros::delay(500);
    intake.moveVoltage(0);
    toggleHang();

    /*--Destroy--*/
    
    motionProfile.moveDistance(-41, 12, 1, {0.0175, 0, 0.01}, {60, 0.1, 0.3, 10});
    rotationTurn(90, 8000, 1, 500, {0.016, 0, 0.08});
    intake.moveVoltage(-12000);
    pros::delay(200);
    intake.moveVoltage(0);
    toggleLeftWing();
    rotationTurn(-80, 8000, 1, 1200, {0.016, 0, 0.08});
    motionProfile.moveDistance(24, -80, 1, {0.0175, 0, 0.01}, {65, 0.1, 0.3, 10}, 1000);
    toggleLeftWing();
    toggleLeftRearWing();
    motionProfile.moveDistance(-38, -90, 1, {0.0175, 0, 0.01}, {60, 0.1, 0.3, 10}, 1500);
    motionProfile.moveDistance(16, -90, 1, {0.0175, 0, 0.01}, {40, 0.1, 0.3, 30}); 
    toggleLeftRearWing();

    /*--Get to matchload area--*/
    rotationTurn(30, 8000, 1, 1200, {0.016, 0, 0.08});
    motionProfile.moveDistance(50, 30, 1, {0.0175, 0, 0.01}, {65, 0.1, 0.3, 10}); // trying to get the triball out
    // somehow works:
    toggleRightRearWing();
    // toggleMatchload(); FIX
    pros::delay(150);
    driveLeftGroup.moveVoltage(-7500);
    driveRightGroup.moveVoltage(7500);
    pros::delay(650); // flying
    driveLeftGroup.moveVoltage(0);
    driveRightGroup.moveVoltage(0);
    
    toggleRightRearWing();

    /*--Winpoint ending--*/
    rotationTurn(-40, 8000, 1, 1200, {0.016, 0, 0.08});
    motionProfile.moveDistance(7, -40, 1, {0.0175, 0, 0.01}, {40, 0.01, 0.3, 10}, 1000);
    rotationTurn(-96, 8000, 1, 800, {0.016, 0, 0.08});
    pros::delay(75);
    intake.moveVoltage(-12000);
    motionProfile.moveDistance(30.5, -96, 1, {0.0175, 0, 0.01}, {65, 0.01, 0.3, 20});
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