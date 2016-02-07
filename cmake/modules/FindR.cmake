set(R_HOME "")

if (NOT R_HOME)
    message(FATAL_ERROR "R directory is not specified")
endif()

set(R_INCLUDE_DIRS "${R_HOME}/include")

find_library(R_64_LIBRARIES NAMES R HINTS "${R_HOME}/bin/x64")
find_library(R_32_LIBRARIES NAMES R HINTS "${R_HOME}/bin/i386")