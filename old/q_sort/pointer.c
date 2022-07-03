#include <stdio.h>
#include <stdlib.h>



void swapnum(int *i, int *j) {
  int temp = *i;
  *i = *j;
  *j = temp;
}


    int main()
    {

        int var; 
        int *ptr;

        var = 10;
        ptr = &var; //this syntax receive address 
        *ptr = 20; //this syntax receive value  --indirect acess


        printf("\nDirect access, var = %d", var);
        printf("\nIndirect access, var = %d\n", *ptr);

        //  Display the address of var two ways 
        printf("\n\nThe address of var = %p", &var);
        printf("\nThe address of var = %p\n", ptr);
              
        printf("The address of *ptr = %p\n", &ptr);  


        //test
        int *ptr1;
        ptr1 = ptr;    
        printf("\ntest");                        
        printf("\nThe address of *ptr1 = %p", &ptr1);  
        printf("\nIndirect access, var = %d", *ptr1);    
        printf("\nThe address of var = %p\n", ptr1);    






        //test2
        // double pointer for ptr2
        int **ptr2;
        
        // Storing address of ptr2 in ptr1
        ptr2 = &ptr1;

        // Displaying value of var using
        // both single and double pointers
        printf("\ntest2\n");              
        printf("Value of var = %d\n", var );
        printf("Value of var using single pointer = %d\n", *ptr1 );
        printf("Value of var using double pointer = %d\n", **ptr2);       

        printf("\nThe address of **ptr2 = %p", &ptr2);  
        printf("\nIndirect access, var = %d", **ptr2);    
        printf("\nThe address of ptr1 = %p\n", ptr2);    


        printf("\ntest3\n");     
        int a = 10;
        int b = 20;

        swapnum(&a, &b);
        printf("A is %d and B is %d\n", a, b);


        return 0;
    }






/*
COMPILE:
    ulimit -a
    ulimit -s 96384
    # ulimit -s 3000000
    # ulimit -s 4600000

    apt-get intall gcc
    #echo "" > pointer.c
    vi pointer.c
    gcc pointer.c -o pointer.exe
    ./pointer.exe


    REFE:
    https://hackr.io/blog/quick-sort-in-c
    https://www.youtube.com/watch?v=MZaf_9IZCrc

*/







