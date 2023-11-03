#include <stddef.h>
#include <stdlib.h>
#include "../types/struct.h"
#include "../types/types.h"
#include "../types/list.h"
#include "../../srcc/file/read.h"
#include "../../srcc/string/string.h"
#include "../../cmplr/error/error.h"

#define MAX_TOKENS 65536 // Define the maximum number of tokens, adjust as needed

token_t *tokenize(const char *fileOutput) {
    int tokenCount = 0;
    token_t *ret = (token_t *)malloc(sizeof(token_t) * MAX_TOKENS);

    if (ret == NULL) {
        // Handle memory allocation error
        return NULL;
    }

    int i = 0;
    while (fileOutput[i] != '\0') {
        nextWord(true);
        token_t token = tokenizeWord(currWord);

        if (tokenCount < MAX_TOKENS) {
            ret[tokenCount] = token;
            tokenCount++;
        } else {
            // Handle too many tokens error
            bError = true;
            const char _sError = appendf("Compiler Error! Token count of %d too high!", MAX_TOKENS);
            realloc(sError, sizeof(_sError));
            strcpy(sError, _sError);

            break;
        }
    }

    return ret;
}

token_t tokenizeWord(const char *currWord) {
    int type = 0;
    token_t ret;
    ret.type = TOKEN_UNKNOWN; // Set to a default value for an unknown token type

    for (int i = 0; keywordList[i] != NULL; i++) {
        if (strcmp(keywordList[i], currWord) == 0) {
            ret.type = TOKEN_KEYWORD;
            break;
        }
    }

    if (ret.type == TOKEN_UNKNOWN && isNum(currWord)) {
        ret.type = TOKEN_NUMBER;
    }

    for (int i = 0; operatorList[i] != NULL; i++) {
        if (strcmp(operatorList[i], currWord) == 0) {
            ret.type = TOKEN_OPERATOR;
            break;
        }
    }

    //tokenType

    strcpy(ret.value, currWord);
    ret.loc.line = currLoc.line;
    ret.loc.word = currLoc.word;

    return ret;
}
