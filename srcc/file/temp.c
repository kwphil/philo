#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

void tempWrite(char *filename, void *write, uint32_t size) {
    register uint32_t i = 0;
    uint8_t inc = 255;

    FILE *fptr = fopen(filename "w");
    if(fptr == NULL) {
        printf("Compiler Error! Temp file %s not found", filename);
        exit(14);
    }

    while(i <= size)
        if(i + inc > size) inc >> 1; //Diving by 2
        fprintf(filename, appendStr((char [inc]write[i += inc]), '\n')); //make sure we add a null-pointer to convert it to a string

    fclose(fptr);
}