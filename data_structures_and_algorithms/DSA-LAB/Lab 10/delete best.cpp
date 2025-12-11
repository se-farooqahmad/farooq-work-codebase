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
  void insert(TreeNode* &tree, int item);
  void insertItem(int value) {
   insert(root, value);
  }
  void print();
  void level(TreeNode * r);
  void print_preorder(TreeNode * r);
  void delete_Node(int val){deletee(root,val);};
  TreeNode* deletee(TreeNode *root, int data);
  
};
void TreeType::insert(TreeNode* &tree, int number) {
  if (tree == NULL) {
    tree = new TreeNode;
    tree->left = NULL;
    tree->right = NULL;
    tree->value = number;
  } else if (number < tree->value) {
    insert(tree->left, number);
  } else {
    insert(tree->right, number);
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
TreeNode* TreeType::deletee(TreeNode *root, int data) {
	if (root == NULL) 
		return root;
	else if (data < root->value) 
		root->left = deletee(root->left, data);
	else if (data > root->value) 
		root->right = deletee(root->right, data);
	else {
		if (root->left == NULL && root->right == NULL) {
			delete root;
			root = NULL;
		}
		else if (root->left == NULL) {
			TreeNode *temp = root;
			root = root->right;
			delete temp;
		}
		else if (root->right == NULL) {
			TreeNode *temp = root;
			root = root->left;
			delete temp;
		}
		else {
			TreeNode*temp = root->right;
			while (temp->left != NULL)
				temp = temp->left;
			root->value = temp->value;
			root->right = deletee(root->right, temp->value);
		}
	}
	return root;
}
void main() {
  TreeType* MyTree = new TreeType;
  MyTree->insertItem(8);
  MyTree->insertItem(9);
  MyTree->insertItem(4);
  MyTree->insertItem(3);
  MyTree->insertItem(5);
  MyTree->insertItem(10);
  MyTree->insertItem(1);
  MyTree->insertItem(2);
  MyTree->insertItem(20);
  cout<<"PREORDER PRINT\n";
   MyTree->print();
   cout<<"delete\n";
  MyTree->delete_Node(9);
  MyTree->print();
  system("pause");
}