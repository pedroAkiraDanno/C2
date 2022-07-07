#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ranstr4.h>


int main(int argc, char **argv) {
  // the seed for a new sequence of pseudo-random integers
  // to be returned by rand()
  srand(time(NULL));

  char *p;
  FILE *fp;
  int i;
  char fname[10];


  fflush (stdout);
  printf("Enter the filename : ");
  gets(fname);

  fp=fopen(fname,"w"); //create a file 


  // compare them with the pivot
  for (int i = 0; i < 10000; i++) {
      p = randomString(10);
      //printf("%s\n", p);
      fprintf(fp,"%s \n",p); //write to a file 
  }
  free(p);

}





/*
COMPILE:

apt-get install gcc
vi ranstr4.c 
#gcc -include ranstr4.h ranstr4.c -o ranstr4.exe
gcc ranstr4.c -o ranstr4.exe
./ranstr4.exe



REFE:
https://siongui.github.io/2017/02/09/c-generate-random-string/


*/


