#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdint.h>
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
            return syntCheck(i);

    //Return compiler error
    bError = true;
    char _sError[] = appendStr("Compiler Error: Uncaught token: ", currToken.value)
    realloc(sError, strlen(_sError));
    strcpy(sError, _sError);
    return false;
}

bool syntCheck(int i) {
    struct syntStruct_s *syntaxUse;
    insertSyntList(syntaxUse, i);
    if(bError) return false;
    for(int i = 0; i < strlen(syntList[currToken.type - 1][i]); i++) {

    }

    bError = true;
    const char _sError[] = "Compiler Error: Uncaught compiler error in syntax.c::106:99!";
    realloc(sError, _sError);
    strcpy(sError, _sError);
    free(_sError);
    return false;
}

void insertSyntList(struct syntStruct_s *syntaxList, int syntLoc) {
    if(syntList[currToken.type - 1][syntLoc][0] == '\0') return true;

    bool inSect = false, incl = false, excl = false;
    char currText = "";

    for(int i = 0, j = 0; i < strlen(syntList[currToken.type - 1][syntLoc]); i++) {
        if(inSect) {
            if(incl && excl) {
                bError = true;
                const char _sError[] = "Compiler Error! var incl & excl are both defined";
                realloc(sError, sizeof(_sError));
                strcpy(sError, _sError);

                return;
            }
            if(syntList[currToken.type - 1][i] == '\'') {
                inSect = false;

                strcpy(syntaxList[j++].value, currText);

                realloc(currText, sizeof(char));
                strcpy(currText, "");
            }

            if(syntList[currToken.type - 1] == '+') {
                incl = true;
            }

            if(syntList[currToken.type - 1] == ' ') {
                if(!incl && !excl) break;

            }

            continue;

            NONE:
            realloc(currText, sizeof(currText) + sizeof(char));
            currText[strlen(currText) - 1] = syntList[currToken.type - 1][syntLoc][i];
        }

        if(syntList[currToken.type - 1][syntLoc][i] == '\'') {
            inSect = true;

            continue;
        }

        if(syntList[currToken.type - 1][syntLoc][i] == '^') {
            syntaxList[j++].dirDefine = true;

            //value
            const char _symbList[] = malloc(sizeof(symbList[currToken.type - 1][syntLoc]));
            strcpy(symbList[currToken.type - 1][syntLoc]);

            realloc(syntaxList[j].value, _symbList);
            strcpy(syntaxList[j].value, _symbList);   

            syntaxList[j].exclude = -1;
            syntaxList[j].include = -1;

            continue;
        }
    }
}

struct syntStruct_s {
    bool    dirDefined;
    char   *value;
    int8_t *exclude;
    int8_t *include;
};