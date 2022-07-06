
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
 * Compile: gcc -Wall -O2 quick_sort9.c -o quick_sort9
 */






//header files 
#include<stdio.h>
#include<stdlib.h>
#include<time.h>


//MACROS 
#define MAX_SIZE 10





//global variable
int list[MAX_SIZE];
//list[] = {2, 8, 4, 1, 10, 5, 9, 8, 3, 7};
int qtd = 0; // to debug, qnt how many times is call quick_sort fucntion


//functions
void quick_sort(int* list[],int left,int right);	// quick_sort function
int swap(int *i, int *j);							// swap function
void print(int* list[]);							// print function
void print_debug(int* list[]);					    // print function debug






int swap(int *i, int *j) {
	int *tmp = 0;
	tmp = *i;
	*i = *j;
	*j = tmp;
	return i, j;
}




void quick_sort(int* list[], int left, int right)
{
	if (left >= right) return;
	int mid = (left + right) / 2;	//(left + right) = qtd so qtd / 2 will find the middle number - very easy to understood
	int i = left, j = right;
	int pivot = list[mid];
	int k = 0;

	//debug
	int v_left = list[left];
	int v_right = list[right];
	int v_mid = list[mid];



	while (left <= right) {
		while (list[left] < pivot)
            left++;
		while (list[right] > pivot)
            right--;
		if (left <= right) {
			swap(&list[left], &list[right]);
			left++; right--;
		}
	}

	//debug
	qtd++;
    printf("qtd: %d",qtd);
	printf(" mid: %d ", v_mid);
    print_debug(list);


	quick_sort(list, i, right);
	quick_sort(list, left, j);
}



void print(int* list[]) {
	int i = 0;
	for (i = 0;i < MAX_SIZE;i++) {
		if (i % 10 == 0) printf("\n");
		printf("%3d ", list[i]);
	}
	printf("\n");
}


//debug
void print_debug(int* list[]) {
	int i = 0;
	for (i = 0;i < MAX_SIZE;i++) {
		if (i % 10 == 0) printf("\n");
		printf("%3d ", list[i]);
	}
	printf("\n");
}




void input_data(int* list[]) {
	int i = 0;
	for (int i = 0;i < MAX_SIZE;i++) {
		//list[i] = (rand() % MAX_SIZE) + 1;	// input random data
		      scanf("%d",&list[i]);

	}

}



//main
int main() {
	clock_t start, end;
	float total_time;
	start = clock();
	input_data(list);
	printf("unsort: ");
	print(list);
	quick_sort(list, 0, sizeof(list) / sizeof(int) - 1);
	printf("--------------------------------------------------------------------------------\n");
	printf("sort: ");
	print(list);
	end = clock();
	total_time = (float)(end - start) / CLOCKS_PER_SEC;

	printf("Execute_time : %.6f\n", total_time);
	return 0;
}








/*
quick sort

**after find the correct place to pivot, always go to the left - 1 = pivot -1

i = 0, left = 0 right = 9
1
2   8   5   1  10   5   9   9   3   5     BEGIN
2   8   5   1  10*   5   9   9   3   5
2   8   5   1  5     5   9   9   3   10*



i = 0, right = 8
2
2   8   5   1  5*   5   9   9   3|   10
2   3   5   1  5*   5   9   9   8|   10  swap (2,5)
2   3   5   1  5*   5   9   9   8|   10  swap (4,4)
2   3   5   1  5*   5   9   9   8|   10



i = 0, right = 3
3
2   3*   5   1|   5   5   9   9   8   10 swap (1,3)
2   1   5   3*|   5   5   9   9   8   10 swap (2,1) left = 2 right = 2
2   5   1   3*|   5   5   9   9   8   10

2   1   5   3   5   5   9   9   8  10


4
i = 0, left = 0 right = 1
2*   1|   5   3   5   5   9   9   8  10 swap (0,1)
1   2*|   5   3   5   5   9   9   8  10


5 no qttd++ so not 5
i = 0, left = 0 right = 0
false

6  no qttd++ so not 6
i = 0, left = 0 right = 0        down quick_sort
false


5
i = 2, left = 2 right = 3        down quick_sort
1   2   |5*   3|   5   5   9   9   8  10
1   2   |3   5*|   5   5   9   9   8  10


7  no qttd++ so not 7
i = 0, left = 2 right = 2        up quick_sort
false


8  no qttd++ so not 8
i = 0, left = 3 right = 3        down quick_sort
false


6
i = 0, left = 5 right = 8        down quick_sort
1   2   3   5   5   |5   9*   9   8|  10  swap (6,8)
1   2   3   5   5   |5   8   9   9*|  10 swap (7,7)
1   2   3   5   5   |5   8   9   9*|  10




















test2

i = 0, left = 0 right = 9
1
2   8   4   1  10*   5   7   9   3   6     BEGIN
2   8   4   1  6   5   7   9   3   10*
2   8   4   1  6   5   7   9   3   10*



i = 0, left = 0 right = 8
2
2   8   4   1  6*   5   7   9   3|   10
2   3   4   1  6*   5   7   9   8|   10     ****left = 2, rigth = 7 so each while finish the size  of array to comparation is less too, this is good
2   3   4   1  5   6*   7   9   8|   10



i = 0, left = 0 right = 4
3
2   3   4*   1   5|   6   7   9   8   10
2   3   1    4*  5|   6   7   9   8   10


i = 0, left = 0 right = 2
4
2   3*   1|    4  5   6   7   9   8   10
2   1   3*|    4  5   6   7   9   8   10



i = 0, left = 0 right = 1
5
2*   1|   3    4  5   6   7   9   8   10
1   2*|   3    4  5   6   7   9   8   10


//FALSE
6  no qttd++ so not 6
i = 0, left = 0 right = 0        up  quick_sort
false

7  no qttd++ so not 7
i = 0, left = 1 right = 1        down  quick_sort
false

8  no qttd++ so not 8
i = 0, left = 2 right = 2        down  quick_sort
false




6
i = 0, left = 3 right = 4        down  quick_sort
1   2   3   |4*  5|   6   7   9   8   10


1   2   3   4   5   6   7   9   8  10








*/








/*
	COMPILE:

		ulimit -a
		ulimit -s 3000000

		apt-get install gcc -y
		sudo apt install build-essential -y
		gcc --version

		cd 	~
		mkdir q_sort ; cd q_sort
		vi quick_sort9.c
		#echo "" > quick_sort9.c
		gcc quick_sort9.c -o quick_sort9.exe
		./quick_sort9.exe



	REFE:
	https://github.com/wk1219/Quick_sort/blob/master/quick_sort.c


*/

