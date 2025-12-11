#include <stdio.h> 
#include <string.h> 
#include <fcntl.h> 
#include <sys/stat.h> 
#include <sys/types.h> 
#include <unistd.h>
#include <stdlib.h>
int main()
{
    int fd1;
    char * myfifo = "/tmp/myfifo";
    mkfifo(myfifo,0666);
    execlp("ls", "ls", NULL);
    dup2(fd1, 1);
    close(fd1);
    

    
}