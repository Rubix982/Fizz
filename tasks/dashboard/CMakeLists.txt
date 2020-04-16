cmake_minimum_required(VERSION 3.15)

project(dashboard)

include_directories(include)

add_executable(dashboard src/dashboard.cpp include/dashboard.hpp)