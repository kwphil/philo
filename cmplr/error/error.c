#include "error.h"
#include "../../srcc/file/read.h"

bool bError;

void setErr() {
    if(!bError) return;
    printf("Error at %d:%d! %s", currLoc.line, currLoc.word, sError);
}
