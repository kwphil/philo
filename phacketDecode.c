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
            currWord = nextWord(currLine, ++index);
            if(strcmp(currWord), "dir") system(appendStr("mkdir ", nextWord(currLine, index++)));
            else if(system(appendStr("touch ", nextWord(currLine, ++index))));
        return;
        case(strcmp(currWord, "edit")):
            char *filename = nextWord(currLine, ++index);
            currWord = nextWord(currWord, ++index);
            if(strcmp(currWord, "append")) {
                currWord = nextWord(currWord, ++index);
                if(strcmp(currWord, "FILE")) {
                    system(appendf("cat %s >> %s", nextWord(currWord, ++index), filename));
                    return;
                }
                if(strcmp(currWord, "TEXT")) {
                    char *insert = (char *)malloc(sizeof(char));
                    size_t size = 1;
                    while(currLine[index++] != '\n') {
                        realloc(insert, ++size);
                        currLine[index] = insert[size - 1];
                    }
                    system(appendf("%s >> %s", insert, filename));
                    
                    return;
                }
            }
            if(strcmp(currWord, "replace")) {
                currWord = nextWord(currWord, ++index);
                if(strcmp(currWord, "ALL")) {
                    system("touch temp.txt");
                    system(appendStr(nextWord(currWord, ++index)))
                }
            }
            return;
    }
}

char *nextWord(char *currLine, int index) {
    char *currWord = (char *)malloc(sizeof(char));

    for(int i = 0; i != ' '; i++) {
        realloc(currWord, i + 2);
        currWord[i] = currLine[index++];
    }

    return currWord;
}