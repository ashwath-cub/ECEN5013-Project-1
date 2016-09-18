#include<stdio.h>
#include<stdint.h>
#include<stdlib.h>
#include"memory.h"

int8_t* my_itoa(int8_t* str, int32_t data, int32_t base);
//char reverse(int8_t* str,uint16_t length);

int main()
{
   int32_t data=1234, base=10;
   
   int8_t* str;
   str=malloc(30);
   
   my_itoa(str, data, base);
   free(str);
}

int8_t* my_itoa(int8_t* str, int32_t data, int32_t base)
{
   int16_t index, i;

   for(index=0; data!=0; index++)
   {
      *(str+index)=data%base;
       data=data/base;
       printf("%d\t", *(str+index));
   }
   printf("%d\n", index); 
  
   my_reverse(str, index);
   
   for(i=0; i<index; i++)
   {
      printf("%d\t",*(str+i));
   }  
   return NULL;
}

//char reverse(int8_t* str, uint16_t length)
//{
  //     if(length<0) //Failure. negative length makes no sense. Non-zero value is returned. Also tests for (length>2147483648)
    //      return '1';

      // int index; //index to run the For loop below.
      // char temp; //temp char variable to facilitate exchange
        
      // for(index=0;index<length/2;index++) //method to reverse the string; exchange elements about the mid-point
      // {
       //   temp=*(str+index);
       //   *(str+index)=*(str+length-(index+1));
     //     *(str+length-(index+1))=temp;
     //     printf("\n\t%d", *(str+index));
     //     printf("\nindex=%d", index);
     //  }
      // return '0';
//}


