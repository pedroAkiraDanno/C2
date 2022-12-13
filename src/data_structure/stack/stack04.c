  /**********************************************
  * OBJETIVO  : ESTRUTURA-DE-DADOS-stack        *
  * CRIACAO   : 28-11-2019	                *
  * VERSAO    : 1.0		                *
  * AUTOR     : Pedro Akira Danno Lima          *
  ***********************************************/


  #include <stdio.h>
  #include <stdlib.h>


  // Data structure for stack 
  struct stack 
  {
    int maxsize; //define max capacity of stack
    int top;
    int *items;
  }

  // Utility function to initialize stack 
  struct stack* newStack(int capacity)
  {
    struct stack *pt = (struct stack*)malloc(sizeof(struct stack));



  }
































  /******************************************************************************************************************
  *                                                   EXPLAIN 
  *  main operations:
  * 
  *  -PUSH operation, which adds an element to the stack
  *  -POP operation, which removes the most recently added element that was not yet removed
  *  -PEEK operation, which returns the top element without modifying the stack
  *
  *
  *  the order in which elements come off a stack gives rise to its alternative name, LIFO(for last in,first out).
  *
  *
  *  Stack Implementation using an array 
  *
  ********************************************************************************************************************/







  /*****************************************************************************************************************
  *                                                   REFERENCIAS      	                                           *
  *https://www.techiedelight.com/stack-implementation/   						           *
  ******************************************************************************************************************/








