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
        void log(const char* file, const char* function, const int line, const std::string& msg, LoggerLevel level);
        std::string LoggerLevelToStr(LoggerLevel level);

    public:

        Logger();
        ~Logger();
        
        void log_trace(const char* file, const char* function, const int line, const std::string& msg);
        void log_info(const char* file, const char* function, const int line, const std::string& msg);
        void log_warning(const char* file, const char* function, const int line, const std::string& msg);
        void log_error(const char* file, const char* function, const int line, const std::string& msg);
        void log_critical(const char* file, const char* function, const int line, const std::string& msg);
};