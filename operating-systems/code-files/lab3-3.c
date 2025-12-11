
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
int main()
{
pid_t pid;
pid=fork();
if(pid==0)
{
    
    printf("I’m in a child process \n\n");
    system("mkdir newfolder1");
    system("mkdir newfolder2");
    printf("Made 2 folders and listing them\n");
    system("ls");
    printf("\n");
    system("mkdir 1 1/2 1/2/3 1/2/3/4");
    printf("Made a nested folder 1->2->3->4 and listing them\n");
    system("ls");
    printf("\n");
}
else if (pid>0)
{
    wait(NULL);
    printf("I’m in the parent process \n\n");
    system("cp -a newfolder1 newfolder2");
    //copied f1 into f2
    printf("Copied newfolder1 into newfolder2\n");
    system("ls");
    printf("\n");
    system("rm -r newfolder2");
    printf("Removed newfolder2 recurssively and listing\n");
    system("ls");
    printf("\n");
    system("rmdir newfolder1");
    printf("Removed newfolder1 and listing\n ");
    system("ls");
    printf("\n");
    system("rm -r 1");
    printf("Removed nested folders 1->2->3->4 recurssively and listing\n");
    system("ls");
    printf("All directories have been removed");
    printf("\n");
    printf("In this program i have invoked many commands in my program\n\n");
}
else
{
    printf("Error \n\n");
}
return 0;
}