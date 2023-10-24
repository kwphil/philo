#ifndef PSYNTLIST_H
#define PSYNTLIST_H

struct syntStruct_t {
    bool    dirDefined;
    bool    required;
    char   *value;
    int8_t *exclude;
    int8_t *include;
};

#endif