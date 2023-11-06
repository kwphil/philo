#ifndef PFUNC_H
#define PFUNC_H

#include "../param/param.h"

func_t parseFunc(const int file, const int tokenNum);
func_t defaultFunc();

typedef struct __func_t {
    int fnType;
    int retType;
    char *name;
    param_t *param;
    int start;
    int end;
} func_t;

#endif