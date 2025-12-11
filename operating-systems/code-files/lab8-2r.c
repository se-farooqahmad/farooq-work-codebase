#include <stdio.h> 
#include <string.h> 
#include <fcntl.h> 
#include <sys/stat.h> 
#include <sys/types.h> 
#include <unistd.h>
#include <stdlib.h>
int main()
{
    int fd2;
    char * myfifo = "/tmp/myfifo";
    mkfifo(myfifo,0666);
    dup2(fd2, 0);
    execlp("ls", "ls", NULL);
    execlp("sort", "sort", "-r", NULL);
    close(fd2);

}