cmake_minimum_required(VERSION 3.2)

project(natsu)

aux_source_directory(. NATSU_LIB_DIR)

add_library(natsu STATIC ${NATSU_LIB_DIR})