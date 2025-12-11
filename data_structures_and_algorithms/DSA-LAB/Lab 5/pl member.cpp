#include <iostream>
using namespace std;
template <class KeyType>
class Stack
{ 
public:
Stack(int max);
bool IsFull();
bool IsEmpty();
void Push(const KeyType item);
void print();
KeyType Pop();
void CopyStack(Stack<KeyType> s1,Stack<KeyType> & s2);
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
	if(IsEmpty())
		cout<<"STACK IS EMPTY\n";
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
void  Stack<KeyType>::CopyStack(Stack<KeyType> s1,Stack<KeyType> &s2)
{
	KeyType a;
	if(!s1.IsEmpty())
	{
		a=s1.Pop();
		CopyStack(s1,s2);
		s2.Push(a);
	}
}
void main()
{
	int size =6;
	Stack<int> stack(size);
	Stack<int> stack1(size);
	cout<<"STACK1\n";
	stack.Push(1);
	stack.Push(2);
	stack.Push(3);
	stack.Push(4);
	stack.Push(5);
	stack.Push(8);
	stack.print();
	cout<<"\nSTACK2 BEFORE COPYING\n";
	stack1.print();
	cout<<"\nSTACK2 AFTER COPYING\n";
	stack.CopyStack(stack, stack1);
	stack1.print();
	cout<<"\nSTACK1 AFTER COPYING\n";
	stack.print();
	system("pause");
}