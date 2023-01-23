#include "../include/globals.h"
#include "pros/adi.hpp"

pros::Controller MasterController (pros::E_CONTROLLER_MASTER);

pros::Imu intertialSensor(INERTIAL_SENSOR);

pros::Motor topRoller(TOP_ROLLER, pros::E_MOTOR_GEARSET_18, false);

pros::Motor intake(INTAKE, pros::E_MOTOR_GEARSET_18, true);

pros::Motor leftFrontDrive(L_FRONT, pros::E_MOTOR_GEARSET_18, true);
pros::Motor leftRearDrive(L_REAR, pros::E_MOTOR_GEARSET_18, true);
pros::Motor leftMidDrive(L_MID, pros::E_MOTOR_GEARSET_18, true);
pros::Motor rightFrontDrive(R_FRONT, pros::E_MOTOR_GEARSET_18, false);
pros::Motor rightRearDrive(R_REAR, pros::E_MOTOR_GEARSET_18, false);
pros::Motor rightMidDrive(R_MID, pros::E_MOTOR_GEARSET_18, false);

pros::Motor fly1(FLY1, pros::E_MOTOR_GEARSET_06, true);
pros::Motor fly2(FLY2, pros::E_MOTOR_GEARSET_06, false);

pros::ADIDigitalOut launch(LAUNCH);
pros::ADIDigitalOut push(PUSH);

std::vector<pros::Motor> leftDriveVector = {leftFrontDrive, leftRearDrive, leftMidDrive};
std::vector<pros::Motor> rightDriveVector = {rightFrontDrive, rightRearDrive, rightMidDrive};
std::vector<pros::Motor> flywheels = {fly1, fly2};
Mines::MinesMotorGroup leftDriveMotors(leftDriveVector);
Mines::MinesMotorGroup rightDriveMotors(rightDriveVector);
Mines::MinesMotorGroup flywheelsGroup(flywheels);

double axisPercentBlue = 600.0 / 127;
double axisPercentGreen = 200.0 / 127;
double axisPercentRed = 100.0 / 127;
int blue = 600;
int green = 200;
int red = 100;
