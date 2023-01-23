#include "odometry.h"

using namespace Mines;

DiffDriveOdometry::DiffDriveOdometry(MinesMotorGroup left, MinesMotorGroup right, pros::IMU imu) : 
    leftMotors(left), rightMotors(right), inertial(imu)
{
    position.x = 0;
    position.y = 0;
}


void DiffDriveOdometry::setStats(double baseWidth, double baseLength, double circumference)
{
    width = baseWidth;
    length = baseLength;
    wheelSize = circumference;
}


double DiffDriveOdometry::getHeading()
{
    return inertial.get_heading();
}

Position DiffDriveOdometry::getPosition()
{
    Position retPos;
    retPos.x = position.x;
    retPos.y = position.y;
    return retPos;
}



// Async 

void DiffDriveOdometry::update(double deltaT)
{
    
}

void DiffDriveOdometry::updateTask()
{
    std::uint32_t startTime = pros::millis();
    int deltaTime = 5;
    int count = 0;

    while(true)
    {
        count++;
        update(deltaTime);
        
        pros::Task::delay(deltaTime);
    }
}

void DiffDriveOdometry::taskStarter(void* arg)
{
    DiffDriveOdometry* pidPtr = static_cast<DiffDriveOdometry *>(arg);  
    pidPtr->updateTask();
}

void DiffDriveOdometry::StartTask(){
    pros::Task my_task(taskStarter, this, "PID task");
}
