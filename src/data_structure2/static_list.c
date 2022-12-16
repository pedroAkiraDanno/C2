 /**********************************************
  * OBJETIVO  : ESTRUTURA-DE-DADOS-list        *
  * CRIACAO   : 30-12-2019	                   *
  * VERSAO    : 1.0		                       *
  * AUTOR     : Pedro Akira Danno Lima         *
  **********************************************/



//TAD- Tipo Abstrato de Dados
//static list 




#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define MAXSIZE 10000




/*variaveis globais*/
int front, rear; /*frente, tras*/
int list[MAXSIZE];




/*Prototipos da funcoes*/
void list_init();
bool list_isempty();
bool list_isfull();
int  list_size();
bool list_insert_at_start(int value);
bool list_insert_at_last(int value);
bool list_insert(int value, int position);
int  list_remove_at_start();
int  list_remove_at_last();
int  list_remove_at_positon(int position);
int  list_front(); /*return the value front*/
int  list_last();  /*return the value last*/
int  list_search_value(int value);
int  list_search_position(int position);
void list_display();






/*main*/
int main(){
	int value;

	list_init();	
	list_insert_at_start(5);
	list_insert_at_last(10);
	list_insert_at_last(20);

	list_display();

	return 0;
}




















/*funtions*/
void list_init(){
	front = 0;
	rear = -1;
}


bool list_isempty(){
	if(rear==-1){
		return true;
	}else
		return false;
}



bool list_isfull(){
	if(rear==MAXSIZE-1)
		return true;
	else
		return false;
}




int list_size(){
	return rear+1;
}




bool list_insert_at_start(int value){ /*inserir no comeco da lista*/
	if(list_isfull())
		return false;
	else{
		for(int i =rear+1; i>front; i--)
			list[i]=list[i-1];

		list[front]=value;
		rear++;
		return true;
	}
}




bool list_insert_at_last(int value){
	if(list_isfull())
		return false;
	else{	
	    rear++;		
		list[rear]=value;
		return true;
	}
}




bool list_insert(int value, int position){
	if(list_isfull()){
		return false;
	}else{
		if(position> front && position<rear){
		 	for(int i =rear+1; i>position; i--)
				list[i]=list[i-1];

		 	list[position]=value;
		 	rear++;
		 	return true;
	   }else{
	   		return false;
	   }
	}	
}






int list_remove_at_start(){
	int value;
	if(!list_isempty()){
		value=list[front];

		for(int i=front;i<rear;i++)
			list[i] = list[i+1];		

		rear--;
		return value;
	}
}





int list_remove_at_last(){
	int value;
	if(!list_isempty()){
		value=list[rear];
		rear--;
		return value;
	}
}






int list_remove_at_positon(int position){
	int value;
	if(!list_isempty()){		
		if(position> front && position<rear){
			value=list[position];

			for(int i=position;i<rear;i++)
				list[i] = list[i+1];

			rear--;
			return value;
		}
	}
}











int list_front(){
	int value;
	if(!list_isempty())
		return value=list[front];	
}







int list_last(){
	int value;
	if(!list_isempty()){
		return value=list[rear];
	}
}






/*qual elemento esta na posicao desejada- return posicao*/
int list_search_value(int value){
	int i,position;
	if(!list_isempty()){
		for(i = front; i<rear;i++){
			if(list[i]==value){
				break;
			}
		}

		if(!i==rear){
			position=i;
			return position;			
		}
	}
}




/*buscar por posicao- return value*/
int list_search_position(int position){
	int value;
	if(!list_isempty()){
		if(position>front && position<rear)
			value=list[position];

     	return true;
	}
}



/*display list without remove*/
void  list_display(){
    int i;
    if (list_isempty())
        printf("List is empty \n");
    else
    {
        printf("List is : \n");
        for (i = front; i <= rear; i++)
            printf("%d ", list[i]);
        printf("\n");
    }
}






  /*****************************************************************************************************************
  *                                                   REFERENCIAS      	                                           *
  *https://www.youtube.com/watch?v=tM7EByVc_lk&list=PLC9E87254BD7A875B&index=31	                		   		   *
  *https://www.ime.usp.br/~pf/algoritmos/apend/stdbool.h.html													   *
  ******************************************************************************************************************/