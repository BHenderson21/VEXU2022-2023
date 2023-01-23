#include "../include/botFunctions.h"
#include "../include/MinesMotorGroup.h"

bool intakeToggle = 0;

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
        intake.move_velocity(-(10000)*pct * INTAKE_MOTOR_GEARSET);
    }
    else if(run == 1)
    {
        intake.move_velocity((10000)*pct * INTAKE_MOTOR_GEARSET);
    }
    else
    {
        intake.brake();
    }
}

void driveLoop(Mines::MinesMotorGroup leftMotorGroup, Mines::MinesMotorGroup rightMotorGroup, double leftVelocity, double rightVelocity)
{
    leftMotorGroup.move(leftVelocity);
    rightMotorGroup.move(rightVelocity);
}

void catapultLoop(Mines::MinesMotorGroup catapultMotorGroup, int pct)
{
    catapultMotorGroup.moveVelocity(R_CATAPULT_MOTOR_GEARSET * (pct*0.01));
}

void fire(Mines::MinesMotorGroup catapultMotorGroup)
{
    catapultMotorGroup.tarePosition();
    while(catapultMotorGroup.getPosition() < 100)
    {
        catapultMotorGroup.moveVelocity(30);
    }
    catapultMotorGroup.brake();
}

void loadAndFire(Mines::MinesMotorGroup catapultMotorGroup, pros::ADIDigitalIn limitSwitch)
{
    bool loaded = 0;

    if(limitSwitch.get_value() == 1)
    {
        while(limitSwitch.get_value() == 1)
        {
            catapultMotorGroup.moveVelocity(10);
        }
        loaded = 0;
    }
    else
    {
        while(limitSwitch.get_value() == 0)
        {
            catapultMotorGroup.moveVelocity(10);
        }
        catapultMotorGroup.brake();
        loaded = 1;
    }
    
}

void rollerLoop(pros::Motor roller, pros::Motor rollerFront, double velocity, bool run, bool rev)
{
    if(run)
    {
        roller.move_velocity(velocity);
        rollerFront.move_velocity(velocity);
    }
    else if(rev)
    {
        roller.move_velocity(velocity);
    }
    else
    {
        roller.brake();
        rollerFront.brake();
    }
}