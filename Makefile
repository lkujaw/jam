# Makefile to build Jam on Unix with the default compiler
# (i.e. "cc" or "$CC" when defined)
#
# To use it, you must be in the top Jam source directory,
# and call
#
#    make
#
# the program "jam" will be created in the new
# directory named "bin.unix"
#

.POSIX:

CC      = cc
CFLAGS  =
TARGET  = -o jam0

all: FEATURES/jam.h jam0
	chmod a+w jambase.c
	./jam0

FEATURES/jam.h: jam.iff
	./iffe.sh -v jam.iff

include common.mk

############################################################################
#
# The following is very specific and deals with installation
# it implements "make install" and "make uninstall" for the
# Jam executable.
#
# Note that for now, no documentation is installed with the executable
#

BUILD_DIR    = bin.unix

PREFIX       = /usr/local
EXEC_PREFIX  = $(PREFIX)
LIBDIR       = $(EXEC_PREFIX)/lib
BINDIR       = $(EXEC_PRREFIX)/bin
INCLUDEDIR   = $(PREFIX)/include
DATADIR      = $(PREFIX)/share

DELETE       = rm -f

# The Jam executable name. This is 'jam' on Unix, except Cygwin where
# it will be "jam.exe".
#
JAMEXE           = jam
INSTALL          = /usr/bin/install -c
INSTALL_PROGRAM  = $(INSTALL)
MKINSTALLDIRS    = builds/unix/mkinstalldirs


# Unix installation and deinstallation targets.
# Package managers can use the DESTDIR variable to force another
# installation prefix
#
install: jam0
	$(MKINSTALLDIRS) $(DESTDIR)$(bindir)
	$(INSTALL_PROGRAM) $(BUILD_DIR)/$(JAMEXE) $(DESTDIR)$(bindir)/$(JAMEXE)

uninstall:
	-$(DELETE) $(DESTDIR)$(bindir)/$(JAMEXE)

clean:
	@-$(DELETE) $(BUILD_DIR)/*
	@-$(DELETE) FEATURE/*
	@-$(DELETE) jam0
	@-$(DELETE) *.o

check:
	@echo There is no validation suite for this package.
