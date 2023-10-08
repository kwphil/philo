#ifndef PSTRUCTTYPE_H
#define PSTRUCTTYPE_H

#include "types.h"

//Specifically designed to have datatypes of type struct 

typedef struct __token_t {
  string_t type;
  int      value;
  loc_t    loc;
} token_t;

typedef struct __loc_t {
  int line;
  int word;
} loc_t;

typedef struct __file_t {
  char *name;
  char *contents;
  token_t *tokenList;
  asm_t *asmList;
} file_t;

typedef struct __asm_t {
  char *ins;
  loc_t loc;
} asm_t;

#endif
