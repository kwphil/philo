#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <unistd.h>
#include <sys/types.h>

void tempPush(char *filename, void *write, size_t size) {

    FILE *fptr = fopen(filename, "w");
    if(fptr == NULL) {
        printf("Compiler Error! Temp file %s not found", filename);
        exit(14);
    }

    fprintf(filename, appendStr((char [size])write, '\0')); //make sure we add a null-pointer to convert it to a string

    fclose(fptr);
}

void *tempPop(char *filename, size_t size) {
    uint64_t i = 0;
    FILE *fptr = fopen(filename, "r");

    while(i++ < size) {
        fseek(fptr, 0, )
    }

    fseek(f, 0, SEEK_END);
    int fSize = ftell(f) - size;

    truncate(filename, fSize);
}