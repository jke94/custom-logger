#include "logger_api.h"
#include "logger.h"


ILogger* logger = new Logger;

void log_trace(const char* file, const char* function, const int line, const std::string& msg)
{
    logger->log_trace(file, function, line, msg);
}

void log_info(const char* file, const char* function, const int line, const std::string& msg)
{
    logger->log_info(file, function, line, msg);
}

void log_warning(const char* file, const char* function, const int line, const std::string& msg)
{
    logger->log_warning(file, function, line, msg);
}

void log_error(const char* file, const char* function, const int line, const std::string& msg)
{
    logger->log_error(file, function, line, msg);
}

void log_critical(const char* file, const char* function, const int line, const std::string& msg)
{
    logger->log_critical(file, function, line, msg);
}