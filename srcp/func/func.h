#ifndef PFUNC_H
#define PFUNC_H

#include "../param/param.h"

func_t parseFunc(loc_t loc);

typedef struct __func_t {
    int fnType;
    int retType;
    char *name;
    param_t *param;
} func_t;

#endif