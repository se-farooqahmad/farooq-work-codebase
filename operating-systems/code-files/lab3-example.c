#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
pid_t pid;
pid=fork();
if(pid==0){
printf("I’m in a child process \n\n");
}
else if (pid>0){
printf("I’m in the parent process \n\n");
}
else
{
printf("Error \n\n");
}
return 0;
}