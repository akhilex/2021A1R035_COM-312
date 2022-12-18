#include<stdio.h>
#include<sys/types.h>
#include<errno.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>
int main(void)
{ //declare variable
int var=1;
int* p= (int*) malloc(2);
pid_t PID = fork();
*p =0;
if(PID >=0) //if fork successful
{
if(PID == 0) //if it is child process
{
printf("\n\nChild Process: \n Initial value =%d",var);
var=5;
printf("\nNew Value of var= %d",var);
printf("\nAddress of malloc in child= %p",p);
printf("\nAddress of var in child= %p\n",&var);
}
else //if it is parent process
{
printf("\n\nParent process:\n Initial value =%d",var);
var=10;
printf("\nNew value= %d",var);
printf("\nAddress of malloc in parent = %p",p);
printf("\nAddress of var in child =%p\n",&var);
}
}
return 0;
}
