# Create Random in C

Program to Create a RANDOM in C

begin:

### STEPS on Linux Environment

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

    gcc -Wall -O2 random*.c -o random*
    #OR
    gcc random*.c -o random*

## Running Example

    ./random*

# ranstr3.c

Program to create a random with 10000 words and each word has 10 caracteres

**obs:.**
This program just a simple example of random - it not the complex random program

## STEPS by STEPS on Linux Environment (completed)

    sudo su -
    sudo apt-get install gcc -y

    cd ~
    rm -fr C2/
    git clone https://github.com/pedroAkiraDanno/C2
    cd C2/src/random/


    gcc -Wall -O2 ranstr3.c -o ranstr3
    #OR
    gcc ranstr3.c -o ranstr3

    ./ranstr3

## Example output & Run :

    	root@instance-20220608-2248:~/C2/src/q_sort# ./ranstr3
    	Enter the filename : a.txt

## Example output file:

    	ceafsokean
    	pdzgxcjacv
    	povbsgmnxj
    	dzpfghtqlw
    	dczeizhuzl
    	pozmssuehr

# ranstr4.c

Program to create a random with 10000 words and each word has 10 caracteres

**obs:.**
This program just a simple example of random - it not the complex random program

NEED USE ranstr4.h include

## STEPS by STEPS on Linux Environment (completed)

    sudo su -
    sudo apt-get install gcc -y

    cd ~
    rm -fr C2/
    git clone https://github.com/pedroAkiraDanno/C2
    cd C2/src/random/


    cp ranstr4.h		 /usr/include


    gcc -Wall -O2 ranstr4.c -o ranstr4
    #OR
    gcc ranstr4.c -o ranstr4

    ./ranstr4

## Example output & Run :

    	root@instance-20220608-2248:~/C2/src/q_sort# ./ranstr4
    	Enter the filename : a.txt

## Example output file:

    	ceafsokean
    	pdzgxcjacv
    	povbsgmnxj
    	dzpfghtqlw
    	dczeizhuzl
    	pozmssuehr

# rannum2.c

Program to create a random with SHRT_MAX number

**obs:.**
This program just a simple example of random - it not the complex random program

## STEPS by STEPS on Linux Environment (completed)

    sudo su -
    sudo apt-get install gcc -y

    cd ~
    rm -fr C2/
    git clone https://github.com/pedroAkiraDanno/C2
    cd C2/src/random/



    gcc -Wall -O2 rannum2.c -o rannum2
    #OR
    gcc ranstr4.c -o rannum2

    ./rannum2

## Example output & Run :

    	root@instance-20220608-2248:~/C2/src/q_sort# ./rannum2
    		978664932
    		48329229
    		1774724142
    		938360505
    		458442484

---

Inspired in [devdocs](https://devdocs.io/c/) , [docs.microsoft](https://docs.microsoft.com/en-us/cpp/c-language/?view=msvc-170) , [cppreference](https://en.cppreference.com/w/c/language) , [programiz](https://www.programiz.com/c-programming) and [gnu](https://www.gnu.org/software/gnu-c-manual/gnu-c-manual.html), this is C-minimalistic version.

end:
