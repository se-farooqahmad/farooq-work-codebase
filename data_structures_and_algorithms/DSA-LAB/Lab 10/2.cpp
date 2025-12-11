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
  system("pause");
}