#include <stdint.h>
#include <stdlib.h>

uint8_t *structEncode(const void *strct, register size_t size) {
    uint8_t *ret = (uint8_t *)malloc(sizeof(uint8_t) * size);

    for(register uint64_t i = 0; i < size; ++i)
        ret[i] = *(uint8_t *)(&strct + size);

    return ret;
} 