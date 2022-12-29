#include<stdio.h>
#define SIZE 5
void enQueue(int);
void deQueue();
void display();
int items[SIZE], front = -1, rear = -1;
int main()
{
     deQueue();
     enQueue(1);
     enQueue(2);
     enQueue(3);
     enQueue(4);
     enQueue(5);
     enQueue(6);
     display();
     deQueue();
     display();
     return 0;
}
void enQueue(int value)
{
     if(rear == SIZE-1)
           printf("nQueue is Full!!");
     else
     {
           if(front == -1)
           front = 0;
           rear++;
           items[rear] = value;
           printf("nInserted -> %d", value);
     }
}
void deQueue()
{
      if(front == -1)
      printf("nQueue is Empty!!");
      else
      {
            printf("nDeleted : %d", items[front]);
            front++;
            if(front > rear)
                   front = rear = -1;
      }
}
void display(){
      if(rear == -1)
            printf("nQueue is Empty!!!");
      else
      {
            int i;
            printf("nQueue elements are:n");
            for(i=front; i<=rear; i++)
                 printf("%dt",items[i]);
       }
}



/*
//Output:

Queue is Empty!!
Inserted -> 1
Inserted -> 2
Inserted -> 3
Inserted -> 4
Inserted -> 5
Queue is Full!!
Queue elements are:
1    2    3    4    5    
Deleted : 1
Queue elements are:
2    3    4    5

*/




//reference: https://www.edureka.co/blog/c-data-structures/#:~:text=Data%20Structures%20in%20C%20are,it%20according%20to%20their%20convenience.

