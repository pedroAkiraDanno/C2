  /************************************************
  * OBJETIVO  : ESTRUTURA-DE-DADOS-binary_tree    *
  * CRIACAO   : 20-01-2020	                      *
  * VERSAO    : 1.0		                          *
  * AUTOR     : Pedro Akira Danno Lima            *
  ************************************************/



  /*
	padrao: elemento maior direita(right)
		    elemento menor esquerda(left) 

	*tem que ter um parametro de ordenacao(no raiz)

	ex:

      tree
      ----
       10    <-- root
     /   \
    5      15  
  /   \   /  \
 null  12 20  null    <-- leaves 



 	problem: search sequence 

 	  tree
      ----
       1    <-- root
        \
         2  
          \
           3
            \
             4
              \
               5    <-- leaves 


 */



#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>



/*structs*/
struct node{ 
  int value; 
  struct node *left; 
  struct node *right; 
};

typedef struct node Node; //typedef permite ao programador definir um novo nome para um determinado tipo.









/*Prototipos da funcoes*/
Node *tree_initialize();
Node *tree_insert(Node *root, int x);
void tree_print(Node *root);
void tree_free(Node *root);
Node *tree_Search(Node *root, int value);
Node *treeMin(Node *root);
Node *treeRemove(Node *root);








/*main*/
int main(){
	
	Node *root = tree_initialize();	
	root = tree_insert(root, 10);
  root = tree_insert(root, 15);
	root = tree_insert(root, 5);
  root = tree_insert(root, 12);

	tree_print(root);


	return 0;
}































/*funtions*/
Node *tree_initialize(){
	return NULL;
}







Node *tree_insert(Node *root, int x){
	if(root == NULL){
		Node *aux = (Node *)malloc(sizeof(Node));
		aux->value = x;
		aux->left = NULL;
		aux->right= NULL;
		return aux;
	}else{
		if(x > root->value){
			root->right = 	tree_insert(root->right,x);
		}else if(x < root->value){
			root->left = tree_insert(root->left,x);
		}
	}
	return root;
}






void tree_print(Node *root){
	if(root != NULL){
		printf("%d \n",root->value);
		tree_print(root->left);
		tree_print(root->right);
	}
}



void tree_free(Node *root){
	if(root != NULL){
		tree_print(root->left);
		tree_print(root->right);
		free(root);
	}
}







Node *tree_Search(Node *root, int value){
	if(root != NULL){
		if(root->value == value) 
			return root;
		else{
			if(value > root->value)
				return tree_Search(root->right, value);
			else
				return tree_Search(root->left,value);
		}
	}
	return NULL;
}




Node *treeMin(Node *root){
	if(root != NULL){
		Node *aux = root;
		while(root-> left != NULL){
			aux = aux->left;
		}
		return aux;
	}
}







Node *treeRemove(Node *root){
	if(root != NULL){
		if(value > root->value){
			root->right = treeRemove(root->right, value);
		}else if (value < root->value){
			root->left = treeRemove(root->left,value);
		}else{
			if(root->left == NULL && root->right == NULL){
				free(root);
				return NULL;
			}else if (root->left == NULL && root->right != NULL){
				Node *aux = root->right;
				free(root);
				return aux;
			}else if (root->left != NULL && root->right == NULL){
				Node *aux = root->left;
				free(root);
				return aux;				
			} 
			else{
				Node *aux = treeMin(root ->right);
				Item itemAux = aux->item;
				root = treeRemove(root,itemAux.cod);
				root->item = itemAux;

			}
		}
		return root;
	}
		return NULL;

}


















  /*****************************************************************************************************************
  *                                                   REFERENCIAS      	                                           *
  *https://www.youtube.com/watch?v=d3rSW_1l6mo																	   *
  *https://www.youtube.com/watch?v=xjm0AKJpCVc																	   *
  *https://www.youtube.com/watch?v=owaBsGQheZM                                                                     *
  *https://www.youtube.com/watch?v=gR__bnL628s 																	   *
  *https://www.youtube.com/watch?v=xPYHHn8DqhI																	   *
  *https://www.youtube.com/watch?v=tM7EByVc_lk&list=PLC9E87254BD7A875B&index=31	                		   		   *
  *https://www.ime.usp.br/~pf/algoritmos/apend/stdbool.h.html													   *
  *pointer,struct,typedef																						   *
  ******************************************************************************************************************/