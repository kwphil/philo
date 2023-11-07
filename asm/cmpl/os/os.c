#include <string.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../../cmplr/error/error.h"

void OSCompile() {
    func_t *funcList = (func_t)malloc(sizeof(func_t));
    size_t funcSize = 0;
    bool mainSet = false;
    bool startSet = false;

    for(uint16_t fileInc = 0; fileList[fileInc].name != NULL; fileInc++) {
        for(uint32_t tokenInc = 0; fileList[fileInc].tokenList[tokenInc].value != NULL; tokenInc++) {
            if(strcmp(fileList[fileInc].tokenList[tokenInc].value, "fn")) {
                realloc(funcList, ++funcSize * sizeof(func_t));
                funcList[funcSize - 1] = parseFunc(fileInc, tokenInc);
                if(bError) return;
            }
        }
    }

    char *definedNames[aLen(funcList)] = "";

    for(uint32_t i = 0; funcList[i].name != NULL; i++) {
        if(strcmp(funcList[i].name, mainSet)) {
            if(startSet) {
                bError = true;
                const char _sError = "Definitions of both main() and start()!";
                realloc(sError, _sError);
                appendStr(sError, _sError);
                return;
            }
        }

        if(strcmp(funcList[i].name, startSet)) {
            if(mainSet) {
                bError = true;
                const char _sError = "Definitions of both main() and start()!";
                realloc(sError, _sError);
                appendStr(sError, _sError);
                return;
            }
        }

        for(uint32_t j = 0; funcList[j].name != NULL; j++) {
            if(i == j) continue;
            if(strcmp(funcList[i].name, funcList[j].name)) {
                bError = true;
                const char _sError = appendStr("Multiple definitions of function: "), funcList[i].name, "!";
                realloc(sError, _sError);
                appendStr(sError, _sError);
                return;
            }
        }
    }
}