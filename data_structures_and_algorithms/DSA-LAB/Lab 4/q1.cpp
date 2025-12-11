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
	Node() {};
	Node(T pdata) {data = pdata; next = NULL; previous = NULL; };
	void setData(T pVal) {data = pval;};
	T getData(){ return data;};
	Node<T>* getNext(){ return next;};
	void setNext(Node<T>* x){ next = x;};
	Node<T>* getPrevious(){ return previous;};
	void setPrevious(Node<T>* x){ previous = x;};
};

template <class T>
class DList
{ 
 private:
  Node<T> *first ;

public:
	DList(){ first = NULL;}; 
	Node<T>* getFirst(){ return first;};
	void Insert(Node<T>* pBefore, Node<T>* pNew);
	void Delete(Node<T>* pToBeDeleted);
	void printList();
	void swap(Node<T> *f, Node<T> *l);
	~DList();
};
template <class T>
void DList<T>::Insert(Node<T>* pBefore, Node<T>* pNew)
{
	cout<<"INSERT\t";
	if (first == NULL)
	{
		first = pNew;
	}
	else if (pBefore->getNext() == NULL)
	{
		pNew->setPrevious(pBefore);
		pNew->setNext(NULL);
		pBefore->setNext(pNew);
	}
	else
	{
		Node<T> *temp = pBefore->getNext();
		pNew->setPrevious(pBefore);
		pNew->setNext(temp);
		pBefore->setNext(pNew);
		temp->setPrevious(pNew);
	}
}
template <class T>
void DList<T>::printList()
{
	cout<<"PRINT\t";
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
	cout<<"DELETE\t";
	if(pToBeDeleted->getNext() == NULL)//TO DEAL LAST ELEMENT
	{
		Node <T> *temp = pToBeDeleted->getPrevious();
		temp->setNext(NULL);
	}
	else if(pToBeDeleted->getPrevious() == NULL)
	{
		Node <T> *temp1 = pToBeDeleted->getNext();
		temp1->setPrevious(NULL);
		first = temp1;
	}
	else
	{
		Node <T> *temp = pToBeDeleted->getPrevious();
		Node <T> *temp1 = pToBeDeleted->getNext();
		temp->setNext(temp1);
		temp1->setPrevious(temp);
	}
	delete pToBeDeleted;
}
template <class T>
void DList<T>::swap(Node<T> *f, Node<T> *l)
{
	cout<<"SWAP\t";
	double count1=0, count2=0;
	Node<T> *temp = first;
	while(temp !=NULL)//checks wether element exists or not.
	{
		if(temp == f)
			count1= 0.5;
		else if( temp == l)
			count2= 0.5;
		temp=temp->getNext();
	}
	if(count1>0&&count2>0)
	{
		temp=first;	
	while(temp != f)//To check the location in the list
	{	
		count1++;
		temp=temp->getNext();
	}
	temp=first;
	while(temp != l )//To check the location in the list	
	{
		count2++;
		temp=temp->getNext();
	}
	if(count1>count2)//to check which element comes first in the list
	{
		temp=f;
		f=l;
		l=temp;
	}
	temp = l->getNext();
	Node <T> * temp1 =f->getNext();
	Node <T> * temp2 = f->getPrevious();
	if(f == first)	
	{
		l->setPrevious(NULL);
		first =l;
	}
	else
	{
		temp2->setNext(l);
		l->setPrevious(temp2);
	}
	l->setNext(temp1);
	temp1->setPrevious(l);
	while(temp1->getNext() != l)
		temp1 = temp1->getNext();
	temp1->setNext(f);
	f->setPrevious(temp1);
	if (temp == NULL)
		f->setNext(NULL);
	else
	{
		f->setNext(temp);
		temp->setPrevious(f);
	}
	}
	else
		cout<<"ALL THE ELEMENTS DO NOT EXIST IN THE LIsT\n";
}
template <class T>
DList<T>::~DList()
{
	Node<T> *a;
	while(temp != NULL)
	{
		temp = first;
		first = first->getNext();
		delete temp;
	}
}
void main()
{	Node<int> *a, *b, *c, *d, *e , *f;
	a = new Node<int>(200);
	b = new Node<int>(30);
	c = new Node<int>(40);
	d = new Node<int>(45);
	e = new Node<int>(450);
	f = new Node<int>(700);
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
	list->Delete(a);
	list->printList();
	list->Insert(c ,f);
	list->printList();
	list->swap(a,f);
	list->printList();
	list->swap(b,f);
	list->printList();
	system("pause");
}