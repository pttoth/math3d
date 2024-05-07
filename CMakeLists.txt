cmake_minimum_required(VERSION 3.5)

project(math3d LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


set(MY_PROJ_ROOT ${PROJECT_SOURCE_DIR})
set(MY_BUILD_DIR ${MY_PROJ_ROOT}/build)

#set up actual output directory
set(MY_OUTPUT_DIR ${MY_PROJ_ROOT}/bin)
set(MY_OUTPUT_DIR_DEBUG ${MY_OUTPUT_DIR}/debug)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${MY_OUTPUT_DIR})
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${MY_OUTPUT_DIR})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${MY_OUTPUT_DIR})

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE ${MY_OUTPUT_DIR})
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_RELEASE ${MY_OUTPUT_DIR})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_RELEASE ${MY_OUTPUT_DIR})

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG ${MY_OUTPUT_DIR_DEBUG})
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_DEBUG ${MY_OUTPUT_DIR_DEBUG})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_DEBUG ${MY_OUTPUT_DIR_DEBUG})

#available configurations:
#  -DMATH_ENABLE_SWIZZLE
#       the swizzle feature is optional as it
#       severely slows down compilation and bloats the binary sizes
set(MY_COMPILE_FLAGS "-Wall -Wextra")
set(CMAKE_C_FLAGS ${MY_COMPILE_FLAGS})
set(CMAKE_CXX_FLAGS ${MY_COMPILE_FLAGS})

add_library(math3d
    ${MY_PROJ_ROOT}/src/constants.cpp
    ${MY_PROJ_ROOT}/src/math.cpp
    ${MY_PROJ_ROOT}/src/FRotator.cpp
    ${MY_PROJ_ROOT}/src/quaternion.cpp
    ${MY_PROJ_ROOT}/src/HPL1/Quaternion.cpp
    ${MY_PROJ_ROOT}/include/pt/math.h
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
    ${MY_PROJ_ROOT}/include/pt/math/FRotator.h
    ${MY_PROJ_ROOT}/include/pt/math/quaternion.h
    ${MY_PROJ_ROOT}/include/pt/HPL1/Quaternion.h
)

target_include_directories(math3d PRIVATE
    /usr/include
    ${MY_PROJ_ROOT}/include
)

set_target_properties(math3d PROPERTIES COMPILE_FLAGS
    "${MY_COMPILE_FLAGS} -fPIC"
)

#define these to enable/disable features
#  note that you need to define these in the project too where you link the library!
target_compile_definitions(math3d PRIVATE
#    MATH_ENABLE_SWIZZLE=1
)
