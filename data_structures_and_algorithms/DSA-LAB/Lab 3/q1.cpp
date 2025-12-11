#include <iostream>
using namespace std;
class Node {
    int data;
    Node *next;
  public:
    Node() {}
	void SetData(int aData) {data = aData;}
	void SetNext(Node* aNext){next = aNext;}
	int Data() {return data;}
	Node *Next() {return next;}
};
class List {
    Node *head;
  public:
    List() { head = NULL; };
    void Print();
    void Append(int data);
	void Insert(int adata, int dataAfter );
	void Delete(int data);
};
void List::Append(int data)
{
	Node *newNode = new Node();
	newNode->SetData(data);
	newNode->SetNext(NULL);
	Node *temp=head;
	if(temp !=NULL)
	{
		while(temp->Next() != NULL)
			temp=temp->Next();
		temp->SetNext(newNode);
	}
	else
		head=newNode;
}
void List::Print()
{
	Node *temp=head;
	if(temp !=NULL)
	{
		while(temp->Next() != NULL)
		{
			cout<<temp->Data()<<"  ";
			temp=temp->Next();
		}
	}
	cout<<temp->Data()<<endl;
}
void List::Delete(int data)
{
	Node *temp,*temp1;
	temp=head;
	if(temp !=NULL)
	{
		while(temp->Next()->Data() != data)
			temp=temp->Next();
	}
	temp1=temp->Next();
	temp->SetNext(temp->Next()->Next());
	delete temp1;
}
void List::Insert(int adata, int dataAfter )
{
	Node *temp = head, *tmp =head;
	int check =0;
	while( tmp->Next() != NULL)
	{
		if( tmp->Data() == dataAfter )
			check++;
		tmp=tmp->Next();
	}
	if(check>0)
	{
	if(temp !=NULL)
	{
		while(temp->Data() != dataAfter)
			temp=temp->Next();
	}
	Node *newNode = new Node();
	newNode->SetData(adata);
	newNode->SetNext(temp->Next());
	temp->SetNext(newNode);
	}
	else 
		cout<<"THE ELEMENT AFTER WHICH YOU WANT TO INSERT DOES NOT EXIST IN LIST"<<endl;
}

int main()
{
    // New list
    List list;
    cout<<"APPEND\n";
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
	cout<<"DELETE\n";
	list.Delete(400);
   list.Print();
    list.Delete(300);
   list.Print();
   cout<<"INSERT\n";
   list.Insert(350,200);
   list.Print();
   list.Insert(750,300);
   list.Print();
    list.Insert(450,350);
   list.Print();
   
}
