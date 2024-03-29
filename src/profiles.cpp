#include "main.h"

PIDvalues dis = {0.05, 0, 0.01};
PIDvalues rot45 = {0.013, 0, 0.034};
PIDvalues rot90 = {0.011, 0, 0.036};
PIDvalues rot135 = {0.009, 0, 0.038};
PIDvalues rot180 = {0.008, 0, 0.04};
PIDvalues piv = {0.013, 0, 0.02};

bool leftWingState = false;
bool rightWingState = false;
bool globalWingState = false;
bool leftRearWingState = false;
bool rightRearWingState = false;
bool globalRearWingState = false;
bool PTOState = false;
bool hangState = false;
double angleOffset = 0;

// Controller
okapi::Controller controller(okapi::ControllerId::master);

okapi::ControllerAnalog leftY(okapi::ControllerAnalog::leftY);
okapi::ControllerAnalog rightX(okapi::ControllerAnalog::rightX);
okapi::ControllerButton l1(okapi::ControllerDigital::L1);
okapi::ControllerButton l2(okapi::ControllerDigital::L2);
okapi::ControllerButton r1(okapi::ControllerDigital::R1);
okapi::ControllerButton r2(okapi::ControllerDigital::R2);
okapi::ControllerButton rightButton(okapi::ControllerDigital::right);
okapi::ControllerButton downButton(okapi::ControllerDigital::down);
okapi::ControllerButton leftButton(okapi::ControllerDigital::left);
okapi::ControllerButton upButton(okapi::ControllerDigital::up);
okapi::ControllerButton AButton(okapi::ControllerDigital::A);
okapi::ControllerButton BButton(okapi::ControllerDigital::B);
okapi::ControllerButton XButton(okapi::ControllerDigital::X);
okapi::ControllerButton YButton(okapi::ControllerDigital::Y);

// Drivetrain
/* Left front */ okapi::Motor lf(20, true, okapi::AbstractMotor::gearset::blue, okapi::AbstractMotor::encoderUnits::degrees);
/* Left bottom */ okapi::Motor lb(10, true, okapi::AbstractMotor::gearset::blue, okapi::AbstractMotor::encoderUnits::degrees);
/* Left top */ okapi::Motor lt(19, true, okapi::AbstractMotor::gearset::blue, okapi::AbstractMotor::encoderUnits::degrees);
/* Right front */ okapi::Motor rf(11, false, okapi::AbstractMotor::gearset::blue, okapi::AbstractMotor::encoderUnits::degrees);
/* Right back */ okapi::Motor rb(1, false, okapi::AbstractMotor::gearset::blue, okapi::AbstractMotor::encoderUnits::degrees);
/* Right top */ okapi::Motor rt(12, false, okapi::AbstractMotor::gearset::blue, okapi::AbstractMotor::encoderUnits::degrees);

// Drivetrain Motor Group
/* Left group*/ okapi::MotorGroup driveLeftGroup = {lb, lf, lt};
/* Right group*/ okapi::MotorGroup driveRightGroup = {rb, rf, rt};
/* Drive group */ okapi::MotorGroup driveGroup = {lb, lf, lt, rf, rb, rt};

// Intake
/* Right intake */ okapi::Motor ri(14, false, okapi::AbstractMotor::gearset::blue, okapi::AbstractMotor::encoderUnits::degrees);
/* Left intake */ okapi::Motor li(17, false, okapi::AbstractMotor::gearset::blue, okapi::AbstractMotor::encoderUnits::degrees);
/* Intake motor group */ okapi::MotorGroup intake = {ri}; //, li};

// Im not ever sure if we have a pot or not LOLOLOL, putthing this here for now.
/* Potentionmeter */ okapi::Potentiometer potentiometer('H');

// Auton
/* Gyro */ pros::Imu gyro(9);

// Pneumatics
/* Front PTO */ pros::ADIDigitalOut frontPTO('C', LOW);
/* Back PTO */ pros::ADIDigitalOut backPTO('G', LOW);
/* Right wing */ pros::ADIDigitalOut rightWing('C', LOW);
/* Left wing */ pros::ADIDigitalOut leftWing('G', LOW);
/* Right back wing */ pros::ADIDigitalOut rightRearWing('C', LOW);
/* Left back wing */ pros::ADIDigitalOut leftRearWing('G', LOW);
/* Hang left */ pros::ADIDigitalOut leftHang('F', LOW);
/* Hang right */ pros::ADIDigitalOut rightHang('F', LOW);

pros::ADIEncoder verticalTracker({4, 'A', 'B'}, false);
pros::ADIEncoder horizontalTracker({4, 'C', 'D'}, true);
