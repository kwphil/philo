#include <string.h>
#include <stdbool.h>
#include "flag.h"

void defaultFlag() {
    strcpy(PRGM_FOR, "OS");
    SEMI_WARN_FLAG = true;
    SEMI_ERR_FLAG = false;
}