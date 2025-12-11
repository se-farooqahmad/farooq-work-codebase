#include <iostream>
#include <cstdlib>
#include <stdlib.h>
using namespace std;
int main(int argc, char*argv[])
{
    int count=0;
    int* arr=new int[argc-1];
    for(int i=0;i<argc-1;i++)
    {
        arr[i]=atoi(argv[i+1]);
        count++;

    }
    for(int j=0;j<count;j++)
    {
        for(int k=0;k<j;k++)
        {
        if(arr[j]<arr[k])
        swap(arr[j],arr[k]);

    }
    for(int l=0;l<argc-1;l++)
    {
        cout<<arr[l]<<" ";
    }
    cout<<endl;
    
    }

}