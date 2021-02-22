#ifndef ANSI_H
#define ANSI_H

#if __STDC__
# define PROTO(x) x
#else
# define PROTO(x) ()
# define const
#endif

#endif /* ANSI_H */
