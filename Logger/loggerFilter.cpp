#include "loggerFilter.h"

LoggerFilter::LoggerFilter()
{
}

LoggerFilter::~LoggerFilter()
{
}

bool LoggerFilter::apply_filter()
{
    if ((log_level_ & LoggerLevel::TRACE) == LoggerLevel::TRACE)
    {
        return true;
    }
    if ((log_level_ & LoggerLevel::INFO) == LoggerLevel::INFO)
    {
        return true;
    }
    if ((log_level_ & LoggerLevel::WARNING) == LoggerLevel::WARNING)
    {
        return true;
    }
    if ((log_level_ & LoggerLevel::ERROR) == LoggerLevel::ERROR)
    {
        return true;
    }
    if ((log_level_ & LoggerLevel::CRITICAL) == LoggerLevel::CRITICAL)
    {
        return true;
    }

    return false;
}