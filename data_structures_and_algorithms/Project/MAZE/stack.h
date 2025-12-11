#include<iostream>
using namespace std;

template<class point>
class Stack
{ 
private:
	point* stack;
	int top;	
	int size;
public:

	Stack()
	{
		top = -1;
		size = 0;
		stack = new point[size];
	}

	
	Stack(int s)
	{
		size = s;
		stack = new point[size];
		top = -1;

	}

	bool IsFull()
	{
		if (top == size - 1)
			return true;
		else
			return false;

	}


	bool IsEmpty()
	{
		if (top == -1)
			return true;
		else
			return false;
	}


	bool Push(const point item)
	{
		top++;
		stack[top] = item;
		size++;
		return true;
	}

	point Pop()
	{
		if (!IsEmpty())
		{
			point x = stack[top];
			top--;
			size--;
			return x;
		}
	}
	int getTop()
	{
		return top;
	}
	/*char display(int index)
	{
		return stack[index];
	}
	char getLast()
	{
		return stack[top];
	}*/
};
