#include <iostream>
using namespace std;
int Sum(int number)
{
    int rem;
    int sum=0;
    while(number!=0)
    {
        rem=number%10;
        sum=sum+rem;
        number=number/10;
    }
    return sum;
}
int main()
{
    cout<<"Enter a Number: ";
    int n;
    cin>>n;
    cout<<"Sum of this integer is: "<<Sum(n);
}