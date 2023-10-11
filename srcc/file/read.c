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
    char ret[] = malloc(sizeof(char) * 0);
    bool check;

    while(currFile.contents[i] != ' ') {
        //In case there are any operators we want to catch them
        if(includeOperator)if(currWordIsOperator ^ matchStrInArr(currFile.contents[i], operatorList)) break;

        if(currFile.contents[i] == '\n') {
            currLoc.line++;
            currLoc.word = 0;
            break;
        }
    }
    currLoc.word++;
    while(currFile.contents[i] == ' ') { //We want to first go past any extra spaces
        i++;
        if(currFile.contents[i] == '\n') {
            currLoc.line++;
            currLoc.word = 0;
        } 
    } 

    while(currFile.contents[i] != ' ' || currFile.contents[i] != '\n') {
        if(includeOperator)if(currWordIsOperator ^ matchStrInArr(currFile.contents[i], operatorList)) break;
        len++;

        realloc(ret, sizeof(char) * len);
        ret[len - 1] = currFile.contents[i];
    }

    realloc(currWord, sizeof(ret));
    strcpy(currWord, ret);
    free(ret);
}
