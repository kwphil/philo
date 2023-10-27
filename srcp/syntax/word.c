#include "syntax.h"

bool checkCurrSyntax(const token_t currToken, const uint8_t currTokenLoc, 
                     const struct syntStruct_t *syntaxList, 
                     int currCheck, uint tokenNum) 
{
    if(syntaxList[currCheck].multiple) {
        int i = 0;
        
        while(checkCurrSyntax0(getNextToken(tokenNum), 
                               currTokenLoc + (++i), 
                               syntaxList, 
                               currCheck + i, 
                               tokenNum + i))
        
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