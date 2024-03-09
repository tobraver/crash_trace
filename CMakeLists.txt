cmake_minimum_required(VERSION 3.1.0)

project(crash_trace)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -g -rdynamic")

set(SRC_LIST crash_trace.cpp)

# target
add_library(${PROJECT_NAME} ${SRC_LIST})

# -I
target_include_directories(${PROJECT_NAME} PUBLIC .)

# -L
target_link_directories(${PROJECT_NAME} PUBLIC )

# -l
target_link_libraries(${PROJECT_NAME} PUBLIC dl)

# example
add_subdirectory(example)