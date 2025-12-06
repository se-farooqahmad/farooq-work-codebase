#include<iostream>
using namespace std;
int evenSum(int n)
{
    int sum=0;
    for(int i=0;i<=n;i++)
    {
        sum=sum+2*i;
    }
    return sum;
}
int main()
{
    int num;
    cout<<"Enter n: ";
    cin>>num;
    cout<<"Sum of the first N integers is: "<<evenSum(num);
}