#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

//constant
#define max 10


//struct
struct nick
{
  char a[10];
};


//function
void quicksort(struct nick items[], int left, int right);                   //function for quick sort


//main
int main()
{

    FILE *fp;
    int i=0,k=0,n;
    char fname[10],str[10],c;
    struct nick name[max];

    printf("Enter the filename : ");
    scanf("%s",fname);
    printf("\nEnter the number of products : ");
    scanf("%d",&n);
    printf("Enter %d product name : \n",n);
    fp=fopen(fname,"w");

    for(i=0;i<n;i++)
    {
        scanf("%s",name);
        fprintf(fp,"%s ",name);
    }
    fclose(fp);
    i=0;

    fp=fopen(fname,"r");                   //open file in read mode
    while((c=getc(fp))!=EOF)
    {
        if(c==' ')
            {
                str[i]='\0';
                strcpy(name[k].a,str);          //copy string name to name
                i=0;
                k++;
            }
        else
        {
            str[i]=c;
            i++;
        }
    }
    
    fclose(fp);
    printf("\nInitial contents of file\n");

    for(i=0; i<k; i++)
        printf("%s,", name[i].a);
    quicksort(name,0,k-1);                              //calling quicksort
    printf("\n\nAfter applying quick sort \n");

    for(i=0; i<k; i++)
    {
        printf("%s,", name[i].a);                       //printing sorted
    }


    return 0;
}








                                                         //function for quick sort
void quicksort(struct nick items[],int first,int last)
{
     int j,i,pivot;
     char temp[10];
     if(first<last)
     {
           pivot=first;
           i=first;
           j=last;
           while(i<j)
           {
               while((strcmp(items[i].a,items[pivot].a))<0)
                    i++;
               while((strcmp(items[j].a,items[pivot].a))>0)
                    j--;

               if(i<j)
               {
                     strcpy(temp,items[i].a);          //swap the values at i and j'th index
                     strcpy(items[i].a,items[j].a);
                     strcpy(items[j].a,temp);
               }
          }
          strcpy(temp,items[pivot].a);
          strcpy(items[pivot].a,items[j].a);
          strcpy(items[j].a,temp);
          quicksort(items,first,j-1);                 //recursive call to quick sort
          quicksort(items,j+1,last);
    }
}













/*
COMPILE:

apt-get intall gcc
vi quick_sort10.c 
gcc quick_sort10.c -o quick_sort10.exe
./quick_sort10.exe



REFE: 
https://www.tutorialride.com/c-sorting-programs/sort-data-using-quick-sort-c-program.htm


*/

