#ifndef CREAD_H
#define CREAD_H

#include "../../srcp/types/struct.h"

file_t currFile;
loc_t currLoc;
int fileLen;

/*
 * Use this after adding/subbing from the file in order to get the correct file length
 */
setFileLen();

#endif