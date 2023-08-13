cmake_minimum_required (VERSION 3.8)

add_library(${CMAKE_PROJECT_NAME} 
    src/beatpos.cpp
    src/chartinfo.cpp
    src/notesplit.cpp
    src/songinfo.cpp
    src/songpos.cpp
)

target_include_directories(${CMAKE_PROJECT_NAME}
    PUBLIC ${CMAKE_SOURCE_DIR}/Foundation/include/
)

set_target_properties(${CMAKE_PROJECT_NAME} PROPERTIES
    VERSION ${PROJECT_VERSION}
)

add_subdirectory(tests)
