#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
sem_t mutex;
void* thread(void* arg)
{
//wait
sem_wait(&mutex);
printf("\nEntered..\nCalculating. . .\nPlease Wait...\n");
//critical section
int *arr=(int*)arg;
for(int i=0;i<10;i++)
{
    arr[i]=2*(arr[i]) + 2;
    printf("%d ",arr[i]);
}
sleep(2);
//signal
printf("\nJust Exiting...\n");
sem_post(&mutex);
}
int main()
{
sem_init(&mutex, 0, 1);
int arr[10]={0,0,0,0,0,0,0,0,0,0};
printf("Array of 10 elements initialized to {0,0,0,0,0,0,0,0,0,0}\n");
pthread_t t1,t2,t3,t4,t5;
pthread_create(&t1,NULL,thread,arr);
sleep(2);
pthread_create(&t2,NULL,thread,arr);
sleep(2);
pthread_create(&t3,NULL,thread,arr);
sleep(2);
pthread_create(&t4,NULL,thread,arr);
sleep(2);
pthread_create(&t5,NULL,thread,arr);
sleep(2);
pthread_join(t1,NULL);
pthread_join(t2,NULL);
pthread_join(t3,NULL);
pthread_join(t4,NULL);
pthread_join(t5,NULL);
printf("Thankyou. . . \n");
sem_destroy(&mutex);
return 0;
}