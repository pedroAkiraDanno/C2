
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
 * 01-07-2022, v2.0, Pedro Akira Danno Lima
 *
 * Compile: gcc -Wall -O2 quick_sort.c -o quick_sort
 */


//header files 
#include<stdio.h>
#include <stdbool.h>
#include<time.h>




/* Global Variables */
int qtd = 0;



/*Function Prototypes */
void swap(int *a, int *b);							               // swap function
int partition(int array[], int low, int high);         // partition fuction
void printArray(int array[], int size);  			         // print function
void quickSort(int array[], int low, int high);	       // quick_sort function
void printArrayPartition(int array[], int size);       // just to TEST -dont use more





// function to swap elements
void swap(int *a, int *b) {
  int t = *a;
  *a = *b;
  *b = t;
}





// function to find the partition position
int partition(int array[], int low, int high) {

  // select the rightmost element as pivot
  int pivot = array[high];

  // pointer for greater element
  int i = (low - 1);

  // traverse each element of the array
  // compare them with the pivot
  for (int j = low; j < high; j++) {
    if (array[j] <= pivot) {

      // if element smaller than pivot is found
      // swap it with the greater element pointed by i
      i++;

      // swap element at i with element at j
      swap(&array[i], &array[j]);
    }
  }

  // swap the pivot element with the greater element at i
  swap(&array[i + 1], &array[high]); // put the pivot in the correct position
  //because i is the end of less value then pivot, so the correct position to the pivot is i+1 - it logical

  //printArrayPartition(array, 10); // just to TEST
  // return the partition point
  return (i + 1); // i + i = pivot
}






void quickSort(int array[], int low, int high) {

    // printf(" low: %d high: %d ", low, high);
  if (low < high) {
    // find the pivot element such that
    // elements smaller than pivot are on left of pivot
    // elements greater than pivot are on right of pivot
    int pi = partition(array, low, high);

     //printf(" low: %d high: %d ", low, pi -1);
    // recursive call on the left of pivot
    // think like tree - Binary search tree - always resolve left part left part then then solved, move to the right = (pi+1)
    quickSort(array, low, pi - 1); // pi - 1 = i

    //printf(" low: %d high: %d ", pi + 1, high);
    // recursive call on the right of pivot
    quickSort(array, pi + 1, high);
  }
    qtd++;

}




// function to print array elements
void printArray(int array[], int size) {
  for (int i = 0; i < size; ++i) {
    printf("%d  ", array[i]);
  }
  printf("\n");
}






// just to TEST
// function to print array elements
void printArrayPartition(int array[], int size) {
  printf("print partiton:  ");
  for (int i = 0; i < size; ++i) {
    printf("%d ", array[i]);
  }
  printf("\n");
}










// main function
int main() {
  int data[] = {8, 7, 2, 1, 0, 9, 5, 10, 3, 6};

  int n = sizeof(data) / sizeof(data[0]);

  printf("Unsorted Array\n");
  printArray(data, n);

  // perform quicksort on data
  quickSort(data, 0, n - 1);

  printf("Sorted array in ascending order: \n");
  printArray(data, n);

      //printf("qtd quicksort functions: %d \n ", qtd); //just to test
  return 0;
}








/*
COMPILE:

apt-get intall gcc
vi quick_sort4.c
gcc quick_sort4.c -o quick_sort4.exe
./quick_sort4.exe



REFE:
https://hackr.io/blog/quick-sort-in-c


*/
