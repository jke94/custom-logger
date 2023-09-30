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

        std::string log_file_name_;
        std::string date_and_time();
        std::string logger_level_to_str(LoggerLevel level);
        void log(const char* file, const char* function, const int line, const std::string& msg, LoggerLevel level);

    public:

        Logger(std::string log_file_name);
        ~Logger();
        
        void log_trace(const char* file, const char* function, const int line, const std::string& msg);
        void log_info(const char* file, const char* function, const int line, const std::string& msg);
        void log_warning(const char* file, const char* function, const int line, const std::string& msg);
        void log_error(const char* file, const char* function, const int line, const std::string& msg);
        void log_critical(const char* file, const char* function, const int line, const std::string& msg);
};