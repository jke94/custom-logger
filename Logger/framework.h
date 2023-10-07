#pragma once

#define WIN32_LEAN_AND_MEAN             // Exclude rarely-used stuff from Windows headers
// Windows Header Files


#ifdef __linux__ 
    //linux code goes here
#elif _WIN32
    // windows code goes here
    #include <windows.h>
#else

#endif