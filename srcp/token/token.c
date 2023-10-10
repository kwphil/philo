#include <stddef.h>
#include <stdlib.h>
#include "../types/struct.h"
#include "../types/types.h"
#include "../../srcc/file/read.h"
#include "../../srcc/string/string.h"
#include "../../cmplr/error.h"

token_t *tokenize(const char *fileOutput) {
  token_t ret[sizeof(currFile.contents)];

  int i = 0;
  while((int)fileOutput[i++] != NULL) {
    setCurrWord(i);

    ret[i] = tokenizeWord(currWord);
  }

  return ret;
}

token_t tokenizeWord(const char *currWord) {
  int i = 0, type = 0;
  token_t ret;
  
  while(keywordList[i++][0] != NULL)
    if(strcmp(keywordList[i], currWord))
      goto ASSIGN_VALUE;
  type++;

  if(isNum(currWord))
    goto ASSIGN_VALUE;
  type++;

  i = 0;
  while(operatorList[i++][0] != NULL)
    if(strcmp(operatorList[i], currWord))
        goto ASSIGN_VALUE
  type++;

  //Did not match anything, so we are we will say it is a name for now. We can return an error later if need be
  goto ASSIGN_VALUE
  
  ASSIGN_VALUE:
  ret.type = i;
  strcpy(ret.value, currWord);
  ret.loc.line = currLoc.line;
  ret.loc.word = currLoc.word;
  return ret;
}

const char *keywordList[] = {"return"};
const char *operatorList[] = {"#", "\v", //--------------------------------------------------------------Macro Operator
                              "\\", "\v", //-------------------------------------------------------------ASM Operator
                              "(", ")", "[", "]", ".", "->", "++", "--", "\v", //------------------------Postfix
                              "+", "-", "!", "~", "`", "@", "\v", //-------------------------------------Unary
                              "*", "/", "%", "\v", //----------------------------------------------------Multiplicative
                              "<<", ">>", "\v", //-------------------------------------------------------Shift
                              "<", "<=", ">", ">=", "\v", //---------------------------------------------Relational
                              "==", "!=", "\v", //-------------------------------------------------------Equality  
                              "&", "^", "|", "\v", //----------------------------------------------------Bitwise
                              "&&", "\v", //-------------------------------------------------------------Logical AND
                              "||", "\v", //-------------------------------------------------------------Logical OR
                              "^^", "\v", //-------------------------------------------------------------Logical XOR
                              "?", ":", "\v", //---------------------------------------------------------Ternary
                              "=", "+=", "-=", "*=", "/=", "%=", ">>=", "<<=", "&=", "|=", "^=", "\v", //Assignment
                              ",", "\v" //---------------------------------------------------------------Comma Operator
                             }; //The vertical tab is used to indicate the order in which the operators are used
