#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* alphabet: [a-z0-9] */
const char alphabet[] = "abcdefghijklmnopqrstuvwxyz";

/**
 * not a cryptographically secure number
 * return interger [0, n).
 */
int intN(int n) { return rand() % n; }

/**
 * Input: length of the random string [a-z0-9] to be generated
 */
char *randomString(int len) {
  char *rstr = malloc((len + 1) * sizeof(char));
  int i;
  for (i = 0; i < len; i++) {
    rstr[i] = alphabet[intN(strlen(alphabet))];
  }
  rstr[len] = '\0';
  return rstr;
}



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

ulimit -a
ulimit -s 819200

apt-get install gcc
vi ranstr.c 
gcc ranstr.c  -o ranstr.exe
./ranstr.exe



REFE:
https://siongui.github.io/2017/02/09/c-generate-random-string/


*/


