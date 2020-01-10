pkgconfigdir = $(libdir)/pkgconfig
pkgconfig_DATA = lxz80.pc

EXTRA_DIST = lxz80.pc.in

AM_CFLAGS = -g  -Wall -fPIC -Wextra -O2 -DLXZ80VERSION="\"$(VERSION)\""

lib_LTLIBRARIES = liblxz80.la
liblxz80_la_SOURCES = z80.c z80.h z80-cb-decoding.c z80-ddfd-decoding.c z80-decoding.c z80-ed-decoding.c  z80-helper.h  

include_HEADERS = lxz80.h
