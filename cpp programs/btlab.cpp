#include<iostream>
using namespace std;
template<class DT>
class BNode
{
	private:
	DT data;
	BNode* leftchild;
	BNode* rightchild;
public:
	BNode()
	{
		data = 0;
		leftchild = NULL;
		rightchild = NULL;
	}
	void setLeftChild(BNode<DT>* n)
	{
		leftchild = n;
	}
	BNode<DT>* getLeftChild()
	{
		return leftchild;
	}
	void setRightChild(BNode<DT>* n)
	{
		rightchild = n;
	}
	BNode<DT>* getRightChild()
	{
		return rightchild;
	}
	void setData(DT pdate)
	{
		data = pdate;
	}
	DT getData()
	{
		return data;
	}

};
template<class DT>
class BinaryTree
{
	private: 
// you may add any other private members which might be needed by recursive functions
	BNode<DT>* root;

public:
	//part1: constructor
	BinaryTree ()
	{
		root = NULL;
	}
	//part 2:
	
	//Build the binary tree from the data given in the array.  
	//If a node doesn't exist the array element is 0
	void BuildTree(DT *Arr, int Size)
	{
		BNode<DT> **t = new BNode<DT>*[Size];
		for(int i=0; i<Size; i++)
		{
			t[i]=new BNode<DT>;
		}
		
		for(int i=1;i<Size;i++)
		{
			
			
			if(Arr[i]==0)
			{
				t[i] = NULL;
			}
			else if(Arr[i]!=0)
			{
				
				t[i]->setData(Arr[i]);
			}
			if(i/2 >=1)
			{
				if(i%2==0)
					t[i/2]->setLeftChild(t[i]);
				else
					t[i/2]->setRightChild(t[i]);
			}
		}	
		root = t[1];
	}
	//part3: post order traversal (recursive)
	//you may call any other function with parameters which might be needed
	BNode<DT>* getRoot () 
	{
		return root;
	}
	void PostOrder()
{	

	PostOrder(root);

}
	void PostOrder(BNode<DT>* d)
{
	if (d != NULL)
		{
			
			PreOrder(d->getLeftChild());
			PreOrder(d->getRightChild());
			cout << d->getData()<<" ";
		}
	
}

	//part4: pre order traversal (recursive)
	// you may call any other function with parameters which might be needed
	void PreOrder(BNode<DT> *d)
	{
		if (d != NULL)
		{
			cout << d->getData()<<" ";
			PreOrder(d->getLeftChild());
			PreOrder(d->getRightChild());
		}
		
	}
	//part5: in order traversal (recursive)
	// you may call any other function with parameters which might be needed
	void InOrder(BNode<DT> *d)
	{
		if (d != NULL)
		{
			
			PreOrder(d->getLeftChild());
			cout << d->getData()<<" ";
			PreOrder(d->getRightChild());
		}
		
	}

// part6: prints the height of the binary tree, you may pass any parameters needed
	int calculate_Depth(BNode<DT> *d)
	{
		
		if(d == NULL)
			return 0;
		else
		{
			int l=0,r=0;
			 l = calculate_Depth(d->getLeftChild());
			 r = calculate_Depth(d->getRightChild());
		
			 if(l > r)
			return l+1;
		else
			return r+1;
		
		}
		
	}

	
};
int main()
{
	//creating an object of binary tree
	BinaryTree<int> *BT=new BinaryTree<int>();

    //array to pass, 0 means no node exists
	int Arr[19]={0,1,2,3,4,5,6,7,8,9,10,0,12,13,14,0,0,0,11};
	
	BT->BuildTree(Arr,19); //building the tree from the array
	cout<<"***************************************************"<<endl;
	
	cout<<"Preorder Traversal(Recursive) is: "<<endl;
	BT->PreOrder(BT->getRoot());
	cout<<endl;
	cout<<"***************************************************"<<endl;
	cout<<"Post order Traversal(Recursive) is: "<<endl;
	BT->PostOrder(BT->getRoot());
	cout<<endl;
	cout<<"***************************************************"<<endl;
       cout<<"Inorder Traversal(Recursive) is: "<<endl;
	BT->InOrder(BT->getRoot());
	cout<<endl;
	cout<<"***************************************************"<<endl;
	
	cout<<BT->calculate_Depth(BT->getRoot())<<endl;

	return 0;
}



