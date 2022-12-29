#include<stdio.h>
#include<stdbool.h>

#define MAX 3       // Queue's maximum size

//Function declaration
void enQueue(void);
void deQueue(void);
bool isEmpty(void);
void display(void);
bool isFull(void);
void peek(void);

int queue[MAX];
int REAR  = -1;
int FRONT = -1;

int main()
{
  int choice;
  printf("*** Queue  Implementation using Array***");
  
  while(1)
  {
    printf("\n1. Enqueue\n");
    printf("2. Dequeue\n");
    printf("3. Display all the Elements\n");
    printf("4. Peek Top element\n");
    printf("Enter the Choice: ");
    scanf("%d",&choice);
    
    switch(choice)
    {
      case 1:
      {
        //Inserting the element into the queue
        enQueue();  
        break;
      }
      case 2:
      {
        //Removing the element from the queue
        deQueue();
        break;
      }
      case 3:
      {
        //Displaying all the elements in the queue
        display();
        break;
      }
      case 4:
      {
        //Displaying the element which is in the front of the queue
        peek();
        break;
      }
      default:
      {
        printf ("\nPlease Enter a Valid Choice: ");
        break;
      }
    }
  }
}

bool isFull()
{
  bool isQueueFull = false;
  
  if( REAR == MAX-1 )
  {
    isQueueFull = true;
  }
  
  return (isQueueFull);
}

bool isEmpty()
{
  bool isQueueEmpty = false;
  
  if( FRONT == -1 )
  {
    isQueueEmpty = true;
  }
  
  return (isQueueEmpty);
}
    
void enQueue()
{
  if( isFull() == true )
  {
    printf("ERROR: Queue is Overflow!!!\n");
  }
  else
  {
    if( FRONT == -1 )
    {
      FRONT = 0;  
    }
    
    REAR++;
    
    int value;
    printf("Enter a value to be add: ");
    scanf("%d",&value);
    queue[REAR] = value;
    printf("%d is added to the Queue\n", value);
  }
}

void deQueue()
{
  if( isEmpty() == true )
  {
    printf("ERROR: Queue is Underflow!!!\n");
  }
  else
  {
    printf("%d is deleted\r\n", queue[FRONT]);
    
    FRONT++;
    /* Reset it, if we reached the end */
    if (FRONT > REAR)
    {
      FRONT = REAR = -1;
    }
  }
}

void display()
{
  if( isEmpty() == true )
  {
    printf("Queue is Empty!!!\n");
  }
  else 
  {
    int i;
    printf("Queue elements are:\n");
    for (i = FRONT; i <= REAR; i++)
    {
      printf("%d  ", queue[i]);
    }
    printf("\n");
  }
}

void peek()
{
  if( isEmpty() == true )
  {
    printf("Queue is Empty!!!\n");
  }
  else 
  {
    printf("Top Element is %d\n", queue[FRONT]);
  }
}



//reference: https://embetronicx.com/tutorials/p_language/c/queue-in-c/
