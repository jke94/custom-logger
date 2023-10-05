#include "loggerFilter.h"

LoggerFilter::LoggerFilter()
{
}

LoggerFilter::~LoggerFilter()
{
}

bool LoggerFilter::apply_filter(uint16_t level)
{
    if ((log_level_ & level) == LoggerLevel::TRACE)
    {
        return true;
    }
    if ((log_level_ & level) == LoggerLevel::INFO)
    {
        return true;
    }
    if ((log_level_ & level) == LoggerLevel::WARNING)
    {
        return true;
    }
    if ((log_level_ & level) == LoggerLevel::ERROR)
    {
        return true;
    }
    if ((log_level_ & level) == LoggerLevel::CRITICAL)
    {
        return true;
    }

    return false;
}

uint16_t LoggerFilter::get_log_filter_level()
{
    return log_level_;
}