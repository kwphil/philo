const char *keywordSynt[] = {"^ 'int'", //return
                             "^('bool') 'exprList'", //while 
                             "^('bool') 'exprList'", //if
                             "^('expr1';'expr2';'expr3') 'exprList'" //for
                            };