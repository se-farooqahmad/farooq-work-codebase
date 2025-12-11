#include<iostream>
#include "Bnode.h"
#include "Bnode.cpp"
#include "BinaryTree.h"
#include "BinaryTree.cpp"
using namespace std;
int main()
{
	//creating an object of binary tree
	BinaryTree<int> *BT=new BinaryTree<int>();

    //array to pass, 0 means no node exists
	int Arr[15]={0,1,2,3,4,5,6,7,8,9,10,0,12,13,14};
	
	BT->BuildTree(Arr,15); //building the tree from the array
	cout<<"***************************************************\n"<<endl;

	cout<<"Height of the Binary Tree is: "<<endl;
	cout<<BT-> calculateDepth();
	cout<<"\n\n***************************************************\n"<<endl;

	cout<<"Preorder Traversal(Iterative) is: "<<endl;
	BT->PreOrder();
	cout<<"\n\n***************************************************\n"<<endl;

	cout<<"Post order Traversal(Iterative) is: "<<endl;
	BT->PostOrder();
	cout<<"\n\n***************************************************\n"<<endl;

	cout<<"Level order Traversal(Iterative) is: "<<endl;
	BT->LevelOrder();
	cout<<"\n\n***************************************************\n"<<endl;

	cout<<"Inorder Traversal(Iterative is: "<<endl;
	BT->InOrder();
	cout<<"\n\n***************************************************\n"<<endl;

	system("pause");
	return 0;
}
