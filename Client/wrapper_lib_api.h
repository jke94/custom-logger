#include <iostream>
#include <string>

#include "logger_api.h"

void write_log_trace(std::string msg);
void write_log_info(std::string msg);
void write_log_warning(std::string msg);
void write_log_error(std::string msg);
void write_log_critical(std::string msg);

#define WRITE_LOG_TRACE(msg) write_log_trace(msg)
#define WRITE_LOG_INFO(msg) write_log_info(msg)
#define WRITE_LOG_WARNING(msg) write_log_warning(msg)
#define WRITE_LOG_ERROR(msg) write_log_error(msg)
#define WRITE_LOG_CRITICAL(msg) write_log_critical(msg)


void write_log_trace(std::string msg)
{
    WRITE_TRACE(msg);
}

void write_log_info(std::string msg)
{
    WRITE_INFO(msg);
}

void write_log_warning(std::string msg)
{
    WRITE_WARNING(msg);
}

void write_log_error(std::string msg)
{
    WRITE_ERROR(msg);
}

void write_log_critical(std::string msg)
{
    WRITE_CRITICAL(msg);
}