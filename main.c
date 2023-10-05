#include <stdio.h>
#include "srcp/token/token.h"
#include "srcc/file/file.h"
#include "srcp/types/struct.h"

int main(int argc, char *argv[]) {

    if(argc != 2) {
        bError = true;
        sError = "Incorrect Usage! Correct usage is ./philo <file>";
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
}
