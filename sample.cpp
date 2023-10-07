#include <iostream>
#include <map>

enum LoggerChannel : uint16_t
{
    TRACE       = 0x0001,   // 2^0      1
    INFO        = 0x0002,   // 2^1      2
    WARNING     = 0x0004,   // 2^2      4
    ERROR       = 0x0008,   // 2^3      8
    CRITICAL    = 0x0010    // 2^4      16
};

bool apply_filter(uint16_t log_level, uint16_t level)
{
    bool value = false;

    switch(log_level & level)
    {
        case LoggerChannel::TRACE:
        case LoggerChannel::INFO:
        case LoggerChannel::WARNING:
        case LoggerChannel::ERROR:
        case LoggerChannel::CRITICAL:
            value = true;
            break;
        default:
            value = false;
            break;
    }

    return value;
}

int main()
{
    std::map<LoggerChannel, std::string> msg_log_map = {
        {LoggerChannel::TRACE,    "Message: Activated LoggerChannel::TRACE"},
        {LoggerChannel::INFO,     "Message: Activated LoggerChannel::INFO"},
        {LoggerChannel::WARNING,  "Message: Activated LoggerChannel::WARNING"},
        {LoggerChannel::ERROR,    "Message: Activated LoggerChannel::ERROR"},
        {LoggerChannel::CRITICAL, "Message: Activated LoggerChannel::CRITICAL"}
    };

    // EXAMPLE A: Selecting the log level channels that you want to use.

    uint16_t sample_A_log_level = LoggerChannel::INFO | LoggerChannel::WARNING;

    std::cout << "sample_A_log_level: " << sample_A_log_level << std::endl;

    for (auto const& item : msg_log_map)
    {
        if(apply_filter(sample_A_log_level, item.first))
        {
            std::cout << "\t" << item.second << std::endl;
        }
    }

    // EXAMPLE B: Selecting all channels less two.

    uint16_t sample_B_log_level = ~(LoggerChannel::INFO | LoggerChannel::ERROR);

    std::cout << "sample_B_log_level: " << sample_B_log_level << std::endl;

    for (auto const& item : msg_log_map)
    {
        if(apply_filter(sample_B_log_level, item.first))
        {
            std::cout << "\t" << item.second << std::endl;
        }
    }

    return 0;
}