const char *keywordSynt[] = {"^ 'int'", //return
                             "^('bool') 'exprList'", //while 
                             "^('bool') 'exprList'", //if
                             "^('expr';'expr';'expr') 'exprList'" //for
                            };
const char *operatorSynt[] = {"^ 'macro'",
                              "^ 'asmLine'",
                              "^'expr')",
                              "",
                              "^'expr']",
                              "'structObj'^'var'",
                              "'macroList'^'macro'",
                              "'int'^",
                              "'int'^",
                              "'expr +COLAVAILIABLE'^'colExpr'"
                              "'int'^'int' | 'char`'^'char`'",
                              "'int'^'int' | 'char`'^'int'",
                              "^'bool",
                              "^'int'",
                              "^'var'",
                              "^'var'",
                              "^('ANY')",
                              "^('macro', 'int') | ^('macro')",
                              "'int'^'int' | 'char`'^'int'",
                              "'int'^'int'",
                              "'int'^'int'",
                              "'int'^'int'",
                              "'int'^'int'",
                              "'int'^'int'",
                              "'int'^'int'",//<=
                              "'int'^'int'",
                              "'int'^'int'",
                              "'expr -void'^'expr -void'",
                              "'expr -void'^'expr -void'",
                              "'int'^'int'",
                              "'int'^'int'",
                              "'int'^'int'",
                              "'bool'^'value':'value'",
                              "",
                              "'var'^'value'",
                              "'var'^'value'",
                              "'var'^'value'",
                              "'var'^'value'", //*=
                              "'var'^'int'",
                              "'var'^'int'",
                              "'var'^'int'",
                              "'var'^'int'",
                              "'var'^'int'",
                              "'var'^'int'",
                              "'var'^'int'",
                              "'value'^'value'"
                             }