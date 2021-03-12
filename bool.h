#ifndef JAM_BOOL_H
#define JAM_BOOL_H 1

#ifndef FALSE
# define FALSE (boolT)0
#endif

#ifndef TRUE
# define TRUE (boolT)1
#endif

/*lint -strong(AJXB,boolT)*/
typedef unsigned char boolT;

#endif  /* JAM_BOOL_H */
