/*
 * command.c - maintain lists of commands
 *
 * 09/08/00 (seiwald) - bulletproof PIECEMEAL size computation
 */

#include "jam.h"  /* Includes system headers */

#include "command.h"
#include "lists.h"
#include "parse.h"
#include "rules.h"
#include "variable.h"
#include "xmem.h"

/*
 * cmd_new() - return a new CMD or 0 if too many args
 */

CMD *
cmd_new(rule, targets, sources, shell, maxline)
    RULE    *rule;
    LIST    *targets;
    LIST    *sources;
    LIST    *shell;
    int     maxline;
{
    CMD *cmd = _NIL_(CMD *);
    memoryAllocateOrFail((voidT **)&cmd, sizeof(*cmd));

    cmd->rule  = rule;
    cmd->shell = shell;
    cmd->next  = 0;

    lol_init(&cmd->args);
    lol_add(&cmd->args, targets);
    lol_add(&cmd->args, sources);

    /* Bail if the result won't fit in maxline */
    /* We don't free targets/sources/shell if bailing. */

    if(var_string(rule->actions, cmd->buf, maxline, &cmd->args) < 0) {
        cmd_free(cmd);
        return(0);
    }

    return(cmd);
}

/*
 * cmd_free() - free a CMD
 */

void
cmd_free(cmd)
    CMD *cmd;
{
    lol_free(&cmd->args);
    list_free(cmd->shell);
    memoryRelease((voidT **)&cmd);
}
