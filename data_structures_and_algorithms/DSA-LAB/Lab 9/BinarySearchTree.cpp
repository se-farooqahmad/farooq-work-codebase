#include <iostream>
#include "Bnode.h"
#include "BinarySearchTree.h"
#include<stack>




                                   //HEADER

template<class DT>
BinarySearchTree<DT>::BinarySearchTree()
{
	root = NULL;
}



                                     //INSERT

template<class DT>
bool BinarySearchTree<DT>::insert(const DT data)
{
	BNode<DT>* a = new BNode<DT>;
	a->setData(data);
	if(root == NULL)
	{
		root = a;
		return 1;
	}
	else
	{
		BNode<DT> *pp = root;
		BNode<DT> *curr = root;
		while(curr != NULL)
		{
			pp = curr;
			if(data < curr->getData())
				curr = curr->getLeftChild();
			else if(data > curr->getData())
				curr = curr->getRightChild();
			else{
				cout<<"Already exists\n\n";
				return 0;}
		}
		if(data < pp->getData())
		 pp->setLeftChild(a);
		else if(data > pp->getData())
		 pp->setRightChild(a);
		return 1;
	}
}




                                       //SEARCH

template<class DT>
BNode<DT>* BinarySearchTree<DT>::search(const DT data)
{
	BNode<DT> *temp = root;
	while (temp != NULL)
	{
		if (data < temp->getData())
			temp = temp->getLeftChild();
		else if (data > temp->getData())
			temp = temp->getRightChild();
		else if (data == temp->getData())
			return temp;
		else if (temp->getLeftChild()==NULL && temp->getRightChild()==NULL)
				return NULL;
	}
}





                                          //PRINT
 
template<class DT>
void BinarySearchTree<DT>::printSorted()
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



                         //DELETE

template<class DT>
bool BinarySearchTree<DT>::Delete(DT data)
{
	BNode<DT> *p=root;
	BNode<DT>*pp=0;
	while(p && p->getData()!=data)
	{
		pp=p;
		if(data<p->getData())
				p=p->getLeftChild();
		else 
			p=p->getRightChild();
	}
	if (p==0)
		return false;

	if(p->getLeftChild() && p->getRightChild())
	{
		BNode<DT>* s=p->getLeftChild();
		BNode<DT> * ps=p;
		while(s->getRightChild())
		{
			ps=s;
			s=s->getRightChild();
		}
		BNode<DT>*q=new BNode<DT>();
		q->setData(s->getData());
		if(pp==0)
			root=q;
		else if(p==pp->getLeftChild())
		
			pp->setLeftChild(q);
		else 
			pp->setLeftChild(q);
		if(ps==p)
			pp=q;
		else 
			pp=ps;
		delete p;
		p=s;
	}
	BNode<DT>* c;
	if(p->getLeftChild())
		c=p->getLeftChild();
	else 
		c=p->getRightChild();
	if(p==root)
		root=c;
	else
	{ 
		if(p==pp->getLeftChild())
			pp->setLeftChild(c);
		else 
			pp->setRightChild(c);
	}
	delete p;
}


                           //DESTRUCTOR

template<class DT>
BinarySearchTree<DT>::~BinarySearchTree()
{
}