#pragma once

#include <string>

typedef void (*LOG_TRACE)(std::string msg);
typedef void (*LOG_INFO)(std::string msg);
typedef void (*LOG_WARNING)(std::string msg);
typedef void (*LOG_ERROR)(std::string msg);
typedef void (*LOG_CRITICAL)(std::string msg);

#ifdef  __cplusplus

extern "C" 
{
#endif

    void log_trace(std::string msg);    
    void log_info(std::string msg);    
    void log_warning(std::string msg);    
    void log_error(std::string msg);    
    void log_critical(std::string msg);    

#ifdef  __cplusplus
}
#endif