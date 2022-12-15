  /**********************************************
  * OBJETIVO  : ESTRUTURA-DE-DADOS-stack        *
  * CRIACAO   : 03-01-2020	                    *
  * VERSAO    : 1.0		                        *
  * AUTOR     : Pedro Akira Danno Lima          *
  ***********************************************/






#include<stdio.h>
#include<stdlib.h>


/*Prototipos da funcoes*/
bool stack_init();
bool stack_destroy();
bool stack_isempty();
int  stack_size();
bool stack_push(int valor);
bool stack_pop();
bool stack_get();



/*struct*/
struct node{
	int data;
	node *prox;
};


/*globais*/
int stack_count;
node *top;




/*main*/
int main(){
	int *p;

	p= (int*) malloc(sizeof(int));

    /*libera a memoria,devolve para o SO*/
	free(p);

	return 0;
}














/*funcoes*/
bool stack_init(){
	top=NULL;
	stack_count=0;
}




bool stack_isempty(){
	if(top==NULL){
		return true;
	}else{
		return false;
	}

}





int stack_size(){
	return stack_count;
}





bool stack_push(int valor){
	node *nova_celula = (node*) malloc(sizeof(node));

    /*caso o SO nao forneca memoria ram*/
	if(nova_celula==NULL){
		return false;
	}else{
		/* -> como se fosse o . em struct, mas para ponteiros*/
		nova_celula->data=valor;
		nova_celula->prox=top;

		top=nova_celula;
		stack_count++;
		return true;
	}
}







/* & por referencia*/
bool stack_pop(int &valor){
	node *temp; /*variavel temporaria*/

	if(stack_isempty()){
		return false;
	}else{
		valor = top->data;
		temp= top;
		top = top->prox;

		temp->prox=NULL; /*medida de seguranca para desligar a celula removida*/

		free(temp);
		stack_count--;
		return true;
	}
}





bool stack_get(int &valor){ /*obter o elemento do top sem desemstackr*/
	if(stack_isempty()){
		return false;
	}else{
		valor=top->data;
		return true;
	}
}







/*destruir toda a stack para devolver a memoria para o SO*/
bool stack_destroy(){
	int aux;
	node *temp;

	if(stack_isempty()){
		return false;
	}else{
		while(top!=NULL){
			temp= top;
			temp->prox=NULL;

			top=top->prox;

			free(temp);			
		}
		stack_count=0;
		return true;
	}

}









  /*****************************************************************************************************************
  *                                                   REFERENCIAS      	                                           *
  *https://www.youtube.com/watch?v=Tvk8FxOSD_k									                		   		   *
  ******************************************************************************************************************/