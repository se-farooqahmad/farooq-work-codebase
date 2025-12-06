#include<iostream>
using namespace std;
template <typename T>
class Node
{
    private: 
	     T data;
		 Node *link ;
    public: 
	     // constructor 
	     Node(T element)
         {
            data = element;
            link = NULL;
         }
		 
		 //sets the KeyType data in the Node
		 void setData(T pVal)
         {
            data = pVal;
         }

		 // returns the KeyType data in the Node
		 T getData()
         {
            return data;
         }

		 // returns the link to the next node
		 Node* GetNext()
         {
            return link;
         }

		 // sets the link to the next node
		 void SetNext(Node *x)
         {
            link = x;
         }
				 
   
};

template <typename T>
class List
{
    private: 
	     Node<T> *first ;
    public: 
	     // constructor of the Singly Linked List 
	     List()
         {
            first = NULL;
         }
		 
//Inserts the node pNew after the node pBefore
// if the list is empty, it makes pNew the first node of the list
		 void Insert(Node<T>* pBefore, Node<T>* pNew)
         {
            if (pBefore == NULL);
                first = pNew;
            else 
            {
                pNew -> setNext(pBefore->getNext());
                pBefore->setNext(pNew);
            }
         }

		 //Deletes the node pToBeDeleted
		 void Delete(Node<T>* pToBeDeleted)
         {
            
         }

		 //prints the contents of the list
		 void printList();

//ADD ONE OR TWO MEMBER FUNCTION(s) DIFFERENT FOR EACH LAB SECTION
   
		
};
int main()
{   	
	Node<int> *a, *b, *c, *d, *e;
	
	a = new Node<int>(1);
	b = new Node<int>(2);
	c = new Node<int>(3);
	d = new Node<int>(4);
	e = new Node<int>(5);


	List<int> *list;

	list = new List<int>();

	list->Insert(0 , a);
	list->Insert(a , b);
	list->Insert(b , c);
	list->Insert(a , d);
	list->Insert(b, e);

   list->printList();

   	list->Delete(a);
	
     cout<<"\nAfter deleting first node"<<endl;
	list->printList();
	
// PLEASE ADD CALL TO MEMBER FUNCTION WHICH WOULD DIFFER SECTION-WISE e.g. list->reverse etc.

	cout<<"\nAfter calling function"<<endl;
	list->printList();
	
	system("pause");
	return 0;

}
