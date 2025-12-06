#include<iostream>
using namespace std;
int factorial (int n)
{
    int fac=1;
    for (int i=n;i>0;i--)
    {
        fac = fac*i;
    }
    return fac;
}
int main()
{
    cout<<"Enter a number: ";
    int num;
    cin>>num;
    cout<<"n! = "<<factorial(num)<<endl;
}