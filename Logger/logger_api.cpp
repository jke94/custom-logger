#include "pch.h"

ILogger* logger = nullptr;

void init_logger(std::string log_file_name, uint16_t log_channel)
{
    logger = new Logger(log_file_name, log_channel);
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