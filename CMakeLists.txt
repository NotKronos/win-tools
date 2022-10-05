cmake_minimum_required(VERSION 3.23)
project(win_tools)

set(CMAKE_CXX_STANDARD 23)

include_directories(term)

add_executable(win_tools
        term/term.cpp
        term/term.h
        tools/cd.cpp
        tools/ls.cpp
        main.cpp tools/mkfile.cpp tools/mkdir.cpp)
