cmake_minimum_required(VERSION 3.21)
project(SubstringSearch)

set(CMAKE_CXX_STANDARD 14)


set(INCLUDES ${PROJECT_SOURCE_DIR}/include)
include_directories(${INCLUDES})

add_subdirectory(lib/googletest-main)
include_directories(lib/googletest-main/googletest/include)

file(GLOB SOURCES ${PROJECT_SOURCE_DIR}/src/*.cpp)
file(GLOB HEADERS ${PROJECT_SOURCE_DIR}/include/*.h)


add_executable(main main.cpp ${HEADERS} ${SOURCES})
add_executable(test test.cpp ${SOURCES})
target_link_libraries(test gtest gtest_main)