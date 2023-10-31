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

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

char *appendStr(char *str, ...) {
    va_list valist;
    char *ret = NULL;
    size_t totalLength = 1; 
    
    va_start(valist, str);

    char *currStr = str;
    while (currStr != NULL) {
        totalLength += strlen(currStr);
        currStr = va_arg(valist, char *);
    }

    va_end(valist);

    ret = (char *)malloc(totalLength);

    if (ret == NULL) {
        return NULL; 
    }

    va_start(valist, str);
    currStr = str;
    strcpy(ret, currStr);
    while ((currStr = va_arg(valist, char *)) != NULL) {
        strcat(ret, currStr);
    }

    va_end(valist);

    return ret;
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