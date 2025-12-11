#ifndef BINARYTREE_H
#define BINARYTREE_H


#include"Bnode.h"
#include<iostream>
using namespace std;

template<class DT>
class BinaryTree
{
private:
	BNode<DT>* root;
	int height(BNode<DT> * n);
public:
	BinaryTree <DT>();
	void BuildTree(DT *Arr, int Size);
	void PreOrder();
	void InOrder();
	void PostOrder();
	void LevelOrder(); 
	int calculateDepth();
};


#endif