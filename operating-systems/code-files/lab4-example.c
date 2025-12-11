#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
int sum; //this data is shared by the thread(s)
//The thread will begin control in this funtion
void* runner(void *parameters)
{
int i, upper=atoi(parameters);
if(upper>0)
{
for(i=1;i<=upper;i++)
sum=sum+i;
}
pthread_exit(0);
}//End runner
int main(int argc, char*argv[])
{
//thread identifier
pthread_t threadID;
//set attributes for the thread
pthread_attr_t attributes;
//get the default attributes
pthread_attr_init(&attributes);
//create the thread
pthread_create(&threadID, &attributes, runner, argv[1]);
//now wait for the thread to exit
pthread_join(threadID, NULL);
printf("sum=%d\n",sum);
}