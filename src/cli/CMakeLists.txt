aux_source_directory(. CLI_LIB_DIR)



add_library(cli ${CLI_LIB_DIR})
link_directories(cli natsu)