#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../srcp/types/types.h"
#include "../../cmplr/error/error.h"

string_t readFile(const string_t filename) {
    FILE *fptr = fopen(filename, "r");
    if(fptr == NULL) {
        bError = true;
        char _sError[] = appendStr("Can't open file: ", filename);
        realloc(sError, sizeof(_sError));
        strcpy(sError, _sError); 
        free(_sError);
        return "\0";
    }
    char ret[] = (char *)malloc(sizeof(char));
    char ch;
    int  size = 0;

    do {
        realloc(ret, sizeof(char) * (size++));
        
        ch = fgetc(fptr);
        ret[size - 1] = ch;
    } while((int)ch != EOF);
    
    if(ret[size - 1] != NULL) {
        realloc(ret, sizeof(char) * (size++));
        ret[size - 1] = NULL;
    }
    
    //What we are doing is adding one more to the alloc space of the string, reading the char 
    //And putting it at the end of the string. If there is not a null at the end, 
    //We will put one on there real quick

    fclose(fptr);

    //Now as an extra, we will update the currFile

    realloc(currFile.contents, sizeof(char) * size);
    strcpy(currFile.contents, ret);
    realloc(currFile.name, strlen(filename));
    strcpy(currFile.name, filename);
    strcpy(currFile.asmList[0], (char *)NULL);

    return ret;
}

void writeFile(const string_t filename, const string_t data) {
    FILE *fptr = fopen(filename, "w");
    fprintf(fptr, data);
    fclose(fptr);
}
