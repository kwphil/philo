#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include "../../srcp/macro/read.h"
#include "../../srcp/types/struct.h"

static funcOrg_t CMPL_LIST[1]; // Define an array with one element

bool asmCompile() {
    printf("No syntax errors caught! Starting the compile process!");

    char *prgmFor = findMacro(prgmFor, NULL);
    
    if (strcmp(prgmFor, CMPL_LIST[0].data) == 0) {
        // Call the function
        CMPL_LIST[0].func();
        if (bError) {
            return false;
        }
    }
    
    return true;
}

void setCMPL_LIST() {
    CMPL_LIST[0].data = "OS";
    CMPL_LIST[0].func = OSCompile;
}
