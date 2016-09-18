#include<stdio.h>
#include "data.h"

int32_t my_atoi(int8_t*str)
{
   int index, result=0;                                                   //index to track the string
   for(index=0;*(str+index)>='0' && *(str+index)<='9';++index)            //loop to form the number 
      result=result*10 +(*(str+index)-'0');
   printf("\n\n%d", result);
   return result;
}





void dump_memory(uint8_t *start,uint32_t length)
{
   uint8_t i;
   
   for(i=0; i<length;i++)
   {
      printf("%x",start);
      start++;
   }
}

uint32_t big_to_little(uint32_t data)
{
   uint32_t result;
   
   result=(((data>>24) | ((data>>8) & 0x0000ff00) | ((data<<8) & 0x00ff0000) | ((data<<24) & 0xff000000));

   
   return result;

}

uint32_t little_to_big(uint32_t	data)
{
   uint32_t result;
   
   result=((data & 0x000000FF) << 24) | ((data & 0x0000FF00)<<8) | ((data >> 8) & 0x0000FF00) | (data >> 24);
  
   return result;

}

