#ifndef FLAG_H
#define FLAG_H

#include <stdbool.h>

/* Contains a list of flags to be used for compiling */

extern char *PRGM_FOR;
extern bool SEMI_WARN_FLAG;
extern bool SEMI_ERR_FLAG;
extern int MAX_TOKENS;

/* Sets flags to default values */
void defaultFlag();

#endif
