#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>
#include <sys/wait.h>
#include <assert.h>
int main(int argc,char*argv[])
{
    key_t key = ftok("shmfile",65);
    int shmid = shmget(key,1024,0644|IPC_CREAT);
    char*shm =shmat(shmid,NULL,0);
    
    char* fileName=argv[1];
    pid_t Process=fork();
    if (Process>0)
    {
        //parent
        wait(NULL);
        char* arr=(char*)malloc(255);
        arr=shm;
        
         for(int i=0;i<255;i++)
         {
             if(arr[i]>='a' && arr[i]<='z')
            {
                arr[i]=toupper(arr[i]);
            }
            else if(arr[i]>='A' && arr[i]<='Z')
            {
                arr[i]=tolower(arr[i]);
            }
         }
         for(int i=0;i<255;i++)
         {
           if(arr[i]>='0' && arr[i]<='9')
            {
                arr[i]='\0';
            }
         }
           
        
    }
    else if(Process==0)
    {
         //child
         printf("File's Contents changed by the parent being written back to the shared memory by the child\n");
         printf("%s\n",shm);
         FILE *f2=fopen(fileName,"w");
         fprintf(f2,"%s",shm);
         fclose(f2);
         shmdt(shm);
         shmctl(shmid,IPC_RMID,NULL);
         FILE *fil=fopen(fileName,"r");
         fgets(shm,255,(FILE*)fil);
         fclose(fil);
    }
}
       