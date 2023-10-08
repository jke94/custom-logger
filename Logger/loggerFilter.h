#pragma once
#include <iostream>
#include "LoggerLevel.h"

class LoggerFilter : public ILoggerFilter
{
    private:
        uint16_t log_level_ = LoggerLevel::WARNING_CHANNEL | LoggerLevel::CRITICAL_CHANNEL;
    public:
        LoggerFilter();
        ~LoggerFilter();
        bool apply_filter(uint16_t level) override;
        uint16_t get_log_filter_level() override;
};
