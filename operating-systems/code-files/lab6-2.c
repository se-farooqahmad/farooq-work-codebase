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
   char* fileInName=argv[1];
   char* fileOutName=argv[2];
   key_t key = ftok("shmemoryfile",75);
   int shmid = shmget(key,1024,0655|IPC_CREAT);
   char*shm =shmat(shmid,NULL,0);
   char arr1[1024];
   memset(arr1,('\0'),sizeof(arr1));
   char arr2[1024];
   memset(arr2,('\0'),sizeof(arr2));
   pid_t process=fork();
   if(process==0)
   {
      //child
      FILE*f1=fopen(fileInName,"r");
      while(fgets(arr1,1024,f1)!=NULL)
      {
         strcat(arr2,arr1);
      }
      shm=arr2;
      fclose(f1);
   }
   else {}
   wait(NULL);
   if(process==0)
   {
      printf("%s",shm);
      FILE*f2=fopen(fileOutName,"w");
      fprintf(f2,"%s",shm);
      fclose(f2);
      shmdt(shm);
      shmctl(shmid,IPC_RMID,NULL);
   }
   
   else{}

}

    
