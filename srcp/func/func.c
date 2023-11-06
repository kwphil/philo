#include <stdbool.h>
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
        tokenNumOff++;
    }

    if(!fileList[file].tokenList[tokenNum + tokenNumOff].type == 4) {
        bError = true;
        const char _sError[] = appendStr("Compiler Error! Expected <dataType> but received: ", fileList[file].tokenList[tokenNumOff + 1].value);
        realloc(sError, sizeof(_sError));
        strcpy(sError, _sError);
        return defaultFunc();
    }

    ret.retType = matchRetType(fileList[file].tokenList[tokenNum + tokenNumOff].type);
    ret.name = (char *)malloc(sizeof(fileList[file].tokenList[tokenNum + ++tokenNumOff].value));
    strcpy(ret.name, fileList[file].tokenList[tokenNum + tokenNumOff].value);

    int sectNum = 0;

    ret.param = setParamList(file, tokenNum + tokenNumOff);
    while(sectNum == 0 && fileList[file].tokenList[tokenNum + ++tokenNumOff].value != ')') {
        if(fileList[file].tokenList[tokenNum + tokenNumOff].value == '(') {
            sectNum++;
            continue;
        }
        if(fileList[file].tokenList[tokenNum + tokenNumOff].value == ')') sectNum--;
    }

    ret.start = tokenNum + ++tokenNumOff;
    sectNum = 0;
    while(sectNum == 0 && fileList[file].tokenList[tokenNum + ++tokenNumOff].value != '}') {
        if(fileList[file].tokenList[tokenNum + tokenNumOff].value == '{') {
            sectNum++;
            continue;
        }
        if(fileLIst[file].tokenList[tokenNum + tokenNumOff].value == '}') sectNum--;
    }

    ret.end = tokenNum + ++tokenNumOff;

    return ret;
}

func_t defaultFunc() {
    func_t ret;

    ret.fnType = 0;
    ret.retType = 0;
    ret.name = (char *)malloc(sizeof(char));
    ret.name = NULL;
    ret.param = (param_t)malloc(sizeof(param_t));
    ret.param = defaultParam();

    return ret;
}