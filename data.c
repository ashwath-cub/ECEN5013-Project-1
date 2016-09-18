
/*Author:Sayan Barman and Ashwath Gundepally
Purpose:This file contains 5 functions-atoi,itoa,dump_memory,big_to little and little_to_big endian conversions*/


/*Inclusion of header files*/
#include<stdio.h>
#include "data.h"

/*Function to convert ASCII to Integer */
int32_t my_atoi(int8_t*str)
{
   int index, result=0;                                                   //index to track the string
   for(index=0;*(str+index)>='0' && *(str+index)<='9';++index)            //loop to form the number 
      result=result*10 +(*(str+index)-'0');
   printf("\n\n%d", result);
   return result;
}


/*Function to print the content of the pointer in hex format which points to a memory location and then printing the subsequent addresses till a certain length specified*/
void dump_memory(uint8_t *start,uint32_t length)
{
   uint8_t i;
   
   for(i=0; i<length;i++)
   {
      printf("%p",start);                                                //printing the addresses
      start++;                                             
   }
}


/*Function to convert a BigEndian formatted data to littleEndian formatted data*/
uint32_t big_to_little(uint32_t data)
{
   uint32_t result;
   
   /*1st,4th and 2nd,3rd bytes exchanging positions*/
   result=(((data>>24) | ((data>>8) & 0x0000ff00) | ((data<<8) & 0x00ff0000) | ((data<<24) & 0xff000000));

   
   return result;

}


/*Function to convert a littleEndian formatted data to BigEndian formatted number*/
uint32_t little_to_big(uint32_t	data)
{
   uint32_t result;
  
   /*1st,4th and 2nd,3rd bytes exchanging positions*/ 
   result=((data & 0x000000FF) << 24) | ((data & 0x0000FF00)<<8) | ((data >> 8) & 0x0000FF00) | (data >> 24);
  
   return result;

}


/*Function to convert a given integer(it's type specified by the base) to an ASCII string*/ 
int8_t* my_itoa(int8_t* str, int32_t data, int32_t base)
{
   int16_t index, i;
   int32_t datacpy=data;
   if (base<0)
   {
      printf("The base value is negative which doesn't make sense. Re-enter the base value.");
      return NULL;
   }

   for(index=0; data!=0; index++)
   {
      *(str+index)=data%base;
       data=data/base;
       printf("%d\t", *(str+index));
   }
   printf("%d\n", index);

   my_reverse(str, index);//reversing the string 

/*The data is checked whether it's negative and if it is so,a negative sign is added in the beginning of the string by pushing the entire string by an element */
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
   return str;
}

