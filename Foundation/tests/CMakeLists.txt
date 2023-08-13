cmake_minimum_required (VERSION 3.8)

add_executable(rglibtests main.cpp)

target_include_directories(rglibtests
    PUBLIC ${CMAKE_SOURCE_DIR}/Foundation/include
)

target_link_libraries(rglibtests
    PRIVATE rglib
)

add_test(NAME rglib.songinfo.init COMMAND rglibtests)
