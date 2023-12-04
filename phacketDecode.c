#include <stdio.h>
#include <stdlib.h>
#include "srcc/file/file.h"
#include "srcc/string/string.h"

int main(int argc, char *argv[]) {
    int line_count = atoi(argv[1]);
    int file_index = 0;
    char *file = readFile("temp.txt");

    if(file == NULL) {
        printf("Error! could not read the file!");
        return 1;
    }

    for(int i = 0; file[i] != '\0'; i++) {
        size_t size = 1;
        char *currLine = (char *)malloc(sizeof(char));

        for(int j = 0; file[j] != '\n'; i++) {
            realloc(currLine, ++size);
            currLine[size - 1] = file[file_index++];
        }

        decodeLine(currLine);
    }

    return 0;
}

void decodeLine(char *currLine) {
    int index = 0;
    char *currWord = nextWord(currLine, index);

    //We want to inc the index in order to account for the whitespace between words
    switch(1) {
        case(strcmp(currWord, "new")):
            if(strcmp(nextWord(currLine, index++)), "dir") system(appendStr("mkdir ", nextWord(currLine, index++)));
            else system(appendStr("touch ", nextWord(currLine, index++)));
        return;
        case(strcmp(currWord, "edit")):
        
    }
}

char *nextWord(char *currLine, int index) {
    size_t size 
    char *currWord = (char *)malloc(sizeof(char));

    for(int i = 0; i != ' '; i++) {
        realloc(currWord, ++size);
        currWord[i] = currLine[index++];
    }

    return currWord;
}