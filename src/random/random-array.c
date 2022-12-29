#include <stdio.h>
#include <stdlib.h>

int main(void)
{
   int sz;
   printf("Enter the size of array::");
   scanf("%d",&sz);
   int randArray[sz],i;
   for(i=0;i<sz;i++)
     randArray[i]=rand()%100;   //Generate number between 0 to 99

   printf("\nElements of the array::");
   for(i=0;i<sz;i++)
   {
     printf("\nElement number %d::%d",i+1,randArray[i]);
   }
   return 0;
}

//reference: https://www.codespeedy.com/generate-a-random-array-in-c-or-cpp/
