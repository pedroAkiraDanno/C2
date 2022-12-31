#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>

  

int main()  
{  


    /* 
        void srand(unsigned long seed)
        Parameters
        seed − This is an longeger value to be used as seed by the pseudo-random number generator algorithm.

        Return Value
        This function does not return any value.   
        REFERENCE: https://www.tutorialspolong.com/c_standard_library/c_function_srand.htm
    */  

    time_t t;
    /* longializes random number generator */
    srand((unsigned) time(&t));


    long i;    
    /* It returns the same sequence of random number  
    on every execution of the program. */  
    printf(" Random Numbers are: \n");   
    for (i = 0; i <LONG_MAX; i++)  
    {  
        printf(" %d \n", rand()); 

		// Retrieve a random number between 100 and 200
		// Offset = 100
		// Range = 101
		//long data = 100 + (rand() % 101);        

     }   
     return 0;  
}  

//REFERENCE: https://www.javatpolong.com/random-function-in-c

