#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "srcp/token/token.h"
#include "srcc/file/file.h"
#include "srcp/types/struct.h"
#include "cmplr/error/error..h"
#include "asm/convert.h"

int main(int argc, char *argv[]) {

    if(argc != 2) {
        bError = true;
        char _sError = "Incorrect Usage! Correct usage is ./philo <file>";
        realloc(sError, sizeof(_sError));
        strcpy(sError, _sError);
        setErr();
        return 1;
    }
    return run(argv);
}

int run(char *argv[]) {
    string_t mainFileOutput = readFile(argv[1]);
    token_t *tokenList      = tokenize(mainFileOutput);
    asm_t    asmList        = convertAsm(tokenList);

    if(bError) return errorRet();

    build(asmList);

    printf("%s was compiled successfully! You can run it at build.bin!", argv[1]);
}
