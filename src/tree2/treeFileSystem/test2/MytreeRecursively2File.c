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

    FILE * fptr;
    fptr = fopen("largefile.txt", "w+"); // "w" defines "writing mode" //create a file 

    if (!(dir = opendir(path))) {
        //fprintf(stderr, "path not found: %s: %s\n",path, strerror(errno));
        fprintf(fptr, "path not found: %s: %s\n",path, strerror(errno));
        return;
    }

    puts(path);
    while ((entry = readdir(dir)) != NULL) {
        char *name = entry->d_name;
        if (entry->d_type == DT_DIR) {
            if (!strcmp(name, ".") || !strcmp(name, ".."))
                continue;
            if (len + strlen(name) + 2 > size) {
                //fprintf(stderr, "path too long: %s/%s\n", path, name);
                fprintf(fptr, "path too long: %s/%s\n", path, name);
            } else {
                path[len] = '/';
                strcpy(path + len + 1, name);
                listdir(path, size);
                path[len] = '\0';
            }
        } else {
            /*printf("%s/%s\n", path, name);*/
            fprintf(fptr, "%s/%s\n", path, name);
        }
    }
    closedir(dir);
    fclose(fptr);
}






            







int main(void) {
    char path[1024] = "/";
    listdir(path, sizeof path);
    return 0;
}










/*
README 

    On my system, its output is exactly identical to that of find .

*/




/*
COMPILE:


    vi MytreeRecursively2File.c
    gcc MytreeRecursively2File.c -o MytreeRecursively2File
    ./MytreeRecursively2File



    echo "" > MytreeRecursively2File.c
    rm largefile.txt MytreeRecursively2File



*/







/*
REFERENCE: 
    https://stackoverflow.com/questions/8436841/how-to-recursively-list-directories-in-c-on-linux

*/











