#include <sys/wait.h>
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>
int main(int argc, char* argv[])
{
    char word;
    pid_t Process;
    int fdPipe1[2];
    int fdPipe2[2];
    pipe(fdPipe1);
    pipe(fdPipe2);
    Process=fork();
    if(Process==0)
    {
        //child
        close(fdPipe1[0]);
        write(fdPipe1[1],argv[1],strlen(argv[1]));
        close(fdPipe1[1]);
        wait(NULL);
        close(fdPipe2[1]);
      
        printf("The Revered case letters string is ");
        while(read(fdPipe2[0],&word,1)>0)
        {
             printf("%c",word);      
        }
        printf("\n");
        close(fdPipe2[0]);
        exit(EXIT_SUCCESS);
    }
    else
    {
        //parent
        close(fdPipe1[1]);
        close(fdPipe2[0]);
        while(read(fdPipe1[0],&word,1)>0)
        {
            if(word>='a' && word<='z')
            {
                word=toupper(word);
            }
            else if(word>='A' && word<='Z')
            {
                word=tolower(word);
            } 
            write(fdPipe2[1],&word,1);
        }
        close(fdPipe2[1]);
        close(fdPipe1[0]);
        exit(EXIT_SUCCESS);
    }
    
}