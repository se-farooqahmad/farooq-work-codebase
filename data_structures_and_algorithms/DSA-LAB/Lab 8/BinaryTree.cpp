#include"Bnode.h"
#include"BinaryTree.h"
#include<iostream>
#include<stack>
#include<queue>
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
{
	stack <BNode<DT>*> *s = new stack <BNode<DT>*> ();
	BNode<DT> *temp = root;
	s->push(temp);
	while(!s->empty())
	{
		temp = s->top();
		s->pop();
		cout<<temp->getData()<<" ";
		if(temp->getRightChild())
			s->push(temp->getRightChild());
		if(temp->getLeftChild())
			s->push(temp->getLeftChild());
	}
}


template<class DT>
void BinaryTree<DT>::PostOrder()
{ 
	stack <BNode<DT>*> *s = new stack <BNode<DT>*> ();
	stack <BNode<DT>*> *t = new stack <BNode<DT>*> ();
	BNode<DT> *temp = root;
	s->push(temp);
	while(!s->empty())
	{
		temp = s->top();
		s->pop();
		t->push(temp);
		if(temp->getLeftChild())
			s->push(temp->getLeftChild());
		if(temp->getRightChild())
			s->push(temp->getRightChild());
	}
	while(!t->empty())
	{
		temp = t->top();
		t->pop();
		cout<<temp->getData()<<" ";
	}
}


template<class DT>
void BinaryTree<DT>::LevelOrder()
{
	queue <BNode<DT>*> *s = new queue <BNode<DT>*> ();
	BNode<DT> *temp = root;
	s->push(temp);
	while(!s->empty())
	{
		temp = s->front();
		if(temp->getLeftChild())
			s->push(temp->getLeftChild());
		if(temp->getRightChild())
			s->push(temp->getRightChild());
		cout<<temp->getData()<<" ";
		s->pop();
	}
}


template<class DT>
void BinaryTree<DT>::InOrder()
{
		BNode <DT>* temp=root;
		stack<BNode<DT>*> *s= new stack<BNode<DT>*>();
		s->push(temp);
		while(!s->empty() || temp)
		{
			if(temp==NULL)
			{
				temp=s->top();
				s->pop();
				cout<<temp->getData()<<" ";
				temp=temp->getRightChild();
			}
			else
			{
				s->push(temp);
				temp=temp->getLeftChild();
			}
		}
	}

