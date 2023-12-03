#pragma once

#include <iostream>
#include "logger_api.h"
#include "ILoggerFilter.h"

class LoggerFilter : public ILoggerFilter
{
    private:
        uint16_t log_level_;
    public:
        LoggerFilter(uint16_t log_level);
        ~LoggerFilter();
        bool apply_filter(uint16_t level) override;
        uint16_t get_log_filter_level() override;
};
