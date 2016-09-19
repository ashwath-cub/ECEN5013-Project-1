/*Author: Sayan Barman and Ashwath Gundepally
Purpose: This file contains the definition of one function that is,project_1_report() to initialize it to zero and move contents of an array within it to achieve the desired output*/



#include <stdio.h>
#include "../headers/project.h"
#include "../headers/memory.h"
#include<stdint.h>


/*Function where we use pointers to move contents of an array and display it in reverse format*/
void project_1_report()
{
   uint8_t arr[32];

   uint8_t *aptr_1,*aptr_2,*aptr_3;

   uint8_t i=0;

   aptr_1=arr;
   aptr_2=aptr_1 + 8;
   aptr_3=aptr_2 + 8;
   
   /*Initializing the first 16 elements of the array with values 31-46*/
   while(i<=15)
   {
      *(aptr_1+i)=31+i;
       i++; 
   }
  
 

   my_memzero(aptr_3,16);//using my_memzero function declared under memory.h
  

   my_memmove(aptr_1, aptr_3, 8);//using my_memmove function declared under memory.h

   my_memmove(aptr_2, aptr_1, 16);//using my_memmove function declared under memory.h

   my_reverse(aptr_1,32);//using my_reverse function declared under memory.h
   


   printf("\nafter reverse\n");
  
   i=0;
   printf("\n\n");

   //displaying the entire array after completing all operations
   while(i<32)
   {
      printf("Element No.- %d Value=%d\n",i, *(aptr_1+i));
      i++;
   }
}

 
