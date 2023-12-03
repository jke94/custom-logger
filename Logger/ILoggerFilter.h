#pragma once

class ILoggerFilter
{
    public:
        virtual bool apply_filter(uint16_t level) = 0;
        virtual uint16_t get_log_filter_level() = 0;
};
