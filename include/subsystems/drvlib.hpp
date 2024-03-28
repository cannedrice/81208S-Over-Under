#pragma once
#include "main.h"

//for turning control
#define LEFT_WHEEL_TURN				0
#define RIGHT_WHEEL_TURN			1
#define WHEELS_TURN						2
#define MAIN_LOOP_PERIOD			20
#define TURN_TASK_PRI					40
#define TURN_TASK_PERIOD			10	//10ms control period
#define GO_STRAIGHT_TASK_PRI  40
#define GO_STRAIGHT_PERIOD		20   //10ms control period
#define GYRO_RANGE 						360
#define TURN_TASK_DEADZONE	  2	 //1 degree

#define WHEEL_TRACK      10.75      // distance between left-right side wheels, in inches
#define WHEEL_PERIMETER		10.210176124166828025   //4.0" wheel, in inches
#define CIRCLE_COUNT			36000  // using rotaton sensor, return degree * 100
#define MAX_MOVE_SPEED		200
#define MIN_MOVE_SPEED		 	10	// need test

//stop deaccelerate setting
#define STOP_DISTANCE			0.5
#define GO_SLOWDOWN_RATIO		((float)(MAX_MOVE_SPEED - MIN_MOVE_SPEED) / STOP_DISTANCE)		// which means the max speed to stop min speed in 0.5m 			//
//#define GO_MOMENTUM				0.04
#define SLOW_DRIVE_DIS		0.0			//10cm

//accelerate setting, unit: distance: m, power: 25
#define ACC_MIN_SPEED			25
#define GO_ACCEL_DIS			0.1
#define GO_ACCEL_RATIO		((float)(MAX_MOVE_SPEED - ACC_MIN_SPEED) / GO_ACCEL_DIS)		// which means the max speed to stop min speed in 0.5m 			//

extern float robotHeading ;
extern int taskFlag;
extern int taskCnt;

/******************************************************************************************************
* set drive chain motors brake mode
* parameter could be (okapi::AbstractMotor::brakeMode::brake) ( (okapi::AbstractMotor::brakeMode::coast)
******************************************************************************************************/
void setDrvMotorBrakeMode(okapi::AbstractMotor::brakeMode mode);

/******************************************************************************************************
* reset IMU heading reading to 0 degree
******************************************************************************************************/
void  resetGyro();
/******************************************************************************************************
* get IMU( or gyro) readign,
* get_totation() function could be go beyond 0~ 360 degeee
* get_heading()  -180 + 180, you need process the overlap
******************************************************************************************************/
float get_gyroReading();

/******************************************************************************************************
* reset roation sensor reading to 0
* if you using the motor encoder, you need reset motor encoder
******************************************************************************************************/
void resetEncoderReading();

/******************************************************************************************************
* set rotation sensor direction
* for odometry system, we need keep positive readign when robot mvoe forward
* hard code here, we need test on robot
******************************************************************************************************/


float get_leftEncoder();
/******************************************************************************************************
* get rotation sensor reading
* if using motor encoder, you need use
******************************************************************************************************/
float get_rightEncoder();

/******************************************************************************************************
* here is the send out actually motor cotnrol cmd
* using moveVelocity command
******************************************************************************************************/

void driveWheels(float leftCmd, float rightCmd);
void driveWheelsVoltage(float leftCmd, float rightCmd);
void stopRobot();

// here we abuse suing task, for better way, need mutex for share variables
void waitTimeOutTask(void *param);

//////////////////////////////////////////////////////////////////////////////
//// turning by PID controller
// please note the setAngle is globle angle, not relative angle, in case the error accumulate
// for easy to use, all the angle is in degree, but internal the odometry the angle is radian
/// default maxPower = 0, so the function will calculate the kp, kd, momentum based on setAngle
// so normally use will be
// turnToAngle(90, WHEELS_TURN);
//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
////Point To Point Dirve //////////////////////////////////////////////////////
/// Turn + Drive by Distance, it will keep original heading = startP ---> DstP(p2p angle)
////////////////////////////////////////////////////////////////////////////////////////////

#define ANGLE_DELTA_TH  10.0 / 180.0 * PI
// template <typename T> int sgn(T val) {
//     return (T(0) < val) - (val < T(0));
// }
