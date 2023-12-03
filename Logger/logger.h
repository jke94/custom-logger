#include <iostream>
#include <string>
#include <chrono>
#include <iomanip>
#include <mutex>
#include <thread>
#include <fstream>

#include "logger_api.h"
#include "loggerFilter.h"
#include "ILogger.h"

class Logger : public ILogger
{
    private:

        std::string log_file_name_;
        ILoggerFilter* logger_filter_ = nullptr;

        std::string date_and_time();
        std::string logger_level_to_str(uint16_t log_level);
        void log(const char* file, const char* function, const int line, const std::string& msg, uint16_t log_level);

    public:

        Logger(std::string log_file_name, uint16_t log_channel);
        ~Logger();
        
        void log_trace(const char* file, const char* function, const int line, const std::string& msg);
        void log_info(const char* file, const char* function, const int line, const std::string& msg);
        void log_warning(const char* file, const char* function, const int line, const std::string& msg);
        void log_error(const char* file, const char* function, const int line, const std::string& msg);
        void log_critical(const char* file, const char* function, const int line, const std::string& msg);
};