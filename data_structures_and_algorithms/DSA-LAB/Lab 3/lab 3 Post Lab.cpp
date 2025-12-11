#include <iostream>
using namespace std;
template<typename T>
class Node
{
private:
	T data;
	Node *link;
public:
	// constructor 
	Node(T element)
	{
		link = NULL;
		data = element;
	}
	void setData(T pVal)
	{
		data = element;
	}
	T getData()
	{
		return data;
	}
	Node* GetNext()
	{
		return link;
	}
	void SetNext(Node *x)
	{
		link = x;
	}
};
template <typename T>
class SCList
{
private:
	Node<T> *last, *head;
public:
	SCList() // constructor of the Singly Circular Linked List 
	{
		last = NULL;
	}
	/*Inserts the node pNew after the node pBefore
	if the list is empty, it makes pNew the first node of the list*/
	void Insert(Node<T>* pBefore, Node<T>* pNew)
	{
		if (last==NULL)
		{
			head = pNew;
			pNew = last;
			last = head;
			//cout<<head->getData();
		}
		else
		{
			pNew->SetNext(pBefore->GetNext());
			if(pNew->GetNext()==NULL)
					pNew->SetNext(head);
			pBefore->SetNext(pNew);
		}
	}


	//Deletes the node pToBeDeleted
	void Delete(Node<T>* pToBeDeleted)
	{
		int a = 1;
		Node < T > *temp1, *temp2;
		temp1 = head;
		temp2 = head->GetNext();
		while (a != 0)
		{
			if(pToBeDeleted == head)
				{
					head = temp1->GetNext();
				}
			else if (temp2 == pToBeDeleted)
			{
				temp1->SetNext(temp2->GetNext());
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
		Node<T> *temp = head;
		cout<<temp->getData();
		while (temp->GetNext() != head)
		{
			temp = temp->GetNext();
			cout << "\t" << temp->getData();
		}
	}



};

int main()
{
	Node<int> *a, *b, *c, *d, *e;

	a = new Node<int>(1);
	b = new Node<int>(2);
	c = new Node<int>(3);
	d = new Node<int>(4);
	e = new Node<int>(5);

	SCList<int> *list;

	list = new SCList<int>();

	list->Insert(0, a);
	list->Insert(a, b);
	list->Insert(b, c);
	list->Insert(c, d);
	list->Insert(d, e);

	list->printList();
	cout << endl;

	list->Delete(e);

	list->printList();
	cout << endl;

	system("pause");
	return 0;

}