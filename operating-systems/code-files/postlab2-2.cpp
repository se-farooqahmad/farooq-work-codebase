#include <iostream>
#include <cstdlib>
#include <stdlib.h>
#include <fstream>
using namespace std;
int main(int argc, char*argv[])
{
    int missing=0;
    int count;
    int* arr=new int[argc-1];
    for(int i=0;i<argc-1;i++)
    {
        arr[i]=atoi(argv[i+1]);
        count++;

    }
    int diff=arr[1]-arr[0];
    for(int i=0;i<count-1;i++)
    {
        if((arr[i+1]-arr[i])!=diff)
        {
            missing=arr[i]+diff;   
        }
    }
    ofstream outfile;
    outfile.open("outputFile.txt");
    outfile<<"The missing element is: "<<missing<<endl;
    outfile.close();

}