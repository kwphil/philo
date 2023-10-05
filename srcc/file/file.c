#include <stdio.h>
#include <stdlib.h>
#include "../../srcp/types/typedef.h"

string_t readFile(string_t filename) {
    FILE *fptr = fopen(filename);
    if(fptr == NULL) {
        bError = true;
        sError = appendStr("Can't open file: ", filename, "!");
        return "\0";
    }
    string_t ret;
    char ch;

    while(ch != EOF){
        ch = fgetc(fptr);
        ret = appendStr(ret, ch);
    }

    fclose(fptr);
    return ret;
}
