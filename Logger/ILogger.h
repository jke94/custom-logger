#pragma once

class ILogger
{
public:

    virtual void log_trace(const char* file, const char* function, const int line, const std::string& msg) = 0;
    virtual void log_info(const char* file, const char* function, const int line, const std::string& msg) = 0;
    virtual void log_warning(const char* file, const char* function, const int line, const std::string& msg) = 0;
    virtual void log_error(const char* file, const char* function, const int line, const std::string& msg) = 0;
    virtual void log_critical(const char* file, const char* function, const int line, const std::string& msg) = 0;
};