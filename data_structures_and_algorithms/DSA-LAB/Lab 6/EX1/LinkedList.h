#ifndef HEAD_H
#define HEAD_H

#include<iostream>
using namespace std;


template <class T>
class Node
{
private:
	Node *link;
	T data;
public:
	Node(T);
	void setData(T pVal);
	T getData();
	Node* GetNext();
	void SetNext(Node *x);
};




template <class T>
class List
{
private:
	Node<T>* first;
public:
	List();
	Node<T>* GetFirst();
	void Insert(Node<T>* , Node<T>*);
	void printList();
	void printReverseR(Node<T>*);
	void printReverse();
	void Delete(Node<T>*);
};
#endif