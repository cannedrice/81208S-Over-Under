#include "util/PID_controller.hpp"
#include "util/motion_profile.hpp"

extern double x;
extern double y;
extern double thetaAdjustment;

void resetRobotPos();

void resetRobotPos(double currX, double currY, double thetaAdjustment);

void estimatePositionTask();

void startOdomTask();

void moveToPoint(double x, double y, double offset, bool forward, PIDvalues values, MotionData data);