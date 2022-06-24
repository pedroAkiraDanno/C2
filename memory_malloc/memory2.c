#include <sys/resource.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>

int main() {
   struct rusage r_usage;
   int *p = 0;
   while(1) {
      p = (int*)malloc(sizeof(int)*1000);
      int ret = getrusage(RUSAGE_SELF,&r_usage);
      if(ret == 0)
         //printf("Memory usage: %ld kilobytes\n",r_usage.ru_maxrss);
      else
         printf("Error in getrusage. errno = %d\n", errno);
      usleep(10);
   }
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
		mkdir c ; cd c
		vi memory.c
		#echo "" > memory_malloc.c
		gcc memory.c -o memory.exe
		./memory.exe

		#when finish
		cd 	~ ; cd c
		rm memory_malloc.c memory_malloc.exe
		#rm *




	REFE:
	https://cppsecrets.com/users/41129711010797106994610011511264103109971051084699111109/C-program-to-get-memory-usage.php


*/
