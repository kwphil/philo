#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdint.h>
#include "../../srcc/file/read.h"
#include "syntList.h"

const char *syntList[][] = {*keywordSynt, *operatorSynt};

const char *keywordSynt[] = {
    "^ 'int' ?':RET';", //return
    "^('bool') 'exprList'", //while 
    "^('bool') 'exprList'", //if
    "^('expr';'expr';'expr' ?':FOR') 'exprList'", //for
    "^ 'retType' 'name'?':'?'::register' ?\"=<value>\";", //var
    "^ 'retType' 'name' (#'args') 'exprList'" //fn
};

const char *operatorSynt[] = {
    "^ 'macro'", //#
    "^ 'asmLine'", //%
    "^'expr')", //(
    "\0", //)
    "^'int']", //[
    "\0", //]
    "'structObj'^'var'", //.
    "'macroList'^'macro'", //->
    "'int'^", //++
    "'int'^", //--
    "\0" //:
    "\"'int'^'int'\" | \"'char`'^'char`'\"",
    "'int'^'int' | 'char`'^'int'",
    "^'bool",
    "^'int'",
    "^'var'",
    "^'var'",
    "^('ANY')",
    "^('macro', 'int') | ^('macro')",
    "'int'^'int' | 'char`'^'int'",
    "'int'^'int'",
    "'int'^'int'",
    "'int'^'int'",
    "'int'^'int'",
    "'int'^'int'",
    "'int'^'int'",//<=
    "'int'^'int'",
    "'int'^'int'",
    "'expr -void'^'expr -void'",
    "'expr -void'^'expr -void'",
    "'int'^'int'",
    "'int'^'int'",
    "'int'^'int'",
    "'bool'^'value':'value'",
    "\0",
    "'var'^'value'",
    "'var'^'value'",
    "'var'^'value'",
    "'var'^'value'", //*=
    "'var'^'int'",
    "'var'^'int'",
    "'var'^'int'",
    "'var'^'int'",
    "'var'^'int'",
    "'var'^'int'",
    "'var'^'int'",
    "'value'^'value'"
};

token_t prevToken, currToken, nextToken;

bool checkSyntax() {
    int i = 0;

    prevToken.type = -1;

    currToken = currFile.tokenList[0];
    nextToken = currFile.tokenList[1];
    while(currFile.tokenList[i++][0] != NULL) {
        prevToken = currToken;
        currToken = nextToken;
        nextToken = currFile.tokenList[i + 1];

        if(!checkTokenSyntax(i)) return false;
    }

    return true;
}

bool checkTokenSyntax(int tokenNum) {
    for(int i = 0; syntList[currToken.type - 1][i][0] != NULL; i++)
        if(matchstr(currToken.value, tokenTypeList[currToken.type - 1][i])) 
            return syntCheck(i, tokenNum);

    //Return compiler error
    bError = true;
    char _sError[] = appendStr("Compiler Error: Uncaught token: ", currToken.value)
    realloc(sError, strlen(_sError));
    strcpy(sError, _sError);
    return false;
}

bool syntCheck(const int i, const int tokenNum) {
    uint8_t currTokenLoc = 0;

    if(syntList[currToken.type - 1][syntLoc][0] == '\0') return true;

    struct syntStruct_t *syntaxList;
    insertSyntList(syntaxList, i);

    if(bError) return false;
    
    if(matchstr(currToken.value, symbList[currToken.type - 1][syntLoc][0])) {
        bError = true;
        const char _sError[] = appendStr("Compiler Error: Unmatched token: ", currToken.value);
        realloc(sError, sizeof(_sError));
        strcpy(sError, _sError);
        return false;
    }

    while(syntaxList[++currTokenLoc].value[0] != '^');

    for(int i = 0; syntaxList[i].value[0] != NULL; i++)
        if(!checkCurrSyntax(currToken, currTokenLoc, syntaxList, i, tokenNum)) return false;

    return true;
}