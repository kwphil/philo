#ifndef CSTRING_H
#define CSTRING_H

#include <stdbool.h>

// Used for some extra string functions

// Outputs the concatenation of two strings without changing either
char *appendStr(char *str1, char *str2);

// Checks if an entire string is a number
// Returns true if the entire string is a number
bool isNum(char *str);

// Substr is just a substring
// Negative inputs will be subtracted by the end of the string
// 0 at the end param will be the last char
char *substr(char *str, int start, int end);

char *appendf(const char *str, ...);

char *sToA(const char **arr);



#endif
