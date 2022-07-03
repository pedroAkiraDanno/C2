# Create a consume Large Memory in C


Program to Create a Consume Large Memory in the System in C








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





# memory_malloc.c
**obs:.** 
	Will create a Memory with 3 GB

## Compile projects and files (handmade)
	gcc -Wall -O2 memory_malloc.c -o memory_malloc
	#OR
	gcc memory_malloc.c -o memory_malloc    	




## Running Example
	./memory_malloc   




## STEPS by STEPS on Linux Environment (completed)
    sudo su - 
    sudo apt-get install gcc -y

    cd ~
    rm -fr C2/
    git clone https://github.com/pedroAkiraDanno/C2
    cd C2/memory_malloc/

	gcc -Wall -O2 memory_malloc.c -o memory_malloc
	#OR
	gcc memory_malloc.c -o memory_malloc    

	./memory_malloc   
















# memory_malloc2.c
**obs:.** 
	Will create a Memory with 3 GB

## Compile projects and files (handmade)
	gcc -Wall -O2 memory_malloc2.c -o memory_malloc2
	#OR
	gcc memory_malloc2.c -o memory_malloc2    	




## Running Example
	./memory_malloc2   




## STEPS by STEPS on Linux Environment (completed)
    sudo su - 
    sudo apt-get install gcc -y

    cd ~
    rm -fr C2/
    git clone https://github.com/pedroAkiraDanno/C2
    cd C2/memory_malloc/

	gcc -Wall -O2 memory_malloc2.c -o memory_malloc2
	#OR
	gcc memory_malloc2.c -o memory_malloc2    

	./memory_malloc2   















---
Inspired in [devdocs](https://devdocs.io/c/) , [docs.microsoft](https://docs.microsoft.com/en-us/cpp/c-language/?view=msvc-170) , [cppreference](https://en.cppreference.com/w/c/language) , [programiz](https://www.programiz.com/c-programming) and [gnu](https://www.gnu.org/software/gnu-c-manual/gnu-c-manual.html), this is C-minimalistic version.




end: