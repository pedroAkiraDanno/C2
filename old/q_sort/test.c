    #include <stdio.h>

    int main () {

    size_t Gb = 1024*1024*1024;
    char *a = (char *)malloc(2 * Gb * sizeof(char));
    char *b = (char *)malloc(2 * Gb * sizeof(char));
    printf("use %%X: a=%X\n", a);
    printf("use %%X: b=%X\n", b);
    printf("use %%p: a=%p\n", a);
    printf("use %%p: b=%p\n", b); 

    return 0;
    }



/*
COMPILE:

apt-get intall gcc
echo "" > test.c 
vi test.c 

gcc test.c   -o test.exe
./test.exe


REFE: 


*/

