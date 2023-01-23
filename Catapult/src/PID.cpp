#include "PID.h"
#include "display/lv_misc/lv_task.h"
#include "pros/rtos.h"
#include "pros/rtos.hpp"

using namespace std;

namespace Mines
{
    PID::PID(PIDInterface *inputInterface)
    {
        interface = inputInterface;
    }

    void PID::update(double deltaT)
    {
        double currentPosition = getPosition();
        double error = target - currentPosition;
        double positional = KP * error;
        double integral = KI * ( lastIntergral + (error * deltaT));
        double derivative = KD * ((error - lastError) / deltaT);
        double controlVariable = positional + integral + derivative;

        //setting loop variables
        if (error != NAN)
        {
            lastError = error;
        }
        if (integral == NAN)
        {
            lastIntergral = 0; 
        }

        //updating times
        timeSinceTargetSet += deltaT;
        if(fabs(target - currentPosition) < tolerance)
        {
            timeSinceTargetReached += deltaT;
        }

        //setting output variables
        setOutput(controlVariable);
    }

    void PID::updateTask()
    {
        std::uint32_t startTime = pros::millis();
        int deltaTime = 20;
        int count = 0;

        while(true)
        {
            count++;
            update(deltaTime);
            
            pros::Task::delay(deltaTime);
        }
    }

    double PID::getPosition()
    {
        return interface->getPositionPID();
    }

    void PID::setOutput(double value)
    {
        velocity = value;
        interface->setVelocityPID(value);
    }

    void PID::taskStarter(void* arg)
    {
        PID* pidPtr = static_cast<PID *>(arg);  
        pidPtr->updateTask();
    }

    void PID::StartTask(){
        pros::Task my_task(taskStarter, this, "PID task");
    }

    //----------------Getters/Setters-------------------
    void PID::resetTimers()
    {
        timeSinceTargetReached = 0;
        timeSinceTargetSet = 0;
    }

    void PID::SetPIDConst(double kp, double ki, double kd)
    {
        KP = kp;
        KI = ki;
        KD = kd;
    }

    void PID::SetTolerance(double tolerance)
    {
        this->tolerance = tolerance;
    }

    void PID::SetTarget(double target)
    {
        resetTimers();
        this->target = target;
    }

    void PID::SetStopped(bool stopped)
    {
        this->stopped = stopped;
    }

    double PID::GetVelocity()
    {
        return velocity;
    }

    double PID::GetTimeSinceTargetReached()
    {
        return timeSinceTargetReached;
    }

    double PID::GetTimeSinceTargetSet()
    {
        return timeSinceTargetSet;
    }

    bool PID::GetStopped()
    {
        return stopped;
    }

    double PID::GetTarget()
    {
        return target;
    }
}

