#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "func.h"
#include "../../cmplr/flag/flag.h"
#include "../param/param.h"

func_t parseFunc(const int file, const int tokenNum) {
    if (strcmp(fileList[file].tokenList[tokenNum].value, "fn") != 0) {
        bError = true;
        const char _sError[] = appendStr("Compiler Error! Expected 'fn' but received: ", fileList[file].tokenList[tokenNum].value);
        realloc(sError, sizeof(_sError));
        strcpy(sError, _sError);
        return defaultFunc();
    }

    func_t ret;
    int tokenNumOff = 1;

    if (fileList[file].tokenList[tokenNum + tokenNumOff].value[0] == ':') {
        if (!NO_COL_WARN_FLAG) {
            bWarning = true;
            const char _sWarning[] = "Warning! No colon operator present!";
            realloc(sWarning, sizeof(_sWarning));
            strcpy(sWarning, _sWarning);
        }
        ret.fnType = 0;
        tokenNumOff++;
    }

    if (fileList[file].tokenList[tokenNum + tokenNumOff].type != TOKEN_TYPE) {
        bError = true;
        const char _sError[] = appendStr("Compiler Error! Expected <dataType> but received: ", fileList[file].tokenList[tokenNumOff].value);
        realloc(sError, sizeof(_sError));
        strcpy(sError, _sError);
        return defaultFunc();
    }

    ret.retType = matchRetType(fileList[file].tokenList[tokenNum + tokenNumOff].value);
    ret.name = strdup(fileList[file].tokenList[tokenNum + tokenNumOff + 1].value);

    int sectNum = 0;

    ret.param = setParamList(file, tokenNum + tokenNumOff + 3);
    while (sectNum == 0 && strcmp(fileList[file].tokenList[tokenNum + tokenNumOff].value, ")") != 0) {
        if (strcmp(fileList[file].tokenList[tokenNum + tokenNumOff].value, "(") == 0) {
            sectNum++;
        }
        if (strcmp(fileList[file].tokenList[tokenNum + tokenNumOff].value, ")") == 0) {
            sectNum--;
        }
        tokenNumOff++;
    }

    ret.start = tokenNum + tokenNumOff + 1;
    sectNum = 0;
    while (sectNum == 0 && strcmp(fileList[file].tokenList[tokenNum + tokenNumOff].value, "}") != 0) {
        if (strcmp(fileList[file].tokenList[tokenNum + tokenNumOff].value, "{") == 0) {
            sectNum++;
        }
        if (strcmp(fileList[file].tokenList[tokenNum + tokenNumOff].value, "}") == 0) {
            sectNum--;
        }
        tokenNumOff++;
    }

    ret.end = tokenNum + tokenNumOff + 1;

    return ret;
}

func_t defaultFunc() {
    func_t ret;

    ret.fnType = 0;
    ret.retType = 0;
    ret.name = NULL;
    ret.param = defaultParam();

    return ret;
}
