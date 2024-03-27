#include "main.h"
#include "util/sensors.hpp"

/**
 * @brief
 *
 * @return double imu in degrees
 */
double getIMU()
{
    return gyro.get_rotation() + angleOffset;
}

/**
 * @brief Get the Average Left Rotation object (360 degree)
 *
 * @return double
 */
double getAverageLeftRotation()
{
    return (lf.getPosition() + lb.getPosition() + lt.getPosition()) / 3;
}

/**
 * @brief Get the Average Right Rotation object (360 degree)
 *
 * @return double
 */
double getAverageRightRotation()
{
    return (rf.getPosition() + rb.getPosition() + rt.getPosition()) / 3;
}

/**
 * @brief Get the Vertical Rotation object
 * 
 * @return double 
 */
double getVerticalRotation(){
    return verticalTracker.get_value();
}

/**
 * @brief Get the Horizontal Rotation object
 * 
 * @return double 
 */
double getHorizontalRotation(){
    return horizontalTracker.get_value();
}