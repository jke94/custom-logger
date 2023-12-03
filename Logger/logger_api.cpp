#include "logger_api.h"
#include "logger.h"

ILogger* logger = nullptr;

LOGGER_API void init_logger(std::string log_file_name, uint16_t log_channel)
{
    logger = new Logger(log_file_name, log_channel);
}

LOGGER_API void end_logger()
{
    logger = nullptr;
}

LOGGER_API void log_trace_def(const char* file, const char* function, const int line, const std::string& msg)
{
    if(logger)
    {
        logger->log_trace(file, function, line, msg);
    }    
}

LOGGER_API void log_info_def(const char* file, const char* function, const int line, const std::string& msg)
{
    if(logger)
    {
        logger->log_info(file, function, line, msg);
    }
}

LOGGER_API void log_warning_def(const char* file, const char* function, const int line, const std::string& msg)
{
    if(logger)
    {
        logger->log_warning(file, function, line, msg);
    } 
}

LOGGER_API void log_error_def(const char* file, const char* function, const int line, const std::string& msg)
{
    if(logger)
    {
        logger->log_error(file, function, line, msg);
    } 
}

LOGGER_API void log_critical_def(const char* file, const char* function, const int line, const std::string& msg)
{
    if(logger)
    {
        logger->log_critical(file, function, line, msg);
    } 
}