cmake_minimum_required(VERSION 3.26)
project(AdventOfCode)

set(CMAKE_CXX_STANDARD 17)

add_executable(Day1Exec "Day 1/main.cpp"
        "Day 1/CalibrationValues.cpp"
        "Day 1/CalibrationValues.h"
        "Day 1/StringUtils.cpp"
        "Day 1/StringUtils.h"
        Day3/Day3.cpp
)

add_executable(   Day2Exec "Day2/Day2.cpp"
        Day2/PossibleGames.cpp
        Day2/PossibleGames.h)

add_executable( Day3Exec "Day3/Day3.cpp"
        Day3/Manifold.cpp
        Day3/Manifold.h)