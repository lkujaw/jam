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

#include "cstd.h"
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

BEGIN_EXTERNS

void compile_builtins PARAM((void));

LIST *compile_append   PARAM((PARSE *parse, LOL *args, int *jmp));
LIST *compile_break    PARAM((PARSE *parse, LOL *args, int *jmp));
LIST *compile_foreach  PARAM((PARSE *parse, LOL *args, int *jmp));
LIST *compile_if       PARAM((PARSE *parse, LOL *args, int *jmp));
LIST *compile_eval     PARAM((PARSE *parse, LOL *args, int *jmp));
LIST *compile_include  PARAM((PARSE *parse, LOL *args, int *jmp));
LIST *compile_list     PARAM((PARSE *parse, LOL *args, int *jmp));
LIST *compile_local    PARAM((PARSE *parse, LOL *args, int *jmp));
LIST *compile_null     PARAM((PARSE *parse, LOL *args, int *jmp));
LIST *compile_on       PARAM((PARSE *parse, LOL *args, int *jmp));
LIST *compile_rule     PARAM((PARSE *parse, LOL *args, int *jmp));
LIST *compile_rules    PARAM((PARSE *parse, LOL *args, int *jmp));
LIST *compile_set      PARAM((PARSE *parse, LOL *args, int *jmp));
LIST *compile_setcomp  PARAM((PARSE *parse, LOL *args, int *jmp));
LIST *compile_setexec  PARAM((PARSE *parse, LOL *args, int *jmp));
LIST *compile_settings PARAM((PARSE *parse, LOL *args, int *jmp));
LIST *compile_switch   PARAM((PARSE *parse, LOL *args, int *jmp));
LIST *compile_while    PARAM((PARSE *parse, LOL *args, int *jmp));

LIST *evaluate_rule PARAM((const char *rulename, LOL *args, LIST *result));

END_EXTERNS

#endif /* JAM_COMPILE_H */
