#include "pch.h"
#include <sstream> 

std::mutex mtx;

Logger::Logger(std::string log_file_name, uint16_t log_channel)
{
    log_file_name_ = log_file_name;
    logger_filter_ = new LoggerFilter(log_channel);
}

Logger::~Logger()
{
    delete(logger_filter_);
}

void Logger::log_trace(const char* file, const char* function, const int line, const std::string& msg)
{
    log(file, function, line, msg, LoggerLevel::TRACE_CHANNEL);
}

void Logger::log_info(const char* file, const char* function, const int line, const std::string& msg)
{
    log(file, function, line, msg, LoggerLevel::INFO_CHANNEL);
}

void Logger::log_warning(const char* file, const char* function, const int line, const std::string& msg)
{
    log(file, function, line, msg, LoggerLevel::WARNING_CHANNEL);
}

void Logger::log_error(const char* file, const char* function, const int line, const std::string& msg)
{
    log(file, function, line, msg, LoggerLevel::ERROR_CHANNEL);
}

void Logger::log_critical(const char* file, const char* function, const int line, const std::string& msg)
{
    log(file, function, line, msg, LoggerLevel::CRITICAL_CHANNEL);
}

void Logger::log(const char* file, const char* function, const int line, const std::string& msg, uint16_t log_level)
{
    mtx.lock();

    bool apply_filter = logger_filter_->apply_filter(log_level);
 
    // std::cout << "get_log_filter_level: " << logger_filter_->get_log_filter_level() << ", apply_filter: " << apply_filter << ", log_level: " << log_level << std::endl;

    if(apply_filter)
    {
        std::string tmp_file(file);
        std::string tmp_function(function);
        std::string temp_msg = "[" + tmp_file  + ":" + tmp_function + ":" + std::to_string(line) + "] " + msg;

        std::ofstream myfile;
        
        myfile.open(log_file_name_, std::ios_base::app);
        
        myfile << date_and_time() << " | " << 
        logger_level_to_str(log_level) << " | " << 
        temp_msg << "\n";
        
        myfile.close();
    }

    mtx.unlock();
}

std::string Logger::date_and_time()
{
    const auto now = std::chrono::system_clock::now();
    const auto nowAsTimeT = std::chrono::system_clock::to_time_t(now);
    const auto nowMs = std::chrono::duration_cast<std::chrono::milliseconds>(now.time_since_epoch()) % 1000;
    
    std::stringstream nowSs{};
      
#if defined(_WIN32) || defined(__CYGWIN__)

    time_t rawtime = std::time(nullptr);
    struct tm timeinfo;
    auto lc_time =  localtime_s(&timeinfo, &rawtime);

    nowSs << std::put_time(&timeinfo, "%Y-%m-%d %X")
    << '.' << std::setfill('0') << std::setw(3) << nowMs.count();

#elif defined(__linux__)

    nowSs << std::put_time(std::localtime(&nowAsTimeT), "%Y-%m-%d %X")
        << '.' << std::setfill('0') << std::setw(3) << nowMs.count();
#else
    nowSs << "[ERROR_GET_TIME]";
#endif

    return nowSs.str();
}


std::string Logger::logger_level_to_str(uint16_t log_level)
{
    std::string value = "";

    switch (log_level)
    {
        case LoggerLevel::TRACE_CHANNEL:
            value = "[TRACE]";
            break;
        case LoggerLevel::INFO_CHANNEL:
            value = "[INFO]";
            break;
        case LoggerLevel::WARNING_CHANNEL:
            value = "[WARNING]";
            break;
        case LoggerLevel::ERROR_CHANNEL:
            value = "[ERROR]";
            break;
        case LoggerLevel::CRITICAL_CHANNEL:
            value = "[CRITICAL]";
            break;
        default:
            break;
    }

    return value;
};