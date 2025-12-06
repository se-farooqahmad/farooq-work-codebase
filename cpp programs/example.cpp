#include <iostream>
using namespace std;

int sum (int arr[])
{
    int sum = 0;
    for (int i=0; i<100; i++)
    {
        sum = arr[i];
    }
    return sum;
}


int main()
{
    int arr[100];
    
    for (int i = 0; i<100; i++)
    {
        arr[i]=rand()%10;
    }
    cout<<sum(arr);
    
}