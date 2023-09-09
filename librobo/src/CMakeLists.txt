cmake_minimum_required(VERSION 3.5)
project(librobo LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(LIBRARY_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/build/lib/)

add_library(${PROJECT_NAME} STATIC
    ${SRC}robot_xd.cpp
    ${SRC}robot_1d.cpp ${SRC}robot_2d.cpp ${SRC}robot_3d.cpp ${SRC}robot_4d.cpp
    ${SRC}position.cpp

    ${INCLUDE}irobot.h
    ${INCLUDE}robot_xd.h
    ${INCLUDE}robot_1d.h ${INCLUDE}robot_2d.h ${INCLUDE}robot_3d.h ${INCLUDE}robot_4d.h
    ${INCLUDE}position.h
)

target_include_directories(${PROJECT_NAME} PRIVATE ${INCLUDE})
