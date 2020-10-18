cmake_minimum_required(VERSION 3.10)
project(Window VERSION 0.01)
add_executable(Window Window.c)

find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR} ${CMAKE_CURRENT_BINARY_DIR})
target_link_libraries(Window ${CURSES_LIBRARY})
configure_file(Cmakeconfig.h.in config.h)