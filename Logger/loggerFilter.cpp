#include "pch.h"

LoggerFilter::LoggerFilter(uint16_t log_level)
{
    log_level_ = log_level;
}

LoggerFilter::~LoggerFilter()
{
}

bool LoggerFilter::apply_filter(uint16_t level)
{
    uint16_t flag = log_level_ & level;

    switch(flag)
    {
        case LoggerLevel::TRACE_CHANNEL:
        case LoggerLevel::INFO_CHANNEL:
        case LoggerLevel::WARNING_CHANNEL:
        case LoggerLevel::ERROR_CHANNEL:
        case LoggerLevel::CRITICAL_CHANNEL:
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