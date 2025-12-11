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
    char str[255];
    char * myfifo = "/tmp/myfifo";
    mkfifo(myfifo,0666);
        fd2 = open(myfifo,O_RDONLY); 
        while(read(fd2,&str,255)>0){}
        close(fd2);
       str[1]=atoi(&str[1]);
       str[2]=atoi(&str[4]);
       char operator = str[0];
       int operand1 = str[1];
       int operand2 = str[2];
       int result;
       if(operator=='+')
       {
           result = operand1 + operand2;
       }
       else if(operator=='-')
       {
           result = operand1 - operand2;
       }
       else if(operator=='/')
       {
           result = operand1 / operand2;
       }
       else if(operator=='*')
       {
           result = operand1 * operand2;
       }
       else
       {
           perror("Wrong Operator");
       }
       //printf("%d",result);
       fd2=open(myfifo, O_WRONLY);
       write(fd2,&result,1);
       close(fd2);  
}