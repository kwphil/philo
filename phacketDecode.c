#include <stdio.h>
#include <stdlib.h>
#include "srcc/file/file.h"
#include "srcc/file/read.h"

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

        newLine(currLine);
    }

    return 0;
}

void newLine(char *currLine) {

}