#include "main.h"

double dis[3] = {0.05, 0, 0.01};
double rot[3] = {0.017, 0, 0.08};
double piv[3] = {0.016, 0, 0.02};

bool leftWingState = false;
bool rightWingState = false;
bool globalWingState = false;
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
okapi::ControllerButton r2(okapi::ControllerDigital::R2);             // toggle cata state
okapi::ControllerButton rightButton(okapi::ControllerDigital::right); // right wing
okapi::ControllerButton downButton(okapi::ControllerDigital::down);   // toggle both wings
okapi::ControllerButton leftButton(okapi::ControllerDigital::left);   // left wing
okapi::ControllerButton upButton(okapi::ControllerDigital::up);       // blocker
okapi::ControllerButton AButton(okapi::ControllerDigital::A);         // right rear wing
okapi::ControllerButton BButton(okapi::ControllerDigital::B);         // toggle both rear wings
okapi::ControllerButton XButton(okapi::ControllerDigital::X);         // hang
okapi::ControllerButton YButton(okapi::ControllerDigital::Y);         // left rear wing

// Drivetrain
/* Left front */ okapi::Motor lf(20, true, okapi::AbstractMotor::gearset::blue, okapi::AbstractMotor::encoderUnits::degrees);
/* Left bottom */ okapi::Motor lb(10, true, okapi::AbstractMotor::gearset::blue, okapi::AbstractMotor::encoderUnits::degrees);
/* Left top */ okapi::Motor lt(19, true, okapi::AbstractMotor::gearset::blue, okapi::AbstractMotor::encoderUnits::degrees);
/* Right front */ okapi::Motor rf(11, false, okapi::AbstractMotor::gearset::blue, okapi::AbstractMotor::encoderUnits::degrees);
/* Right back */ okapi::Motor rb(1, false, okapi::AbstractMotor::gearset::blue, okapi::AbstractMotor::encoderUnits::degrees);
/* Right top */ okapi::Motor rt (12, false, okapi::AbstractMotor::gearset::blue, okapi::AbstractMotor::encoderUnits::degrees);

// Drivetrain Motor Group
/* Left group*/ okapi::MotorGroup driveLeftGroup = {lb, lf, lt};
/* Right group*/ okapi::MotorGroup driveRightGroup = {rb, rf, rt};
/* Drive group */ okapi::MotorGroup driveGroup = {lb, lf, lt, rf, rb, rt};

// Intake
/* Right intake */ okapi::Motor ri(13, false, okapi::AbstractMotor::gearset::blue, okapi::AbstractMotor::encoderUnits::degrees);
/* Left intake */ okapi::Motor li(17, false, okapi::AbstractMotor::gearset::blue, okapi::AbstractMotor::encoderUnits::degrees);
/* Intake motor group */ okapi::MotorGroup intake = {ri};//, li};

// Hang
/* Hang */ okapi::Motor hang(11, true, okapi::AbstractMotor::gearset::red, okapi::AbstractMotor::encoderUnits::degrees);
/* Potentionmeter */ okapi::Potentiometer potentiometer('H');

// Auton
/* Gyro */ pros::Imu gyro(9);

// Pneumatics
/* Front PTO */ pros::ADIDigitalOut frontPTO('C', LOW);
/* Back PTO */ pros::ADIDigitalOut backPTO('G', LOW);
/* Right back wing */ pros::ADIDigitalOut rightBackWing('C', LOW);
/* Left back wing */ pros::ADIDigitalOut leftBackWing('G', LOW);
/* Right wing */ pros::ADIDigitalOut rightWing('C', LOW);
/* Left wing */ pros::ADIDigitalOut leftWing('G', LOW);
/* Right rear wing */ pros::ADIDigitalOut rightRearWing('D', LOW);
/* Left rear wing */ pros::ADIDigitalOut leftRearWing('B', LOW);
/* Hang Right */ pros::ADIDigitalOut blocker('A', LOW);
/* Hang left */ pros::ADIDigitalOut hang('F', LOW);

pros::ADIEncoder verticalTracker({4, 'A', 'B'},false);
pros::ADIEncoder horizontalTracker({4, 'C', 'D'},true);
