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

#include "cstd.h"

typedef void (*scanback)PARAM((voidT      *closure,
                               const char *file,
                               int         found,
                               time_t      t));

BEGIN_EXTERNS

void file_dirscan  PARAM((const char *dir,
                          scanback    func,
                          voidT      *closure));

void file_archscan PARAM((const char *arch,
                          scanback    func,
                          voidT      *closure));

int file_time PARAM((const char *filename, time_t *time));

END_EXTERNS

#endif /* JAM_FILESYS_H */
