cmake_minimum_required(VERSION 3.20)
project(eser2)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")


set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wshadow -Werror=vla")
set(SOURCES alg_uno.cpp)

add_executable(eser2 alg_uno.cpp)
add_executable(es2_pos es2_pos_memoria.cpp)