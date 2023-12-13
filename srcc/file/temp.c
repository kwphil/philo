#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <unistd.h>
#include <sys/types.h>

void tempPush(char *filename, void *write, size_t size) {

    FILE *fptr = fopen(appendStr("temp/", filename), "w");
    if(fptr == NULL) {
        printf("Compiler Error! Temp file %s not found", filename);
        exit(14);
    }

    fprintf(filename, appendStr((char [size])write, '\0')); //make sure we add a null-pointer to convert it to a string

    fclose(fptr);
}

void *tempPop(char *filename, size_t size) {
    char *ret = malloc(sizeof(char));
    uint64_t i = 0;
    FILE *fptr = fopen(appendStr("temp/", filename), "r");
    fseek(fptr, SEEK_END, ~size + 1);
    int fsize = ftell(fptr);

    while(i++ < size)
        char[i] = fgetc(fptr);

    truncate(filename, fSize);
}