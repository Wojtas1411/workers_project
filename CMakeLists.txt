cmake_minimum_required(VERSION 3.8)
project(workers_project)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp worker.cpp worker.h terminal.cpp terminal.h)
add_executable(workers_project ${SOURCE_FILES})