#ifndef CREAD_H
#define CREAD_H

#include "../../srcp/types/struct.h"
#include <stdbool.h>

extern file_t currFile;
extern loc_t currLoc;
extern int fileLen;

/*
 * Use this after adding/subbing from the file in order to get the correct file length
 */
void setFileLen();

/*
 * Sets the current word to the next available word. This will mainly be used in 
 * token.c so is built to handle operators
 */
void nextWord(const bool includeOperator);

#endif
