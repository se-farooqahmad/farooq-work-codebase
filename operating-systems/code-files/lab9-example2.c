#include <sys/wait.h>
#include <stdlib.h>
#include <assert.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <semaphore.h>
#include <stdio.h>
int main(int argc, char **argv)
{
int i, nloop=10, *ptr;
sem_t mutex;
int shmid2,shmid1;
int SHMSIZE=1024;
sem_t *p_mutex;
if((shmid2 = shmget(IPC_PRIVATE,SHMSIZE,0666))<0)
{
perror("shmget");
exit(1);
}
p_mutex = (sem_t*) shmat(shmid2,NULL,0);
if(p_mutex==(sem_t *)-1)
{
perror("mutex shmat fails");
exit(0);
}
if(p_mutex == (sem_t*)-1)
{
perror("semaphore initialization");
exit(0);
}
if (fork()==0)
{
sem_wait(p_mutex);
for (i=0;i<nloop;i++)
printf("child: %d\n",(*ptr)++);
sem_destroy(p_mutex);
shmctl(shmid2,IPC_RMID,(struct shmid_ds*)0);
shmctl(shmid1,IPC_RMID,(struct shmid_ds*)0);
exit(0);}
sem_post(p_mutex);
for (i=0;i<nloop;i++)
printf("parent: %d\n",(*ptr)++);
exit(0);
return 0;
}