/*
 * Copyright 1993, 1995 Christopher Seiwald.
 *
 * This file is part of Jam - see jam.c for Copyright information.
 */

/*
 * make.h - bring a target up to date, once rules are in place
 *
 * 11/04/02 (seiwald) - const-ing for string literals
 */

#ifndef JAM_MAKE_H
#define JAM_MAKE_H 1

#include "cstd.h"
#include "rules.h"

BEGIN_EXTERNS

int make  PARAM((int n_targets, const char **targets, int anyhow));
int make1 PARAM((TARGET *t));

END_EXTERNS

#endif /* JAM_MAKE_H */
