#include "read.h"
#include <string.h>
#include <stdlib.h>

void setFileLen() {
    fileLen = strlen(currFile.contents);
}

void nextWord() {
    int i = getLoc(currLoc), len = 0;
    char ret[] = malloc(sizeof(char) * 0);

    while(currFile.contents[i] != ' ') {
        if(currFile.contents[i] == '\n') {
            currLoc.line++;
            currLoc.word = 0;
            break;
        }
        currLoc.word++;
    }
    while(currFile.contents[i] == ' ') { //We want to first go past any extra spaces
        i++;
        if(currFile.contents[i] == '\n') {
            currLoc.line++;
            currLoc.word = 0;
        } 
    } 

    while(currFile.contents[i] != ' ' || currFile.contents[i] != '\n') {
        len++;

        realloc(ret, sizeof(char) * len);
        ret[len - 1] = currFile.contents[i];
    }

    realloc(currWord, sizeof(ret));
    strcpy(currWord, ret);
    free(ret);
}
