cmake_minimum_required (VERSION 3.8)

file(GLOB SRCS "src/*.cpp")
file(GLOB_RECURSE HDRS "include/*.h")

add_library(${CMAKE_PROJECT_NAME}
    ${SRCS}
    ${HDRS}
)

target_include_directories(${CMAKE_PROJECT_NAME}
    PUBLIC ${CMAKE_SOURCE_DIR}/Foundation/include/
)

add_subdirectory(tests)
