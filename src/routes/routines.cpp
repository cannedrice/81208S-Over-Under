#include "main.h"

// 450 chassis has max speed of ~76.6 inches/sec

void tests()
{
}

void qualCloseside()
{
    // setup against wall and matchload bar
    motion_profile motionProfile;

    /*--Deploy intake--*/
    angleOffset = 45;
    toggleHang();
    pros::delay(400);
    toggleHang();

    /*--Alliance ball--*/
    motionProfile.moveDistance(-10, 45, 1, {dis[0], dis[1], dis[2]}, {60, 0.05, 0.2, 40});
    pivotTurn(90, 9500, 0.5, 800, false, {piv[0], piv[1], piv[2]});
    motionProfile.moveDistance(-4, 90, 1, {dis[0], dis[1], dis[2]}, {60, 0.05, 0.2, 40});
    pros::delay(200);
    driveGroup.moveVoltage(-10000);
    pros::delay(300);
    driveGroup.moveVoltage(0);
    motionProfile.moveDistance(9, 90, 1, {dis[0], dis[1], dis[2]}, {60, 0.05, 0.2, 40});
    pivotTurn(40, 9500, 0.5, 800, false, {piv[0], piv[1], piv[2]});
    motionProfile.moveDistance(8, 40, 1, {dis[0], dis[1], dis[2]}, {60, 0.05, 0.2, 40});

    pros::delay(150);
    driveLeftGroup.moveVoltage(-7500);
    driveRightGroup.moveVoltage(7500);
    pros::delay(350); // flying
    driveLeftGroup.moveVoltage(0);
    driveRightGroup.moveVoltage(0);

    rotationTurn(35, 9500, 1, 1200, {rot[0], rot[1], rot[2]});
    intake.moveVoltage(-12000);
    motionProfile.moveDistance(11.5, 35, 1, {dis[0], dis[1], dis[2]}, {60, 0.05, 0.2, 40});
    pivotTurn(0, 9500, 0.5, 800, false, {piv[0], piv[1], piv[2]});
    motionProfile.moveDistance(21.5, 0, 1, {dis[0], dis[1], dis[2]}, {60, 0.05, 0.2, 40});
}

void qualCloseside2()
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
    motionProfile.moveDistance(-41, 12, 1, {0.0175, 0, 0.01}, {60, 0.1, 0.3, 25});
    rotationTurn(90, 8000, 1, 500, {0.016, 0, 0.08});
    intake.moveVoltage(-12000);
    pros::delay(200);
    intake.moveVoltage(0);
    toggleLeftWing();
    rotationTurn(-80, 8000, 1, 1200, {0.016, 0, 0.08});
    motionProfile.moveDistance(24, -80, 1, {0.0175, 0, 0.01}, {65, 0.1, 0.3, 25}, 1000);
    toggleLeftWing();

    motionProfile.moveDistance(-38, -90, 1, {0.0175, 0, 0.01}, {60, 0.1, 0.3, 25}, 1500);
    motionProfile.moveDistance(16, -90, 1, {0.0175, 0, 0.01}, {40, 0.1, 0.3, 30});

    /*--Get to matchload area--*/
    rotationTurn(30, 8000, 1, 1200, {0.016, 0, 0.08});
    motionProfile.moveDistance(45.25, 30, 1, {0.0175, 0, 0.01}, {65, 0.1, 0.3, 10});

    pros::delay(150);
    driveLeftGroup.moveVoltage(-7500);
    driveRightGroup.moveVoltage(7500);
    pros::delay(650); // flying
    driveLeftGroup.moveVoltage(0);
    driveRightGroup.moveVoltage(0);

    /*--Winpoint ending--*/
    rotationTurn(-39, 8000, 1, 1200, {rot[0], rot[1], rot[2]});
    motionProfile.moveDistance(7.75, -39, 1, {0.0175, 0, 0.01}, {40, 0.01, 0.3, 10}, 1000);
    rotationTurn(-93, 8000, 1, 800, {rot[0], rot[1], rot[2]});
    pros::delay(75);
    intake.moveVoltage(-12000);
    motionProfile.moveDistance(31.75, -93, 1, {0.0175, 0, 0.01}, {65, 0.01, 0.4, 20}); // tounches bar
    driveGroup.moveVoltage(0);
    intake.moveVoltage(0);

    /*--Destroy ending--*/
    //     rotationTurn(30, 8000, 1, 1200, {rot[0], rot[1], rot[2]});
    //     motionProfile.moveDistance(10, 136.5, 1, {0.0175, 0, 0.01}, {30, 0.01, 0.3, 3});
    //     rotationTurn(110, 8000, 1, 1200, {rot[0], rot[1], rot[2]});
    //     motionProfile.moveDistance(6, 110, 1, {0.0175, 0, 0.01}, {30, 0.01, 0.3, 3});
}

void elimCloseside()
{
    // same setup as regular winpoint, but intake facing front
    motion_profile motionProfile;

    /*--Deploy intake--*/
    angleOffset = -78;
    toggleHang();
    toggleLeftWing();
    intake.moveVoltage(12000);
    pros::delay(400);
    toggleHang();
    toggleLeftWing();

    motionProfile.moveDistance(42, -78, 1, {dis[0], dis[1], dis[2]}, {70, 0.05, 0.2, 60});
    pros::delay(1000);
    motionProfile.moveDistance(-37, -78, 1, {dis[0], dis[1], dis[2]}, {70, 0.05, 0.2, 60});
    pivotTurn(45, 9500, 0.5, 800, false, {piv[0], piv[1], piv[2]});
    motionProfile.moveDistance(-10, 45, 1, {dis[0], dis[1], dis[2]}, {65, 0.05, 0.2, 55});
    pivotTurn(90, 9500, 0.5, 800, false, {piv[0], piv[1], piv[2]});
    motionProfile.moveDistance(-4, 90, 1, {dis[0], dis[1], dis[2]}, {60, 0.05, 0.2, 40});
    pros::delay(200);
    driveGroup.moveVoltage(-10000);
    pros::delay(300);
    driveGroup.moveVoltage(0);
    motionProfile.moveDistance(9, 90, 1, {dis[0], dis[1], dis[2]}, {65, 0.05, 0.2, 55});
    pivotTurn(40, 9500, 0.5, 800, false, {piv[0], piv[1], piv[2]});
    motionProfile.moveDistance(9, 40, 1, {dis[0], dis[1], dis[2]}, {65, 0.05, 0.2, 55});

    pros::delay(150);
    driveLeftGroup.moveVoltage(-7500);
    driveRightGroup.moveVoltage(7500);
    pros::delay(350); // flying
    driveLeftGroup.moveVoltage(0);
    driveRightGroup.moveVoltage(0);

    rotationTurn(35, 9500, 1, 1200, {rot[0], rot[1], rot[2]});
    intake.moveVoltage(-12000);
    motionProfile.moveDistance(11.5, 35, 1, {dis[0], dis[1], dis[2]}, {65, 0.05, 0.2, 55});
    pivotTurn(0, 9500, 0.5, 800, false, {piv[0], piv[1], piv[2]});
    motionProfile.moveDistance(21.5, 0, 1, {dis[0], dis[1], dis[2]}, {60, 0.05, 0.2, 40});
}

void elimCloseside2()
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

    motionProfile.moveDistance(42, -78, 1, {dis[0], dis[1], dis[2]}, {70, 0.05, 0.2, 60});
    toggleHang();
    pros::delay(200);
    motionProfile.moveDistance(-2, -78, 1, {dis[0], dis[1], dis[2]}, {65, 0.05, 0.2, 55});
    rotationTurn(0, 9500, 1, 1200, {rot[0], rot[1], rot[2]});
    toggleLeftWing();
    motionProfile.moveDistance(19, 0, 1, {dis[0], dis[1], dis[2]}, {65, 0.05, 0.2, 55}, 600);
    toggleLeftWing();
    intake.moveVoltage(-12000);
    motionProfile.moveDistance(-3, 0, 1, {dis[0], dis[1], dis[2]}, {65, 0.05, 0.2, 55}, 500);
    pros::delay(500);
    intake.moveVoltage(0);
    motionProfile.moveDistance(-20, 0, 1, {dis[0], dis[1], dis[2]}, {65, 0.05, 0.2, 55}, 1000);
}


void qualFarside()
{
    motion_profile motionProfile;
    // edge of chassis on middle of second tooth
    angleOffset = 0;
    toggleHang();
    pros::delay(350);
    toggleHang();

    intake.moveVoltage(12000);
    motionProfile.moveDistance(6, 0, 2, {dis[0], dis[1], dis[2]}, {65, 0.05, 0.1, 60}, 750);
    pros::delay(200);

    motionProfile.moveDistance(-21.75, 0, 2, {dis[0], dis[1], dis[2]}, {67, 0.05, 0.2, 60}, 1500);
    pivotTurn(-33, 9500, 0.5, 750, true, {piv[0], piv[1], piv[2]});

    motionProfile.moveDistance(-11.5, -33, 2, {dis[0], dis[1], dis[2]}, {69, 0.05, 0.2, 60}, 1500);
    pivotTurn(-60, 9500, 0.5, 750, true, {piv[0], piv[1], piv[2]});

    motionProfile.moveDistance(2.5, -60, 2, {dis[0], dis[1], dis[2]}, {65, 0.05, 0.2, 60}, 1500);
    motionProfile.moveDistance(-6.5, -60, 2, {dis[0], dis[1], dis[2]}, {70, 0.05, 0.2, 60}, 1500);
    pivotTurn(-85, 9500, 0.5, 750, true, {piv[0], piv[1], piv[2]});
    motionProfile.moveDistance(-4, -85, 2, {dis[0], dis[1], dis[2]}, {65, 0.05, 0.2, 60}, 1500);
    driveGroup.moveVoltage(-12000);
    pros::delay(500);
    driveGroup.moveVoltage(0);
    motionProfile.moveDistance(7, -90, 2, {dis[0], dis[1], dis[2]}, {70, 0.05, 0.2, 60}, 1500);
    pivotTurn(32, 9500, 0.5, 1200, true, {piv[0], piv[1], piv[2]});
    motionProfile.moveDistance(17, 35, 2, {dis[0], dis[1], dis[2]}, {70, 0.05, 0.2, 60}, 1500);
    pivotTurn(150, 9500, 0.5, 1200, true, {piv[0], piv[1], piv[2]});
    intake.moveVoltage(-12000);
    pros::delay(200);
    intake.moveVoltage(12000);
    motionProfile.moveDistance(-5, 150, 2, {dis[0], dis[1], dis[2]}, {65, 0.05, 0.2, 60}, 1500);
    rotationTurn(15, 9500, 1, 1200, {rot[0], rot[1], rot[2]});
    motionProfile.moveDistance(12, 17, 2, {dis[0], dis[1], dis[2]}, {70, 0.05, 0.2, 60}, 1500);
    pros::delay(200);
    motionProfile.moveDistance(-6, 15, 2, {dis[0], dis[1], dis[2]}, {65, 0.05, 0.2, 60}, 1500);
    rotationTurn(132, 10000, 1, 600, {0.015, 0, 0.06});
    motionProfile.moveDistance(8, 137, 2, {dis[0], dis[1], dis[2]}, {70, 0.05, 0.2, 60}, 1500);
    intake.moveVoltage(-12000);
    pros::delay(250);
    intake.moveVoltage(12000);
    rotationTurn(43, 10000, 1, 600, {rot[0], rot[1], rot[2]});
    motionProfile.moveDistance(29.25, 45, 2, {dis[0], dis[1], dis[2]}, {70, 0.05, 0.2, 60}, 1200);
    motionProfile.moveDistance(-5.5, 45, 2, {dis[0], dis[1], dis[2]}, {65, 0.05, 0.2, 60}, 1500);
    rotationTurn(110, 10000, 1, 600, {rot[0], rot[1], rot[2]});
    pivotTurn(175, 10000, 0.5, 800, true, {piv[0], piv[1], piv[2]});
    toggleLeftWing();
    toggleRightWing();
    motionProfile.moveDistance(4, 175, 2, {dis[0], dis[1], dis[2]}, {70, 0.05, 0.2, 60}, 1500);
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
    // motionProfile.moveDistance(60, -35, 2, {dis[0], dis[1], dis[2]}, {65, 0.1, 0.3, 55}, 1500); //temp time out, will decrease

    // // pros::delay(500);

    // rotationTurn(90, 9500, 0.5, 750, {rot[0], rot[1], rot[2]}); //face net

    // openLeftWing();
    // openRightWing();

    // intake.moveVoltage(-12000);
    // pros::delay(100);

    // motionProfile.moveDistance(16, 90, 2, {dis[0], dis[1], dis[2]}, {70, 0.1, 0.3, 60}, 1500);
    // intake.moveVoltage(0);
    // motionProfile.moveDistance(16, 90, 2, {dis[0], dis[1], dis[2]}, {60, 0.1, 0.3, 60}, 1500); //rams
    // driveGroup.moveVoltage(-12000);
    // pros::delay(250);
    // driveGroup.moveVoltage(0);

    // closeLeftWing();
    // closeRightWing();

    // //this has to be right to the ball
    // pivotTurn(0, 9500, 0.5, 750, true, {piv[0], piv[1], piv[2]}); //INCREASE //delay was 1000 WEIRD PAUSE

    // motionProfile.moveDistance(-12, 0, 2,{dis[0], dis[1], dis[2]}, {60, 0.1, 0.3, 50}, 750);//-13

    // rotationTurn(-85, 9500, 0.5, 500, {rot[0], rot[1], rot[2]}); //turn to ball //INCREASE

    // intake.moveVoltage(12000);

    // //reset pos???? maybe better to not touch the bar
    // motionProfile.moveDistance(22, -85, 2, {dis[0], dis[1], dis[2]}, {50, 0.1, 0.3, 40}, 1500);

    // motionProfile.moveDistance(-15, -85, 2, {dis[0], dis[1], dis[2]}, {50, 0.1, 0.3, 50}, 1500);

    // //might have to purely stop with timeout or use drivegroup
    // pivotTurn(-15, 9500, 0.5, 650, false, {piv[0], piv[1], piv[2]}); //test this one now, see if anything changes

    // motionProfile.moveDistance(-29, -15, 2, {dis[0], dis[1], dis[2]}, {60, 0.1, 0.3, 40}, 1500);//INCREASE //WATCH FOR THIS!

    // //face side of net
    // rotationTurn(33, 9500, 0.5, 500, {rot[0], rot[1], rot[2]}); //INCREASE

    // intake.moveVoltage(-12000);
    // pros::delay(350);
    // intake.moveVoltage(0);
    // rotationTurn(-87, 9500, 0.5, 750, {rot[0], rot[1], rot[2]}); //INCREASE

    // intake.moveVoltage(12000);

    // //MAKE SURE THIS DOESN'T CROSS
    // motionProfile.moveDistance(32, -87, 2,{dis[0], dis[1], dis[2]}, {60, 0.1, 0.3, 40}, 2000);

    // motionProfile.moveDistance(-29, -87, 2,{dis[0], dis[1], dis[2]}, {60, 0.1, 0.3, 40}, 2000);
    // intake.moveVoltage(0);

    // //foward ram-------
    // rotationTurn(45, 9500, 0.5, 750, {rot[0], rot[1], rot[2]});//INCREASE

    // // toggleRightRearWing();
    // // pros::delay(100);

    // // motionProfile.moveDistance(13, 45, 2, {dis[0], dis[1], dis[2]}, {50, 0.1, 0.3, 40}, 500);

    // //get ball out of corner
    // // rotationTurn(-45, 12000, 0.5, 800,{rot[0], rot[1], rot[2]});

    // // toggleRightRearWing();
    // // pros::delay(150);

    // rotationTurn(30, 9500, 0.5, 800, {rot[0], rot[1], rot[2]}); //face net //INCREASE
    // intake.moveVoltage(-12000);

    // pros::delay(100);

    // //rams, also adjust these angles so that they are straighter and will have no difficulty pushing it in.
    // motionProfile.moveDistance(22, 30, 2, {dis[0], dis[1], dis[2]}, {70, 0.1, 0.3, 70}, 650);

    // pivotTurn(0, 9500, 0.5, 650, true, {piv[0], piv[1], piv[2]});
    // motionProfile.moveDistance(-10.5, 15, 2, {dis[0], dis[1], dis[2]}, {60, 0.1, 0.3, 60}, 1500);

    // // motionProfile.moveDistance(16, 18, 2, {dis[0], dis[1], dis[2]}, {70, 0.1, 0.3, 70}, 1500);

    // driveGroup.moveVoltage(12000);
    // pros::delay(500);
    // driveGroup.moveVoltage(0);

    // motionProfile.moveDistance(-9, 0, 2, {dis[0], dis[1], dis[2]}, {60, 0.1, 0.3, 60}, 1500);//move back so not touching
}