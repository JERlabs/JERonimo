#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.65])
AC_INIT([GameFramework], [0.0.0], [BUG-REPORT-ADDRESS])
AC_CONFIG_MACRO_DIR([m4])
AC_CONFIG_SRCDIR([Space2D/Point.cpp])
AM_INIT_AUTOMAKE([foreign subdir-objects])
LT_INIT
AC_CONFIG_HEADERS([config.h])

# Checks for programs.
AC_PROG_CXX
AC_PROG_CC
AC_PROG_RANLIB

# Checks for libraries.
# FIXME: Replace `main' with a function in `-lSDL':
AC_CHECK_LIB([SDL], [SDL_Init])

# Checks for header files.
AC_CHECK_HEADERS([stdlib.h])

# Checks for typedefs, structures, and compiler characteristics.
AC_CHECK_HEADER_STDBOOL

# Checks for library functions.
AC_CHECK_FUNCS([sqrt])

AC_CHECK_DECL([M_PI],[],[AC_DEFINE([M_PI],[3.14159265358979323846],
              [Check if M_PI is defined])],[math.h])

AC_CONFIG_FILES([Makefile])
AC_CONFIG_COMMANDS([lol], [rm -rf \$\(*])
AC_OUTPUT
