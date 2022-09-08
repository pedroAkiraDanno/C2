
  /************************************************
  * GOALS     : BINARY TREE        
  * DATA      : 06-08-2022	                      
  * VERSION   : 1.0		                          
  * AUTHOR    : Pedro Akira Danno Lima            
  ************************************************/







/*
COMPILE:
    ulimit -a
    ulimit -s 819200
    apt-get install gcc
    vi binaryTree3_2.c 
    gcc binaryTree3_2.c  -o binaryTree3_2
    ./binaryTree3_2



*/

#include <stdio.h>
#include <stdlib.h>
struct BTnode {
int data;
struct BTnode* leftNode;
struct BTnode* rightNode;
};
void inorder(struct BTnode* rootNode) {
if (rootNode == NULL) return;
inorder(rootNode->leftNode);
printf("%d ->", rootNode->data);
inorder(rootNode->rightNode);
}
void preorder(struct BTnode* rootNode) {
if (rootNode == NULL) return;
printf("%d ->", rootNode->data);
preorder(rootNode->leftNode);
preorder(rootNode->rightNode);
}
void postorder(struct BTnode* rootNode) {
if (rootNode == NULL) return;
postorder(rootNode->leftNode);
postorder(rootNode->rightNode);
printf("%d ->", rootNode->data);
}
struct BTnode* createNode(value) {
struct BTnode* newNode = malloc(sizeof(struct BTnode));
newNode->data = value;
newNode->leftNode = NULL;
newNode->rightNode = NULL;
return newNode;
}
struct BTnode* insertLeftNode(struct BTnode* rootNode, int value) {
rootNode->leftNode = createNode(value);
return rootNode->leftNode;
}
struct BTnode* insertRightNode(struct BTnode* rootNode, int value) {
rootNode->rightNode = createNode(value);
return rootNode->rightNode;
}
int main() {
struct BTnode* rootNode = createNode(7);
insertLeftNode(rootNode, 4);
insertRightNode(rootNode, 8);
insertLeftNode(rootNode->leftNode, 1);
insertRightNode(rootNode->rightNode, 5);
insertLeftNode(rootNode->leftNode, 6);
insertRightNode(rootNode->rightNode, 3);
printf("Inorder \n");
inorder(rootNode);
printf("\nPreorder \n");
preorder(rootNode);
printf("\nPostorder \n");
postorder(rootNode);
}






  /*****************************************************************************************************************
  *                                                   REFERENCES      	                                           
  * https://www.educba.com/binary-tree-program-in-c/
  *****************************************************************************************************************/









