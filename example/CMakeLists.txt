cmake_minimum_required(VERSION 3.1.0)

project(crash_trace_example)

# target
add_executable(crash_trace_example example.cpp)

# -l
target_link_libraries(crash_trace_example PRIVATE crash_trace)