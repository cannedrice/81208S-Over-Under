#include "main.h"

using namespace std;
#define M_PI 3.1415926535897932384626433832795
#define CIRCUMFERENCE 3.25 * M_PI
#define ENCODER_TICKS 360
#define GEAR_RATIO 2 / 3
#define GEARBOX 600

/**
 * @brief Construct a new motion profile::motion profile object
 *
 */
motion_profile::motion_profile()
{
}

/**
 * @brief Destroy the motion profile::motion profile object
 *
 */
motion_profile::~motion_profile()
{
}
/**
 * @brief moves a certain distance
 *
 * @param distance distance to travel
 * @param direction heading of the bot
 * @param values pid values to control the heading
 * @param Data motion profiling values for balancing
 */
void motion_profile::moveDistance(double distance, double direction, double offset, PIDvalues values, MotionData Data)
{

    _data = Data;
    // find out the accel slopes
    double accelSlope = _data.maxVelocity / _data.accelTime; // per second
    double decelSlope = _data.maxVelocity / _data.decelTime; // per second

    // double accelSlope = 60;
    // double decelSlope = 60;
    // starting and ending position of each wheel, in inches
    double leftStart = getAverageLeftRotation() / ENCODER_TICKS * CIRCUMFERENCE * GEAR_RATIO;
    double rightStart = getAverageRightRotation() / ENCODER_TICKS * CIRCUMFERENCE * GEAR_RATIO;

    // set target variables
    double leftTarget = getAverageLeftRotation() / ENCODER_TICKS * CIRCUMFERENCE * GEAR_RATIO + distance;
    double rightTarget = getAverageRightRotation() / ENCODER_TICKS * CIRCUMFERENCE * GEAR_RATIO + distance;
    double gyroReading = 0;
    double minVelocity = _data.minVelocity;
    double maxVelocity = _data.maxVelocity;
    double distanceRemaining = 69;

    PID_controller angleController(values);
    angleController.SetTarget(direction);

    while (distanceRemaining > offset)
    {
        pros::delay(10);
        // have to calculate speed and heading individually
        double leftCurrent = getAverageLeftRotation() / ENCODER_TICKS * CIRCUMFERENCE * GEAR_RATIO;
        double rightCurrent = getAverageRightRotation() / ENCODER_TICKS * CIRCUMFERENCE * GEAR_RATIO;

        double distanceTraveled = leftCurrent + rightCurrent - leftStart - rightStart; // how far robot has traveled ,in inches (averaged out)
        distanceTraveled /= 2;
        distanceTraveled = abs(distanceTraveled);

        distanceRemaining = rightTarget + leftTarget - rightCurrent - leftCurrent; // how far robot has to travel, in inches (averaged out)
        distanceRemaining /= 2;
        distanceRemaining = abs(distanceRemaining);
        // distanceTraveled + distanceRemaining should always equal distance

        // calculate the velocities of accel and decel slope, using formula |Vf| = Math.sqrt(|Vi|^2 + 2ad) & |Vi| = Math.sqrt(|Vf|^2 - 2ad);
        double accelVelocity = sqrt((2 * accelSlope * distanceTraveled));
        double decelVelocity = sqrt((2 * decelSlope * (distanceRemaining - offset))); // if you crashed, this is the issue

        double velocityPoints[4] = {minVelocity, accelVelocity, maxVelocity, decelVelocity};
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3 - i; j++)
            {
                if (velocityPoints[j] > velocityPoints[j + 1])
                {
                    // Swap elements if they are in the wrong order
                    double temp = velocityPoints[j];
                    velocityPoints[j] = velocityPoints[j + 1];
                    velocityPoints[j + 1] = temp;
                }
            }
        }
        double velocity = velocityPoints[1]; // we take the second lowest velocity out of the 4 we have generated

        // velocity is now in inches/second, convert into percentage of max steering (drive is 300rpm on 3.25s)
        double forwardVoltage = velocity / (CIRCUMFERENCE * GEARBOX * GEAR_RATIO / 60);
        // now that we have the velocity, we can worry about steering, use pid controller
        double steerVoltage = angleController.Calculate(getIMU());

        moveLeftGroup(((squiggles::sgn(distance) * forwardVoltage + steerVoltage) * 12000));
        moveRightGroup(((squiggles::sgn(distance) * forwardVoltage - steerVoltage) * 12000));

        // if((distanceRemaining - offset) < 1){
        //     break;
        // }
    }
    moveLeftGroup(0);
    moveRightGroup(0);
}

void motion_profile::moveDistance(double distance, double direction, double offset, PIDvalues values, MotionData Data, uint32_t timeout)
{
    // Start time for timeout
    uint32_t startTime = pros::millis();

    _data = Data;
    // find out the accel slopes
    double accelSlope = _data.maxVelocity / _data.accelTime; // per second
    double decelSlope = _data.maxVelocity / _data.decelTime; // per second

    // double accelSlope = 60;
    // double decelSlope = 60;
    // starting and ending position of each wheel, in inches
    double leftStart = getAverageLeftRotation() / ENCODER_TICKS * CIRCUMFERENCE * GEAR_RATIO;
    double rightStart = getAverageRightRotation() / ENCODER_TICKS * CIRCUMFERENCE * GEAR_RATIO;

    // set target variables
    double leftTarget = getAverageLeftRotation() / ENCODER_TICKS * CIRCUMFERENCE * GEAR_RATIO + distance;
    double rightTarget = getAverageRightRotation() / ENCODER_TICKS * CIRCUMFERENCE * GEAR_RATIO + distance;
    double gyroReading = 0;
    double minVelocity = _data.minVelocity;
    double maxVelocity = _data.maxVelocity;
    double distanceRemaining = 69;

    PID_controller angleController(values);
    angleController.SetTarget(direction);

    while (distanceRemaining > offset && timeout > pros::millis() - startTime)
    {
        pros::delay(10);
        // have to calculate speed and heading individually
        double leftCurrent = getAverageLeftRotation() / ENCODER_TICKS * CIRCUMFERENCE * GEAR_RATIO;
        double rightCurrent = getAverageRightRotation() / ENCODER_TICKS * CIRCUMFERENCE * GEAR_RATIO;

        double distanceTraveled = leftCurrent + rightCurrent - leftStart - rightStart; // how far robot has traveled ,in inches (averaged out)
        distanceTraveled /= 2;
        distanceTraveled = abs(distanceTraveled);

        distanceRemaining = rightTarget + leftTarget - rightCurrent - leftCurrent; // how far robot has to travel, in inches (averaged out)
        distanceRemaining /= 2;
        distanceRemaining = abs(distanceRemaining);
        // distanceTraveled + distanceRemaining should always equal distance

        // calculate the velocities of accel and decel slope, using formula |Vf| = Math.sqrt(|Vi|^2 + 2ad) & |Vi| = Math.sqrt(|Vf|^2 - 2ad);
        double accelVelocity = sqrt((2 * accelSlope * distanceTraveled));
        double decelVelocity = sqrt((2 * decelSlope * (distanceRemaining - offset))); // if you crashed, this is the issue

        double velocityPoints[4] = {minVelocity, accelVelocity, maxVelocity, decelVelocity};
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3 - i; j++)
            {
                if (velocityPoints[j] > velocityPoints[j + 1])
                {
                    // Swap elements if they are in the wrong order
                    double temp = velocityPoints[j];
                    velocityPoints[j] = velocityPoints[j + 1];
                    velocityPoints[j + 1] = temp;
                }
            }
        }
        double velocity = velocityPoints[1]; // we take the second lowest velocity out of the 4 we have generated

        // velocity is now in inches/second, convert into percentage of max power 600 rpm * 0.5
        double forwardVoltage = velocity / (CIRCUMFERENCE * GEARBOX * GEAR_RATIO / 60);
        // now that we have the velocity, we can worry about steering, use pid controller
        double steerVoltage = angleController.Calculate(getIMU());

        moveLeftGroup(((squiggles::sgn(distance) * forwardVoltage + steerVoltage) * 12000));
        moveRightGroup(((squiggles::sgn(distance) * forwardVoltage - steerVoltage) * 12000));
    }
    moveLeftGroup(0);
    moveRightGroup(0);
}

void motion_profile::moveDistance2(double distance, double direction, double jerk)
{
}
