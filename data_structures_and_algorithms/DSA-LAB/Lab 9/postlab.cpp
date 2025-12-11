#include<iostream>
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
  void print();
  void print_preorder(TreeNode * r);
  int search(int val);
  
};
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
void TreeType::print()
{
	cout<<endl;
	print_preorder(root);
	
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
int TreeType::search(int val)
{
	TreeNode *tree = root;
	int count =0;
	bool found =false;
	while(tree != NULL && !found)
	{
		if(tree->value==val)
		{	
			count++;
			found = true;
		}
		if(tree->value>val)	
		{
			count++;
			tree=tree->left;
		}
		else if(tree->value<val)
		{	
			count++;
			tree=tree->right;
		}
	}
	if(found)
		return count;
	else
		return -1;
}
void main() {
  TreeType* MyTree = new TreeType;
  MyTree->insertItem(8);
  MyTree->insertItem(9);
  MyTree->insertItem(4);
  MyTree->insertItem(10);
  MyTree->insertItem(3);
  MyTree->insertItem(5);
  cout<<"print\n";
  MyTree->print();
  cout<<"\nsearch\t "<<MyTree->search(3);
  cout<<endl;
  system("pause");
}