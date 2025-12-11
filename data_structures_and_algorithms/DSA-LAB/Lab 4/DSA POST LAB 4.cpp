#include <iostream>
using namespace std;

#ifndef DLIST_H
#define DLIST_H

template<class T>
class Node 
{
private:
	T data;
	Node *next ;
	Node *prev ;

public:
	// constructor
	Node(T pdata)
	{
		data = pdata;
		next = NULL;
		prev = NULL;
	}
	void setData(T pVal)
	{
		data = pVal;
	}
	// returns the T data in the Node
	T getData()
	{
		return data;
	}
	// returns the link to the next node
	Node* getNext()
	{
		return next;
	}
	// sets the link to the next node
	void setNext(Node* x)
	{
		next = x;
	}
	// returns the link to the previous node
	Node* getPrev()
	{
		return prev;
	}
	// sets the link to the previous node
	void setPrev(Node* x)
	{

		prev = x;
	}
};

template<class T>
class DList
{ 
private:
	Node<T> *first ;
public:
	DList()
	{
		first = NULL;
	}
	
	//Inserts the node pNew after the node pBefore
	// if the list is empty, it makes pNew the first node of the list
	void Insert(Node<T>* pBefore, Node<T>* pNew)
	{
		
		if (first == NULL)
		{
			first = pNew;
		}
		
		else if(pBefore == NULL && first != NULL)
		{
			first->setNext(pNew);
			pNew->setNext(first);
			first->setPrev(pNew);
			pNew->setPrev(first);
			first = pNew;
		}
		
	
		else
		{
		
			pNew->setNext(pBefore->getNext());
			if(pNew->getNext()!=NULL)
				(pBefore->getNext())->setPrev(pNew);
			pBefore->setNext(pNew);
			pNew->setPrev(pBefore);
			if(pNew->getNext() == NULL)
			{
				pNew->setNext(first);
				first->setPrev(pNew);
			}
		}
	}




	//Deletes the node pToBeDeleted
	void Delete(Node<T>* pToBeDeleted)
	{
		int a = 1;
		Node < T > *temp1, *temp2, *temp3;
		temp1 = first;
		temp2 = first->getNext();
		while (a != 0)
		{
			if(pToBeDeleted == first)
				{
					temp3 = temp1->getPrev();
					temp2->setPrev(temp3);
					(temp3)->setNext(temp2);
					temp1->setNext(NULL);
					temp1->setPrev(NULL);
					first = temp2;
					a=0;
				}
			else if (temp2 == pToBeDeleted)
			{
				temp1->setNext(temp2->getNext());
				(temp2->getNext())->setPrev(temp1);
				a = 0;
			}
			//else if(
			else
			{
				temp1 = temp2;
				temp2 = temp2->getNext();
				if(temp2 == first)
				{
					cout<<"Node not found\n";
					a=0;
				}
			}
		}
	}




	////prints the contents of the list
	void printList()
	{
		int i=0;
		Node<T> *temp = first;
		cout<<temp->getData() << "\t";
		temp=temp->getNext();
		while(temp != first)
		{
			cout<<temp->getData() << "\t";
			temp=temp->getNext();
			i++;
		}
	}




	//Swaps the two nodes in the list.
      void Swap(Node<T>* Node1, Node<T>* Node2)
	  {
		  if(Node1 == Node2->getNext())
		  {
			  Node <T> *temp1 = Node2->getPrev() , *temp2 = Node1->getNext();
			  temp1->setNext(Node1);
			  Node1->setPrev(temp1);
			  Node2->setNext(temp2);
			  temp2->setPrev(Node2);
			  Node1->setNext(Node2);
			  Node2->setPrev(Node1);
			  if(Node1 == first)
			  {
				  if(Node1 == first)
				  {
					  first = Node2;
				  }
			  }
			  else
			  {
				  if(Node1 == first)
				  {
					  first = Node2;
				  }
				  else if(Node2 == first)
				  {
					  first = Node1;
				  }
			  }
		  }
		  else if(Node2 == Node1->getNext())
		  {
			   Node <T> *temp1 = Node1->getPrev() , *temp2 = Node2->getNext();
			  temp1->setNext(Node2);
			  Node2->setPrev(temp1);
			  Node1->setNext(temp2);
			  (temp2)->setPrev(Node1);
			  Node2->setNext(Node1);
			  Node1->setPrev(Node2);
			  if(Node2 == first)
			  {
				  first = Node1;
			  }
			  else if(Node1 == first)
			  {
				  first = Node2;
			  }
		  }
		  else if(Node1 && Node2)
		  {
			  Node<T> *temp, *t1, *t2, *temp1, *temp2, *temp3, *temp4;
			  int step1 = 0, step2 = 0;

			  t1 = first;
			  t2 = first;

			  while(t1 != Node1)
			  {
				  t1 = t1->getNext();
				  step1++;
			  }
			  while(t2 != Node2)
			  {
				  t2 = t2->getNext();
				  step2++;
			  }
			  if(step1 > step2)
			  {
				  temp = Node1;
				  Node1 = Node2;
				  Node2 = temp;
			  }

			  temp1=Node1->getPrev();
			  temp2=Node1->getNext();
			  temp3=Node2->getPrev();
			  temp4=Node2->getNext();

			  Node1->setNext(temp4);
			  Node1->setPrev(temp3);
			  Node2->setNext(temp2);
			  Node2->setPrev(temp1);

			  temp1->setNext(Node2);
			  temp2->setPrev(Node2);
			  temp3->setNext(Node1);
			  temp4->setPrev(Node1);
			  if(Node1 == first)
			  {
				  first = Node2;
			  }
		  }
	  }
};
#endif
int main()
{   
	Node<int> *a, *b, *c, *d, *e;
	
	a = new Node<int>(200);
	b = new Node<int>(30);
	c = new Node<int>(40);
	d = new Node<int>(45);
	e = new Node<int>(450);

	DList<int> *list;

	list = new DList<int>();

	list->Insert(0 , a);
	list->Insert(a , b);
	list->Insert(b , c);
	list->Insert(c , d);
	list->Insert(d , e);
	list->printList();

	list->Delete(a);
	cout<<"\nAfter deleting first node"<<endl;
	list->printList();

	list->Swap(d,b);

	cout<<"\nAfter swaping the two nodes"<<endl;
	list->printList();
	system("pause");
	return 0;
}