#include <stdio.h>
#include <time.h>
#include <omp.h>

int main() {
    double start, end;
    double runTime;
    start = omp_get_wtime();
    int num = 1,primes = 0;

    int limit = 1000000;

#pragma omp parallel for schedule(dynamic) reduction(+ : primes)
    for (num = 1; num <= limit; num++) {
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
    printf("This machine calculated all %d prime numbers under %d in %g seconds\n",primes,limit,runTime);

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
		mkdir test_c ; cd test_c
		vi cpu_intensive.c
		#echo "" > cpu_intensive.c
		gcc cpu_intensive.c -o cpu_intensive.exe
		./cpu_intensive.exe

    rm *.exe *.c quick* *.txt 'a.txt'$'\n'



    REFE:
    https://kalkicode.com/quicksort-singly-linked-list


*/
