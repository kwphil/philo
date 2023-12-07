#ifndef PSTRUCTTYPE_H
#define PSTRUCTTYPE_H

#include "types.h"

//Specifically designed to have datatypes of type struct 

typedef struct {
  int line;
  int word;
} loc_t;

typedef struct {
  char * type;
  int      value;
  loc_t    loc;
} token_t;

typedef struct {
  int section;
  char *ins;
} asm_t;

typedef struct {
  char *name;
  char *contents;
  token_t *tokenList;
  asm_t *asmList;
} file_t;

typedef struct {
  char *data;
  void *func;
} funcOrg_t;

#endif
