#include "main.h"

bool leftWingState = false;
bool rightWingState = false;
bool leftRearWingState = false;
bool rightRearWingState = false;
bool blockerState = false;
bool shooterState = false;
bool hangState = false;
bool cataToggle = false;
double angleOffset = 0;

// Controller
okapi::Controller controller(okapi::ControllerId::master);

okapi::ControllerAnalog leftY(okapi::ControllerAnalog::leftY);        // forward + backwards
okapi::ControllerAnalog rightX(okapi::ControllerAnalog::rightX);      // left + right
okapi::ControllerButton l1(okapi::ControllerDigital::L1);             // intake
okapi::ControllerButton l2(okapi::ControllerDigital::L2);             // outtake
okapi::ControllerButton r1(okapi::ControllerDigital::R1);             // fire catapult
okapi::ControllerButton r2(okapi::ControllerDigital::R2);             // unused
okapi::ControllerButton rightButton(okapi::ControllerDigital::right); // right wing
okapi::ControllerButton downButton(okapi::ControllerDigital::down);   // toggle both wings
okapi::ControllerButton leftButton(okapi::ControllerDigital::left);   // left wing
okapi::ControllerButton upButton(okapi::ControllerDigital::up);       // blocker
okapi::ControllerButton AButton(okapi::ControllerDigital::A);         // right rear wing
okapi::ControllerButton BButton(okapi::ControllerDigital::B);         // toggle both rear wings
okapi::ControllerButton XButton(okapi::ControllerDigital::X);         // hang
okapi::ControllerButton YButton(okapi::ControllerDigital::Y);         // left rear wing

// Drivetrain
/* Left front */ okapi::Motor lf(14, true, okapi::AbstractMotor::gearset::blue, okapi::AbstractMotor::encoderUnits::degrees);
/* Left bottom */ okapi::Motor lb(2, true, okapi::AbstractMotor::gearset::blue, okapi::AbstractMotor::encoderUnits::degrees);
/* Left top */ okapi::Motor lt(4, false, okapi::AbstractMotor::gearset::blue, okapi::AbstractMotor::encoderUnits::degrees);
/* Right front */ okapi::Motor rf(15, false, okapi::AbstractMotor::gearset::blue, okapi::AbstractMotor::encoderUnits::degrees);
/* Right back */ okapi::Motor rb(1, false, okapi::AbstractMotor::gearset::blue, okapi::AbstractMotor::encoderUnits::degrees);
/* Right top */ okapi::Motor rt(5, true, okapi::AbstractMotor::gearset::blue, okapi::AbstractMotor::encoderUnits::degrees);

// Drivetrain Motor Group
/* Left group*/ okapi::MotorGroup driveLeftGroup = {lb, lf, lt};
/* Right group*/ okapi::MotorGroup driveRightGroup = {rb, rf, rt};
/* Drive group */ okapi::MotorGroup driveGroup = {lb, lf, lt, rf, rb, rt};

// Intake
/* Right intake */ okapi::Motor ri(20, true, okapi::AbstractMotor::gearset::green, okapi::AbstractMotor::encoderUnits::degrees);
/* Left intake */ okapi::Motor li(12, false, okapi::AbstractMotor::gearset::green, okapi::AbstractMotor::encoderUnits::degrees);
/* Intake motor group */ okapi::MotorGroup intake = {ri, li};

// Catapult
/* Catapult */ okapi::Motor catapult(11, true, okapi::AbstractMotor::gearset::red, okapi::AbstractMotor::encoderUnits::degrees);
/* Potentionmeter */ okapi::Potentiometer potentiometer('H');

// Auton
/* Gyro */ pros::Imu gyro(18);

// Pneumatics
/* Right wing */ pros::ADIDigitalOut rightWing('C', LOW);
/* Left wing */ pros::ADIDigitalOut leftWing('G', LOW);
/* Right rear wing */ pros::ADIDigitalOut rightRearWing('D', LOW);
/* Left rear wing */ pros::ADIDigitalOut leftRearWing('B', LOW);
/* Blocker Right */ pros::ADIDigitalOut blocker('A', LOW);
/* Blocker left */ pros::ADIDigitalOut hang('D', LOW);
/* Single use */ pros::ADIDigitalOut shooter('E', LOW);