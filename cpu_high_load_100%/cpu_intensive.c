
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
 * Compile: gcc -Wall -O2 cpuintensive.c -o cpuintensive
 */




//header files 
#include <stdio.h>
#include <stdlib.h>
#include <time.h>




void main() {
    clock_t start, end;
    double runTime;
    start = clock();
    int i, num = 1, primes = 0;

    while (num <= 100000) {
        i = 2;
        while (i <= num) {
            if(num % i == 0)
                break;
            i++;
        }
        if (i == num)
            primes++;

        system("clear");
        printf("%d prime numbers calculated\n",primes);
        num++;
    }

    end = clock();
    runTime = (end - start) / (double) CLOCKS_PER_SEC;
    printf("This machine calculated all %d prime numbers under 1000 in %g seconds\n", primes, runTime);
}










/*
	COMPILE:

		ulimit -a
		ulimit -s 3000000

		apt-get install gcc -y
		sudo apt install build-essential -y
		gcc --version

		cd 	~
		mkdir test_c ; cd test_c
		vi cpu_intensive.c
		#echo "" > cpu_intensive.c
		gcc cpu_intensive.c -o cpu_intensive.exe
		./cpu_intensive.exe

    rm *.exe *.c quick* *.txt 'a.txt'$'\n'



    REFE:
    https://kalkicode.com/quicksort-singly-linked-list


*/




  /*****************************************************************************************************************
  *                                                   REFERENCIAS                                                  *
  * https://pt.stackoverflow.com/questions/104118/qual-%C3%A9-a-finalidade-dos-comandos-size-t-e-ssize-t-em-c      *
  ******************************************************************************************************************/



