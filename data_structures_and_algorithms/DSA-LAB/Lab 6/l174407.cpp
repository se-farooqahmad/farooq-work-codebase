#include <iostream>
using namespace std;
template <typename T>
class Node
{   public: 
Node() {};
	     Node(T element){data = element; link = NULL;};		 
		 void setData(T pVal){data = pVal;}; 
		 T getData(){return data;};
		 Node* GetNext(){return link;};
		 void SetNext(Node<T> *x){ link = x;}			 
   private: 
	     T data;
	     Node *link;
};
template <typename T>
class Queue
{
 private:
 Node<T> *rear;
 Node<T> *front;
 public:
	 Queue(){rear = NULL; front = NULL;};
 void enqueue( T value);
 bool empty();
 T dequeue();
 void display();
 };
template <typename T>
bool Queue<T>::empty()
{
	if(rear == NULL && front == NULL)
		return true;
	else
		return false;
}
template <typename T>
void Queue<T>::enqueue( T value)
{
	Node<T> *temp = new Node<T>();
	temp->setData(value);
	if(empty())
	{
		front=temp;
		rear=temp;
	}
	else
	{	
		rear->SetNext(temp);
		rear=temp;
	}
}
template <typename T>
void Queue<T>::display()
{
	cout<<"PRINT\t";
	Node<T> *temp = front;
	if(!empty())
	{
		while(temp != rear)
		{
			cout<<temp->getData()<<" ";
			temp=temp->GetNext();
		}
		cout<<temp->getData();
		cout<<endl;
	}
}
template <typename T>
T Queue<T>::dequeue()
{
	if(!empty())
	{
		T x;
		Node<T> *temp = front;
		front = front->GetNext();
		x=temp->getData();
		delete  temp;
		return x;
	}
	else
	{	cout<<"THE LIST IS EMPTY\n";
		return 0;
	}
}
void main()
{
	Queue<int> *q;
	q= new Queue<int>();
	cout<<"ENQUEUE\t";
	q->enqueue(5);
	q->display();
	cout<<"ENQUEUE\t";
	q->enqueue(7);
	q->display();
	cout<<"ENQUEUE\t";
	q->enqueue(8);
	q->display();
	cout<<"DEQUE\t";
	cout<<q->dequeue()<<endl;
	q->display();
	cout<<"DEQUE\t";
	cout<<q->dequeue()<<endl;
	q->display();
	system("pause");
}
