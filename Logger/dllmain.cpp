#include "pch.h"
#include <iostream>

#ifdef __linux__ 
    //linux code goes here
#elif _WIN32
    // windows code goes here
    BOOL APIENTRY DllMain( HMODULE hModule,
                        DWORD  ul_reason_for_call,
                        LPVOID lpReserved
                        )
    {
        switch (ul_reason_for_call)
        {
            case DLL_PROCESS_ATTACH:
                break;

            case DLL_THREAD_ATTACH:
                break;

            case DLL_THREAD_DETACH:
                break;

            case DLL_PROCESS_DETACH:
                break;
        }
        return TRUE;
    }
#else

#endif