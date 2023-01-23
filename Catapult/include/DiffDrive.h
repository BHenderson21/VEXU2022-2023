#ifndef DIFF_DRIVE
#define DIFF_DRIVE

#include "MinesMotorGroup.h"
#include "PID.h"
#include "pros/imu.hpp"
#include <math.h>

namespace Mines {

class DiffDrive
{
    //static nested classes
    class DriveInterface : public PIDInterface
    {
        DiffDrive* parent;

        public:
            DriveInterface(DiffDrive* pParent);

            double getPositionPID() override;
            void setVelocityPID(double value) override;
    };
    class TurnInterface : public PIDInterface
    {
        DiffDrive* parent;

        public:
            TurnInterface(DiffDrive* pParent);

            double getPositionPID() override;
            void setVelocityPID(double value) override;
    };

    //instance variables
    MinesMotorGroup leftMotors;
    MinesMotorGroup rightMotors;
    pros::Imu intertial;
    DriveInterface driveInterface;
    TurnInterface turnInterface;
    PID drivePID;
    PID turnPID;

    //configuration variables
    double MAX_SPEED;


    //updateable variables
    double turnVelocity = 0;
    double driveVelocity = 0;

    public:
        DiffDrive(MinesMotorGroup left, MinesMotorGroup right, pros::Imu Imu);

        void driveTiles(double target, bool waitForCompletion=true);
        void driveTiles(double target, double timeOut);
        void turnDegreesAbsolute(double target, bool waitForCompletion=true);
        void turnDegreesAbsolute(double target, double timeOut);

        //configuration functions
        void setBrakeMode(pros::motor_brake_mode_e mode);
        void setDrivePIDVals(double kp, double ki, double kd);
        void setTurnPIDVals(double kp, double ki, double kd);
        void setDrivePIDTol(double tolerance);
        void setTurnPIDTol(double tolerance);



    private:
        double getDrivePosition();
        void setDriveVelocity(double value);
        double getTurnPosition();
        void setTurnVelocity(double value);
        void setMotorVelocities();

};

}

#endif

