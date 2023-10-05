#include "loggerFilter.h"

LoggerFilter::LoggerFilter()
{
    std::cout << log_level_ << std::endl;
    log_level_ = LoggerLevel::TRACE | LoggerLevel::INFO;
    std::cout << log_level_ << std::endl;
}

LoggerFilter::~LoggerFilter()
{
}

bool LoggerFilter::apply_filter()
{
    if (log_level_ & LoggerLevel::TRACE)
    {
        std::cout <<"TRACE" << std::endl;
        return true;
    }
    if (log_level_ & LoggerLevel::INFO)
    {
        return true;
    }
    if (log_level_ & LoggerLevel::WARNING)
    {
        return true;
    }
    if (log_level_ & LoggerLevel::ERROR)
    {
        return true;
    }
    if (log_level_ & LoggerLevel::CRITICAL)
    {
        return true;
    }

    return false;
}