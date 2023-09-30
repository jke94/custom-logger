#include "logger_api.h"

#include <iostream>
#include <thread>
#include <dlfcn.h>


int main()
{
    void* handle = dlopen("libdemologger.so", RTLD_LAZY);
    
    std::cout << "Handle: " << handle << std::endl;

    if (!handle) 
    {
        std::cout << "Could not open the library 'libdemologger.so'" << std::endl;

        return -1;
    }

    LOG_TRACE log_trace = reinterpret_cast<LOG_TRACE>(dlsym(handle, "log_trace"));
    LOG_INFO log_info = reinterpret_cast<LOG_INFO>(dlsym(handle, "log_info"));
    LOG_WARNING log_warning = reinterpret_cast<LOG_WARNING>(dlsym(handle, "log_warning"));
    LOG_ERROR log_error = reinterpret_cast<LOG_ERROR>(dlsym(handle, "log_error"));
    LOG_CRITICAL log_critical = reinterpret_cast<LOG_CRITICAL>(dlsym(handle, "log_critical"));


    if(!log_trace && !log_info && !log_warning && !log_error && !log_critical)
    {
        std::cout << "Error in load function." << std::endl;
        return -2;
    }

    log_trace("Hello Javi! Come on!");

    const int n_threads = 100;
    std::thread threads [n_threads] = {};

    log_trace("START!");

    for(int i=0; i<n_threads; i++)
    {
        if(i % 2 == 0)
        {
            threads[i] = std::thread(log_trace, "[THREAD] " + std::to_string(i) + ": A simple trace message.");
        }
        else if (i % 3 == 0)
        {
            threads[i] = std::thread(log_info, "[THREAD] " + std::to_string(i) + ": A simple info message");
        }
        else if (i % 5 == 0)
        {
            threads[i] = std::thread(log_warning, "[THREAD] " + std::to_string(i) + ": Wow! It is a warning message.");
        }
        else if (i % 7 == 0)
        {
            threads[i] = std::thread(log_error, "[THREAD] " + std::to_string(i) + ": Ouuh! It is an error message.");
        }
        else
        {
            threads[i] = std::thread(log_critical, "[THREAD] " + std::to_string(i) + ": Help! We have a critical message.");
        } 
    }

    for(int i=0; i<n_threads; i++)
    {
        threads[i].join();
    }
  
    log_trace("END!");

    dlclose(handle);

    return 0;
}