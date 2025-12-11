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
  TreeNode* search(int val);
  void delete_Node(int val);
  
};
void TreeType::delete_Node(int val)
{
	if(search(val) != NULL)
	{TreeNode* temp =search(val);
	TreeNode *tobedeleted = NULL;
	if(temp->right != NULL && temp->right->value == val && temp->right->left==NULL && temp->right->right == NULL)
	{	
		temp->right= NULL;
		delete temp->right;
	}
	else if(temp->left != NULL && temp->left->value == val && temp->left->right==NULL && temp->left->left == NULL)
	{
	
		temp->left= NULL;
		delete temp->left;
	}
	else if(temp->right != NULL && temp->right->value == val && temp->right->left==NULL && temp->right->right != NULL)
	{
		
		tobedeleted = temp->right;
		temp->right=temp->right->right;
		delete tobedeleted;
	}
	else if(temp->right != NULL && temp->right->value == val && temp->right->left!=NULL && temp->right->right == NULL)
	{
		
		tobedeleted = temp->right;
		temp->right=temp->right->left;
		delete tobedeleted;
	}
	else if(temp->left != NULL && temp->left->value == val && temp->left->right==NULL && temp->left->left != NULL)
	{
		tobedeleted = temp->left;
		temp->left=temp->left->left;
		delete tobedeleted;
	}
	else if(temp->left != NULL && temp->left->value == val && temp->left->right!=NULL && temp->left->left == NULL)
	{
		tobedeleted = temp->left;
		temp->left=temp->left->right;
		delete tobedeleted;
	}
	}
	else 
		cout<<"THE ELEMENT DOES NOT EXIST IN THE BINARY TREE\n";
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
TreeNode* TreeType::search(int val)
{
	TreeNode *tree = root;
	TreeNode *temp = NULL;
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
			temp=tree;
			count++;
			tree=tree->left;
		}
		else if(tree->value<val)
		{	
			temp=tree;
			count++;
			tree=tree->right;
		}
	}
	
	if(found)
		return temp;
	else
		return NULL;
}
void main() {
  TreeType* MyTree = new TreeType;
  MyTree->insertItem(8);
  MyTree->insertItem(9);
  MyTree->insertItem(4);
  MyTree->insertItem(10);
  MyTree->insertItem(3);
  MyTree->insertItem(5);
  MyTree->insertItem(20);
  MyTree->insertItem(1);
  cout<<"print\n";
  MyTree->print();
  cout<<endl;
  cout<<"delete\n";
  MyTree->delete_Node(1);
  MyTree->print();
  system("pause");
}