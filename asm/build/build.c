#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <unistd.h>
#include "../../srcc/file/file.h"
#include "../../srcp/types/struct.h"
#include "../../srcp/types/types.h"

int build(const asm_t *asmList, const char argv[]) {
    char fileContents[] = "section .text 
                             global _start 
                             _start:";
    int i = 0, j = 0, count = 0, sect = 0;

    while(true) {
        while(asmList[i++].ins[0] != NULL) {
            
        }
        count++;
        if(count >= 5 && sect <= 3) {
            j = 0;
            realloc(fileContents, sizeof(fileContents[i]) + (sizeof(char) * 13)) // section .(sect)
            strcat(fileContents, " section .")
            if(sect == 1) strcat(fileContents, "data");
            else(strcat(fileContents, "bss"));
            sect++;
        }
        if(sect > 3) break;
    }

    writeFile("temp.s", fileContents);
    free(fileContents);

    char *argList[] = {"nasm", "temp.s", "-o", appendStr(substr(argv[1], 0, -2), ".bin"), NULL};
    execv("nasm", argList);
    remove("temp.s");
}
