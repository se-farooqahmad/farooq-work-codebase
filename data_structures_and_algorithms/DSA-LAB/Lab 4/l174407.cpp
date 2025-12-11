#include <iostream>
using namespace std;
template <class T>
class Node 
{
  private:
   T data;
   Node *next ;
   Node *previous ;

public:
	Node(){};
	Node(T pdata){data =pdata;
	next = NULL;
	previous = NULL;
	};
void setData(T pVal){ data= pval;};
 T getData(){ return data;};
 Node<T>* getNext(){ return next;};
void setNext(Node* x){next =x;};
 Node<T>* getPrevious(){return previous;};
void setPrevious(Node* x){previous = x;};

};

template <class T>
class DList
{ 
 private:
  Node<T> *first ;

public:
	DList(){ first = NULL;};
	Node<T>* getFirst() { return first;};
void Insert(Node<T>* pBefore, Node<T>* pNew);//3 marks

//Deletes the node pToBeDeleted
void Delete(Node<T>* pToBeDeleted);//3 marks

//prints the contents of the list
void printList();
void swap(Node<T> *f, Node<T> *l); //5 marks
};

template <class T>

void DList<T>::Insert(Node<T> *pBefore, Node<T> *pNew)
{
	if(first==NULL)
	{
		first=pNew;
	}
	else
	{
		pNew->setPrevious(pBefore);
		pNew->setNext(pBefore->getNext());
		pBefore->setNext(pNew);
	}
}
template <class T>
void DList<T>::printList()
{cout<<"PRINT : ";
	Node<T> *a = first;
	while(a)
	{
		cout<<a->getData()<<"  ";
		a=a->getNext();
	}
	cout<<endl;
}
template <class T>
void DList<T>::Delete(Node<T>* pToBeDeleted)
{
	Node<T> *a = pToBeDeleted->getPrevious();
	Node<T> *b = pToBeDeleted->getNext();
	a->setNext(b);
	delete pToBeDeleted;
};
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
	list->printList();
	list->Insert(a , b);
	list->printList();
	list->Insert(b , c);
	list->printList();
	list->Insert(a , d);
	list->printList();
	list->Insert(b,e);
	list->printList();
	list->Delete(e);
	list->printList();
	system ("pause");
	return 0;
}