#include <iostream>
using namespace std;
void main()
{
	int r=3,c=2;
	int a[3][2];
	int offset=0;
	int column[3*2];
	cout<<"ENTER THE ELEMENTS : "<<endl;
	for(int i=0;i<3;i++)
	{
		cout<<"ENTER THE ELEMENTS OF "<<i<<" ROW :"<<endl; 
		for(int j=0;j<2;j++)
		{
			cout<<"ENTER THE ELEMENT OF "<<j<<" COLUMN ; "<<endl;
			cin>>a[i][j];
		}
	}
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<2;j++)
			cout<<a[i][j]<<"\t";
		cout<<endl;
	}
	cout<<"COLUMN MAJOR MATRIX"<<endl;
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<2;j++)
		{
			offset=j*r+i;
			column[offset]=a[i][j];
		}
	}
	for(int i=0;i<6;i++)
		cout<<column[i]<<endl;
}