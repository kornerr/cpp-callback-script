PROJECT(RESEARCH_CHAI_SCRIPT)
CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

# Use C++14.
ADD_DEFINITIONS("-std=c++14")

# Reference app includes.
INCLUDE_DIRECTORIES(${CMAKE_SOURCE_DIR}/app)

# Reference ChaiScript includes.
#INCLUDE_DIRECTORIES(${CMAKE_SOURCE_DIR}/../ChaiScript/include)

ADD_EXECUTABLE(cpp-callback-script app/main.cpp)
#TARGET_LINK_LIBRARIES(researchChaiScript dl pthread)

#ADD_EXECUTABLE(factory factory.cpp)
#TARGET_LINK_LIBRARIES(factory dl pthread)
