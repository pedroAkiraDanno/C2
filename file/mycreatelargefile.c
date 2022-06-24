    //fputc() Function:
    #include <stdio.h>
    #include <string.h>
    #include <stdlib.h>

    int main() {
            long long int i;
            FILE * fptr;

            fptr = fopen("largefile.txt", "w+"); // "w" defines "writing mode" //create a file 

            for (i = 0; i < 1000000000; i++) {
                // write to file //
                fprintf(fptr, "large file\n");
            }

            fclose(fptr);

            return 0;
        }    

/*
COMPILE:

    apt-get install gcc
    echo "" > mycreatelargefile.c
    vi mycreatelargefile.c
    gcc mycreatelargefile.c  -o mycreatelargefile.exe
    ./mycreatelargefile.exe


obs: 
will create a file with 11G


REFE: 


*/

