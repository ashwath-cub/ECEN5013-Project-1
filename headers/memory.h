/*Declaring the functions that are defined in memory.c*/

#include<stdint.h>

#ifndef prototype
#define ptototype
uint8_t my_memmove(uint8_t *src, uint8_t *dst, uint32_t length);
uint8_t my_memzero(uint8_t *src, uint32_t length);
uint8_t my_reverse(uint8_t *src, uint32_t length);
#endif

