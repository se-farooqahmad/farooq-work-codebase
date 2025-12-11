#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
int sum; //this data is shared by the thread(s)
//The thread will begin control in this funtion
void* fibconniGenerator(void *parameters)
{
    int number=atoi(parameters);
    int a=0,b=1;
    int next=a+b;
    printf("%d",a);
    printf(" ");
    printf("%d",b);
    printf(" ");
    while(next<number)
    {
        a=b;
        b=next;
        next=a+b;
        printf("%d",next);
        printf(" ");
    }
    printf("\n");

pthread_exit(0);
}//End runner
int main(int argc, char*argv[])
{
//thread identifier
pthread_t threadID[argc-1];
//set attributes for the thread
pthread_attr_t attributes;
//get the default attributes
pthread_attr_init(&attributes);
//create the thread
for (int i=0;i<argc-1;i++)
{pthread_create(&threadID[i+1], &attributes, fibconniGenerator, argv[i+1]);
//now wait for the thread to exit
printf("Thread ");
printf("%d",(i+1));
printf(":  ");
pthread_join(threadID[i+1], NULL);

}

}