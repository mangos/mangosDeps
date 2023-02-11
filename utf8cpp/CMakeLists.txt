cmake_minimum_required(VERSION 3.12 FATAL_ERROR)

set(CMAKE_CXX_STANDARD          14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(UTF8CPP)

add_library(utf8 INTERFACE)

target_include_directories(utf8
    INTERFACE
        ${CMAKE_CURRENT_SOURCE_DIR})
