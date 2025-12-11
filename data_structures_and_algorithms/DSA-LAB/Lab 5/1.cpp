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
void main()
{
	Stack<int> stack(6);
	cout<<"\nPush\n";
	stack.Push(1);
	stack.Push(2);
	stack.Push(3);
	stack.Push(4);
	stack.Push(5);
	stack.Push(6);
	stack.print();
	cout<<"\nPOP\n";
	cout<<stack.Pop();
	cout<<endl;
	stack.print();
	cout<<endl;
	cout<<stack.Pop();
	cout<<endl;
	stack.print();
	system("pause");
}