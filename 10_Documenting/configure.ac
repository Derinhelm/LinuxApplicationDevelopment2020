#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.69])
AC_INIT([GUESS_NUMBER], [0.0.0], [Derinhelm@yandex.ru])
AM_INIT_AUTOMAKE([foreign])
DX_INIT_DOXYGEN(guess)
AC_CONFIG_SRCDIR([guess.c])
AC_CONFIG_HEADERS([config.h])

# Checks for programs.
AC_PROG_CC

# Checks for libraries.

# Checks for header files.
AC_CHECK_HEADERS([libintl.h locale.h stdlib.h string.h])

# Checks for typedefs, structures, and compiler characteristics.

# Checks for library functions.

AC_CHECK_FUNCS([realpath setlocale])

AC_CONFIG_FILES([Makefile Doxyfile guess.md libguess.md])
AC_OUTPUT
