cmake_minimum_required (VERSION 3.10)

set (PROJECT library_reg)

project (${PROJECT})

set (SOURCES sources/library_reg.c)

option(WithoutUTF "Without UTF" OFF)
configure_file(Cmakeconfig.h.in config.h @ONLY)

include_directories(${CMAKE_CURRENT_BINARY_DIR})

source_group ("Source Files" FILES ${SOURCES})

add_library (${PROJECT} ${SOURCES})
