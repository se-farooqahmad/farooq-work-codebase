#include <iostream>
#include <cstdlib>
#include <stdlib.h>
using namespace std;
int main(int argc, char*argv[])
{
    int count=0;
    int sum=0;
    int avg=0;
    int* arr=new int[argc-1];
    for(int i=0;i<argc-1;i++)
    {
        arr[i]=atoi(argv[i+1]);
        count++;
        sum=sum+arr[i];
    }
    avg=sum/count;
    cout<<"Sum of the integers is: "<<sum<<endl;
    cout<<"Average of the integers is: "<<avg<<endl;
}