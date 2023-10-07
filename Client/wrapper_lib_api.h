#include <iostream>
#include <string>

#include "logger_api.h"

#define WRITE_LOG_TRACE(msg) WRITE_TRACE(msg)
#define WRITE_LOG_INFO(msg) WRITE_INFO(msg)
#define WRITE_LOG_WARNING(msg) WRITE_WARNING(msg)
#define WRITE_LOG_ERROR(msg) WRITE_ERROR(msg)
#define WRITE_LOG_CRITICAL(msg) WRITE_CRITICAL(msg)


void write_log_trace(std::string msg)
{
    WRITE_LOG_TRACE(msg);
}

void write_log_info(std::string msg)
{
    WRITE_LOG_INFO(msg);
}

void write_log_warning(std::string msg)
{
    WRITE_LOG_WARNING(msg);
}

void write_log_error(std::string msg)
{
    WRITE_LOG_ERROR(msg);
}

void write_log_critical(std::string msg)
{
    WRITE_LOG_CRITICAL(msg);
}