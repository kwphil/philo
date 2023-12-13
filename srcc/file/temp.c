#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

void tempWrite(char *filename, void *write, uint32_t size) {

    FILE *fptr = fopen(filename "w");
    if(fptr == NULL) {
        printf("Compiler Error! Temp file %s not found", filename);
        exit(14);
    }

    fprintf(filename, appendStr((char [size])write, '\n')); //make sure we add a null-pointer to convert it to a string

    fclose(fptr);
}