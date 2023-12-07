#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "srcc/file/file.h"
#include "srcc/string/string.h"

char *prgmName;
char *currWord = (char *)malloc(sizeof(char));
uint32_t index = 0;

int main(int argc, char *argv[]) {
    char *prgmName = (char *)malloc(sizeof(argv[2])), *currWord = (char *)malloc(sizeof(char));
    uint32_t index = 0;
    
    int line_count = atoi(argv[1]);
    int file_index = 0;
    char *file = readFile("temp.txt");

    strcpy(prgmName, argv[2]);

    if(file == NULL) {
        printf("Error! could not read the file!");
        return 1;
    }

    for(int i = 0, j = 0; i < line_count; i++) {
        size_t size = 1;
        char *currLine = (char *)malloc(sizeof(char));

        for (; currLine[j] != '\n'; j++) {
            realloc(currLine, ++size);
            currLine[size - 1] = file[file_index++];
        }

        decodeLine(currLine, i, j, prgmName, currWord, index);
    }

    free(prgmName);
    free(currWord);
    return 0;
}

void decodeLine(char *currLine, int line, int c, char *prgmName, char *currWord, int index) {
    //We want to inc the index in order to account for the whitespace between 
    if(strcmp(currWord, "new")) {
        currWord = nextWord(currLine, currWord, ++index);
        if(strcmp(currWord, "DIR")) system(appendStr("mkdir ", nextWord(currLine, currWord, index)));
        else if(strcmp(currWord, "FILE")) system(appendStr("touch ", nextWord(currLine, currWord, ++index)));
        return;
    }
    if(strcmp(currWord, "edit")) {
        char *filename = nextWord(currLine, currWord, ++index);
        currWord = nextWord(currLine, currWord, ++index);
        if(strcmp(currWord, "append")) {
            nextWord(currLine, currWord, ++index);
            system(appendf("temp.txt >> %s && rm temp.txt", filename));
        }
        else if(strcmp(currWord, "replace")) {
            currWord = nextWord(currLine, currWord, ++index);
            if(strcmp(currWord, "ALL")) {
                nextWord(currLine, currWord, ++index);
                system(appendf("cp -f temp.txt %s && rm temp.txt", filename));
            } else if(isNum(currWord)) {
                nextWord(currLine, currWord, ++index);
                system("$TEXT=$(cat temp.txt)");
                system(appendf("sed '%d s/.*/$TEXT' %s && rm temp.txt", atoi(currWord), filename));
            } else {
                printf("Error at %d:%d. Data type: %s not recognized", line, c, currWord);
                exit(-2);
            }
        }
        free(filename);
        return;
    }
}

void getString(char *currWord, char *currLine, char *prgmName, uint32_t index) {
    currWord = nextWord(currLine, currWord, ++index);
    if(strcmp(currWord, "FILE")) {
        system(appendf("touch temp.txt && wget https://raw.githubusercontent.com/kwphil/phacket/main/%s/%s -O temp.txt", prgmName, nextWord(currLine, currWord, index)));

        return;
    }
    if(strcmp(currWord, "TEXT")) {
        char *insert = (char *)malloc(sizeof(char));
        size_t size = 1;
        while(currLine[index++] != '\n') {
            realloc(insert, ++size);
            currLine[index] = insert[size - 1];
        }
        system(appendf("touch temp.txt && %s >> temp.txt", insert));

        free(insert);
        return;
    }
    else {
        printf("Error in string %s Data type: %s not recognized", currLine, currWord);
        exit(-1);
    }
}

char *nextWord(char *currLine, char *currWord, uint32_t index) {
    currWord = realloc(currWord, sizeof(char));

    for(int i = 0; i != ' '; i++) {
        realloc(currWord, i + 2);
        currWord[i] = currLine[index++];
    }

    return currWord;
}