#include<iostream>
using namespace std;
struct node
{
  int key_value;
  node* left;
  node* right;
};
class btree
{
    public:
        
		btree();
        ~btree();
		void insert(int key);
		void insertitem(node *& treeroot, int key);
		void print(int c);
        void print_inorder(node * r);
		void print_preorder(node * r);
		void print_postorder(node * r);
    private:
        node *root;
};
btree::btree()
{
	root = NULL;
}
btree::~btree()
{
	delete root;
}
void btree::insert(int key)
{
	insertitem(root,key);
}
void btree::insertitem(node*& tree, int number) {
  if (tree == NULL) {
    tree = new node;
    tree->left = NULL;
    tree->right = NULL;
    tree->key_value = number;
  } else if (number < tree->key_value) {
    insertitem(tree->left, number);
  } else {
    insertitem(tree->right, number);
  }
}
void btree::print(int c)
{
	cout<<endl;
	if (c==1)
		print_preorder(root);
	else if(c==2)
		print_postorder(root);
	else if(c==3)
		print_inorder(root);
}
void btree::print_preorder(node *r)
{
	if(r == NULL)
		return;
	else
	{
		cout << r->key_value<<" ";
		print_preorder(r->left);
		print_preorder(r->right);
	}


}
void btree::print_inorder(node *r)
{
	if (r == NULL)
			return;
		else{
			print_inorder(r->left);
			cout << r->key_value<<" ";
			print_inorder(r->right);
		}
}
void btree::print_postorder(node *r)
{
	if (r == NULL)
			return;
		else
		{
			print_postorder(r->left);
			print_postorder(r->right);
			cout << r->key_value<<" ";
		}
}
void main()
{
	
  btree* tree = new btree;
  tree->insert(1);
  tree->insert(2);
  tree->insert(3);
  tree->insert(8);
  tree->insert(5);
  tree->insert(4);
  tree->insert(6);
  cout<<"PREORDER\n";
  tree->print(1);
  cout<<"\nPOSTORDER\n";
  tree->print(2);
   cout<<"\nINORDER\n";
  tree->print(3);
  system ("pause");
}