#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

int main()
{
    int cpid;
pid_t pid;

printf("I am a process and my process ID is: ");
printf("%d",getpid());
printf("\n");
printf("I am going to create my child\n\n");
pid=fork();
if(pid==0){
printf("I’m the child process \n");
printf("My process ID is: ");
printf("%d",getpid());
printf("\n");
printf("And my parent's process ID is: ");
printf("%d",getppid());
printf("\n\n");
cpid=getpid();
}
else if (pid>0){
    wait(NULL);
printf("I’m the parent process \n");
printf("My process ID is: ");
printf("%d",getpid());
printf("\n");
printf("And my child's process ID is: ");
printf("%d",pid);
printf("\n\n");


}
else
{
printf("Error \n\n");
}
return 0;
}