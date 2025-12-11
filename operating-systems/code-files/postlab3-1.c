#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
int main()
{
pid_t pid;
pid=fork();
if(pid==0){
printf("I’m in a child process \nMy task is to print the contents of this directory\n");
system("ls");
printf("\n");
printf("This is the the list of all the contents of this directory");
printf("\n\n");
}
else if (pid>0){
    wait(NULL);
printf("I’m in the parent process \nMy task is to wait for my child to complete its task\n");
printf("I have done my Task... GoodBye  TakeCare\n\n");

}
else
{
printf("Error \n\n");
}
return 0;
}