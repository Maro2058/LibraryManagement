cmake_minimum_required(VERSION 3.27)
project(LibraryManagement)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(LibraryManagement
        LibraryManagement.h
        main.cpp
        LibraryManagementImplementation.cpp
)
