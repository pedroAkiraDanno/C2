//header files 
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ranstr4.h"
#define MAX 15



int main(int argc, char **argv) {
  // the seed for a new sequence of pseudo-random integers
  // to be returned by rand()
  srand(time(NULL));

  char *p;
  FILE *fp;
  int i;
  char fname[MAX];


  fflush (stdout);
  printf("Enter the filename : ");
  //fgets(fname, MAX, stdin);
  scanf("%s",fname);

  fname[strcspn(fname, "\n\r")] = '\0';


  fp=fopen(fname,"w"); //create a file 


  // compare them with the pivot
  for (int i = 0; i < 100; i++) {
      p = randomString(10);
      //printf("%s\n", p);
      fprintf(fp,"%s \n",p); //write to a file 
  }
  free(p);

}


/*
COMPILE:

  #OLD
  apt-get install gcc
  vi ranstr4.c 
  #gcc -include ranstr4.h ranstr4.c -o ranstr4.exe
  gcc ranstr4.c -o ranstr4.exe
  ./ranstr4.exe




apt-get install gcc
gcc ranstr4.c main.c
./a.out 



REFE:
https://siongui.github.io/2017/02/09/c-generate-random-string/


*/



