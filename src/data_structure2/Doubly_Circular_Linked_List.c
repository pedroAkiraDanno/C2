  /***************************************************************
  * OBJETIVO  : ESTRUTURA-DE-DADOS-Doubly Circular Linked List   *
  * CRIACAO   : 10-02-2020	                    				         *
  * VERSAO    : 1.0		                        				           *
  * AUTOR     : Pedro Akira Danno Lima          				         * 
  ***************************************************************/





/*
Lista Dinamica Duplamente Circular encadeada/ligada- Doubly Circular Linked List 

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
    struct node *prev;
    struct node *next;
};
 
struct node *head,*tail;
 
 

/*Prototipos da funcoes*/
void createDCLL();
void display();
void insertBegin();
void insertEnd();
void insertPos();
void delBegin();
void delEnd();
void delPos();








/*main*/
int main(){
  createDCLL();
  display();
  delBegin();
  display();

  return 0;
}





void createDCLL(){
  struct node *newNode;
  head = NULL;
  int choice = 1;

  while (choice){
    newNode = (struct node*)malloc(sizeof(struct node));

    printf("\n Enter the data:");
    scanf("%d", &newNode->data);

    if(head == NULL){
      head = tail = newNode;
      head->next = head; /*apontar para o primeiro node, o primeiro node*/
      head->prev = head; /*apontar para o primeiro node, o primeiro node*/
    }else{
      tail->next = newNode;
      newNode->prev = tail;
      newNode->next = head;
      head->prev = newNode;
      tail = newNode; /*tail apontar para o novo ultimo node*/
    }

    printf("\n1 For continue 0 for exit:");
    scanf("%d",&choice);
  }

}








void display(){
  struct node *temp;
  temp = head;

  if(head == NULL){
    printf("\n List is empty");
  }else{
    while(temp != tail){
      printf("%d->",temp->data); /*print date*/
          temp = temp->next;
    }
      printf("%d->",temp->data); /*print date*/
  }
}








void insertBegin(){
  struct node *newNode;
  

  newNode = (struct node*)malloc(sizeof(struct node));
  
  printf("\n Enter the data:");
  scanf("%d", &newNode->data);


  if(head = NULL){
      head = tail = newNode;
      newNode->prev = tail;
      newNode->next = head;
  }else{
    newNode->next = head;
    head->prev=newNode;
    newNode->prev = tail;
    tail->next = newNode;
    head = newNode;
  }

}





void insertEnd(){
  struct node *newNode;
  

  newNode = (struct node*)malloc(sizeof(struct node));
  
  printf("\n Enter the data:");
  scanf("%d", &newNode->data);


  if(head = NULL){
      head = tail = newNode;
      newNode->prev = tail;
      newNode->next = head;
  }else{
    newNode->prev = tail;
    tail->next = newNode;
    newNode->next = head;
    head->prev = newNode;
    tail = newNode;
  }

}





void insertPos(){
  struct node *newNode,*temp;
  int pos, i =1,l;

  printf("\n Enter position:");
  scanf("%d", &pos);

  l = getlength();

  if(pos < 1 || pos >l){
    printf("\n Invalid position");    
  }else if(pos == 1){
    insertBegin();
  }else{
    newNode = (struct node*)malloc(sizeof(struct node));
    printf("\n Enter the data:");
    scanf("%d", &newNode->data);

    temp = head; 
    while(i < pos - 1){
      temp = temp -> next;
      i++;
    } 
    newNode->prev = temp;
    newNode->next = temp->next;
    temp->next->prev = newNode;
    temp->next = newNode;
  }

}



void delBegin(){
  struct node *temp;
  temp = head;

  if(head == NULL){
    printf("\n List is empty");
  }else if(head->next == head){ /*only one node in the list*/
    head = tail = NULL;
    free(temp);
  }else{
    head = head->next;
    head->prev = tail;
    tail->next = head;
    free(temp);
  }

}






void delEnd(){
  struct node *temp;
  temp = tail;

  if(head == NULL){
    printf("\n List is empty");
  }else if(head->next == head){ /*only one node in the list*/
    head = tail = NULL;
    free(temp);
  }else{
    tail = tail->prev;
    tail->next = head; /*update to the firt node*/
    head->prev = tail; /*update to the last node*/
    free(temp);
  }
}






void delPos(){
  struct node *newNode,*temp;
  int pos, i =1,l;

  temp  = head;

  printf("\n Enter position:");
  scanf("%d", &pos);

  l = getlength();

  if(pos < 1 || pos >l){
    printf("\n Invalid position");    
  }else if(pos == 1){
    delBegin();
  }else{

    while(i < pos){
      temp = temp -> next;
      i++;
    } 

    temp->prev->next=temp->next;
    temp ->next->prev = temp->prev;
    if(temp->next == head){ /*significa q é o ultimo node*/
      tail = temp->prev;
      free(temp);
    }else{
      free(temp);
    }

}








  /*****************************************************************************************************************
  *                                                   REFERENCIAS                                                  *
  *https://www.youtube.com/watch?v=eBCTtS_sptM&list=PLdo5W4Nhv31YIeatFDBuAvPlNwaKejIKC&index=19                    *
  *https://www.youtube.com/watch?v=Fa958fGdgx0&list=PLdo5W4Nhv31YIeatFDBuAvPlNwaKejIKC&index=20                    *
  ******************************************************************************************************************/










