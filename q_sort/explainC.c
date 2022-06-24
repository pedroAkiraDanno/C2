//-------------------------------------------------------------------------------------------------------------------------------------------------------------
/*

INDEX: 
    Pointers
    ARRAY
    STRING
    Passing by value, passing by reference in C
    PRINT
    struct 
    FILE 
    scanf vs gets
    malloc



*/

//-------------------------------------------------------------------------------------------------------------------------------------------------------------
/*
Pointers 

IMPORTANT:
& = the address of variable 

C Pointers
Pointers (pointer variables) are special variables that are used to store addresses rather than values.


Pointer Syntax
    Here is how we can declare pointers.

    int* p;

    You can also declare pointers in these ways.
    int *p1;
    int * p2;


Assigning addresses to Pointers
    int *pc, c;
    c = 5;
    pc = &c; // this syntax receve address

    Here, 5 is assigned to the c variable. And, the address of c is assigned to the pc pointer.



Get Value of Thing Pointed by Pointers
    int* pc, c;
    c = 5;
    pc = &c;
    printf("%d", *pc);   // Output: 5

    To get the value of the thing pointed by the pointers, we use the * operator. For example:
    Here, the address of c is assigned to the pc pointer. To get the value stored in that address, we used *pc.

    Note: In the above example, pc is a pointer, not *pc. You cannot and should not do something like *pc = &c;

    By the way, * is called the dereference operator (when working with pointers). It operates on a pointer and gives the value stored in that pointer.




Changing Value Pointed by Pointers
    int* pc, c;
    c = 5;
    pc = &c;
    c = 1;
    printf("%d", c);    // Output: 1
    printf("%d", *pc);  // Ouptut: 1

    We have assigned the address of c to the pc pointer.

    Then, we changed the value of c to 1. Since pc and the address of c is the same, *pc gives us 1.







EXEMPLO 1: 
    #include <stdio.h>

    int main () {

    int  var1;
    char var2[10];

    printf("Address of var1 variable: %x\n", &var1  );
    printf("Address of var2 variable: %x\n", &var2  );

    return 0;
    }



EXEMPLO 2: 
    #include <stdio.h>
    int main () {

        int  var = 20;   // actual variable declaration 
        int  *ip;        // pointer variable declaration 

        ip = &var;  // store address of var in pointer variable

        printf("Address of var variable: %x\n", &var  );

        // address stored in pointer variable 
        printf("Address stored in ip variable: %x\n", ip );

        // access the value using the pointer 
        printf("Value of *ip variable: %d\n", *ip );

        return 0;
    }



EXEMPLO 3: 
    #include <stdio.h>
    int main()
    {
        int a=10;    //variable declaration
        int *p;      //pointer variable declaration
        p=&a;        //store address of variable a in pointer p
        printf("Address stored in a variable p is:%x\n",p);  //accessing the address
        printf("Value stored in a variable p is:%d\n",*p);   //accessing the value
        return 0;
    }




EXEMPLO 4: 
    #include <stdio.h>
    // Declare and initialize an int variable
    int var = 1;
    //  Declare a pointer to int 
    int *ptr;
    int main( void )
    {
        //  Initialize ptr to point to var 
        ptr = &var;
        //  Access var directly and indirectly 
        printf("\nDirect access, var = %d", var);
        printf("\nIndirect access, var = %d", *ptr);

        //  Display the address of var two ways 
        printf("\n\nThe address of var = %d", &var);
        printf("\nThe address of var = %d\n", ptr);

        // change the content of var through the pointer
        *ptr=48;
        printf("\nIndirect access, var = %d\n", *ptr);

        return 0;
    }




EXEMPLO 5: C Pointers & Arrays with Examples
    #include <stdio.h>
    int main()
    {
        int a[5]={1,2,3,4,5};   //array initialization
        int *p;     //pointer declaration
                //the ptr points to the first element of the array

        p=a; //We can also type simply ptr==&a[0] 
        
        printf("Printing the array elements using pointer\n");
        for(int i=0;i<5;i++)    //loop for traversing array elements
        {
                printf("\n%x",*p);  //printing array elements
                p++;    //incrementing to the next element, you can also write p=p+1
        }
        return 0;
    }








EXEMPLO 6: C Pointers and Strings with Examples
    #include <stdio.h>
    #include <string.h>
    int main()
    {
        char str[]="Hello Guru99!";
        char *p;
        p=str;
        printf("First character is:%c\n",*p);
        p =p+1;
        printf("Next character is:%c\n",*p);
        printf("Printing all the characters in a string\n");
        p=str;  //reset the pointer
            for(int i=0;i<strlen(str);i++){
                printf("%c\n",*p);
                p++;
            }   
        return 0;
    }




EXEMPLO 7:
    #include <stdio.h>
    int main()
    {

        int var; 
        int *ptr;

        var = 10;
        ptr = &var;
        *ptr = 20;


        printf("\nDirect access, var = %d", var);
        printf("\nIndirect access, var = %d\n", *ptr);

        //  Display the address of var two ways 
        printf("\n\nThe address of var = %d", &var);
        printf("\nThe address of var = %d\n", ptr);
        

        return 0;
    }




Pointer Arithmetic in C


    We can perform arithmetic operations on the pointers like addition, subtraction, etc. However, as we know that pointer contains the address, 
    the result of an arithmetic operation performed on the pointer will also be a pointer if the other operand is of type integer.

    In pointer-from-pointer subtraction, the result will be an integer value. Following arithmetic operations are possible on the pointer in C language:

    Increment
    Decrement
    Addition
    Subtraction
    Comparison

    Incrementing Pointer in C
    If we increment a pointer by 1, the pointer will start pointing to the immediate next location. This is somewhat different from the general arithmetic since the value of the pointer will get increased by the size of the data type to which the pointer is pointing.

    We can traverse an array by using the increment operation on a pointer which will keep pointing to every element of the array, perform some operation on that, and update itself in a loop.

    The Rule to increment the pointer is given below:
    new_address= current_address + i * size_of(data type)  

    32-bit
    For 32-bit int variable, it will be incremented by 2 bytes.

    64-bit
    For 64-bit int variable, it will be incremented by 4 bytes. 


    EXEMPLO: 
    #include<stdio.h>  
    int main(){  
        int number=50;        
        int *p;//pointer to int      
        p=&number;//stores the address of number variable        
        printf("Address of p variable is %u \n",p);        
        p=p+1;        
        printf("After increment: Address of p variable is %u \n",p); // in our case, p will get incremented by 4 bytes.      
        return 0;  
    }    



    #include<stdio.h>  
    void main ()  
    {  
        int arr[5] = {1, 2, 3, 4, 5};  
        int *p = arr;  
        int i;  
        printf("printing array elements...\n");  
        for(i = 0; i< 5; i++)  
        {  
            printf("%d  ",*(p+i));  
        }  
    }  



    TEST:
    #include<stdio.h>  
    int main(){  
        int number=50;        
        int *p,*temp;//pointer to int      
        p=&number;//stores the address of number variable
        temp=p;        
        printf("Address of p variable is %u \n",p);        
        temp=temp+1;        
        printf("After increment: Address of p variable is %u \n",temp); // in our case, p will get incremented by 4 bytes.      

        //trash
        int i;  
        for(i = 0; i< 100; i++){  
            temp=temp+1;   
            printf("After increment: Address of temp variable is %u \n",temp); // in our case, p will get incremented by 4 bytes.         
        }      
        return 0;      
    }    




    #include <stdio.h>
    int main () {

        int  var = 20;   // actual variable declaration 
        int  *ip;        // pointer variable declaration 

        ip = &var;  // store address of var in pointer variable

        printf("Address of var variable: %x\n", &var  );

        // address stored in pointer variable 
        printf("Address stored in ip variable: %x\n", ip );

        // access the value using the pointer 
        printf("Value of *ip variable: %d\n", *ip );

        int i;  
        for(i = 0; i< 100; i++){  
            ip = ip+1;
            printf("%x\n  ",ip);  
        }          

        return 0;
    }









*/



/*
Double Pointer (Pointer to Pointer) in C

We already know that a pointer points to a location in memory and thus used to store the address of variables. So, when we define a pointer to pointer. The first pointer is used to store the address of the variable. And the second pointer is used to store the address of the first pointer. That is why they are also known as double pointers.


How to declare a pointer to pointer in C?
Declaring Pointer to Pointer is similar to declaring pointer in C. The difference is we have to place an additional ‘*’ before the name of pointer.
Syntax:

int **ptr;    // declaring double pointers


Let us understand this more clearly with the help of the below program:

#include <stdio.h>
  
// C program to demonstrate pointer to pointer
int main()
{
    int var = 789;
  
    // pointer for var
    int *ptr2;
  
    // double pointer for ptr2
    int **ptr1;
  
    // storing address of var in ptr2
    ptr2 = &var;
      
    // Storing address of ptr2 in ptr1
    ptr1 = &ptr2;
      
    // Displaying value of var using
    // both single and double pointers
    printf("Value of var = %d\n", var );
    printf("Value of var using single pointer = %d\n", *ptr2 );
    printf("Value of var using double pointer = %d\n", **ptr1);
    
  return 0;
} 
Output:

Value of var = 789
Value of var using single pointer = 789
Value of var using double pointer = 789





REF: https://www.geeksforgeeks.org/double-pointer-pointer-pointer-c/


*/



/*
C – Pointer to Pointer (Double Pointer) with example


We already know that a pointer holds the address of another variable of same type. When a pointer holds the address of another pointer then such type of pointer is known as pointer-to-pointer or double pointer. In this guide, we will learn what is a double pointer, how to declare them and how to use them in C programming. To understand this concept, you should know the basics of pointers.

How to declare a Pointer to Pointer (Double Pointer) in C?
int **pr;
Here pr is a double pointer. There must be two *’s in the declaration of double pointer.





As per the diagram, pr2 is a normal pointer that holds the address of an integer variable num. There is another pointer pr1 in the diagram that holds the address of another pointer pr2, the pointer pr1 here is a pointer-to-pointer (or double pointer).

Values from above diagram:

Variable num has address: XX771230
Address of Pointer pr1 is: XX661111
Address of Pointer pr2 is: 66X123X1


Example of double Pointer
Lets write a C program based on the diagram that we have seen above.

#include <stdio.h>
int main()
{
     int num=123;

     //A normal pointer pr2
     int *pr2;

     //This pointer pr2 is a double pointer
     int **pr1;

      //      Assigning the address of variable num to the
      // pointer pr2
      
     pr2 = #

      // Assigning the address of pointer pr2 to the
      //* pointer-to-pointer pr1
       //
     pr1 = &pr2;

      // Possible ways to find value of variable num //
     printf("\n Value of num is: %d", num);
     printf("\n Value of num using pr2 is: %d", *pr2);
     printf("\n Value of num using pr1 is: %d", **pr1);

      //Possible ways to find address of num 
     printf("\n Address of num is: %p", &num);
     printf("\n Address of num using pr2 is: %p", pr2);
     printf("\n Address of num using pr1 is: %p", *pr1);

      //Find value of pointer 
     printf("\n Value of Pointer pr2 is: %p", pr2);
     printf("\n Value of Pointer pr2 using pr1 is: %p", *pr1);

      //Ways to find address of pointer
     printf("\n Address of Pointer pr2 is:%p",&pr2);
     printf("\n Address of Pointer pr2 using pr1 is:%p",pr1);

      //Double pointer value and address
     printf("\n Value of Pointer pr1 is:%p",pr1);
     printf("\n Address of Pointer pr1 is:%p",&pr1);

     return 0;
}
Output:

Value of num is: 123
Value of num using pr2 is: 123
Value of num using pr1 is: 123
Address of num is: XX771230
Address of num using pr2 is: XX771230
Address of num using pr1 is: XX771230
Value of Pointer pr2 is: XX771230
Value of Pointer pr2 using pr1 is: XX771230
Address of Pointer pr2 is: 66X123X1
Address of Pointer pr2 using pr1 is: 66X123X1
Value of Pointer pr1 is:  66X123X1
Address of Pointer pr1 is: XX661111
There are some confusions regarding the output of this program, when you run this program you would see the address similar to this: 0x7fff54da7c58. The reason I have given the address in different format is because I want you to relate this program with the diagram above. I have used the exact address values in the above diagram so that it would be easy for you to relate the output of this program with the above diagram.

You can also understand the program logic with these simple equations:

num == *pr2 == **pr1
&num == pr2 == *pr1
&pr2 == pr1






REFE: https://beginnersbook.com/2014/01/c-pointer-to-pointer/


*/
















//-------------------------------------------------------------------------------------------------------------------------------------------------------------
/*
ARRAY 
Relationship Between Arrays and Pointers
An array is a block of sequential data.


#include <stdio.h>
int main() {
   int x[4];
   int i;

   for(i = 0; i < 4; ++i) {
      printf("&x[%d] = %p\n", i, &x[i]);
   }

   printf("Address of array x: %p", x);

   return 0;
}

Output

&x[0] = 1450734448
&x[1] = 1450734452
&x[2] = 1450734456
&x[3] = 1450734460

Address of array x: 1450734448
There is a difference of 4 bytes between two consecutive elements of array x. It is because the size of int is 4 bytes (on our compiler).

Notice that, the address of &x[0] and x is the same. It's because the variable name x points to the first element of the array.

From the above example, it is clear that &x[0] is equivalent to x. And, x[0] is equivalent to *x.

Similarly,

&x[1] is equivalent to x+1 and x[1] is equivalent to *(x+1).
&x[2] is equivalent to x+2 and x[2] is equivalent to *(x+2).
...
Basically, &x[i] is equivalent to x+i and x[i] is equivalent to *(x+i).


Example 1: Pointers and Arrays
#include <stdio.h>
int main() {

  int i, x[6], sum = 0;

  printf("Enter 6 numbers: ");

  for(i = 0; i < 6; ++i) {
  // Equivalent to scanf("%d", &x[i]);
      scanf("%d", x+i);

  // Equivalent to sum += x[i]
      sum += *(x+i);
  }

  printf("Sum = %d", sum);

  return 0;
}

When you run the program, the output will be:
Enter 6 numbers: 
2
3
4
4
12
4
Sum = 29 

In most contexts, array names decay to pointers. In simple words, array names are converted to pointers. That's the reason why you can use pointers to access elements of arrays. However, you should remember that pointers and arrays are not the same.

There are a few cases where array names don't decay to pointers. To learn more, visit: When does array name doesn't decay into a pointer?

Example 2: Arrays and Pointers
#include <stdio.h>
int main() {

  int x[5] = {1, 2, 3, 4, 5};
  int* ptr;

  // ptr is assigned the address of the third element
  ptr = &x[2]; 

  printf("*ptr = %d \n", *ptr);   // 3
  printf("*(ptr+1) = %d \n", *(ptr+1)); // 4
  printf("*(ptr-1) = %d", *(ptr-1));  // 2

  return 0;
}
When you run the program, the output will be:

*ptr = 3 
*(ptr+1) = 4 
*(ptr-1) = 2
In this example, &x[2], the address of the third element, is assigned to the ptr pointer. Hence, 3 was displayed when we printed *ptr.

And, printing *(ptr+1) gives us the fourth element. Similarly, printing *(ptr-1) gives us the second element.



*/





//-------------------------------------------------------------------------------------------------------------------------------------------------------------
/*
STRING 

Strings are actually one-dimensional array of characters terminated by a null character '\0'. Thus a null-terminated string contains the characters that comprise the string followed by a null.

The following declaration and initialization create a string consisting of the word "Hello". To hold the null character at the end of the array, the size of the character array containing the string is one more than the number of characters in the word "Hello."

char greeting[6] = {'H', 'e', 'l', 'l', 'o', '\0'};
If you follow the rule of array initialization then you can write the above statement as follows 

char greeting[] = "Hello";





Actually, you do not place the null character at the end of a string constant. The C compiler automatically places the '\0' at the end of the string when it initializes the array. Let us try to print the above mentioned string 

Live Demo
#include <stdio.h>

int main () {

   char greeting[6] = {'H', 'e', 'l', 'l', 'o', '\0'};
   printf("Greeting message: %s\n", greeting );
   return 0;
}
When the above code is compiled and executed, it produces the following result 

Greeting message: Hello



Inicializando o valor de strings.
Vejamos alguns exemplos:

char nome_cliente[30] = "Fulano";
 
char nome_cliente[30] = {'F','u','l','a','n','o'};
Inicializando uma string sem definir o tamanho do vetor

char nome_cliente[] = "Fulano";
Neste caso, a quantidade de caracteres de armazenamento e calculada automaticamente de forma a ter a dimensao exata para conter a string que esta sendo atribuida.

Para armazenar "Fulano", sao necessarios 6 caracteres + 1 para o finalizador \0.

Entao podemos dizer que

char nome_cliente[] = "Fulano";
equivale a declarar

char nome_cliente[7] = "Fulano";





Lendo uma string em C
Usando scanf

A funcao scanf permite fazer leitura de strings usando %s.

Em relacao ao uso de scanf para armazenar string devemos observar duas coisas:

A funcao scanf realiza a leitura ate encontrar um espaco, depois encerra a leitura e coloca o caracter terminador \0.
A variavel que vai armazenar a string nao necessita ser precedida por &.
Exemplo de utilizacao do scanf:

scanf("%s",nome);

Exemplo: Usando scanf para receber uma string.

#include<stdio.h>

int main(void)
{
  char nome[61];
  
  printf("Digite seu nome: ");
  scanf("%s",nome);
  
  printf("O nome armazenado foi: %s", nome);
  
  return 0;
}




Funcao gets-(get string)

Esta funcao armazena tudo que foi digitado, inclusive os espacos, ate que a tecla ENTER seja pressionada.

Exemplo:

printf ("Digite o nome do cliente:");
gets(nome_cliente);

Exemplo de programa usando gets() para armazenar uma string

#include<stdio.h>
#include<conio.h>
int main(void)
{
  char nome[61];
  
  printf("Digite seu nome: ");
  gets(nome);
  
  printf("O nome armazenado foi: %s", nome);
  
  getch();
  return 0;
}




Observe que por definicao, uma string nada mais e do que um vetor de caracteres.

Podemos percorrer o vetor normalmente, usando as mesmas estrategias usadas para vetores de numeros.

Exemplo: percorrendo um vetor de char

#include <stdio.h>
#include <conio.h>
int main(void)
{
  int i;
  
  //declarando e atribuindo valores no vetor de char
        //texto[7] usa 6 caracteres uteis + 1 caracter para o finalizador
  char texto[7] = "string";
  
  printf("Valor da variavel texto = %s\n", texto);
  
  //Percorrendo o vetor de char e mostrando
  //cada elemento individualmente
  for (i=0; i<6; i++)
  {
    printf("Valor do elemento %d da string = %c\n",i, texto[i]);
  }
  
  getch();
  return 0;
}







Pointers with strings
We have used pointers with the array, functions, and primitive data types so far. However, pointers can be used to point to the strings. There are various advantages of using pointers to point strings. Let us consider the following example to access the string via the pointer.

#include<stdio.h>  
void main ()  
{  
    char s[11] = "javatpoint";  
    char *p = s; // pointer p is pointing to string s.   
    printf("%s",p); // the string javatpoint is printed if we print p.  
}  







strcpy
C strcpy()
The function prototype of strcpy() is:

char* strcpy(char* destination, const char* source);
The strcpy() function copies the string pointed by source (including the null character) to the destination.
The strcpy() function also returns the copied string.

The strcpy() function is defined in the string.h header file.

#include <stdio.h>
#include <string.h>

int main() {
  char str1[20] = "C programming";
  char str2[20];

  // copying str1 to str2
  strcpy(str2, str1);

  puts(str2); // C programming

  return 0;
}

Note: When you use strcpy(), the size of the destination string should be large enough to store the copied string. Otherwise, it may result in undefined behavior.


#include <stdio.h>
#include <string.h>

int main () {
   char src[40];
   char dest[100];
  
   memset(dest, '\0', sizeof(dest));
   strcpy(src, "This is tutorialspoint.com");
   strcpy(dest, src);

   printf("Final copied string : %s\n", dest);
   
   return(0);
}








strcmp
C strcmp()
The strcmp() compares two strings character by character. If the strings are equal, the function returns 0.

C strcmp() Prototype
The function prototype of strcmp() is:

int strcmp (const char* str1, const char* str2);

strcmp() Parameters
The function takes two parameters:

str1 - a string
str2 - a string


Return Value from strcmp()
Return Value	        Remarks
0	                    if strings are equal
>0	                    if the first non-matching character in str1 is greater (in ASCII) than that of str2.
<0	                    if the first non-matching character in str1 is lower (in ASCII) than that of str2.


Example: C strcmp() function
#include <stdio.h>
#include <string.h>

int main() {
  char str1[] = "abcd", str2[] = "abCd", str3[] = "abcd";
  int result;

  // comparing strings str1 and str2
  result = strcmp(str1, str2);
  printf("strcmp(str1, str2) = %d\n", result);

  // comparing strings str1 and str3
  result = strcmp(str1, str3);
  printf("strcmp(str1, str3) = %d\n", result);

  return 0;
}
Output

strcmp(str1, str2) = 1
strcmp(str1, str3) = 0
In the program,

strings str1 and str2 are not equal. Hence, the result is a non-zero integer.
strings str1 and str3 are equal. Hence, the result is 0.




#include <stdio.h>
#include <string.h>

int main () {
   char str1[15];
   char str2[15];
   int ret;


   strcpy(str1, "abcdef");
   strcpy(str2, "ABCDEF");

   ret = strcmp(str1, str2);

   if(ret < 0) {
      printf("str1 is less than str2");
   } else if(ret > 0) {
      printf("str2 is less than str1");
   } else {
      printf("str1 is equal to str2");
   }
   
   return(0);
}

#include <stdio.h>
#include <string.h>

int main ()
{
  char key[] = "apple";
  char buffer[80];
  do {
     printf ("Guess my favorite fruit? ");
     fflush (stdout);
     scanf ("%79s",buffer);
  } while (strcmp (key,buffer) != 0);
  puts ("Correct answer!");
  return 0;
}
 Edit & Run


Output:

Guess my favourite fruit? orange
Guess my favourite fruit? apple
Correct answer!





TEST 1: 

#include <stdio.h>
#include <string.h>

int main ()
{
  int result;
  char str1[] = "a";
  char str2[] = "b";

  // comparing strings str1 and str2
  result = strcmp(str1, str2);
  printf("strcmp(str1, str2) = %d\n", result);


  // comparing strings str2 and str1   
  result = strcmp(str2, str1);
  printf("strcmp(str2, str1) = %d\n", result);


  return 0;
}





*/


//-------------------------------------------------------------------------------------------------------------------------------------------------------------

/*
Passing by value, passing by reference in C






EXEMPLO 1: Pass by value
    void swap(int fistVariable, int secondVariable)
    {
    // create a temporary variable to hold one of the values to perform the swap
    int tempVariable;

    tempVariable = firstVariable;  // temporarily save the value of the first variable
    firstVariable = secondVariable;  // swap the vale of the first variable with the value of the second variable 
    secondVariable = tempVariable;  // put the value of the first variable into the second variable 

    return;
    }

    int main(void)
    {
    int a = 100;
    int b = 200;

    printf("before swap: value of a: %d \n", a);
    printf("before swap: value of b: %d \n", b);

    // call function to swap values
    swap(a, b);

    // check values outside the function after swap function is run
    printf("after swap: value of a: %d \n", a);
    printf("after swap: value of b: %d \n", b);

    return 0;

    }


EXEMPLO 2: Pass by reference
    void swap(int *pFirstVariable, int *pSecondVariable)
    {
    int temp;

    // using dereferenced pointers means the function is working with the values at the addresses that are passed in
    temp = *pFirstVariable;
    *pFirstVariable = *pSecondVariable;
    *pSecondVariable = temp;

    return;
    }

    int main(void)
    {
    int a = 100;
    int b = 200;

    printf("before swap: value of a: %d \n", a);
    printf("before swap: value of b: %d \n", b);

    // call the function to swap values, using the 'address of' operator to pass in the address of each variable
    swap(&a, &b);

    // check values outside the function after swap function is run
    printf("after swap: value of a: %d \n", a);
    printf("after swap: value of b: %d \n", b);

    return 0;

    }






reference: https://dev.to/mikkel250/passing-by-value-passing-by-reference-in-c-1acg
*/

//-------------------------------------------------------------------------------------------------------------------------------------------------------------

/*
PRINT

Format Specifiers for I/O

Data Type	                Format Specifier
int	                        %d
char	                    %c
float	                    %f
double	                    %lf
short int	                %hd
unsigned int	            %u
long int	                %li
long long int	            %lli
unsigned long int	        %lu
unsigned long long int	    %llu
signed char	                %c
unsigned char	            %c
long double	                %Lf


%x
imprime o conteudo da variavel com representacao hexadecimal sem sinal.

%p is for printing a pointer address.




refe: 
https://www.programiz.com/c-programming/c-input-output
*/






//-------------------------------------------------------------------------------------------------------------------------------------------------------------
/*
C - Structures

Arrays allow to define type of variables that can hold several data items of the same kind. Similarly structure is another user defined data type available in C that allows to combine data items of different kinds.

Structures are used to represent a record. Suppose you want to keep track of your books in a library. You might want to track the following attributes about each book −
Title
Author
Subject
Book ID

Defining a Structure
To define a structure, you must use the struct statement. The struct statement defines a new data type, with more than one member. The format of the struct statement is as follows −

struct [structure tag] {

   member definition;
   member definition;
   ...
   member definition;
} [one or more structure variables]; 

The structure tag is optional and each member definition is a normal variable definition, such as int i; or float f; or any other valid variable definition. At the end of the structure's definition, before the final semicolon, you can specify one or more structure variables but it is optional. Here is the way you would declare the Book structure −

struct Books {
   char  title[50];
   char  author[50];
   char  subject[100];
   int   book_id;
} book;  


Accessing Structure Members
To access any member of a structure, we use the member access operator (.). The member access operator is coded as a period between the structure variable name and the structure member that we wish to access. You would use the keyword struct to define variables of structure type. The following example shows how to use a structure in a program −


#include <stdio.h>
#include <string.h>
 
struct Books {
   char  title[50];
   char  author[50];
   char  subject[100];
   int   book_id;
};
 
int main( ) {

   struct Books Book1;        // Declare Book1 of type Book //
   struct Books Book2;        //Declare Book2 of type Book //
 
   // book 1 specification //
   strcpy( Book1.title, "C Programming");
   strcpy( Book1.author, "Nuha Ali"); 
   strcpy( Book1.subject, "C Programming Tutorial");
   Book1.book_id = 6495407;

   // book 2 specification //
   strcpy( Book2.title, "Telecom Billing");
   strcpy( Book2.author, "Zara Ali");
   strcpy( Book2.subject, "Telecom Billing Tutorial");
   Book2.book_id = 6495700;
 
   // print Book1 info //
   printf( "Book 1 title : %s\n", Book1.title);
   printf( "Book 1 author : %s\n", Book1.author);
   printf( "Book 1 subject : %s\n", Book1.subject);
   printf( "Book 1 book_id : %d\n", Book1.book_id);

  // print Book2 info //
   printf( "Book 2 title : %s\n", Book2.title);
   printf( "Book 2 author : %s\n", Book2.author);
   printf( "Book 2 subject : %s\n", Book2.subject);
   printf( "Book 2 book_id : %d\n", Book2.book_id);

   return 0;
}



Structures as Function Arguments
You can pass a structure as a function argument in the same way as you pass any other variable or pointer.

#include <stdio.h>
#include <string.h>
 
struct Books {
   char  title[50];
   char  author[50];
   char  subject[100];
   int   book_id;
};

// function declaration //
void printBook( struct Books book );

int main( ) {

   struct Books Book1;        // Declare Book1 of type Book //
   struct Books Book2;        // Declare Book2 of type Book //
 
   // book 1 specification //
   strcpy( Book1.title, "C Programming");
   strcpy( Book1.author, "Nuha Ali"); 
   strcpy( Book1.subject, "C Programming Tutorial");
   Book1.book_id = 6495407;

   // book 2 specification //
   strcpy( Book2.title, "Telecom Billing");
   strcpy( Book2.author, "Zara Ali");
   strcpy( Book2.subject, "Telecom Billing Tutorial");
   Book2.book_id = 6495700;
 
   // print Book1 info //
   printBook( Book1 );

   // Print Book2 info //
   printBook( Book2 );

   return 0;
}

void printBook( struct Books book ) {

   printf( "Book title : %s\n", book.title);
   printf( "Book author : %s\n", book.author);
   printf( "Book subject : %s\n", book.subject);
   printf( "Book book_id : %d\n", book.book_id);
}



Pointers to Structures
You can define pointers to structures in the same way as you define pointer to any other variable −

struct Books *struct_pointer;

Now, you can store the address of a structure variable in the above defined pointer variable. To find the address of a structure variable, place the '&'; operator before the structure's name as follows −
struct_pointer = &Book1;


To access the members of a structure using a pointer to that structure, you must use the → operator as follows −
struct_pointer->title;

#include <stdio.h>
#include <string.h>
 
struct Books {
   char  title[50];
   char  author[50];
   char  subject[100];
   int   book_id;
};

// function declaration //
void printBook( struct Books *book );
int main( ) {

   struct Books Book1;        // Declare Book1 of type Book //
   struct Books Book2;        // Declare Book2 of type Book //
 
   // book 1 specification //
   strcpy( Book1.title, "C Programming");
   strcpy( Book1.author, "Nuha Ali"); 
   strcpy( Book1.subject, "C Programming Tutorial");
   Book1.book_id = 6495407;

   // book 2 specification //
   strcpy( Book2.title, "Telecom Billing");
   strcpy( Book2.author, "Zara Ali");
   strcpy( Book2.subject, "Telecom Billing Tutorial");
   Book2.book_id = 6495700;
 
   // print Book1 info by passing address of Book1 //
   printBook( &Book1 );

   // print Book2 info by passing address of Book2 //
   printBook( &Book2 );

   return 0;
}

void printBook( struct Books *book ) {

   printf( "Book title : %s\n", book->title);
   printf( "Book author : %s\n", book->author);
   printf( "Book subject : %s\n", book->subject);
   printf( "Book book_id : %d\n", book->book_id);
}




REFE: https://www.tutorialspoint.com/cprogramming/c_structures.htm
https://www.inf.pucrs.br/~pinho/LaproI/Structs/Structs.htm

Uso de Estruturas de Dados Heterogêneas

Structs, também conhecidas como Registros, definem tipos de dados que agrupam variáveis sob um mesmo tipo de dado.

A ideia de usar uma struct é permitir que, ao armazenar os dados de uma mesma entidade, isto possa ser feito com uma única variável. Por exemplo, se for preciso armazenar a altura, o peso e a idade de uma pessoa, pode-se criar uma struct chamada Pessoa e agrupar os dados em um único tipo de dado, conforme o exemplo a seguir.

Aos dados agruados em uma struct dá-se o nome de campos(fields).

typedef struct // Cria uma STRUCT para armazenar os dados de uma pessoa
{
    float Peso;   // define o campo Peso
    int Idade;    // define o campo Idade
    float Altura; // define o campo Altura
} Pessoa; // Define o nome do novo tipo criado
Após a criação do tipo, é possivel declarar variáveis do tipo Pessoa, desta forma:

Pessoa Joao, P1, P2;
Pessoa Povo[10];  // cria um vetor de 10 pessoas.
Para acessar os campos de uma struct, usa-se a sintaxe  NomeDaVariavel.NomeDoCampo, conforme o exemplo a seguir.

Joao.Idade = 15;
Joao.Peso = 60.5;
Joao.Altura = 1.75;

Povo[4].Idade = 23;
Povo[4].Peso = 75.3;
Povo[4].Altura = 1.89;

Outra vantagem de utilizar struct é a possibilidade de atribuir os dados de uma struct para outra, com apenas um comando de atribuição, como neste exemplo:

P2 = Povo[4];


Passagem de Structs por Parâmetro

Para passar uma struct por valor basta declará-la como um dos parâmetros, como no exemplo a seguir

#include <stdio.h>

typedef struct // Cria uma STRUCT para armazenar os dados de uma pessoa
{
    float Peso;   // define o campo Peso
    int Idade;    // define o campo Idade
    float Altura; // define o campo Altura
} Pessoa; // Define o nome do novo tipo criado

void ImprimePessoa(Pessoa P) // declara o parâmetro como uma struct
{
  printf("Idade: %d  Peso: %f Altura: %f\n", P.Idade, P.Peso, P.Altura);
}

int main()
{
    Pessoa Joao, P2;
    Pessoa Povo[10];

    Joao.Idade = 15;
    Joao.Peso = 60.5;
    Joao.Altura = 1.75;

    Povo[4].Idade = 23;
    Povo[4].Peso = 75.3;
    Povo[4].Altura = 1.89;

    P2 = Povo[4];
           P2.Idade++;

    // chama a função que recebe a struct como parâmetro
    ImprimePessoa(Joao);
    ImprimePessoa(Povo[4]);
    ImprimePessoa(P2);
   return 0;
}

Retorno de Structs em Funções

Como uma struct define um tipo de dado, este tipo pode ser retornado em uma função, da mesma forma que ocorre com qualquer outro tipo de dado.
No exemplo a seguir, a função retorna uma struct que conterá, em seus campos, os dados que foram recebidos por parâmetro.

#include <stdio.h>

typedef struct // Cria uma STRUCT para armazenar os dados de uma pessoa
{
    float Peso;   // define o campo Peso
    int Idade;    // define o campo Idade
    float Altura; // define o campo Altura
} Pessoa; // Define o nome do novo tipo criado

Pessoa SetPessoa(int idade, float peso, float altura)
{ 
    Pessoa P;
    P.Idade = idade; 
    P.Peso = peso;   
    P.Altura = altura;
    return P; // retorna a struct contendo os dados passados por parâmetro
}
void ImprimePessoa(Pessoa P) // declara o parâmetro como uma struct
{
  printf("Idade: %d  Peso: %f Altura: %f\n", P.Idade, P.Peso, P.Altura);
}


int main()
{
    Pessoa Joao;

    Joao = SetPessoa(15,60.5,1.75); // atribui o retorno da função a uma variável struct
    ImprimePessoa(Joao);
   return 0;
}

Sugere-se, antes da leitura das próximas seções, a consulta à página sobre ponteiros.
Passagem de Structs por Referência

Para passar uma struct por referência, deve-se passar um ponteiro para a struct, como no exemplo a seguir.

#include <stdio.h>

typedef struct // Cria uma STRUCT para armazenar os dados de uma pessoa
{
    float Peso;   // define o campo Peso
    int Idade;    // define o campo Idade
    float Altura; // define o campo Altura
} Pessoa; // Define o nome do novo tipo criado

void ImprimePessoa(Pessoa P)
{
  printf("Idade: %d  Peso: %f Altura: %f\n", P.Idade, P.Peso, P.Altura);
}

void SetPessoa(Pessoa *P, int idade, float peso, float altura)
{ // Nesta função o parâmetro P é um ponteiro para uma struct
    (*P).Idade = idade;  // o campo pode ser acessado desta forma
    P->Peso = peso;      // ou desta
    P->Altura = altura;
}
   
int main()
{
    Pessoa Joao;
    SetPessoa(&Joao, 15, 70.5, 1.75);
    ImprimePessoa(Joao);

    return 0;
}

*/




/*
my tests 1: 



#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//constant
#define max 10

//struct
struct nick
{
char a[10];
};


int main()
{
    struct nick name[max];

    strcpy("pedro akira",name[1].a );

    printf("%s ", name[1].a);



    return 0;
}




*/


//-------------------------------------------------------------------------------------------------------------------------------------------------------------

/*
FILE 

C Files I/O: Create, Open, Read, Write and Close a File

C File management
A File can be used to store a large volume of persistent data. Like many other languages 'C' provides following file management functions,

Creation of a file
Opening a file
Reading a file
Writing to a file
Closing a file

Following are the most important file management functions available in 'C'
function	purpose	
fopen ()	Creating a file or opening an existing file
fclose ()	Closing a file
fprintf ()	Writing a block of data to a file
fscanf ()	Reading a block data from a file
getc ()	    Reads a single character from a file
putc ()	    Writes a single character to a file
getw ()	    Reads an integer from a file
putw ()	    Writing an integer to a file
fseek ()	Sets the position of a file pointer to a specified location
ftell ()	Returns the current position of a file pointer
rewind ()	Sets the file pointer at the beginning of a file

How to Create a File
Whenever you want to work with a file, the first step is to create a file. A file is nothing but space in a memory where data is stored.

To create a file in a C program following syntax is used,

FILE *fp;
fp = fopen ("file_name", "mode");

In the above syntax, the file is a data structure which is defined in the standard library.

fopen is a standard function which is used to open a file.

If the file is not present on the system, then it is created and then opened.
If a file is already present on the system, then it is directly opened using this function.
fp is a file pointer which points to the type file.

Whenever you open or create a file, you have to specify what you are going to do with the file. A file in ‘C’ programming can be created or opened for reading/writing purposes. A mode is used to specify whether you want to open a file for any of the below-given purposes. Following are the different types of modes in ‘C’ programming which can be used while working with a file.

File Mode	Description
r	Open a file for reading. If a file is in reading mode, then no data is deleted if a file is already present on a system.
w	Open a file for writing. If a file is in writing mode, then a new file is created if a file doesn’t exist at all. If a file is already present on a system, then all the data inside the file is truncated, and it is opened for writing purposes.
a	Open a file in append mode. If a file is in append mode, then the file is opened. The content within the file doesn’t change.
r+	open for reading and writing from beginning
w+	open for reading and writing, overwriting a file
a+	open for reading and writing, appending to file

In the given syntax, the filename and the mode are specified as strings hence they must always be enclosed within double quotes.

Example:

#include <stdio.h>
int main() {
FILE *fp;
fp  = fopen ("data.txt", "w");
}


How to Close a file

    One should always close a file whenever the operations on file are over. It means the contents and links to the file are terminated. This prevents accidental damage to the file.

    ‘C’ provides the fclose function to perform file closing operation. The syntax of fclose is as follows,

    fclose (file_pointer);
    Example:

    FILE *fp;
    fp  = fopen ("data.txt", "r");
    fclose (fp);

    The fclose function takes a file pointer as an argument. The file associated with the file pointer is then closed with the help of fclose function. It returns 0 if close was successful and EOF (end of file) if there is an error has occurred while file closing.

    After closing the file, the same file pointer can also be used with other files.

    In ‘C’ programming, files are automatically close when the program is terminated. Closing a file manually by writing fclose function is a good programming practice.


Writing to a File
    In C, when you write to a file, newline characters ‘\n’ must be explicitly added.

    The stdio library offers the necessary functions to write to a file:

    fputc(char, file_pointer): It writes a character to the file pointed to by file_pointer.
    fputs(str, file_pointer): It writes a string to the file pointed to by file_pointer.
    fprintf(file_pointer, str, variable_lists): It prints a string to the file pointed to by file_pointer. The string can optionally include format specifiers and a list of variables variable_lists.


The program below shows how to perform writing to a file:

#include <stdio.h>
int main() {
        int i;
        FILE * fptr;
        char fn[50];
        char str[] = "Guru99 Rocks\n";
        fptr = fopen("fputc_test.txt", "w"); // "w" defines "writing mode"
        for (i = 0; str[i] != '\n'; i++) {
            // write to file using fputc() function //
            fputc(str[i], fptr);
        }
        fclose(fptr);
        return 0;
    }




The above program writes a single character into the fputc_test.txt file until it reaches the next line symbol “\n” which indicates that the sentence was successfully written. The process is to take each character of the array and write it into the file.

In the above program, we have created and opened a file called fputc_test.txt in a write mode and declare our string which will be written into the file.
We do a character by character write operation using for loop and put each character in our file until the “\n” character is encountered then the file is closed using the fclose function.




fputs () Function:
    #include <stdio.h>
    int main() {
            FILE * fp;
            fp = fopen("fputs_test.txt", "w+");
            fputs("This is Guru99 Tutorial on fputs,", fp);
            fputs("We don't need to use for loop\n", fp);
            fputs("Easier than fputc function\n", fp);
            fclose(fp);
            return (0);
        }




fprintf()Function:
#include <stdio.h>
    int main() {
        FILE *fptr;
        fptr = fopen("fprintf_test.txt", "w"); // "w" defines "writing mode"
        // write to file //
        fprintf(fptr, "Learning C with Guru99\n");
        fclose(fptr);
        return 0;
    }


In the above program we have created and opened a file called fprintf_test.txt in a write mode.
After a write operation is performed using fprintf() function by writing a string, then the file is closed using the fclose function.




Reading data from a File
There are three different functions dedicated to reading data from a file

fgetc(file_pointer): It returns the next character from the file pointed to by the file pointer. When the end of the file has been reached, the EOF is sent back.
fgets(buffer, n, file_pointer): It reads n-1 characters from the file and stores the string in a buffer in which the NULL character ‘\0’ is appended as the last character.
fscanf(file_pointer, conversion_specifiers, variable_adresses): It is used to parse and analyze data. It reads characters from the file and assigns the input to a list of variable pointers variable_adresses using conversion specifiers. Keep in mind that as with scanf, fscanf stops reading a string when space or newline is encountered.


The following program demonstrates reading from fputs_test.txt file using fgets(),fscanf() and fgetc () functions respectively :

#include <stdio.h>
int main() {
        FILE * file_pointer;
        char buffer[30], c;

        file_pointer = fopen("fprintf_test.txt", "r");
        printf("----read a line----\n");
        fgets(buffer, 50, file_pointer);
        printf("%s\n", buffer);

        printf("----read and parse data----\n");
        file_pointer = fopen("fprintf_test.txt", "r"); //reset the pointer
        char str1[10], str2[2], str3[20], str4[2];
        fscanf(file_pointer, "%s %s %s %s", str1, str2, str3, str4);
        printf("Read String1 |%s|\n", str1);
        printf("Read String2 |%s|\n", str2);
        printf("Read String3 |%s|\n", str3);
        printf("Read String4 |%s|\n", str4);

        printf("----read the entire file----\n");

        file_pointer = fopen("fprintf_test.txt", "r"); //reset the pointer
        while ((c = getc(file_pointer)) != EOF) printf("%c", c);

        fclose(file_pointer);
        return 0;
    }



Interactive File Read and Write with getc and putc

These are the simplest file operations. Getc stands for get character, and putc stands for put character. These two functions are used to handle only a single character at a time.

Following program demonstrates the file handling functions in ‘C’ programming:


#include <stdio.h>
int main() {
        FILE * fp;
        char c;
        printf("File Handling\n");
        //open a file
        fp = fopen("demo.txt", "w");
        //writing operation
        while ((c = getchar()) != EOF) {
            putc(c, fp);
        }
        //close file
        fclose(fp);
        printf("Data Entered:\n");
        //reading
        fp = fopen("demo.txt", "r");
        while ((c = getc(fp)) != EOF) {
            printf("%c", c);
        }
        fclose(fp);
        return 0;
    }



references: 
https://www.guru99.com/c-file-input-output.html
*/


/*
TEST 1:



#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    char fname[10];
    FILE *fp;

    printf("Enter the filename : ");
    scanf("%s",fname);    

    fp=fopen(fname,"w"); //create a file 
    fclose(fp);

    return 0;
}


#include <stdio.h>
    int main() {
    FILE *fp;
    fp  = fopen ("data.txt", "w");
}

#include <stdio.h>
    int main() {
    FILE *fp;
    fp  = fopen ("D://data.txt", "w");
}




*/




/*
TEST2 

//CREATE A FILE 

    #include <stdio.h>
    #include <string.h>
    #include <stdlib.h>

    int main()
    {
        char fname[10];
        FILE *fp;

        printf("Enter the filename : ");
        scanf("%s",fname);    

        fp=fopen(fname,"w"); //create a file 
        fclose(fp);

        return 0;
    }


//Writing to a File
    //fputc() Function:
    #include <stdio.h>
    int main() {
            int i;
            FILE * fptr;
            char fn[50];
            char str[] = "Guru99 Rocks\n";
            fptr = fopen("fputc_test.txt", "w"); // "w" defines "writing mode"
            for (i = 0; str[i] != '\n'; i++) {
                // write to file using fputc() function //
                fputc(str[i], fptr);
            }
            fclose(fptr);
            return 0;
        }    


    //fputs () Function:
    #include <stdio.h>
    int main() {
            FILE * fp;
            fp = fopen("fputs_test.txt", "w+");
            fputs("This is Guru99 Tutorial on fputs,", fp);
            fputs("We don't need to use for loop\n", fp);
            fputs("Easier than fputc function\n", fp);
            fclose(fp);
            return (0);
        }

    //fprintf()Function:
    #include <stdio.h>
        int main() {
            FILE *fptr;
            fptr = fopen("fprintf_test.txt", "w"); // "w" defines "writing mode"
            // write to file //
            fprintf(fptr, "Learning C with Guru99\n");
            fclose(fptr);
            return 0;
        }


    //Reading data from a File
    #include <stdio.h>
    int main() {
            FILE * file_pointer;
            char buffer[30], c;

            file_pointer = fopen("fprintf_test.txt", "r");
            printf("----read a line----\n");
            fgets(buffer, 50, file_pointer);
            printf("%s\n", buffer);

            printf("----read and parse data----\n");
            file_pointer = fopen("fprintf_test.txt", "r"); //reset the pointer
            char str1[10], str2[2], str3[20], str4[2];
            fscanf(file_pointer, "%s %s %s %s", str1, str2, str3, str4);
            printf("Read String1 |%s|\n", str1);
            printf("Read String2 |%s|\n", str2);
            printf("Read String3 |%s|\n", str3);
            printf("Read String4 |%s|\n", str4);

            printf("----read the entire file----\n");

            file_pointer = fopen("fprintf_test.txt", "r"); //reset the pointer
            while ((c = getc(file_pointer)) != EOF) printf("%c", c);

            fclose(file_pointer);
            return 0;
        }



*/




/*
CARACTERES 


\n -> next line 
EOF -> end of file 
NULL or \0 -> 

*/





//-------------------------------------------------------------------------------------------------------------------------------------------------------------

/*scanf vs gets


The main difference between them is:

scanf() reads input until it encounters whitespace, newline or End Of File(EOF) whereas 
gets() reads input until it encounters newline or End Of File(EOF), gets() does not stop reading input when it encounters whitespace instead it takes whitespace as a string.
scanf can read multiple values of different data types whereas gets() will only get character string data.

*/




//-------------------------------------------------------------------------------------------------------------------------------------------------------------


/*

malloc

How to use "malloc" in C

Memory allocation (malloc), is an in-built function in C. This function is used to assign a specified amount of memory for an array to be created. It also returns a pointer to the space allocated in memory using this function.

The need for malloc
In the world of programming where every space counts, there are numerous times when we only want an array to have a specific amount of space at run time. That is, we want to create an array occupying a particular amount of space, dynamically. We do this using malloc.

Syntax
We know what malloc returns and we know what it requires as an input, but how does the syntax of the function work. The illustration below shows that:


Note: malloc will return NULL if the memory specified is not available and hence, the allocation has failed













exemplo 1:



#include <stdio.h>
#include <stdlib.h>

int main()
{

	// This pointer will hold the
	// base address of the block created
	int* ptr;
	int n, i;

	// Get the number of elements for the array
	printf("Enter number of elements:");
	scanf("%d",&n);
	printf("Entered number of elements: %d\n", n);

	// Dynamically allocate memory using malloc()
	ptr = (int*)malloc(n * sizeof(int));

	// Check if the memory has been successfully
	// allocated by malloc or not
	if (ptr == NULL) {
		printf("Memory not allocated.\n");
		exit(0);
	}
	else {

		// Memory has been successfully allocated
		printf("Memory successfully allocated using malloc.\n");

		// Get the elements of the array
		for (i = 0; i < n; ++i) {
			ptr[i] = i + 1;
		}

		// Print the elements of the array
		printf("The elements of the array are: ");
		for (i = 0; i < n; ++i) {
			printf("%d, ", ptr[i]);
		}
	}

	return 0;
}




exemplo 2:

#include <stdio.h>
#include <stdlib.h>

int main()
{

	// This pointer will hold the
	// base address of the block created
	int* ptr;
	int n, i;

	// Get the number of elements for the array
	printf("Enter number of elements:");
	scanf("%d",&n);
	printf("Entered number of elements: %d\n", n);

	// Dynamically allocate memory using malloc()
	ptr = (int*)malloc(n * sizeof(int));

	// Check if the memory has been successfully
	// allocated by malloc or not
	if (ptr == NULL) {
		printf("Memory not allocated.\n");
		exit(0);
	}
	else {

		// Memory has been successfully allocated
		printf("Memory successfully allocated using malloc.\n");

		// Get the elements of the array
		for (i = 0; i < n; ++i) {
			ptr[i] = i + 1;
		}

		// Print the elements of the array
		//printf("The elements of the array are: ");
		//for (i = 0; i < n; ++i) {
		//	printf("%d, ", ptr[i]);
		//}



	}

	return 0;
}



*/





/*
malloc 

Dynamic Memory Allocation in C using malloc(), calloc(), free() and realloc()

Since C is a structured language, it has some fixed rules for programming. One of them includes changing the size of an array. An array is a collection of items stored at contiguous memory locations. 

As it can be seen that the length (size) of the array above made is 9. But what if there is a requirement to change this length (size). For Example, 

As it can be seen that the length (size) of the array above made is 9. But what if there is a requirement to change this length (size). For Example, 

If there is a situation where only 5 elements are needed to be entered in this array. In this case, the remaining 4 indices are just wasting memory in this array. So there is a requirement to lessen the length (size) of the array from 9 to 5.
Take another situation. In this, there is an array of 9 elements with all 9 indices filled. But there is a need to enter 3 more elements in this array. In this case, 3 indices more are required. So the length (size) of the array needs to be changed from 9 to 12.

This procedure is referred to as Dynamic Memory Allocation in C.
Therefore, C Dynamic Memory Allocation can be defined as a procedure in which the size of a data structure (like Array) is changed during the runtime.
C provides some functions to achieve these tasks. There are 4 library functions provided by C defined under <stdlib.h> header file to facilitate dynamic memory allocation in C programming. They are: 

malloc()
calloc()
free()
realloc()



C malloc() method
The “malloc” or “memory allocation” method in C is used to dynamically allocate a single large block of memory with the specified size. It returns a pointer of type void which can be cast into a pointer of any form. It doesn’t Initialize memory at execution time so that it has initialized each block with the default garbage value initially. 

Syntax: 

ptr = (cast-type*) malloc(byte-size)
For Example:
ptr = (int*) malloc(100 * sizeof(int));
Since the size of int is 4 bytes, this statement will allocate 400 bytes of memory. And, the pointer ptr holds the address of the first byte in the allocated memory.


C calloc() method
“calloc” or “contiguous allocation” method in C is used to dynamically allocate the specified number of blocks of memory of the specified type. it is very much similar to malloc() but has two different points and these are:
It initializes each block with a default value ‘0’.
It has two parameters or arguments as compare to malloc().

Syntax: 

ptr = (cast-type*)calloc(n, element-size);
here, n is the no. of elements and element-size is the size of each element.
For Example: 

ptr = (float*) calloc(25, sizeof(float));
This statement allocates contiguous space in memory for 25 elements each with the size of the float.




C free() method
“free” method in C is used to dynamically de-allocate the memory. The memory allocated using functions malloc() and calloc() is not de-allocated on their own. Hence the free() method is used, whenever the dynamic memory allocation takes place. It helps to reduce wastage of memory by freeing it.

Syntax: 

free(ptr);










C realloc() method
“realloc” or “re-allocation” method in C is used to dynamically change the memory allocation of a previously allocated memory. In other words, if the memory previously allocated with the help of malloc or calloc is insufficient, realloc can be used to dynamically re-allocate memory. re-allocation of memory maintains the already present value and new blocks will be initialized with the default garbage value.

Syntax: 

ptr = realloc(ptr, newSize);

where ptr is reallocated with new size 'newSize'.

If space is insufficient, allocation fails and returns a NULL pointer.

Exemplo: 


#include <stdio.h>
#include <stdlib.h>
 
int main()
{
 
    // This pointer will hold the
    // base address of the block created
    int* ptr;
    int n, i;
 
    // Get the number of elements for the array
    n = 5;
    printf("Enter number of elements: %d\n", n);
 
    // Dynamically allocate memory using calloc()
    ptr = (int*)calloc(n, sizeof(int));
 
    // Check if the memory has been successfully
    // allocated by malloc or not
    if (ptr == NULL) {
        printf("Memory not allocated.\n");
        exit(0);
    }
    else {
 
        // Memory has been successfully allocated
        printf("Memory successfully allocated using calloc.\n");
 
        // Get the elements of the array
        for (i = 0; i < n; ++i) {
            ptr[i] = i + 1;
        }
 
        // Print the elements of the array
        printf("The elements of the array are: ");
        for (i = 0; i < n; ++i) {
            printf("%d, ", ptr[i]);
        }
 
        // Get the new size for the array
        n = 10;
        printf("\n\nEnter the new size of the array: %d\n", n);
 
        // Dynamically re-allocate memory using realloc()
        ptr = realloc(ptr, n * sizeof(int));
 
        // Memory has been successfully allocated
        printf("Memory successfully re-allocated using realloc.\n");
 
        // Get the new elements of the array
        for (i = 5; i < n; ++i) {
            ptr[i] = i + 1;
        }
 
        // Print the elements of the array
        printf("The elements of the array are: ");
        for (i = 0; i < n; ++i) {
            printf("%d, ", ptr[i]);
        }
 
        free(ptr);
    }
 
    return 0;
}



another exemplo:


#include <stdio.h>
#include <stdlib.h>
int main()
{
    int index = 0, i = 0, n,
        *marks; // this marks pointer hold the base address
                // of  the block created
    int ans;
    marks = (int*)malloc(sizeof(
        int)); // dynamically allocate memory using malloc
    // check if the memory is successfully allocated by
    // malloc or not?
    if (marks == NULL) {
        printf("memory cannot be allocated");
    }
    else {
        // memory has successfully allocated
        printf("Memory has been successfully allocated by "
               "using malloc\n");
        printf("\n marks = %pc\n",
               marks); // print the base or beginning
                       // address of allocated memory
        do {
            printf("\n Enter Marks\n");
            scanf("%d", &marks[index]); // Get the marks
            printf("would you like to add more(1/0): ");
            scanf("%d", &ans);
 
            if (ans == 1) {
                index++;
                marks = (int*)realloc(
                    marks,
                    (index + 1)
                        * sizeof(
                            int)); // Dynamically reallocate
                                   // memory by using realloc
                // check if the memory is successfully
                // allocated by realloc or not?
                if (marks == NULL) {
                    printf("memory cannot be allocated");
                }
                else {
                    printf("Memory has been successfully "
                           "reallocated using realloc:\n");
                    printf(
                        "\n base address of marks are:%pc",
                        marks); ////print the base or
                                ///beginning address of
                                ///allocated memory
                }
            }
        } while (ans == 1);
        // print the marks of the students
        for (i = 0; i <= index; i++) {
            printf("marks of students %d are: %d\n ", i,
                   marks[i]);
        }
        free(marks);
    }
    return 0;
}




*/









/*
Difference Between malloc() and calloc() with Examples


The functions malloc() and calloc() are library functions that allocate memory dynamically. Dynamic means the memory is allocated during runtime (execution of the program) from the heap segment.

Initialization
malloc() allocates a memory block of given size (in bytes) and returns a pointer to the beginning of the block. malloc() doesn’t initialize the allocated memory. If you try to read from the allocated memory without first initializing it, then you will invoke undefined behavior, which will usually mean the values you read will be garbage.

calloc() allocates the memory and also initializes every byte in the allocated memory to 0. If you try to read the value of the allocated memory without initializing it, you’ll get 0 as it has already been initialized to 0 by calloc().

Parameters
malloc() takes a single argument, which is the number of bytes to allocate.

Unlike malloc(), calloc() takes two arguments: 
1) Number of blocks to be allocated. 
2) Size of each block in bytes.

Return Value
After successful allocation in malloc() and calloc(), a pointer to the block of memory is returned otherwise NULL is returned which indicates failure. 

Example

#include <stdio.h>
#include <stdlib.h>
 
int main()
{
    // Both of these allocate the same number of bytes,
    // which is the amount of bytes that is required to
    // store 5 int values.
 
    // The memory allocated by calloc will be
    // zero-initialized, but the memory allocated with
    // malloc will be uninitialized so reading it would be
    // undefined behavior.
    int* allocated_with_malloc = malloc(5 * sizeof(int));
    int* allocated_with_calloc = calloc(5, sizeof(int));
 
    // As you can see, all of the values are initialized to
    // zero.
      printf("Values of allocated_with_calloc: ");
    for (size_t i = 0; i < 5; ++i) {
        printf("%d ", allocated_with_calloc[i]);
    }
    putchar('\n');
 
    // This malloc requests 1 terabyte of dynamic memory,
    // which is unavailable in this case, and so the
    // allocation fails and returns NULL.
    int* failed_malloc = malloc(1000000000000);
    if (failed_malloc == NULL) {
        printf("The allocation failed, the value of "
               "failed_malloc is: %p",
               (void*)failed_malloc);
    }
 
    // Remember to always free dynamically allocated memory.
    free(allocated_with_malloc);
    free(allocated_with_calloc);
}
Output
Values of allocated_with_calloc: 0 0 0 0 0 
The allocation failed, the value of failed_malloc is: (nil)

*/






/*
what happens when you don’t free memory after using malloc()


The “malloc” or “memory allocation” method is used to dynamically allocate a single large block of memory with the specified size. It returns a pointer of type void which can be cast into a pointer of any form. It initializes each block with a default garbage value.



*/







/*
Difference between Static and Dynamic Memory Allocation in C

Memory Allocation: Memory allocation is a process by which computer programs and services are assigned with physical or virtual memory space. The memory allocation is done either before or at the time of program execution. There are two types of memory allocations: 







*/






//-------------------------------------------------------------------------------------------------------------------------------------------------------------

/*
Sizeof operator in C




#include <stdio.h>
int main() {
int a = 16;
   printf("Size of variable a : %d\n",sizeof(a));
   printf("Size of int data type : %d\n",sizeof(int));
   printf("Size of char data type : %d\n",sizeof(char));
   printf("Size of float data type : %d\n",sizeof(float));
   printf("Size of double data type : %d\n",sizeof(double));
   return 0;
}

*/





//-------------------------------------------------------------------------------------------------------------------------------------------------------------

/*
COMPILE:

ulimit -a
ulimit -s 819200


apt-get install gcc
echo "" > explainC.c 
vi explainC.c 

gcc explainC.c  -o explainC.exe
./explainC.exe


REFE: 


*/
//-------------------------------------------------------------------------------------------------------------------------------------------------------------


