#include <iostream>
#include <string>
using namespace std;
class node
{
public:
	string data;
	node* next;
	node(){data="0";next=NULL;}
};
class hashmap
{
private:
	int size;
	node **arr;
public:
	hashmap()
	{
		size=10;
		arr = new node*();
		for(int i=0;i<size;i++)
			arr[i] = new node();
	}
	int hash_func(string key)
	{
		int sum=0;
		for(int i=0;i<key.length();i++)
			sum=sum+key[i];
		return sum%10;
	}
	void insert(string key)
	{
		int i=0;
		int index=hash_func(key);
			if (arr[index]->data =="0")
			{
				arr[index]->data =key;
				arr[index]->next = NULL;
			}
			else
			{
				node* temp=arr[index];
				node *new_node = new node();
				new_node->data=key;
				new_node->next=NULL;
				while(temp->next != NULL)
					temp=temp->next;
				temp->next=new_node;

			}
	}
	void print()
	{
		cout<<endl;
		for (int i=0;i<size;i++)
		{
			node* temp=arr[i];
		while(temp)
			{
				cout<<"i"<<temp->data<<"\t\t";
				temp=temp->next;
		}
		cout<<endl;
		}
		cout<<endl;
	}
	bool search(string key)
	{
		int index=hash_func(key);
		node* temp=arr[index];
		while(temp)
		{
			if (temp->data ==key)
				return true;
			temp=temp->next;
		}
		return false;
	}
};
void main()
{
	hashmap h;
	h.insert("ayesha");
	h.insert("shaheera");
	h.insert("tayyaba");
	h.insert("kainat");
	h.insert("ghausia");
	h.insert("rajja");
	h.insert("zainab");
	h.insert("rabia");
	h.insert("khansa");
	h.insert("qirat");
	h.print();
	if(h.search("shaheera"))
		cout<<"\nfound\n";
	else
		cout<<"\n not found\n";
	system("pause");
}