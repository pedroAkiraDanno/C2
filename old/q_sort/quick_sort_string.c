/* Quick sort algorithm to sort strings */
#include <unistd.h>
#include <string.h>
#include <stdio.h>
//#include "quicksort.h"

/* Swaps position of strings in array (char**) */
void swap(const char **a, const char **b) {
	const char *temp = *a;
	*a = *b;
	*b = temp;
}

void quicksort(char const * arr[], unsigned int length) {
	unsigned int i, piv = 0;
	if (length <= 1) 
		return;
	
	for (i = 0; i < length; i++) {
		// if curr str < pivot str, move curr into lower array and  lower++(pvt)
		if (strcmp(arr[i], arr[length -1]) < 0) 	//use string in last index as pivot
			swap(arr + i, arr + piv++);		
	}
	//move pivot to "middle"
	swap(arr + piv, arr + length - 1);

	//recursively sort upper and lower
	quicksort(arr, piv++);			//set length to current pvt and increase for next call
	quicksort(arr + piv, length - piv);
}



int main(int argc, char** argv) {
	char const *arr[] = {"this", "is", "a", "test", "of", "quicksort", "with", "strings"};
	quicksort(arr, sizeof(arr) / sizeof(*arr));
	//write(1, arr, sizeof(arr) / sizeof(*arr));
	char out[50];
	int i = 0;
	for (; i < 9; i++) {
		sprintf(out, "%s\n",arr[i]);
		puts(arr[i]);
	}
		//write(1, out, sizeof(out));

	return 0;
	
}





/*
COMPILE:

apt-get intall gcc
vi quick_sort_string.c 
gcc quick_sort_string.c -o quick_sort_string.exe
./quick_sort_string.exe



REFE: 
https://www.tutorialride.com/c-sorting-programs/sort-data-using-quick-sort-c-program.htm


*/