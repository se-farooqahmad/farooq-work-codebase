#include<iostream>
using namespace std;
int main()
{
    char arr[6][6];
    for (int i=1; i<=6; i++)
    {
        for(int j=1; j<=6; j++)
        {
            arr[i][j]='*';
        }
    }
    for (int i=1; i<=6; i++)
    {
        if ( i % 2 == 0)
            cout<<" ";
        for(int j=1; j<=6; j++)
        {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
}