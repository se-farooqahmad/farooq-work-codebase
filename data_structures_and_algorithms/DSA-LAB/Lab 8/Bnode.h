#ifndef BNODE_H
#define BNODE_H


#include<iostream>

template<class DT>
class BNode
{
public:
	BNode();
	void setLeftChild(BNode<DT>* n);
	BNode<DT>* getLeftChild();
	void setRightChild(BNode<DT>* n);
	BNode<DT>* getRightChild();
	void setData(DT pdate);
	DT getData();
private:
	DT data;
	BNode* leftchild;
	BNode* rightchild;
};
#endif