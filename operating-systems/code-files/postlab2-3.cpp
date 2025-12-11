#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;
int main()
{   
    int count;
    int arr[5];
    int missing;
    int i;
ifstream file;
file.open("integerFile.txt");
if(file.is_open())
{
    while(!file.eof() && i<5)
    {
        file>>arr[i];
        i++;
        count++;
    }
}
int diff=arr[1]-arr[0];
    for(int i=0;i<count-1;i++)
    {
        if((arr[i+1]-arr[i])!=diff)
        {
            missing=arr[i]+diff;   
        }
    }
 
    ofstream outFile;
    outFile.open("outFile.txt");
    outFile<<"The missing element is: "<<missing<<endl;
    outFile.close();
    file.close();   
}