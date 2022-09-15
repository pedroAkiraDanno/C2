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

#include <stdio.h>
#include <sys/types.h>


// included so we can use the opendir, readdir and closedir functions
#include <dirent.h>

int main(void)
{
  // directory stream variable for accessing the directory
  DIR *directory;

  // will store pointer to each entry in the directory
  struct dirent *entry;
  
  // attempt to open the current working directory, opendir() returns NULL 
  // on failure
  directory = opendir(".");
  
  // if opening the directory fails, exit with an error message and status
  if (directory == NULL)
  {
    printf("Error opening directory.\n");
    return 1;
  }
  
  // Read each entry in the directory with readdir() and store the pointer to 
  // the struct dirent into entry... when there are no more entries in the 
  // directory readdir() will return NULL and terminate the loop at that point.
entry = readdir(directory);

printf("File: %s \n", entry->d_name);
printf("File: %d \n", entry->d_fileno);
printf("File: %d \n", entry->d_type);
  
  
  return 0;
}







/*
COMPILE | README 




find / -name dirent.h
cat /usr/include/dirent.h
cat /usr/include/x86_64-linux-gnu/bits/dirent.h


vi posix_list_files2.c

gcc posix_list_files2.c
./a.out











*/





