#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main () {
   int i, n;
   time_t t;
   
   n = 5;
   
   /* Intializes random number generator */
   srand((unsigned) time(&t));

   /* Print 5 random numbers from 0 to 49 */
   for( i = 0 ; i < SHRT_MAX ; i++ ) {
      printf("%d\n", rand() % 50);
   }
   
   return(0);
}

//REFERENCE: 