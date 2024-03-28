#include "okapi/api.hpp"

#define CIRCUMFERENCE 3.25 * M_PI
#define ENCODER_TICKS 360
#define GEAR_RATIO 3 / 4
#define GEARBOX 600

#define VERTICALCIRC 2.75 * M_PI * 24/22.4
#define HORIZONTALCIRC 2.75 * M_PI * 24/23.2
#define TICKS 360

double extern dis[3];
double extern rot[3];
double extern piv[3];

extern bool leftWingState;
extern bool rightWingState;
extern bool globalWingState;
extern bool leftRearWingState;
extern bool rightRearWingState;
extern bool globalRearWingState;
extern bool PTOState;
extern bool hangState;
extern double angleOffset;

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
/* Left front */ extern okapi::Motor lf;
/* Left bottom */ extern okapi::Motor lb;
/* Left top */ extern okapi::Motor lt;
/* Right front */ extern okapi::Motor rf;
/* Right back */ extern okapi::Motor rb;
/* Right top */ extern okapi::Motor rt;

// Drive motorgroups
/* Left group */ extern okapi::MotorGroup driveLeftGroup;
/* Right group */ extern okapi::MotorGroup driveRightGroup;
/* Drive group */ extern okapi::MotorGroup driveGroup;

// Intake
/* Right intake */ extern okapi::Motor ri;
/* Left intake */ extern okapi::Motor li;
/* Intake motor group */ extern okapi::MotorGroup intake;

/* Catapult potentiometer */ extern okapi::Potentiometer potentiometer;

// Auton
/* Gyro */ extern pros::IMU gyro;

// Pneumatics
/* Front PTO */ extern pros::ADIDigitalOut frontPTO;
/* Back PTO*/ extern pros::ADIDigitalOut backPTO;
/* Right wing */ extern pros::ADIDigitalOut rightWing;
/* Left wing */ extern pros::ADIDigitalOut leftWing;
/* Right rear wing */ extern pros::ADIDigitalOut rightRearWing;
/* Left rear wing */ extern pros::ADIDigitalOut leftRearWing;
/* Hang left*/ extern pros::ADIDigitalOut leftHang;
/* hang right*/ extern pros::ADIDigitalOut rightHang;

extern pros::ADIEncoder verticalTracker;
extern pros::ADIEncoder horizontalTracker;
