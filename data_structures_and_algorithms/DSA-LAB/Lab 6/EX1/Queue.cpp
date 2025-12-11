#include<iostream>
#include "LinkedList.h"
#include "Queue.h"
using namespace std;

template <class T>
Queue<T>::Queue()
{
	list=new List<T>();
	first=NULL;
	rear=NULL;
};

template <class T>
bool Queue<T>::IsEmpty()
{
	if ((first ==0)&&(rear ==0))
		return true;
	else return false;
};

template <class T>
void Queue<T>::Put(T element)
{
	Node<T> *temp = new Node<T>(element);
	if(IsEmpty())
	{
		list->Insert(0,temp);
		rear = temp;
		first = rear;
	}
	else
	{
		list->Insert(rear,temp);
		rear = temp;
	}
}

template <class T>
void Queue<T>::PrintQueue()
{
	list->printList();
}

template <class T>
T Queue<T>::Get()
{
	T data;
	if(!IsEmpty())
	{
		Node<T> *temp = first;
		first = first->GetNext();
		data = temp->getData();
		list->Delete(temp);
		return data;
	}
	else
	{
		rear = NULL;
		first = NULL;
		return 0;
	}
	
};
