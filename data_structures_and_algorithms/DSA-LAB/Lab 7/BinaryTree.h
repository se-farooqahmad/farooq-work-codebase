#ifndef BINARYTREE_H
#define BINARYTREE_H


#include"Bnode.h"
#include<iostream>
using namespace std;

template<class DT>
class BinaryTree
{
public:
	BinaryTree <DT>();
	void BuildTree(DT *Arr, int Size); 
	int calculateDepth();
	void PostOrder();
	void PreOrder();
	void InOrder();
	



private:
	BNode<DT>* root;
	int height(BNode<DT> * n);
	void PreOrderRC(BNode<DT>*n);
	void PostOrderRC(BNode<DT>* n);
	void InOrderRC(BNode<DT>* n);
};


#endif