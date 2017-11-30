cmake_minimum_required(VERSION 3.8)

project(competition_clion)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        classroom.cpp
        classroom.h
        course.cpp
        course.h
        reg_system.cpp
        reg_system.h
        Sat-Uni-Main-Body.cpp
        student.cpp
        student.h
        term_operations.cpp
        term_operations.h)

add_executable(competition_clion ${SOURCE_FILES})