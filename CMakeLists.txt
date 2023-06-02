#Mark Hentges 5814125 2/23/2023

cmake_minimum_required(VERSION 3.24)
project(project3)

set(CMAKE_CXX_STANDARD 17)

add_executable(project3 main.cpp LinkedSet.h LinkedSet.cpp Node.cpp Node.h)
