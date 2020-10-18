cmake_minimum_required (VERSION 3.10)

set (PROJECT library_reg)

project (${PROJECT})

set (HEADERS library_reg.h)
set (SOURCES sources/library_reg.c)

source_group ("Header Files" FILES ${HEADERS})
source_group ("Source Files" FILES ${SOURCES})

add_library (${PROJECT} ${HEADERS} ${SOURCES})