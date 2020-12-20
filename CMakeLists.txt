cmake_minimum_required(VERSION 3.2)

set(CMAKE_C_COMPILER "C:/MinGW64/bin/gcc.exe")
set(CMAKE_CXX_COMPILER "C:/MinGW64/bin/g++.exe")

project(chess4)

set(PROJECT_BINARY_DIR "./bin")
set(PROJECT_SOURCE_DIR "./src")
set(PROJECT_CONFIG_DIR "./config")


aux_source_directory(./src SRCS)

add_executable(chess4 ${SRCS})