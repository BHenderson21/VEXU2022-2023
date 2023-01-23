#ifndef ODOMETRY_H
#define ODOMETRY_H

#include "MinesMotorGroup.h"
#include "pros/imu.hpp"

namespace Mines {


struct Position
{
    double x;
    double y;
};


class DiffDriveOdometry
{
    private:
        pros::Imu inertial;
        MinesMotorGroup leftMotors;
        MinesMotorGroup rightMotors;

        double width;
        double length;
        double wheelSize;

        Position position;

        static void taskStarter(void* arg);
        void updateTask();
        void StartTask();
        void update(double deltaT);

    public:
        DiffDriveOdometry(MinesMotorGroup left, MinesMotorGroup right, pros::Imu imu);

        void setStats(double baseWidth, double baseLength, double circumference); //using cm for the moment

        double getHeading();
        Position getPosition();
};




}

#endif 


