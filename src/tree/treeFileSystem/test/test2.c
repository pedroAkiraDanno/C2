/*******************************************************************************
*
* Program: List All Files And Directories In A Directory
* 
* Description: Example of how to list all files and directories contained in a 
* directory using the POSIX Library in C.
*
* YouTube Lesson: https://www.youtube.com/watch?v=0pjtn6HGPVI 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/



#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <sys/types.h>
//included so we can use the opendir, readdir and closedir functions
#include <dirent.h>




int main(int argc, char *argv[ ] )
{

    printf("%lu (char) \n", sizeof(char));
    printf("%lu (int) \n", sizeof(int));
    printf("%lu (float) \n", sizeof(float));
    printf("%lu (double) \n ", sizeof(double));

    char path[1024] = ".";
    printf("%lu (path) \n ", sizeof(path));    

  
  return 0;
}


/*
output: 

1 (char)
4 (int)
4 (float)
8 (double)


*/




/*
COMPILE | README 



  sudo su -
  sudo apt-get install gcc -y

  cd ~
  rm -fr C2/
  git clone https://github.com/pedroAkiraDanno/C2

  //  cd ~   ;   	cd C2 	; 	git checkout feature/tree   ;      cd ~  ;     cd C2/src/tree/treeFileSystem/test
  //  cd ~   ;   	cd C2 	; 	git checkout develop   ;      cd ~  ;     cd C2/src/tree/treeFileSystem/test

  cd C2/src/tree/treeFileSystem/test


  gcc -Wall -O2 test2.c -o test2
  #OR
  gcc test2.c -o test2

  ./test2



*/





