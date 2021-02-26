/*
 * Copyright 1993-2002 Christopher Seiwald and Perforce Software, Inc.
 *
 * This file is part of Jam - see jam.c for Copyright information.
 */

/*
 * compile.h - compile parsed jam statements
 *
 * 01/22/01 (seiwald) - replace evaluate_if() with compile_eval()
 * 01/24/01 (seiwald) - 'while' statement
 * 03/02/02 (seiwald) - rules can be invoked via variable names
 * 02/28/02 (seiwald) - merge EXEC_xxx flags in with RULE_xxx
 * 10/22/02 (seiwald) - working return/break/continue statements
 * 11/04/02 (seiwald) - const-ing for string literals
 */

#ifndef JAM_COMPILE_H
#define JAM_COMPILE_H 1

#include "ansi.h"
#include "lists.h"
#include "parse.h"

/* Conditions for compile_if() */

#define EXPR_NOT       0       /* ! cond */
#define EXPR_AND       1       /* cond && cond */
#define EXPR_OR        2       /* cond || cond */

#define EXPR_EXISTS    3       /* arg */
#define EXPR_EQUALS    4       /* arg = arg */
#define EXPR_NOTEQ     5       /* arg != arg */
#define EXPR_LESS      6       /* arg < arg  */
#define EXPR_LESSEQ    7       /* arg <= arg */
#define EXPR_MORE      8       /* arg > arg  */
#define EXPR_MOREEQ    9       /* arg >= arg */
#define EXPR_IN        10      /* arg in arg */

/* Flags for compile_return */

#define JMP_NONE       0       /* flow continues */
#define JMP_BREAK      1       /* break out of loop */
#define JMP_CONTINUE   2       /* step to end of loop */
#define JMP_RETURN     3       /* return from rule */

_BEGIN_EXTERNS_

void compile_builtins _ARG_((void));

LIST *compile_append   _ARG_(( PARSE *parse, LOL *args, int *jmp ));
LIST *compile_break    _ARG_(( PARSE *parse, LOL *args, int *jmp ));
LIST *compile_foreach  _ARG_(( PARSE *parse, LOL *args, int *jmp ));
LIST *compile_if       _ARG_(( PARSE *parse, LOL *args, int *jmp ));
LIST *compile_eval     _ARG_(( PARSE *parse, LOL *args, int *jmp ));
LIST *compile_include  _ARG_(( PARSE *parse, LOL *args, int *jmp ));
LIST *compile_list     _ARG_(( PARSE *parse, LOL *args, int *jmp ));
LIST *compile_local    _ARG_(( PARSE *parse, LOL *args, int *jmp ));
LIST *compile_null     _ARG_(( PARSE *parse, LOL *args, int *jmp ));
LIST *compile_on       _ARG_(( PARSE *parse, LOL *args, int *jmp ));
LIST *compile_rule     _ARG_(( PARSE *parse, LOL *args, int *jmp ));
LIST *compile_rules    _ARG_(( PARSE *parse, LOL *args, int *jmp ));
LIST *compile_set      _ARG_(( PARSE *parse, LOL *args, int *jmp ));
LIST *compile_setcomp  _ARG_(( PARSE *parse, LOL *args, int *jmp ));
LIST *compile_setexec  _ARG_(( PARSE *parse, LOL *args, int *jmp ));
LIST *compile_settings _ARG_(( PARSE *parse, LOL *args, int *jmp ));
LIST *compile_switch   _ARG_(( PARSE *parse, LOL *args, int *jmp ));
LIST *compile_while    _ARG_(( PARSE *parse, LOL *args, int *jmp ));

LIST *evaluate_rule _ARG_(( const char *rulename, LOL *args, LIST *result ));

_END_EXTERNS_

#endif /* JAM_COMPILE_H */
