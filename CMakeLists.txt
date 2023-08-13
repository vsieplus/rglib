cmake_minimum_required (VERSION 3.16)

set(CMAKE_CXX_STANDARD 17)

project(rglib VERSION 1.0.0 DESCRIPTION "C++ library for rhythm game development")

message(STATUS "Project Name: ${CMAKE_PROJECT_NAME}")
message(STATUS "Build type: ${CMAKE_BUILD_TYPE}")
message(STATUS "System name: ${CMAKE_SYSTEM_NAME}")

message(STATUS "Using CMAKE_C_FLAGS: ${CMAKE_C_FLAGS}")
message(STATUS "Using CMAKE_CXX_FLAGS: ${CMAKE_CXX_FLAGS}")

add_library(${CMAKE_PROJECT_NAME} 
    src/beatpos.cpp
    src/chartinfo.cpp
    src/notesplit.cpp
    src/songinfo.cpp
    src/songpos.cpp
)

target_include_directories(${CMAKE_PROJECT_NAME}
    PUBLIC ${CMAKE_SOURCE_DIR}/include/
)

set_target_properties(${CMAKE_PROJECT_NAME} PROPERTIES
    VERSION ${PROJECT_VERSION}
)

add_subdirectory(tests)

enable_testing()
