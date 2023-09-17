/**
 * How to compile: 
 * 
 *      g++ main.cpp -std=c++20 -o main
 * 
*/
#include "loggerAPI.h"
#include <iostream>
#include <dlfcn.h>

// typedef void (*LOG_TRACE)(std::string msg);
typedef void (*LOG_TRACE)(const char*);
// typedef void (*LOG_INFO)(std::string msg);
// typedef void (*LOG_WARNING)(std::string msg);
// typedef void (*LOG_ERROR)(std::string msg);
// typedef void (*LOG_CRITICAL)(std::string msg);

int main()
{
    void* handle = dlopen("/home/javi/Repositories/custom-logger/build/libdemologger.so", RTLD_LAZY);
    
    std::cout << handle << std::endl;

    if (!handle) 
    {
        std::cout << "Could not open the library 'libdemologger.so'" << std::endl;

        return -1;
    }

    LOG_TRACE log_trace = reinterpret_cast<LOG_TRACE>(dlsym(handle, "log_trace"));

    // const int n_threads = 500;
    // std::thread threads [n_threads] = {};

    // for(int i=0; i<n_threads; i++)
    // {
    //     if(i % 2 == 0)
    //     {
    //         threads[i] = std::thread(log_trace, "[THREAD] " + std::to_string(i) + ": asdasd");
    //     }
    //     // else if (i % 3 == 0)
    //     // {
    //     //     threads[i] = std::thread(logger_info, "[THREAD] " + std::to_string(i) + ": asdasd");
    //     // }
    //     // else if (i % 5 == 0)
    //     // {
    //     //     threads[i] = std::thread(logger_warning, "[THREAD] " + std::to_string(i) + ": asdasd");
    //     // }
    //     // else if (i % 7 == 0)
    //     // {
    //     //     threads[i] = std::thread(logger_error, "[THREAD] " + std::to_string(i) + ": asdasd");
    //     // }
    //     // else
    //     // {
    //     //     threads[i] = std::thread(logger_critical, "[THREAD] " + std::to_string(i) + ": asdasd");
    //     // } 
    // }

    // for(int i=0; i<n_threads; i++)
    // {
    //     threads[i].join();
    // }
  
    // log_trace("END!");

    dlclose(handle);

    return 0;
}