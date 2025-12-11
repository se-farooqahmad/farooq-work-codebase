#include<iostream>
using namespace std;
class matrix{

int **p;
int r;
int c;
int *rowmajor;
public:

    matrix(int row,int col);
void display2D();
 void MULTIPLY_ROW_MAJOR(matrix & , matrix &);
 void displayRowMajor();
 void convertRowMajor_To_2D();
 ~matrix();
};
matrix::matrix(int row,int col)
{
r=row;
c=col;
p = new int*[r];
for(int i=0;i<r;i++)
    {
        p[i]=new int[c];
        for(int j=0;j<c;j++)
            p[i][j]=(i+j);
}
int offset=0;
rowmajor =new int [r*c];
for(int i=0;i<r;i++)
	{
		for(int j=0;j<c;j++)
		{
			offset=i*c+j;
			rowmajor[offset]=p[i][j];
		}
	}

}
void matrix::display2D()
{
	cout<<"THE 2D MATRIX IS : \n";
	for(int i=0;i<r;i++)
	{
		for(int j=0;j<c;j++)
			cout<<p[i][j]<<"\t";
		cout<<endl;
	}
	cout<<endl;
}
void matrix::displayRowMajor()
{
	cout<<"THE 1D ROW MAJOR IS : \n";
	for(int i=0;i<r*c;i++)
		cout<<rowmajor[i]<<"\t";
	cout<<endl<<endl;
}
void matrix::MULTIPLY_ROW_MAJOR(matrix & a, matrix & b)
{
	int offset=0;
	r=a.r;
	c=b.c;
	rowmajor=new int [(a.r)*(b.c)];
	for (int i=0;i<a.r*a.c;i=i+2)
	{
		for(int j=0;j<b.c;j++)	
		{	
			rowmajor[offset]=a.rowmajor[i]*b.rowmajor[j]+a.rowmajor[i+1]*b.rowmajor[j+c];
			offset++;
		}
	}
}
void matrix::convertRowMajor_To_2D()
{
	p = new int*[r];
	for(int i=0;i<r;i++)
    {
        p[i]=new int[c];
	}
	int offset=0;
	for(int i=0;i<r;i++)
	{
		for(int j=0;j<c;j++)
		{
			offset=i*c+j;
			p[i][j]=rowmajor[offset];
		}
	}

}
matrix::~matrix()
{
	delete []rowmajor;
	for(int i=0;i<r;i++)
		delete []p[i];
	delete []p;
}
void main()
{
    matrix a(3,2);
    matrix b(2,3);
	a.display2D();
	a.displayRowMajor();
	b.display2D();
	b.displayRowMajor();
	matrix c(3,3);
	c.MULTIPLY_ROW_MAJOR(a,b);
	c.displayRowMajor();
	c.convertRowMajor_To_2D();
	c.display2D();
system("pause");
}