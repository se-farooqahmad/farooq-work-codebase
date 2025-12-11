#include<iostream>
#include "Queue.h"
using namespace std;

template <class T>
Queue<T>::Queue()
{
	size = 10;
	queue = new T [size];
	front = 0;
	rear = -1;
	indexFilled = 0;
};

template <class T>
bool Queue<T>::IsEmpty()
{
	if (indexFilled == 0)
		return true;
	else return false;
};

template <class T>
void Queue<T>::Put(T element)
{
	rear++;
	indexFilled++;

	arr[rear] = element;
	
};

//template <class T>
//void Queue<T>::PrintQueue()
//{
//	list->printList();
//}
//
//template <class T>
//T Queue<T>::Get()
//{
//	T data;
//	if(!IsEmpty())
//	{
//		Node<T> *temp = first;
//		first = first->GetNext();
//		data = temp->getData();
//		list->Delete(temp);
//		return data;
//	}
//	else
//	{
//		rear = NULL;
//		first = NULL;
//		return 0;
//	}
	
//};
