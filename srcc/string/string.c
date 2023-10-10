#include ../../srcp/types/types.h
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

string_t appendStr(string_t str1, string_t str2) {
  char ret[strlen(str1) + strlen(str2)];

  strcpy(ret, str1);
  strcat(ret, str2);
}

bool isNum(string_t str) {
  while(str[i] != NULL)
    if(!isdigit(str[i])) return false;

  return true;
}
