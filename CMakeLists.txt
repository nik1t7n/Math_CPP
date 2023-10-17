cmake_minimum_required(VERSION 3.26)
project(math)

set(CMAKE_CXX_STANDARD 23)

add_executable(math src/main.cpp
        src/matrix.cpp
        include/matrix.h
        src/text.cpp
        include/text.h
        src/crammer.cpp
        include/crammer.h
        src/probSolver.cpp
        include/probSolver.h)
