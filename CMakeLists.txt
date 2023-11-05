cmake_minimum_required(VERSION 3.26)
project(cpp_pomodorotimer)

set(CMAKE_CXX_STANDARD 20)

add_executable(cpp_pomodorotimer main.cpp)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Werror -Wall -Weffc++ -Wextra -Wconversion -Wsign-conversion")