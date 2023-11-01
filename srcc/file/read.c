#include "read.h"
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../../srcp/types/list.h"

void setFileLen() {
    fileLen = strlen(currFile.contents);
}

bool currWordIsOperator = false;

void nextWord(const bool includeOperator) {
    int i = getLoc(currLoc), len = 0;
    char *ret = (char *)malloc(sizeof(char) * 1);
    ret[0] = '\0';
    bool check;

    while (currFile.contents[i] != ' ') {
        if (includeOperator && (currWordIsOperator ^ matchStrInArr(currFile.contents[i], operatorList))) {
            break;
        }

        if (currFile.contents[i] == '\n') {
            currLoc.line++;
            currLoc.word = 0;
            break;
        }
    }

    currLoc.word++;

    while (currFile.contents[i] == ' ') {
        i++;
        if (currFile.contents[i] == '\n') {
            currLoc.line++;
            currLoc.word = 0;
        }
    }

    while (currFile.contents[i] != ' ' && currFile.contents[i] != '\n') {
        if (includeOperator && (currWordIsOperator ^ matchStrInArr(currFile.contents[i], operatorList))) {
            break;
        }
        len++;

        char *newRet = (char *)realloc(ret, sizeof(char) * (len + 1));
        if (newRet != NULL) {
            ret = newRet;
        }
        ret[len - 1] = currFile.contents[i];
        ret[len] = '\0';
        i++;
    }

    realloc(currWord, sizeof(char) * (len + 1));
    strcpy(currWord, ret);
    free(ret);
}
