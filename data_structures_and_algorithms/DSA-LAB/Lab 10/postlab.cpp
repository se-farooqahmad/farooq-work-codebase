#include<iostream>
#include <queue>
using namespace std;
class TreeNode {

public:
  
	int value;
	TreeNode* left;
	TreeNode* right;
};

class TreeType {
  TreeNode* root;
public:
  TreeType(){root =NULL;};
  void insertItem(int value);
  void bstinsert(int val);
  void print();
  void print_preorder(TreeNode * r);
  void level(TreeNode * r);
  void bst(TreeType  *&Tree);
};
void TreeType::bstinsert(int val)
{
	TreeNode *tree = root; 
	TreeNode *temp= new TreeNode;
		 temp->left = NULL;
		 temp->right = NULL;
		 temp->value = val;
	if(tree == NULL)
		 root=tree=temp;
	else{
	while((tree->left != NULL && val<tree->value)||(tree->right !=NULL && val>tree->value))
	{
		if(tree->value>val)
			tree=tree->left;
		else if(tree->value<val)
			tree=tree->right;
	}
	if(tree->value>val)
		tree->left=temp;
	else if(tree->value<val)
		tree->right=temp;
	}
}
void TreeType::bst(TreeType *&Tree)
{
	queue<TreeNode*> q;
	if(root == NULL)
		return;
	else
	{
		q.push(root);
		while(!q.empty())
		{
			TreeNode *temp = q.front();
			q.pop();
			Tree->bstinsert(temp->value);
			if(temp->left !=NULL)
			q.push(temp->left);
			if(temp->right !=NULL)
			q.push(temp->right);
			
		}	
	}
}
void TreeType::insertItem(int val) 
{
	TreeNode *tree = root; 
	TreeNode *temp= new TreeNode;
		 temp->left = NULL;
		 temp->right = NULL;
		 temp->value = val;
	if(tree == NULL)
		 root=tree=temp;
	else{
		bool done=false;
	while(!done)
	{
		if(tree->left ==NULL)
		{
			tree->left=temp;
			done =true;
		}
		else if(tree->right == NULL)
		{
			tree->right=temp;
			done =true;
		}
		else
			tree=tree->left;
	}
	}
}
void TreeType::print()
{
	cout<<endl;
	print_preorder(root);
	cout<<endl;
	cout<<"LEVEL PRINT\n";
	level(root);
	
}
void TreeType::print_preorder(TreeNode *r)
{
	if(r == NULL)
		return;
	else
	{
		cout << r->value<<" ";
		print_preorder(r->left);
		print_preorder(r->right);
	}

}
void TreeType::level(TreeNode *r)
{
	queue<TreeNode*> q;
	if(r == NULL)
		return;
	else
	{
		q.push(r);
		while(!q.empty())
		{
			TreeNode *temp = q.front();
			cout<<temp->value<<" ";
			q.pop();
			if(temp->left !=NULL)
			q.push(temp->left);
			if(temp->right !=NULL)
			q.push(temp->right);
			
		}	
	}

}
void main() {
  TreeType* MyTree = new TreeType;
  TreeType* MyTree2 = new TreeType;
  cout<<"BINARY TREE\n";
  MyTree->insertItem(8);
  MyTree->insertItem(9);
  MyTree->insertItem(4);
  MyTree->insertItem(10);
  MyTree->insertItem(3);
  MyTree->insertItem(5);
  MyTree->insertItem(20);
  cout<<"PREORDER PRINT\n";
   MyTree->print();
   MyTree->bst(MyTree2);
   cout<<"\n\nBINARY SEARCH TREE\n";
   cout<<"\nPREORDER PRINT\n";
   MyTree2->print();
  system("pause");
}