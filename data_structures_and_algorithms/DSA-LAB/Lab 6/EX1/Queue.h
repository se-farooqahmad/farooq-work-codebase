#ifndef QUEUE_H
#define QUEUE_H

#include<iostream>
#include "LinkedList.h"
template<class T>
class Queue
{
private:
	List <T>* list;
	Node<T>* first;
	Node<T>* rear;

public:
	//contructor
	Queue();

//puts element at the rear end of the Queue if it is not full. Must be O(1)
	void Put(T element);

//if queue not empty then delete the element at front of the Queue. Must be O(1)
	T Get();

	//return true if the Queue is empty and false if it is not
	bool IsEmpty();

	//return true if the Queue is full and false if it is not
	bool IsFull();
	void PrintQueue();

};
#endif
