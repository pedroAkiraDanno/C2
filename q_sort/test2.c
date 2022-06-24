// QUICK SORT - Divide & Conquer

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

int qtd= 0;

#define MAX_SIZE 100000000


void swap(int *a, int *b);                                                                     // swap function
int partition(int array[], int low, int high);         // partition fuction
void printArray(int array[], int size);                                  // print function
void quickSort(int array[], int low, int high);        // quick_sort function





// main function
int main() {
        clock_t start, end;
        float total_time;

        int data[MAX_SIZE];

        // put random numbers in array to sort
        int i;
        for (i = 0; i < MAX_SIZE; i++) {
            data[i] = rand() % 100 + 1;
        }


        int n = sizeof(data) / sizeof(data[0]);

        //printf("Unsorted Array\n");
        //printArray(data, n);
        
        start = clock();

        // perform quicksort on data
        quickSort(data, 0, n - 1);

        end = clock();
        total_time = (float)(end - start) / CLOCKS_PER_SEC;

        //printf("Sorted array in ascending order: \n");
        //printArray(data, n);

        printf("Execute_time : %.6f\n", total_time);
        printf("qtd: %d \n", qtd);

        return 0;
}






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
  swap(&array[i + 1], &array[high]);

  // return the partition point
  return (i + 1);
}








void quickSort(int array[], int low, int high) {
  if (low < high) {

    // find the pivot element such that
    // elements smaller than pivot are on left of pivot
    // elements greater than pivot are on right of pivot
    int pi = partition(array, low, high);

    // recursive call on the left of pivot
    quickSort(array, low, pi - 1);

    // recursive call on the right of pivot
    quickSort(array, pi + 1, high);
  }
  qtd++;
  //printf("qtd: %d \n", qtd);
}






// function to print array elements
void printArray(int array[], int size) {
  for (int i = 0; i < size; ++i) {
    printf("%d  \n", array[i]);
  }
  printf("\n");
}






/*
COMPILE:
ulimit -a
ulimit -s 96384
# ulimit -s 3000000

apt-get intall gcc
#echo "" > quick_sort4.c
vi quick_sort4.c
gcc quick_sort4.c -o quick_sort4.exe
./quick_sort4.exe


REFE:
https://hackr.io/blog/quick-sort-in-c
https://www.youtube.com/watch?v=MZaf_9IZCrc

*/



/*
EXPLAIN Quicksort


*/



/*
EXPLAIN C




*/



/*
Quicksort
  Quicksort is an in-place sorting algorithm. Developed by British computer scientist Tony Hoare in 1959[1] and published in 1961,[2] it is still a
  commonly used algorithm for sorting.
  When implemented well, it can be somewhat faster than merge sort and about two or three times faster than heapsort


*/

