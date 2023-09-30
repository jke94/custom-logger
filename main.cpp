#include "logger_api.h"

#include <iostream>
#include <thread>
#include <dlfcn.h>

void write_log_trace(std::string msg)
{
    WRITE_TRACE(msg);
}

void write_log_info(std::string msg)
{
    WRITE_INFO(msg);
}

void write_log_warning(std::string msg)
{
    WRITE_WARNING(msg);
}

void write_log_error(std::string msg)
{
    WRITE_ERROR(msg);
}

void write_log_critical(std::string msg)
{
    WRITE_CRITICAL(msg);
}

int main()
{
    // TODO: Investigate if it make sense load dll.

    // void* handle = dlopen("libdemologger.so", RTLD_LAZY);
    
    // std::cout << "Handle: " << handle << std::endl;

    // if (!handle) 
    // {
    //     std::cout << "Could not open the library 'libdemologger.so'" << std::endl;

    //     return -1;
    // }

    WRITE_TRACE("Hello Javi! Come on!");
    
    const int n_threads = 100;
    std::thread threads [n_threads] = {};

    WRITE_TRACE("START!");

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
  
    WRITE_TRACE("END!");

    // TODO: Investigate if it make sense load dll.

    // dlclose(handle);

    return 0;
}