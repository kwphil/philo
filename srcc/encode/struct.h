#ifndef CESTRUCT_H
#define CESTRUCT_H

#include <stdint.h>
#include <stdlib.h>

//Encodes any struct into a uint8_t array, which can be used to pass into the tempPush() function
//To call it would be 
// uint8_t arr = structEncode(<object>, sizeof(<object>));
uint8_t *structEncode(const void *strct, register size_t size);