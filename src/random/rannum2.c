#include <stdio.h>  
#include <stdlib.h>  
  
int main()  
{  
    int i;    
    /* It returns the same sequence of random number  
    on every execution of the program. */  
    printf(" Random Numbers are: \n");   
    for (i = 0; i <5; i++)  
    {  
        printf(" %d", rand()); 

		// Retrieve a random number between 100 and 200
		// Offset = 100
		// Range = 101
		//int data = 100 + (rand() % 101);        

     }   
     return 0;  
}  

//REFERENCE: https://www.javatpoint.com/random-function-in-c

