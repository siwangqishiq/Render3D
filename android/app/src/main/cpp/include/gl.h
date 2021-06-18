//从不同平台 引入opengl头文件
#ifndef _GL_H_
#define _GL_H_

#include <GLES3/gl3.h>
#include <GLES2/gl2ext.h>

//for debug
//#include "glad/glad.h"

//#ifdef _WIN32
//#include <glad/glad.h>
//#elif __APPLE__
//    #include "TargetConditionals.h"
//    #if TARGET_IPHONE_SIMULATOR
//         // iOS Simulator
//    #elif TARGET_OS_IPHONE
//        // iOS device
//    #elif TARGET_OS_MAC
//        // Other kinds of Mac OS
//    #else
//    #   error "Unknown Apple platform"
//    #endif
//#elif __ANDROID__
//#include <GLES3/gl3.h>
//#include <GLES2/gl2ext.h>
//#elif __linux__
//    // linux
//#elif __unix__ // all unices not caught above
//    // Unix
//#elif defined(_POSIX_VERSION)
//    // POSIX
//#else
//#   error "Unknown compiler"
//#endif
//
#endif

#ifndef _ANDROID_LOG_H_
#define _ANDROID_LOG_H_

#include <android/log.h>

#define TAG "System.out"

#define LOGE(...) __android_log_print(ANDROID_LOG_ERROR,    TAG, __VA_ARGS__)
#define LOGW(...) __android_log_print(ANDROID_LOG_WARN,     TAG, __VA_ARGS__)
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO,     TAG, __VA_ARGS__)
#define LOGD(...) __android_log_print(ANDROID_LOG_DEBUG,    TAG, __VA_ARGS__)

#endif //SIMPLEPLAYER_LOG_H