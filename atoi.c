#include<stdio.h>
#include<stdint.h>

int32_t my_atoi(int8_t*str)
{
   int index, result=0;                                                   //index to track the string
   for(index=0;*(str+index)>='0' && *(str+index)<='9';++index)            //loop to form the number 
      result=result*10 +(*(str+index)-'0');
   printf("\n\n%d", result);                                              
   return result;
}

