#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include<stdlib.h>
#include <stdlib.h>
int main(int argc, char*argv[])
{
    int count=0;
    int sum=0;
    int avg=0;
    int max=0;
    int* arr=new int[argc-1];
    for(int i=0;i<argc-1;i++)
    {
        arr[i]=atoi(argv[i+1]);
        count++;

    }
    pid_t pid;
    pid = fork();
    if(pid==0)
    {
        printf("I'm the child process one\nMy Task is to calculate the sum of the array\nSum= ");
        for(int i=0;i<count;i++)
        {
            sum=sum+arr[i];
        }
        printf("%d",sum);
        printf("\n\n");
    }
    else{}
    if( pid>0)
    {
        pid = fork();
        if(pid==0)
    {
        printf("I'm the child process two\nMy Task is to calculate the avg of the array\nAverage= ");
        for(int i=0;i<count;i++)
        {
            sum=sum+arr[i];
        }
        avg=sum/count;
        printf("%d",avg);
        printf("\n\n");
    }
    else{}
    }
    if( pid>0)
    {
        pid = fork();
        if(pid==0)
    {
        printf("I'm the child process three\nMy Task is to find out the maximum Num is the Array\nMaximum num is: ");
        for(int i=0;i<count;i++)
        {
            if(arr[i]>max)
            {
                max=arr[i];
            }
        }
        printf("%d",max);
        printf("\n\n");
        
    }
    else{}
    }
    
}