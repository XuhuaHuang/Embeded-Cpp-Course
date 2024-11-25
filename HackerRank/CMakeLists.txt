cmake_minimum_required(VERSION 3.20)

project("hacker_rank" LANGUAGES CXX)

set(CMAKE_C_STANDARD 20)
SET(CMAKE_C_STANDARD_REQUIRED ON)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Adding multiple executable to the project
# Right-click on each item to set as start-up project
add_executable(bracket_matching "bracket_matching.cpp")
add_executable(camel_case "camel_case.cpp")
add_executable(find_digit "find_digit.cpp")
add_executable(time_conversion "time_conversion.cpp")
add_executable(virtual_function "virtual_function.cpp")
