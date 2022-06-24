#include <stdio.h>
 //for malloc function
#include <stdlib.h>


//Create structure
struct Node
{
	int data;
	struct Node *next;
};




//Add new node at end of linked list 
void insert(struct Node **head, int value)
{
	//Create dynamic node
	struct Node *node = (struct Node *) malloc(sizeof(struct Node));
	if (node == NULL)
	{
		printf("Memory overflow\n");
	}
	else
	{

		node->data = value;
		node->next = NULL;
		if ( *head == NULL)
		{
			*head = node;
		}
		else
		{
			struct Node *temp = *head;
			//find last node
			while (temp->next != NULL)
			{
				temp = temp->next;
			}
			//add node at last possition
			temp->next = node;

        //  Display the address of var 
        printf("\nThe address of head = %p\n", head);				
        printf("\n\nThe address of node = %p data= %d", node, node->data);
        printf("\n\nThe address of temp = %p  data= %d", temp, temp->data);
	
		}

	}
}




//Display linked list element
void display(struct Node *head)
{
	if (head == NULL)
	{
		printf("Empty linked list");
		return;
	}
	struct Node *temp = head;
	printf("\n Linked List :");
	while (temp != NULL)
	{
		printf("  %d", temp->data);
		temp = temp->next;
	}
}



//Find last node of linked list
struct Node *last_node(struct Node *head)
{
	struct Node *temp = head;
	while (temp != NULL && temp->next != NULL)
	{
		temp = temp->next;
	}
	return temp;
}




//Set of given last node position to its proper position
struct Node *parition(struct Node *first, struct Node *last)
{
	//Get first node of given linked list
	struct Node *pivot = first;
	struct Node *front = first;
	int temp = 0;
	while (front != NULL && front != last)
	{
		if (front->data < last->data)
		{
			pivot = first;
			//Swap node value - (first with front)
			temp = first->data;
			first->data = front->data;
			front->data = temp;
			//Visit to next node
			first = first->next;
		}
		//Visit to next node
		front = front->next;
	}
	//Change last node value to current node
	temp = first->data;
	first->data = last->data;
	last->data = temp;
	return pivot;
}




//Perform quick sort in given linked list
void quick_sort(struct Node *first, struct Node *last)
{
	if (first == last)
	{
		return;
	}
	struct Node *pivot = parition(first, last);
	if (pivot != NULL && pivot->next != NULL)
	{
		quick_sort(pivot->next, last);
	}
	if (pivot != NULL && first != pivot)
	{
		quick_sort(first, pivot);
	}
}




int main()
{
	struct Node *head = NULL;
	//Create linked list
	insert( &head, 41);
	insert( &head, 5);
	insert( &head, 7);
	insert( &head, 22);
	insert( &head, 28);
	insert( &head, 63);
	insert( &head, 4);
	insert( &head, 8);
	insert( &head, 2);
	insert( &head, 11);
	printf("\n Before Sort ");
	display(head);
	quick_sort(head, last_node(head));
	printf("\n After Sort ");
	display(head);
	return 0;
}







/*
	COMPILE:

		ulimit -a
		ulimit -s 3000000

		apt-get install gcc -y
		sudo apt install build-essential -y
		gcc --version

		cd 	~ 
		mkdir q_sort ; cd q_sort
		vi quicksort-singly-linked-list.c
		#echo "" > quicksort-singly-linked-list.c
		gcc quicksort-singly-linked-list.c -o quicksort-singly-linked-list.exe
		./quicksort-singly-linked-list.exe



    REFE: 
    https://kalkicode.com/quicksort-singly-linked-list


*/







/*
TEST QUICKSORT:


BEGIN 
*41first -> 5front -> 7 -> 22 -> 28 -> 63 -> 4 -> 8 -> 2 -> 11
*5 ->  41first -> 7front -> 22 -> 28 -> 63 -> 4 -> 8 -> 2 -> 11
*5 ->  7first -> 41front -> 22 -> 28 -> 63 -> 4 -> 8 -> 2 -> 11
*5 ->  7first -> 41front -> 22 -> 28 -> 63 -> 4 -> 8 -> 2 -> 11










BEGIN 
*41first|front -> 5 -> 7 -> 22 -> 28 -> 63 -> 4 -> 8 -> 2 -> 11
*5-> 41first  -> 7front -> 22 -> 28 -> 63 -> 4 -> 8 -> 2 -> 11
5-> *7  -> 41first -> 22front -> 28 -> 63 -> 4 -> 8 -> 2 -> 11
5->  7  -> *4-> 22first  -> 28 -> 63 -> 41front -> 8 -> 2 -> 11
5->  7  -> *4-> 22 -> 28first  -> 63 -> 41 -> 8front -> 2 -> 11




















BEGIN 
*41 -> 50 -> 60 -> 5 -> 7 -> 22 -> 28 -> 63 -> 4 -> 8 -> 2 -> 11
*5 -> 50 -> 60 -> 41 -> 7 -> 22 -> 28 -> 63 -> 4 -> 8 -> 2 -> 11
5 -> *7 -> 60 -> 41 -> 50 -> 22 -> 28 -> 63 -> 4 -> 8 -> 2 -> 11
5 -> 7 -> 4 -> 41 -> 50 -> 22 -> 28 -> 63 -> 60 -> 8 -> 2 -> 11
5 -> 7 -> 4 -> *8 -> 50 -> 22 -> 28 -> 63 -> 60 -> 41 -> 2 -> 11
5 -> 7 -> 4 -> 8 -> *2 -> 22 -> 28 -> 63 -> 60 -> 41 -> 50 -> 11



















****************



BEGIN 
*41 -> 50 -> 60 -> 5 -> 7 -> 22 -> 28 -> 63 -> 4 -> 8 -> 2 -> 11

5 -> *50 -> 60 -> 41 -> 7 -> 22 -> 28 -> 63 -> 4 -> 8 -> 2 -> 11

5 -> 7 -> *60 -> 41 -> 50 -> 22 -> 28 -> 63 -> 4 -> 8 -> 2 -> 11

5 -> 7 -> 4 -> *41 -> 50 -> 22 -> 28 -> 63 -> 60 -> 8 -> 2 -> 11

5 -> 7 -> 4 -> 8 -> *50 -> 22 -> 28 -> 63 -> 60 -> 41 -> 2 -> 11

5 -> 7 -> 4 -> 8 -> 2 -> *22 -> 28 -> 63 -> 60 -> 41 -> 50 -> 11

5 -> 7 -> 4 -> 8 -> 2 -> 11 -> *28 -> 63 -> 60 -> 41 -> 50 -> 22

****the last valeu in the end of while always will be in the correct position 
because this is logical - imagine the last value comperer with last and the last is large 
so the correct position is between





*/




