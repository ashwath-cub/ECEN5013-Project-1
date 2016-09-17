#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>

int8_t my_memmove(uint8_t *src, uint8_t *dst, uint32_t length);

void readLine(char *str);

//the main function has all the test apparatus to check memmove's basic  functionality. Will get rid of this soon.
int main()
{
  
   uint8_t *dst=NULL, *src=NULL;                                         //initialising pointers passed to be passed to memmove
   
   src= (char*)(malloc(50*sizeof(char))); 
   
   printf("\n\n\t\tEnter source data:");                             //adding user data to source address          
   
   readLine(src);                                                        //function to read spaces
   
   uint8_t length=0;                                                     //tracks length of source data
   
   while(*(src+length)!='\0')                                            //length loop
   {
    length++;
   }
   
   printf("\n\n\t\t%d is the length of the data", length);               //prints length of user input
   
   dst=src-2;                                                            //using test cases that guarantee overlaps.
   //dst=src+2;
   my_memmove(src, dst, length);                                         //call memmove
   
   printf("\n\n\t\tSource has:%s", src);                                 //print data at source. Not sure what is required to happen to source data after a move 
								         //with an overlap 
   
   printf("\n\n\t\tDestination has: %s\n\n", dst);                               //print data at destination 
   
   return 0;                                                             
}

int8_t my_memmove(uint8_t *src, uint8_t *dst, uint32_t length)
{
   
   uint32_t index;                                                       //32 bit unsigned index to track 32 bit max data length                                                                   
   if(length>abs(dst-src))
       printf("\n\n\t\tThere's an overlap. Source data will be corrupted.");
       
//the following lines are written assuming there's an overlap. Works just fine if there isn't one.                                                     

   if(dst-src>0)                                                                                                          
   {   
       for(index=1; index<=length; index++)                              //this will cover overlap cases like dst=src+k |k<length 
       {                                                                 //start from the top
          *(dst+length-index)=*(src+length-index);                  
       }
       *(dst+index)='\0';
   }
   else if(dst-src<0)                      
   {   for(index=0; index<length; index++)                               //this will cover overlap cases like src=dst+k |k<length
       {                                               			 //start from the bottom
         *(dst+index)=*(src+index);       
       }
       *(dst+index)='\0';
   }
   else
       dst=src;
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
