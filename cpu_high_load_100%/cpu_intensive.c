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
