#include <string>
#include <iostream>

#if defined(_MSC_VER)

#include "framework.h"
#include <Windows.h>

BOOL WINAPI DllMain(
    HINSTANCE hinstDLL,  // handle to DLL module
    DWORD fdwReason,     // reason for calling function
    LPVOID lpvReserved)  // reserved
{
    // Perform actions based on the reason for calling.
    switch (fdwReason)
    {
    case DLL_PROCESS_ATTACH:
        // Initialize once for each new process.
        // Return FALSE to fail DLL load.
        //std::cout << "Logger: DLL_PROCESS_ATTACH" << std::endl;
        break;

    case DLL_THREAD_ATTACH:
        // Do thread-specific initialization.
        //std::cout << "Logger: DLL_THREAD_ATTACH" << std::endl;
        break;

    case DLL_THREAD_DETACH:
        // Do thread-specific cleanup.
        //std::cout << "Logger: DLL_THREAD_DETACH" << std::endl;
        break;

    case DLL_PROCESS_DETACH:
        //std::cout << "Logger: DLL_PROCESS_DETACH" << std::endl;
        if (lpvReserved != nullptr)
        {
            break; // do not do cleanup if process termination scenario
        }

        // Perform any necessary cleanup.
        break;
        }
    return TRUE;  // Successful DLL_PROCESS_ATTACH.
    }

#elif defined(__GNUC__)

//  TODO

#else

//  TODO

#endif