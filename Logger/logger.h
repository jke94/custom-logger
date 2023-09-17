#include <iostream>
#include <string>
#include <chrono>
#include <iomanip>
#include <mutex>
#include <thread>
#include <fstream>
#include "loggerAPI.h"

enum LoggerLevel 
{
    TRACE,
    INFO,
    WARNING,
    ERROR,
    CRITICAL
};

class ILogger
{
    public:
        virtual void log_trace(std::string msg) = 0;
        virtual void log_info(std::string msg) = 0;
        virtual void log_warning(std::string msg) = 0;
        virtual void log_error(std::string msg) = 0;
        virtual void log_critical(std::string msg) = 0;
};

class Logger : public ILogger
{
    private:
        static Logger* _logger;
        Logger();
        std::string date_and_time();
        void log(std::string msg, LoggerLevel level);

    public:
        
        static Logger* get_instance();
        ~Logger();
        void log_trace(std::string msg);
        void log_info(std::string msg);
        void log_warning(std::string msg);
        void log_error(std::string msg);
        void log_critical(std::string msg);
};

std::string LoggerLevelToStr(LoggerLevel level);