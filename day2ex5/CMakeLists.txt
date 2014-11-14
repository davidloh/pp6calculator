cmake_minimum_required(VERSION 2.8 FATAL_ERROR)

project(pp6calculator)

include_directories(pp6lib)

add_library(pp6lib pp6lib/pp6math.hpp pp6lib/pp6math.cpp pp6lib/pp6day1.hpp pp6lib/pp6day1.cpp pp6lib/pp6day2.hpp pp6lib/pp6day2.cpp)

add_executable(pp6calculator pp6calculator.cpp)

target_link_libraries(pp6calculator pp6lib)
