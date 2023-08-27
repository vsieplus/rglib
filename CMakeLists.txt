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
    src/sequenceitem.cpp
    src/songinfo.cpp
    src/songpos.cpp
    src/section.cpp
    src/timeinfo.cpp
)

target_include_directories(${CMAKE_PROJECT_NAME}
    PUBLIC ${CMAKE_SOURCE_DIR}/include/
    PUBLIC ${CMAKE_SOURCE_DIR}/third_party/
)

set(HDRS
    include/rglib/beatpos.h
    include/rglib/chartinfo.h
    include/rglib/constants.h
    include/rglib/fileformat.h
    include/rglib/notesplit.h
    include/rglib/sequenceitem.h
    include/rglib/section.h
    include/rglib/songinfo.h
    include/rglib/songpos.h
    include/rglib/timeinfo.h
)

set_target_properties(${CMAKE_PROJECT_NAME} PROPERTIES VERSION ${PROJECT_VERSION})
set_target_properties(${CMAKE_PROJECT_NAME} PROPERTIES PUBLIC_HEADER "${HDRS}")

# pkg-config setup
configure_file(cmake/rglib.pc.in rglib.pc @ONLY)

include(GNUInstallDirs)
install(TARGETS ${CMAKE_PROJECT_NAME}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/rglib)
install(FILES ${CMAKE_BINARY_DIR}/rglib.pc
    DESTINATION ${CMAKE_INSTALL_DATAROOTDIR}/pkgconfig)

add_subdirectory(examples)
add_subdirectory(tests)
enable_testing()
