#include <sys/wait.h>
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>
int main(int argc,char*argv[])
{
    char *ftbc = argv[1];
    char *fc = argv[2];
    char contents[255];
    int fdp[2];
    pipe(fdp);
    
    pid_t Process;
    Process=fork();
    if(Process==0)
    {
        //child
        char *arr = (char*) malloc(255);
        close(fdp[1]);
        while(read(fdp[0],&contents,255)>0)
        {
            arr=contents;
        }
        //printf("%s\n", arr );
        close(fdp[0]);
        FILE *f2;
        f2=fopen(fc,"w");
        fprintf(f2,"%s",arr);
        fclose(f2);
    }
    else
    {
        //parent
        FILE *f1;  
    f1=fopen(ftbc,"r");
    fgets(contents, 255, (FILE*)f1);
    close(fdp[0]);
    write(fdp[1],&contents,255);
    close(fdp[1]);
    fclose(f1);  
    }
    
   
}