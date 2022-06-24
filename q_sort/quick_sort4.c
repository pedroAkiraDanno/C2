#include<stdio.h>

void swap(int* a, int* b)

{

int t = *a;

*a = *b;

*b = t;

}

int partition (int arr[], int low, int high)

{

int pivot = arr[high];

int i = (low - 1);

for (int j = low; j <= high- 1; j++)

{

if (arr[j] <= pivot)

{

i++;

swap(&arr[i], &arr[j]);

}

}

swap(&arr[i + 1], &arr[high]);

return (i + 1);

}

void quickSort(int arr[], int low, int high)

{

if (low < high)

{

int pi = partition(arr, low, high);

quickSort(arr, low, pi - 1);

quickSort(arr, pi + 1, high);

}

}

void printArray(int arr[], int size)

{

int i;

for (i=0; i < size; i++)

printf("%d ", arr[i]);

printf("n");

}

int main()

{

int arr[] = ;

int n = sizeof(arr)/sizeof(arr[0]);

quickSort(arr, 0, n-1);

printf("The sorted array is: n");

printArray(arr, n);

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