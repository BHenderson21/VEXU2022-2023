#ifndef _GLOBALS_H
#define _GLOBALS_H

#include "api.h"

#define INERTIAL_SENSOR 17

#define TOP_ROLLER 11
#define TOP_ROLLER_FRONT 21
#define ROLLER_MOTOR_GEARSET red

#define L_TOP_REAR 19
#define L_TOP_REAR_MOTOR_GEARSET blue
#define L_BOT_REAR 16
#define L_BOT_REAR_MOTOR_GEARSET blue
#define L_FRONT 20
#define L_FRONT_MOTOR_GEARSET blue
#define R_TOP_REAR 5
#define R_TOP_REAR_MOTOR_GEARSET blue
#define R_BOT_REAR 6
#define R_BOT_REAR_MOTOR_GEARSET blue
#define R_FRONT 8
#define R_FRONT_MOTOR_GEARSET blue

#define L_CATAPULT 14
#define L_CATAPULT_MOTOR_GEARSET red
#define R_CATAPULT 1
#define R_CATAPULT_MOTOR_GEARSET red


#define INTAKE 15
#define INTAKE_MOTOR_GEARSET blue

#define LIMIT_SWITCH 2
#define SHIELD 8
#define ENDGAME 1

extern pros::Controller MasterController;

extern pros::Imu intertialSensor;

extern pros::Motor topRoller;
extern pros::Motor topRollerFront;

extern pros::Motor leftTopRearDrive;
extern pros::Motor leftBotRearDrive;
extern pros::Motor leftFrontDrive;
extern pros::Motor rightTopRearDrive;
extern pros::Motor rightBotRearDrive;
extern pros::Motor rightFrontDrive;

extern pros::Motor leftCatapult;
extern pros::Motor rightCatapult;

extern pros::Motor intake;

extern pros::ADIDigitalIn limitSwitch;
extern pros::ADIDigitalOut shield;
extern pros::ADIDigitalOut endgame;

extern std::vector<pros::Motor> leftDriveVector;
extern std::vector<pros::Motor> rightDriveVector;

extern std::vector<pros::Motor> catapultVector;

extern double axisPercentBlue;
extern double axisPercentGreen;
extern double axisPercentRed;
extern int blue;
extern int green;
extern int red;
#define RED_GEARSET pros::E_MOTOR_GEARSET_36
#define GREEN_GEARSET pros::E_MOTOR_GEARSET_18
#define BLUE_GEARSET pros::E_MOTOR_GEARSET_06

#define buttonUp pros::E_CONTROLLER_DIGITAL_UP
#define buttonDown pros::E_CONTROLLER_DIGITAL_DOWN
#define buttonLeft pros::E_CONTROLLER_DIGITAL_LEFT
#define buttonRight pros::E_CONTROLLER_DIGITAL_RIGHT
#define buttonX pros::E_CONTROLLER_DIGITAL_X
#define buttonY pros::E_CONTROLLER_DIGITAL_Y
#define buttonA pros::E_CONTROLLER_DIGITAL_A
#define buttonB pros::E_CONTROLLER_DIGITAL_B
#define buttonL1 pros::E_CONTROLLER_DIGITAL_L1
#define buttonL2 pros::E_CONTROLLER_DIGITAL_L2
#define buttonR1 pros::E_CONTROLLER_DIGITAL_R1
#define buttonR2 pros::E_CONTROLLER_DIGITAL_R2
#define axisLeftY pros::E_CONTROLLER_ANALOG_LEFT_Y
#define axisleftX pros::E_CONTROLLER_ANALOG_LEFT_X
#define axisRightY pros::E_CONTROLLER_ANALOG_RIGHT_Y
#define axisRightX pros::E_CONTROLLER_ANALOG_RIGHT_X

#endif