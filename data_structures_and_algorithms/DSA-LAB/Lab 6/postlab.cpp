#include <iostream>
using namespace std;
class queue
{ 
private:
	int *a;
	int front;
	int rear;
	int count;
	int size;
public:
	queue(int s);
	bool IsFull();
	bool IsEmpty();
	void enqueue(int val);
	int dequeue();
	void print();
};
queue::queue(int s)
{
	size = s;
	a = new int [size];
	front =-1;
	rear =-1;
	count =0;
}

bool queue::IsEmpty()
{
	if(rear == -1 && front == -1)
		return true;
	else if(rear == -1 && front == 0)
		return true;
	else 
		return false;
}
bool queue::IsFull()
{
	if(size == count)
		return true;
	else 
		return false;
}
void queue::print()
{
	cout<<"PRINT\t";
	if(!IsEmpty())
	{

		for(int i=front;i<=rear;i++)
		cout<<a[i]<<" ";
	}
	cout<<endl;
}
void queue :: enqueue( int val)
{
	cout<<"ENQUEUE\t";
	if(IsEmpty())
	{
		rear ++;
		front ++;
		a [rear] =val;
		a [front] = val;
		count++;
	}
	else if(!IsFull())
	{
		rear ++;
		a [rear] = val;
		count++;
	}
	else if(IsFull())
		cout<<"LIST IS FULL";
	cout<<endl;
}
int queue::dequeue()
{
	cout<<"\nDEQUEUE\t";
	if(IsEmpty())
	{
		cout<<"LIST IS EMPTY ";
		rear= -1;
		front =-1;
		return 0;
		
	}
	else
	{
		int temp = a[front];
		for(int i=front ;i<rear;i++)
		{
			a[i]=a[i+1];
		}
		a[rear] = NULL;
		rear--;
		count--;
		return temp;
	}
	cout<<endl;
}
void main()
{
	queue q(3);
	q.enqueue(1);
	q.print();
	q.enqueue(2);
	q.print();
	q.enqueue(3);
	q.print();
	q.enqueue(4);
	q.print();
	cout<<q.dequeue();
	q.print();
	q.enqueue(4);
	q.print();
	cout<<q.dequeue();
	q.print();
	cout<<q.dequeue();
	q.print();
	q.enqueue(1);
	q.print();
	q.enqueue(2);
	q.print();
	q.enqueue(3);
	q.print();
	q.enqueue(4);
	q.print();
	system("pause");
}