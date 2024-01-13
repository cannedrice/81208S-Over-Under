#include "main.h"

#define M_PI 3.1415926535897932384626433832795
#define CIRCUMFERENCE 3.25 * M_PI
#define ENCODER_TICKS 360
#define GEAR_RATIO 4 / 6

/**
 * @brief rotationTurn
 * turns on the spot using both wheels
 * 
 * @param angle angle to be turned to
 * @param turnVoltage how fast the motors should spin, in millivolts
 * @param momentum tolerance 
 * @param timeout longest time the function can run for, in milliseconds
 * @param values pid values
 */
void rotationTurn(double angle, double turnVoltage, double momentum, uint32_t timeout, PIDvalues values){
    //setup variables
    uint32_t startTime = pros::millis();
    PID_controller turnController(values);
    turnController.SetTarget(angle);
    double startingAngle = getIMU();
    //have the loop include timeout and angle checking
    while(abs(angle - getIMU()) > momentum && timeout > pros::millis() - startTime){
        double outputValue = turnController.Calculate(getIMU());
        moveLeftGroup(turnVoltage * outputValue);
        moveRightGroup(turnVoltage * outputValue * (-1));
        pros::lcd::print(1, "Current angle: %f", getIMU());
        pros::delay(10);
    }
    moveLeftGroup(0);
    moveRightGroup(0);
}

/**
 * @brief pivotTurn
 * turns using 1 wheel
 * 
 * @param angle angle to be turned to
 * @param turnVoltage voltage to be spun at, in millivolts
 * @param momentum  tolerance
 * @param timeout maximum time the function can run for, in milliseconds
 * @param isLeft if we are using the left wheel or not
 * @param values pid values
 */
void pivotTurn(double angle, double turnVoltage, double momentum, uint32_t timeout, bool isLeft, PIDvalues values){
    PID_controller turnController(values);
    uint32_t startTime = pros::millis();
    turnController.SetTarget(angle);
    double startingAngle = getIMU();
    //angle checking
    while((abs(angle - getIMU()) > momentum) && (timeout > pros::millis() - startTime)){
        double outputValue = turnController.Calculate(getIMU());
        //only run 1 wheel based on configuration
        if(isLeft == true){
            moveLeftGroup(turnVoltage * outputValue);
        } else{
            moveRightGroup(turnVoltage * outputValue * (-1));
        }
        pros::lcd::print(1, "Current angle: %f", getIMU());
        pros::delay(10);
    }
    moveLeftGroup(0);
    moveRightGroup(0);
}

/**
 * @brief travelTurn
 * travels a certain distance in an arc
 * 
 * @param distance distance to be traveled on circumference
 * @param driveVoltage the driving power, in millivolts
 * @param angle final angle the bot reaches
 * @param turnVoltage the turning power, in millivolts
 * @param momentum the tolerance for angle, in degree
 * @param timeout  maxmimum time the function can run for
 * @param values  pid values
 */

void travelTurn(double distance, double driveVoltage, double angle, double turnVoltage, double momentum, uint32_t timeout, PIDvalues values){
    //have to keep track of how far everything travels, and adjust target based on % of path completed
    //setup things
    uint32_t startTime = pros::millis();
    int isForward = squiggles::sgn(distance);
    PID_controller turnController(values);
    turnController.SetTarget(angle);
    double startingAngle = getIMU();
    double distanceTraveled = 0.0;
    
    double leftStart = getAverageLeftRotation() / ENCODER_TICKS * CIRCUMFERENCE * GEAR_RATIO;
    double rightStart = getAverageRightRotation() / ENCODER_TICKS * CIRCUMFERENCE * GEAR_RATIO;
    double rightCurrent = rightStart;
    double leftCurrent = leftStart;
    //timeout and angle checking
    //the way it works is its a normal drive distance, but we change the angle constantly as we drive
    while(abs(angle - getIMU()) > momentum && timeout > pros::millis() - startTime){
        leftCurrent = getAverageLeftRotation() / ENCODER_TICKS * CIRCUMFERENCE * GEAR_RATIO;
        rightCurrent = getAverageRightRotation() / ENCODER_TICKS * CIRCUMFERENCE * GEAR_RATIO;
        distanceTraveled = leftCurrent + rightCurrent - leftStart - rightStart;

        //calculate the needed heading based on % of path completed
        double currentTarget = (angle - startingAngle) * (distanceTraveled / distance) /*demical of distance traveled*/ + startingAngle;
        //update target as we drive
        turnController.SetTarget(currentTarget);
        double outputValue = turnController.Calculate(getIMU());
        //regular pid movement, just with adjusted heading throughout the loop
        moveLeftGroup(turnVoltage * (+outputValue) * isForward+ driveVoltage * isForward);
        moveRightGroup(turnVoltage * (-outputValue) * isForward + driveVoltage * isForward);
        //pros::lcd::print(1, "Current angle: %f", getIMU());
        //pros::lcd::print(2, "Distance traveled: %f", getIMU());
        pros::delay(20);
    }
    moveLeftGroup(0);
    moveRightGroup(0);
    pros::delay(10);
}