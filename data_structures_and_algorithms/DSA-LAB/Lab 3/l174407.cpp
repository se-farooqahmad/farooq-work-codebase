#include <iostream>
using namespace std;

// Node class
class Node {
    int data;
    Node *next;

  public:
    Node() {};
	void SetData(int aData){ data =aData;};
	void SetNext(Node* aNext) {next= aNext;};
	int Data() {return data;};
	Node *Next() {return next;}
};

// List class
class List {
    Node *head;
  public:
    List() { head = NULL; };
    void Print();
    void Append(int data);
   //void Insert(int data, int dataAfter );
    void Delete(int data);
};
void List::Append(int data)
{
	Node *newNode =new Node();
	newNode->SetData(data);
	newNode->SetNext(NULL);
	Node *tmp =head;
	if(tmp!= NULL)
	{
		while (tmp->Next() !=NULL)
		{
			tmp=tmp->Next();
		}
		tmp->SetNext(newNode);
	}
	else
		head=newNode;
}
void List::Print()
{
	Node *tmp= head;
	if(tmp != NULL)
	{
		while(tmp->Next() !=NULL)
		{
			cout<<tmp->Data()<<"  ";
			tmp=tmp->Next();
		}
	}
		cout<<tmp->Data()<<endl;

}
void List::Delete(int data)
{
	Node *tmp =head;
	Node *tmp1,*tmp2;
	while(tmp->Data() != data)
	{
		tmp=tmp->Next();
		tmp1=tmp->Next();
		tmp2=tmp1->Next();	
	}
	while(tmp->Next() !=NULL)
		{
			
			tmp2=tmp->Next();
			tmp=tmp->Next();
		}
	tmp2->SetNext(NULL);
	tmp1->SetNext(tmp2->Next());
	delete tmp2;
	
	

}
int main()
{
    // New list
    List list;
    // Append nodes to the list
    list.Append(100);
    list.Print();
    list.Append(200);
    list.Print();
    list.Append(300);
    list.Print();
    list.Append(400);
    list.Print();
    list.Append(500);
    list.Print();
   list.Delete(400);
    list.Print();
    list.Delete(300);
    list.Print();
}
