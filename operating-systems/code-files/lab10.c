#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/mman.h>
#include <errno.h>
#include <pthread.h>
#include <semaphore.h>
#include <string.h>
sem_t mutex;
int fd;
char*data;
int count=0;
int count1=0;
int length;
int half;

void* find1(void* arg)
{
    //wait
    int i, j, l, l1, l2;    
    sem_wait(&mutex);
    char* word=arg;
    printf("\nEntered..\n");
    char*arr1=(char*)malloc(1024);
    for(int i=0;i<=half;i++)
    {
        arr1[i]=data[i];
    }
    printf("First Half : %s",arr1);
    l1 = strlen(arr1);
    l2 = strlen(word);
    for (i = 0; i < l1;)
    {
        j = 0;
        count = 0;
        while ((arr1[i] == word[j]))
        {
            count++;
            i++;
            j++;
        }
        if (count == l2)
        {
            count1++;                                   
            count = 0;
        }
        else
            i++;
    }    
    printf("\nJust Exiting...\n");
    sem_post(&mutex);   
}
void* find2(void* arg)
{
    //wait
    int i, j, l, l1, l2;
    char* word=arg;
    sem_wait(&mutex);
    printf("\nEntered..\n");
    char*arr2=(char*)malloc(1024);
    for(int i=0;i<=half;i++)
    {
        arr2[i]=data[i+half];
    }
    printf("Second Half : %s",arr2);
    l1 = strlen(arr2);
    l2 = strlen(word);
    for (i = 0; i < l1;)
    {
        j = 0;
        count = 0;
        while ((arr2[i] == word[j]))
        {
            count++;
            i++;
            j++;
        }
        if (count == l2)
        {
            count1++;                                   
            count = 0;
        }
        else
            i++;
    }    
    printf("\nJust Exiting...\n");
    sem_post(&mutex);   
}

int main(int argc, char*argv[])
{
    char*fileName=argv[1];
    char*sstring=argv[2];   
    fd=open(fileName,O_RDONLY);
    data=mmap(NULL, getpagesize(), PROT_READ,MAP_SHARED, fd,0);
    length = strlen(data);
    printf("Total length %d \n",length);
    half = length/2;
    printf("Half of the length %d \n",half);
    printf("File contains: %s\n", data);
    sem_init(&mutex, 0, 1);
    pthread_t t1,t2;
    pthread_create(&t1,NULL,find1,sstring);
    pthread_create(&t2,NULL,find2,sstring);
    pthread_join(t1,NULL);
    pthread_join(t2,NULL);
    sem_destroy(&mutex);

    printf("Number of times of occurence of the substring: %d \n",count1);
   
    return 0;
}