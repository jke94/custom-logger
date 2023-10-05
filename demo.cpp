#include <iostream>

enum LoggerLevel : uint16_t
{
    TRACE       = 0x0001,   // 2^0      1
    INFO        = 0x0002,   // 2^1      2
    WARNING     = 0x0004,   // 2^2      4
    ERROR       = 0x0008,   // 2^3      8
    CRITICAL    = 0x0010    // 2^4      16
};


bool apply_filter(uint16_t flag)
{
    if ((flag & LoggerLevel::TRACE) == LoggerLevel::TRACE)
    {
        return true;
    }
    if ((flag & LoggerLevel::INFO) == LoggerLevel::INFO)
    {
        return true;
    }
    if ((flag & LoggerLevel::WARNING) == LoggerLevel::WARNING)
    {
        return true;
    }
    if ((flag & LoggerLevel::ERROR) == LoggerLevel::ERROR)
    {
        return true;
    }
    if ((flag & LoggerLevel::CRITICAL) == LoggerLevel::CRITICAL)
    {
        return true;
    }

    return false;
}


int main()
{
    uint16_t flag = LoggerLevel::INFO | LoggerLevel::WARNING;

    std::cout << "flag: " << flag << std::endl;

    if ((flag & LoggerLevel::TRACE) == LoggerLevel::TRACE)
    {
        std::cout << "Activated: LoggerLevel::TRACE" << std::endl;
    }
    if ((flag & LoggerLevel::INFO) == LoggerLevel::INFO)
    {
        std::cout << "Activated: LoggerLevel::INFO" << std::endl;
    }
    if ((flag & LoggerLevel::WARNING) == LoggerLevel::WARNING)
    {
        std::cout << "Activated: LoggerLevel::WARNING" << std::endl;
    }
    if ((flag & LoggerLevel::ERROR) == LoggerLevel::ERROR)
    {
        std::cout << "Activated: LoggerLevel::ERROR" << std::endl;
    }
    if ((flag & LoggerLevel::CRITICAL) == LoggerLevel::CRITICAL)
    {
        std::cout << "Activated: LoggerLevel::CRITICAL" << std::endl;
    }

    return 0;
}