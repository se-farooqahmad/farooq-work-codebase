#include <iostream>
using namespace std;
template <typename T>
class Node
{   public: 
Node() {};
Node(T element) {data = element; link = NULL;plink = NULL;};   
void setData(T pVal){data = pVal;}; 
T getData(){return data;};
Node<T>* GetNext(){return link;};
void SetNext(Node<T> *x){ link = x;};	
Node<T>* GetPrevious(){return plink;};
void SetPrevious(Node<T> *x){plink =x;};
private: 
	     T data;
	     Node *link;
		 Node *plink;
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
		 void swap(Node<T>* a , Node<T>* b);
		 ~SCList();
   private: 
	     Node<T> *last ;
		
};
template <typename T>
Node<T>* SCList<T>::GetFirst()
{
		return last->GetNext();
}
template <typename T>
SCList<T>::~SCList()
{
	Node<T> *temp= GetFirst();
	while(temp != NULL)
	{
		temp = first;
		first = first->getNext();
		delete temp;
	}
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
		pNew->SetPrevious(pBefore);
		pBefore->SetNext(pNew);
		last = pNew;
	}
	else
	{
		Node<T> *temp =pBefore->GetNext();
		pBefore->SetNext(pNew);
		pNew->SetPrevious(pBefore);
		pNew->SetNext(temp);
		temp->SetPrevious(pNew);
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
			GetFirst()->SetPrevious(temp);
			last = temp;
		}
		else if( pToBeDeleted == GetFirst())
		{
			last->SetNext(GetFirst()->GetNext());
			GetFirst()->GetNext()->SetPrevious(last);
		}
		else
		{
			Node<T> *temp1 = temp->GetNext()->GetNext();
			temp->SetNext(temp1);
			temp1->SetPrevious(temp);
		}
		delete pToBeDeleted;
	}
}
template <typename T>
void SCList<T>::swap(Node<T>* a , Node<T>* b)
{
	cout<<"SWAP\t";
	int check1=0,check2=0,check3=0,check4=0;
	Node<T> *temp =GetFirst();
	while(temp != last)
	{ 
		if(temp == a)
			check1++;
		else if(temp == b)
			check2++;
		temp = temp->GetNext();
	}
	if(temp == a)
		check1++;
	else if(temp == b)
		check2++;
	temp = GetFirst();
	for(temp;temp!=a&&check1>0;temp=temp->GetNext())
		check3++;
	temp = GetFirst();
	for(temp;temp!=b&&check2>0;temp=temp->GetNext())
		check4++;
	if(check3>check4)
	{
		temp = a;
		a = b;
		b = temp;
	}
	if(last != NULL && check1 >0 && check2 >0)
	{
		Node<T> *temp1 = b->GetPrevious();
		Node<T> *temp2 = b->GetNext(); 
		if(a==GetFirst())
		{
			last->SetNext(b);
			b->SetPrevious(last);
			if(check3-check4 == 1||check3-check4 == -1)
			{
				b->SetNext(a);
				a->SetPrevious(b);
				a->SetNext(temp2);
				temp2->SetPrevious(a);
			}
			else
			{
				b->SetNext(a->GetNext());
				a->GetNext()->SetPrevious(b);
				temp1->SetNext(a);
				a->SetPrevious(temp1);
				a->SetNext(temp2);
				temp2->SetPrevious(a);
			}
		}
		else if(b==last)
		{
			a->GetPrevious()->SetNext(b);
			b->SetPrevious(a->GetPrevious());
			if(check3-check4 == 1||check3-check4 == -1)
			{
				b->SetNext(a);
				a->SetPrevious(b);
				a->SetNext(temp2);
				temp2->SetPrevious(a);
			}
			else
			{
				b->SetNext(a->GetNext());
				a->GetNext()->SetPrevious(b);
				temp1->SetNext(a);
				a->SetPrevious(temp1);
				a->SetNext(temp2);
				temp2->SetPrevious(a);
			}
		last=a;
		}
		else
		{
			a->GetPrevious()->SetNext(b);
			b->SetPrevious(a->GetPrevious());
			if(check3-check4 == 1||check3-check4 == -1)
			{
				b->SetNext(a);
				a->SetPrevious(b);
				a->SetNext(temp2);
				temp2->SetPrevious(a);
			}
			else
			{
		b->SetNext(a->GetNext());
		a->GetNext()->SetPrevious(b);
		temp1->SetNext(a);
		a->SetPrevious(temp1);
		a->SetNext(temp2);
		temp2->SetPrevious(a);
			}
		}
	}
	else 
		cout<<"\nTHE ELEMENTS DO NOT EXIST IN THE LIST\n";
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
	list->swap(c,d);
	list->printList();
	system("pause");
}