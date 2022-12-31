# Create Quick Sort in C

Program to Create a Quick sort in C

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

    gcc -Wall -O2 quicksort*.c -o quicksort*
    #OR
    gcc quicksort*.c -o quicksort*

## Running Example

    ./quicksort*

# quick_sort.c

Will use quick_sort and partition functions with C

**obs:.**
Will print Unsorted Array and Sorted array in ascending order

## STEPS by STEPS on Linux Environment (completed)

    sudo su -
    sudo apt-get install gcc -y

    cd ~
    rm -fr C2/
    git clone https://github.com/pedroAkiraDanno/C2
    cd C2/ ; git checkout develop ; cd ..

    cd C2/src/q_sort/



    gcc -Wall -O2 quick_sort.c -o quick_sort
    #OR
    gcc quick_sort.c -o quick_sort

    ./quick_sort

# ranstr3.c

Will use quick_sort and partition functions with C

**obs:.**
Will print Unsorted Array and Sorted array in ascending order

## STEPS by STEPS on Linux Environment (completed)

    sudo su -
    sudo apt-get install gcc -y

    cd ~
    rm -fr C2/
    git clone https://github.com/pedroAkiraDanno/C2
    cd C2/ ; git checkout develop ; cd ..

    cd C2/src/q_sort/


    cp ranstr4.h		 /usr/include


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

# myquick_sort.c

Will use quick_sort and partition functions with C

**obs:.**
Will print Unsorted Array and Sorted array in ascending order

## STEPS by STEPS on Linux Environment (completed)

    sudo su -
    sudo apt-get install gcc -y

    cd ~
    rm -fr C2/
    git clone https://github.com/pedroAkiraDanno/C2
    cd C2/ ; git checkout develop ; cd ..
    cd C2/src/q_sort/



    gcc -Wall -O2 myquick_sort.c -o myquick_sort
    #OR
    gcc myquick_sort.c -o myquick_sort

    ./myquick_sort

# myquick_sort2.c

Will use quick_sort and partition functions with C

**obs:.**
Will print Unsorted Array and Sorted array in ascending order with just 10 number control by MAX_SIZE

## STEPS by STEPS on Linux Environment (completed)

    sudo su -
    sudo apt-get install gcc -y

    cd ~
    rm -fr C2/
    git clone https://github.com/pedroAkiraDanno/C2
    cd C2/ ; git checkout develop ; cd ..
    cd C2/src/q_sort/



    gcc -Wall -O2 myquick_sort2.c -o myquick_sort2
    #OR
    gcc myquick_sort2.c -o myquick_sort2

    ./myquick_sort2

---

Inspired in [devdocs](https://devdocs.io/c/) , [docs.microsoft](https://docs.microsoft.com/en-us/cpp/c-language/?view=msvc-170) , [cppreference](https://en.cppreference.com/w/c/language) , [programiz](https://www.programiz.com/c-programming) and [gnu](https://www.gnu.org/software/gnu-c-manual/gnu-c-manual.html), this is C-minimalistic version.

end:
