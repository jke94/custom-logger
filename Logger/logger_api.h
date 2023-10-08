// #pragma once

#include <cstring>
#include <string>

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