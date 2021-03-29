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
cmd_new DECLARE((rule, targets, sources, shell, maxline))
    RULE  *rule     NP
    LIST  *targets  NP
    LIST  *sources  NP
    LIST  *shell    NP
    int    maxline  EP
BEGIN
    CMD *cmd = NIL(CMD*);
    memoryAllocateOrFail((voidT**)&cmd, sizeof(*cmd));

    cmd->rule  = rule;
    cmd->shell = shell;
    cmd->next  = NIL(CMD*);
    cmd->buf   = NIL(voidT*);
    memoryAllocateOrFail((voidT**)&cmd->buf, maxline);

    lol_init(&cmd->args);
    lol_add(&cmd->args, targets);
    lol_add(&cmd->args, sources);

    /* Bail if the result won't fit in maxline */
    /* We don't free targets/sources/shell if bailing. */
    if(var_string(rule->actions, cmd->buf, maxline, &cmd->args) < 0) {
        cmd_free(cmd);
        return(NIL(CMD*));
    }

    return(cmd);
END_FUNCTION(cmd_new)


/*
 * cmd_free() - free a CMD
 */
void
cmd_free DECLARE((cmd))
    CMD *cmd  EP
BEGIN
    lol_free(&cmd->args);
    if(cmd->shell != NIL(LIST*)) {
        list_free(cmd->shell);
    }
    memoryRelease((voidT**)&cmd->buf);
    memoryRelease((voidT**)&cmd);
END_FUNCTION(cmd_free)
