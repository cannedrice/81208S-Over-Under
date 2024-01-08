#include "main.h"

bool leftWingState = false;
bool rightWingState = false;
bool matchloadState = false;
bool climbingState = false;
bool cataToggle = false;
double angleOffset = 0;

// Controller
okapi::Controller controller(okapi::ControllerId::master);

okapi::ControllerAnalog leftY(okapi::ControllerAnalog::leftY);        // forward + backwards
okapi::ControllerAnalog rightX(okapi::ControllerAnalog::rightX);      // left + right
okapi::ControllerAnalog rightY(okapi::ControllerAnalog::rightY);      // unused
okapi::ControllerButton l1(okapi::ControllerDigital::L1);             // intake
okapi::ControllerButton l2(okapi::ControllerDigital::L2);             // outtake
okapi::ControllerButton r1(okapi::ControllerDigital::R1);             // fire catapult
okapi::ControllerButton r2(okapi::ControllerDigital::R2);             // toggle catapult
okapi::ControllerButton rightButton(okapi::ControllerDigital::right); // toggle right wing
okapi::ControllerButton downButton(okapi::ControllerDigital::down);   // toggle matchload
okapi::ControllerButton leftButton(okapi::ControllerDigital::left);   // toggle left wing
okapi::ControllerButton upButton(okapi::ControllerDigital::up);       // toggle hang bar
okapi::ControllerButton AButton(okapi::ControllerDigital::A);         // exit auton selector
okapi::ControllerButton BButton(okapi::ControllerDigital::B);         // decrement auton selector
okapi::ControllerButton XButton(okapi::ControllerDigital::X);         // increment auton selector
okapi::ControllerButton YButton(okapi::ControllerDigital::Y);         // select auton path

// Drivetrain
/* Left front */ okapi::Motor lf(14, true, okapi::AbstractMotor::gearset::blue, okapi::AbstractMotor::encoderUnits::degrees);
/* Left bottom */ okapi::Motor lb(8, true, okapi::AbstractMotor::gearset::blue, okapi::AbstractMotor::encoderUnits::degrees);
/* Left top */ okapi::Motor lt(10, false, okapi::AbstractMotor::gearset::blue, okapi::AbstractMotor::encoderUnits::degrees);
/* Right front */ okapi::Motor rf(13, false, okapi::AbstractMotor::gearset::blue, okapi::AbstractMotor::encoderUnits::degrees);
/* Right back */ okapi::Motor rb(18, false, okapi::AbstractMotor::gearset::blue, okapi::AbstractMotor::encoderUnits::degrees);
/* Right top */ okapi::Motor rt(12, true, okapi::AbstractMotor::gearset::blue, okapi::AbstractMotor::encoderUnits::degrees);

// Drivetrain Motor Group
/* Left group*/ okapi::MotorGroup driveLeftGroup = {lb, lf, lt};
/* Right group*/ okapi::MotorGroup driveRightGroup = {rb, rf, rt};
/* Drive group */ okapi::MotorGroup driveGroup = {lb, lf, lt, rf, rb, rt};

// Intake
/* Right intake */ okapi::Motor ri(20, true, okapi::AbstractMotor::gearset::green, okapi::AbstractMotor::encoderUnits::degrees);
/* Left intake */ okapi::Motor li(11, false, okapi::AbstractMotor::gearset::green, okapi::AbstractMotor::encoderUnits::degrees);
/* Intake motor group */ okapi::MotorGroup intake = {ri, li};

// Catapult
/* Catapult */ okapi::Motor catapult(9, true, okapi::AbstractMotor::gearset::red, okapi::AbstractMotor::encoderUnits::degrees);
/* Potentionmeter */ okapi::Potentiometer potentiometer('H');

// Auton
/* Gyro */ pros::Imu gyro(15);

// Pneumatics
/* Right wing */ pros::ADIDigitalOut rightWing('A', LOW);
/* Left wing */ pros::ADIDigitalOut leftWing('D', LOW);
/* Matchload bar */ pros::ADIDigitalOut matchloadBar('E', LOW);
/* Hang bar */ pros::ADIDigitalOut hangBar('B', LOW);