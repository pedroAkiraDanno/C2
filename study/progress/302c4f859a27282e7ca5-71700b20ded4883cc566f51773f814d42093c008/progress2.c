/**
 * progress.c - Progress bar and progress percentage in C. 
 * This program uses ANSI escape codes to show an always updating progress line in the terminal. 
 * Author: Shubhanshu Mishra 
**/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 100000
#define WIDTH 100

int main(){
  long i;
  float progress = 0.0;
  int c  = 0, x=0, last_c=0;

  /**
   * Print a basic template of the progress line.
  **/
  fprintf(stderr, "%3d%% [", (int)progress);
  for (x = 0; x < c; x++){
    fprintf(stderr, "=");
  }
  for (x = c; x < WIDTH; x++){
    fprintf(stderr, " ");
  }
  fprintf(stderr, "]");



  

  /**
   * Write a finish line.
  **/
  fprintf(stderr, "\033[EDone\n");
}