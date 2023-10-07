#include "loggerFilter.h"

LoggerFilter::LoggerFilter()
{
}

LoggerFilter::~LoggerFilter()
{
}

bool LoggerFilter::apply_filter(uint16_t level)
{
    uint16_t flag = log_level_ & level;

    switch(flag)
    {
        case LoggerLevel::TRACE:
        case LoggerLevel::INFO:
        case LoggerLevel::WARNING:
        case LoggerLevel::ERROR:
        case LoggerLevel::CRITICAL:
            return true;
        default:
            break;
    }

    return false;
}

uint16_t LoggerFilter::get_log_filter_level()
{
    return log_level_;
}