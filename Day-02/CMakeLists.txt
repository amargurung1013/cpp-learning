cmake_minimum_required(VERSION 3.20)

project(Day02)

set(CMAKE_CXX_STANDARD 23)

# Individual target for main.cpp
add_executable(Day02_Main main.cpp)

# Individual target for a-tiny-combat-system.cpp
add_executable(Day02_Combat a-tiny-combat-system.cpp)
