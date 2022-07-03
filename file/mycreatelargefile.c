
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
 * Compile: gcc -Wall -O2 mycreatelargefile.c -o mycreatelargefile
 */





    //header files 
    #include <stdio.h>
    #include <string.h>
    #include <stdlib.h>

    //MACROS 
    #define _LARGENUMBER 1000000000 //large number     



    int main() {
            long long int i;
            FILE * fptr;

            fptr = fopen("largefile.txt", "w+"); // "w" defines "writing mode" //create a file 

            for (i = 0; i < _LARGENUMBER; i++) {
                // write to file //
                fprintf(fptr, "large file\n");
            }

            fclose(fptr);

            return 0;
        }    








/*
STUDY: 

    //fputc() Function:

*/


/*
COMPILE:

    apt-get install gcc
    echo "" > mycreatelargefile.c
    vi mycreatelargefile.c
    gcc mycreatelargefile.c  -o mycreatelargefile
    ./mycreatelargefile


obs: 
    will create a file with 11G


*/









  /*****************************************************************************************************************
  *                                                   REFERENCIAS                                                  *
  * https://pt.stackoverflow.com/questions/104118/qual-%C3%A9-a-finalidade-dos-comandos-size-t-e-ssize-t-em-c      *
  ******************************************************************************************************************/


