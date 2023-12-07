#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "read.h"
#include "../../srcp/types/types.h"
#include "../../cmplr/error/error.h"

char * readFile(const char * filename) {
    FILE *fptr = fopen(filename, "r");
    if (fptr == NULL) {
        printf("Can't open file: %s", filename);
        exit(-3);
        return NULL;
    }
    
    char *ret = NULL;
    char ch;
    int size = 0;

    do {
        ret = (char *)realloc(ret, sizeof(char) * (size + 1));
        ch = fgetc(fptr);
        ret[size] = ch;
        size++;
    } while (ch != EOF);

    ret = (char *)realloc(ret, sizeof(char) * (size + 1));
    ret[size] = '\0';

    fclose(fptr);

    realloc(currFile.contents, sizeof(char) * (size + 1));
    strcpy(currFile.contents, ret);
    realloc(currFile.name, strlen(filename) + 1);
    strcpy(currFile.name, filename);
    strcpy(currFile.asmList[0].ins, '\0');

    return ret;
}

void writeFile(const char * filename, const char * data) {
    FILE *fptr = fopen(filename, "w");
    fprintf(fptr, "%s", data);
    fclose(fptr);
}