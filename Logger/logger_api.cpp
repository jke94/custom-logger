#include "logger_api.h"
#include "logger.h"

ILogger* logger = nullptr;

void init_logger(std::string log_file_name)
{
    logger = new Logger(log_file_name);
}

void end_logger()
{
    logger = nullptr;
}

void log_trace(const char* file, const char* function, const int line, const std::string& msg)
{
    if(logger)
    {
        logger->log_trace(file, function, line, msg);
    }    
}

void log_info(const char* file, const char* function, const int line, const std::string& msg)
{
    if(logger)
    {
        logger->log_info(file, function, line, msg);
    }
}

void log_warning(const char* file, const char* function, const int line, const std::string& msg)
{
    if(logger)
    {
        logger->log_warning(file, function, line, msg);
    } 
}

void log_error(const char* file, const char* function, const int line, const std::string& msg)
{
    if(logger)
    {
        logger->log_error(file, function, line, msg);
    } 
}

void log_critical(const char* file, const char* function, const int line, const std::string& msg)
{
    if(logger)
    {
        logger->log_critical(file, function, line, msg);
    } 
}