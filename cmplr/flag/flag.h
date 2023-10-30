#ifndef FLAG_H
#define FLAG_H

#include <stdbool.h>

/* Sets flags to default value */
void defaultFlag();

/* Contains a list of flags to be used for compiling */

char *PRGM_FOR;
bool SEMI_WARN_FLAG;
bool SEMI_ERR_FLAG;

#endif