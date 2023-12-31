#ifndef CFTEMP_H
#define CFTEMP_H

#include <stdlib.h>

//Used to define temperary files, which will be used to help relieve usage on ram
//Note that this can be dangerous, do not use unless necessary, and you know what you are doing.

//Appends to a specified file
void tempPush(char *filename, void *write, size_t size);

//Reads a specific amount from a file, and then removes that data from the file
void *tempPop(char *filename, size_t size);

//Reads a specific amount from a file
void *tempRead(char *filename, size_t size);