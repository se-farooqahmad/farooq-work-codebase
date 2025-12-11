#include <iostream>
#include <fstream>
using namespace std;
struct phnum
{
	char code[4];
	
	char no[5];
};
void main()
{
	phnum a[10];
	ifstream sync;
	sync.open("phnum.txt");
	int i=0,j=0;
	while(!sync.eof())
	{
		sync.getline(a[i].code,4,'-');
		sync.getline(a[i].no,5,'\n');
		i++;
	}

	ofstream print;
	print.open("outfile.txt");
	for(int i=0;i<10;i++)
		{
			print<<a[i].code<<a[j].no<<endl;
			cout<<a[i].code<<a[j].no<<endl;
		}
}
