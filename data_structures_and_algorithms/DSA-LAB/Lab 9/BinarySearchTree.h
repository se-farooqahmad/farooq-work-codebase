#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

#include "BNode.h"
using namespace std;

template<class DT>
class BinarySearchTree
{
public:
	BinarySearchTree();
	bool insert(const DT data);
	BNode<DT> * search(const DT data);
	void printSorted();
	bool Delete(const DT data);
	~BinarySearchTree();


private:
	BNode<DT> * root;

};
#endif
