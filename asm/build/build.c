#include <stdlib.h>
#include <string.h>
#include "../../srcc/file/file.h"
#include "../../srcc/string/string.h"
#include "../../srcp/types/struct.h"
#include "../../srcp/types/types.h"

void build(const asm_t *asmList, const char *argv) {
    if((int)argv[2] == 1 && argv[3] != NULL) system(appendStr("touch", argv[3]));
    else system("touch temp.s");
    system("\"section .text\nglobal _start\n_start: \" >> temp.s");
    int i = 0, loc = 0, sect = 0;

    while (1) {
        for (;asmList[i].ins[0] != '\0'; loc++) {
            if (asmList[i].section != sect || asmList[i].loc != loc)
                continue;

            system(appendf("\"%s \" >> temp.s", asmList[i].ins));
            i = 0;
        }

        if (sect <= 3) {
            loc = 0;
            system("\"section .\" >> temp.s");
            if (sect == 1) system("\"data \" >> temp.s");
            else system("\"bss \" >> temp.s");
            sect++;
        } else break;
    }

    // Execute the assembler with the correct path
    if((int)argv[2] == 0) {
        system("nasm temp.s -o build.bin && rm temp.s");
        exit(0);
    }
}
