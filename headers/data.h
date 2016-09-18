/*Declaring all functions which are defined in data.c*/

<<<<<<< HEAD:data.h
#include<stdio.h>

=======
//#include<stdint.h>
>>>>>>> 8a31da34d04b0ebee840aa544d5990f8dda4ca72:headers/data.h

int8_t * my_itoa(int8_t *str,int32_t data,int32_t base);
int32_t my_atoi(int8_t *str);
void dump_memory(uint8_t *start,uint32_t length);
uint32_t big_to_little(uint32_t data);
uint32_t little_to_big(uint32_t data);

