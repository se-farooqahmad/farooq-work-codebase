#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
pid_t pid;
pid=fork();
if(pid==0){
    for(int i=0;i<100;i++){
printf("I’m in a child process \n");}
printf("My Parent's ID is: ");
printf("%d",getppid());
printf("\n");
printf("My Own ID is: ");
printf("%d",getpid());
printf("\n\n");
}
else if (pid>0){
    wait(NULL);
    for(int i=0;i<100;i++){
printf("I’m in the parent process \n");}
printf("My Parent's ID is: ");
printf("%d",getppid());
printf("\n");
printf("My Own ID is: ");
printf("%d",getpid());
printf("\n\n");
}
else
{
printf("Error \n\n");
}
return 0;
}