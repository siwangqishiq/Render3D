
//for debug
#ifndef GLSL
#define GLSL(A) "#version 330 core\n" #A
#endif

// #ifdef _WIN32
// #ifndef GLSL
// #define GLSL(A) "#version 330 core\n" #A
// #endif
// #elif __APPLE__
//     #include "TargetConditionals.h"
//     #if TARGET_IPHONE_SIMULATOR
//          // iOS Simulator
//     #elif TARGET_OS_IPHONE
//         // iOS device
//     #elif TARGET_OS_MAC
//         // Other kinds of Mac OS
//     #else
//     #   error "Unknown Apple platform"
//     #endif
// #elif __ANDROID__
// #ifndef GLSL
// #define GLSL(A) "#version 330 es\n" #A
// #endif
// #elif __linux__
//     // linux
// #elif __unix__ // all unices not caught above
//     // Unix
// #elif defined(_POSIX_VERSION)
//     // POSIX
// #else
// #   error "Unknown compiler"
// #endif