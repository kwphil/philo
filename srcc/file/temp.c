#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <string.h>
#include "string.h"

uint8_t *tempPush(char *filename, uint8_t *write, size_t size) {
    FILE *fptr = fopen(appendStr("temp/", filename), "w");
    if(fptr == NULL) {
        printf("Compiler Error! Temp file %s not found", filename);
        exit(14);
    }

    fwrite(write, size, 1, fptr); //make sure we add a null-pointer to convert it to a string
    fclose(fptr);
}

uint8_t *tempPop(char *filename, size_t size) {
    uint8_t *ret = malloc(size);
    uint64_t i = 0;
    FILE *fptr = fopen(appendStr("temp/", filename), "r");

    if(fptr == NULL) {
        printf("Compiler Error! Temp file %s not found", filename);
        exit(14);
    }

    fseek(fptr, SEEK_END, ~size + 1);
    int fSize = ftell(fptr);

    while(i++ < size)
        ret[i] = (uint8_t)fgetc(fptr);

    truncate(filename, fSize);
    fclose(fptr);

    return ret;
}

uint8_t *tempRead(char *filename, size_t size) {
    uint8_t *ret = malloc(size);
    uint64_t i = 0;
    FILE *fptr = fopen(appendStr("temp/", filename), "r");

    if(fptr == NULL) {
        printf("Compiler Error! Temp file %s not found", filename);
        exit(14);
    }

    fseek(fptr, SEEK_END, ~size + 1);

    while(i++ < size)
        ret[i] = (uint8_t)fgetc(fptr);

    fclose(fptr);
    return ret;
}