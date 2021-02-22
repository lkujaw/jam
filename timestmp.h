/*
 * Copyright 1993, 1995 Christopher Seiwald.
 *
 * This file is part of Jam - see jam.c for Copyright information.
 */

/*
 * timestmp.h - get the timestamp of a file or archive member
 */

#include "ansi.h"

void timestamp  PROTO(( char *target, time_t *time ));
void donestamps PROTO(( void ));
