#include "../../srcp/types/struct.h"

token_t defaultToken() {
    token_t ret;

    ret.type = -1;
    ret.value = "";
    ret.loc.word = -1;
    ret.loc.line = -1;
}

token_t setToken(int type, char *value, loc_t loc) {
    token_t ret;
    
    ret.type = type;
    ret.value = value;
    ret.loc = loc;
}