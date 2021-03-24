# Makefile to build Jam on Unix with the default compiler
# (i.e. "cc" or "$CC" when defined)
#
# To use it, you must be in the top Jam source directory,
# and call
#
#    make
#
# NOTE: Including '.POSIX:' here will confuse Interix's make.
SHELL   = /bin/sh
CC      = cc
DELETE  = rm -f
# Necessary to bootstrap scan.c
CFLAGS  = $(CCFLAGS) -I.
TARGET  = -o jam0
# The Jam executable name.
#   Cygwin: Substitute jam.exe
JAMEXE  = jam

all: FEATURE/jam jam0
	chmod a+w jambase.c
	./jam0

FEATURE/jam: iffe.sh jam.iff
	$(SHELL) iffe.sh -v --cc="$(CC) $(CFLAGS)" jam.iff

check:
	@echo There is no validation suite for this package.

clean:
	@-$(DELETE) FEATURE/jam
	@-$(DELETE) -r tgt/*
	@-$(DELETE) jam0 jam0.exe
	@-$(DELETE) *.o *.obj

include common.mk
