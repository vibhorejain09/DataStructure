#include<bits/stdc++.h>
using namespace std;
struct Node
{
	int key;
	Node *left;
	Node *right;
	Node(int k)
	{
		key=k;
		left=NULL;
		right=NULL;
	}
};
void itrinorder(Node *root)
{
	stack<Node *> s;
	Node *curr=root;
	while(curr!=NULL || s.empty()==false)
	{
		while(curr!=NULL)
		{
			s.push(curr);
			curr=curr->left;
		}
		curr=s.top();
		s.pop();
		cout<<curr->key<<" ";
		curr=curr->right;
	}
}
Node *iterativeInsertInBST(Node *root, int x)
{
	Node *temp = new Node(x);
	if(root==NULL)
	{
		return temp;
	}
	Node *curr=root,*parent=NULL; //to make linking , so take hold of the parent to which need to be added
	while(curr!=NULL)
	{
		parent=curr;
		if (curr->key == x) {
			return root;
		}
		else if (curr->key < x) {
			curr = curr->right;
		}
		else {
			curr = curr->left;
		}
	}
	if (parent->key < x) {
		parent->right = temp;
	}
	else 
	{
		parent->left = temp;
	}
	return root;
}
Node *recursiveInsertInBST(Node *root, int x)
{
	if (root == NULL)
		return new Node(x);
	if (root->key < x)
		root->right = recursiveInsertInBST(root->right, x);
	else if (root->key > x)
		root->left = recursiveInsertInBST(root->left, x);
	return root;
}
int main()
{
	Node *root = new Node(15);
	root->left = new Node(5);
	root->left->left = new Node(3);
	root->right = new Node(20);
	root->right->left = new Node(18);
	root->right->right = new Node(80);
	root->right->left->left = new Node(16);
	itrinorder(root);
	root = recursiveInsertInBST(root, 10);
	cout<<"\n";
	itrinorder(root);
	root = iterativeInsertInBST(root, 90);
	cout<<"\n";
	itrinorder(root);
}