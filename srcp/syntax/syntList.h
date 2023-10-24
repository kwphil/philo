#ifndef PSYNTLIST_H
#define PSYNTLIST_H

//Is not really needed in most of the program except for in syntax.c, it is used
//If you are wanting to add some new syntax, you can access it in syntList.c
void insertSyntList(struct syntStruct_t *syntaxList, int syntLoc);

struct syntStruct_t {
    bool    dirDefined;
    bool    required;
    char   *value;
    int8_t *exclude;
    int8_t *include;
};

#endif