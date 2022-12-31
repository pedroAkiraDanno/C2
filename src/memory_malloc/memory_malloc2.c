
/*
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 *
 * 02-07-2022, v1.0, Pedro Akira Danno Lima
 *
 * Compile: gcc -Wall -O2 memory_malloc.c -o memory_malloc
 */





//header files 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h> //to sleep function


int main () {
   char *str;

   /* Initial memory allocation */
   str = (char *) malloc(15);
   strcpy(str, "tutorialspoint");
   printf("String = %s,  Address = %u\n", str, str);

   /* Reallocating memory */
   str = (char *) realloc(str, 25);
   strcat(str, ".com");
   printf("String = %s,  Address = %u\n", str, str);


	 sleep(8);

   free(str);
   
   return(0);
}








/*
	COMPILE:

		ulimit -a
		ulimit -s 3000000

		apt-get install gcc -y
		sudo apt install build-essential -y
		gcc --version

		cd 	~
		mkdir c ; cd c
		vi memory_malloc.c
		#echo "" > memory_malloc.c
		gcc memory_malloc.c -o memory_malloc.exe -w
		./memory_malloc.exe

		#when finish
		cd 	~ ; cd c
		rm memory_malloc.c memory_malloc.exe
		#rm *



*/




  /*****************************************************************************************************************
  *                                                   REFERENCIAS                                                  
  * https://github.com/wk1219/Quick_sort/blob/master/quick_sort.c     
  ******************************************************************************************************************/



