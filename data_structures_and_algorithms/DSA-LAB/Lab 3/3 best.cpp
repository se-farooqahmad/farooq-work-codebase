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
	void Swap(int adata, int bdata);
	void reverse_print(){reverse(head);};
	void reverse(Node* root);
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
	if(tmp->Data() == dataAfter)
		check++;
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
void List::Swap(int adata, int bdata)
{
	int check,check1=0,check2=0;
	if(bdata<adata)//setting in order
	{
		check=bdata;
		bdata=adata;
		adata=check;
	}

	Node *temp,*temp1,*temp2,*temp3;
	temp=head;
	while( temp->Next() != NULL)//checking wether element exist
	{
		if( temp->Data() == adata )
			check1++;
		else if( temp->Data() == bdata )
			check2++;
		temp=temp->Next();
	}
	if(temp->Data() == adata)
		check1++;
	else if(temp->Data() == bdata)
		check2++;
	temp=head;
	if(check1>0&&check2>0)
	{
		check1=0;
		check2=0;
	while(temp->Next()->Data() != adata)
	{
		temp1=temp->Next();
		temp=temp->Next();
		check1++;
	}
	if(check1==0)//if the element is second
		temp1=head;
	while(temp->Data() != bdata)
	{
		temp2=temp->Next();
		temp=temp->Next();
	}
	if(temp2== NULL)//if the element is last
		temp3->SetNext(NULL);
	else
		temp3=temp2->Next();
	temp=temp1->Next();
	temp1->SetNext(temp2);
	temp2->SetNext(temp->Next());
	while(temp2->Next()->Data() != bdata)
	{
		temp2= temp2->Next();}
	temp2->SetNext(NULL);
	temp->SetNext(temp3);
	temp2->SetNext(temp);
	}
	else
		cout<<"THE ELEMENTS DO NOT EXIST IN THE LIST"<<endl;

}
void List::reverse(Node * root)
{
	Node *temp =root;
	if(temp->Next() == NULL)
	{
		cout<<temp->Data()<<" ";
	}
	else
	{
		reverse(temp->Next());
		cout<<temp->Data()<<" ";
	}
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
	cout<<"REVERSE PRINT\n";
	list.reverse_print();
}