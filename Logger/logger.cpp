#include "logger.h"

std::mutex mtx;

Logger::Logger(std::string log_file_name)
{
    log_file_name_ = log_file_name;
}

Logger::~Logger()
{
}

void Logger::log_trace(const char* file, const char* function, const int line, const std::string& msg)
{
    log(file, function, line, msg, LoggerLevel::TRACE);
}

void Logger::log_info(const char* file, const char* function, const int line, const std::string& msg)
{
    log(file, function, line, msg, LoggerLevel::INFO);
}

void Logger::log_warning(const char* file, const char* function, const int line, const std::string& msg)
{
    log(file, function, line, msg, LoggerLevel::WARNING);
}

void Logger::log_error(const char* file, const char* function, const int line, const std::string& msg)
{
    log(file, function, line, msg, LoggerLevel::ERROR);
}

void Logger::log_critical(const char* file, const char* function, const int line, const std::string& msg)
{
    log(file, function, line, msg, LoggerLevel::CRITICAL);
}

void Logger::log(const char* file, const char* function, const int line, const std::string& msg, LoggerLevel level)
{
    mtx.lock();

    std::string tmp_file(file);
    std::string tmp_function(function);
    std::string temp_msg = "[" + tmp_file  + ":" + tmp_function + ":" + std::to_string(line) + "] " + msg;

    std::ofstream myfile;
    
    myfile.open(log_file_name_, std::ios_base::app);
    
    myfile << date_and_time() << " | " << 
    logger_level_to_str(level) << " | " << 
    temp_msg << "\n";

    myfile.close();

    mtx.unlock();
}

std::string Logger::date_and_time()
{
    const auto now = std::chrono::system_clock::now();
    const auto nowAsTimeT = std::chrono::system_clock::to_time_t(now);
    const auto nowMs = std::chrono::duration_cast<std::chrono::milliseconds>(now.time_since_epoch()) % 1000;
    
    std::stringstream nowSs;
    nowSs << std::put_time(std::localtime(&nowAsTimeT), "%Y-%m-%d %X")
        << '.' << std::setfill('0') << std::setw(3) << nowMs.count();

  return nowSs.str();
}


std::string Logger::logger_level_to_str(LoggerLevel level)
{
    std::string value = "";

    switch (level)
    {
        case LoggerLevel::TRACE:
            value = "TRACE";
            break;
        case LoggerLevel::INFO:
            value = "INFO";
            break;
        case LoggerLevel::WARNING:
            value = "WARNING";
            break;
        case LoggerLevel::ERROR:
            value = "ERROR";
            break;
        case LoggerLevel::CRITICAL:
            value = "CRITICAL";
            break;
        default:
            break;
    }

    return value;
};