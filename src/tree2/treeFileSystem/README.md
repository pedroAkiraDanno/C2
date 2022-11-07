# Create Tree in C

Program to Tree in C

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

    gcc -Wall -O2 bst3.c -o bst3
    #OR
    gcc bst3.c -o bst3

## Running Example

    ./bst3

## STEPS by STEPS on Linux Environment (completed)

    sudo su -
    sudo apt-get install gcc -y

    cd ~
    rm -fr C2/
    git clone https://github.com/pedroAkiraDanno/C2
    cd C2/tree/bst

    gcc -Wall -O2 bst3.c -o bst3
    #OR
    gcc bst3.c -o bst3

    ./bst3

# tree2.c (tree.c)

Will use tree2.c like tree command in linux C

## STEPS by STEPS on Linux Environment (completed)

    sudo su -
    sudo apt-get install gcc -y

    cd ~
    rm -fr C2/
    git clone https://github.com/pedroAkiraDanno/C2

    //  cd ~   ;   	cd C2 	; 	git checkout feature/tree   ;      cd ~  ;     cd C2/src/tree/treeFileSystem
    //  cd ~   ;   	cd C2 	; 	git checkout develop   ;      cd ~  ;     cd C2/src/tree/treeFileSystem

    cd C2/src/tree/treeFileSystem


    gcc -Wall -O2 tree2.c -o tree2
    #OR
    gcc tree2.c -o tree2

    ./tree2

## output:

    .
    ├── README.md
    ├── rest1
    ├── test
    │   ├── Lec-dynamic-memory.pdf
    │   ├── aula19.pdf
    │   ├── posix_list_files.c
    │   └── posix_list_files2.c
    ├── tree.c
    ├── tree2
    ├── tree2.c
    └── treeStudy.c

    2 directories, 9 files

## REFERENCE:

    zip -> tree-main.zip
    https://github.com/kddnewton/tree/blob/main/tree.c

---

# treeRecursively.c (treeRecursively.c)

Will use treeRecursively.c like find . command in linux C

## STEPS by STEPS on Linux Environment (completed)

    sudo su -
    sudo apt-get install gcc -y

    cd ~
    rm -fr C2/
    git clone https://github.com/pedroAkiraDanno/C2

    //  cd ~   ;   	cd C2 	; 	git checkout feature/tree   ;      cd ~  ;     cd C2/src/tree/treeFileSystem
    //  cd ~   ;   	cd C2 	; 	git checkout develop   ;      cd ~  ;     cd C2/src/tree/treeFileSystem

    cd C2/src/tree/treeFileSystem


    gcc -Wall -O2 treeRecursively.c -o treeRecursively
    #OR
    gcc treeRecursively.c -o treeRecursively

    ./treeRecursively

## output:

    - treeStudy.c
    [test]
    [pdf]
        - Lec-dynamic-memory.pdf
        - aula19.pdf
    - posix_list_files.c
    - posix_list_files2.c
    - tree2.c
    - README.md
    - treeRecursively2.c
    - treeRecursively.c
    - tree.c
    - treeRecursively

---

# treeRecursivily2.c (treeRecursivily2.c) \*\*MOST IMPORTAT

Will use tree2.c like tree command in linux C

## STEPS by STEPS on Linux Environment (completed)

    sudo su -
    sudo apt-get install gcc -y

    cd ~
    rm -fr C2/
    git clone https://github.com/pedroAkiraDanno/C2

    //  cd ~   ;   	cd C2 	; 	git checkout feature/tree   ;      cd ~  ;     cd C2/src/tree/treeFileSystem
    //  cd ~   ;   	cd C2 	; 	git checkout develop   ;      cd ~  ;     cd C2/src/tree/treeFileSystem

    cd C2/src/tree/treeFileSystem


    gcc -Wall -O2 treeRecursively2.c -o treeRecursively2
    #OR
    gcc treeRecursively2.c -o treeRecursively2

    ./treeRecursively2

## output:

    .
    ./treeStudy.c
    ./treeRecursivily2
    ./test
    ./test/Lec-dynamic-memory.pdf
    ./test/aula19.pdf
    ./test/posix_list_files.c
    ./test/posix_list_files2.c
    ./treeRecursively2
    ./tree2.c
    ./README.md
    ./treeRecursively2.c
    ./treeRecursively.c
    ./tree.c

## output2:

    .
    ./treeStudy.c
    ./test
    ./test/pdf
    ./test/pdf/Lec-dynamic-memory.pdf
    ./test/pdf/aula19.pdf
    ./test/posix_list_files.c
    ./test/posix_list_files2.c
    ./treeRecursively2
    ./tree2.c
    ./README.md
    ./treeRecursively2.c
    ./treeRecursively.c
    ./tree.c
    ./treeRecursively

---

## REFERENCES GLOBAL:

https://www.sanfoundry.com/c-programming-examples/

https://www.sanfoundry.com/c-program-implement-search-in-binary-search-tree/

---

Inspired in [devdocs](https://devdocs.io/c/) , [docs.microsoft](https://docs.microsoft.com/en-us/cpp/c-language/?view=msvc-170) , [cppreference](https://en.cppreference.com/w/c/language) , [programiz](https://www.programiz.com/c-programming) and [gnu](https://www.gnu.org/software/gnu-c-manual/gnu-c-manual.html), this is C-minimalistic version.

end:
