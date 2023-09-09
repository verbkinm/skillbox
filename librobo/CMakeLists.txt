cmake_minimum_required(VERSION 3.5)
project(robo LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(INCLUDE ${CMAKE_SOURCE_DIR}/include/)
set(SRC ${CMAKE_SOURCE_DIR}/src/)

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/build/bin/)

add_executable(${PROJECT_NAME} main.cpp)
add_subdirectory(${SRC})

target_include_directories(${PROJECT_NAME} PRIVATE ${INCLUDE})
target_link_libraries(${PROJECT_NAME} PRIVATE librobo)
