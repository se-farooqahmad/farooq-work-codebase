#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int *arr1 = (int*) malloc(100);
    arr1[0]=2;
    int *arr2 = (int*) malloc(100);
    arr2[0]=4;
    int *arr3 = (int*) malloc(100);
    arr3[0]=7;
    int *arr4 = (int*) malloc(100);
    arr4[0]=3;
    int *arr5 = (int*) malloc(100);
    arr5[0]=4;
    int *arr6 = (int*) malloc(100);
    arr6[0]=10;
    for (int i=1;i<4;i++)
    {
        arr1[i]=arr1[0]+1;
        arr1[0]++;   
        arr2[i]=arr2[0]+2;
        arr2[0]=arr2[0]+2;
        arr3[i]=arr3[0]+3;
        arr3[0]=arr3[0]+3;      
    }
    arr1[0]=2;
    arr2[0]=4;
    arr3[0]=7;
    for (int i=0;i<4;i++)
    {
        printf(" %d x %d x %d,",arr1[i],arr2[i],arr3[i]);
    }
    printf("\n");
    for (int i=1;i<4;i++)
    {
        arr4[i]=arr4[0];
        arr5[i]=arr5[0]+4;
        arr5[0]=arr5[0]+4;
        arr6[i]=arr6[0]-5;
        arr6[0]=arr6[0]-5;
    }
    arr4[0]=3;
    arr5[0]=4;
    arr6[0]=10;
    for (int i=0;i<4;i++)
    {
        printf(" %d x %d x %d,",arr4[i],arr5[i],arr6[i]);
    }
    printf("\n");
    FILE *f=fopen("finalOutputFile.txt","w");
       for(int i=0;i<4;i++)
       {
           fprintf(f," %d x %d x %d,",arr1[i],arr2[i],arr3[i]);
       }
       fprintf(f,"\n");
       for (int i=0;i<4;i++)
        {
            fprintf(f," %d x %d x %d,",arr4[i],arr5[i],arr6[i]);
        }
        fprintf(f,"\n");
        fclose(f);
}