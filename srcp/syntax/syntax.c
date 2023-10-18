#include <stdlib.h>
#include <stdbool.h>
#include "../../srcc/file/read.h"

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

token_t currToken;

bool checkSyntax() {
    int i = 0;
    setWord(0);

    while(currFile.tokenList[i++][0] != NULL) {
        

        if(!checkTokenSyntax(i)) return false;
    }
}

checkTokenSyntax