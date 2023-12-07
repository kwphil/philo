//Anything to do with reading/writing files will go in here
#ifndef CFILE_H
#define CFILE_H

//This will output the entire contents of a file, and will set the currFile for you
char * readFile(const char * filename);

//This will input a string into a file, and will overwrite any contents
void writeFile(const char * filename, const char * data);

#endif
