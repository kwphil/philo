#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "syntax.h"
#include "../../srcc/string/string.h"

bool checkCurrSyntax(const token_t currToken, const uint8_t currTokenLoc,
                     const struct syntStruct_t *syntaxList,
                     register int currCheck, register uint tokenNum) {
    if (syntaxList[currCheck].multiple) {
        register int i = 0;

        while (checkCurrSyntax0(currFile.tokenList[tokenNum], currTokenLoc + (++i),
                               syntaxList, currCheck + i, tokenNum + i)) {
            if (bError)
                return false;
        }

        return true;
    }

    return checkCurrSyntax0(currToken, currTokenLoc, syntaxList, currCheck, tokenNum);
}

bool checkCurrSyntax0(const token_t currToken, const uint8_t currTokenLoc,
                      const struct syntStruct_t *syntaxList,
                      const int currCheck, const uint tokenNum) {
    if (syntaxList[currCheck].optional)
        return true;

    if (syntaxList[currCheck].dirDefined) {
        if (strcmp(syntaxList[currCheck].value, ";") == 0 && strcmp(currFile.tokenList[tokenNum].value, ";") != 0 &&
            SEMI_WARN_FLAG && !SEMI_ERR_FLAG) {
            bWarning = true;
            const char _sWarning[] = appendf("Warning! Missing semicolon at %s::%d:%d\n%s",
                                            currFile.name, currFile.tokenList[tokenNum].loc.line,
                                            currFile.tokenList[tokenNum].loc.word,
                                            "Note: Semicolons are not required but are recommended\n");
            realloc(sWarning, strlen(_sWarning) + 1);
            strcpy(sWarning, _sWarning);
            return true;
        }
        if ((strcmp(syntaxList[currCheck].value, currFile.tokenList[tokenNum].value) != 0) ||
            (SEMI_ERR_FLAG && strcmp(currFile.tokenList[tokenNum].value, ";") == 0)) {
            bError = true;
            const char _sError[] = appendStr(appendStr(appendStr("Expected: ", syntaxList[currCheck].value),
                                                      "But received: "), currFile.tokenList[tokenNum].value);
            realloc(sError, strlen(_sError) + 1);
            strcpy(sError, _sError);
            return false;
        }

        return true;
    }

    if (strcmp(syntaxList[currCheck].include, "") != 0) {
        char *includeList = syntaxList[currCheck].include;
        char *tokenType = currFile.tokenList[tokenNum].type;
        char *includeToken = strtok(includeList, ",");
        bool matchFound = false;

        while (includeToken != NULL) {
            if (strcmp(includeToken, tokenType) == 0) {
                matchFound = true;
                break;
            }
            includeToken = strtok(NULL, ",");
        }

        if (!matchFound) {
            bError = true;
            const char _sError[] = appendStr("Expected one of: ", syntaxList[currCheck].include,
                                            "But received: ", currFile.tokenList[tokenNum].value);
            realloc(sError, strlen(_sError) + 1);
            strcpy(sError, _sError);
            return false;
        }

        return true;
    }

    if (strcmp(syntaxList[currCheck].exclude, "") != 0) {
        char *excludeList = syntaxList[currCheck].exclude;
        char *tokenType = currFile.tokenList[tokenNum].type;
        char *excludeToken = strtok(excludeList, ",");
        bool matchFound = false;

        while (excludeToken != NULL) {
            if (strcmp(excludeToken, tokenType) == 0) {
                matchFound = true;
                break;
            }
            excludeToken = strtok(NULL, ",");
        }

        if (matchFound) {
            bError = true;
            const char _sError[] = appendStr("Didn't expect: ", syntaxList[currCheck].exclude,
                                            "But received: ", currFile.tokenList[tokenNum].value);
            realloc(sError, strlen(_sError) + 1);
            strcpy(sError, _sError);
            return false;
        }

        return true;
    }

    if (!(syntaxList[currCheck].type == switchTypeToInt(currFile.tokenList[tokenNum].type))) {
        bError = true;
        const char _sError[] = appendStr("Type mismatch: Expected type ", syntaxList[currCheck].type,
                                        "But received type ", switchTypeToInt(currFile.tokenList[tokenNum].type));
        realloc(sError, strlen(_sError) + 1);
        strcpy(sError, _sError);
        return false;
    }

    return true;
}
