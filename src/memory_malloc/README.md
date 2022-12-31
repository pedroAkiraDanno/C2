# Create a consume Large Memory in C

Program to Create a Consume Large Memory in the System amd Test Memorys in C

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

## Compile Example projects and files (handmade)

    gcc -Wall -O2 memory*.c -o memory*
    #OR
    gcc memory*.c -o memory*

## Running Example

    ./memory*

# memory_malloc.c

Will use malloc to consume a large size of memory in the system with C

**obs:.**
Will create a Memory with 3 GB

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

    ulimit -a
    ulimit -s 3000000

    ./memory_malloc

# memory_malloc2.c

Use malloc and realloc and show the memory address just to test

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

# memory_malloc3.c

Will use malloc to consume a large size of memory and use realloc to expand the memory size in the system with C

**obs:.**
Will create a Memory with 1 GB realloc(expand) to Size : 3 GB

## STEPS by STEPS on Linux Environment (completed)

    sudo su -
    sudo apt-get install gcc -y

    cd ~
    rm -fr C2/
    git clone https://github.com/pedroAkiraDanno/C2
    cd C2/ ; git checkout develop ; cd ..
    cd C2/memory_malloc/

    gcc -Wall -O2 memory_malloc3.c -o memory_malloc3
    #OR
    gcc memory_malloc3.c -o memory_malloc3

    ./memory_malloc3

# memory2.c

Allocated memory until the system crash. Allocated each time: 1548 kilobytes

**obs:.**
Need stop manual because exist the infinity loop in the program while(1){}

## STEPS by STEPS on Linux Environment (completed)

    sudo su -
    sudo apt-get install gcc -y

    cd ~
    rm -fr C2/
    git clone https://github.com/pedroAkiraDanno/C2
    cd C2/ ; git checkout develop ; cd ..
    cd C2/memory_malloc/

    gcc -Wall -O2 memory2.c -o memory2
    #OR
    gcc memory2.c -o memory2

    ./memory2

---

Inspired in [devdocs](https://devdocs.io/c/) , [docs.microsoft](https://docs.microsoft.com/en-us/cpp/c-language/?view=msvc-170) , [cppreference](https://en.cppreference.com/w/c/language) , [programiz](https://www.programiz.com/c-programming) and [gnu](https://www.gnu.org/software/gnu-c-manual/gnu-c-manual.html), this is C-minimalistic version.

end:
