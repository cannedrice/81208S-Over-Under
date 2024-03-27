#include "main.h"
#include "subsystems/drvlib.hpp"

double x = 0; //x and y only used for odom
double y = 0;


/**
 * @brief resetRobotPos
 * resets robot position to 0, 0
 * 
 */
void resetRobotPos(){
    x = 0;
    y = 0;
    angleOffset = 0;
}

/**
 * @brief updates the x, y, theta adjustment values
 * 
 * @param currX  x value to be updated to
 * @param currY  y value to be updated to
 * @param theta heading the robot is to be set to
 */
void resetRobotPos(double currX, double currY, double theta){
    x = currX;
    y = currY;
    thetaAdjustment = theta;
}

/**
 * @brief estimatePositionTask
 * estimates the position of the robot on a regular cycle given readings from 1 horizontal and 1 vertical tracking wheel
 * 
 * @param param 
 */
void estimatePositionTask(void *param){
    //init good values
    double verticalDelta = 0;
    double horizontalDelta = 0;
    
    double verticalEncReading = getVerticalRotation();
    double horizontalEncReading = getHorizontalRotation();
    double lastVerticalEncReading = verticalEncReading;
    double lastHorizontalEncReading = horizontalEncReading;

    double gyroReading = getIMU();

    while(true){
        verticalEncReading = getVerticalRotation();
        horizontalEncReading = getHorizontalRotation();
        
        //convert the deltas into inches
        double verticalWheelDelta = (verticalEncReading - lastVerticalEncReading) / TICKS * VERTICALCIRC;
        double horizontalWheelDelta = (horizontalEncReading - lastHorizontalEncReading) / TICKS * HORIZONTALCIRC;
        //pros::lcd::print(3, "gyro = %f", getOdomIMU());
        gyroReading = getIMU() / 180 * M_PI;

        //calculate dX and dY using g10 math (i remember that)
        double dX =  cos(gyroReading) * verticalWheelDelta + sin(gyroReading) * horizontalWheelDelta;
        double dY = cos(gyroReading) * horizontalWheelDelta + sin(gyroReading) * verticalWheelDelta;
        //double gdX = (dX * cosMA) + (dY * -sinMA);
        //double gdY = (dX * sinMA) + (dY * cosMA);
        x += dX;
        y += dY;

        pros::lcd::print(1, "x = %f", x);
        pros::lcd::print(2, "y = %f", y);
        

        //update lastReadings
        lastVerticalEncReading = verticalEncReading;
        lastHorizontalEncReading = horizontalEncReading;
        pros::delay(20);
    }
}

/**
 * @brief startOdomTask
 * regulates odometry and timing 
 * 
 */
void startOdomTask(){
    resetGyro();
	resetRobotPos();
    pros::delay(1000);
    pros::Task odometry_task(estimatePositionTask, (void *)0, "odom task");
}

/**
 * @brief 
 * 
 * @param targetX the targeted x coordinate 
 * @param targetY the targeted y coordinate
 * @param forward if the bot approaches final position facing forward or backward
 * @param turnValues pid turn values
 * @param movementValues pid movement values
 * @param data motion profiling data
 */
void moveToPoint(double targetX, double targetY, double offset, bool forward, PIDvalues turnValues, PIDvalues movementValues, MotionData data) {
    //first calculate heading and distance between robot and target
    double deltaX = targetX - x;
    double deltaY = targetY - y;
    //find the acute target radian, not adjusted for robot positioning 
	double heading = atan(abs(deltaY/deltaX));

    //find distance 
    double distance = sqrt(pow(deltaX, 2) + pow(deltaY, 2));
	
	//find what quadrant the robot should be pointing in, adjust heading accordingly
	if(deltaX < 0 && deltaY > 0) {
        heading += 1.0/2.0 * M_PI;
    } else if (deltaX < 0 && deltaY < 0){
        heading += M_PI;
    } else if (deltaX > 0 && deltaY < 0) {
        heading += 3.0/2.0 * M_PI;
    }

    heading = heading / M_PI * 180; //convert to degrees
    if(forward == false) { //check for forward/backward
        heading += M_PI;
        if(M_PI >= 2 * M_PI){
            heading -= 2*M_PI;
        }
        distance = -distance;
    }
    
	//+/- angle to closest one that the robot needs 
    //find tree closest angles, and pick that one
    //note that heading is always positive
    int startingAngle = getIMU();
    startingAngle = (startingAngle % 360 + 360)%360; //force positive 
    double turnAmount;
    if(abs(heading - startingAngle) > 180) {
        //this means we turn counter clockwise by (target - startingAngle - 360)
        turnAmount = heading - (double)startingAngle;
    } else {
        //this means we turn clockwise by target - startingAngle
        turnAmount = heading - (double)startingAngle - 360;
    }
    double target = getIMU() + turnAmount;
    motion_profile motionProfile;
    //turn to target
    rotationTurn(target, 6000, 3, 1000, turnValues);
    //drive to final target
    motionProfile.moveDistance(distance, target, offset, movementValues, data);
}