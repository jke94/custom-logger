#include <cstring>
#include <string>

#if defined(_WIN32) || defined(__CYGWIN__)
	#define __FILENAME__ (strrchr(__FILE__, '\\') ? strrchr(__FILE__, '\\') + 1 : __FILE__)
#elif defined(__linux__)
	#define __FILENAME__ (strrchr(__FILE__, '/') ? strrchr(__FILE__, '/') + 1 : __FILE__)
#else
	#error Unknown environment!
#endif

void init_logger(std::string log_file_name);
void end_logger();

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