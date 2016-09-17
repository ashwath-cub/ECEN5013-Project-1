#include<stdio.h>
#include<stdint.h>
#include<stdlib.h>
#include"memory.h"

void readLine(char *str1);   


int main()
{

   uint8_t *dst=NULL, *src=NULL;                                         //initialising pointers passed to be passed to memmove

   src= (char*)(malloc(50*sizeof(char)));

   printf("\n\n\t\tEnter source data:");                                

   readLine(src);                                                      

   uint8_t length=0;                                                     

   while(*(src+length)!='\0')                                           
   {
      length++;
   }

   printf("\n\n\t\t%d is the length of the data", length);               

   dst=src+length+1;
                                                                         
                                                                          
   my_memmove(src, dst, length);                                   
   printf("\n\n\t\tafter move, dst is %s", dst);
  
   my_memzero(src, length);
   printf("\n\n\t\tafter memzero, source %s", src);

   my_reverse(dst, length);
   printf("\n\n\t\tafter reverse, dst %s", dst);                  
   
                         //print data at 
  
   return 0;
}


void readLine(char *str1)                                                 //function to accept user input. this is just for now.
{
   char character;
   int i=0;
   do
   {
      character = getchar();
      *(str1+i)=character;
      ++i;
   }
   while (character!='\n');
   *(str1+i-1)='\0';
}

