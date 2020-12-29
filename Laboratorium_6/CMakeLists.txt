cmake_minimum_required(VERSION 3.19.0)

project(Laboratorium_6)

include_directories(./include ./src)

add_executable(binary ./src/main.cpp ./src/employee.cpp ./src/hrms.cpp)