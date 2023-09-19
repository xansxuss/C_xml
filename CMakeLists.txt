cmake_minimum_required(VERSION 3.15)
project(xml_test)

if(CMAKE_BULID_TYPE STREQUAL Debug)
    MESSAGE("status Debug")
    ADD_DEFINITIONS(-DDebug)
elseif(CMAKE_BULID_TYPE STREQUAL Release)
    MESSAGE("status Release")
ENDIF()

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -Wl,--allow-shlib-undefined")
include_directories(${CMAKE_SOURCE_DIR}/include)

add_executable(main main.cpp)
