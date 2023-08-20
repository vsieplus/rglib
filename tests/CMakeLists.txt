cmake_minimum_required (VERSION 3.16)

add_executable(tests
    "src/beatpos_test.cpp"
    "src/timeinfo_test.cpp"
    "src/songinfo_test.cpp"
)

target_include_directories(tests
    PUBLIC ${CMAKE_SOURCE_DIR}/include
)

file(COPY data DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

# Get Catch2
Include(FetchContent)

FetchContent_Declare(
  Catch2
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG        v3.0.1 # or a later release
)

FetchContent_MakeAvailable(Catch2)

target_link_libraries(tests
    PRIVATE rglib
    PRIVATE Catch2::Catch2WithMain
)

include(CTest)
include(Catch)
catch_discover_tests(tests)
