#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <ranstr4.h>



//constant
#define MAX 2000



//global variable
int k=0;

//struct
struct nick
{
int id;
char a[2000];
};


//function
void quicksort(struct nick items[], int left, int right);                   //function for quick sort
void printArray(struct nick array[], int size);  			         // print function
void printArrayQuick(struct nick array[], int size);  			         // print function


//main
int main()
{

    char *p;

    //time
	clock_t start, end;
	float total_time;

    FILE *fp;
    int i=0,n=2000; //n control the qtd of strings
    char fname[10],str[2000],c;
    struct nick name[MAX];

    printf("Enter the filename : ");
    //gets(fname);
    fgets(fname, sizeof(fname), stdin);

    fp=fopen(fname,"w"); //create a file 

    if (NULL == fp) {
            printf("file can't be opened \n");
        }    

    for(i=0;i<n;i++)
    {
        //fflush (stdout);
        //scanf("%s",name[i].a);       // write to array struct 
        p = randomString(200);        
        strcpy(name[i].a,p);          //copy string name to name - struct         
        fprintf(fp,"%s ",name[i].a); //write to a file 
    }

    fclose(fp);
    i=0;

    fp=fopen(fname,"r");                   //open file in read mode
    while(!feof(fp))               //read a file and record in string variable content 
    {

        c=fgetc(fp);
        if(c==' ')
            {
                str[i]='\0';
                strcpy(name[k].a,str);          //copy string name to name - struct 
                i=0;
                k++;
            }
        else
        {
            str[i]=c; //str to buffer, record file content in a variable 
            i++;
        }
    }

    fclose(fp);

    //printf("\nInitial contents of file\n");
    for(i=0; i<k; i++)
       // printf("%s,", name[i].a);                       //print unsort data
    //printArray(name,k);

    quicksort(name,0,k-1);                              //calling quicksort

    //printf("\n\nAfter applying quick sort \n");
    for(i=0; i<k; i++)
    {
       // printf("%s,", name[i].a);                       //printing sorted
    }

    //printArray(name,k);


    //time
    end = clock();
	total_time = (float)(end - start) / CLOCKS_PER_SEC;
	printf("\nExecute_time : %.6f\n", total_time);    

    return 0;
}








                                                         //function for quick sort
void quicksort(struct nick items[],int first,int last)
{
     int j,i,pivot;
     char temp[2000]; // variable to swap elements

     if(first<last)
     {
           pivot=first;
           i=first;
           j=last;


           // function to find the partition position
           while(i<j)
           {
               while((strcmp(items[i].a,items[pivot].a))<0) //<0  ex: a,b = -1    if the first non-matching character in str1 is lower (in ASCII) than that of str2.  
                    i++;
               while((strcmp(items[j].a,items[pivot].a))>0) //>0  ex: b,a = 1	if the first non-matching character in str1 is greater (in ASCII) than that of str2.
                    j--;
                // bigger then pivot = true so j--. Want find the less value compare with pivot, to find the correct positon to pivot and partition. Left more, rigth less values    

               if(i<j)
               {
                     // function to swap elements
                     strcpy(temp,items[i].a);          //swap the values at i and j'th index
                     strcpy(items[i].a,items[j].a);
                     strcpy(items[j].a,temp);
                     //printArrayQuick(items,k);
               }
                

          }

          // function to swap elements
          strcpy(temp,items[pivot].a);
          strcpy(items[pivot].a,items[j].a);
          strcpy(items[j].a,temp);


          quicksort(items,first,j-1);                 //recursive call to quick sort
          quicksort(items,j+1,last);
    }


}



// function to print array elements
void printArray(struct nick array[], int size) {
  for (int i = 0; i < size; ++i) {
    printf("%s,", array[i].a);                       //printing     
  }
  printf("\n");
}


// function to print array elements
void printArrayQuick(struct nick array[], int size) {
  printf("\n quicksort print: ");
  for (int i = 0; i < size; ++i) {
    printf(" %s,", array[i].a);                       //printing     
  }
  printf("\n");
}




/*
this quicksort 


pivot = first 


Initial contents of file
pedro,akira,danno,lima,saty,

After applying quick sort
akira,danno,lima,pedro,saty,




Initial contents of file
beatriz,akira,zabbix,pedro,fernanda,rafaela

After applying quick sort
akira,beatriz,ferdanda,pedro,rafaela,zabbix,

    1
    beatriz*,akira,zabbix,pedro,fernanda,rafaela
    akira,beatriz*,zabbix,pedro,fernanda,rafaela

    2
    akira*,beatriz,zabbix,pedro,fernanda,rafaela
    akira*,beatriz,zabbix,pedro,fernanda,rafaela


    3
    akira,beatriz*,zabbix,pedro,fernanda,rafaela
    akira,beatriz*,zabbix,pedro,fernanda,rafaela


    4
    akira,beatriz,zabbix*,pedro,fernanda,rafaela
    akira,beatriz,rafaela*,pedro,fernanda,zabbix
    akira,beatriz,fernanda*,pedro,rafaela,zabbix


    5
    akira,beatriz,fernanda,pedro*,rafaela,zabbix


    6
    akira,beatriz,fernanda,pedro,rafaela*,zabbix









Initial contents of file
camila,beatriz,faria,akira,batriz,zabbix,pedro,emerson,queijo,gabriel,daiane

After applying quick sort
akira,batriz,beatriz,camila,daiane,emerson,faria,gabriel,pedro,queijo,zabbix


1
camila*,beatriz,faria,akira,batriz,zabbix,pedro,emerson,queijo,gabriel,daiane
batriz*,beatriz,faria,akira,camilaj,zabbix,pedro,emerson,queijo,gabriel,daiane
akira*,beatriz,faria,batrizj,camila,zabbix,pedro,emerson,queijo,gabriel,daiane


2
akira,beatriz*,faria,batriz,camila,zabbix,pedro,emerson,queijo,gabriel,daiane
akira,batriz*,faria,beatriz,camila,zabbix,pedro,emerson,queijo,gabriel,daiane


3
akira,batriz,faria*,beatriz,camila,zabbix,pedro,emerson,queijo,gabriel,daiane
akira,batriz,daiane*,beatriz,camila,zabbix,pedro,emerson,queijo,gabriel,faria
akira,batriz,camila*,beatriz,daianej,zabbix,pedro,emerson,queijo,gabriel,faria
akira,batriz,beatriz*,camila,daianej,zabbix,pedro,emerson,queijo,gabriel,faria


4
akira,batriz,beatriz,camila*,daianej,zabbix,pedro,emerson,queijo,gabriel,faria


5
akira,batriz,beatriz,camila,daiane*,zabbix,pedro,emerson,queijo,gabriel,faria


6
akira,batriz,beatriz,camila,daiane,zabbix*,pedro,emerson,queijo,gabriel,faria
akira,batriz,beatriz,camila,daiane,faria*,pedro,emerson,queijo,gabriel,zabbix
akira,batriz,beatriz,camila,daiane,emerson*,pedro,fariaj,queijo,gabriel,zabbix


7
akira,batriz,beatriz,camila,daiane,emerson,pedro*,faria,queijo,gabriel,zabbix
akira,batriz,beatriz,camila,daiane,emerson,gabriel*,faria,queijo,pedroj,zabbix
akira,batriz,beatriz,camila,daiane,emerson,faria*,gabrielj,queijo,pedro,zabbix


8
akira,batriz,beatriz,camila,daiane,emerson,faria,gabriel*,queijo,pedro,zabbix



9
akira,batriz,beatriz,camila,daiane,emerson,faria,gabriel,queijo*,pedro,zabbix
akira,batriz,beatriz,camila,daiane,emerson,faria,gabriel,pedro*,queijoj,zabbix

10
akira,batriz,beatriz,camila,daiane,emerson,faria,gabriel,pedro,queijo*,zabbix






*/











/*
COMPILE:

ulimit -a
ulimit -s 2097152
ulimit -a


apt-get intall gcc
vi quick_sort4.c
echo "" > quick_sort4.c
gcc quick_sort4.c -o quick_sort4
./quick_sort4

rm *.exe *.c quick* *.txt 'a.txt'$'\n'

REFE:
https://www.tutorialride.com/c-sorting-programs/sort-data-using-quick-sort-c-program.htm


*/

