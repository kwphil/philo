#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include "../../srcp/macro/read.h"
#include "../../srcp/types/struct.h"

bool asmCompile() {
    printf("No syntax errors caught! Starting the compile process!");

    char *prgmFor = findMacro(prgmFor, NULL);
    int i = 0;

    while(CMPL_LIST.data != NULL) {
        if(strcmp(prgmFor, CMPL_LIST.data)) {
            CMPL_LIST.func;

            if(bError) return false;
        }
    }

    
}