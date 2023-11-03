#include <stdlib.h>
#include <string.h>
#include "func.h"
#include "../param/param.h"

func_t parseFunc(file_t file, int tokenNum) {
    if(!matchstr(fileList[file].tokenList[tokenNum].value, "fn")) {
        bError = true;
        const char _sError[] = appendStr("Compiler Error! Expected 'fn' but received: ", fileList[file].tokenList[tokenNum].value);
        realloc(sError, sizeof(_sError));
        strcpy(sError, _sError);
        return defaultFunc();
    }

    func_t ret;

    
}

func_t defaultFunc() {
    func_t ret;

    fnType = 0;
    retType = 0;
    str = (char *)malloc(sizeof(char));
    str = NULL;
    param = (param_t)malloc(sizeof(param_t));
    param = defaultParam();
}