#ifndef OS_FUNC_TOOLSET_H
#define OS_FUNC_TOOLSET_H

#include "../../../srcc/types/struct.h"

void setOSToolset();
extern toolset_t os;

typedef struct __OSToolset_t {
    char **bootloader;
    void *convertToASM;
    void *insertASM;
} OSToolset_t;

#endif