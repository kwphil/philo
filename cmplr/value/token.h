#ifndef DTOKEN_H
#define DTOKEN_H

#include "../../srcp/types/struct.h"

//Sets the default value for the token
token_t defaultToken();

//Sets the value of the token
token_t setToken(int type, char *value, loc_t loc);

#endif