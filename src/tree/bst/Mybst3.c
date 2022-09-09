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
    vi bst3.c 
    gcc bst3.c  -o bst3
    ./bst3
*/










/*
* C program to implement the Binary Search Tree 
*/
#include <stdio.h>
#include <stdlib.h>
 
// structure of a node
struct node
{
    int data;
    struct node *left;
    struct node *right;
};
 
// globally initialized root pointer
struct node *root = NULL;
static int count = 0, sum[100] = {0}, max = 0; //used in function countnodes(struct node *)
 
// function prototyping
struct node *create_node(int);
void insert(int);
struct node *delete (struct node *, int);
int search(int);
void inorder(struct node *);
void postorder();
void preorder();
struct node *smallest_node(struct node *);
struct node *largest_node(struct node *);
int get_data();
int countnodes(struct node *);
int calculateSum(struct node *);
int nonleafnodes(struct node* );
int heightoftree(struct node* );
void computesum(struct  node *t);
void display();
 
int main()
{
    int userChoice;
    int userActive = 'Y';
    int data;
    struct node* result = NULL;
 
    while (userActive == 'Y' || userActive == 'y')
    {
        printf("\n\n------- Binary Search Tree ------\n");
        printf("\n1. Insert");
        printf("\n2. Delete");
        printf("\n3. Search");
        printf("\n4. Get Larger Node Data");
        printf("\n5. Get smaller Node data");
        printf("\n6. Count the Number of Nodes");  
        printf("\n7. Count Non Leaf Nodes");          
        printf("\n8. Sum of All Nodes");    
        printf("\n9. Find the Height of Tree");   
        printf("\n10. Display the sum of the elements at the same level");  
        printf("\n\n-- Traversals --");
        printf("\n\n11. Inorder ");
        printf("\n12. Post Order ");
        printf("\n13. Pre Oder ");
        printf("\n14. Exit");
 
        printf("\n\nEnter Your Choice: ");
        scanf("%d", &userChoice);
        printf("\n");
 
        switch(userChoice)
        {
            case 1:
                data = get_data();
                insert(data);
                break;
 
            case 2:
                data = get_data();
                root = delete(root, data);
                break;
 
            case 3:
                data = get_data();
                if (search(data) == 1)
                {
                    printf("\nData was found!\n");
                }
                else
                {
                    printf("\nData does not found!\n");
                }
                break;
 
            case 4:
                result = largest_node(root);
                if (result != NULL)
                {
                    printf("\nLargest Data: %d\n", result->data);
                }
                break;
 
            case 5:
                result = smallest_node(root);
                if (result != NULL)
                {
                    printf("\nSmallest Data: %d\n", result->data);
                }
                break;

            case 6:
                printf("Number of nodes in tree  = %d \n",countnodes(root));
                count = 0;
                break;

            case 7:
                printf("Count Non Leaf Nodes in a Tree  = %d \n",nonleafnodes(root));
                count = 0;
                break;                            
                
            case 8:
                printf("Sum of all nodes of binary tree: %d \n", calculateSum(root));  
                break;

            case 9:
                printf("Height of the first Tree is\t%d\n",heightoftree(root));
                break;       

            case 10:
                count = 0;
                max = 0;
                computesum(root);
                display();                
                break;                                

            case 11:
                inorder(root);
                break;
 
            case 12:
                postorder(root);
                break;
 
            case 13:
                preorder(root);
                break;
 
            case 14:
                printf("\n\nProgram was terminated\n");
                break;
 
            default:
                printf("\n\tInvalid Choice\n");
                break;
        }
 
        printf("\n__________\nDo you want to continue? ");
        fflush(stdin);
        scanf(" %c", &userActive);
    }
 
    return 0;
}
 
// creates a new node
struct node *create_node(int data)
{
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
 
    if (new_node == NULL)
    {
        printf("\nMemory for new node can't be allocated");
        return NULL;
    }
 
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;
 
    return new_node;
}
 
// inserts the data in the BST
void insert(int data)
{
    struct node *new_node = create_node(data);
 
    if (new_node != NULL)
    {
        // if the root is empty then make a new node as the root node
        if (root == NULL)
        {
            root = new_node;
            printf("\n* node having data %d was inserted\n", data);
            return;
        }
 
        struct node *temp = root;
        struct node *prev = NULL;
 
        // traverse through the BST to get the correct position for insertion
        while (temp != NULL)
        {
            prev = temp;
            if (data > temp->data)
            {
                temp = temp->right;
            }
            else
            {
                temp = temp->left;
            }
        }
 
        // found the last node where the new node should insert
        if (data > prev->data)
        {
            prev->right = new_node;
        }
        else
        {
            prev->left = new_node;
        }
 
        printf("\n* node having data %d was inserted\n", data);
    }
}
 
// deletes the given key node from the BST
struct node *delete (struct node *root, int key)
{
    if (root == NULL)
    {
        return root;
    }
    if (key < root->data)
    {
        root->left = delete (root->left, key);
    }
    else if (key > root->data)
    {
        root->right = delete (root->right, key);
    }
    else
    {
        if (root->left == NULL)
        {
            struct node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            struct node *temp = root->left;
            free(root);
            return temp;
        }
        struct node *temp = smallest_node(root->right);
        root->data = temp->data;
        root->right = delete (root->right, temp->data);
    }
    return root;
 
}
 
// search the given key node in BST
int search(int key)
{
    struct node *temp = root;
 
    while (temp != NULL)
    {
        if (key == temp->data)
        {
            return 1;
        }
        else if (key > temp->data)
        {
            temp = temp->right;
        }
        else
        {
            temp = temp->left;
        }
    }
    return 0;
}
 
// finds the node with the smallest value in BST
struct node *smallest_node(struct node *root)
{
    struct node *curr = root;
    while (curr != NULL && curr->left != NULL)
   {
        curr = curr->left;
    }
    return curr;
}
 
// finds the node with the largest value in BST
struct node *largest_node(struct node *root)
{
    struct node *curr = root;
    while (curr != NULL && curr->right != NULL)
    {
        curr = curr->right;
    }
    return curr;
}
 
// inorder traversal of the BST
void inorder(struct node *root)
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->left);
    printf("%d ",  root->data);
    inorder(root->right);
}
 
// preorder traversal of the BST
void preorder(struct node *root)
{
    if (root == NULL)
    {
        return;
    }
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}
 
// postorder travsersal of the BST
void postorder(struct node *root)
{
    if (root == NULL)
    {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}
 
// getting data from the user
int get_data()
{
    int data;
    printf("\nEnter Data: ");
    scanf("%d", &data);
    return data;
}


//Count the Number of Nodes in Binary Tree
int countnodes(struct node *root)
{
    if(root != NULL)
    {
        countnodes(root->left);
        count++;
        countnodes(root->right);
    }
    return count;
}


//Count Non Leaf Nodes in a Tree
int nonleafnodes(struct node* newnode)
{
 
    if(newnode != NULL)
    {
        nonleafnodes(newnode->left);
        if((newnode->left != NULL) || (newnode->right != NULL))
        {
            count++;
        }
        nonleafnodes(newnode->right);
    }
    return count;
 
}
 



//Sum of All Nodes in a Binary Tree
/* int sumofnodes(struct node *root)
{
    int rightsubtree, leftsubtree, sum = 0;
    if(root != NULL)
    {
        leftsubtree = sumofnodes(root->left);
        rightsubtree = sumofnodes(root->right);
        sum = (root->data) + leftsubtree + rightsubtree;
        return sum;
    }
}

//REFERENCE: https://www.sanfoundry.com/c-program-sum-of-all-nodes-in-binary-tree/
 */



//calculateSum() will calculate the sum of all the nodes present in the binary tree  
int calculateSum(struct node *temp){  
    int sum, sumLeft, sumRight;  
    sum = sumRight = sumLeft = 0;  
      
    //Check whether tree is empty  
    if(root == NULL) {  
        printf("Tree is empty\n");  
        return 0;  
    }  
    else {  
        //Calculate the sum of nodes present in left subtree  
        if(temp->left != NULL)  
            sumLeft = calculateSum(temp->left);  
          
        //Calculate the sum of nodes present in right subtree  
        if(temp->right != NULL)  
              sumRight = calculateSum(temp->right);  
          
        //Calculate the sum of all nodes by adding sumLeft, sumRight and root node's data  
        sum = temp->data + sumLeft + sumRight;   
        return sum;  
  }      
}  
//REFERENCE: https://prepinsta.com/c-program/sum-of-all-nodes-in-binary-tree/




int heightoftree(struct node* root)
{
    int max;
 
    if (root!=NULL)
    {
        /*Finding the height of left subtree.*/
        int leftsubtree = heightoftree(root->left); 
        /*Finding the height of right subtree.*/
        int rightsubtree = heightoftree(root->right);  
        if (leftsubtree > rightsubtree)
        {
            max = leftsubtree + 1;
            return max;
        }
        else
        {
            max = rightsubtree + 1;
            return max;
        }
    }
}
//REFERENCE: https://www.sanfoundry.com/c-program-find-height-tree-using-recursion/













/* Function to find the sum of nodes at same distance */
void computesum(struct node *t)
{
    if (root == NULL)
    {    
        printf("Tree is empty ");
        return;
    }
    if (t->left != NULL)
    {
        count++;    
        computesum(t->left);
    }
    sum[count] = sum[count] + t->data;  /* addition of elelment by row wise */
    if (max < count)
        max = count;
    if (t->right != NULL)
    {
        count++;        
        computesum(t->right);
    }
    count--;
}

 /* To display the sum of the nodes at the same distance */
void display()
{
    int i;
 
    printf("Sum of nodes : \n Level \t Sum ");
    for (i = 0; i <= max; i++)
       printf("\n %d \t: %d ", i, sum[i]);
}
//REFERENCE: https://www.sanfoundry.com/c-program-summation-of-node-values/














  /*****************************************************************************************************************
  *                                                   REFERENCES      	                                           
  * https://www.sanfoundry.com/c-program-implement-search-in-binary-search-tree/
  *****************************************************************************************************************/



