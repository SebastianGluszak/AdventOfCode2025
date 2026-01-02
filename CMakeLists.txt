cmake_minimum_required(VERSION 4.1)
project(AdventOfCode2025)

set(CMAKE_CXX_STANDARD 26)

add_executable(AdventOfCode2025 main.cpp
        src/DayOne.cpp
        include/DayOne.h
        src/DayTwo.cpp
        include/DayTwo.h
        include/DayThree.h
        src/DayThree.cpp
        src/DayThree.cpp)
