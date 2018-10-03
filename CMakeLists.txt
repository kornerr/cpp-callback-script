PROJECT(CPP_CALLBACK_SCRIPT)
CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

# Use C++14.
ADD_DEFINITIONS("-std=c++14")

# Sol2 must be located in <this directory>/../sol2
INCLUDE_DIRECTORIES(${CMAKE_SOURCE_DIR}/../sol2)

SET(LIBS "")
# Link with `dl` lib on Linux.
IF ("${CMAKE_SYSTEM_NAME}" STREQUAL "Linux")
    SET(LIBS "dl")
ENDIF ()

# Executable.
INCLUDE_DIRECTORIES(${CMAKE_SOURCE_DIR}/src)
ADD_EXECUTABLE(
    cpp-callback-script
    src/main.cpp
)
TARGET_LINK_LIBRARIES(
    cpp-callback-script
    lua
    ${LIBS}
)

