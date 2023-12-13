#ifndef CFTEMP_H
#define CFTEMP_H

#include <stdlib.h>

//Used to define temperary files, which will be used to help relieve usage on ram
//Note that this can be dangerous, do not use unless necessary, and you know what you are doing.

//Appends to a specified file
void tempWrite(char *filename, void *write, size_t size);