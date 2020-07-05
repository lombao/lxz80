#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.69])
AC_INIT([lxz80], [0.0.10], [cesar.lombao@gmail.com])
AC_CONFIG_SRCDIR([src/lxz80/z80.c])
AC_CONFIG_AUX_DIR([build-aux])
AC_CONFIG_HEADERS([config.h])
AC_CONFIG_MACRO_DIRS([m4])

# Checks for programs.
AC_PROG_CC
AC_PROG_MAKE_SET
AC_PROG_YACC
AC_PROG_LEX
AM_PROG_AR

# Checks for header files.
AC_CHECK_HEADERS([stdint.h stdlib.h string.h signal.h time.h unistd.h])

# Checks for typedefs, structures, and compiler characteristics.
AC_TYPE_INT16_T
AC_TYPE_INT32_T
AC_TYPE_INT8_T
AC_TYPE_UINT16_T
AC_TYPE_UINT8_T

# Checks for library functions.

AM_INIT_AUTOMAKE([1.11 -Wall -Werror foreign])
AC_CONFIG_FILES([src/lxz80/Makefile src/lxzasm/Makefile src/lxzrun/Makefile examples/Makefile Makefile])
AC_CONFIG_FILES([src/lxz80/lxz80.pc])
AC_CONFIG_FILES([src/lxz80/lxz80.h])
LT_INIT([shared disable-static])
AC_OUTPUT

echo "
	LXZ80 ${VERSION} has been configured
	PREFIX: ${prefix}
	You can know do
	make
	sudo make install
"