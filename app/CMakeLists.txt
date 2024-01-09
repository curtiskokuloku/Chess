cmake_minimum_required(VERSION 3.26)
project(app)

set(CMAKE_CXX_STANDARD 17)

add_executable(app main.cpp
        lib/Fen.h)
