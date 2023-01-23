#ifndef LOGGER
#define LOGGER

#include "globals.h"
#include "pros/imu.hpp"
#include "pros/llemu.hpp"
#include "pros/motors.hpp"
#include "pros/rtos.h"

enum LoggerSettings
{
    none = 0, //do not use this for logging, only for the constructor
    exception = 1,
    error = 2,
    warning = 3,
    verbose = 4,
};

class ScreenLogger
{
    LoggerSettings printSetting;

    public:
        ScreenLogger(LoggerSettings setting);

        void Log(const char logLine[], int row, LoggerSettings setting);
};


#endif