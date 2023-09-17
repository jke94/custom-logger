#include <iostream>
#include <string>
#include <chrono>
#include <iomanip>
#include <mutex>
#include <thread>
#include <fstream>

#include "ILogger.h"
#include "logger_api.h"

enum LoggerLevel 
{
    TRACE,
    INFO,
    WARNING,
    ERROR,
    CRITICAL
};

class Logger : public ILogger
{
    private:

        std::string date_and_time();
        void log(std::string msg, LoggerLevel level);
        std::string LoggerLevelToStr(LoggerLevel level);

    public:

        Logger();
        ~Logger();
        void log_trace(std::string msg);
        void log_info(std::string msg);
        void log_warning(std::string msg);
        void log_error(std::string msg);
        void log_critical(std::string msg);
};