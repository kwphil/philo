#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../srcc/file/file.h"
#include "../../srcc/string/string.h"
#include "../../srcp/types/struct.h"
#include "../../srcp/types/types.h"

void build(const asm_t *asmList, const char *argv) {
    FILE *fptr = fopen("asm.s", "a");

    fprintf(fptr, appendStr("section .text\nglobal _start\n_start: \n")); //start the program here
    int i = 0, loc = 0, sect = 0;

    while (1) {
        while (asmList[i].ins[0] != '\0') {
            if(asmList[i].section == sect && asmList[i].loc == loc) {
                fprintf(fptr, asmList[i].ins);
                i = 0;
                ++loc;

                continue;
            }
        }

        if (sect <= 3) {
            loc = 0;
            fprintf(fptr, "section .");
            if (sect == 1) {
                fprintf(fptr, "data ");
                continue;
            }
            
            fprintf(fptr, "bss ");
            sect++;
        } else break;
    }

    fclose(fptr);

    // Execute the assembler with the correct path
    system(appendf("nasm asm.s -o %s && rm asm.s", (argv[3] == NULL || argv[2] == 0) ? "test.bin" : argv[3]));
    if(argv[2] == 0) system("./test.bin && rm test.bin");

    exit(0);
}
