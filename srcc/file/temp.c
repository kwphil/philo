#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

void tempWrite(char *filename, void *write, uint32_t size) {
    register uint32_t i = 0;

    FILE *fptr = fopen(filename "w");
    if(fptr == NULL) {
        printf("Compiler Error! Temp file %s not found", filename);
        exit(14);
    }

    while(i < size)
        fprintf(filename, (uint8_t)write[i++ * 4]);
}