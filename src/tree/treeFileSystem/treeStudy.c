





//----------------------------------------------------------------------

/*
STUDY HEARDER FILE 





Header files in C


  What are those mysterious include statements at the beginning of most C programs? What are header files and why do we need them? In this article we'll answer these questions thoroughly with interesting examples, so buckle up!

  We'll also see how they add some modularity to projects, make compilation fast, and help introduce some data abstraction.


  Scope
  Header Files are just .h files that inform the compiler about the existence of functions, macros, etc. that exist in other C files in your project.
  We'll begin by going through a small example, which will give us an idea of why header files are needed in the first place.
  Then, we'll cover the needed syntax, along with the #include directive.
  We'll then explore the 2 types of header files - System Header files and User Defined Header files.
  Finally, we'll conclude with the concept of Once Only Headers, which can be used to prevent multiple definitions and make life easier!



  Introduction
  Most large scale projects cannot fit in one file. This is mostly because after a certain point, code becomes hard to read and maintain.

  Splitting the source code into multiple files makes it modular and portable. For example, if we’re working on GUI elements, then the navigation bar’s source code can be placed in a file called navbar.c, and can be included wherever needed. Or, if we are writing math functions that can be used in other files, we can place all these functions in mathematics.c and then include them when needed.

  During compilation, the linker puts together source code from multiple files and converts the whole project to a single executable file. It is at this stage that header files inform the linker about various function definitions, macros, etc. which have to be included.





  Making our own headerfile
  The following example shows how you can compile 2 program files into one. We’re trying to write out own mathematics module which can be used in future projects with ease.


  In the mathematics.c file, we'll define a function isPrime which returns true if a function is prime and false otherwise. We're using the root(N) approach here.

  #include <stdbool.h>

  bool isPrime(int n) {
      for (int i = 2; i * i < n + 1; i++) {
          if (n % i == 0) {
              return false;
          }
      }
      return true;
  }


  In the app.c file, we'll write the code that takes an integer as input and uses the isPrime function defined in mathematics.c to give us the appropriate output.

  #include <stdio.h>
  #include <stdbool.h>

  bool isPrime(int n);

  int main() {
      printf("Prime Number Check!\n");

      int n;
      printf("Enter a number: ");
      scanf("%d", &n);
      
      if (isPrime(n)) {
          printf("The number is prime!\n");
      } else {
          printf("The number is composite\n");
      }

      return 0;
  }




  Note: Make sure that both the files are in the same folder!




  Depending on your operating system and C compiler, the command for compiling both the files will be slightly different. For windows, with gcc, it is,


  gcc .\app.c .\mathematics.c -o app

  Now we can run the following executable using the following command,
  .\app.exe


  Code Output:

  Prime Number Check!
  Enter a number: 23
  The number is prime!



  Now, this code worked fine, but can you see the problem with this approach?

  The problem is that as we keep adding more functions to mathematics.c, the number of function definitions in app.c will increase.

  Moreover, to make it work, we’ll have to include some of the standard library files in app.c to make the function prototypes valid. For example, in the above scenario we had to write #include<stdbool.h> again in app.c, without which it would not have worked.

  Now we’ll see how all these problems get addressed on using C Header Files!

  Now we’ll see how all these problems get addressed on using C Header Files!





  What are Header Files in C?
  Header files are .h files that contain function prototypes and macro definitions which can be included in other source files.



  Basically, during compilation, we needed to inform the compiler that functions like isPrime() exist in another C file, by writing the function prototypes in files where these functions are used.

  Without these definitions, the linker will not know how to piece the 2 files together and the code will not get compiled properly.

  In [example 1], we can add the following mathematics.h header file and include it directly in app.c

  Create a new file, named mathematics.h and simply define the function isPrime() and import stdbool.h



  #include<stdbool.h>

  bool isPrime(int n);



  The mathematics.c file is the same as above.

  In app.c we'll remove the function definition of isPrime() and we'll include the mathematics.h file instead


  #include <stdio.h>
  #include "mathematics.h"

  int main() {
      printf("Prime Number Check!\n");

      int n;
      printf("Enter a number: ");
      scanf("%d", &n);
      
      if (isPrime(n)) {
          printf("The number is prime!\n");
      } else {
          printf("The number is composite\n");
      }

      return 0;
  }



  The compiled executable behaves the same as before, but to use isPrime(), we didn’t have to define its function protype this time.


  Note: Header files themselves don’t have the function details!

  In our example, mathematics.h didn’t contain the code that goes into making isPrime() work. It just told the compiler to go search for isPrime() in the file mathematics.c


  This is why it is crucial for the .c file and its corresponding .h file to have the same name.







Include Syntax


  The include statement in C is a preprocessor directive and can be used with the hash symbol #. It’s purpose is to include content from other files into the file that used include.

  We included the mathematics.h file above, but we could have gotten away with including mathematics.c as well.

  #include "mathematics.c"
  This is the same as copying the contents of mathematics.c to app.c at the location where the include statement is used.

  The problem with including the entire .c file is that during compilation, the compiler compiles a single .c file which contains the contents of both mathematics.c and app.c

  In our small example this won’t make a difference, but for code that has hundreds of c files and millions of lines of code it would take forever to compile.

  This is why we normally compile the files once and define their header files. Then, if a change is made to a single .c file, we need to compile only that small file, instead of compiling the entire project! This is how header files help make compilation efficient.



  Types of Header Files
  C header files are of 2 types:

  System Header Files
  User Defined Header Files




  System Header Files
  These get installed on installing the C compiler. If you try to import a system header file, the C compiler will go through the standard files using the set path. System header files are there to ‘inform’ the compiler that standard functions like printf, scanf, malloc exist.

  At the beginning of compilation, the compiler reads #include<stdio.h> and then includes the definitions of printf, scanf and more. Then, while the executable is being made, the actual printf() function in stdio.c gets used to make the .exe file.

  You can include system header files using angular brackets <>. This is something that we’ve all seen via:

  I/O operations (printf, scanf)


  #include <stdio.h>
  Or while allocating memory (malloc)

  #include <stdlib.h>



  User Defined Header Files
  These are to inform the compiler about definitions made in other C files that lie in the same directory. We can inform the compiler about the existence of our C files by including their header files using double quotes “”.

  Example - (as seen above)

  #include "mathematics.c"






  Once-Only Headers
  Now, you might get the question, what will happen if you include header files which include other header files? Will the header files get repeated?

  The answer to that is – yes. If a header file gets repeated, then its contents will get repeated twice, which will confuse the compiler and throw an error during compilation. Even if no error is thrown, a lot of time will be wasted in processing the redundant lines.

  Let’s say, if we added a new file – helper.c, which contains a function which helps us calculate the greatest common divisor of 2 integers. In this example, we want to find out if 2 numbers are co-prime.


Two numbers are co-prime if they do not share any factors (apart from 1), which means that two numbers will be co-prime if their greatest common divisor (gcd) is 1.



In helper.c, we'll write a quick function to find the greatest common divisor of 2 integers.

int gcd(int x, int y) {
    if(x == 0) {
        return y;
    }
    return gcd(y%x, x);
}



In helper.h, we'll simply mention the function definition of gcd()

int gcd(int x, int y);



In mathematics.c, we'll include the helper.c file, which which the user can use gcd() while programming the isCoPrime() function. The isCoPrime() function simply tells us if two numbers are co-prime or not.


#include <stdbool.h>
#include "helper.h"

bool isPrime(int n) {
    for int i = 2; i * i < n + 1; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

bool isCoPrime(int x, int y) {
    if (gcd(x,y) == 1) {
        return true;
    } else {
        return false;
    }
}




In mathematics.h, we'll include the header files included and the functions defined in mathematics.c

#include <stdbool.h>
#include "helper.h"

bool isPrime(int n);
bool isCoPrime(int x, int y);



In app.c, we'll integrate code from the above files and write a program that takes two numbers, and returns whether they are prime or not (using mathematics.h). Then, we'll try to compute the gcd of those two numbers using gcd() from helper.h

#include <stdio.h>
#include "mathematics.h"
#include "helper.h"

int main() {

    printf("Co-Prime Checker!\n");

    int x,y;
    printf("Enter 2 numbers: ");
    scanf("%d %d", &x, &y);
    
    if (isCoPrime(x,y)) {
        printf("The 2 numbers are co-prime!\n");
    } else {
        printf("The 2 numbers are not co-prime\n");
    }

    printf("GCD of the 2 numbers is: %d\n", gcd(x,y));

    return 0;
}


Now compile the code with –



gcc app.c mathematics.c helper.c -o app


The code itself works fine in this case, but we have accidentally included helper.h twice in app.c, which is may problematic in the future.

The first time helper.h got included was when mathematics.h got included. And, the second time was when we included helper.h explicitly in app.c, in order to use gcd() directly.

To prevent this second include statement, we can use the ifndef, or the if not defined preprocessor. This wrapper helps include headers only once (hence the name Once Only Headers).

To do this in our little project, mathematics.c should be changed to -


#include<stdbool.h>

#ifndef FILE_HELPER_SEEN

#define FILE_HELPER_SEEN
#include "helper.h"

#endif

bool isPrime(int n);
bool isCoPrime(int x, int y);



We're basically telling the compiler - if the helper.h file is not seen (included), then include it, and mark it as 'seen'.

Then, beginning of app.c should be changed to,


#include <stdio.h>

#include "mathematics.h"

#ifndef FILE_HELPER_SEEN

#define FILE_HELPER_SEEN
#include "helper.h"

#endif



In your code editor, the second definition might get automatically greyed out, which signals us that the block will not get executed. It looks like this,




This solves our problem of multiple includes and gives some clarity to both - the programmers working on the files and the compiler!


Conclusion
In this exhaustive article we covered quite a few concepts, including header files, why they're needed, the various types of header files, and once-only headers as well!
This simple concept has helped introduce data abstraction (as functions like printf need not be written from scratch, they can just be included), modularity, and has even helped speeden the process of compilation!
As an exercise try to implement all the codes mentioned, as this will help drill the concept in.
With all the examples executed, you will have a mini math project which can be further modified in the future, and more importantly, a clear idea of what header files are, why they're needed, and how to use them - for both system defined functions and in user defined cases!
Thank you for taking the time to read this article!






REFERENCE:
https://www.scaler.com/topics/header-files-in-c/









Short introduction to header files in C

  declar, define 


REFERENCE:
https://www.youtube.com/watch?v=u1e0gLoz1SU








C "Modules" - Tutorial on .h Header Files, Include Guards, .o Object Code, & Incremental Compilation

REFERENCE:
https://www.youtube.com/watch?v=8KyZedtkEhk








Once-Only Headers | Including Multiple Header Files  | Once-Only Headers (The C Preprocessor)


    If a header file happens to be included twice, the compiler will process its contents twice and it will result in an error. The standard way to prevent this is to enclose the entire real contents of the file in a conditional, like this −

    #ifndef HEADER_FILE
    #define HEADER_FILE

    the entire header file file

    #endif


    This construct is commonly known as a wrapper #ifndef. When the header is included again, the conditional will be false, because HEADER_FILE is defined. The preprocessor will skip over the entire contents of the file, and the compiler will not see it twice.



    Computed Includes


    Sometimes it is necessary to select one of the several different header files to be included into your program. For instance, they might specify configuration parameters to be used on different sorts of operating systems. You could do this with a series of conditionals as follows −


    #if SYSTEM_1
    # include "system_1.h"
    #elif SYSTEM_2
    # include "system_2.h"
    #elif SYSTEM_3
    ...
    #endif


    But as it grows, it becomes tedious, instead the preprocessor offers the ability to use a macro for the header name. This is called a computed include. Instead of writing a header name as the direct argument of #include, you simply put a macro name there −

    #define SYSTEM_H "system_1.h"
    ...
    #include SYSTEM_H
    SYSTEM_H will be expanded, and the preprocessor will look for system_1.h as if the #include had been written that way originally. SYSTEM_H could be defined by your Makefile with a -D option.


    REFERENCE: https://www.tutorialspoint.com/cprogramming/c_header_files.htm








Including Multiple Header Files: 
    You can use various header files in a program. When a header file is included twice within a program, the compiler processes the contents of that header file twice. This leads to an error in the program. To eliminate this error, conditional preprocessor directives are used. 
    Syntax: 
    

    #ifndef HEADER_FILE_NAME
    #define HEADER_FILE_NAME

    the entire header file

    #endif
    This construct is called wrapper “#ifndef”. When the header is included again, the conditional will become false, because HEADER_FILE_NAME is defined. The preprocessor will skip over the entire contents of the file and the compiler will not see it twice. 
    Sometimes it’s essential to include several diverse header files based on the requirements of the program. For this, multiple conditionals are used.
    Syntax: 
    

    #if SYSTEM_ONE
            #include "system1.h"
    #elif SYSTEM_TWO
            #include "system2.h"
    #elif SYSTEM_THREE
    ....
    #endif

    REFERENCE: https://www.geeksforgeeks.org/header-files-in-c-cpp-and-its-uses/









2.7 Wrapper Headers
    Sometimes it is necessary to adjust the contents of a system-provided header file without editing it directly. GCC’s fixincludes operation does this, for example. One way to do that would be to create a new header file with the same name and insert it in the search path before the original header. That works fine as long as you’re willing to replace the old header entirely. But what if you want to refer to the old header from the new one?

    You cannot simply include the old header with ‘#include’. That will start from the beginning, and find your new header again. If your header is not protected from multiple inclusion (see Once-Only Headers), it will recurse infinitely and cause a fatal error.

    You could include the old header with an absolute pathname:

    #include "/usr/include/old-header.h"
    This works, but is not clean; should the system headers ever move, you would have to edit the new headers to match.

    There is no way to solve this problem within the C standard, but you can use the GNU extension ‘#include_next’. It means, “Include the next file with this name”. This directive works like ‘#include’ except in searching for the specified file: it starts searching the list of header file directories after the directory in which the current file was found.

    Suppose you specify -I /usr/local/include, and the list of directories to search also includes /usr/include; and suppose both directories contain signal.h. Ordinary #include <signal.h> finds the file under /usr/local/include. If that file contains #include_next <signal.h>, it starts searching after that directory, and finds the file in /usr/include.

    ‘#include_next’ does not distinguish between <file> and "file" inclusion, nor does it check that the file you specify has the same name as the current file. It simply looks for the file named, starting with the directory in the search path after the one where the current file was found.

    The use of ‘#include_next’ can lead to great confusion. We recommend it be used only when there is no other alternative. In particular, it should not be used in the headers belonging to a specific program; it should be used only to make global corrections along the lines of fixincludes.

    REFERENCE: https://gcc.gnu.org/onlinedocs/cpp/Wrapper-Headers.html#Wrapper-Headers






2.4 Once-Only Headers
    If a header file happens to be included twice, the compiler will process its contents twice. This is very likely to cause an error, e.g. when the compiler sees the same structure definition twice. Even if it does not, it will certainly waste time.

    The standard way to prevent this is to enclose the entire real contents of the file in a conditional, like this:

    File foo.  
    #ifndef FILE_FOO_SEEN
    #define FILE_FOO_SEEN

    the entire file

    #endif !FILE_FOO_SEEN 
    This construct is commonly known as a wrapper #ifndef. When the header is included again, the conditional will be false, because FILE_FOO_SEEN is defined. The preprocessor will skip over the entire contents of the file, and the compiler will not see it twice.

    CPP optimizes even further. It remembers when a header file has a wrapper ‘#ifndef’. If a subsequent ‘#include’ specifies that header, and the macro in the ‘#ifndef’ is still defined, it does not bother to rescan the file at all.

    You can put comments outside the wrapper. They will not interfere with this optimization.

    The macro FILE_FOO_SEEN is called the controlling macro or guard macro. In a user header file, the macro name should not begin with ‘_’. In a system header file, it should begin with ‘__’ to avoid conflicts with user programs. In any kind of header file, the macro name should contain the name of the file and some additional text, to avoid conflicts with other header files.


    REFERENCE: https://gcc.gnu.org/onlinedocs/cpp/Once-Only-Headers.html#Once-Only-Headers















2.8 System Headers
    The header files declaring interfaces to the operating system and runtime libraries often cannot be written in strictly conforming C. Therefore, GCC gives code found in system headers special treatment. All warnings, other than those generated by ‘#warning’ (see Diagnostics), are suppressed while GCC is processing a system header. Macros defined in a system header are immune to a few warnings wherever they are expanded. This immunity is granted on an ad-hoc basis, when we find that a warning generates lots of false positives because of code in macros defined in system headers.

    Normally, only the headers found in specific directories are considered system headers. These directories are determined when GCC is compiled. There are, however, two ways to make normal headers into system headers:

    Header files found in directories added to the search path with the -isystem and -idirafter command-line options are treated as system headers for the purposes of diagnostics.
    There is also a directive, #pragma GCC system_header, which tells GCC to consider the rest of the current include file a system header, no matter where it was found. Code that comes before the ‘#pragma’ in the file is not affected. #pragma GCC system_header has no effect in the primary source file.
    On some targets, such as RS/6000 AIX, GCC implicitly surrounds all system headers with an ‘extern "C"’ block when compiling as C++.

    REFERENCE: https://gcc.gnu.org/onlinedocs/cpp/System-Headers.html#System-Headers
















*/




//----------------------------------------------------------------------

































/*
    ---
*/















//----------------------------------------------------------------------

/*
STUDY TYPEDEF | STRUCT 


*/



/*
    How to use the typedef struct in C


    The C language contains the typedef keyword to allow users to provide alternative names for the primitive (e.g.,​ int) and user-defined​ (e.g struct) data types.


    Remember, this keyword adds a new name for some existing data type but does not create a new type.


    Syntax
    typedef <existing_type> <alias> 

    Using typedef struct results in a cleaner, more readable code, and saves the programmer keystrokes​. However, it also leads to a more cluttered global namespace which can be problematic for large programs.


    Examples
    The following code snippets illustrate how to use the typedef struct.

    1. Variable declaration without using typedef:

   #include<stdio.h>

    struct Point{
    int x;
    int y;
    };
    int main() {
        struct Point p1;
        p1.x = 1;
        p1.y = 3;
        printf("%d \n", p1.x);
        printf("%d \n", p1.y);
        return 0;
    }



    2. Using the typedef keyword:
    Note that there is no longer a need to type struct again and again with every declaration of the variable of this type.


    Method one:

    #include<stdio.h>

    struct Point{
    int x;
    int y;
    };
    typedef struct Point Point;
    int main() {
        Point p1;
        p1.x = 1;
        p1.y = 3;
        printf("%d \n", p1.x);
        printf("%d \n", p1.y);
        return 0;
    }




    Method two:
    #include<stdio.h>

    typedef struct Point{
    int x;
    int y;
    } Point;
    int main() {
        Point p1;
        p1.x = 1;
        p1.y = 3;
        printf("%d \n", p1.x);
        printf("%d \n", p1.y);
        return 0;
    }











    REFERENCE: https://www.educative.io/answers/how-to-use-the-typedef-struct-in-c

*/



//----------------------------------------------------------------------





































//----------------------------------------------------------------------

/*
STUDY FUNCTION 

*/






/*

C - Functions

    A function is a group of statements that together perform a task. Every C program has at least one function, which is main(), and all the most trivial programs can define additional functions.

    You can divide up your code into separate functions. How you divide up your code among different functions is up to you, but logically the division is such that each function performs a specific task.

    A function declaration tells the compiler about a function's name, return type, and parameters. A function definition provides the actual body of the function.

    The C standard library provides numerous built-in functions that your program can call. For example, strcat() to concatenate two strings, memcpy() to copy one memory location to another location, and many more functions.

    A function can also be referred as a method or a sub-routine or a procedure, etc.



    Defining a Function
    The general form of a function definition in C programming language is as follows −

    return_type function_name( parameter list ) {
    body of the function
    }

    A function definition in C programming consists of a function header and a function body. Here are all the parts of a function −

        Return Type − A function may return a value. The return_type is the data type of the value the function returns. Some functions perform the desired operations without returning a value. In this case, the return_type is the keyword void.

        Function Name − This is the actual name of the function. The function name and the parameter list together constitute the function signature.

        Parameters − A parameter is like a placeholder. When a function is invoked, you pass a value to the parameter. This value is referred to as actual parameter or argument. The parameter list refers to the type, order, and number of the parameters of a function. Parameters are optional; that is, a function may contain no parameters.

        Function Body − The function body contains a collection of statements that define what the function does.



    Example
    Given below is the source code for a function called max(). This function takes two parameters num1 and num2 and returns the maximum value between the two −

    // function returning the max between two numbers 
    int max(int num1, int num2) {

    // local variable declaration 
    int result;
    
    if (num1 > num2)
        result = num1;
    else
        result = num2;
    
    return result; 
    }





Function Declarations
A function declaration tells the compiler about a function name and how to call the function. The actual body of the function can be defined separately.


A function declaration has the following parts −
return_type function_name( parameter list );


For the above defined function max(), the function declaration is as follows −

int max(int num1, int num2);


Parameter names are not important in function declaration only their type is required, so the following is also a valid declaration −
int max(int, int);

Function declaration is required when you define a function in one source file and you call that function in another file. In such case, you should declare the function at the top of the file calling the function.






Calling a Function
    While creating a C function, you give a definition of what the function has to do. To use a function, you will have to call that function to perform the defined task.

    When a program calls a function, the program control is transferred to the called function. A called function performs a defined task and when its return statement is executed or when its function-ending closing brace is reached, it returns the program control back to the main program.

    To call a function, you simply need to pass the required parameters along with the function name, and if the function returns a value, then you can store the returned value. For example −

    #include <stdio.h>
    
    //function declaration 
    int max(int num1, int num2);
    
    int main () {

   //local variable definition 
    int a = 100;
    int b = 200;
    int ret;
    
    // calling a function to get max value 
    ret = max(a, b);
    
    printf( "Max value is : %d\n", ret );
    
    return 0;
    }
    
    // function returning the max between two numbers 
    int max(int num1, int num2) {

    //local variable declaration
    int result;
    
    if (num1 > num2)
        result = num1;
    else
        result = num2;
    
    return result; 
    }



    We have kept max() along with main() and compiled the source code. While running the final executable, it would produce the following result −

    Max value is : 200




    Function Arguments
        If a function is to use arguments, it must declare variables that accept the values of the arguments. These variables are called the formal parameters of the function.
        
        Formal parameters behave like other local variables inside the function and are created upon entry into the function and destroyed upon exit.

        While calling a function, there are two ways in which arguments can be passed to a function −

        Call Type & Description
        Call by value
            This method copies the actual value of an argument into the formal parameter of the function. In this case, changes made to the parameter inside the function have no effect on the argument.

        Call by reference
            This method copies the address of an argument into the formal parameter. Inside the function, the address is used to access the actual argument used in the call. This means that changes made to the parameter affect the argument.


        By default, C uses call by value to pass arguments. In general, it means the code within a function cannot alter the arguments used to call the function.












REFERENCE: https://www.tutorialspoint.com/cprogramming/c_functions.htm?fbclid=IwAR0yp016J7-xetoQZ0TY9zoWGx_pKVLw-0mJeqYObz-YC65w3vm-1lEVL4s

*/




/*
Function call by Value in C

    The call by value method of passing arguments to a function copies the actual value of an argument into the formal parameter of the function. In this case, changes made to the parameter inside the function have no effect on the argument.


    By default, C programming uses call by value to pass arguments. In general, it means the code within a function cannot alter the arguments used to call the function. Consider the function swap() definition as follows.


   // function definition to swap the values 
    void swap(int x, int y) {

    int temp;

    temp = x; // save the value of x 
    x = y;    // put y into x 
    y = temp; // put temp into y 
    
    return;
    }


    Now, let us call the function swap() by passing actual values as in the following example −


#include <stdio.h>
 
// function declaration//
void swap(int x, int y);
 
int main () {

   // local variable definition//
   int a = 100;
   int b = 200;
 
   printf("Before swap, value of a : %d\n", a );
   printf("Before swap, value of b : %d\n", b );
 
   // calling a function to swap the values //
   swap(a, b);
 
   printf("After swap, value of a : %d\n", a );
   printf("After swap, value of b : %d\n", b );
 
   return 0;
}
void swap(int x, int y) {

   int temp;

   temp = x; // save the value of x//
   x = y;    // put y into x //
   y = temp; // put temp into y //
  
   return;
}



Let us put the above code in a single C file, compile and execute it, it will produce the following result −

Before swap, value of a : 100
Before swap, value of b : 200
After swap, value of a : 100
After swap, value of b : 200


It shows that there are no changes in the values, though they had been changed inside the function.








REFERENCE: https://www.tutorialspoint.com/cprogramming/c_function_call_by_value.htm


*/









/*

Function call by reference in C

    The call by reference method of passing arguments to a function copies the address of an argument into the formal parameter. Inside the function, the address is used to access the actual argument used in the call. It means the changes made to the parameter affect the passed argument.

    To pass a value by reference, argument pointers are passed to the functions just like any other value. So accordingly you need to declare the function parameters as pointer types as in the following function swap(), which exchanges the values of the two integer variables pointed to, by their arguments.



    // function definition to swap the values //
    void swap(int *x, int *y) {

    int temp;
    temp = *x;    // save the value at address x //
    *x = *y;      // put y into x //
    *y = temp;    // put temp into y //
    
    return;
    }


Let us now call the function swap() by passing values by reference as in the following example −


#include <stdio.h>

int main () {

   // local variable definition //
   int a = 100;
   int b = 200;
 
   printf("Before swap, value of a : %d\n", a );
   printf("Before swap, value of b : %d\n", b );
 
   // calling a function to swap the values //
   swap(&a, &b);
 
   printf("After swap, value of a : %d\n", a );
   printf("After swap, value of b : %d\n", b );
 
   return 0;
}
void swap(int *x, int *y) {

   int temp;

   temp = *x; // save the value of x //
   *x = *y;    // put y into x //
   *y = temp; // put temp into y //
  
   return;
}



Let us put the above code in a single C file, compile and execute it, to produce the following result −

Before swap, value of a : 100
Before swap, value of b : 200
After swap, value of a : 200
After swap, value of b : 100


It shows that the change has reflected outside the function as well, unlike call by value where the changes do not reflect outside the function.






REFERENCE: https://www.tutorialspoint.com/cprogramming/c_function_call_by_reference.htm
*/


















//----------------------------------------------------------------------
