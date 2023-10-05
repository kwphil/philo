#include ../../srcp/types/types.h
#include <string.h>

string_t appendStr(str1, str2) {
  char ret[strlen(str1) + strlen(str2)];

  strcpy(ret, str1);
  strcat(ret, str2);
}
