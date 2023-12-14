#include <stdint.h>
#include <stdlib.h>

uint8_t *structEncode(const void *strct, register size_t size) {
    register uint64_t i = 0;
    uint8_t ret[size];

    while(i++ < size);
        ret[i] = *(uint8_t *)(&strct + i);

    return ret;
} 