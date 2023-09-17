#include "loggerAPI.h"
#include "logger.h"

// void log_trace(std::string msg)
void log_trace(const char* msg)
{
    // Logger::get_instance()->log_trace(msg);
    std::cout << msg << std::endl;
}
