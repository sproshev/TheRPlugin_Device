cmake_minimum_required(VERSION 3.3)
project(TheRPlugin_Device)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall -Werror")

find_package(Boost REQUIRED)

include_directories(${Boost_INCLUDE_DIRS})
include_directories("/usr/share/R/include")

set(
        SOURCE_FILES
        Common.h
        Evaluator.cpp Evaluator.h
        Interface.cpp Interface.h
        MasterDevice.cpp MasterDevice.h
        ScopeProtector.cpp ScopeProtector.h
        SlaveDevice.cpp SlaveDevice.h
)

add_library(therplugin_device SHARED ${SOURCE_FILES})