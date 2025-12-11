#include<iostream>
#include <cmath>
using namespace std;
int fr(int );
void main()
{
int sum,i,n,c;
cout<<"Enter number to find its factorial= ";
cin>>n;
cout<<"for iterative press 1\nFor recursive Press 2\n";
cin>>c;
sum = n;
if (c==1)
{
for (i=1;i<n; i++)
{
	sum=sum*(n-i);
}
cout <<"iterative   "<<sum<<"\n\n";}
else if(c==2)
{
	int f=sum*fr(n-1);
	cout<<f<<"\n\n";
}
system("pause");

}

int fr(int  n)
{

	if (n<=1)
		return 1;
	else
		return n*fr(n-1); 
	
}