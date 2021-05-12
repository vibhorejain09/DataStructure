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
bool iterativeBstSearch(Node *root, int x)
{
	Node *curr = root;
	while (curr != NULL) {
		if (curr->key == x) 
			return true;
		else if (x < curr->key)
			curr = curr->left;
		else 
			curr = curr->right;
		}
		return false;
}
bool recursiveBstSearch(Node *root, int x)
{
	if (root == NULL)
		return false;
	else if (root->key == x)
		return true;
	else if (x < root->key)
		return recursiveBstSearch(root->left, x);
	else
		return recursiveBstSearch(root->right, x);
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
	cout<<recursiveBstSearch(root, 16)<<"\n";
	cout<<iterativeBstSearch(root, 19)<<"\n";
}