/*
 * C Program to Implement Quick Sort Using Randomization
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


#define MAX 5000000
void random_shuffle(long arr[])
{
    srand(time(NULL));
    long i, j, temp;
    for (i = MAX - 1; i > 0; i--)
    {
        j = rand()%(i + 1);
        temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}
 
void swap(long *a, long *b)
{
    long temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
long partion(long arr[], long p, long r)
{
    long pivotIndex = p + rand()%(r - p + 1); //generates a random number as a pivot
    long pivot;
    long i = p - 1;
    long j;
    pivot = arr[pivotIndex];
    swap(&arr[pivotIndex], &arr[r]);
    for (j = p; j < r; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
 
    }
    swap(&arr[i+1], &arr[r]);
    return i + 1;
}
 
void quick_sort(long arr[], long p, long q)
{
    long j;
    if (p < q)
    {
        j = partion(arr, p, q);
        quick_sort(arr, p, j-1);
        quick_sort(arr, j+1, q);
    }
}
int main()
{
    long i;
    long arr[MAX];
    for (i = 0; i < MAX; i++)
        arr[i] = i;
    random_shuffle(arr); //To randomize the array
    quick_sort(arr, 0, MAX-1); //function to sort the elements of array
    for (i = 0; i < MAX; i++)
         printf("%ld \n", arr[i]);


    return 0;
}










/*
$ gcc randomizedquicksort.c -o randomizedquicksort
$ ./randomizedquicksort
 
 
Sorted array is : 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31 32 33 34 35 36 37 38 39 40 41 42 43 44 45 46 47 48 49 50 51 52 53 54 55 56 57 58 59 60 61 62 63 64 65 66 67 68 69 70 71 72 73 74 75 76 77 78 79 80 81 82 83 84 85 86 87 88 89 90 91 92 93 94 95 96 97 98 99

*/






//reference:  https://www.sanfoundry.com/c-program-implement-quick-sort-using-randomization/












