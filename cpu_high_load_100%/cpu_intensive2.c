
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
 * _LIMITations under the License.
 *
 *
 * 02-07-2022, v1.0, Pedro Akira Danno Lima
 *
 * Compile: gcc -Wall -O2 cpuintensive2.c -o cpuintensive2
 */



//header files 
#include <stdio.h>
#include <time.h>
#include <omp.h>


//MACROS 
#define __LIMIT 1000000 //large number     



int main() {
    double start, end;
    double runTime;
    start = omp_get_wtime();
    int num = 1,primes = 0;

   // int limit = 1000000;

#pragma omp parallel for schedule(dynamic) reduction(+ : primes)
    for (num = 1; num <= _LIMIT; num++) {
        int i = 2;
        while(i <= num) {
            if(num % i == 0)
                break;
            i++;
        }
        if(i == num)
            primes++;
     // printf("%d prime numbers calculated\n",primes);
    }

    end = omp_get_wtime();
    runTime = end - start;
    printf("This machine calculated all %d prime numbers under %d in %g seconds\n",primes,_LIMIT,runTime);

    return 0;
}


/*
	COMPILE:

		u_limit -a
		u_limit -s 3000000

		apt-get install gcc -y
		sudo apt install build-essential -y
		gcc --version

		cd 	~
		mkdir test_c ; cd test_c
		vi cpuintensive2.c
		#echo "" > cpuintensive2.c
		gcc cpuintensive2.c -o cpuintensive2.exe
		./cpuintensive2.exe

    rm *.exe *.c quick* *.txt 'a.txt'$'\n'



    REFE:
    https://kalkicode.com/quicksort-singly-linked-list


*/



  /*****************************************************************************************************************
  *                                                   REFERENCIAS                                                  *
  * https://pt.stackoverflow.com/questions/104118/qual-%C3%A9-a-finalidade-dos-comandos-size-t-e-ssize-t-em-c      *
  ******************************************************************************************************************/







