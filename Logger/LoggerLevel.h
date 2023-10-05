#include <iostream>

enum LoggerLevel : uint16_t
{
    TRACE       = 0x0001,   // 2^0      1
    INFO        = 0x0002,   // 2^1      2
    WARNING     = 0x0004,   // 2^2      4
    ERROR       = 0x0008,   // 2^3      8
    CRITICAL    = 0x0010    // 2^4      16
};