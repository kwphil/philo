#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "../../srcc/file/file.h"
#include "../../srcc/string/string.h"
#include "../../srcp/types/struct.h"
#include "../../srcp/types/types.h"

void build(const asm_t *asmList, const char argv[]) {
    char fileContents[] = "section .text 
                             global _start 
                             _start: ";
    int i = 0, loc = 0, sect = 0;

    while(1) {
        while(asmList[i++].ins[0] != NULL) {
            if(asmList[i].section != sect || asmList[i].loc != loc) 
                continue;

            realloc(fileContents, sizeof(fileContents) + strlen(asmList[i].ins) + sizeof(char)); //The original file length, the new instruction, and a space to separate

            strcat(fileContents, appendStr(asmList[i].ins, " "));
            free(currIns);
            i = 0;
            loc++;
        }

        if(sect <= 3) {
            loc = 0;
            realloc(fileContents, sizeof(fileContents) + (sizeof(char) * 13)) // section .(sect)
            strcat(fileContents, "section .")
            if(sect == 1) strcat(fileContents, "data ");
            else(strcat(fileContents, "bss "));
            sect++;
        } else break;
    }

    writeFile("temp.s", fileContents);
    
    free(fileContents);

    char *argList[] = {"nasm", "temp.s", "-o", "build.bin", NULL};
    execv("nasm", argList);
    remove("temp.s");
}