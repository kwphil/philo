#include <string.h>
#include <stdint.h>
#include <stdlib.h>
#include "../../cmplr/error/error.h"

void OSCompile() {
    func_t funcList = (func_t)malloc(sizeof(func_t));
    size_t funcSize = 0;

    for(uint16_t fileInc = 0; fileList[fileInc].name != NULL; fileInc++) {
        for(uint32_t tokenInc = 0; fileList[fileInc].tokenList[tokenInc].value != NULL; tokenInc++) {
            if(strcmp(fileList[fileInc].tokenList[tokenInc].value, "fn")) {
                realloc(funcList, ++funcSize * sizeof(func_t));
                funcList[funcSize - 1] = parseFunc(fileInc, tokenInc);
                if(bError) return;
            }
        }
    }

    for(uint16_t i = 0; funcList[i].name)
}