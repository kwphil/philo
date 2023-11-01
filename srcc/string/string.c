#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>

char * substr(const char * str, const int start, const int end) {
  int _start = start, _end = end;
  
  if(_start < 0) _start -= strlen(str) - 1;
  if(_end <= 0) _end -= strlen(str) - 1;

  char *ret = (char *)malloc((size_t)_end - _start + 1);

  for(int i = _start, j = 0; i < _end; i++) {
    ret[j] = str[i];
  }
  
  return ret;
}

char *appendStr(const char *str, ...) {
    va_list args;
    char *ret = NULL;
    size_t totalLength = 1; 
    
    va_start(args, str);

    char *currStr = str;
    while (currStr != NULL) {
        totalLength += strlen(currStr);
        currStr = va_arg(args, char *);
    }

    va_end(args);

    ret = (char *)malloc(totalLength);

    if (ret == NULL) {
        return NULL; 
    }

    va_start(args, str);
    currStr = str;
    strcpy(ret, currStr);
    while ((currStr = va_arg(args, char *)) != NULL) {
        strcat(ret, currStr);
    }

    va_end(args);

    return ret;
}

char *appendf(const char *str, ...) {
    va_list args;
    va_start(args, str);

    va_list args_copy;
    va_copy(args_copy, args);
    int size = vsnprintf(NULL, 0, str, args_copy) + 1; 
    va_end(args_copy);

    if (size <= 0) {
        va_end(args);
        return NULL;
    }

    char *ret = (char *)malloc(size);
    if (ret == NULL) {
        va_end(args);
        return NULL;
    }

    vsnprintf(ret, size, str, args);

    va_end(args);

    return ret;
}

bool isNum(const char * str) {
  int i = 0;
    
  while(str[i] != NULL)
    if(!isdigit(str[i])) return false;

  return true;
}

char *sToA(const char **arr) {
  char ret[] = "";

  for(register int i = 0, k = 0; arr[i][0] != NULL; i++)
    for(register int j = 0; arr[i][j] != NULL; j++) {
      realloc(ret, sizeof(ret) + sizeof(char));
      ret[++k] = arr[i][j];
    }

  return ret;
}

int main() {
    return 0;
}