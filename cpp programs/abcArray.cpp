#include<iostream>
using namespace std;
int main()
{
    int M,N;
    cout<<"Enter the size for array A : ";
    cin>>M;
    int *arrA = new int (M);
    cout<<"Enter the elements for array A : ";
    for (int i=0; i<M; i++)
    {
        cin>>arrA[i];
    }
    /*cout<<"The elements you have entered are : ";
    for (int i=0; i<M; i++)
    {
        cout<<arrA[i]<<" ";
    } 
    for (int i=0; i<M ; i++)
    {
        for ( int j=0; j<M-1; j++)
        {
            if (arrA[j]>arrA[j+1])
                swap(arrA[j],arrA[j+1]);
        }
    }
    cout<<endl;
    cout<<"Sorted Array A : ";
    for (int i=0; i<M; i++)
    {
        cout<<arrA[i]<<" ";
    }
    cout<<endl; */
    cout<<"Enter the size for array B : ";
    cin>>N;
    int *arrB = new int (N);
    cout<<"Enter the elements for array B : ";
    for (int i=0; i<N; i++)
    {
        cin>>arrB[i];
    }
    /*cout<<"The elements you have entered are : ";
    for (int i=0; i<N; i++)
    {
        cout<<arrB[i]<<" ";
    } 
    for (int i=0; i<N ; i++)
    {
        for ( int j=0; j<N-1; j++)
        {
            if (arrB[j]>arrB[j+1])
                swap(arrB[j],arrB[j+1]);
        }
    }
    cout<<endl;
    cout<<"Sorted Array B : ";
    for (int i=0; i<N; i++)
    {
        cout<<arrB[i]<<" ";
    } */
    int * arrC = new int (M+N);
    for(int i=0; i<M; i++)
    {
        arrC[i]=arrA[i];
    }
    int index=0;
    for (int i=M; i<M+N; i++)
    {
        arrC[i]=arrB[index];
        index++;
    }
    cout<<"MErged Array"<<endl;
    for(int i=0; i<M+N; i++)
    {
        cout<<arrC[i]<<" ";
    }
}