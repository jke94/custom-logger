#pragma once

#if defined(_WIN32)
    #define LOGGER_API __declspec(dllexport)
#elif defined(__GNUC__)
    #define LOGGER_API __attribute__((visibility("default")))
#else
    #define EXPORT
    #define IMPORT
    #pragma warning Unknown dynamic link import/export semantics.
#endif

#include <cstring>
#include <string>

#if defined(_WIN32) || defined(__CYGWIN__)
	#define __FILENAME__ (strrchr(__FILE__, '\\') ? strrchr(__FILE__, '\\') + 1 : __FILE__)
#elif defined(__linux__)
	#define __FILENAME__ (strrchr(__FILE__, '/') ? strrchr(__FILE__, '/') + 1 : __FILE__)
#else
	#error Ey! Unknown environment!
#endif

class ILogger
{
public:

    virtual void log_trace(const char* file, const char* function, const int line, const std::string& msg) = 0;
    virtual void log_info(const char* file, const char* function, const int line, const std::string& msg) = 0;
    virtual void log_warning(const char* file, const char* function, const int line, const std::string& msg) = 0;
    virtual void log_error(const char* file, const char* function, const int line, const std::string& msg) = 0;
    virtual void log_critical(const char* file, const char* function, const int line, const std::string& msg) = 0;
};

enum LoggerLevel : uint16_t
{
    TRACE_CHANNEL       = 0x0001,   // 2^0      1
    INFO_CHANNEL        = 0x0002,   // 2^1      2
    WARNING_CHANNEL     = 0x0004,   // 2^2      4
    ERROR_CHANNEL       = 0x0008,   // 2^3      8
    CRITICAL_CHANNEL    = 0x0010    // 2^4      16
};

LOGGER_API void init_logger(std::string log_file_name, uint16_t log_channel);
LOGGER_API void end_logger();

LOGGER_API void log_trace_def(const char* file, const char* function, const int line, const std::string& msg);
#define WRITE_TRACE(msg) log_trace_def( __FILENAME__, __FUNCTION__, __LINE__ , msg)

LOGGER_API void log_info_def(const char* file, const char* function, const int line, const std::string& msg);
#define WRITE_INFO(msg) log_info_def(__FILENAME__, __FUNCTION__, __LINE__ , msg)

LOGGER_API void log_warning_def(const char* file, const char* function, const int line, const std::string& msg);
#define WRITE_WARNING(msg) log_warning_def(__FILENAME__, __FUNCTION__, __LINE__ , msg)

LOGGER_API void log_error_def(const char* file, const char* function, const int line, const std::string& msg);
#define WRITE_ERROR(msg) log_error_def(__FILENAME__, __FUNCTION__, __LINE__ , msg)

LOGGER_API void log_critical_def(const char* file, const char* function, const int line, const std::string& msg);
#define WRITE_CRITICAL(msg) log_critical_def(__FILENAME__, __FUNCTION__, __LINE__ , msg)