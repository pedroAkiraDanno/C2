# Create Large File in C


Program to Create a Quick sort in C
 
 Inserted Total qtd : 1000000 to sort and include the progress bar feature


**obs:.** 
	Will created the quick sort with linked list





### STEPS on Linux Environment 


begin:


---



## 1- step install gcc
	### login server: 
	### On Ubuntu ### 
	sudo su - 
	sudo apt update  --yes
	sudo apt-get update && sudo apt-get upgrade -y
	apt list --upgradable
    sudo apt-get install -y gcc
	sudo apt-get install build-essential	
	## Installing Clang on Linux
	sudo apt install -y clang 






## Compile projects and files (handmade)
	gcc -Wall -O2 my_quicksort_singly_linked_list.c -o my_quicksort_singly_linked_list
	#OR
	gcc my_quicksort_singly_linked_list.c -o my_quicksort_singly_linked_list    	




## Running Example
	./my_quicksort_singly_linked_list   




## STEPS by STEPS on Linux Environment (completed)
    sudo su - 
    sudo apt-get install gcc -y

    cd ~
    rm -fr C2/
    git clone https://github.com/pedroAkiraDanno/C2
    cd C2/src/q_sort/string/quicksort_string

	gcc -Wall -O2 quicksort_string.c -o quicksort_string
	#OR
	gcc quicksort_string.c -o quicksort_string    

	./quicksort_string   







# quicksort_string2.c
Will use malloc to consume a large size of memory  and use realloc to expand the memory size in the system with C 

**obs:.** 
Will create a Memory with 1 GB realloc(expand) to Size : 3 GB


## STEPS by STEPS on Linux Environment (completed)
    sudo su - 
    sudo apt-get install gcc -y

    cd ~
    rm -fr C2/
    git clone https://github.com/pedroAkiraDanno/C2
    cd C2/q_sort/string/quicksort_string2

	cp ranstr4.h		 /usr/include


	gcc -Wall -O2 quicksort_string2.c -o quicksort_string2
	#OR
	gcc quicksort_string2.c -o quicksort_string2    

	./quicksort_string2   









---
Inspired in [devdocs](https://devdocs.io/c/) , [docs.microsoft](https://docs.microsoft.com/en-us/cpp/c-language/?view=msvc-170) , [cppreference](https://en.cppreference.com/w/c/language) , [programiz](https://www.programiz.com/c-programming) and [gnu](https://www.gnu.org/software/gnu-c-manual/gnu-c-manual.html), this is C-minimalistic version.




end:
