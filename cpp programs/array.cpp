#include<iostream>
using namespace std;
const int arraySize = 10;
int search(int arr[], int key);

int main()
{
    
    int arr[arraySize];
    int sum = 0;
    int avg = 0;
    int min,max;
    cout<<"Enter 10 Integers"<<endl;
    for (int i=0; i<arraySize; i++)
    {
        cin>>arr[i];
        sum = sum + arr[i];
    }
    cout<<"Array in the index ascending order"<<endl;
    for (int i=0; i<arraySize; i++)
        cout<<arr[i]<<" ";
    cout<<endl;
    cout<<"Array in the index descending order"<<endl;
    for (int i=arraySize-1; i>=0; i--)
        cout<<arr[i]<<" ";
    min=arr[0];
    for (int i=0;i<arraySize;i++)
    {
        if(arr[i]<min)
        min=arr[i];
    }
    cout<<endl;
    
    max=arr[0];
    for (int i=0;i<arraySize;i++)
    {
        if(arr[i]>max)
        max=arr[i];
    }
    
    for (int i=0; i<arraySize; i++)
    {
        for (int j=0; j<arraySize-1; j++)
        {
            if(arr[j]>arr[j+1])
            {
                swap(arr[j],arr[j+1]);
            }
        }
    }
    cout<<"Array Sorted in the Ascending order"<<endl;
    for (int i=0;i<arraySize;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    cout<<"Array Sorted in the Descending order"<<endl;
    for (int i=arraySize-1;i>=0;i--)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    avg = sum/arraySize;
    cout<<"Minimum is :"<<min<<endl;
    cout<<"Maximum is :"<<max<<endl;
    cout<<"Sum is :"<<sum<<endl;
    cout<<"Avg is :"<<avg<<endl;

    cout<<"Enter a key value to find"<<endl;
    int key;
    cin>>key;
    cout<<"Key found at index : "<<search(arr,key);

}
int search(int arr[], int key)
{
    for(int i=0; i<arraySize; i++)
    {
        if(arr[i]==key)
            return i;
    }
    return -999;
}