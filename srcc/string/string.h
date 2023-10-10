#ifndef CSTRING_H
#define CSTRING_H

#include "../../srcp/types/types.h"
#include <stdbool.h>
//used for some extra string functions

//outputs the concatenation of two strings without changing either
string_t appendStr(string_t str1, string_t str2);

//Checks if an entire string is a number
//Returns true if the entire string is a number
bool isNum(string_t str);

#endif
