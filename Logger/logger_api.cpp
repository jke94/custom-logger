#include "logger_api.h"
#include "logger.h"

ILogger* logger = new Logger;

void log_trace(std::string msg)
{
    logger->log_trace(msg);
}

void log_info(std::string msg)
{
    logger->log_info(msg);
}

void log_warning(std::string msg)
{
    logger->log_warning(msg);
}

void log_error(std::string msg)
{
    logger->log_error(msg);
}

void log_critical(std::string msg)
{
    logger->log_critical(msg);
}