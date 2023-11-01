#ifndef PSWORD_H
#define PSWORD_H

#include <stdbool.h>
#include "../../srcc/string/string.h"
#include "syntax.h"

/* Used in syntax.c to check each word individually */
bool checkCurrSyntax(const token_t currToken, const uint8_t currTokenLoc, 
                     const struct syntStruct_t *syntaxList, 
                     register int currCheck, register uint tokenNum);

#endif
