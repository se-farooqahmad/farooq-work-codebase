#include<iostream>
using namespace std;
//ITERATIVE FUNCTION
void factorial (int n)
{int f=1;
	for(int i=n;i>=1;i--)
	{ f=f*i;}
	cout<<"Factorial = "<<f<<endl;}
//RECURSIVE FUNCTION
int recursive (int n)
{ if(n==0)
return 1;
else return (recursive(n-1)*n);
}
void main ()
{
	int nn;
	cout<<"Enter a num\n";
	cin>>nn;
	/*cout<<recursive(nn)<<endl;*/
	factorial(nn);
	system("pause");
}