
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
 * 01-07-2022, v2.0, Pedro Akira Danno Lima
 *
 * Compile: gcc -Wall -O2 ranstr4.c -o ranstr4
 */




//header files 
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


