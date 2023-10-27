#include "syntax.h"

bool checkCurrSyntax(const token_t currToken, const uint8_t currTokenLoc, 
                     const syntStruct_t *syntaxList, 
                     const int currCheck, const uint tokenNum) 
{
    if(syntaxList[currCheck].multiple) {
        int i = 0;
        
        while(syntList[tokenTypeToNum(syntaxList[currCheck].type)])
    }
    
    return checkCurrSyntax0(currToken, currTokenLoc syntaxList, currCheck)
}

bool checkCurrSyntax0(const token_t currToken, const uint8_t currTokenLoc, 
                      const syntStruct_t *syntaxList, 
                      const int currCheck, const uint tokenNum) 
{
    
    if(syntaxList[currCheck].dirDefined) 
        return matchstr(syntaxList[currCheck].value, 
                        syntList[tokenTypeToNum(currFile.tokenList)]); //Needs work here
}