#include<stdio.h>
void form(int []);
void set_down(int [],int);
int main()
{
int val[100],chk,counter,end,temp_val;
printf("Please enter the total count of the elements that you want to sort: \n");
scanf("%d",&chk);
printf("Please input the elements that has to be sorted:\n");
for(counter=1;counter<=chk;counter++)
scanf("%d",&val[counter]);
val[0]=chk;
form(val);
while(val[0] > 1)
{
end=val[0];
temp_val=val[1];
val[1]=val[end];
val[end]=temp_val;
val[0]--;
set_down(val,1);
}
printf("\n Output generated after using heap sort \n");
for(counter=1;counter<=chk;counter++)
printf("%d ",val[counter]);
}
void form(int val[])
{
int counter,chk;
chk=val[0];
for(counter=chk/2;counter>=1;counter--)
set_down(val,counter);
}
void set_down(int val[],int counter)
{
int counter2,temp_val,chk,flag=1;
chk=val[0];
while(2*counter<=chk && flag==1)
{
counter2=2*counter;
if(counter2+1<=chk && val[counter2+1] > val[counter2])
counter2=counter2+1;
if(val[counter] > val[counter2])
flag=0;
else
{
temp_val=val[counter];
val[counter]=val[counter2];
val[counter2]=temp_val;
counter=counter2;
}
}
}

//reference: https://www.educba.com/sorting-in-c/
