/*
 * option.c - command line option processing
 *
 * {o >o
 *  \<>) "Process command line options as defined in <option.h>.
 *                  Return the number of argv[] elements used up by options,
 *                  or -1 if an invalid option flag was given or an argument
 *                  was supplied for an option that does not require one."
 *
 * 11/04/02 (seiwald) - const-ing for string literals
 */

#include "jam.h"  /* Includes system headers */

#include "option.h"

int
getoptions DECLARE((argc, argv, opts, optv, targets))
    int          argc     NP
    char       **argv     NP
    const char  *opts     NP
    option      *optv     NP
    char       **targets  EP
BEGIN
    int          i, n;
    int          optc = N_OPTS;

    memset((char *)optv, '\0', sizeof(*optv) * N_OPTS);

    n = 0;
    for(i = 0; i < argc; i++) {
        char *arg;

        if(argv[i][0] == '-') {
            if(!optc--) {
                printf("too many options (%d max)\n", N_OPTS);
                return(-1);
            }

            for(arg = &argv[i][1]; *arg; ++arg) {
                const char *f;

                for(f = opts; *f; f++) {
                    if(*f == *arg) {
                        break;
                    }
                }

                if(!*f) {
                    printf("Invalid option: -%c\n", *arg);
                    return(-1);
                }

                optv->flag = *f;

                if(f[1] != ':') {
                    optv++->val = "true";
                } else if(arg[1]) {
                    optv++->val = &arg[1];
                    break;
                } else if(++i < argc) {
                    optv++->val = argv[i];
                    break;
                } else   {
                    printf("option: -%c needs argument\n", *f);
                    return(-1);
                }
            }
        } else {
            /* something like VARNAME=... is treated as an implicit '-s' flag */
            if(argv[i][0] != '=' && strchr(argv[i], '=')) {
                if(!optc--) {
                    printf("too many options (%d max)\n", N_OPTS);
                    return(-1);
                }

                optv->flag  = 's';
                optv++->val = argv[i];
            } else   {
                if(n >= N_TARGETS) {
                    printf("too many targets (%d max)\n", N_TARGETS);
                    return(-1);
                }
                targets[n++] = argv[i];
            }
        }
    }

    return(n);
END_FUNCTION(get_options)


/*
 * Name: getoptval() - find an option given its character
 */
const char *
getoptval DECLARE((optv, opt, subopt))
    option  *optv    NP
    int      opt     NP
    int      subopt  EP
BEGIN
    int  i;

    for(i = 0; i < N_OPTS; ++i, ++optv) {
        if(optv->flag == opt && !subopt--) {
            return(optv->val);
        }
    }

    return(0);
END_FUNCTION(getoptval)
