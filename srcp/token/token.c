#include "../types/struct.h"
#include "../types/types.h"
#include <stddef.h>
#include <stdlib.h>
#include "../../srcc/file/read.h"
#include "../../cmplr/error.h"

token_t *tokenize(char *fileOutput) {
  setFileLen();
  realloc(currFile.contents, sizeof(char) * fileLen);
  token_t ret[sizeof(currFile.contents)];

  int i = 0;
  while((int)fileOutput[i++] != NULL) {
    setCurrWord(i);

    ret[i] = tokenizeWord(currWord);

    if(bError) setErr();
  }

  return ret;
}

token_t tokenizeWord(char *currWord) {
  if(isNum(currWord)) 
}

const int listLen[] = {1}

const char *keywordList[] = {"return"};
