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
  void insert(TreeNode* tree, int item);
  void insertItem(int value) {
   insert(root, value);
  }
};
void TreeType::insert(TreeNode* &tree, int number) {
  if (tree == NULL) {
    tree = new TreeNode;
    tree->left = NULL;
    tree->right = NULL;
    tree->value = number;
    cout << "DONE";
  } else if (number < tree->value) {
    insert(tree->left, number);
  } else {
    insert(tree->right, number);
  }
}
void main() {
  TreeType* MyTree = new TreeType;
  MyTree->insertItem(8);

  system("pause");
}
