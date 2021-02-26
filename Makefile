# Makefile to build Jam on Unix with the default compiler
# (i.e. "cc" or "$CC" when defined)
#
# To use it, you must be in the top Jam source directory,
# and call
#
#    make
#
.POSIX:

SHELL   = /bin/sh
CC      = cc
DELETE  = rm -f
CFLAGS  =
TARGET  = -o jam0
# The Jam executable name. This is "jam" on Unix,
# except Cygwin where it will be "jam.exe".
JAMEXE  = jam

all: FEATURE/jam jam0
	chmod a+w jambase.c
	./jam0

FEATURE/jam: iffe.sh jam.iff
	$(SHELL) iffe.sh --cc=$(CC) -v jam.iff

check:
	@echo There is no validation suite for this package.

clean:
	@-$(DELETE) FEATURE/*
	@-$(DELETE) -r tgt/*
	@-$(DELETE) jam0
	@-$(DELETE) *.o

include common.mk
