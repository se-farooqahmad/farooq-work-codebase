#include"Bnode.h"



template<class DT>
BNode<DT>::BNode()
{
	leftchild=0;
	rightchild=0;
}


template<class DT>
void BNode<DT>::setLeftChild(BNode<DT>* n)
{
	leftchild=n;
}

template<class DT>
BNode<DT> * BNode<DT>::getLeftChild()
{ 
	return leftchild;
}


template<class DT>
void BNode<DT>::setRightChild(BNode<DT>* n)
{
	rightchild=n;
}


template<class DT>
BNode<DT> * BNode<DT>::getRightChild()
{
	return rightchild;
}


template<class DT>
void BNode<DT>::setData(DT pdate)
{
	data=pdate;
}


template<class DT>
DT BNode<DT>::getData()
{
	return data;
}