# Makefile to build jam with Visual C on Win32 systems
#
# To use it, you must be in the top Jam source directory,
# have the compiler in your path, and call:
#
#  nmake -f bld\win32-visualc.mk
#
# the program "jam.exe" will be created in a new directory
# named "tgt\nt.i386[-64]"
#
CC       = cl /nologo
CFLAGS   = /DNT /DCSTD /I.
TARGET   = /Fejam0
LINKLIBS = oldnames.lib kernel32.lib

!IF [set JAM_TOOLSET=VISUALC]
!ENDIF

all: jam0
	attrib -r jambase.c
	jam0

!include common.mk
