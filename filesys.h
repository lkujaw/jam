/*
 * Copyright 1993-2002 Christopher Seiwald and Perforce Software, Inc.
 *
 * This file is part of Jam - see jam.c for Copyright information.
 */

/*
 * filesys.h - OS specific file routines
 *
 * 11/04/02 (seiwald) - const-ing for string literals
 */

#ifndef JAM_FILESYS_H
#define JAM_FILESYS_H 1

#include "jam.h"  /* Includes system headers */

#include "ansi.h"

typedef void (*scanback)_ARG_(( Void_t     *closure,
                                const char *file,
                                int         found,
                                time_t      t ));

_BEGIN_EXTERNS_

void file_dirscan  _ARG_(( const char *dir,
                           scanback    func,
                           Void_t     *closure ));

void file_archscan _ARG_(( const char *arch,
                           scanback    func,
                           Void_t     *closure ));

int file_time _ARG_((const char *filename, time_t *time));

_END_EXTERNS_

#endif /* JAM_FILESYS_H */
