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

double getDriveTemp(){
    return ((lf.getTemperature() + lb.getTemperature() + lt.getTemperature() + rf.getTemperature() + rb.getTemperature() + rt.getTemperature())/6) ;
}

double getEfficiency(){ // Only using this to see how much resistance the drivetrain puts up
    return ((lf.getEfficiency() + lb.getEfficiency() + lt.getEfficiency() + rf.getEfficiency() + rb.getEfficiency() + rt.getEfficiency()) / 6);
}
