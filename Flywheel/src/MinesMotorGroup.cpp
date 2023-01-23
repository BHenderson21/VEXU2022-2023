#include "./../include/MinesMotorGroup.h"
#include "pros/motors.h"
#include "pros/motors.hpp"
#include <vector>

using namespace Mines;

MinesMotorGroup::MinesMotorGroup(pros::Motor motors[], int numMotors)
{
    if (!initialized)
    {
        for(int i = 0; i < numMotors; i++)
        {
            motorVector.push_back(motors[i]);
        }

        initialized = true;
        size = motorVector.size();
    }
}

MinesMotorGroup::MinesMotorGroup(std::vector<pros::Motor> &motors)
{
    if (!initialized)
    {
        for(int i = 0; i < motors.size() ; i++)
        {
            motorVector.push_back(motors[i]);
        }

        initialized = true;
        size = motorVector.size();
    }
}


int MinesMotorGroup::move(const int voltage)
{
    for(int i = 0; i < motorVector.size(); i++)
    {
        motorVector[i].move(voltage);
    }
    return 0;
}

int MinesMotorGroup::moveVelocity(const int velocity)
{
    for(int i = 0; i < motorVector.size(); i++)
    {
        motorVector[i].move_velocity(velocity);
    }
    return 0;
}

int MinesMotorGroup::brake()
{
    for(int i = 0; i < motorVector.size(); i++)
    {
        motorVector[i].brake();
    }
    return 0;
}

int MinesMotorGroup::tarePosition()
{
    for(int i = 0; i < motorVector.size(); i++)
    {
        motorVector[i].tare_position();
    }
    return 0;
}

int MinesMotorGroup::setBrakeMode(pros::motor_brake_mode_e mode)
{
    for(int i = 0; i < motorVector.size(); i++)
    {
        motorVector[i].set_brake_mode(mode);
    }
    return 0;
}

double MinesMotorGroup::getActualVelocity()
{
    double average = 0;
    for(int i = 0; i < motorVector.size(); i++)
    {
        average += motorVector[i].get_actual_velocity();
    }
    return average / motorVector.size();
}

double MinesMotorGroup::getPosition()
{
    double average = 0;
    for(int i = 0; i < motorVector.size(); i++)
    {
        average += motorVector[i].get_position();
    }
    return average / motorVector.size();
}

double MinesMotorGroup::getMaxVelocity()
{
    if(motorVector[0].get_gearing()== pros::E_MOTOR_GEARSET_36)
    {
        return 100;
    }
    if(motorVector[0].get_gearing() == pros::E_MOTOR_GEARSET_18)
    {
        return 200;
    }
    if(motorVector[0].get_gearing() == pros::E_MOTOR_GEARSET_06)
    {
        return 600;
    }
    return 0;
}
