#include "DiffDrive.h"
#include "MinesMotorGroup.h"
#include "globals.h"
#include "pros/imu.hpp"
#include "pros/llemu.hpp"
#include "pros/motors.hpp"
#include "pros/rtos.h"
#include <algorithm>
#include <cmath>

using namespace Mines;
using namespace std;


DiffDrive::DiffDrive(MinesMotorGroup left, MinesMotorGroup right, pros::IMU imu) : 
    leftMotors(left), rightMotors(right), intertial(imu),
    driveInterface(this), turnInterface(this),
    drivePID(&driveInterface), turnPID(&turnInterface)
{
    MAX_SPEED = rightMotors.getMaxVelocity();

    drivePID.StartTask();
    turnPID.StartTask();
}

void DiffDrive::driveTiles(double target, bool waitForCompletion)
{
    leftMotors.tarePosition();
    rightMotors.tarePosition();

    drivePID.SetTarget(target);
    if(waitForCompletion)
    {
        while(drivePID.GetTimeSinceTargetReached() < 1)
        {
            pros::c::delay(20);
        }
    }
}

void DiffDrive::driveTiles(double target, double timeOut)
{
    leftMotors.tarePosition();
    rightMotors.tarePosition();

    drivePID.SetTarget(target);

    while(drivePID.GetTimeSinceTargetReached() < 1 && drivePID.GetTimeSinceTargetSet() < timeOut)
    {
        pros::c::delay(20);
    }
}

void DiffDrive::turnDegreesAbsolute(double target, bool waitForCompletion)
{
    turnPID.SetTarget(target);
    if(waitForCompletion)
    {
        while(drivePID.GetTimeSinceTargetReached() < 1)
        {
            pros::c::delay(20);
        }
    }
}

void DiffDrive::turnDegreesAbsolute(double target, double timeOut)
{
    turnPID.SetTarget(target);
    while(drivePID.GetTimeSinceTargetReached() < 1 && drivePID.GetTimeSinceTargetSet() < timeOut)
    {
        pros::c::delay(20);
    }
}

void DiffDrive::setBrakeMode(pros::motor_brake_mode_e mode)
{
    leftMotors.setBrakeMode(mode);
}

void DiffDrive::setDrivePIDVals(double kp, double ki, double kd)
{
    drivePID.SetPIDConst(kp, ki, kd);
}

void DiffDrive::setTurnPIDVals(double kp, double ki, double kd)
{
    turnPID.SetPIDConst(kp, ki, kd); 
}

void DiffDrive::setDrivePIDTol(double tolerance)
{
    drivePID.SetTolerance(tolerance);
}

void DiffDrive::setTurnPIDTol(double tolerance)
{
    turnPID.SetTolerance(tolerance);
}

double DiffDrive::getDrivePosition()
{
    return (leftMotors.getPosition() + rightMotors.getPosition()) / 2;
}

void DiffDrive::setDriveVelocity(double value)
{
    driveVelocity = value;
    setMotorVelocities();
}

double DiffDrive::getTurnPosition()
{
    double current = intertial.get_heading();
    double target = turnPID.GetTarget();

    if (current - target > 180)
    {
        return current - 360;
    }
    else if (target - current > 180)
    {
        return current + 360;
    }
    else
    {
        return current;
    }
}

void DiffDrive::setTurnVelocity(double value)
{
    turnVelocity = value;
    setMotorVelocities();
}

void DiffDrive::setMotorVelocities()
{
    double targetLeftSpeed = driveVelocity + turnVelocity;
    double targetRightSpeed = driveVelocity - turnVelocity;
    double scaleFactor = min(MAX_SPEED / max(fabs(targetLeftSpeed), fabs(targetRightSpeed)), 1.0);

    leftMotors.moveVelocity(targetLeftSpeed * scaleFactor);
    rightMotors.moveVelocity(targetRightSpeed* scaleFactor);
}





//--------------------nested classes-----------------------


DiffDrive::DriveInterface::DriveInterface(DiffDrive* pParent)
{
    parent = pParent;
}

double DiffDrive::DriveInterface::getPositionPID()
{
    return parent->getDrivePosition();
}

void DiffDrive::DriveInterface::setVelocityPID(double value)
{
    parent->setDriveVelocity(value);
}

DiffDrive::TurnInterface::TurnInterface(DiffDrive* pParent)
{
    parent = pParent;
}

double DiffDrive::TurnInterface::getPositionPID()
{
    return parent->getTurnPosition();
}

void DiffDrive::TurnInterface::setVelocityPID(double value)
{
    parent->setTurnVelocity(value);
}

