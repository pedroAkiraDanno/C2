  /***************************************************************
  * OBJETIVO  : ESTRUTURA-DE-DADOS-dynamic_list_circular.c       *
  * CRIACAO   : 03-01-2020	                    				         *
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
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

struct node {
   int data;
   int key;
  
   struct node *next;
};

struct node *head = NULL;
struct node *current = NULL;

bool isEmpty() {
   return head == NULL;
}

int length() {
   int length = 0;

   //if list is empty
   if(head == NULL) {
      return 0;
   }

   current = head->next;

   while(current != head) {
      length++;
      current = current->next;   
   }
  
   return length;
}


//insert link at the first location
void insertFirst(int key, int data) {

   //create a link
   struct node *link = (struct node*) malloc(sizeof(struct node));
   link->key = key;
   link->data = data;
  
   if (isEmpty()) {
      head = link;
      head->next = head;
   } else {
      //point it to old first node
      link->next = head;
    
      //point first to new first node
      head = link;
   }    
}

//delete first item
struct node * deleteFirst() {

   //save reference to first link
   struct node *tempLink = head;
  
   if(head->next == head) {  
      head = NULL;
      return tempLink;
   }     

   //mark next to first link as first 
   head = head->next;
  
   //return the deleted link
   return tempLink;
}

//display the list
void printList() {

   struct node *ptr = head;
   printf("\n[ ");
  
   //start from the beginning
   if(head != NULL) {
  
      while(ptr->next != ptr) {     
         printf("(%d,%d) ",ptr->key,ptr->data);
         ptr = ptr->next;
      }
   }
  
   printf(" ]");
}



void main() {
   insertFirst(1,10);
   insertFirst(2,20);
   insertFirst(3,30);
   insertFirst(4,1);
   insertFirst(5,40);
   insertFirst(6,56); 

   printf("Original List: "); 
  
   //print list
   printList();

   while(!isEmpty()) {            
      struct node *temp = deleteFirst();
      printf("\nDeleted value:");  
      printf("(%d,%d) ",temp->key,temp->data);
   }   
  
   printf("\nList after deleting all items: ");
   printList();   
}








  /*****************************************************************************************************************
  *                                                   REFERENCIAS      	                                           *
  *(ebook)Estruturas%20de%20Dados%20Usando%20C%20(Tenenbaum).pdf						                		   		             *
  *https://www.tutorialspoint.com/data_structures_algorithms/circular_linked_list_program_in_c.htm                 *
  ******************************************************************************************************************/