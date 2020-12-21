aux_source_directory(. CLI_LIB_DIR)

add_library(natsu STATIC IMPORTED)
set_property(TARGET natsu PROPERTY IMPORTED_LOCATION ${PROJECT_SOURCE_DIR}/natsu/libnatsu.a)

add_library(cli ${CLI_LIB_DIR})

target_link_libraries(cli natsu)