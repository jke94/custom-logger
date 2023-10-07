#include <iostream>

#include "ILoggerFilter.h"
#include "logger_api.h"
#include "LoggerLevel.h"

class LoggerFilter : public ILoggerFilter
{
    private:
        uint16_t log_level_ = LoggerLevel::WARNING | LoggerLevel::CRITICAL;
    public:
        LoggerFilter();
        ~LoggerFilter();
        bool apply_filter(uint16_t level) override;
        uint16_t get_log_filter_level() override;
};
