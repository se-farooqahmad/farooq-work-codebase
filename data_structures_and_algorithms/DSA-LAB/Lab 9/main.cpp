#include<iostream>
#include "BNode.h"
#include "BNode.cpp"
#include "BinarySearchTree.h"
#include "BinarySearchTree.cpp"
using namespace std;
int main()
{
	BinarySearchTree<int> *BST=new BinarySearchTree<int>();	

	BST->insert(12);
	BST->insert(4);
	BST->insert(9);
	BST->insert(2);
	BST->insert(14);
	BST->insert(16);
	BST->insert(13);

	BST->insert(12);

	cout<<"Sorted tree : "<<endl;
	BST->printSorted();
	cout<<endl<<endl;


	BNode<int>*n =BST->search(12);
	if(n)
		cout<<"Value exists\n"<<endl;
	else
		cout<<"Value does not exist\n"<<endl;
	n =BST->search(23);
	if(n)
		cout<<"Value exists\n"<<endl;
	else
		cout<<"Value does not exist\n"<<endl;
	
	
	BST->Delete(13);
	
	cout<<"Sorted tree : "<<endl;
	BST->printSorted();

	system("pause");
	return 0;
}
