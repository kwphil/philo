#include ../../srcp/types/types.h
#include <string.h>

string_t appendStr(string_t str1, string_t str2) {
  char ret[strlen(str1) + strlen(str2)];

  strcpy(ret, str1);
  strcat(ret, str2);
}
