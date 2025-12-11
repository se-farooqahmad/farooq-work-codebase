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
			pNew->setPrev(NULL);
			pNew->setNext(NULL);
			//cout<<"a";
		}
		
		else if(pBefore == NULL && first != NULL)
		{
			pNew->setNext(first);
			first->setPrev(pNew);
			first = pNew;
			first->setPrev(NULL);
			//cout<<"b";
		}
		
	
		else
		{
		
			pNew->setNext(pBefore->getNext());
			if(pNew->getNext()!=NULL)
				(pBefore->getNext())->setPrev(pNew);
			pBefore->setNext(pNew);
			pNew->setPrev(pBefore);
			//cout<<"c";
		}
	}
	//Deletes the node pToBeDeleted
	void Delete(Node<T>* pToBeDeleted)
	{
		int a = 1;
		Node < T > *temp1, *temp2;
		temp1 = first;
		temp2 = first->GetNext();
		while (a != 0)
		{
			if(pToBeDeleted == first)
				{
					first = temp1->GetNext();
					(temp1->GetNext())->setPrev(NULL);
				}
			else if (temp2 == pToBeDeleted)
			{
				temp1->SetNext(temp2->GetNext());
				(temp2->GetNext())->setPrev(temp1)
				a = 0;
			}
			else
			{
				temp1 = temp2;
				temp2 = temp2->GetNext();
			}
		}
	}
	//prints the contents of the list
	void printList()
	{
		Node<T> *temp = first;
		while(temp != NULL)
		{
			cout<<temp->getData() << "\t";
			temp=temp->getNext();
		}
	}
	//Swaps the two nodes in the list.
      void Swap(Node<T>* Node1, Node<T>* Node2)
	  {
		  if(Node1!=first && Node2==Node1->getNext() && Node2->getNext()!=NULL)
		  {
			  Node <T> *temp = first;
			  while (temp->getNext()!=Node1)
			  {
				  temp = temp->getNext();
			  }
			  temp->setNext(Node2);
			  Node2->setPrev(Node1->getPrev());
			  Node1->setNext(Node2->getNext());
			  (Node2->getNext())->setPrev(Node1);
			  Node2->setNext(Node1);
			  Node1->setPrev(Node2);
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

	//list->Delete(c);
	//cout<<"\nAfter deleting first node"<<endl;
	//list->printList();

	list->Swap(b , c);

	cout<<"\nAfter swaping the two nodes"<<endl;
	list->printList();
	system("pause");
	return 0;
}
