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
    uint8_t *ret = malloc(size);
    uint64_t i = 0;
    FILE *fptr = fopen(appendStr("temp/", filename), "r");
    fseek(fptr, 0, SEEK_END - size);
    int fsize = ftell(fptr);

    while(i++ < size)
        ret[i] = (uint8_t)fgetc(fptr);

    truncate(filename, fSize);

    return ret;
}

void *tempRead(char *filename. size_t size) {
    uint8_t *ret = malloc(size);
    uint64_t i = 0;
    FILE *fptr = fopen(appendStr("temp/", filename), "r");
    fseek(fptr, 0, SEEK_END - size);

    while(i++ < size)
        ret[i] = (uint8_t)fgetc(fptr);

    return ret;
}