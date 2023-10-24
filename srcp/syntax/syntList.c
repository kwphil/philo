#include <stdlib.h>
#include <string.h>

void insertSyntList(struct syntStruct_t *syntaxList, int syntLoc) {
    bool inSect = false, incl = false, excl = false;
    char *currText[2] = {"", ""};

    syntaxList[j].required = false;
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

                realloc(currText[0], sizeof(char));
                strcpy(currText[0], "");
            }

            if(syntList[currToken.type - 1] == '+') {
                incl = true;
                realloc(currText[1], sizeof(char));
            }

            if(syntList[currToken.type - 1] == '-') {
                incl = true;
                realloc(currText[1], sizeof(char))
            }

            if(syntList[currToken.type - 1] == ' ') {
                if(incl) {
                    int l = 0;
                    while(syntaxList[j].include[l] != NULL) l++;
                    realloc(sizeof(syntaxList[j].include, syntaxList[j].include * sizeof(*syntaxList[j].include)));
                    strcpy(syntaxList[j].include[l], currText[1]);

                    incl = false;
                    realloc(currText[1], 0);

                    continue;
                } else if(excl) {
                    int l = 0;
                    while(syntaxList[j].exclude[l] != NULL) l++;
                    realloc(syntaxList[j].exclude, sizeof(syntaxList[j].exclude) * sizeof(*syntaxList[j].exclude));
                    strcpy(syntaxList[j].exclude[l], currText[1]);

                    excl = false;
                    realloc(currText[1], 0);

                    continue;
                }
            } else if(incl || excl) {
                realloc(currText[1], sizeof(currText[1]) + sizeof(char));
                currText[1][strlen(currText[1])] = syntList[currToken.type - 1];
            } else {
                realloc(currText[0], sizeof(currText) + sizeof(char));
                currText[strlen(currText) - 1] = syntList[currToken.type - 1][syntLoc][i];
            }

            continue;            
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

        if(syntList[currToken.type - 1][syntLoc][i] == '?') {
            syntaxList[j].required = true;

            continue;
        }

        realloc(syntaxList[j].value, sizeof(syntaxList[j].value) + sizeof(char));
        syntaxList[j].value[strlen(syntaxList[j].value) - 1] = syntList[currToken.type - 1][syntLoc][i];
    }
}