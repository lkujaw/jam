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

#ifndef FILESYS_H
#define FILESYS_H

#include "ansi.h"
#include "jam.h"

typedef void (*scanback)PROTO(( void *closure, const char *file,
                                int found, time_t t ));

void file_dirscan  PROTO(( const char *dir, scanback func, void *closure ));
void file_archscan PROTO(( const char *arch, scanback func, void *closure ));

int file_time PROTO(( const char *filename, time_t *time ));

#endif /* FILESYS_H */
