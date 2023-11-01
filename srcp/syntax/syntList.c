#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdint.h>
#include "syntList.h"

void insertSyntList(struct syntStruct_t *syntaxList, int syntLoc) {
    bool inSect = false, incl = false, excl = false;
    char currText[2][256] = {"", ""}; // Change to a 2D array with a reasonable size

    int j = 0; // Moved j outside the loop

    syntaxList[j].required = false;

    for (int i = 0; i < strlen(syntList[currToken.type - 1][syntLoc]); i++) {
        if (inSect) {
            if (incl && excl) {
                bError = true;
                const char _sError[] = "Compiler Error! var incl & excl are both defined";
                realloc(sError, strlen(_sError) + 1); // Allocate enough space
                strcpy(sError, _sError);

                return;
            }

            if (syntList[currToken.type - 1][syntLoc][i] == '\'') {
                inSect = false;

                strcpy(syntaxList[j].value, currText[0]);

                currText[0][0] = '\0';
            }

            if (syntList[currToken.type - 1][syntLoc][i] == '+') {
                incl = true;
                currText[1][0] = '\0';
            }

            if (syntList[currToken.type - 1][syntLoc][i] == '-') {
                excl = true;
                currText[1][0] = '\0';
            }

            if (syntList[currToken.type - 1][syntLoc][i] == ' ') {
                if (incl) {
                    int l = 0;
                    while (syntaxList[j].include[l] != NULL)
                        l++;
                    syntaxList[j].include[l] = strdup(currText[1]);

                    incl = false;
                    currText[1][0] = '\0';

                    continue;
                } else if (excl) {
                    int l = 0;
                    while (syntaxList[j].exclude[l] != NULL)
                        l++;
                    syntaxList[j].exclude[l] = strdup(currText[1]);

                    excl = false;
                    currText[1][0] = '\0';

                    continue;
                }
            } else if (incl || excl) {
                strcat(currText[1], &syntList[currToken.type - 1][syntLoc][i]);
            } else {
                strcat(currText[0], &syntList[currToken.type - 1][syntLoc][i]);
            }

            continue;
        }

        if (syntList[currToken.type - 1][syntLoc][i] == '\'') {
            inSect = true;
            continue;
        }

        if (syntList[currToken.type - 1][syntLoc][i] == '^') {
            syntaxList[j].dirDefine = true;

            // value
            syntaxList[j].value = strdup(symbList[currToken.type - 1][syntLoc]);
            syntaxList[j].exclude = NULL;
            syntaxList[j].include = NULL;

            j++;

            continue;
        }

        if (syntList[currToken.type - 1][syntLoc][i] == '?') {
            syntaxList[j].required = true;

            continue;
        }

        if (syntList[currToken.type - 1][syntLoc][i] == '#') {
            syntaxList[j].multiple = true;

            continue;
        }

        strcat(currText[0], &syntList[currToken.type - 1][syntLoc][i]);
    }
}
