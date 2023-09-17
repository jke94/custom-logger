#pragma once
#include <iostream>

// LOG_INFO log_info(std::string msg);
// LOG_WARNING log_warning(std::string msg);
// LOG_ERROR log_error(std::string msg);
// LOG_CRITICAL log_critical(std::string msg);

#ifdef  __cplusplus

extern "C" 
{
#endif

    void log_trace(const char* msg);

#ifdef  __cplusplus
}
#endif