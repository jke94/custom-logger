// #pragma once

#ifndef __CUSTOMLOGGER_H__
#define __CUSTOMLOGGER_H__

#include <string>

// typedef void (*LOG_TRACE)(std::string msg);
// typedef void (*LOG_INFO)(std::string msg);
// typedef void (*LOG_WARNING)(std::string msg);
// typedef void (*LOG_ERROR)(std::string msg);
// typedef void (*LOG_CRITICAL)(std::string msg);

void log_trace(const char* file, const char* function, const int line, const std::string& msg);
void log_info(const char* file, const char* function, const int line, const std::string& msg);
void log_warning(const char* file, const char* function, const int line, const std::string& msg);
void log_error(const char* file, const char* function, const int line, const std::string& msg);
void log_critical(const char* file, const char* function, const int line, const std::string& msg);

#ifdef  __cplusplus

extern "C" 
{
#endif

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

#define WRITE_TRACE(msg) log_trace( __FILE__, __FUNCTION__, __LINE__ , msg)
#define WRITE_INFO(msg) log_info(__FILE__, __FUNCTION__, __LINE__ , msg)
#define WRITE_WARNING(msg) log_warning(__FILE__, __FUNCTION__, __LINE__ , msg)
#define WRITE_ERROR(msg) log_error(__FILE__, __FUNCTION__, __LINE__ , msg)
#define WRITE_CRITICAL(msg) log_critical(__FILE__, __FUNCTION__, __LINE__ , msg)

#ifdef  __cplusplus
}
#endif

#endif