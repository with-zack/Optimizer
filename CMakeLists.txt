cmake_minimum_required(VERSION 3.10)
project(Optimizer)
include_directories( "/usr/include/eigen3" )
add_executable(Optimizer main.cpp optimizer.cpp optimizer.hpp)
