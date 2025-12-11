#include <iostream>
using namespace std;
template <typename T>
class Node
{   
public: 
	Node() {} 
	Node(T element) {data =element;}
	void setData(T pVal) {data=pval;}
	T getData() { return data;}
	Node* GetNext(){ return link;}
	void SetNext(Node *x){ link=x;}			   
private: 
	T data; 
	Node *link;
};
template <typename T>
class SCList
{
   public:
	   SCList(){ last = NULL}
		 //Returns the pointer to the first node of the list
		 Node<T>* GetFirst();
	/*Inserts the node pNew after the node pBefore
	if the list is empty, it makes pNew the first node of the list*/
		 void Insert(Node<T>* pBefore, Node<T>* pNew);
		 //Deletes the node pToBeDeleted
		 void Delete(Node<T>* pToBeDeleted);
		 //prints the contents of the list
		 void printList();		 		 
   private: 
	     Node<T> *last ;
};
void main()
{
	system("pause");
}