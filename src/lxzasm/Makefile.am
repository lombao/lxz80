BUILT_SOURCES = grammar.h

AM_CFLAGS = -g  -Wall -Wextra -O2 -DLXZ80VERSION="\"$(VERSION)\""
AM_YFLAGS = -d

bin_PROGRAMS = lxzasm
lxzasm_SOURCES = main.c code.c error.c label.c grammar.y lex.l preproc.c defs.h codedata.h

