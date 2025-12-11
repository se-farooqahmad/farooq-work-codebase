#include <iostream>
using namespace std;
void iterative(int n)

{
	int m=1;
	for(int i=n; i>=1; i--)
	{
		m=m*i;
		
	}
	cout<<m<<endl;
}
int recursive(int n)
{if(n==0)
return 1;
else return(recursive(n-1)*n);
}
void main()
{
	cout<<"Please enter any number"<<endl;
	int f;
	cin>>f;
	iterative(f);
	cout<<recursive(f)<<endl;

}