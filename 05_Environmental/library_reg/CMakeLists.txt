cmake_minimum_required (VERSION 3.10)

set (PROJECT library_reg)

project (${PROJECT})

set (SOURCES sources/library_reg.c)

configure_file(Cmakeconfig.h.in config.h)

source_group ("Source Files" FILES ${SOURCES})
add_definitions(-DWithoutUTF=FALSE)

add_library (${PROJECT} ${SOURCES})