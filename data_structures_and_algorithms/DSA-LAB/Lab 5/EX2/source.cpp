#include "header.h"
#include <iostream>
using namespace std;

int main()
{   	
	Stack<int> *st =new Stack<int>();
	int a=0,b=0;

	//if(st->IsEmpty())
	//	cout<<"Stack is currently empty"<<endl;

	//st->Push(1);
	//st->Push(2);
	//st->Push(3);

	//while (!st->IsEmpty())
	//{
	//	int value=st->Pop();
	//	cout<<value<<endl;
	//}
	

	char arr[1000] = {1,2,'+',3,'*',4,5,'+',6,'%','+'};
	for(int i = 0 ; i<11 ;i++)
	{
		switch (arr[i])
		{

		    case '+' :
			{
				a = st->Pop();
				b = st->Pop();
				if(st->IsEmpty() == 1)
				{
					cout<<a+b<<endl;
					st->Push(a+b);
				}
				else
				{
					st->Push(a+b);
				}
				break;
			}
		    case '*' :
			{
				a = st->Pop();
				b = st->Pop();
				if(st->IsEmpty())
				{
					cout<<a*b<<endl;
					st->Push(a*b);
				}
				else
				{
					st->Push(a*b);
				}
				break;
			}
			case '/' :
			{
				a = st->Pop();
				b = st->Pop();
				if(st->IsEmpty())
				{
					cout<<b/a<<endl;
					st->Push(b/a);
				}
				else
				{
					st->Push(b/a);
				}
				break;
			}
			case '-' :
			{
				a = st->Pop();
				b = st->Pop();
				if(st->IsEmpty())
				{
					cout<<a-b<<endl;
					st->Push(a-b);
				}
				else
				{
					st->Push(a-b);
				}
				break;
			}
			case '%' :
			{
				a = st->Pop();
				b = st->Pop();
				if(st->IsEmpty() == 1)
				{
					cout<<b%a<<endl;
					st->Push(b%a);
				}
				else
				{
					st->Push(b%a);
				}
				break;
			}
			default :
			{
				st->Push(arr[i]);
				break;
			}
		}
	}


	system("pause");
	return 0;

}
