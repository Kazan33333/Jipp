cmake_minimum_required(VERSION 3.19.0)

project(Laboratorium_4)

include_directories(./include ./src)

add_executable(binary ./src/main.cpp ./src/matrix.cpp)