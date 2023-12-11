#include "cmplToolchain.h"
#include <stdint.h>

cmplToolchain_t cmpl = setCmplToolchain();

void setCmplToolchain() {
    cmpl.setCompileUntil = cmplToolchain_SetCompileUntil;
}

cmplToolchain_SetCompileUntil(char *input, char *data) {
    cmpl.stopCmpl = false;

    if(strcmp(input, "instructions")) {
        
    }
}