#include<iostream>
using namespace std;
void primeChecker(int n)
{
    int count = 0;
    for(int i=2;i<=n;i++)
    {
        if(n%i==0)
            count++;
    }
    if (count==1)
        cout<<"Prime Number";
    else
        cout<<"Not a Prime Number";
}
int main()
{
    int num;
    cout<<"Enter an integer: ";
    cin>>num;
    primeChecker(num);
}