  /**********************************************
  * OBJETIVO  : ESTRUTURA-DE-DADOS-queue        *
  * CRIACAO   : 03-01-2019	                    *
  * VERSAO    : 1.0		                        *
  * AUTOR     : Pedro Akira Danno Lima          *
  ***********************************************/



//TAD- Tipo Abstrato de Dados
//FIFO- First in, first out ou Primeiro a entrar, primeiro a sair



#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define MAXTAM 100000


/*variaveis globais*/
int front, rear; /*frente, tras*/
int queue[MAXTAM];




/*Prototipos da funcoes*/
void queue_init();
bool queue_isempty();
bool queue_isfull();
bool queue_enqueue(int value); /*enfileirar*/
int  queue_dequeue(); /*desenfileirar*/
int  queue_front();
int  queue_size();
void queue_display();




/*main*/
int main(){
	
	queue_init();

	queue_enqueue(5);
	queue_enqueue(2);
	queue_enqueue(7);

	queue_dequeue();
	
	queue_display();

	return 0;
}








/*functions*/
void queue_init(){
	front= 0;
	rear= -1;
}




bool queue_isempty(){
	if(front> rear){
		return true; /*queue vazia*/
	}else{
		return false;
	}
	/*return front>rear*/
}




bool queue_isfull(){
	if(rear==MAXTAM-1){
		return true; /*queue cheia*/
	}else{
		return false;
	}
	/*return rear==MAXTAM-1;*/
}





/*add new value in queue*/
bool queue_enqueue(int value){
	if(queue_isfull()){
		return false;
	}else{
		rear++;
		queue[rear] = value;
		return true;
	}
}



/*remove new value in queue*/
int queue_dequeue(){
	int value;
	if(!queue_isempty()){
		value=queue[front];
		front++;
		return value;
	}
}




int queue_front(){
	if(!queue_isempty())
		return queue[front];
}




int queue_size(){
	return (rear - front)+1;
}






void queue_display(){
    int i;
    if (front == - 1)
        printf("Queue is empty \n");
    else
    {
        printf("Queue is : \n");
        for (i = front; i <= rear; i++)
            printf("%d ", queue[i]);
        printf("\n");
    }
}




  /*****************************************************************************************************************
  *                                                   REFERENCIAS      	                                           *
  *https://www.youtube.com/watch?v=XiCADB67p9M&list=PLC9E87254BD7A875B&index=27					   		   		   *
  *https://www.hackerearth.com/pt-br/practice/notes/stacks-and-queues/											   *
  ******************************************************************************************************************/

