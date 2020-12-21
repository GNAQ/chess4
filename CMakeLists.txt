cmake_minimum_required(VERSION 3.2)

set(CMAKE_C_COMPILER "C:/MinGW64/bin/gcc.exe")
# set(CMAKE_CXX_COMPILER "C:/MinGW64/bin/g++.exe")

project(chess4)

set(PROJECT_BINARY_DIR "./bin")
set(PROJECT_SOURCE_DIR "./src")
set(PROJECT_CONFIG_DIR "./config")
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR})


# add_subdirectory(./src/cli)
link_directories(./src/cboard)
add_subdirectory(./src/cboard)

# add_library(natsu STATIC IMPORTED)
# set_property(TARGET natsu PROPERTY IMPORTED_LOCATION ./src/natsu/libnatsu.a)

aux_source_directory(./src SRCS)
add_executable(chess4 ${SRCS})

# link_libraries(chess4 cboard)
# target_link_libraries(chess4 cboard natsu)
target_link_libraries(chess4 cboard)