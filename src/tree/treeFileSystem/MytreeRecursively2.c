#include <errno.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <dirent.h>



void listdir(char *path, size_t size) {
    DIR *dir;
    struct dirent *entry;
    size_t len = strlen(path);

    if (!(dir = opendir(path))) {
        fprintf(stderr, "path not found: %s: %s\n", path, strerror(errno));
        return;
    }

    puts(path);
    while ((entry = readdir(dir)) != NULL) {
        char *name = entry->d_name;


        //DEBUG
        printf("entry->d_name: %s", name);


        if (entry->d_type == DT_DIR) {
            if (!strcmp(name, ".") || !strcmp(name, ".."))
                continue;
            if (len + strlen(name) + 2 > size) {
                fprintf(stderr, "path too long: %s/%s\n", path, name);
            } else {
                path[len] = '/';
                strcpy(path + len + 1, name);
                listdir(path, size);
                path[len] = '\0';
            }
        } else {
            printf("%s/%s\n", path, name);
        }
    }
    closedir(dir);
}




int main(void) {
    char path[1024] = ".";

    //DEBUG
    printf("sizeof(path): %zu", sizeof(path));

    listdir(path, sizeof path);
    return 0;
}










/*
README 

    On my system, its output is exactly identical to that of find .

*/



/*
COMPILE:


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


*/




/*
REFERENCE: 
    https://stackoverflow.com/questions/8436841/how-to-recursively-list-directories-in-c-on-linux

*/










