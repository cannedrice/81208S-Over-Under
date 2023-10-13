#include "okapi/api.hpp"

extern bool leftWingState;
extern bool rightWingState;
extern bool matchloadState;
extern bool climbingState;

// Controller
extern okapi::Controller controller;

extern okapi::ControllerAnalog leftY;
extern okapi::ControllerAnalog rightX;
extern okapi::ControllerAnalog rightY;
extern okapi::ControllerButton l1;
extern okapi::ControllerButton l2;
extern okapi::ControllerButton r1;
extern okapi::ControllerButton r2;
extern okapi::ControllerButton leftButton;
extern okapi::ControllerButton downButton;
extern okapi::ControllerButton rightButton;
extern okapi::ControllerButton upButton;
extern okapi::ControllerButton YButton;
extern okapi::ControllerButton AButton;
extern okapi::ControllerButton BButton;
extern okapi::ControllerButton XButton;

// Drivetrain 
/* Left front */extern okapi::Motor lf;
/* Left bottom */extern okapi::Motor lb;
/* Left top */extern okapi::Motor lt;
/* Right front */extern okapi::Motor rf;
/* Right back */extern okapi::Motor rb;
/* Right top */extern okapi::Motor rt;

// Drive motorgroups
/* Left group */extern okapi::MotorGroup driveLeftGroup;
/* Right group */extern okapi::MotorGroup driveRightGroup;
extern okapi::MotorGroup driveGroup;

// Intake 
/* Right intake */extern okapi::Motor ri;
/* Left intake */extern okapi::Motor li;
/* Intake motor group */extern okapi::MotorGroup intake;

// Catapult
/* Catapult */extern okapi::Motor catapult;
/* Catapult potentiometer */extern okapi::Potentiometer potentiometer;

// Auton 
/* Gyro */extern pros::IMU gyro;

//Pneumatics
pros::ADIDigitalOut rightWing;
pros::ADIDigitalOut leftWing;
pros::ADIDigitalOut matchloadBar;
pros::ADIDigitalOut hangMech;