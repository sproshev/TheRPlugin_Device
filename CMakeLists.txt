cmake_minimum_required(VERSION 3.3)
project(RUniversalDevice)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

include_directories("/usr/share/R/include")

set(SOURCE_FILES primary_device.cpp primary_device.h evaluator.cpp evaluator.h scope_protector.cpp scope_protector.h ScopeSlaveDevice.cpp ScopeSlaveDevice.h)

add_library(r_universal_device SHARED ${SOURCE_FILES})