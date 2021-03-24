/*
 * command.h - the CMD structure and routines to manipulate them
 *
 * Both ACTION and CMD contain a rule, targets, and sources.  An
 * ACTION describes a rule to be applied to the given targets and
 * sources; a CMD is what actually gets executed by the shell.  The
 * differences are due to:
 *
 *      ACTIONS must be combined if 'actions together' is given.
 *      ACTIONS must be split if 'actions piecemeal' is given.
 *      ACTIONS must have current sources omitted for 'actions updated'.
 *
 * The CMD datatype holds a single command that is to be executed
 * against a target, and they can chain together to represent the
 * full collection of commands used to update a target.
 *
 * Structures:
 *
 *      CMD - an action, ready to be formatted into a buffer and executed
 *
 * External routines:
 *
 *      cmd_new() - return a new CMD or 0 if too many args
 *      cmd_free() - delete CMD and its parts
 *      cmd_next() - walk the CMD chain
 */

/*
 * CMD - an action, ready to be formatted into a buffer and executed
 */

#ifndef JAM_COMMAND_H
#define JAM_COMMAND_H 1

#include "cstd.h"
#include "lists.h"
#include "rules.h"

#define cmd_next(c) ((c)->next)

typedef struct _cmd CMD;

struct _cmd {
    CMD    *next;
    CMD    *tail;    /* valid on in head */
    RULE   *rule;    /* rule->actions contains shell script */
    LIST   *shell;   /* $(SHELL) value */
    LOL     args;    /* LISTs for $(<), $(>) */
    voidT  *buf;     /* actual commands */
};

BEGIN_EXTERNS

CMD *cmd_new PARAM
((
    RULE    *rule,          /* rule (referenced) */
    LIST    *targets,       /* $(<) (freed) */
    LIST    *sources,       /* $(>) (freed) */
    LIST    *shell,         /* $(SHELL) (freed) */
    int      maxline        /* max line length */
));

void cmd_free PARAM((CMD *cmd));

END_EXTERNS

#endif /* JAM_COMMAND_H */
