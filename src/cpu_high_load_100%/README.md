# Create a consume Large Memory in C

Program to Create a Consume Large CPU in the System in C c

### STEPS on Linux Environment

cpu_high_load_100%

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
    sudo apt-get install build-essential ## Installing Clang on Linux
    sudo apt install -y clang

## Compile Example projects and files (handmade)

    gcc -Wall -O2 cpu_high_load_100%*.c -o cpu_high_load_100%*
    #OR
    gcc cpu_high_load_100%*.c -o cpu_high_load_100%*

## Running Example

    ./cpu_high_load_100%*

# cpu_intensive.c

Will use malloc to consume a large size of memory in the system with C

**obs:.**
Will create a Memory with 3 GB

## STEPS by STEPS on Linux Environment (completed)

    sudo su -
    sudo apt-get install gcc -y

    cd ~
    rm -fr C2/
    git clone https://github.com/pedroAkiraDanno/C2
    cd C2/ ; git checkout develop ; cd ..
    cd C2/src/cpu_high_load_100%/

    gcc -Wall -O2 cpu_intensive.c -o cpu_intensive
    #OR
    gcc cpu_intensive.c -o cpu_intensive


    ./cpu_intensive

# cpu_intensive2.c

Use malloc and realloc and show the memory address just to test

## STEPS by STEPS on Linux Environment (completed)

    sudo su -
    sudo apt-get install gcc -y
    sudo apt install libomp-dev  -y

    cd ~
    rm -fr C2/
    git clone https://github.com/pedroAkiraDanno/C2
    cd C2/ ; git checkout develop ; cd ..
    cd C2/src/cpu_high_load_100%/


    gcc -fopenmp cpu_intensive2.c  -o  cpu_intensive2

    ./cpu_intensive2

---

Inspired in [devdocs](https://devdocs.io/c/) , [docs.microsoft](https://docs.microsoft.com/en-us/cpp/c-language/?view=msvc-170) , [cppreference](https://en.cppreference.com/w/c/language) , [programiz](https://www.programiz.com/c-programming) and [gnu](https://www.gnu.org/software/gnu-c-manual/gnu-c-manual.html), this is C-minimalistic version.

end:
