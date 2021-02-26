Portable Jam
============

This project is an effort to broaden the platform support of the last
release of FreeType Jam, 2.5.2. Bug fixes and new features are also
quite welcome.

New Features
============

- Replaces GNU Autotools with AT&T's Iffe, a configuration framework
  that is simpler to master than m4, more portable to diverse Unix
  platforms, self-documenting, and dependent on only one program: a
  Bourne compatible shell.

- Source code compatibility with pre-ANSI compilers has been restored.
  K&R compilers tested include those bundled with HP-UX and ULTRIX.

Why Jam?
========

Maintaining portable software is challenging enough without the added
complexity of keeping native diverse build systems synchronized. Jam
offers an alternative both to old standbys, like the GNU Autotools
suite, that are ill at ease in a non-POSIX environment and new
entrants, like cmake and meson, that are quick to abandon platforms
that do not support the latest standards.

Portable Jam is different. It can run on almost any platform with a C
compiler (K&R only counts), even operating systems almost antithetical
to POSIX/Unix OS fundamentals, such as pre-OS X releases of the
Macintosh System.

ULTRIX
======

Unfortunately, iffe does not work with Ultrix's /bin/sh yet, so run
make SHELL=/bin/ksh.