/* TODO: Split this file into ANSI and POSIX */
#ifndef _def_jam_jam
#define _def_jam_jam	1
#define _sys_types	1	/* #include <sys/types.h> ok */
#include <sys/types.h>
#include <assert.h>
#define _mac_assert	1	/* assert is a macro */

#include <ctype.h>
#include <limits.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <fcntl.h>
#define _lib_vfork	1	/* vfork() in default lib(s) */
#define _lib_wait	1	/* wait() in default lib(s) */
#define _ptr_void	1	/* standard C void* ok */
/* standard C void* ok */
#define voidT void

#define SIZET_MIN 0
#define SIZET_MAX 4294967295
#define SIZET_CHR 10
#define _sizet_u	1	/* size_t is unsigned int */
/* size_t is unsigned int */
typedef unsigned int sizeT;
#define SIZET_FMT "%u"
#endif
