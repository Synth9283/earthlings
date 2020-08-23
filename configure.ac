#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.69])
AC_INIT([earthlings], [0.9.0], [synth9283@gmail.com])
AC_CONFIG_SRCDIR([main.c])
AC_CONFIG_HEADERS([config.h])
AM_INIT_AUTOMAKE([-Wall -Werror foreign])

# Checks for programs.
AC_PROG_CC

# Checks for libraries.
PKG_CHECK_MODULES([SDL2], sdl2)
PKG_CHECK_MODULES([SDL2_MIXER], SDL2_mixer)
PKG_CHECK_MODULES([SDL2_TTF], SDL2_ttf)
PKG_CHECK_MODULES([SDL2_IMAGE], SDL2_image)

# Checks for header files.

# Checks for typedefs, structures, and compiler characteristics.

# Checks for library functions.

AC_CONFIG_FILES([Makefile])
AC_OUTPUT
