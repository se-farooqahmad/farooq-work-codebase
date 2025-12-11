#include <stdio.h> 
#include <string.h> 
#include <fcntl.h> 
#include <sys/stat.h> 
#include <sys/types.h> 
#include <unistd.h>
#include <stdlib.h>

int main()
{
    char arr[255];
    int fd1;
    char * myfifo = "/tmp/myfifo";
    mkfifo(myfifo,0666);
        int solution;
        fd1=open(myfifo,O_WRONLY);
        fgets(arr, 255, stdin);
        write(fd1, &arr, strlen(arr)+1); 
        close(fd1);
        fd1=open(myfifo,O_RDONLY);
        read(fd1,&solution,1);
        printf("The result is: ");
        printf("%d\n",solution);
        close(fd1);

}