cmake_minimum_required (VERSION 3.8)

file(GLOB_RECURSE SRCS "src/*.cpp")
add_executable(tests ${SRCS})

target_include_directories(tests
    PUBLIC ${CMAKE_SOURCE_DIR}/Foundation/include
)

find_package(Catch2 3 REQUIRED)

target_link_libraries(tests
    PRIVATE rglib
    PRIVATE Catch2::Catch2WithMain
)

include(CTest)
include(Catch)
catch_discover_tests(tests)
