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
void recinoredr(Node *root)
{
	if(root!=NULL)
	{
		recinoredr(root->left);
		cout<<root->key<<" ";
		recinoredr(root->right);
	}
}
int main()
{
	Node *root = new Node(10); // for empty tree Node *root = NULL;          10
	root->left = new Node(20);										//20          30
	root->right = new Node(30);									//40    50	   60    70
	root->left->left = new Node(40);
	root->left->right = new Node(50);
	root->right->left = new Node(60);
	root->right->right = new Node(70);	
	recinoredr(root);
}
