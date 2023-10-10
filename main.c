#include <stdio.h>
#include "srcp/token/token.h"
#include "srcc/file/file.h"
#include "srcp/types/struct.h"
#include "cmplr/error/error..h"
#include "asm/convert.h"

int main(int argc, char *argv[]) {

    if(argc != 2) {
        bError = true;
        sError = "Incorrect Usage! Correct usage is ./philo <file>";
        setErr();
        return 1;
    }
    return run(argv[1]);
}

int run(char *filename) {
    string_t mainFileOutput = readFile(filename);
    token_t *tokenList      = tokenize(mainFileOutput);
    asm_t    asmList        = convertAsm(tokenList);

    if(bError) return errorRet();

    createBinFile(asmList);
}
