cmake_minimum_required (VERSION 2.6)

set (PROJECT demo)
project (${PROJECT})

include_directories (.)

set (LIBRARY
		library_reg)


foreach (LIBRARY ${LIBRARY})
	add_subdirectory (${LIBRARY} bin/${LIBRARY})
endforeach ()


set (HEADERS)
set (SOURCES main.c)


source_group ("Header Files" FILES ${HEADERS})
source_group ("Source Files" FILES ${SOURCES})

add_executable (${PROJECT} ${HEADERS} ${SOURCES})



find_library(PCRE_LIBRARY pcre2-8)

find_library(CURSES_LIBRARY ncursesw)
include_directories(${CURSES_INCLUDE_DIR} ${CMAKE_CURRENT_BINARY_DIR})
target_link_libraries(${PROJECT} ${LIBRARY} ${CURSES_LIBRARY} ${PCRE_LIBRARY})


set (TRASHDIR CMakeFiles bin library_reg/bin library_reg/CMakeFiles)
set (TRASH CMakeCache.txt cmake_install.cmake Makefile demo 
    library_reg/CMakeCache.txt library_reg/cmake_install.cmake library_reg/Makefile library_reg/liblibrary_reg.a)

add_custom_target(allclean
    COMMAND rm -rf ${TRASHDIR}
    COMMAND rm -f ${TRASH}
)