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

int8_t* my_itoa(int8_t* str, int32_t data, int32_t base)
{
   int16_t index, i;
   int32_t datacpy=data;
   if (base<0)
   {
      printf("The base value is negative which doesn't make sense. Re-enter the base value.");
      return 1;
   }

   for(index=0; data!=0; index++)
   {
      *(str+index)=data%base;
       data=data/base;
       printf("%d\t", *(str+index));
   }
   printf("%d\n", index);

   my_reverse(str, index);
   if (datacpy<0)
   {
      for(i=0; i<index-1; i++)
      {
         *(str+index-i)=*(str+index-i-1);     //shifting by one byte so as to make room for the negative sign.
      }
      *(str)=-;
   }

   for(i=0; i<index; i++)
   {
      printf("%d\t",*(str+i));
   }
   return NULL;
}

