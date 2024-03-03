#include "main.h"
#include "util/sensors.hpp"

/**
 * @brief
 *
 * @return double imu in degrees
 */
double getIMU()
{
    return gyro.get_yaw() + angleOffset;
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
