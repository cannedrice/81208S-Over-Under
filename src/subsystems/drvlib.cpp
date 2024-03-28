#include "subsystems/drvlib.hpp"
#include "math.h"


//handles chassis autonomous control at lowest level, including base move functions
//mostly depreciated at this point

float robotHeading = 0;

/******************************************************************************************************
* set drive chain motors brake mode
* parameter could be (okapi::AbstractMotor::brakeMode::brake) ( (okapi::AbstractMotor::brakeMode::coast)
******************************************************************************************************/
void setDrvMotorBrakeMode(okapi::AbstractMotor::brakeMode mode){
  driveGroup.setBrakeMode(mode);
}

/******************************************************************************************************
* reset IMU heading reading to 0 degree
******************************************************************************************************/
void resetGyro() {
  gyro.tare_pitch();
  gyro.tare_roll();
  gyro.tare_rotation();
  gyro.reset();
}
/******************************************************************************************************
* get IMU( or gyro) readign,
* get_totation() function could be go beyond 0~ 360 degeee
* get_heading()  -180 + 180, you need process the overlap
******************************************************************************************************/
float get_gyroReading()  {
  return gyro.get_rotation();
}

/******************************************************************************************************
* reset roation sensor reading to 0
* if you using the motor encoder, you need reset motor encoder
******************************************************************************************************/
void resetEncoderReading() {
    verticalTracker.reset();
    horizontalTracker.reset();
}

/******************************************************************************************************
* set rotation sensor direction
* for odometry system, we need keep positive readign when robot mvoe forward
* hard code here, we need test on robot
******************************************************************************************************/


float get_leftEncoder(){
  //return leftRotation.get_position();
  return 0;  //adi encoder
  //return lf.getPosition().controllerGet()
}
/******************************************************************************************************
* get rotation sensor reading
* if using motor encoder, you need use
******************************************************************************************************/
float get_rightEncoder(){
  //return rightRotation.get_position();
  return 0;  //ADIencoder
  // rf.getPosition()
}

void driveWheels(float leftCmd, float rightCmd){
  //here we use velocity control, it is better than voltage??
  driveLeftGroup.moveVelocity(leftCmd);
  driveRightGroup.moveVelocity(rightCmd);
}

/******************************************************************************************************
* here is the send out actually motor cotnrol cmd
* using moveVelocity command
******************************************************************************************************/

void driveWheelsVoltage(float leftCmd, float rightCmd){
  //here we use velocity control, it is better than voltage
  driveLeftGroup.moveVoltage(leftCmd / 200.0 * 12000.0);
  driveRightGroup.moveVoltage(rightCmd / 200.0 * 12000.0);
}


void stopRobot() {
  driveGroup.moveVelocity(0);
}

// wait task , will be used in drive/turn functions,
// we set some global flag here,  so we can control intake, lift or otherthing in the drive/turn task
int taskFlag = 0;
int taskCnt = 0;
int timeOutSet = 0;
int turnTaskStartFlag = 0;
int driveTaskStartStartFlag = 0;
bool waitTaskLive = false;
// here we abuse suing task, for better way, need mutex for share variables
void waitTimeOutTask(void *param) {
  timeOutSet =  timeOutSet / 20;  // 20ms period
	int delayCnt = 0;
	while(waitTaskLive){
		delayCnt ++;
		if (delayCnt > timeOutSet) {
			break;
		}
    if (delayCnt == taskCnt){
      if (taskFlag == 1){
        // do something here
      }
    }
	  pros::delay(20);
	}
}
