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
	void setLeftChild(BNode<DT>* n){leftchild = n;}
	BNode<DT>* getLeftChild(){return leftchild;}
	void setRightChild(BNode<DT>* n){rightchild = n;}
	BNode<DT>* getRightChild(){return rightchild;}
	void setData(DT pdate){data = pdate;}
	DT getData(){return data;}

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
    int getRoot()
    {
        return root;
    }
    void insert(DT data)
    {
        BNode<DT> * tempNode = new BNode<DT>;
        BNode<DT> * current = new BNode<DT>;
        BNode<DT> * parent = new BNode<DT>;
        tempNode->setData(data);
        tempNode->setLeftChild(NULL);
        tempNode->setRightChild(NULL);
        if(root == NULL)
        {
            root = tempNode;
        }
        else
        {
            current = root;
            parent = NULL;
            while(1)
            {
                parent = current;
                if ( data < parent->getData())
                {
                    current = current->getLeftChild();
                    if( current == NULL)
                    {
                        parent->setLeftChild(tempNode);
                        return;
                    }
                }
                else 
                {
                    current = current->getRightChild();
                    if( current == NULL)
                    {
                        parent -> setRightChild(tempNode);
                        return;
                    }
                }
            }
        }
    }
	//part 2:
	//Build the binary tree from the data given in the array.  
	//If a node doesn't exist the array element is 0
	void BuildTree(DT *Arr, int Size)
    {
        for(int i=0; i<Size; i++)
        {
            insert(Arr[i]);
        }
    }
	//part3: post order traversal (recursive)
	//you may call any other function with parameters which might be needed
	void PostOrder(BNode<DT> * t)
    {
        if(t!=NULL)
        {
            PostOrder(t->getLeftChild());
            PostOrder(t->getRightChild());
            cout<< t->getData();
        }
    }
	//part4: pre order traversal (recursive)
	// you may call any other function with parameters which might be needed
	void PreOrder(BNode<DT> * t)
    {
        if ( t!=NULL)
        {
            cout<< t->getData();
            PreOrder(t->getLeftChild());
            PreOrder(t->getRightChild());
        }
    }
	//part5: in order traversal (recursive)
	// you may call any other function with parameters which might be needed
	void InOrder(BNode<DT> * t)
    {
        if(t!=NULL)
        {
            InOrder(t->getLeftChild());
            cout<<t->getData();
            InOrder(t->getRightChild());
        }
    }

// part6: prints the height of the binary tree, you may pass any parameters needed
	int calculateDepth();


	
};
int main()
{
	//creating an object of binary tree
	BinaryTree<int> *BT=new BinaryTree<int>();

    //array to pass, 0 means no node exists
	int Arr[15]={0,1,2,3,4,5,6,7,8,9,10,0,12,13,14};
	
	BT->BuildTree(Arr,15); //building the tree from the array
	cout<<"***************************************************"<<endl;
	
	cout<<"Preorder Traversal(Recursive) is: "<<endl;
	BT->PreOrder();
	cout<<"***************************************************"<<endl;
	cout<<"Post order Traversal(Recursive) is: "<<endl;
	BT->PostOrder();
	cout<<"***************************************************"<<endl;
       cout<<"Inorder Traversal(Recursive) is: "<<endl;
	BT->InOrder();
	cout<<"***************************************************"<<endl;

	return 0;
}
