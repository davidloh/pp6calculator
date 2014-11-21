cmake_minimum_required(VERSION 2.8 FATAL_ERROR)

project(pp6calculator)

if(CMAKE_COMPILER_IS_GNUCXX)
	set(CMAKE_CXX_FLAGS "-Wall -Wextra")
endif()

include_directories(pp6lib)

add_library(pp6lib pp6lib/pp6math.hpp pp6lib/pp6math.cpp pp6lib/pp6day1.hpp pp6lib/pp6day1.cpp pp6lib/pp6day2.hpp pp6lib/pp6day2.cpp pp6lib/pp6day3.cpp pp6lib/pp6day3.hpp pp6lib/FileReader.hpp pp6lib/FileReader.cpp pp6lib/fourvector.hpp pp6lib/fourvector.cpp pp6lib/threevector.hpp pp6lib/threevector.cpp pp6lib/particle.cpp pp6lib/particle.hpp)

add_executable(pp6calculator pp6calculator.cpp)

target_link_libraries(pp6calculator pp6lib)
