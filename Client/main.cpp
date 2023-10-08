#if defined(_WIN32) || defined(__CYGWIN__)
    #include <windows.h>
#elif defined(__linux__)
    #include <dlfcn.h>
#else
    #include <dlfcn.h>
#endif

#include <iostream>
#include <thread>
#include "wrapper_lib_api.h"

int main()
{
    init_logger("application.log");

    WRITE_LOG_TRACE("Hello Javi! Come on!");
    
    const int n_threads = 100;
    std::thread threads[n_threads] = {};

    WRITE_LOG_INFO("START!");

    WRITE_LOG_INFO("YUJUUUU!");

    for(int i=0; i<n_threads; i++)
    {
        if(i % 2 == 0)
        {
            threads[i] = std::thread(write_log_trace, "[THREAD] " + std::to_string(i) + ": A simple trace message.");
        }
        else if (i % 3 == 0)
        {
            threads[i] = std::thread(write_log_info, "[THREAD] " + std::to_string(i) + ": A simple info message");
        }
        else if (i % 5 == 0)
        {
            threads[i] = std::thread(write_log_warning, "[THREAD] " + std::to_string(i) + ": A simple info message");
        }
        else if (i % 7 == 0)
        {
            threads[i] = std::thread(write_log_error, "[THREAD] " + std::to_string(i) + ": A simple info message");
        }
        else
        {
            threads[i] = std::thread(write_log_critical, "[THREAD] " + std::to_string(i) + ": A simple info message");
        }
    }

    for(int i=0; i<n_threads; i++)
    {
        threads[i].join();
    }
    
    WRITE_LOG_WARNING("Ups! We have a warning!");
    WRITE_LOG_ERROR("Ey! It appears a error! :O");
    WRITE_LOG_CRITICAL("Critical message!!!");

    WRITE_LOG_TRACE("END!");

    end_logger();

    return 0;
}