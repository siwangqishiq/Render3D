# For more information about using CMake with Android Studio, read the
# documentation: https://d.android.com/studio/projects/add-native-code.html

# Sets the minimum version of CMake required to build the native library.

cmake_minimum_required(VERSION 3.10.2)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c11 -Wall")

# Declares and names the project.

project("render")

# Creates and names a library, sets it as either STATIC
# or SHARED, and provides the relative paths to its source code.
# You can define multiple libraries, and CMake builds them for you.
# Gradle automatically packages shared libraries with your APK.

set(SRC_DIR "../../../../../src")  #源码

include_directories(${SRC_DIR}/include) #添加include目录
include_directories(include)

add_library( # Sets the name of the library.
            render3d
             # Sets the library as a shared library.
             SHARED

            ${SRC_DIR}/platform/AndroidApp.cpp
            ${SRC_DIR}/core/App.cpp
            ${SRC_DIR}/core/Shader.cpp
            ${SRC_DIR}/core/Shape.cpp
            ${SRC_DIR}/example/TriangleApp.cpp
        )

# Searches for a specified prebuilt library and stores the path as a
# variable. Because CMake includes system libraries in the search path by
# default, you only need to specify the name of the public NDK library
# you want to add. CMake verifies that the library exists before
# completing its build.

set(OPENGL_LIB GLESv3)

find_library( # Sets the name of the path variable.
              log-lib
              # Specifies the name of the NDK library that
              # you want CMake to locate.
              log )

# Specifies libraries CMake should link to your target library. You
# can link multiple libraries, such as libraries you define in this
# build script, prebuilt third-party libraries, or system libraries.

target_link_libraries( # Specifies the target library.
                        render3d
                       # Links the target library to the log library
                       # included in the NDK.
                        ${log-lib}
                        ${OPENGL_LIB}
                        android
                        ${log-lib}
                        mediandk
                        jnigraphics)