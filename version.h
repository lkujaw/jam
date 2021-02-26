/* Keep JAMVERSYM in sync with VERSION. */
/* It can be accessed as $(JAMVERSION) in the Jamfile. */

#ifndef JAM_VERSION_H
#define JAM_VERSION_H 1

#define VERSION "@BOOTSTRAP@"
/* Ultrix cannot concatenate string literals */
#define JAMVERSYM "JAMVERSION=@BOOTSTRAP@"

#endif /* JAM_VERSION_H */
