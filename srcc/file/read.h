#ifndef CREAD_H
#define CREAD_H

#include "../../srcp/types/struct.h"

file_t currFile;
loc_t currLoc;
int fileLen;

/*
 * Use this after adding/subbing from the file in order to get the correct file length
 */
void setFileLen();

/*
 *  Sets the current word to the next availabel word. This will mainly be used in 
 *  token.c so is built to handle operators
 */
void nextWord(const bool includeOperator);

#endif
