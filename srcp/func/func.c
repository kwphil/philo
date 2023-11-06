#include <stdlib.h>
#include <string.h>
#include "func.h"
#include "../../cmplr/flag/flag.h"
#include "../param/param.h"

func_t parseFunc(const int file, const int tokenNum) {
    if(!matchstr(fileList[file].tokenList[tokenNum].value, "fn")) {
        bError = true;
        const char _sError[] = appendStr("Compiler Error! Expected 'fn' but received: ", fileList[file].tokenList[tokenNum].value);
        realloc(sError, sizeof(_sError));
        strcpy(sError, _sError);
        return defaultFunc();
    }

    func_t ret;
    register int tokenNumOff = 1;

    if(!fileList[file].tokenList[tokenNum + tokenNumOff].value[0] == ':') {
        if(NO_COL_WARN_FLAG) {
            bWarning = true;
            const char _sWarning = "Warning! No colon operator present!";
            realloc(sWarning, sizeof(_sWarning));
            strcpy(sWarning, sizeof(_sWarning));
        }

        ret.fnType = 0;
    }

    if(!fileList[file].tokenList[tokenNum + tokenNumOff].type == 4) {
        bError = true;
        const char _sError[] = appendStr("Compiler Error! Expected ':' or <dataType> but received: ", fileList[file].tokenList[tokenNumOff + 1].value);
        realloc(sError, sizeof(_sError));
        strcpy(sError, _sError);
        return defaultFunc();
    }

    ret.retType = matchRetType(fileList[file].tokenList[tokenNum + tokenNumOff].type);

    
}

func_t defaultFunc() {
    func_t ret;

    fnType = 0;
    retType = 0;
    name = (char *)malloc(sizeof(char));
    name = NULL;
    param = (param_t)malloc(sizeof(param_t));
    param = defaultParam();
}