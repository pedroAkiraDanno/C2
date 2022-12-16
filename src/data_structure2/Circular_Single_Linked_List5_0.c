  /***************************************************************
  * OBJETIVO  : ESTRUTURA-DE-DADOS-dynamic_list_circular.c       *
  * CRIACAO   : 10-02-2020	                    				         *
  * VERSAO    : 1.0		                        				           *
  * AUTOR     : Pedro Akira Danno Lima          				         * 
  ***************************************************************/





/*
Lista Dinamica Circular encadeada/ligada- Circular Linked List


Problema lista dinamica simples:
  -Dado um ponteiro p para um nó numa lista linear, não podemos atingir nenhum dos nós que antecedem node(p). Se uma lista for atravessada, o ponteiro externo para a lista deverá ser preservado para poder referenciá-la novamente.



Lista Circular
  -Campo next no último nó contenha um ponteiro de volta para o primeiro nó, em vez de um ponteiro nulo.
  -Lista circular não tem um "primeiro" ou um "ultimo" nó natural. Precisamos, portanto, estabelecer um primeiro e um último nó por convenção.
  -vantagem de poder incluir ou remover um elemento convenientemente a partir do início ou do final de uma lista
  -Além disso, estabelecemos a convenção de que um ponteiro nulo representa uma lista circular vazia.


Pilha e fila como uma lista circular
-Uma lista circular pode ser usada para representar uma pilha ou uma fila

*/














#include <stdio.h>
#include <stdlib.h>
 

struct node
{
    int data;
    struct node *next;
};
 
struct node *head,*tail;
 
 

/*Prototipos da funcoes*/
void create();
void display();








/*main*/
int main(){
  create();
  display();


  return 0;
}





void create(){
  int choice =1; 
  struct node *newNode, *tail;
  tail=NULL;

  while(choice){
    newNode = (struct node*)malloc(sizeof(struct node));

    printf("\n Enter the data:");
    scanf("%d", &newNode->data);
    newNode->next = NULL;

    if(tail == NULL){
       tail = newNode;  
       tail->next = newNode; /*aponta para ele mesmo, pq é uma lista circular*/ 
    }else{
      newNode->next = tail->next;
      tail->next = newNode;
      tail = newNode; /*update adress to newNode*/ 
    }

    //tail->next = head; /*circular list, if and else fazem essa condicao */



    printf("\n1 For continue 0 for exit:");
    scanf("%d",&choice);
  }

}



void display(){
  struct node *temp;

  if(tail == NULL){
    printf("\n List is empty");
  }else{
    temp = tail->next; /*get the firt node*/

    while(temp->next !=tail->next){
          printf("(%d,%p)->",temp->data, temp->next); /*print date and address*/
          temp = temp->next;
    }
          printf("(%d,%p)\n",temp->data, temp->next);  

  }

}






void insertBegin(){
  struct node *newNode;

  newNode = (struct node*)malloc(sizeof(struct node));

  printf("\n Enter the data:");
  scanf("%d", &newNode->data);
  newNode->next = NULL;

  if(tail == NULL){
    tail = newNode;
    tail->next= newNode;
  }else{
    newNode->next = tail->next;
    tail->next = newNode;
  }

  tail->next->data;


}






void insertEnd(){
  struct node *newNode;

  newNode = (struct node*)malloc(sizeof(struct node));

  printf("\n Enter the data:");
  scanf("%d", &newNode->data);
  newNode->next = NULL;

  if(tail == NULL){
    tail = newNode;
    tail->next= newNode;
  }else{
    newNode->next=tail->next;
    tail->next = newNode;
    tail = newNode;
  }

}






void insertPosition(){
  struct node *newNode,*temp;
  int pos,l,i; /*posicao, tamanho*/

  printf("\n Enter the position:");
  scanf("%d", &pos);

  l = getlength();

  if(pos < 0 || pos > l){
    printf("\n invalid position");
  }else if(pos == l){
    insertBegin();
  }else {
    newNode = (struct node*)malloc(sizeof(struct node));

    printf("\n Enter the data:");
    scanf("%d", &newNode->data);
    newNode->next = NULL;

    temp = tail->next; /*head pointer*/
    while(i < pos - 1){
      temp = temp -> next;
      i++;
    }
    newNode->next = temp->next;
    temp->next = newNode;
  }

}











void delbegin(){
  struct node *temp;
  temp = tail->next; /*guardar o primeiro node*/

  if(tail == NULL){
      printf("\n Empyty list");
  }else if(temp->next == temp){ /*one node in the list, aponta para ele mesmo*/
      tail = NULL; /*quebrar a conexao*/
      free(temp); /*desalocar o espaco no SO*/
  }else{
    tail->next = temp->next;
    free (temp);/*desalocar o espaco no SO, free = delete*/
  }

}







void delend(){
  struct node *current,*previous; /*current atual, previous antes do current, auxliares para percorrer list*/
  current = tail->next; /*guardar o primeiro node*/


  if(tail == NULL){
      printf("\n Empyty list");
  }else if(current->next == current){ /*one node in the list, aponta para ele mesmo*/
      tail = NULL; /*quebrar a conexao*/
      free(temp); /*desalocar o espaco no SO*/
  }else{
    while(current->next != tail->next){
      previous = current;
      current = current->next;
    }
    previous->next = tail->next; /*penultimo aponta para o priemeiro*/
    tail=previous; /*aponta para o penultimo, que agora se torna o ultimo*/
    free(current); /*current se torna o ultomo, que vai ser deletado p o SO*/
  }

}




void delpositon(){
  struct node *current,*nextNode; /*current atual. next depois do current*/
  int pos, i =1, l;
  current = tail->next; /*guardar o primeiro node*/

  printf("Enter pasition:");
  scanf("%d",&pos);
  l= getlength();
  
  if(pos < 1 || pes > l){
    printf("invalid position");
  } else if(pos == 1){
    delbegin();
  }else{
    while(i<pos -1){
      current = current->next;
      i++;
    }
    nextNode = current->next;
    current->next = nextNode->next;
    free(nextNode); 
  }
}







/*reverter lista muda a referencia do ponteiro para o do lado esquendo para o direito*/
void reverse(){
  struct node *current,*prev,nextnode;

  current = tail->next; /*tail->next = firt node*/
  nextNode = current->nextNode;

  if(tail==NULL){
    printf("\n Empyty list");
  }else{

    while(current != tail){
        prev = current;
        current = nextNode;
        nextNode = current->nextNode; /*guarda o valor do node quebrado a conecxao*/
        current->next = prev; /*aponta para o esquerdo agora*/        
    }
      nextNode->next = tail;/*primeiro aponta para o ulitmo*/
      tail= nextNode; /*tail aponta para o primeiro node antigo, que agora é o ultimo*/
  }

}















  /*****************************************************************************************************************
  *                                                   REFERENCIAS                                                  *
  *https://www.sanfoundry.com/c-program-implement-circular-single-linked-list/                                     *
  *https://www.youtube.com/watch?v=fmfx1C4TTxw&list=PLdo5W4Nhv31YIeatFDBuAvPlNwaKejIKC&index=14                    *
  *https://www.youtube.com/watch?v=jsTybZ5qSNE&list=PLdo5W4Nhv31YIeatFDBuAvPlNwaKejIKC&index=15                    *
  *https://www.youtube.com/watch?v=EkE6RHuMx3I&list=PLdo5W4Nhv31YIeatFDBuAvPlNwaKejIKC&index=17                    *
  *https://www.youtube.com/watch?v=xvAoleV706Q&list=PLdo5W4Nhv31YIeatFDBuAvPlNwaKejIKC&index=18                    *
  ******************************************************************************************************************/










