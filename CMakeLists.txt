cmake_minimum_required(VERSION 3.3)
project(TheRPlugin_Device)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall -Werror")

find_package(Boost 1.31.0 REQUIRED COMPONENTS system)

include_directories(${Boost_INCLUDE_DIRS})
include_directories("/usr/share/R/include")

set(
        SOURCE_FILES
        Evaluator.cpp
        Interface.cpp
        MasterDevice.cpp
        ScopeProtector.cpp
        SlaveDevice.cpp
)

function(build_for_platform BIT)
    add_library(therplugin_device${BIT} SHARED ${SOURCE_FILES})
    set_target_properties(therplugin_device${BIT} PROPERTIES COMPILE_FLAGS "-m${BIT}" LINK_FLAGS "-m${BIT}")
endfunction()

build_for_platform(32)
build_for_platform(64)
