#include "../include/botFunctions.h"
#include "../include/MinesMotorGroup.h"
#include "pros/motors.h"

bool intakeToggle = 0;
bool flywheelToggle = 0;

void toggleIntake()
{
    if(intakeToggle == 0)
    {
        intakeToggle = 1;
    }
    else
    {
        intakeToggle = 0;
    }
}

void toggleFlywheels()
{
    if(flywheelToggle == 0)
    {
        flywheelToggle = 1;
    }
    else
    {
        flywheelToggle = 0;
    }
}

void driveLoop(Mines::MinesMotorGroup leftMotorGroup, Mines::MinesMotorGroup rightMotorGroup, double leftVelocity, double rightVelocity)
{
    leftMotorGroup.move(leftVelocity);
    rightMotorGroup.move(rightVelocity);
}

void rollerLoop(pros::Motor roller, double velocity, bool run, bool rev)
{
    if(run)
    {
        roller.move_velocity(velocity);
    }
    else if(rev)
    {
        roller.move_velocity(-velocity);
    }
    else
    {
        roller.brake();
    }
}

void intakeLoopToggle(bool rev, int pct)
{
    if(rev == 1)
    {
        intakeToggle = 0;
        intake.move_velocity((100)*pct * INTAKE_MOTOR_GEARSET*-1);
    }
    else if(intakeToggle == 1)
    {
        intake.move_velocity((100)*pct * INTAKE_MOTOR_GEARSET);
    }
    else
    {
        intake.brake();
    }
}

void intakeLoopHold(bool run, bool rev, double pct)
{
    if(rev == 1)
    {
        intakeToggle = 0;
        intake.move_velocity(-(100)*pct * INTAKE_MOTOR_GEARSET);
    }
    else if(run == 1)
    {
        intake.move_velocity((100)*pct * INTAKE_MOTOR_GEARSET);
    }
    else
    {
        intake.brake();
    }
}
void flywheelLoopToggle(Mines::MinesMotorGroup flywheels, int pct)
{
    if(flywheelToggle == 1)
    {
        flywheels.move(((0.01)* (pct) * 127));
    }
    else
    {
        flywheels.brake();
    }
}