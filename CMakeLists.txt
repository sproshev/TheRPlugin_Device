cmake_minimum_required(VERSION 3.3)
project(RUniversalDevice)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall -Werror")

include_directories("/usr/share/R/include")

set(
        SOURCE_FILES
        Evaluator.cpp Evaluator.h
        MasterDevice.cpp MasterDevice.h
        ScopeProtector.cpp ScopeProtector.h
        ScopeSlaveDevice.cpp ScopeSlaveDevice.h
)

add_library(r_universal_device SHARED ${SOURCE_FILES})