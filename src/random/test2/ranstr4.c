
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
#include "ranstr4.h"



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


