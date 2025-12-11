#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int size;
int avg;
int max;
int min=65535;
void* average(void* parameters)
{
    int *arr=(int*)parameters;
    int sum=0;
    for(int i=0; i<size;i++)
    {
        sum=sum+arr[i];
    }
    avg=sum/size;
    
pthread_exit(0);
}
void* maximum(void* parameters)
{
    int *arr=(int*)parameters;
    for(int i=0; i<size;i++)
    {
        if(arr[i]>max)
        {
            max=arr[i];
        }
        
    }
    
pthread_exit(0);
}
void* minimum(void* parameters)
{
    int *arr=(int*)parameters;
    for(int i=0; i<size;i++)
    {
        if(arr[i]<min)
        min=arr[i];
    }
    
    
pthread_exit(0);
}
void main(int argc, char*argv[])
{
    size=argc-1;
    int *arr = (int*) malloc(size);
   for (int i=0;i<size;i++)
   {
       arr[i]=atoi(argv[i+1]);
   }
//thread identifier
pthread_t threadID1;
pthread_t threadID2;
pthread_t threadID3;
//set attributes for the thread
//pthread_attr_t attributes;
//get the default attributes
//pthread_attr_init(&attributes);
//create the thread
pthread_create(&threadID1, NULL, average, arr);
pthread_create(&threadID2, NULL, maximum, arr);
pthread_create(&threadID3, NULL, minimum, arr);
//now wait for the thread to exit
pthread_join(threadID1, NULL);
pthread_join(threadID2, NULL);
pthread_join(threadID3, NULL);
printf("The Avgerage Value is: ");
printf("%d",avg);
printf("\n");
printf("The Minimum Value is: ");
printf("%d",min);
printf("\n");
printf("The Maximum Value is: ");
printf("%d",max);
printf("\n");
}