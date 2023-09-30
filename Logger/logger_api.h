// #pragma once

#ifndef __CUSTOMLOGGER_H__
#define __CUSTOMLOGGER_H__

#include <cstring>
#include <string>

#ifdef  __cplusplus

extern "C" 
{
#endif

// TODO: Investigate set logger level traces.

// #define WRITE_TRACE         0x00
// #define WRITE_INFO          0x01
// #define WRITE_WARNING       0x02
// #define WRITE_ERROR         0x03
// #define WRITE_CRITICAL      0x04

// #ifdef LOG_LEVEL
//     #define LOG_LEVEL   WRITE_CRITICAL
// #endif


// #ifdef LOG_LEVEL >= WRITE_TRACE
//     #define WRITE_TRACE(msg) log_trace(__FILE__, __FUNCTION__, __LINE__ , msg)
// #else
//     #define WRITE_TRACE(msg)
// #endif

// #ifdef LOG_LEVEL >= WRITE_INFO
//     #define WRITE_INFO(msg) log_info(__FILE__, __FUNCTION__, __LINE__ , msg)
// #else
//     #define WRITE_INFO(msg)
// #endif

    typedef void (*INIT_LOGGER)(std::string msg);
    void init_logger(std::string log_file_name);

    typedef void (*END_LOGGER)();
    void end_logger();

    #define __FILENAME__ (strrchr(__FILE__, '/') ? strrchr(__FILE__, '/') + 1 : __FILE__)

    void log_trace(const char* file, const char* function, const int line, const std::string& msg);
    #define WRITE_TRACE(msg) log_trace( __FILENAME__, __FUNCTION__, __LINE__ , msg)

    void log_info(const char* file, const char* function, const int line, const std::string& msg);
    #define WRITE_INFO(msg) log_info(__FILENAME__, __FUNCTION__, __LINE__ , msg)

    void log_warning(const char* file, const char* function, const int line, const std::string& msg);
    #define WRITE_WARNING(msg) log_warning(__FILENAME__, __FUNCTION__, __LINE__ , msg)

    void log_error(const char* file, const char* function, const int line, const std::string& msg);
    #define WRITE_ERROR(msg) log_error(__FILENAME__, __FUNCTION__, __LINE__ , msg)

    void log_critical(const char* file, const char* function, const int line, const std::string& msg);
    #define WRITE_CRITICAL(msg) log_critical(__FILENAME__, __FUNCTION__, __LINE__ , msg)

#ifdef  __cplusplus
}
#endif

#endif