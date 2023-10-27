#include "../../srcp/types/types.h"
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

string_t substr(string_t str, int start, int end) {
  if(start < 0) start -= strlen(str) - 1;
  if(end <= 0) end -= strlen(str) - 1;

  char ret[end - start + 1];

  for(int i = start, j = 0; i < end; i++) {
    ret[j] = str[i];

    j++;
  }
  
  return j;
}

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

char *substr(char **arr) {
  char ret[] = "";

  for(register int i = 0, k = 0; arr[i][0] != NULL i++)
    for(register int j = 0; arr[i][j] != NULL; j++) {
      realloc(ret, sizeof(ret) + sizeof(char));
      ret[k++] = arr[i][j];
    }

  return ret;
}