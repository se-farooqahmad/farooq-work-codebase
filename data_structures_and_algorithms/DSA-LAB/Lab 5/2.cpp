#include <iostream>
using namespace std;
template <class KeyType>
class Stack
{ //
public:
Stack(int max);
bool IsFull();
bool IsEmpty();
void Push(const KeyType item);
void print();
KeyType Pop();
int Postfix(char a[]);
private:
	KeyType * arr;
	int maxsize;
	int top;
};
template <class KeyType>
Stack<KeyType>::Stack(int max)
{
	maxsize = max;
	top = -1;
	arr = new KeyType[max];
}
template <class KeyType>
bool Stack<KeyType>::IsFull()
{
	if(top == maxsize)
		return true;
	else 
		return false;
}
template <class KeyType>
bool Stack<KeyType>::IsEmpty()
{
	if(top == -1)
		return true;
	else 
		return false;
}
template <class KeyType>
void Stack<KeyType>::Push(const KeyType item)
{	
	if(!IsFull())
	{	
		top++;
		arr[top] =item;
	}
	else
		cout<<"SORRY , THE STACK IS FULL\n";

}
template <class KeyType>
void Stack<KeyType>::print()
{
	for(int i=top;i>=0;i--)
		cout<<arr[i]<<" ";
}
template <class KeyType>
KeyType Stack<KeyType>::Pop()
{	
	if(IsFull())
		return 0;
	else
	{
		int temp=top;
		top--;
		return arr[temp];
	}
}
template <class KeyType>
int Stack<KeyType>::Postfix(char a[])
{
	int i=0;
	char x='0',y;
	KeyType z,c,d,final;
	while(a[i]!='\0')
	{
		if(a[i] == '+'||a[i] == '-'||a[i] == '*'||a[i] == '/')
		{
			d=Pop();
			c=Pop();
			if(a[i]=='+')
				final=c+d;
			else if(a[i]=='-')
				final=c-d;
			else if(a[i]=='*')
				final=c*d;
			else if(a[i]=='/')
				final=c/d;
			Push(final);
		}
		else
		{
			y=a[i];
			z=y-x;
			Push(z);
		}
		i++;
	}
	return Pop();
}
void main()
{
	char arr[100];
	cout<<"ENTER THE EXPRESSION\n";
	cin.getline(arr,100,'\n');
	Stack<int> stack(10);
	cout<<stack.Postfix(arr);
	system("pause");
}