#include <stdio.h>
#include <stdlib.h>
int main(int argc, char*argv[])
{
   int *arr = (int*) malloc(argc-1);
   for (int i=0;i<argc-1;i++)
   {
       arr[i]=atoi(argv[i+1]);
        printf("%d",arr[i]);
        
   }
}