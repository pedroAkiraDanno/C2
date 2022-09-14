#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>


int main () {
   int i;
   
   
   /* Intializes random number generator */
   srand(time(NULL));



   /*    
      Get your random number into the range you want. The general formula for doing so is this:

      int random_number = rand() % range + min;
      Where range is how many (consecutive) numbers you want to choose from, and min is the smallest of these. So to generate a number between 1 and 100, range is 100 and min is 1:

      int random_number = rand() % 100 + 1; 
   */


   /* Print SHRT_MAX    random numbers from 1 to 100 */
   for( i = 0 ; i < SHRT_MAX ; i++ ) {
      printf("%d\n", rand() % 100 + 1);
   }
   
   return(0);
}




//REFERENCE: 