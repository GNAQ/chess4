aux_source_directory(. CBOARD_LIB_DIR)

add_library(natsu STATIC IMPORTED)
set_property(TARGET natsu PROPERTY IMPORTED_LOCATION ${PROJECT_SOURCE_DIR}/natsu/libnatsu.a)

add_library(cboard STATIC ${CBOARD_LIB_DIR})

target_link_libraries(cboard natsu)