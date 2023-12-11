#include "cmplToolchain.h"
#include <stdint.h>

cmplToolchain_t cmpl = setCmplToolchain();

setCmplToolchain() {
    cmplToolchain_t ret;

    ret.setCompileUntil = cmplToolchain_SetCompileUntil;
}

cmplToolchain_SetCompileUntil(char *input, uint64_t data) {
    
}