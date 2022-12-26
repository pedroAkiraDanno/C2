#include<stdio.h>
#include<stdlib.h>


void push();
void pop();
void display();
void getValue();

struct node{
    int data;
    struct node * prev;
};

struct node * top = NULL;

void main(){
    getValue();
}

void getValue(){
    int n;
    printf("nAvailable operations on stack : nEnter 1 for PushnEnter 2 for pop nEnter 3 for displaynEnter 4 for exit");
    printf("nPlease enter your operation index : ");
    scanf("%d",&n);
    
    switch(n){
        case 1:push();
        break;
        case 2:pop();
        break;
        case 3:display();
        break;
        case 4:exit(0);
        break;
        default:printf("Error! Invalid Inputsn");
    }
}


void push(){
    struct node * temp;
    temp = (struct node *) malloc(sizeof(struct node));
    printf("Enter the node value : n");
    scanf("%d",&temp->data);
    temp->prev = top;
    top = temp;
    getValue();
}

void pop(){
    if(top == NULL){
        printf("Stack is Underflow n");
        getValue();
    }else{
        printf("Element %d is deletedn",top->data);
        top = top->prev;
        getValue();
    }
}


void display(){
    struct node * temp;
    if(top == NULL){
        printf("No element available in the stackn");
        getValue();
    }else{
        temp = top;
        while(temp != NULL){
            printf("%d-->",temp->data);
            temp = temp->prev;
        }
        getValue();
    }
}



/*
Output:


Available operations on stack : 
Enter 1 for Push
Enter 2 for pop 
Enter 3 for display
Enter 4 for exit
Please enter your operation index : 1
Enter the node value : 43

Available operations on stack : 
Enter 1 for Push
Enter 2 for pop 
Enter 3 for display
Enter 4 for exit
Please enter your operation index : 2
Element 43 is deleted

Available operations on stack : 
Enter 1 for Push
Enter 2 for pop 
Enter 3 for display
Enter 4 for exit
Please enter your operation index : 3
No element available in the stack

Available operations on stack : 
Enter 1 for Push
Enter 2 for pop 
Enter 3 for display
Enter 4 for exit
Please enter your operation index : 4



*/



//reference: https://www.stechies.com/stack-in-c/

