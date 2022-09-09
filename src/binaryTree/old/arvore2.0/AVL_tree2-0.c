  /************************************************
  * OBJETIVO  : ESTRUTURA-DE-DADOS-AVL_tree       *
  * CRIACAO   : 31-01-2020	                      *
  * VERSAO    : 1.0		                          *
  * AUTOR     : Pedro Akira Danno Lima            *
  ************************************************/






/*
ARVORES AVL

name file: AVL_tree2-0.c
path to execute: /tmp
compilation: gcc AVL_tree2-0.c -o exe_AVL_tree2-0.c
execute: ./exe_AVL_tree2-0.c



-O AVL vem de seus autores Adelson-Velskii e landis (em 1962)

-Basicamente:
	-Sao arvores binarias com balanceadas
	-Mas o que é esse tal "balanceamento"?
	-Um lado nao é mais "pesado" que o outro
	-Ha um limete maximo para a "diferenca" de altura dos filhos

-Calculamos um "fator de balanceamento", que indica se um no da arvore tem filhos 
que pendem para um lado ou outro(ou nenhum - equilibrio)

-Por que é bom?
	-Garante-se um tempo maximo de busca - que é log2(n)
	*obs: 1024 elementos-em no maximo 10 passos. Se dobra elementos, so aumenta 1 passo.  1 milhao de elementos - 20 passos
	-A arvore deve sempre estar organizada 


      tree
      ----
       5    <-- root
     /   \
    3      8  
  /   \   /  \
 1    4  7    9
 				\
 				10
 				 \
 				 11	<-- leaves 	deu ruim


Por que deu ruim?
	-Na verdade a arvore ficou "desbalanceada"
	-Como sabemos, entao qual é esse "balanceamento"?
	-A diferenca de altura dos descendentes de um no tem que ser, no maximo
		-0- quando nao ha filhos ou a altura dos filhos é a mesma
		-1- quando ha no maximo 1 nivel a mais na sub-arvore direita
		-1- quando ha no maximo 1 nivel a mais na sub-arvore esquerda



-E como deixar esse balanceamento correto a cada insercao/remoceo?

-2 passos
	-Calcular o fator de balanceamento de cada no
	-Se o fator de balanceamento superar 1 ou -1, ai aplicar as devidas 
	rotacoes para poder inserir/remover correramente o novo no
	
-Sao operacoes simetricas
	-Rotacao Simples a esquerda/Rotacao simples a direira
	-Rotacoa Dupla a esquerda/Rotacao Dupla a Direita 

*/





/*
ARVORES AVL

Balanceamento é importante

Contudo, um balanceamento perfeito é algo computacionalmente caro

O bom é inimigo do otimo e vice-versa
O otimo é inimigo do bom

pq eu preciso do perfeito se eu posso ter o bom balanceamento? 

Algorimo de Adelson-Velshkii e landis(as arvores AVL)


AVL é uma arvore de busca binaria balanceada com relacao a altura de suas subarvores

Uma arvore AVL verifica a altura das subarvores da esquerda e da direita, gerantindo que essa diferenca n seja maior que mais ou menos  1 (n pode passar de 1)

Esta diferenca é seu fator de balanceamento 

altura = comprimeito do maior caminho ate um NO folha.

o fator de balanceamento é calculado a cada no


a altura de uma arvore vazia é -1




balanceado = no maximo 1 a diferença entre o altura da subarvore da esqueda com a direita 



apos a insecao, voltamos ate a raiz, no por no atualizando as alturas
se um novo fator de balanceamento para um determinado no for 2 ou -2 ajustamos a arvore 
rotacionado em torno desse no 


existem dois tipos de rotacao:
	-rotacao a esquerda
	-gira para esquerda 


      ----
       x  			->    y
        \ 				 /	
         y  			x	


	-rotacao a direita
	-gira para direita

      ----
       y  			->    x
      /   				 	\	
      x     				 y	





insecoes na parte mais externa da arvore sao resolvidas com rotacao simples

na subarvore esquerda do filho esquerdo do no desbalanceado




E quando a insecao é na parte mais interna?
Na subarvore direita do filho esquerdo do no desbalanceado




enquanto insercoes na parte mais externa da arvore sao resolvidas com rotacao simples
insercoes na parte mais interna da arvore sao resolvidas com rotacao duplas




fazemos uma rotacao a ESQUERDA se um NO foi inserido na subarvore direita do filho a direita 

A
 \
  B 		->		B
   \			   / \	
	C 			  A	  C





fazemos uma rotacao a DIREITA se um NO foi inserido na subarvore ESQUERDA do filho a ESQUERDA


	  A
 	 /
	B 			->       B
   /				    /  \
  C                    C    A



fazemos uma rotacao esquerda-direta se um no foi inserido na subarvore direita do filho a esquerda


		A 	  ->    A  	->				C
	   /           /				   / \
	  B            C                  B   A
	  \  		  /
	   C         B



fazemos uma rotacao direita-esquerda se um NO foi inserido na sub-arvore esquerda do filho a direita


	A 			-> 			A			->			C
	 \						 \					   / \
	 B 					     C 					   A  B
	/ 						 \
   C 						 B


*/




/*

ArvoreAVL.h: definir:
	-os prototipos das funcoes
	-o tipo de dado armazenado na arvore
	-o ponteiro arvore

ArvoreAVL.c definir:
	-o tipo de dado arvore
	-implementar as suas funcoes 

*com execao da insecao e da remocao as demais funcoes da arvore AVL sao 
identicas a da arvore binaria

*/





/*
Rotacao 

-considerando q o NO c foi inserido como filho do no b, e que b é filho do no a 


se o fator de balanceamento for:
	-A = +2 e B = +1: rotacao LL
	-A = -2 e B = -1: rotacao RR
	-A = +2 e B = -1: rotacao LR
	-A = -2 e B = +1: rotacao RL

As rotacoes LL e RR sao simetricas entre si 
assim como LR RL 
(sinais iguais ou diferentes)	


Implementando as rotacoes 
	-as rotacoes sao aplicadas no ancestral 
	mais proximo do NO inserdo cujo fator de balancemento passa a ser +2 ou -2
    -esse é o parametro das funcoes implementadas

    -as rotacoes simples (LL e RR) atualizam as novas alturas das sub-arvore

    -as rotacoes duplas (LR e RL) podem ser implementadas com 2 rotacoes simples	



https://www.youtube.com/watch?v=3zmjQlJhBLM

Como detectar o desequilibrio?
Como corrigir o desequilibrio?



O equilibrio de uma arvore binaria de busca é medido
subtraindo o numero de niveis na sub-arvore da esquerda do numero de niveis 
na sub-arvore da direita 

calculada em cada no

desequilibrada: maior que 1 ou menor que -1 
tolerar: 0, 1 e -1



O equilicrio da arvore é corrigido atraves das chamadas rotacoes:

existem 4 tipos basicos de rotacoes:
	-rotacao a esquerda
	-rotacao a direita 
	-rotacao dupla a esquerda 
	-rotacao dupla a direita 


rotacao a esquerda
	mover os nos que estao na subarvore da direita para a esquerda
	fazendo com que o filho da direita se torne a nova raiz
    a raiz original vira filho da esquerda na nova raiz
1                     2
 \                   / \
  2      ->         1   3 
   \
    3

 
    e se o filho da direita ja tem um filho da esquerda?

1                     2
 \                   / \
  2      ->         1   3 
 / \                 \ 
x    3                x 

todos os elementos da sub-arvore da direita sao maior que a raiz 
x > 1

o filho da direita vira nova raiz
o filho da esquerda do filho da direita vira filho da direita do filho da esquerda
a raiz original vira filho da esquerda da nova raiz



COMO DECIDIR AS ROTACOES:
	calcule q = r -l, q-> r- nivel da direita - nivel da esquerda
	se -1 <= q <= 1 -> arvore equilibrada
	se q > 1 
		se a sub-arvore da direita tem q < 0
			rotacao dupla a esquerda
		senao 
			rotao a esquerda
        senao
        	se a sub-arvore da esquerda tem q > 0
        		ratacao dupla a direita
            senao 
            	rotacao a direita         		




https://www.youtube.com/watch?v=JAeQuNsKQWk

arvore AVL = arvore binaria + balanceamento(p otimizar e nao deixar arvore com busca sequencial) 

15-27-49-10-8-67-59-9-13-20-17

FB = alt sub-arv esq - alt sub-arv dir
fator de balanceamento 
altura -> numero de nivel, n quantidade de NOS








https://www.youtube.com/watch?v=jDM6_TnYIqE

AVL Tree

-What is a binary search tree(BST)
-How BST can be improved
-What is an AVL tree
-Rotations in AVL tree
-How to create AVL tree


balance factor = height of left subtree - height of rigth subtree

bf =hl-hr = {-1,0,1} - balance

|bf| = |hl-hr| <= 1 - inbalance

rotation is to balance tree


Rotations: 
LL- Left-Left
RR- Right-Right
LR- Left-Right
RL- Right-Left

Left rotation
Right rotation
Left-Right rotation
Right-Left rotation

An unbalanced state is defined as a state in which any subtree has a balance
factor of greater than 1, or less than -1.



*/













#include <stdio.h>
#include <stdlib.h>

/*structs*/
typedef struct node
{
	int data;
	struct node *left,*right;
	int ht;
}node;
 


/*Prototipos da funcoes*/
node *insert(node *,int);
node *Delete(node *,int);
void preorder(node *);
void inorder(node *);
int height( node *);
node *rotateright(node *);
node *rotateleft(node *);
node *RR(node *);
node *LL(node *);
node *LR(node *);
node *RL(node *);
int BF(node *);
 







/*main*/
int main()
{
	node *root=NULL;
	int x,n,i,op;
	
	do
	{
		printf("\n1)Create:");
		printf("\n2)Insert:");
		printf("\n3)Delete:");
		printf("\n4)Print:");
		printf("\n5)Quit:");
		printf("\n\nEnter Your Choice:");
		scanf("%d",&op);
		
		switch(op)
		{
			case 1: printf("\nEnter no. of elements:");
					scanf("%d",&n);
					printf("\nEnter tree data:");
					root=NULL;
					for(i=0;i<n;i++)
					{
						scanf("%d",&x);
						root=insert(root,x);
					}
					break;
				
			case 2: printf("\nEnter a data:");
					scanf("%d",&x);
					root=insert(root,x);
					break;
					
			case 3: printf("\nEnter a data:");
					scanf("%d",&x);
					root=Delete(root,x);
					break;
			
			case 4: printf("\nPreorder sequence:\n");
					preorder(root);
					printf("\n\nInorder sequence:\n");
					inorder(root);
					printf("\n");
					break;			
		}
	}while(op!=5);
	
	return 0;
}






































/*funtions*/
node * insert(node *T,int x)
{
	if(T==NULL)
	{
		T=(node*)malloc(sizeof(node));
		T->data=x;
		T->left=NULL;
		T->right=NULL;
	}
	else
		if(x > T->data)		// insert in right subtree
		{
			T->right=insert(T->right,x);
			if(BF(T)==-2)
				if(x>T->right->data)
					T=RR(T);
				else
					T=RL(T);
		}
		else
			if(x<T->data)
			{
				T->left=insert(T->left,x);
				if(BF(T)==2)
					if(x < T->left->data)
						T=LL(T);
					else
						T=LR(T);
			}
		
		T->ht=height(T);
		
		return(T);
}
 



node * Delete(node *T,int x)
{
	node *p;
	
	if(T==NULL)
	{
		return NULL;
	}
	else
		if(x > T->data)		// insert in right subtree
		{
			T->right=Delete(T->right,x);
			if(BF(T)==2)
				if(BF(T->left)>=0)
					T=LL(T);
				else
					T=LR(T);
		}
		else
			if(x<T->data)
			{
				T->left=Delete(T->left,x);
				if(BF(T)==-2)	//Rebalance during windup
					if(BF(T->right)<=0)
						T=RR(T);
					else
						T=RL(T);
			}
			else
			{
				//data to be deleted is found
				if(T->right!=NULL)
				{	//delete its inorder succesor
					p=T->right;
					
					while(p->left!= NULL)
						p=p->left;
					
					T->data=p->data;
					T->right=Delete(T->right,p->data);
					
					if(BF(T)==2)//Rebalance during windup
						if(BF(T->left)>=0)
							T=LL(T);
						else
							T=LR(T);\
				}
				else
					return(T->left);
			}
	T->ht=height(T);
	return(T);
}







 
int height(node *T)
{
	int lh,rh;
	if(T==NULL)
		return(0);
	
	if(T->left==NULL)
		lh=0;
	else
		lh=1+T->left->ht;
		
	if(T->right==NULL)
		rh=0;
	else
		rh=1+T->right->ht;
	
	if(lh>rh)
		return(lh);
	
	return(rh);
}
 





node * rotateright(node *x)
{
	node *y;
	y=x->left;
	x->left=y->right;
	y->right=x;
	x->ht=height(x);
	y->ht=height(y);
	return(y);
}
 




node * rotateleft(node *x)
{
	node *y;
	y=x->right;
	x->right=y->left;
	y->left=x;
	x->ht=height(x);
	y->ht=height(y);
	
	return(y);
}
 




node * RR(node *T)
{
	T=rotateleft(T);
	return(T);
}







 
node * LL(node *T)
{
	T=rotateright(T);
	return(T);
}





 
node * LR(node *T)
{
	T->left=rotateleft(T->left);
	T=rotateright(T);
	
	return(T);
}
 



node * RL(node *T)
{
	T->right=rotateright(T->right);
	T=rotateleft(T);
	return(T);
}
 




int BF(node *T)
{
	int lh,rh;
	if(T==NULL)
		return(0);
 
	if(T->left==NULL)
		lh=0;
	else
		lh=1+T->left->ht;
 
	if(T->right==NULL)
		rh=0;
	else
		rh=1+T->right->ht;
 
	return(lh-rh);
}
 



void preorder(node *T)
{
	if(T!=NULL)
	{
		printf("%d(Bf=%d)-> ",T->data,BF(T));
		preorder(T->left);
		preorder(T->right);
	}
}
 



 
void inorder(node *T)
{
	if(T!=NULL)
	{
		inorder(T->left);
		printf("%d(Bf=%d)-> ",T->data,BF(T));
		inorder(T->right);
	}
}






/*

Output

1)Create:
2)Insert:
3)Delete:
4)Print:
5)Quit:

Enter Your Choice:1

Enter no. of elements:4

Enter tree data:7 12 4 9

1)Create:
2)Insert:
3)Delete:
4)Print:
5)Quit:

Enter Your Choice:4

Preorder sequence:
7(Bf=-1)4(Bf=0)12(Bf=1)9(Bf=0)

Inorder sequence:
4(Bf=0)7(Bf=-1)9(Bf=0)12(Bf=1)

1)Create:
2)Insert:
3)Delete:
4)Print:
5)Quit:

Enter Your Choice:3

Enter a data:7

1)Create:
2)Insert:
3)Delete:
4)Print:
5)Quit:

Enter Your Choice:4

Preorder sequence:
9(Bf=0)4(Bf=0)12(Bf=0)

Inorder sequence:
4(Bf=0)9(Bf=0)12(Bf=0)

1)Create:
2)Insert:
3)Delete:
4)Print:
5)Quit:

Enter Your Choice:5
*/









  /*****************************************************************************************************************
  *                                                   REFERENCIAS      	                                           *
  *https://www.youtube.com/watch?v=RDtJ6CCU6ZU&list=PLjcmNukBom6_nyEVge9stJLdq-bAeDoWx&index=15  				   *
  *https://justtechreview.com/program-for-avl-tree-in-c/ 														   *
  *https://www.youtube.com/watch?v=3zmjQlJhBLM																	   *
  *https://www.youtube.com/watch?v=JAeQuNsKQWk																	   *
  *****************************************************************************************************************/