#include <stdio.h>
#include <stdlib.h>
#include <string.h>


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




		REFE:
		https://github.com/wk1219/Quick_sort/blob/master/quick_sort.c


*/
