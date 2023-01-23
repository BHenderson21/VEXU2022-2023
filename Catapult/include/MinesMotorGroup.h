#ifndef MINES_MOTOR_GROUP
#define MINES_MOTOR_GROUP

#include <vector>
#include "api.h"
#include "pros/motors.hpp"

namespace Mines {


class MinesMotorGroup
{
    const int NOT_INITIALIZED_CODE = -2;

    //variables
    std::vector<pros::Motor> motorVector;
    bool initialized = false;
    int size;

    //public functions
    public:
        MinesMotorGroup(std::vector<pros::Motor> &motors);
        MinesMotorGroup(pros::Motor motors[], int numMotors);

        int move(const int voltage);
        int moveVelocity(const int velocity);
        int brake();
        int tarePosition();
        int setBrakeMode(pros::motor_brake_mode_e mode);
        double getActualVelocity();
        double getMaxVelocity();
        double getPosition();


    //private functions
    private:

};

}

#endif
