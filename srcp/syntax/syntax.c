#include <stdlib.h>
#include <stdbool.h>
#include "../../srcc/file/read.h"

const char *syntList[][] = {*keywordSynt, *operatorSynt};

const char *keywordSynt[] = {"^ 'int' ?':RET';", //return
                             "^('bool') 'exprList'", //while 
                             "^('bool') 'exprList'", //if
                             "^('expr';'expr';'expr' ?':FOR') 'exprList'" //for
                            };
const char *operatorSynt[] = {"^ 'macro'",
                              "^ 'asmLine'",
                              "^'expr')",
                              "\0",
                              "^'int']",
                              "\0",
                              "'structObj'^'var'",
                              "'macroList'^'macro'",
                              "'int'^",
                              "'int'^",
                              "'expr +COLAVAILIABLE'^'colExpr'"
                              "'int'^'int' | 'char`'^'char`'",
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
                             }

token_t prevToken;
token_t currToken;
token_t nextToken;

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
    for(int i = 0; syntList[currToken.type - 1][i][0] != NULL; i++) {
        if(matchstr(currToken.value, tokenTypeList[currToken.type - 1][i])) {
            return syntCheck(i);
        }
    }
}