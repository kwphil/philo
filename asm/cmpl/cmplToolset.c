#include "cmplToolchain.h"
#include <stdint.h>

cmplToolchain_t cmpl = setCmplToolchain();

int cmpl_stop_i;
void *cmpl_stop_data;
int instruct_num = 0;

void setCmplToolchain() {
    cmpl.setCompileUntil = cmplToolchain_SetCompileUntil;
}

cmplToolchain_SetCompileUntil(char *input, void *data) {
    cmpl.stopCmpl = false;

    if(strcmp(input, "instruct-num"))
        cmpl_stop_i = 0;

    cmpl_stop_data = data;
}

cmplToolcahin_CheckStop() {
    switch(cmpl_stop_i) {
        case(0):
            if((int)cmpl_stop_data <= instruct_num)
                cmpl.stopCmpl = true;
        return;

        
    }
}