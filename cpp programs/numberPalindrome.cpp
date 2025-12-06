#include <iostream>
using namespace std;
int main()
{
    cout<<"Enter a Number: ";
    int n;
    cin>>n;
    int num = n;
    int rev=0;
    int rem;
    while(n!=0)
    {
        rem=n%10;
        rev=(rev*10)+rem;
        n=n/10;
    }
    cout<<"Reversed: "<<rev<<endl;
    if(num==rev)
        cout<<"Palindrome";
    else cout<<"Not Palindrome";
    
}