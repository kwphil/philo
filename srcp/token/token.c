#include <stddef.h>
#include <stdlib.h>
#include "../types/struct.h"
#include "../types/types.h"
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
  int i = 0;
  token_t ret;
  
  while(keywordList[i++][0] != NULL) {
    if(strcmp(keywordList[i], currWord)) {
      ret.type = 0;
      ret.value = currWord;
      ret.loc.word = currLoc.word;
      ret.loc.line = currLoc.line;
      return ret;
    }
  }

  
}

const char *keywordList[] = {"return"};
