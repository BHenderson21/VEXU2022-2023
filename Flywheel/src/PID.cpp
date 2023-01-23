#include "PID.h"
#include "display/lv_misc/lv_task.h"
#include "pros/rtos.h"
#include "pros/rtos.hpp"

using namespace std;

namespace Mines
{
    PID::PID(PIDInterface *inputInterface, LoggerSettings settings) : logger(settings)
    {
        interface = inputInterface;
    }

    void PID::update(double deltaT)
    {
        double currentPosition = getPosition();
        logger.Log(("current position: " + std::to_string(currentPosition)).c_str(), 0, LoggerSettings::verbose);
        double error = target - currentPosition;
        logger.Log(("current error value: " + std::to_string(error)).c_str(), 1, LoggerSettings::verbose);

        double positional = KP * error;
        double integral = KI * ( lastIntergral + (error * deltaT));
        double derivative = KD * ((error - lastError) / deltaT);
        logger.Log(("positional: " + std::to_string(positional)).c_str(), 2, LoggerSettings::verbose);
        logger.Log(("integral: " + std::to_string(integral)).c_str(), 3, LoggerSettings::verbose);
        logger.Log(("derivative: " + std::to_string(derivative)).c_str(), 4, LoggerSettings::verbose);

        double controlVariable = positional + integral + derivative;
        logger.Log(("controlVariable: " + std::to_string(controlVariable)).c_str(), 6, LoggerSettings::verbose);


        //setting loop variables
        if (error != NAN)
        {
            logger.Log(("error: " + std::to_string(error)).c_str(), 8, LoggerSettings::verbose); 
            lastError = error;
        }
        else
        {
            logger.Log("ERROR: error is Nan", 8, LoggerSettings::error);
        }
        
        if (integral == NAN)
        {
            logger.Log("ERROR: integral is Nan", 9, LoggerSettings::error);
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

