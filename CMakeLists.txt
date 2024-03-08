cmake_minimum_required(VERSION 3.1.0)

project(crash_trace)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c99 -g -rdynamic")

set(SRC_LIST crash_trace.c)

# target
add_library(${PROJECT_NAME} ${SRC_LIST})

# -I
target_include_directories(${PROJECT_NAME} PUBLIC .)

# -L
target_link_directories(${PROJECT_NAME} PUBLIC )

# -l
target_link_libraries(${PROJECT_NAME} PUBLIC )

# example
add_subdirectory(example)