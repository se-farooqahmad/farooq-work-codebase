#include<iostream>
using namespace std;
int main()
{
    int x,n,p;
    cout<<"Enter angle x: ";
    cin>>x;
    cout<<"enter n: ";
    cin>>n;
    int temp =x;
    for(int i=2;i<=n;i++)
    {
        x=x*temp;
    }
    cout<<"Power is: "<<x;
}