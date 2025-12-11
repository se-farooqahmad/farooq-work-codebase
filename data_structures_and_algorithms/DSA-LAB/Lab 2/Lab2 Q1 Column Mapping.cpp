//COLUMN MAPPING
#include<iostream>
using namespace std;
void main()
{
	//initializing 3D array
	int p[2][2][2];
	for(int i=0;i<2;i++)
	{
		for(int j=0;j<2;j++)
		{
			for(int k=0;k<2;k++)
			{
				cin>>p[i][j][k];
			}
		}
	}
	cout<<endl<<endl;
	for(int i=0;i<2;i++)
	{
		for(int j=0;j<2;j++)
		{
			for(int k=0;k<2;k++)
			{
				cout<<p[i][j][k]<<" ";
			}
			cout<<endl;
		}
		cout<<endl<<endl;
	}
	//mapping 3D array to 1D array
	int count=0;
	int a[8];
	for(int i=0;i<2;i++)//depth
	{
		for(int j=0;j<2;j++)//row
		{
			for(int k=0;k<2;k++)//column
			{
				a[count]=p[i][k][j];
				count++;
			}
		}
	}
	//
	for(int i=0;i<8;i++)
	{
		cout<<a[i]<<" ";
	}
	system ("pause");
}