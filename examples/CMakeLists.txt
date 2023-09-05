cmake_minimum_required (VERSION 3.16)

set(SRCS
    "typing_tempo.cpp"
)

foreach(SRC_PATH ${SRCS})
    get_filename_component(EXE_NAME ${SRC_PATH} NAME_WE)

    add_executable(${EXE_NAME} ${SRC_PATH})

    target_include_directories(${EXE_NAME}
        PUBLIC ${CMAKE_SOURCE_DIR}/include
    )

    target_link_libraries(${EXE_NAME}
        PRIVATE rglib
    )
endforeach(SRC_PATH ${SRCS})

file(COPY data DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
