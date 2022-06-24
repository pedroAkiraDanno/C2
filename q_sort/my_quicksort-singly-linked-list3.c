#include <stdio.h>
 //for malloc function
#include <stdlib.h>
#include <time.h>
#include <limits.h>

#include <errno.h>
#include <unistd.h>
#include <sys/resource.h>


// C Program
// Quicksort on singly linked list

//#define MAX_SIZE (INT_MAX - 2147183647) =  300000
#define MAX_SIZE (INT_MAX - 2147283647)




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
	printf("\n");	

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
			//Swap node value
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






int input_data() {
	int i = 0, num = 0;
	for (int i = 0;i < MAX_SIZE;i++) {
		return num = (rand() % MAX_SIZE) + 1;	// input random data

	}

}








int main()
{

	//test progress 
	float progress = 0.0;

    // Calculate the time taken by fun()
    clock_t t1;
    t1 = clock();



	struct Node *head = NULL;

	//Create linked list
	int i = 0,last_c = 0;
	//starting data load
	printf("\n Starting data load...\n ");
	for (i = 0;i < MAX_SIZE;i++) {
		insert( &head, input_data());

	    //test progress 
		progress = i*100.0/MAX_SIZE;
		int c  = 0;
        c = (int) progress;		

		if (c % 5 == 0 &&	c != last_c){
			//printf("\n");
			fprintf(stderr, "%3d%%", (int)progress);
			//system("clear");
		} 
        last_c = c;
		

	}	
	printf("\n Finish data load ... \n\n");	


	printf("\n Infos:  ");
	printf("\nTotal qtd inserted: %d ", MAX_SIZE);	

    t1 = clock() - t1;
    double time_taken1 = ((double)t1)/CLOCKS_PER_SEC; // in seconds
  
    printf("\nData load took %f seconds to execute \n", time_taken1);


    //memory 
    struct rusage r_usage;   

      int ret = getrusage(RUSAGE_SELF,&r_usage);
      if(ret == 0){
         printf("Memory usage: %ld kilobytes\n",r_usage.ru_maxrss);
         //test
         printf("Integral shared memory size: %ld \n",r_usage.ru_ixrss);
      }
      else
         printf("Error in getrusage. errno = %d\n", errno);
      usleep(10);     




	printf("\n Before Sort ");
	//display(head);
	printf("\n Starting sort data...\n ");	



    // Calculate the time taken by fun()
    clock_t t;
    t = clock();


	quick_sort(head, last_node(head));

	printf("\n Finish sort data...\n ");		
	printf("\n After Sort\n ");
	//display(head);

    t = clock() - t;
    double time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds
  
    printf("\nsort function took %f seconds to execute \n", time_taken);


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

		#when finish
		cd 	~ ; cd q_sort
		rm *linked*.*
		#rm *




INFO: 
	if you want visualize the result, descomment the 	//display(head);



    REFE: 
    https://kalkicode.com/quicksort-singly-linked-list


*/




