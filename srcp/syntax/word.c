#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "syntax.h"
#include "../../srcc/string/string.h"

bool checkCurrSyntax(const token_t currToken, const uint8_t currTokenLoc, 
                     const struct syntStruct_t *syntaxList, 
                     register int currCheck, register uint tokenNum) 
{
    if(syntaxList[currCheck].multiple) {
        register int i = 0;
        
        while(checkCurrSyntax0(currFile.tokenList[tokenNum], 
                               currTokenLoc + (++i), 
                               syntaxList, 
                               currCheck + i, 
                               tokenNum + i)) if(bError) return false;
        
        return true;
    }
    
    return checkCurrSyntax0(currToken, currTokenLoc syntaxList, currCheck, tokenNum);
}

bool checkCurrSyntax0(const token_t currToken, const uint8_t currTokenLoc, 
                      const struct syntStruct_t *syntaxList, 
                      const int currCheck, const uint tokenNum) 
{    
    if(syntaxList[currCheck].optional) return true;
    
    if(syntaxList[currCheck].dirDefined) { 
        if(syntaxList[currCheck].value == ';' && currFile.tokenList[tokenNum].value != ';' && SEMI_WARN_FLAG && !SEMI_ERR_FLAG) {
            bWarning = true;
            _sWarning = appendf(
                        "Warning! Missing semicolon at %s::%d:%d\n%s", 
                        currFile.name, currFile.tokenList[tokenNum].loc.line, 
                        currFile.tokenList[tokenNum].loc.word,
                        "Note: Semicolons are not required but are recommended\n");
            realloc(sWarning, sizeof(_sWarning));
            strcpy(sWarning, _sWarning);
            return true;
        }
        if((!matchstr(syntaxList[currCheck].value, currFile.tokenList[tokenNum].value)) || (SEMI_ERR_FLAG && currFile.tokenList[tokenNum].value == ';')) {
            bError = true;
            const char _sError[] = appendStr(appendStr(appendStr("Expected: ", syntaxList[currCheck].value), "But received: "), currFile.tokenList[tokenNum].value);
            realloc(sError, sizeof(_sError));
            strcpy(sError, _sError);
            return false;
        }

        return true;
    }

    if(sizeof(syntaxList[currCheck].include) != sizeof(char)) {
        for(int i = 0; syntaxList[currCheck].include[i][0]; i++) 
            if(matchstr(syntaxList[currCheck].include[i], currFile.tokenList[tokenNum].type)) return true;  

        bError = true;
        const char _sError[] = appendStr("Expected: ", aToS(syntaxList[currCheck].include), "But received: ", currFile.tokenList[tokenNum].value);
        realloc(sError, sizeof(_sError));
        strcpy(sError, _sError);
        return false;
    }

    if(sizeof(syntaxList[currCheck].exclude) != sizeof(char)) {
        for(int i = 0; syntaxList[currCheck].exclude[i][0] != NULL; i++) {
            if(!matchstr(syntaxList[currCheck].exclude[i], currFile.tokenList[tokenNum].type)) {
                bError = true;
                const char _sError[] = appendStr("Didn't expect: ", aToS(syntaxList[currCheck].exclude), "But received: ", currFile.tokenList[tokenNum].value);
                realloc(sError, sizeof(_sError));
                strcpy(sError, _sError);
                return false;
            }

            return true;
        }
    }

    if(!(syntaxList[currCheck].type == switchTypeToInt(currFile.tokenList[tokenNum].type))) {
        bError = true;
        const char _sError[] = append
    }
}