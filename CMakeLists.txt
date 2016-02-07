cmake_minimum_required(VERSION 3.3)

project(TheRPlugin_Device)
string(TOLOWER ${PROJECT_NAME} TARGET_NAME_PREFIX)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/modules")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall -Werror")

find_package(R)
find_package(Boost 1.31.0 REQUIRED)

include_directories(${R_INCLUDE_DIRS})
include_directories(${Boost_INCLUDE_DIRS})

set(
        SOURCE_FILES
        Evaluator.cpp
        Interface.cpp
        MasterDevice.cpp
        ScopeProtector.cpp
        SlaveDevice.cpp
)

function(build_for_platform BIT BIT_LIBRARIES)
    add_library(${TARGET_NAME_PREFIX}${BIT} SHARED ${SOURCE_FILES})

    set_target_properties(${TARGET_NAME_PREFIX}${BIT} PROPERTIES COMPILE_FLAGS "-m${BIT}" LINK_FLAGS "-m${BIT}")
    target_link_libraries(${TARGET_NAME_PREFIX}${BIT} ${BIT_LIBRARIES})
endfunction()

build_for_platform(32 ${R_32_LIBRARIES})
build_for_platform(64 ${R_64_LIBRARIES})
