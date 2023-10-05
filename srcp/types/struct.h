#ifndef PSTRUCTTYPE_H
#define PSTRUCTTYPE_H

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
