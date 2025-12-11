#include <iostream>
using namespace std;
template <typename T>
class Node
{   public: 
Node() {};
Node(T element) {data = element; link = NULL;};   
void setData(T pVal){data = pVal;}; 
T getData(){return data;};
Node<T>* GetNext(){return link;};
void SetNext(Node<T> *x){ link = x;}			 
private: 
	     T data;
	     Node *link;
};
template <typename T>
class SCList
{
   public: 
	   SCList(){last = NULL;};
	   Node<T>* GetFirst();
		 void Insert(Node<T>* pBefore, Node<T>* pNew);
		 void Delete(Node<T>* pToBeDeleted);
		 void printList();		 		 
   private: 
	     Node<T> *last ;
		
};
template <typename T>
Node<T>* SCList<T>::GetFirst()
{
		return last->GetNext();
}
template <typename T>
void SCList<T>::Insert(Node<T>* pBefore, Node<T>* pNew)
{
	cout<<"INSERT\t";
	if (last == NULL)
	{
		pNew->SetNext(pNew);
		last = pNew;
	}
	else if(pBefore == last)
	{
		pNew->SetNext(GetFirst());
		pBefore->SetNext(pNew);
		last = pNew;
	}
	else
	{
		Node<T> *temp =pBefore->GetNext();
		pBefore->SetNext(pNew);
		pNew->SetNext(temp);
		while(temp->GetNext() != GetFirst())
		{
			temp= temp ->GetNext();
		}
		last = temp;
		
	}
}
template <typename T>
void SCList<T>::printList()
{
	cout<<"PRINT\t";
	if(last != NULL)
	{
		Node<T> *temp = GetFirst();
		while(temp != last)
		{ 
			cout << temp->getData()<<"   ";
			temp=temp->GetNext();
		}
		cout << temp->getData()<<endl;
	}
}
template <typename T>
void SCList<T>::Delete(Node<T>* pToBeDeleted)
{
	cout<<"DELETE\t";
	if(last != NULL)
	{
		Node<T> *temp = GetFirst();
		while (temp->GetNext() != pToBeDeleted)
		 temp = temp->GetNext();
		if(pToBeDeleted == last)
		{
			temp->SetNext(GetFirst());
			last = temp;
		}
		else if( pToBeDeleted == GetFirst())
		{
			last->SetNext(GetFirst()->GetNext());
		}
		else
		{
			Node<T> *temp1 = temp->GetNext()->GetNext();
			temp->SetNext(temp1);
		}
		delete pToBeDeleted;
	}
}
void main()
{
	Node<int> *a, *b, *c, *d, *e;
	a = new Node<int>(200);
	b = new Node<int>(30);
	c = new Node<int>(40);
	d = new Node<int>(45);
	e = new Node<int>(450);
	SCList<int> *list;
	list = new SCList<int>();
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
	list->Delete(b);
	list->printList();
	list->Delete(c);
	list->printList();
	list->Delete(a);
	list->printList();
	system("pause");
}