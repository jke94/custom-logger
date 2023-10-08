#pragma once
#include <iostream>

enum LoggerLevel : uint16_t
{
    TRACE_CHANNEL       = 0x0001,   // 2^0      1
    INFO_CHANNEL        = 0x0002,   // 2^1      2
    WARNING_CHANNEL     = 0x0004,   // 2^2      4
    ERROR_CHANNEL       = 0x0008,   // 2^3      8
    CRITICAL_CHANNEL    = 0x0010    // 2^4      16
};