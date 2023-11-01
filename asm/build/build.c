#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "../../srcc/file/file.h"
#include "../../srcc/string/string.h"
#include "../../srcp/types/struct.h"
#include "../../srcp/types/types.h"

void build(const asm_t *asmList, const char *argv) {
    char fileContents[10000] = "section .text\nglobal _start\n_start: ";
    int i = 0, loc = 0, sect = 0;

    while (1) {
        while (asmList[i].ins[0] != '\0') {
            if (asmList[i].section != sect || asmList[i].loc != loc)
                continue;

            strcat(fileContents, asmList[i].ins);
            strcat(fileContents, " ");
            i = 0;
            loc++;
        }

        if (sect <= 3) {
            loc = 0;
            strcat(fileContents, "section .");
            if (sect == 1) strcat(fileContents, "data ");
            else strcat(fileContents, "bss ");
            sect++;
        } else break;
    }

    writeFile("temp.s", fileContents);

    // Execute the assembler with the correct path
    char *argList[] = {"nasm", "temp.s", "-o", "build.bin", NULL};
    execvp("nasm", argList);
    remove("temp.s");
}
