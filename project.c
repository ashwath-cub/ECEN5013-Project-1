#include <stdio.h>
#include "project.h"
#include "memory.h"
#include<stdint.h>

void project_1_report()
{
   uint8_t arr[32];

   uint8_t *aptr_1,*aptr_2,*aptr_3;

   uint8_t i=0;

   aptr_1=arr;
   aptr_2=aptr_1 + 8;
   aptr_3=aptr_2 + 8;
   
   while(i<=15)
   {
      *(aptr_1+i)=31+i;
       i++; 
   }
   i=0;
 

   my_memzero(aptr_3,16);
  

   my_memmove(aptr_1, aptr_3, 8);

   my_memmove(aptr_2, aptr_1, 16);
    
   my_reverse(aptr_1,32);
   


   printf("\nafter reverse\n");
  
   i=0;
   printf("\n\n");
   while(i<32)
   {
      printf(" %d.  %d\n",i, *(aptr_1+i));
      i++;
   }
}

 
