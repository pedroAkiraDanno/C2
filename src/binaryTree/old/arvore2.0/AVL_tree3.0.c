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




AVL Tree (simplified, and named after inventors Adelson-Velsky and Landis)

An AVL tree is a subtype of binary search tree(BST). 
AVL trees have the property of dynamic self-balancing in addition to all the properties exhibited by binary search trees.
AVL trees are also called as self-balancing binary search trees.


BALANCE FACTOR:
 BalanceFactor = height(left-sutree) − height(right-sutree)

 bf = hl-hr = {-1,0,1} - balance
 |bf| = |hl-hr| <= 1 - inbalance

 An unbalanced state is defined as a state in which any subtree has a balance factor of greater than 1, or less than -1.
 That is, any tree with a difference between the heights of its two subtrees greater than 1, is considered unbalanced.



AVL Rotations: is to balance tree
 LL- Left-Left = Left rotation = simples
 RR- Right-Right = Right rotation = simples
 LR- Left-Right = Left-Right rotation = Double left
 RL- Right-Left = Right-Left rotation = Double right



Rotations, When to Use Them and Why/Rules:

If there is an imbalance in left child of right subtree, then you perform a left-right rotation.
If there is an imbalance in left child of left subtree, then you perform a right rotation.
If there is an imbalance in right child of right subtree, then you perform a left rotation.
If there is an imbalance in right child of left subtree, then you perform a right-left rotation.

(Se fb = -negativo, esta desbalanceada a direita)- p/ balanciar tem que rotacionar esquerda
(Se fb = +posivito, esta desbalanceada a esquerda)- p/ balanciar tem que rotacionar direita

ex: 
"A = +2" e "B = +1": Rotacao simples direita
"A = -2" e "B = -1": Rotacao simples esquerda
"A = +2" e "B = -1": Rotacao dupla direita
"A = -2" e "B = +1": Rotacao dupla a esquerda




IF tree is right heavy
{
 	IF tree's right subtree is left heavy
 {
 		Perform Double Left rotation
 }
 	ELSE
 {
 		Perform Single Left rotation
 }
}
	ELSE IF tree is left heavy
{
 		IF tree's left subtree is right heavy
 {
 			Perform Double Right rotation
 }
 		ELSE
 {
 			Perform Single Right rotation
 }
}


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