#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
    cout<<"Enter an integer: ";
    int n;
    int sum = 0;
    int fac = 1;
    cin>>n;
    cout<<"Integer"<<setw(10)<<"Sum"<<setw(15)<<"Factorial"<<endl;
    cout<<"================================"<<endl;
    for (int i=1;i<=n;i++)
    {   
        sum = sum + i;
        fac = fac * i;
        cout<<setw(5)<<i<<setw(12)<<sum<<setw(15)<<fac<<endl;
    }
}