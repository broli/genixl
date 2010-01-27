#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.63])
AC_INIT([Genixl], [0.0.1], [http://github.com/broli/genixl/issues])
AM_INIT_AUTOMAKE([-Wall -Werror ])


AC_CONFIG_SRCDIR([src/ixlmxml.h])

# Checks for programs.
AC_PROG_CC

# Checks for libraries.

# Checks for header files.
AC_CHECK_HEADERS([locale.h stdlib.h string.h stdio.h iconv.h mxml.h])

# Checks for typedefs, structures, and compiler characteristics.

# Checks for library functions.
AC_CHECK_FUNCS([setlocale])

AC_CONFIG_FILES([Makefile src/Makefile])

AC_OUTPUT
