#include <iostream>
#include <fstream>
using namespace std;

#ifndef MATRIX_H
#define MATRIX_H

template <class elementType>
class TwoDMatrix
{
public:
	//constructor
	TwoDMatrix();
	//destructor
	~TwoDMatrix();

	//input the matrix from the file
	void TakeInput(ifstream &stream);

	//return the total rows of the matrix
	int GetRows();

	//return the total cols of the matrix
	int GetCols();

	//Get a value of an element at index i,j and return in val
	//return false on error and true on valid operation
	bool Get(int i,int j,elementType &val);

	//set the value of an element at location i,j to val
	//return false on error and true on valid operation
	bool Set(int i,int j,elementType val);

	//should print the matrix in 2D matrix form
	void Print();

	void initialize(int rows, int columns);
	
private:
	elementType **Arr;
	int row,col;

};

//add the implementation of the functions here
template <class elementType>
TwoDMatrix<elementType>::TwoDMatrix()
{
	row=col=0;
	Arr=0;
}

template <class elementType>
TwoDMatrix<elementType>::~TwoDMatrix()
{
	for(int i=0; i<row; i++)
		delete [] Arr[i];

	delete[]Arr;
}

template <class elementType>
void TwoDMatrix<elementType>::initialize(int rows, int columns)
{
	row=rows;
	col=columns;

	Arr= new elementType*[row];
	for(int i=0; i<row; i++)
		Arr[i]= new elementType[col];
}

template <class elementType>
void TwoDMatrix<elementType>::TakeInput(ifstream &stream)
{
	for(int i=0; i<row; i++)
		for(int j=0; j<col; j++)
			stream>>Arr[i][j];
}

template <class elementType>
int TwoDMatrix<elementType>::GetRows()
{
	return row;
}
template <class elementType>
int TwoDMatrix<elementType>::GetCols()
{
	return col;
}

template <class elementType>
bool TwoDMatrix<elementType>::Get(int i,int j,elementType &val)
{
	bool rt=false;
	if(Arr)
	{
		val=Arr[i][j];
		rt=true;
	}
	return rt;
}

template <class elementType>
bool TwoDMatrix<elementType>::Set(int i,int j,elementType val)
{
	bool rt=false;
	if(Arr)
	{
		Arr[i][j]=val;
		rt=true;
	}
	return rt;
}

template <class elementType>
void TwoDMatrix<elementType>::Print()
{
	for(int i=0; i<row; i++)
	{	for(int j=0; j<col; j++)
		{cout<<Arr[i][j]<<" ";}
		cout<<endl;
	}
	
}

#endif