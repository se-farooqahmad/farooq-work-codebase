#include<iostream>
#include "LinkedList.h"
using namespace std;

template <class T>
Node<T>::Node(T element)
{
	data = element;
	link = 0;
};

template <class T>
void Node<T>::setData(T pVal)
{
	data = pVal; 
};

template <class T>
T Node<T>::getData()
{
	return data;
};

template <class T>
Node<T>* Node<T>::GetNext()
{
	return link;
};

template <class T>
void Node<T>::SetNext(Node *x)
{   
    link = x;
	
};








template<class T>
List<T>::List()
{
	first = NULL;
};

template<class T>
Node<T>*  List<T>::GetFirst()
{
    return	first;
};

template <class T>
void List<T>::Insert(Node<T>* pBefore, Node<T>* pNew)
{
	if(!first)
	{ 
		first = pNew; 
	}
	else if( first && !pBefore)
	 {
		 pNew->SetNext(first);
		 first=pNew;
	 }

	else
	{
		pNew->SetNext( pBefore->GetNext() );
		pBefore->SetNext(pNew);
	}
};

template <class T>
void List<T>::printList()
{
	cout<<" *********************"<<endl;
      Node<T> *temp ;
	  temp=first;
	  int i=0;

    while(temp)
	{
		T test2 = temp->getData();
	    cout<<"Value in Node # "<< i+1<<" is "<<test2<<endl;
	    temp=temp->GetNext();
	    i++;
	}

};

template <class T>
 void List<T>::printReverseR(Node<T>* n)
 {
	 if(n)
	 {
		 printReverseR(n->GetNext());
		 cout<<n->getData()<<" ";
	 }
 };


template <class T>
void List<T>::printReverse()
{
	printReverseR(first);
};



template <class T>
void List<T>::Delete(Node<T>* pToBeDeleted)
{
      Node<T> *tmp ;
	  tmp=first;
	  
	  if(pToBeDeleted == first )
	  {
	    first = first->GetNext();
	  }
	  else
	  {
		     
            while(tmp->GetNext()!= pToBeDeleted )
			{ 
	           tmp=tmp->GetNext();
			}
	
			tmp->SetNext(pToBeDeleted->GetNext());
	  }

	  delete pToBeDeleted;
};