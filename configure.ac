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
AC_CHECK_HEADERS([locale.h stdlib.h string.h stdio.h iconv.h],
		 [],
		 [AC_MSG_ERROR([Some stdc header is missing. please check your OS documentation on how to install them])])

#check for mxml. do nothing if found. die with an error if not found
AC_CHECK_HEADER([mxml.h],
		[],
		[AC_MSG_ERROR([mini-xml is missing; please install the headers first])])

# Checks for typedefs, structures, and compiler characteristics.

# Checks for library functions.
AC_CHECK_FUNCS([setlocale])

#Set cflags for MXML
AM_CFLAGS="`pkg-config --cflags mxml`"
AC_SUBST(AM_CFLAGS)

#set Libs for MXML
##AM_LIBS="`pkg-config --libs mxml`"
AM_LDFLAGS="`pkg-config --libs mxml`"
AC_SUBST(AM_LDFLAGS)

AC_CONFIG_FILES([Makefile src/Makefile])

AC_OUTPUT
