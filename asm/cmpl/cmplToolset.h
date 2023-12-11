#ifndef CMPLTOOLCHAIN_H
#define CMPLTOOLCHAIN_H

#include <stdint.h>

typedef struct {
    void *setCompileUntil(char *input, uint64_t data);
    void *addLines(asm_t *lines);
} cmplToolchain_t;

#endif