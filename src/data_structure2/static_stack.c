 /**********************************************
  * OBJETIVO  : ESTRUTURA-DE-DADOS-stack       *
  * CRIACAO   : 30-12-2019	                   *
  * VERSAO    : 1.0		                       *
  * AUTOR     : Pedro Akira Danno Lima         *
  **********************************************/


//TAD- Tipo Abstrato de Dados
//LIFO- Last in, first out ou ultimo a entrar, primeiro a sair



#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define MAXSIZE 10000


/*variaveis globais*/
int stack[MAXSIZE];
int top;





/*Prototipos da funcoes*/
void stack_init();
int  stack_isempty();
int  stack_push(int data);
int  stack_pop();
int  stack_isfull();
int  stack_peek(); /*print the top stack without pop()*/
void stack_print(); /*print stack with pop()*/








int main(){

   stack_init();

   /*push items on to the stack */
   stack_push(3);
   stack_push(5);
   stack_push(9);
   stack_push(1);
   stack_push(12);
   stack_push(15);

   printf("Element at top of the stack: %d\n" ,stack_peek());

   /*pop*/
   stack_pop();

   printf("Elements: \n");
   stack_print();

   printf("Stack full: %s\n" , stack_isfull()?"true":"false");
   printf("Stack empty: %s\n" , stack_isempty()?"true":"false");



	return 0;
}















void stack_print(){
	int data;	
   /*print stack data*/ 
   while(!stack_isempty()) {
      data = stack_pop();
      printf("%d\n",data);
   }
}




void stack_init(){
	top= -1;
}



int stack_isempty(){
	if(top == -1)
		return 1;
	else
		return 0;

	//return top === -1;
}




int stack_isfull(){
	if(top == MAXSIZE - 1)
		return 1; /*true*/
	else
		return 0; /*false*/
}



/*inserir*/
int stack_push(int data){
	if(stack_isfull()){
		return 0; /*false*/
	}else{
		top++;
		stack[top] = data;
		return 1; /*true*/
	}
}



/*desempilhar*/
int stack_pop(){
	int data;

	if(stack_isempty()){
		return 0;
	}else{
		data = stack[top];
		top--;
		return data;
	}
}




/*Function to return the top from stack without removing it */
int stack_peek() {
	if(!stack_isempty()){
		return stack[top];
	}
}







  /*****************************************************************************************************************
  *                                                   REFERENCIAS      	                                           *
  *https://www.youtube.com/watch?v=Symvpn9J3FM&t=412s							                		   		   *
  *https://www.ime.usp.br/~pf/algoritmos/apend/stdbool.h.html													   *
  ******************************************************************************************************************/
