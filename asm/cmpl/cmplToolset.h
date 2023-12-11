#ifndef CMPLTOOLCHAIN_H
#define CMPLTOOLCHAIN_H

typedef struct {
    void *setCompileUntil(char *input, char *data);
    void *addLines(asm_t *lines);

    bool stopCmpl;
} cmplToolchain_t;

#endif