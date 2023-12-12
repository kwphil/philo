#ifndef CFTEMP_H
#define CFTEMP_H

//Used to define temperary files, which will be used to help relieve usage on ram
//Note that this can be dangerous, do not use unless necessary, and you know what you are doing.

//Writes a temperary file
//If programs need to take up more data than 0xFFFFFFFF chars at a time (for some reason), we can just change the size value to uint64_t
void tempWrite(char *filename, void *write, uint32_t size);