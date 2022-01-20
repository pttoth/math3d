cmake_minimum_required(VERSION 3.5)

project(math3d_win64 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


set(MY_PROJ_ROOT ${PROJECT_SOURCE_DIR}/../..)

#set(MY_BUILD_DIR ${MY_PROJ_ROOT}/build)

set(MY_OUTPUT_DIR_WIN32 ${MY_PROJ_ROOT}/bin/win32)
set(MY_OUTPUT_DIR_WIN64 ${MY_PROJ_ROOT}/bin/win64)
set(MY_OUTPUT_DIR_DEBIAN ${MY_PROJ_ROOT}/bin/debian)

#set up actual output directory
set(MY_OUTPUT_DIR ${MY_OUTPUT_DIR_WIN64})

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${MY_OUTPUT_DIR})
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${MY_OUTPUT_DIR})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${MY_OUTPUT_DIR})


add_library(math3d
    ${MY_PROJ_ROOT}/src/constants.cpp
    ${MY_PROJ_ROOT}/include/pt/math.h
    ${MY_PROJ_ROOT}/include/pt/math/
    ${MY_PROJ_ROOT}/include/pt/math/bool1.h
    ${MY_PROJ_ROOT}/include/pt/math/bool2.h
    ${MY_PROJ_ROOT}/include/pt/math/bool3.h
    ${MY_PROJ_ROOT}/include/pt/math/bool4.h
    ${MY_PROJ_ROOT}/include/pt/math/boolswizzle.h
    ${MY_PROJ_ROOT}/include/pt/math/float1.h
    ${MY_PROJ_ROOT}/include/pt/math/float2.h
    ${MY_PROJ_ROOT}/include/pt/math/float2swizzle.h
    ${MY_PROJ_ROOT}/include/pt/math/float3.h
    ${MY_PROJ_ROOT}/include/pt/math/float3swizzle.h
    ${MY_PROJ_ROOT}/include/pt/math/float4.h
    ${MY_PROJ_ROOT}/include/pt/math/float4swizzle.h
    ${MY_PROJ_ROOT}/include/pt/math/float4x4.h
    ${MY_PROJ_ROOT}/include/pt/math/floatswizzle.h
    ${MY_PROJ_ROOT}/include/pt/math/int1.h
    ${MY_PROJ_ROOT}/include/pt/math/int2.h
    ${MY_PROJ_ROOT}/include/pt/math/int3.h
    ${MY_PROJ_ROOT}/include/pt/math/int4.h
    ${MY_PROJ_ROOT}/include/pt/math/intswizzle.h
    )

target_include_directories(math3d PRIVATE
    ${MY_PROJ_ROOT}/include
    )

#define these to enable/disable features
#  note that you need to define these in the project too where you link the library!
target_compile_definitions(math3d PRIVATE
#    MATH_REMOVE_PT_NAMESPACE=1
#    MATH_ENABLE_SWIZZLE=1
    )
