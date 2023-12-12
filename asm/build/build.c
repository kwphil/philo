#include <stdlib.h>
#include <string.h>
#include "../../srcc/file/file.h"
#include "../../srcc/string/string.h"
#include "../../srcp/types/struct.h"
#include "../../srcp/types/types.h"

void build(const asm_t *asmList, const char *argv) {
    if((int)argv[2] != 1 || argv[3] == NULL) {
        argv[3] = (char *)malloc((size_t)6);
        strcpy(argv[3], "asm.s");
    } else system(appendStr("touch ", argv[3]));
    system(appendStr("\"section .text\nglobal _start\n_start: \" >> ", argv[3]));
    int i = 0, loc = 0, sect = 0;

    while (1) {
        while (asmList[i].ins[0] != '\0') {
            if (asmList[i].section != sect || asmList[i].loc != loc)
                continue;

            system(appendf("\"%s \" >> %s", argv[3], asmList[i].ins));
            i = 0;
            loc++;
        }

        if (sect <= 3) {
            loc = 0;
            system(appendStr("\"section .\" >> ", argv[3]));
            if (sect == 1) system(appendStr("\"data \" >> ", argv[3]));
            else system(appendStr("\"bss \" >> ", argv[3]));
            sect++;
        } else break;
    }

    // Execute the assembler with the correct path
    if((int)argv[2] == 0) {
        system(appendf("nasm %s -o build.bin && rm %s", argv[3], argv[3]));
        exit(0);
    }

    exit(0);
}
