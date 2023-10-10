//Anything to do with reading/writing files will go in here
#ifndef CFILE_H
#define CFILE_H

#include "../../srcp/types/type.h"

//This will output the entire contents of a file, and will set the currFile for you
string_t readFile(const string_t filename);

//This will input a string into a file, and will overwrite any contents
void writeFile(const string_t filename, const string_t data);

#endif
