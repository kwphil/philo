#include <string.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../../cmplr/error/error.h"

#define MAX_BYTE 512

const asm_t startMsg[] = {asm_t(0, "push bp"), asm_t(0, "mov sp, bp")};
const asm_t bootPadding[] = {asm_t(0, "times 510-($-$$) db 0"), asm_t(0, "dw 0xaa55")};

void OSCompile() {
    // Allocate memory for the funcList based on an initial size.
    size_t initialFuncListSize = 10;  // Adjust the size as needed.
    func_t* funcList = (func_t*)malloc(initialFuncListSize * sizeof(func_t));
    if (funcList == NULL) {
        // Handle memory allocation error.
        return;
    }
    size_t funcSize = 0;

    bool mainSet = false;
    bool startSet = false;
    int startLoc;

    for (uint16_t fileInc = 0; fileList[fileInc].name != NULL; fileInc++) {
        for (uint32_t tokenInc = 0; fileList[fileInc].tokenList[tokenInc].value != NULL; tokenInc++) {
            if (!strcmp(fileList[fileInc].tokenList[tokenInc].value, "fn")) {
                // Check if funcList needs to be expanded.
                if (funcSize >= initialFuncListSize) {
                    initialFuncListSize *= 2;
                    func_t* newFuncList = (func_t*)realloc(funcList, initialFuncListSize * sizeof(func_t));
                    if (newFuncList == NULL) {
                        free(funcList);
                        // Handle memory allocation error.
                        return;
                    }
                    funcList = newFuncList;
                }

                funcList[funcSize] = parseFunc(fileInc, tokenInc);
                if (bError) {
                    free(funcList);  // Free the memory allocated.
                    return;
                }
                funcSize++;
            }
        }
    }

    char* definedNames[funcSize] = {0};  // Initialize an array to hold function names.

    for (size_t i = 0; i < funcSize; i++) {
        if (!strcmp(funcList[i].name, "main")) {
            if (mainSet) {
                bError = true;
                const char _sError[] = "Multiple definitions of main function!";
                realloc(sError, sizeof(_sError));
                appendStr(sError, _sError);
                free(funcList);  // Free the memory allocated.
                return;
            }
            mainSet = true;
        }

        if (!strcmp(funcList[i].name, "start")) {
            if (startSet) {
                bError = true;
                const char _sError[] = "Multiple definitions of start function!";
                realloc(sError, sizeof(_sError));
                appendStr(sError, _sError);
                free(funcList);  // Free the memory allocated.
                return;
            }
            startSet = true;
            startLoc = i;
        }

        for (size_t j = 0; j < funcSize; j++) {
            if (i == j) continue;
            if (!strcmp(funcList[i].name, funcList[j].name)) {
                bError = true;
                const char _sError[] = appendStr("Multiple definitions of function: ", funcList[i].name, "!");
                realloc(sError, sizeof(_sError));
                appendStr(sError, _sError);
                free(funcList);  // Free the memory allocated.
                return;
            }
        }
    }

    if (mainSet) {
        if (funcList[startLoc].retType != 1) {
            bError = true;
            const char _sError[] = "start() is defined incorrectly!";
            realloc(sError, sizeof(_sError));
            appendStr(sError, _sError);
            free(funcList);  // Free the memory allocated.
            return;
        }
    } else if (startSet) {
        if (funcList[startLoc].retType != 0) {
            bError = true;
            const char _sError[] = "main() is defined incorrectly!";
            realloc(sError, sizeof(_sError));
            appendStr(sError, _sError);
            free(funcList);  // Free the memory allocated.
            return;
        }
    } else {
        bError = true;
        const char _sError[] = "No start() or main() function defined!";
        realloc(sError, sizeof(_sError));
        appendStr(sError, _sError);
        free(funcList);  // Free the memory allocated.
        return;
    }

    //from here we can start putting the program together

    int currBytes;
    size_t asmSize = 0;

    for(currBytes = MAX_BYTE; currBytes < aLen(startMsg[]); currBytes -= 2) {
        realloc(asmCompileList, sizeof(asm_t) * ++asmSize);
        asmCompileList[asmSize - 1] = startMsg[MAX_BYTE - currBytes];
    }

    for(; currBytes < MAX_BYTE - 2; currBytes -= 2) {

    }
    realloc(asmCompileList, sizeof(asm_t) * asmSize += 2);
    asmCompileList[asmSize - 2] = bootPadding[0];
    asmCompileList[asmSize - 1] = bootPadding[1];
}