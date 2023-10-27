#include <stdlib.h>
#include <string.h>
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
    if(syntaxList[currCheck].dirDefined) { 
        if(!matchstr(syntaxList[currCheck].value, currFile.tokenList[tokenNum].value)) {
            bError = true;
            const char _sError[] = appendStr(appendStr(appendStr("Expected: ", syntaxList[currCheck].value), "But received: "), currFile.tokenList[tokenNum].value);
            realloc(sError, sizeof(_sError));
            strcpy(sError, _sError);
            return false;
        }
        
        return true;
    }

    if(sizeof(syntaxList[currCheck].include) != sizeof(char)) {
        for(int i = 0; exclude[i][0] )
    }
    if(sizeof(syntaxList[currCheck].exclude) != sizeof(char)) {
        for(int i = 0; exclude[i][0] != NULL; i++) {

        }
    }
}