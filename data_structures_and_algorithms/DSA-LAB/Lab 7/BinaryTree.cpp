#include"Bnode.h"
#include"BinaryTree.h"
#include<iostream>
using namespace std;


template<class DT>
BinaryTree<DT>::BinaryTree()
{
	root=NULL;
}


template<class DT>
void BinaryTree<DT>::BuildTree(DT * Arr, int Size)
{
	
	if (Size < 2)
		return;
	BNode<DT> ** nodePtrs = new BNode<DT>* [Size];
	for (int i = 1; i < Size; ++i)
	{
		if (Arr[i] == 0)
		{
			nodePtrs[i] = nullptr;
		}

		else
		{
			nodePtrs[i] = new BNode<DT>();
			nodePtrs[i]->setData(Arr[i]);
		}

		if (i / 2 >= 1)
		{
			if (i % 2 == 0)
				nodePtrs[i / 2]->setLeftChild(nodePtrs[i]);
			else
				nodePtrs[i / 2]->setRightChild(nodePtrs[i]);
		}
	}
	root = nodePtrs[1];
	delete [] nodePtrs;
}

template<class DT>
int BinaryTree<DT>::height(BNode<DT> * n)
{
	if(n)
	{
		int left = 1 + height(n->getLeftChild());
		int right = 1 + height(n->getRightChild());
		return max(left , right);
	}
	return 0;
	
}




template<class DT>
int BinaryTree<DT>::calculateDepth()
{
	return height(root);
}



template<class DT>
void BinaryTree<DT>::PreOrder()
{ PreOrderRC(root);}

template<class DT>
void BinaryTree<DT>::PreOrderRC(BNode<DT>* n)
{ 
if(n)

{
	cout<<n->getData()<<" ";
PreOrderRC(n->getLeftChild());

PreOrderRC(n->getRightChild());

}
}

template<class DT>
void BinaryTree<DT>::PostOrder()
{PostOrderRC(root);}

template<class DT>
void BinaryTree<DT>::PostOrderRC(BNode<DT>* n)
{ 
if(n)

{

PostOrderRC(n->getLeftChild());

PostOrderRC(n->getRightChild());
cout<<n->getData()<<" ";
}
}

template<class DT>
void BinaryTree<DT>::InOrder()
{ InOrderRC(root);}

template<class DT>
void BinaryTree<DT>::InOrderRC(BNode<DT>* n)
{ 
if(n)

{

PostOrderRC(n->getLeftChild());
cout<<n->getData()<<" ";
PostOrderRC(n->getRightChild());

}
}