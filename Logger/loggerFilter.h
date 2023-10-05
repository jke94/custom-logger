#include <iostream>

#include "ILoggerFilter.h"
#include "logger_api.h"
#include "LoggerLevel.h"

class LoggerFilter : public ILoggerFilter
{
    private:
        uint16_t log_level_;
    public:
        LoggerFilter(/* args */);
        ~LoggerFilter();
        bool apply_filter();
};
