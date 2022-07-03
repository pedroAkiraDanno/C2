# Create Large File in C


Program to Create a Large File in C


**obs:** 
Will create a file with 11G
Time to finish about 





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
	gcc -Wall -O2 mycreatelargefile.c -o mycreatelargefile
	#OR
	gcc mycreatelargefile.c -o mycreatelargefile    	




## Running Example
	./mycreatelargefile   




## STEPS by STEPS on Linux Environment (completed)
    sudo su - 
    sudo apt-get install gcc -y

    cd ~
    rm -fr C2/
    git clone https://github.com/pedroAkiraDanno/C2
    cd C2/file/

	gcc -Wall -O2 mycreatelargefile.c -o mycreatelargefile
	#OR
	gcc mycreatelargefile.c -o mycreatelargefile    

	./mycreatelargefile   





---
Inspired in [devdocs](https://devdocs.io/c/) , [docs.microsoft](https://docs.microsoft.com/en-us/cpp/c-language/?view=msvc-170) , [cppreference](https://en.cppreference.com/w/c/language) , [programiz](https://www.programiz.com/c-programming) and [gnu](https://www.gnu.org/software/gnu-c-manual/gnu-c-manual.html), this is C-minimalistic version.




end: