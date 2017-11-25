cmake_minimum_required(VERSION 3.8)
project(Main_body)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES Sat-Uni-Main-Body.cpp course.cpp course.h classroom.cpp classroom.h student.cpp student.h reg_system.cpp reg_system.h)
add_executable(Main_body ${SOURCE_FILES})