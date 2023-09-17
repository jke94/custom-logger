#include "logger.h"

std::mutex mtx;

Logger::Logger()
{
}

Logger::~Logger()
{
}

void Logger::log_trace(std::string msg)
{
    log(msg, LoggerLevel::TRACE);
}

void Logger::log_info(std::string msg)
{
    log(msg, LoggerLevel::INFO);
}

void Logger::log_warning(std::string msg)
{
    log(msg, LoggerLevel::WARNING);
}

void Logger::log_error(std::string msg)
{
    log(msg, LoggerLevel::ERROR);
}

void Logger::log_critical(std::string msg)
{
    log(msg, LoggerLevel::CRITICAL);
}

void Logger::log(std::string msg, LoggerLevel level)
{
    mtx.lock();

    std::ofstream myfile;
    myfile.open("application.log", std::ios_base::app);
    myfile << date_and_time() << " | " << LoggerLevelToStr(level) << " | " << msg << "\n";
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


std::string Logger::LoggerLevelToStr(LoggerLevel level)
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