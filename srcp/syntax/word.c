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
        
        currCheck + i;
        tokenNum + i;
        return true;
    }
    
    return checkCurrSyntax0(currToken, currTokenLoc syntaxList, currCheck, tokenNum);
}

bool checkCurrSyntax0(const token_t currToken, const uint8_t currTokenLoc, 
                      const struct syntStruct_t *syntaxList, 
                      const int currCheck, const uint tokenNum) 
{
    
    if(syntaxList[currCheck].dirDefined) 
        return matchstr(syntaxList[currCheck][].value, 
                        currFile.tokenList[tokenNum].value);


}