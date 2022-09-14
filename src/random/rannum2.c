#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>

  

int main()  
{  

    time_t t;
    /* Intializes random number generator */
    srand((unsigned) time(&t));


    int i;    
    /* It returns the same sequence of random number  
    on every execution of the program. */  
    printf(" Random Numbers are: \n");   
    for (i = 0; i <SHRT_MAX; i++)  
    {  
        printf(" %d \n", rand()); 

		// Retrieve a random number between 100 and 200
		// Offset = 100
		// Range = 101
		//int data = 100 + (rand() % 101);        

     }   
     return 0;  
}  

//REFERENCE: https://www.javatpoint.com/random-function-in-c

