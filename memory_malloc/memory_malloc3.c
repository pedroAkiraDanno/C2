
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
#include <unistd.h> //to sleep function



 
int main()
{
 
    // This pointer will hold the
    // base address of the block created
    int* ptr;
    int n, i;
 
    // Get the number of elements for the array
    n = 500000000;
    printf("Enter number of elements: %d\n", n);
 
    // Dynamically allocate memory using calloc()
    ptr = (int*)calloc(n, sizeof(int));
 
 	printf("Size : %ld bytes\n", n*sizeof(int));
	printf("Size : %ld GB\n", n*sizeof(int)/1024/1024/1024);
 
 
 
    // Check if the memory has been successfully
    // allocated by malloc or not
    if (ptr == NULL) {
        printf("Memory not allocated.\n");
        exit(0);
    }
    else {
 
        // Memory has been successfully allocated
        printf("Memory successfully allocated using calloc.\n");
 
        // Get the elements of the array
        for (i = 0; i < n; ++i) {
            ptr[i] = i + 1;
        }
 
        // Print the elements of the array
        //printf("The elements of the array are: ");
        //for (i = 0; i < n; ++i) {
        //    printf("%d, ", ptr[i]);
        //}
 
        // Get the new size for the array
        n = 900000000;
        printf("\n\nEnter the new size of the array: %d\n", n);
 
        // Dynamically re-allocate memory using realloc()
        ptr = realloc(ptr, n * sizeof(int));
		
		
		printf("Size : %ld bytes\n", n*sizeof(int));
		printf("Size : %ld GB\n", n*sizeof(int)/1024/1024/1024);		
 
        // Memory has been successfully allocated
        printf("Memory successfully re-allocated using realloc.\n");
 
        // Get the new elements of the array
        for (i = 500000000; i < n; ++i) {
            ptr[i] = i + 1;
        }
 
		sleep(3);

        // Print the elements of the array
        //printf("The elements of the array are: ");
        //for (i = 0; i < n; ++i) {
        //    printf("%d, ", ptr[i]);
        //}
 
        free(ptr);
    }
 
    return 0;
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
		gcc memory_malloc.c -o memory_malloc.exe
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



