cmake_minimum_required(VERSION 3.19.0)

project("Laboratorium 4")

include_directories(./include ./src)

add_executable(binary ./src/Lab_3.cpp ./src/matrix.cpp)