#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "../../srcc/file/file.h"
#include "../../srcc/string/string.h"
#include "../../srcp/types/struct.h"
#include "../../srcp/types/types.h"

void build(const asm_t *asmList, const char *argv) {
    system("touch temp.s");
    system("\"section .text\nglobal _start\n_start: \" >> temp.s")
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

    system("touch temp.s");
    system(appendf(""))
    writeFile("temp.s", fileContents);

    // Execute the assembler with the correct path
    char *argList[] = {"nasm", "temp.s", "-o", "build.bin", NULL};
    execvp("nasm", argList);
    remove("temp.s");
}
