#include<iostream>
using namespace std;
int main()
{
    int a,b;
    char op;
    cout<<"Enter two numbers: "<<endl;
    cin>>a>>b;
    cout<<"Enter Operator: ";
    cin>>op;
    switch(op){
    case '+': cout<<"Sum = "<<a+b;
    break;
    case '-': cout<<"Sub = "<<a-b;
    break;
    case '*': cout<<"Product = "<<a*b;
    break;
    case '/': cout<<"div = "<<a/b;
    break;
    case '%': cout<<"Mod = "<<a%b;
    break;
    default: cout<<"Invalid Operator";
    }
}