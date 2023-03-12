cmake_minimum_required (VERSION 3.10)
project (common)

set(CMAKE_CXX_STANDARD 11)

set(SOURCES
        config.cpp
)


add_library(common ${SOURCES})