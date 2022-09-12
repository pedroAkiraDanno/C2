





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






*/




//----------------------------------------------------------------------










