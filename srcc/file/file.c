#include <stdio.h>
#include <stdlib.h>
#include "../../srcp/types/types.h"
#include <string.h>

string_t readFile(string_t filename) {
    FILE *fptr = fopen(filename);
    if(fptr == NULL) {
        bError = true;
        sError = appendStr("Can't open file: ", filename); 
        return "\0";
    }
    ret = (char *) malloc(sizeof(char));
    char ch;
    size_t size = 0;

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

    char retn[size];
    strcpy(retn, ret);
    free(ret);
    return retn;
}
