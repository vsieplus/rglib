cmake_minimum_required (VERSION 3.8)

set(CMAKE_CXX_STANDARD 17)

project(rglib VERSION 0.1.0)

message(STATUS "Project Name: ${CMAKE_PROJECT_NAME}")
message(STATUS "Build type: ${CMAKE_BUILD_TYPE}")
message(STATUS "System name: ${CMAKE_SYSTEM_NAME}")

message(STATUS "Using CMAKE_C_FLAGS: ${CMAKE_C_FLAGS}")
message(STATUS "Using CMAKE_CXX_FLAGS: ${CMAKE_CXX_FLAGS}")

enable_testing()

add_subdirectory(Foundation)
